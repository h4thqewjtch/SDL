#ifndef LISTBOOKS_H
#define LISTBOOKS_H

#include <QDialog>
#include <QListWidgetItem>

namespace Ui {
class listBooks;
}

class listBooks : public QDialog
{
    Q_OBJECT

public:
    explicit listBooks(QWidget *parent = nullptr);
    ~listBooks();
    void setBooksList(QStringList);

private slots:

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::listBooks *ui;
};

#endif // LISTBOOKS_H
