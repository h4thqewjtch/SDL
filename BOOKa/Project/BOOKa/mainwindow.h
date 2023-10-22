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
    void show_fb2();
    void show_epub();
    void show_txt();

private slots:

    void on_actionSelect_text_triggered();

    void on_actionInfo_triggered();

    void on_comboFonts_activated(int index);

    void on_comboSize_activated(int index);

    void on_addToFavorites_clicked();

    void on_addBookmark_clicked();

    void on_actionRecent_Books_triggered();

    void on_btnBack_clicked();

    void on_btnNext_clicked();

private:
    Ui::MainWindow *ui;
    QString favoritesPath;
    QString recentBooksPath;
    QString bookMarksPath = "";
    QString filePath, fileName;
    QString text;
    QString fontName = "Arial";;
    int fontSize = 8;
    long pagesCount = 0;
    long curPage = 0;
    long charCount = 4802;
};
#endif // MAINWINDOW_H
