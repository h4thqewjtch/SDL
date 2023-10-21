#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void open_file();

private slots:

    void on_actionSelect_text_triggered();

    void on_actionInfo_triggered();

    void on_comboFonts_activated(int index);

    void on_comboSize_activated(int index);

    void on_addToFavorites_clicked();

    void on_addBookmark_clicked();

    void on_actionAlready_Read_triggered();

private:
    Ui::MainWindow *ui;
    QString filePath, fileName;
    QString text;
    QString fontName = "Arial";;
    int fontSize = 9;
    QString favoritesPath;
    QString alreadyReadPath;
};
#endif // MAINWINDOW_H
