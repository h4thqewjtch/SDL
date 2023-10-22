/********************************************************************************
** Form generated from reading UI file 'recentbooks.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECENTBOOKS_H
#define UI_RECENTBOOKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RecentBooks
{
public:
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *RecentBooks)
    {
        if (RecentBooks->objectName().isEmpty())
            RecentBooks->setObjectName("RecentBooks");
        RecentBooks->resize(400, 300);
        verticalLayout = new QVBoxLayout(RecentBooks);
        verticalLayout->setObjectName("verticalLayout");
        textBrowser = new QTextBrowser(RecentBooks);
        textBrowser->setObjectName("textBrowser");

        verticalLayout->addWidget(textBrowser);


        retranslateUi(RecentBooks);

        QMetaObject::connectSlotsByName(RecentBooks);
    } // setupUi

    void retranslateUi(QDialog *RecentBooks)
    {
        RecentBooks->setWindowTitle(QCoreApplication::translate("RecentBooks", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RecentBooks: public Ui_RecentBooks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECENTBOOKS_H
