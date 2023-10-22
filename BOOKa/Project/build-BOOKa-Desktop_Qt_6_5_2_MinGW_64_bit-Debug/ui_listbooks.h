/********************************************************************************
** Form generated from reading UI file 'listbooks.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTBOOKS_H
#define UI_LISTBOOKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_listBooks
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;

    void setupUi(QDialog *listBooks)
    {
        if (listBooks->objectName().isEmpty())
            listBooks->setObjectName("listBooks");
        listBooks->resize(400, 300);
        verticalLayout = new QVBoxLayout(listBooks);
        verticalLayout->setObjectName("verticalLayout");
        listWidget = new QListWidget(listBooks);
        listWidget->setObjectName("listWidget");

        verticalLayout->addWidget(listWidget);


        retranslateUi(listBooks);

        QMetaObject::connectSlotsByName(listBooks);
    } // setupUi

    void retranslateUi(QDialog *listBooks)
    {
        listBooks->setWindowTitle(QCoreApplication::translate("listBooks", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class listBooks: public Ui_listBooks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTBOOKS_H
