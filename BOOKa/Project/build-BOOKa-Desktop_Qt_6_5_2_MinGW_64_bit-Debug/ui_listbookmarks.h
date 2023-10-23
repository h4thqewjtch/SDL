/********************************************************************************
** Form generated from reading UI file 'listbookmarks.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTBOOKMARKS_H
#define UI_LISTBOOKMARKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_listBookMarks
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;

    void setupUi(QDialog *listBookMarks)
    {
        if (listBookMarks->objectName().isEmpty())
            listBookMarks->setObjectName("listBookMarks");
        listBookMarks->resize(400, 300);
        verticalLayout = new QVBoxLayout(listBookMarks);
        verticalLayout->setObjectName("verticalLayout");
        listWidget = new QListWidget(listBookMarks);
        listWidget->setObjectName("listWidget");

        verticalLayout->addWidget(listWidget);


        retranslateUi(listBookMarks);

        QMetaObject::connectSlotsByName(listBookMarks);
    } // setupUi

    void retranslateUi(QDialog *listBookMarks)
    {
        listBookMarks->setWindowTitle(QCoreApplication::translate("listBookMarks", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class listBookMarks: public Ui_listBookMarks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTBOOKMARKS_H
