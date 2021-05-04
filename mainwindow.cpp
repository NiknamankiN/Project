#include "mainwindow.h"
#include "ui_mainwindow.h"

bool is_count(std::string s)
{
    for(long long unsigned int i = 0; i < s.length(); ++i)
        if(!isdigit(s[i]))
            return false;
    return true;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Tenement_house *u = new Tenement_house();
    Private_house *s = new Private_house("Homer","","",100,"");
    liv_arr.build_house(*u);
    liv_arr.build_house(*s);
    writed();
    ui->radioButton->setChecked(true);
    ui->listWidget->setFont(QFont("Times",14));
    ui->textEdit->setFont(QFont("Times",14));
}

void MainWindow::writed()
{
    if(liv_arr.get_num() > 0)
    {

        if(liv_arr.get_num() > 1 )
            ui->sort->setEnabled(true);
        else
            ui->sort->setEnabled(false);
    }
    ui->del_all->setEnabled(true);
    ui->del_f->setEnabled(true);
    ui->listWidget->clear();
    ui->radioButton->setChecked(true);
    Iterator uk = liv_arr.begin();
    std::string res;
    QString qres;
    Private_house *pri;
    Tenement_house *tene;
    while(!uk.end())
    {
        if((uk.get()->get_type() == "Private"))
        {
            pri = dynamic_cast<Private_house*>(uk.get());
            res =pri->get_name() + " " + pri->get_type() + " " +
                    pri->get_size() + " " +
                    std::to_string(pri->get_cost()) + " rub " +
                    pri->get_land_holder() + " " + pri->get_house_holder();
        }
        else
        {
            tene = dynamic_cast<Tenement_house*>(uk.get());
            res = tene->get_name() + " " + tene->get_type() + " " +
                    tene->get_size() + " " +
                    std::to_string(tene->get_cost()) + " rub " +
                    std::to_string(tene->get_apart()) + " flats " + tene->get_resident(1);
        }

        qres = QString::fromUtf8(res.c_str());
        QListWidgetItem *item = new QListWidgetItem(qres);
        ui->listWidget->addItem(item);
        uk.step();
    }
}

void MainWindow::on_del_f_clicked()
{
    liv_arr.del_f();
    writed();
    if (!liv_arr.get_num())
    {
        ui->del_all->setEnabled(false);
        ui->del_f->setEnabled(false);
        ui->sort->setEnabled(false);
    }
}

void MainWindow::on_del_all_clicked()
{
    liv_arr.del_all();
    writed();
    ui->del_all->setEnabled(false);
    ui->del_f->setEnabled(false);
    ui->sort->setEnabled(false);
}

void MainWindow::on_sort_clicked()
{
    liv_arr.sort_by_cost(ui->radioButton->isChecked());
    writed();
}

void MainWindow::on_open_f_clicked()
{
    QString name = ui->textEdit->toPlainText();
    ui->open_f->show();
    Living_array n;
    liv_arr.read_file(name.toUtf8().constData());
    ui->textEdit->clear();
    writed();
}

void MainWindow::on_save_f_clicked() const
{
    QString name = ui->textEdit->toPlainText();
    ui->save_f->show();
    liv_arr.write_to_file(name.toUtf8().constData());
    ui->textEdit->clear();
}

void MainWindow::on_pb_clicked() const
{
    QString x_max = ui->lineEdit->text();
    QString x_min = ui->lineEdit_2->text();
    QString path_1 = ui->lineEdit_3->text();
    double min = 0, max = 1000000000;
    std::string path = "D://new.txt";
    if (is_count(x_min.toUtf8().constData()))
        min = atoi(x_min.toUtf8().constData());
    if (is_count(x_max.toUtf8().constData()))
        max = atoi(x_max.toUtf8().constData());
    std::string p = path_1.toUtf8().constData();
    if (!p.empty())
        path = p;
    liv_arr.search_writef_by_cost(min, max, path);
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
}

void MainWindow::on_add_privat_clicked()
{
    QString one = ui->lineEdit_4->text();
    QString two = ui->lineEdit_5->text();
    QString three = ui->lineEdit_6->text();
    QString four = ui->lineEdit_7->text();
    QString five = ui->lineEdit_8->text();
    std::string po[4];

    po[1] = two.toUtf8().constData();
    po[2] = three.toUtf8().constData();
    po[3] = four.toUtf8().constData();
    po[0] = five.toUtf8().constData();
    int u;
    u = atoi(one.toUtf8().constData());
    liv_arr.build_house(*new Private_house(po[0], po[2], po[1], u, po[3]));
    writed();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
}

void MainWindow::on_add_tenem_clicked()
{
    QString one = ui->lineEdit_9->text();
    QString two = ui->lineEdit_10->text();
    QString three = ui->lineEdit_11->text();
    QString four = ui->lineEdit_12->text();
    QString five = ui->lineEdit_13->text();
    std::string po[6];
    po[0] = one.toUtf8().constData();
    po[1] = two.toUtf8().constData();
    po[2] = three.toUtf8().constData();
    po[3] = four.toUtf8().constData();
    po[4] = five.toUtf8().constData();
    int u, u1;
    u = atoi(two.toUtf8().constData());
    u1 = atoi(five.toUtf8().constData());
    liv_arr.build_house(*new Tenement_house(po[0], po[3], po[2], u, u1));
    writed();
    ui->lineEdit_9->clear();
    ui->lineEdit_10->clear();
    ui->lineEdit_11->clear();
    ui->lineEdit_12->clear();
    ui->lineEdit_13->clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}

