/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSelect_text;
    QAction *actionAlready_Read;
    QAction *actionFavorites;
    QAction *actionBookMarks;
    QAction *actionInfo;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *mainGrid;
    QGridLayout *readGrid;
    QTextBrowser *textBrowser;
    QLabel *label_3;
    QComboBox *comboFonts;
    QPushButton *addToFavorites;
    QLabel *bookInfo;
    QLabel *label;
    QPushButton *addBookmark;
    QComboBox *comboSize;
    QMenuBar *menubar;
    QMenu *menuInfo;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1023, 698);
        actionSelect_text = new QAction(MainWindow);
        actionSelect_text->setObjectName("actionSelect_text");
        actionAlready_Read = new QAction(MainWindow);
        actionAlready_Read->setObjectName("actionAlready_Read");
        actionFavorites = new QAction(MainWindow);
        actionFavorites->setObjectName("actionFavorites");
        actionBookMarks = new QAction(MainWindow);
        actionBookMarks->setObjectName("actionBookMarks");
        actionInfo = new QAction(MainWindow);
        actionInfo->setObjectName("actionInfo");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        mainGrid = new QGridLayout();
        mainGrid->setObjectName("mainGrid");
        readGrid = new QGridLayout();
        readGrid->setObjectName("readGrid");
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setStyleSheet(QString::fromUtf8(""));

        readGrid->addWidget(textBrowser, 0, 0, 1, 1);


        mainGrid->addLayout(readGrid, 4, 0, 1, 3);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        mainGrid->addWidget(label_3, 0, 0, 1, 3);

        comboFonts = new QComboBox(centralwidget);
        comboFonts->addItem(QString());
        comboFonts->addItem(QString());
        comboFonts->addItem(QString());
        comboFonts->addItem(QString());
        comboFonts->addItem(QString());
        comboFonts->addItem(QString());
        comboFonts->addItem(QString());
        comboFonts->addItem(QString());
        comboFonts->setObjectName("comboFonts");

        mainGrid->addWidget(comboFonts, 1, 0, 1, 1);

        addToFavorites = new QPushButton(centralwidget);
        addToFavorites->setObjectName("addToFavorites");

        mainGrid->addWidget(addToFavorites, 1, 2, 1, 1);

        bookInfo = new QLabel(centralwidget);
        bookInfo->setObjectName("bookInfo");

        mainGrid->addWidget(bookInfo, 3, 0, 1, 2);

        label = new QLabel(centralwidget);
        label->setObjectName("label");

        mainGrid->addWidget(label, 2, 0, 1, 3);

        addBookmark = new QPushButton(centralwidget);
        addBookmark->setObjectName("addBookmark");

        mainGrid->addWidget(addBookmark, 3, 2, 1, 1);

        comboSize = new QComboBox(centralwidget);
        comboSize->addItem(QString());
        comboSize->addItem(QString());
        comboSize->addItem(QString());
        comboSize->addItem(QString());
        comboSize->addItem(QString());
        comboSize->addItem(QString());
        comboSize->addItem(QString());
        comboSize->addItem(QString());
        comboSize->addItem(QString());
        comboSize->setObjectName("comboSize");

        mainGrid->addWidget(comboSize, 1, 1, 1, 1);


        verticalLayout->addLayout(mainGrid);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1023, 21));
        menuInfo = new QMenu(menubar);
        menuInfo->setObjectName("menuInfo");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuInfo->menuAction());
        menuInfo->addAction(actionSelect_text);
        menuInfo->addAction(actionAlready_Read);
        menuInfo->addAction(actionFavorites);
        menuInfo->addAction(actionBookMarks);
        menuInfo->addAction(actionInfo);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSelect_text->setText(QCoreApplication::translate("MainWindow", "Select text", nullptr));
#if QT_CONFIG(shortcut)
        actionSelect_text->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAlready_Read->setText(QCoreApplication::translate("MainWindow", "Already Read", nullptr));
        actionFavorites->setText(QCoreApplication::translate("MainWindow", "Favorites", nullptr));
        actionBookMarks->setText(QCoreApplication::translate("MainWindow", "BookMarks", nullptr));
        actionInfo->setText(QCoreApplication::translate("MainWindow", "Info", nullptr));
#if QT_CONFIG(shortcut)
        actionInfo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+I", nullptr));
#endif // QT_CONFIG(shortcut)
        label_3->setText(QString());
        comboFonts->setItemText(0, QCoreApplication::translate("MainWindow", "Arial", nullptr));
        comboFonts->setItemText(1, QCoreApplication::translate("MainWindow", "Calibri", nullptr));
        comboFonts->setItemText(2, QCoreApplication::translate("MainWindow", "Courier New", nullptr));
        comboFonts->setItemText(3, QCoreApplication::translate("MainWindow", "Impact", nullptr));
        comboFonts->setItemText(4, QCoreApplication::translate("MainWindow", "Malgun Gothic", nullptr));
        comboFonts->setItemText(5, QCoreApplication::translate("MainWindow", "Monotype Corsiva", nullptr));
        comboFonts->setItemText(6, QCoreApplication::translate("MainWindow", "Source Code Pro", nullptr));
        comboFonts->setItemText(7, QCoreApplication::translate("MainWindow", "Times New Roman", nullptr));

        addToFavorites->setText(QCoreApplication::translate("MainWindow", "Add to Favorites", nullptr));
        bookInfo->setText(QString());
        label->setText(QString());
        addBookmark->setText(QCoreApplication::translate("MainWindow", "Add Bookmark", nullptr));
        comboSize->setItemText(0, QCoreApplication::translate("MainWindow", "8", nullptr));
        comboSize->setItemText(1, QCoreApplication::translate("MainWindow", "12", nullptr));
        comboSize->setItemText(2, QCoreApplication::translate("MainWindow", "16", nullptr));
        comboSize->setItemText(3, QCoreApplication::translate("MainWindow", "20", nullptr));
        comboSize->setItemText(4, QCoreApplication::translate("MainWindow", "24", nullptr));
        comboSize->setItemText(5, QCoreApplication::translate("MainWindow", "28", nullptr));
        comboSize->setItemText(6, QCoreApplication::translate("MainWindow", "32", nullptr));
        comboSize->setItemText(7, QCoreApplication::translate("MainWindow", "36", nullptr));
        comboSize->setItemText(8, QCoreApplication::translate("MainWindow", "40", nullptr));

        menuInfo->setTitle(QCoreApplication::translate("MainWindow", "Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
