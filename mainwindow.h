#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "living_array.h"

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
    void on_del_f_clicked();
    void on_del_all_clicked();
    void on_sort_clicked();
    void on_save_f_clicked() const;
    void on_open_f_clicked();
    void on_pb_clicked() const;
    void on_add_privat_clicked();
    void on_add_tenem_clicked();
private:
    Ui::MainWindow *ui;
    Living_array liv_arr;
    void writed();
};
#endif // MAINWINDOW_H
