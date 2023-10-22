#include "mainwindow.h"
#include "listbookmarks.h"
#include "listbooks.h"
#include "ui_mainwindow.h"
#include "fb2files.h"

#include <QClipboard>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextEdit>
#include <QTextStream>
#include <QXmlStreamReader>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("BOOKa");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open_file()
{
    // очистка виджета отображения страниц
    ui->textBrowser->clear();
    //открытие выбранной книги
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        if(filePath.endsWith(".fb2"))
        {
            FB2Files fb2;
            //парсинг .fb2
            if(fb2.openFB2File(file, text, fontName, fontSize))
            {
                //расчет количества страниц
                //из общего числа символов и числа символов одной страницы для конкретного размера текста
                pagesCount = text.size()/charCount;
                //очистка строки с названием книги и местом чтения
                ui->bookInfo->clear();
                //вывод названия книги и места чтения
                ui->bookInfo->setText(QFileInfo(file.fileName()).baseName()
                                          .append("          ")
                                          .append(QString::number(curPage))
                                          .append("/")
                                          .append(QString::number(pagesCount)));

                //отображение страницы .fb2
                show_fb2();
            }
        }
        else if(filePath.endsWith(".epub"))
        {
        }
        else if(filePath.endsWith(".txt"))
        {
            QTextStream in(&file);
            text = in.readAll();
            QFont *font = new QFont(fontName);
            font->setPointSize(fontSize);
            ui->textBrowser->setFont(*font);
            pagesCount = text.size()/charCount;
            ui->bookInfo->clear();
            ui->bookInfo->setText(QFileInfo(file.fileName()).baseName()
                                      .append("          ")
                                      .append(QString::number(curPage))
                                      .append("/")
                                      .append(QString::number(pagesCount)));
            show_txt();
        }
        file.close();
    }
    else
    {
        QMessageBox::critical(this, "ACCESS_ERROR","File is not opened");
    }
}

void MainWindow::show_fb2()
{
    QString page = "";
    //если номер текущей страницы не выходит за границу рассчитанного общего количества
    if(curPage<=pagesCount)
    {
        //отделение от всего текста одной страницы
        page = text.mid(curPage*charCount, charCount);
    }
    //если общее количество символов не делится на количство символов одной страницы конкретного размера текста
    else if(text.size()%charCount)
    {
        //отображение остатка символов
        page = text.mid((curPage-1)*charCount, text.size()%charCount);
    }
    //вывод страницы в формате html
    QTextDocument document;
    document.setHtml(page);

    QFont font(fontName, fontSize);
    document.setDefaultFont(font);

    QString html = document.toHtml();
    ui->textBrowser->setHtml(html);
}

void MainWindow::show_epub()
{

}

void MainWindow::show_txt()
{
    QString page = "";
    if(curPage<=pagesCount)
    {
        page = text.mid(curPage*charCount, charCount);
    }
    else if(text.size()%charCount)
    {
        page = text.mid((curPage-1)*charCount, text.size()%charCount);
    }
    ui->textBrowser->setText(page);
}

void MainWindow::reset_settings()
{
    filePath.clear();
    fileName.clear();
    text.clear();
    fontName = "Arial";
    fontSize = 8;
    pagesCount = 0;
    curPage = 0;
    charCount =3430;
}

void MainWindow::add_to_recent()
{
    QDir dir = QDir(filePath);
    if(!QDir(dir.homePath().append("/SDL/BOOKa/Project/RecentBooks")).exists())
    {
        QDir().mkdir(dir.homePath().append("/SDL/BOOKa/Project/RecentBooks"));
    }
    if (QFile::exists(dir.homePath().append("/SDL/BOOKa/Project/RecentBooks").append("/").append(fileName)))
    {
        QFile::remove(dir.homePath().append("/SDL/BOOKa/Project/RecentBooks").append("/").append(fileName));
    }
    QFile::copy(filePath, dir.homePath().append("/SDL/BOOKa/Project/RecentBooks").append("/").append(fileName));
}

void MainWindow::open_bookmarks()
{
    QDir dir = QDir(filePath);
    QFile bookMarks(dir.homePath().append("/SDL/BOOKa/Project/BookMarks").append("/").append(fileName).append(".txt"));
    if (bookMarks.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QTextStream in(&bookMarks);
        QString line = "";
        //чтение файла до конца
        while (!in.atEnd())
        {
            line = in.readLine();
        }
        //если есть закладки для этой книги
        if(!line.isEmpty())
        {
            bool state;
            QStringList info = line.split("|");
            qDebug() << info;
            // получение информации о прошлом чтении книги из закладки
            curPage = info[0].toLong(&state, 10);
            fontName = info[1];
            fontSize = info[2].toLong(&state, 10);
            charCount = info[3].toLong(&state, 10);
            ui->comboFonts->setCurrentText(fontName);
            ui->comboSize->setCurrentText(QString::number(fontSize));
        }
        bookMarks.close();
    }
}

void MainWindow::on_actionSelect_text_triggered()
{
    //Сброс настроек предыдущей книги
    reset_settings();
    //выбор новой книги
    filePath = QFileDialog::getOpenFileName();
    QFile file(filePath);
    //получение имени книги
    fileName = QFileInfo(file.fileName()).fileName();
    //добавление в папку "Hедавние"
    add_to_recent();
    //открытие файла с закладками для этой книги
    open_bookmarks();
    open_file();
}

void MainWindow::on_actionRecent_Books_triggered()
{
    QStringList recBooksList;
    QDir dir = QDir(filePath);
    if(QDir(dir.homePath().append("/SDL/BOOKa/Project/RecentBooks")).exists())
    {
        dir = QDir(dir.homePath().append("/SDL/BOOKa/Project/RecentBooks"));
        qDebug()<<dir.absolutePath();
        qDebug()<<"exists\n";
        foreach (QFileInfo info, dir.entryInfoList(QDir::Files, QDir::Name))
        {
            recBooksList.append(info.fileName());
            qDebug()<<"info: "<<info.fileName()<<"\n";
        }
        listBooks recBooks;
        recBooks.setBooksList(recBooksList);
        recBooks.exec();
        reset_settings();
        QClipboard* pcb = QApplication::clipboard();
        filePath = dir.homePath().append("/SDL/BOOKa/Project/RecentBooks/").append(pcb->text());
        QFile file(filePath);
        fileName = QFileInfo(file.fileName()).fileName();
        open_bookmarks();
        open_file();
    }
    else
    {
        QMessageBox::information(this, "ACCESS_ERROR","Recent books do not exist");
    }

}

void MainWindow::on_actionFavorites_triggered()
{
    QStringList favorList;
    QDir dir = QDir(filePath);
    if(QDir(dir.homePath().append("/SDL/BOOKa/Project/Favorites")).exists())
    {
        dir = QDir(dir.homePath().append("/SDL/BOOKa/Project/Favorites"));
        qDebug()<<dir.absolutePath();
        foreach (QFileInfo info, dir.entryInfoList(QDir::Files, QDir::Name))
        {
            favorList.append(info.fileName());
            //qDebug()<<"info: "<<info.fileName()<<"\n";
        }
        listBooks favorites;
        favorites.setBooksList(favorList);
        favorites.exec();
        reset_settings();
        QClipboard* pcb = QApplication::clipboard();
        filePath = dir.homePath().append("/SDL/BOOKa/Project/Favorites/").append(pcb->text());
        QFile file(filePath);
        fileName = QFileInfo(file.fileName()).fileName();
        open_bookmarks();
        open_file();
    }
    else
    {
        QMessageBox::information(this, "ACCESS_ERROR","Favorite books do not exist");
    }
}

void MainWindow::on_actionBookMarks_triggered()
{
    QStringList bookMarksList;
    QDir dir = QDir(filePath);
    if(QDir(dir.homePath().append("/SDL/BOOKa/Project/BookMarks")).exists())
    {
        dir = QDir(dir.homePath().append("/SDL/BOOKa/Project/BookMarks"));
        qDebug()<<dir.absolutePath();
        foreach (QFileInfo info, dir.entryInfoList(QDir::Files, QDir::Name))
        {
            bookMarksList.append(info.fileName());
            //qDebug()<<"info: "<<info.fileName()<<"\n";
        }
        listBookMarks bookMarks;
        bookMarks.setBookMarksList(bookMarksList);
        bookMarks.exec();
        reset_settings();
        QClipboard* pcb = QApplication::clipboard();
        filePath = dir.homePath().append("/SDL/BOOKa/Project/Favorites/").append(pcb->text());
        QFile file(filePath);
        fileName = QFileInfo(file.fileName()).fileName();
        open_bookmarks();
        open_file();
    }
    else
    {
        QMessageBox::information(this, "ACCESS_ERROR","Favorite books do not exist");
    }
}

void MainWindow::on_actionInfo_triggered()
{

}

void MainWindow::on_addToFavorites_clicked()
{
    QDir dir = QDir(filePath);
    // создание папки с понравившимися книгами
    if(!QDir(dir.homePath().append("/SDL/BOOKa/Project/Favorites")).exists())
    {
        QDir().mkdir(dir.homePath().append("/SDL/BOOKa/Project/Favorites"));
    }
    //добавление книги в Понравившиеся
    if (QFile::exists(dir.homePath().append("/SDL/BOOKa/Project/Favorites/").append(fileName)))
    {
        QFile::remove(dir.homePath().append("/SDL/BOOKa/Project/Favorites/").append(fileName));
    }
    QFile::copy(filePath,dir.homePath().append("/SDL/BOOKa/Project/Favorites/").append(fileName));
}

void MainWindow::on_addBookmark_clicked()
{
    QDir dir = QDir(filePath);
    // создание папки с закладками
    if(!QDir(dir.homePath().append("/SDL/BOOKa/Project/BookMarks")).exists())
    {
        QDir().mkdir(dir.homePath().append("/SDL/BOOKa/Project/BookMarks"));
    }
    //добавление закладки(номер страницы, шрифт, размер текста) в отдельный файл для конкретной книги
    QFile bookMarks(dir.homePath().append("/SDL/BOOKa/Project/BookMarks/").append(fileName).append(".txt"));
    if (bookMarks.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        bookMarks.seek(bookMarks.size());
        QTextStream out(&bookMarks);
        out << curPage << "|" << fontName << "|" << fontSize << "|" << charCount <<"\n";
        bookMarks.close();
    }
    else
    {
        QMessageBox::warning(this, "ACCESS_ERROR","BookMark is not added");
    }

}

void MainWindow::on_comboFonts_activated(int index)
{
    //получение выбранного шрифта
    switch(index)
    {
    case 0:
    {
        fontName = "Arial";
        break;
    }
    case 1:
    {
        fontName = "Calibri";
        break;
    }
    case 2:
    {
        fontName = "Courier New";
        break;
    }
    case 3:
    {
        fontName = "Impact";
        break;
    }
    case 4:
    {
        fontName = "Malgun Gothic";
        break;
    }
    case 5:
    {
        fontName = "Monotype Corsiva";
        break;
    }
    case 6:
    {
        fontName = "Source Code Pro";
        break;
    }
    case 7:
    {
        fontName = "Times New Roman";
        break;
    }
    }
    open_file();
}

void MainWindow::on_comboSize_activated(int index)
{
    // получение выбранного размера текста и количества символов для одной страницы с этим размером текста
    switch(index)
    {
    case 0:
    {
        fontSize = 8;
        charCount = 3430;
        break;
    }
    case 1:
    {
        fontSize = 12;
        charCount = 3087;
        break;
    }
    case 2:
    {
        fontSize = 16;
        charCount = 2744;
        break;
    }
    case 3:
    {
        fontSize = 20;
        charCount = 2401;
        break;
    }
    case 4:
    {
        fontSize = 24;
        charCount = 2058;
        break;
    }
    case 5:
    {
        fontSize = 28;
        charCount = 1715;
        break;
    }
    case 6:
    {
        fontSize = 32;
        charCount = 1372;
        break;
    }
    case 7:
    {
        fontSize = 36;
        charCount = 1029;
        break;
    }
    case 8:
    {
        fontSize = 40;
        charCount = 686;
        break;
    }
    }
    open_file();
}

void MainWindow::on_btnBack_clicked()
{
    if(curPage>0)
    {
        curPage--;
        open_file();
    }
}

void MainWindow::on_btnNext_clicked()
{
    if(curPage<pagesCount)
    {
        curPage++;
        open_file();
    }
}





