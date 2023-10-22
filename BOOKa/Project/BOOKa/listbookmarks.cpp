#include "listbookmarks.h"
#include "ui_listbookmarks.h"

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
    ui->listWidget->clear();
    ui->listWidget->addItems(list);
}

void listBookMarks::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QClipboard* pcb = QApplication::clipboard(); //создание объекта для взаимодействия с буфером обмена
    pcb->setText(item->text(), QClipboard::Clipboard); //копирование выбранного текста в буфер обмена
}

