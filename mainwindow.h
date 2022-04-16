#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QFile>
#include <QSettings>
#include <QShortcut>
#include <QRegExp>
#include <QRegExpValidator>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_exit_pb_clicked();

    void on_ch_lvl_pb_clicked();

    void on_back_to_menu_pb_clicked();

    void on_back_to_menu_from_about_pb_clicked();

    void on_about_pb_clicked();

    void on_begin_lvl_pb_clicked();

    void on_lvl_1_pb_clicked();

    void on_lvl_2_pb_clicked();

    void on_lvl_3_pb_clicked();

    void on_lvl_4_pb_clicked();

    void on_lvl_5_pb_clicked();

    void on_lvl_6_pb_clicked();

    void on_end_lvl_pb_clicked();

    void on_menu_begin_lvl_pb_clicked();

    void on_menu_lvl_1_pb_clicked();

    void on_menu_lvl_2_pb_clicked();

    void on_menu_lvl_3_pb_clicked();

    void on_menu_lvl_4_pb_clicked();

    void on_menu_lvl_5_pb_clicked();

    void on_menu_lvl_6_pb_clicked();

    void on_menu_end_lvl_pb_clicked();

    void on_play_pb_clicked();

    void on_next_begin_lvl_pb_clicked();

    void on_next_lvl_1_pb_clicked();

    void on_next_lvl_2_pb_clicked();

    void on_next_lvl_3_pb_clicked();

    void on_next_lvl_4_pb_clicked();

    void on_next_lvl_5_pb_clicked();

    void on_next_lvl_6_pb_clicked();

    void slotShortcutEsc();

    void slotShortcutHelp();

    void on_agree_pb_clicked();

    void on_check_lvl_1_pb_clicked();

    void on_check_lvl_2_pb_clicked();

    void on_check_lvl_3_pb_clicked();

    void on_check_lvl_4_pb_clicked();

    void on_check_lvl_5_pb_clicked();

    void on_check_lvl_6_pb_clicked();

private:
    Ui::MainWindow *ui;
    QShortcut      *global_exit_key;
    QShortcut      *global_help_key;
};
#endif // MAINWINDOW_H
