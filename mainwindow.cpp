#include "mainwindow.h"
#include "ui_mainwindow.h"

int current_lvl;
QString ini_path = QDir::currentPath()+"/save/save.ini";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

//    qDebug()<<QDir::current();
//    qDebug()<<QDir::currentPath();

    global_exit_key = new QShortcut(this);
    global_exit_key->setKey(Qt::Key_Escape);
    global_help_key = new QShortcut(this);
    global_help_key->setKey(Qt::Key_H);
    connect(global_exit_key, SIGNAL(activated()), this, SLOT(slotShortcutEsc()));
    connect(global_help_key, SIGNAL(activated()), this, SLOT(slotShortcutHelp()));

    if (!QFile(ini_path).exists())
    {
        QSettings sett(ini_path, QSettings::IniFormat);
        sett.setValue("Progress/Current_progress", "0");
//        sett.setValue("Progress/Current_path", QDir::currentPath());
//        qDebug()<<"not exist";
    }
    else
    {
        QSettings sett(ini_path, QSettings::IniFormat);
        current_lvl = sett.value("Progress/Current_progress", "").toInt();
//        qDebug()<<"exist: lvl:"+QString::number(current_lvl);
    }

    ui->setupUi(this);
    ui->logo_lbl->setPixmap(QDir::currentPath()+"/img/img_logo");
    ui->img_lvl_1_lbl->setPixmap(QDir::currentPath()+"/img/img_1.jpg");
    ui->img_lvl_2_lbl->setPixmap(QDir::currentPath()+"/img/img_2.jpg");
    ui->img_lvl_3_lbl->setPixmap(QDir::currentPath()+"/img/img_3.jpg");
    ui->img_lvl_4_lbl->setPixmap(QDir::currentPath()+"/img/img_4.jpg");
    ui->img_lvl_5_lbl->setPixmap(QDir::currentPath()+"/img/img_5.jpg");
    ui->img_lvl_6_lbl->setPixmap(QDir::currentPath()+"/img/img_6.jpg");

    QRegExp reg_exp_1_lvl("[0-9][0-9]");
    QRegExpValidator *lvl_1_validator = new QRegExpValidator(reg_exp_1_lvl, this);
    ui->lvl_1_le->setValidator(lvl_1_validator);

    QRegExp reg_exp_2_lvl("[0-9][0-9][0-9]");
    QRegExpValidator *lvl_2_validator = new QRegExpValidator(reg_exp_2_lvl, this);
    ui->lvl_2_le->setValidator(lvl_2_validator);

    QRegExp reg_exp_3_lvl("[0-9][0-9][0-9][0-9]");
    QRegExpValidator *lvl_3_validator = new QRegExpValidator(reg_exp_3_lvl, this);
    ui->lvl_3_le->setValidator(lvl_3_validator);
    ui->lvl_4_le->setValidator(lvl_3_validator);

    ui->lvl_5_le->setValidator(lvl_1_validator);

    QRegExp reg_exp_6_lvl("[0-9][0-9][0-9][0-9][0-9][0-9]");
    QRegExpValidator *lvl_6_validator = new QRegExpValidator(reg_exp_6_lvl, this);
    ui->lvl_6_le->setValidator(lvl_6_validator);

    switch (current_lvl)
    {
        case 7:  ui->end_lvl_pb->setEnabled(true);
        case 6:  ui->lvl_6_pb->setEnabled(true);
        case 5:  ui->lvl_5_pb->setEnabled(true);
        case 4:  ui->lvl_4_pb->setEnabled(true);
        case 3:  ui->lvl_3_pb->setEnabled(true);
        case 2:  ui->lvl_2_pb->setEnabled(true);
        case 1:  ui->lvl_1_pb->setEnabled(true);
        case 0:  ui->begin_lvl_pb->setEnabled(true);
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_exit_pb_clicked()
{
    QApplication::quit();
}


void MainWindow::on_ch_lvl_pb_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->select_lvl_page);
}


void MainWindow::on_back_to_menu_pb_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->main_page);
}


void MainWindow::on_back_to_menu_from_about_pb_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->main_page);
}


void MainWindow::on_about_pb_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->about_page);
}


void MainWindow::on_begin_lvl_pb_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->begin_lvl_page);
}


void MainWindow::on_lvl_1_pb_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->lvl_1_page);
}


void MainWindow::on_lvl_2_pb_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->lvl_2_page);
}


void MainWindow::on_lvl_3_pb_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->lvl_3_page);
}


void MainWindow::on_lvl_4_pb_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->lvl_4_page);
}


void MainWindow::on_lvl_5_pb_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->lvl_5_page);
}


void MainWindow::on_lvl_6_pb_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->lvl_6_page);
}


void MainWindow::on_end_lvl_pb_clicked()
{

    ui->stackedWidget->setCurrentWidget(ui->end_lvl_page);
}


void MainWindow::on_menu_begin_lvl_pb_clicked()
{
    switch (current_lvl)
    {
        case 7:  ui->end_lvl_pb->setEnabled(true);
        case 6:  ui->lvl_6_pb->setEnabled(true);
        case 5:  ui->lvl_5_pb->setEnabled(true);
        case 4:  ui->lvl_4_pb->setEnabled(true);
        case 3:  ui->lvl_3_pb->setEnabled(true);
        case 2:  ui->lvl_2_pb->setEnabled(true);
        case 1:  ui->lvl_1_pb->setEnabled(true);
        case 0:  ui->begin_lvl_pb->setEnabled(true);
        break;
    }
    ui->stackedWidget->setCurrentWidget(ui->main_page);
}


void MainWindow::on_menu_lvl_1_pb_clicked()
{
    switch (current_lvl)
    {
        case 7:  ui->end_lvl_pb->setEnabled(true);
        case 6:  ui->lvl_6_pb->setEnabled(true);
        case 5:  ui->lvl_5_pb->setEnabled(true);
        case 4:  ui->lvl_4_pb->setEnabled(true);
        case 3:  ui->lvl_3_pb->setEnabled(true);
        case 2:  ui->lvl_2_pb->setEnabled(true);
        case 1:  ui->lvl_1_pb->setEnabled(true);
        case 0:  ui->begin_lvl_pb->setEnabled(true);
        break;
    }
    ui->stackedWidget->setCurrentWidget(ui->main_page);
}


void MainWindow::on_menu_lvl_2_pb_clicked()
{
    switch (current_lvl)
    {
        case 7:  ui->end_lvl_pb->setEnabled(true);
        case 6:  ui->lvl_6_pb->setEnabled(true);
        case 5:  ui->lvl_5_pb->setEnabled(true);
        case 4:  ui->lvl_4_pb->setEnabled(true);
        case 3:  ui->lvl_3_pb->setEnabled(true);
        case 2:  ui->lvl_2_pb->setEnabled(true);
        case 1:  ui->lvl_1_pb->setEnabled(true);
        case 0:  ui->begin_lvl_pb->setEnabled(true);
        break;
    }
    ui->stackedWidget->setCurrentWidget(ui->main_page);
}


void MainWindow::on_menu_lvl_3_pb_clicked()
{
    switch (current_lvl)
    {
        case 7:  ui->end_lvl_pb->setEnabled(true);
        case 6:  ui->lvl_6_pb->setEnabled(true);
        case 5:  ui->lvl_5_pb->setEnabled(true);
        case 4:  ui->lvl_4_pb->setEnabled(true);
        case 3:  ui->lvl_3_pb->setEnabled(true);
        case 2:  ui->lvl_2_pb->setEnabled(true);
        case 1:  ui->lvl_1_pb->setEnabled(true);
        case 0:  ui->begin_lvl_pb->setEnabled(true);
        break;
    }
    ui->stackedWidget->setCurrentWidget(ui->main_page);
}


void MainWindow::on_menu_lvl_4_pb_clicked()
{
    switch (current_lvl)
    {
        case 7:  ui->end_lvl_pb->setEnabled(true);
        case 6:  ui->lvl_6_pb->setEnabled(true);
        case 5:  ui->lvl_5_pb->setEnabled(true);
        case 4:  ui->lvl_4_pb->setEnabled(true);
        case 3:  ui->lvl_3_pb->setEnabled(true);
        case 2:  ui->lvl_2_pb->setEnabled(true);
        case 1:  ui->lvl_1_pb->setEnabled(true);
        case 0:  ui->begin_lvl_pb->setEnabled(true);
        break;
    }
    ui->stackedWidget->setCurrentWidget(ui->main_page);
}


void MainWindow::on_menu_lvl_5_pb_clicked()
{
    switch (current_lvl)
    {
        case 7:  ui->end_lvl_pb->setEnabled(true);
        case 6:  ui->lvl_6_pb->setEnabled(true);
        case 5:  ui->lvl_5_pb->setEnabled(true);
        case 4:  ui->lvl_4_pb->setEnabled(true);
        case 3:  ui->lvl_3_pb->setEnabled(true);
        case 2:  ui->lvl_2_pb->setEnabled(true);
        case 1:  ui->lvl_1_pb->setEnabled(true);
        case 0:  ui->begin_lvl_pb->setEnabled(true);
        break;
    }
    ui->stackedWidget->setCurrentWidget(ui->main_page);
}


void MainWindow::on_menu_lvl_6_pb_clicked()
{
    switch (current_lvl)
    {
        case 7:  ui->end_lvl_pb->setEnabled(true);
        case 6:  ui->lvl_6_pb->setEnabled(true);
        case 5:  ui->lvl_5_pb->setEnabled(true);
        case 4:  ui->lvl_4_pb->setEnabled(true);
        case 3:  ui->lvl_3_pb->setEnabled(true);
        case 2:  ui->lvl_2_pb->setEnabled(true);
        case 1:  ui->lvl_1_pb->setEnabled(true);
        case 0:  ui->begin_lvl_pb->setEnabled(true);
        break;
    }
    ui->stackedWidget->setCurrentWidget(ui->main_page);
}


void MainWindow::on_menu_end_lvl_pb_clicked()
{
    if(current_lvl <= 6)
    {
        current_lvl=7;
        QSettings sett(ini_path, QSettings::IniFormat);
        sett.setValue("Progress/Current_progress", current_lvl);
    }
    switch (current_lvl)
    {
        case 7:  ui->end_lvl_pb->setEnabled(true);
        case 6:  ui->lvl_6_pb->setEnabled(true);
        case 5:  ui->lvl_5_pb->setEnabled(true);
        case 4:  ui->lvl_4_pb->setEnabled(true);
        case 3:  ui->lvl_3_pb->setEnabled(true);
        case 2:  ui->lvl_2_pb->setEnabled(true);
        case 1:  ui->lvl_1_pb->setEnabled(true);
        case 0:  ui->begin_lvl_pb->setEnabled(true);
        break;
    }
    ui->stackedWidget->setCurrentWidget(ui->main_page);
}


void MainWindow::on_play_pb_clicked()
{
    switch (current_lvl)
    {
        case 7:  ui->stackedWidget->setCurrentWidget(ui->end_lvl_page);
        break;
        case 6:  ui->stackedWidget->setCurrentWidget(ui->lvl_6_page);
        break;
        case 5:  ui->stackedWidget->setCurrentWidget(ui->lvl_5_page);
        break;
        case 4:  ui->stackedWidget->setCurrentWidget(ui->lvl_4_page);
        break;
        case 3:  ui->stackedWidget->setCurrentWidget(ui->lvl_3_page);
        break;
        case 2:  ui->stackedWidget->setCurrentWidget(ui->lvl_2_page);
        break;
        case 1:  ui->stackedWidget->setCurrentWidget(ui->lvl_1_page);
        break;
        case 0:  ui->stackedWidget->setCurrentWidget(ui->begin_lvl_page);
        break;
    }
}


void MainWindow::on_next_begin_lvl_pb_clicked()
{

    if(current_lvl == 0)
    {
        current_lvl=1;
        QSettings sett(ini_path, QSettings::IniFormat);
        sett.setValue("Progress/Current_progress", current_lvl);
    }
    ui->stackedWidget->setCurrentWidget(ui->lvl_1_page);
}


void MainWindow::on_next_lvl_1_pb_clicked()
{
    if(current_lvl <= 1)
    {
        current_lvl=2;
        QSettings sett(ini_path, QSettings::IniFormat);
        sett.setValue("Progress/Current_progress", current_lvl);
    }
    ui->stackedWidget->setCurrentWidget(ui->lvl_2_page);
    ui->next_lvl_1_pb->setEnabled(false);
    ui->result_lvl_1_lbl->setText("Результат");
    ui->lvl_1_le->setText("");
}


void MainWindow::on_next_lvl_2_pb_clicked()
{
    if(current_lvl <= 2)
    {
        current_lvl=3;
        QSettings sett(ini_path, QSettings::IniFormat);
        sett.setValue("Progress/Current_progress", current_lvl);
    }
    ui->stackedWidget->setCurrentWidget(ui->lvl_3_page);
    ui->next_lvl_2_pb->setEnabled(false);
    ui->result_lvl_2_lbl->setText("Результат");
    ui->lvl_2_le->setText("");
}


void MainWindow::on_next_lvl_3_pb_clicked()
{
    if(current_lvl <= 3)
    {
        current_lvl=4;
        QSettings sett(ini_path, QSettings::IniFormat);
        sett.setValue("Progress/Current_progress", current_lvl);
    }
    ui->stackedWidget->setCurrentWidget(ui->lvl_4_page);
    ui->next_lvl_3_pb->setEnabled(false);
    ui->result_lvl_3_lbl->setText("Результат");
    ui->lvl_3_le->setText("");
}


void MainWindow::on_next_lvl_4_pb_clicked()
{
    if(current_lvl <= 4)
    {
        current_lvl=5;
        QSettings sett(ini_path, QSettings::IniFormat);
        sett.setValue("Progress/Current_progress", current_lvl);
    }
    ui->stackedWidget->setCurrentWidget(ui->lvl_5_page);
    ui->next_lvl_4_pb->setEnabled(false);
    ui->result_lvl_4_lbl->setText("Результат");
    ui->lvl_4_le->setText("");
}


void MainWindow::on_next_lvl_5_pb_clicked()
{
    if(current_lvl <= 5)
    {
        current_lvl=6;
        QSettings sett(ini_path, QSettings::IniFormat);
        sett.setValue("Progress/Current_progress", current_lvl);
    }
    ui->stackedWidget->setCurrentWidget(ui->lvl_6_page);
    ui->next_lvl_5_pb->setEnabled(false);
    ui->result_lvl_5_lbl->setText("Результат");
    ui->lvl_5_le->setText("");
}


void MainWindow::on_next_lvl_6_pb_clicked()
{
    if(current_lvl <= 6)
    {
        current_lvl=7;
        QSettings sett(ini_path, QSettings::IniFormat);
        sett.setValue("Progress/Current_progress", current_lvl);
    }
    ui->stackedWidget->setCurrentWidget(ui->end_lvl_page);
    ui->next_lvl_6_pb->setEnabled(false);
    ui->result_lvl_6_lbl->setText("Результат");
    ui->lvl_6_le->setText("");
}

void MainWindow::slotShortcutEsc()
{
    QApplication::quit();
}

void MainWindow::slotShortcutHelp()
{
//    qDebug()<<"h";
    (ui->next_lvl_1_pb->isEnabled())?ui->next_lvl_1_pb->setEnabled(false):ui->next_lvl_1_pb->setEnabled(true);
    (ui->next_lvl_2_pb->isEnabled())?ui->next_lvl_2_pb->setEnabled(false):ui->next_lvl_2_pb->setEnabled(true);
    (ui->next_lvl_3_pb->isEnabled())?ui->next_lvl_3_pb->setEnabled(false):ui->next_lvl_3_pb->setEnabled(true);
    (ui->next_lvl_4_pb->isEnabled())?ui->next_lvl_4_pb->setEnabled(false):ui->next_lvl_4_pb->setEnabled(true);
    (ui->next_lvl_5_pb->isEnabled())?ui->next_lvl_5_pb->setEnabled(false):ui->next_lvl_5_pb->setEnabled(true);
    (ui->next_lvl_6_pb->isEnabled())?ui->next_lvl_6_pb->setEnabled(false):ui->next_lvl_6_pb->setEnabled(true);
}


void MainWindow::on_agree_pb_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->main_page);
}


void MainWindow::on_check_lvl_1_pb_clicked()
{
    if(ui->lvl_1_le->text().toInt() == 69)
    {
        ui->result_lvl_1_lbl->setText("Успех!");
        ui->next_lvl_1_pb->setEnabled(true);
    }
    else
    {
        ui->result_lvl_1_lbl->setText("Не-а.");
    }
}


void MainWindow::on_check_lvl_2_pb_clicked()
{
    if(ui->lvl_2_le->text().toInt() == 451)
    {
        ui->result_lvl_2_lbl->setText("Успех!");
        ui->next_lvl_2_pb->setEnabled(true);
    }
    else
    {
        ui->result_lvl_2_lbl->setText("Не-а.");
    }
}


void MainWindow::on_check_lvl_3_pb_clicked()
{
    if(ui->lvl_3_le->text().toInt() == 1984)
    {
        ui->result_lvl_3_lbl->setText("Успех!");
        ui->next_lvl_3_pb->setEnabled(true);
    }
    else
    {
        ui->result_lvl_3_lbl->setText("Не-а.");
    }
}


void MainWindow::on_check_lvl_4_pb_clicked()
{
    if(ui->lvl_4_le->text().toInt() == 1337)
    {
        ui->result_lvl_4_lbl->setText("Успех!");
        ui->next_lvl_4_pb->setEnabled(true);
    }
    else
    {
        ui->result_lvl_4_lbl->setText("Не-а.");
    }
}


void MainWindow::on_check_lvl_5_pb_clicked()
{
    if(ui->lvl_5_le->text().toInt() == 34)
    {
        ui->result_lvl_5_lbl->setText("Успех!");
        ui->next_lvl_5_pb->setEnabled(true);
    }
    else
    {
        ui->result_lvl_5_lbl->setText("Не-а.");
    }
}


void MainWindow::on_check_lvl_6_pb_clicked()
{
    if(ui->lvl_6_le->text().toInt() == 123456)
    {
        ui->result_lvl_6_lbl->setText("Успех!");
        ui->next_lvl_6_pb->setEnabled(true);
    }
    else
    {
        ui->result_lvl_6_lbl->setText("Не-а.");
    }
}

