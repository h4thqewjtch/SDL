#ifndef LISTBOOKMARKS_H
#define LISTBOOKMARKS_H

#include <QDialog>
#include <QListWidgetItem>

namespace Ui {
class listBookMarks;
}

class listBookMarks : public QDialog
{
    Q_OBJECT

public:
    explicit listBookMarks(QWidget *parent = nullptr);
    ~listBookMarks();
    void setBookMarksList(QStringList);

private slots:


    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::listBookMarks *ui;
};

#endif // LISTBOOKMARKS_H
