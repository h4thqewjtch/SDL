#include "listbooks.h"
#include "ui_listbooks.h"

#include <QClipboard>

listBooks::listBooks(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::listBooks)
{
    ui->setupUi(this);
}

listBooks::~listBooks()
{
    delete ui;
}

void listBooks::setBooksList(QStringList list)
{
    ui->listWidget->clear();
    ui->listWidget->addItems(list);
//  создание объекта для взаимодействия с буфером обмена
    clipBoard = QApplication::clipboard();
    clipBoard->clear();
}

void listBooks::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
//  копирование выбранного текста в буфер обмена
    clipBoard->setText(item->text(), QClipboard::Clipboard);
}

