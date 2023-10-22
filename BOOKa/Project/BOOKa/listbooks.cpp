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
}

void listBooks::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QClipboard* pcb = QApplication::clipboard(); //создание объекта для взаимодействия с буфером обмена
    pcb->setText(item->text(), QClipboard::Clipboard); //копирование выбранного текста в буфер обмена
}

