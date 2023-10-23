#include "listbookmarks.h"
#include "ui_listbookmarks.h"

#include <QDir>
#include <QClipboard>

listBookMarks::listBookMarks(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::listBookMarks)
{
    ui->setupUi(this);
}

listBookMarks::~listBookMarks()
{
    delete ui;
}

void listBookMarks::setBookMarksList(QStringList list)
{
    QStringList bookInfoList;
    foreach(QString filePath, list)
    {
        bookInfoList.append(open_bookMarks(filePath));
    }
    //qDebug() <<"list: "<< bookInfoList << "\n";
    ui->listWidget->clear();
    ui->listWidget->addItems(bookInfoList);
//  создание объекта для взаимодействия с буфером обмена
    clipBoard = QApplication::clipboard();
    clipBoard->clear();
}

QStringList listBookMarks::open_bookMarks(QString filePath)
{
    QStringList list = filePath.split("/");
    QString fileName = list[list.size()-1];
    //qDebug() << "fileName: "<< fileName<<"\n";
    list.clear();
    QDir dir = QDir(filePath);
    dir = dir.homePath().append("/SDL/BOOKa/Project/BookMarks");
    QFileInfo info = QFileInfo(dir.homePath().append("/SDL/BOOKa/Project/BookMarks/").append(fileName).append(".txt"));
    if(info.exists())
    {
        QFile bookMarksFile(info.absoluteFilePath());
        if (bookMarksFile.open(QIODevice::ReadWrite | QIODevice::Text))
        {
            QTextStream in(&bookMarksFile);
            QString line = "";
//          чтение файла до конца
            while (!in.atEnd())
            {
                line = in.readLine();
                line = line.append("|").append(fileName);
                //qDebug() <<"line: "<< line << "\n";
                list.append(line);
            }
            bookMarksFile.close();
        }
    }
    return list;
}

void listBookMarks::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
//  копирование выбранного текста в буфер обмена
    clipBoard->setText(item->text(), QClipboard::Clipboard);
}

