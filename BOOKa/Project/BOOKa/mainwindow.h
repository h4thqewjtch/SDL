#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFile>
#include <QMainWindow>

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
    void reset_settings();
    void add_to_recent();
    void open_bookmarks();
    void open_list(QString);

private slots:

    void on_actionSelect_text_triggered();

    void on_actionRecent_Books_triggered();

    void on_actionFavorites_triggered();

    void on_actionBookMarks_triggered();

    void on_actionInfo_triggered();

    void on_addToFavorites_clicked();

    void on_addBookmark_clicked();

    void on_comboFonts_activated(int index);

    void on_comboSize_activated(int index);

    void on_btnBack_clicked();

    void on_btnNext_clicked();

private:
    Ui::MainWindow *ui;
    QString filePath, fileName;
    QString text;
    QString fontName = "Arial";;
    int fontSize = 8;
    long pagesCount = 0;
    long curPage = 0;
    long charCount = 0;
};
#endif // MAINWINDOW_H
