#include "../headers/widget.h"
#include "./ui_widget.h"
#include <QPixmap>
#include <QMenu>
#include <QLineEdit>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    myController = new Main_Controller;

    ui->graphicsView->set_main_controller(myController);

}




Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_2_clicked()
{
    form.show();
}

void Widget::ShowWindow() {

    form.show();
}


void Widget::on_pushButton_4_clicked()
{
    myController->startCircuit();
}

