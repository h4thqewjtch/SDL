#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fb2files.h"

#include <QFileDialog>
#include <QTextEdit>
#include <QFile>
#include <QTextStream>
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
    ui->textBrowser->clear();
    QFile file(filePath);
    fileName = QFileInfo(file.fileName()).fileName();
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        if(filePath.endsWith(".fb2"))
        {
            FB2Files fb2;
            text = "";
            if(fb2.openFB2File(file, &text, fontName, fontSize))
            {
                ui->textBrowser->setText(text);
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
            ui->textBrowser->setText(text);
        }
        file.close();
    }
    else{}
}

void MainWindow::on_actionSelect_text_triggered()
{
    filePath = QFileDialog::getOpenFileName();
    open_file();
}

void MainWindow::on_actionInfo_triggered()
{

}

void MainWindow::on_comboFonts_activated(int index)
{
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
    switch(index)
    {
    case 0:
    {
        fontSize = 8;
        break;
    }
    case 1:
    {
        fontSize = 12;
        break;
    }
    case 2:
    {
        fontSize = 16;
        break;
    }
    case 3:
    {
        fontSize = 20;
        break;
    }
    case 4:
    {
        fontSize = 24;
        break;
    }
    case 5:
    {
        fontSize = 28;
        break;
    }
    case 6:
    {
        fontSize = 32;
        break;
    }
    case 7:
    {
        fontSize = 36;
        break;
    }
    case 8:
    {
        fontSize = 40;
        break;
    }
    }
    open_file();
}

void MainWindow::on_addToFavorites_clicked()
{
    QDir dir = QDir(filePath);
    if(favoritesPath.isEmpty())
    {
        favoritesPath = dir.homePath().append("/SDL/BOOKa/Project/Favorites");
        QDir().mkdir(favoritesPath);
    }
    if (QFile::exists(favoritesPath.append("/").append(fileName)))
    {
        QFile::remove(favoritesPath.append("/").append(fileName));
    }
    QFile::copy(filePath, favoritesPath);
}

void MainWindow::on_addBookmark_clicked()
{

}


void MainWindow::on_actionAlready_Read_triggered()
{
    QDir dir = QDir(filePath);
    if(alreadyReadPath.isEmpty())
    {
        alreadyReadPath = dir.homePath().append("/SDL/BOOKa/Project/AlreadyRead");
        QDir().mkdir(alreadyReadPath);
    }
    if (QFile::exists(alreadyReadPath.append(fileName)))
    {
        QFile::remove(favoritesPath.append("/").append(fileName));
    }
    QFile::copy(filePath, favoritesPath);
}

