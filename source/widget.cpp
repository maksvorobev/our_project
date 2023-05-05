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



    QMenu* menu1 = new QMenu(this);

    QAction* act1 = new QAction("фильтр 1");
    connect(act1, &QAction::triggered, this, &Widget::ShowWindow);
    QAction* act2 = new QAction("фильтр 2");
    connect(act2, &QAction::triggered, this, &Widget::ShowWindow);
    QAction* act3 = new QAction("фильтр 3");
    connect(act3, &QAction::triggered, this, &Widget::ShowWindow);
    QAction* act4 = new QAction("фильтр по функции...");
    connect(act4, &QAction::triggered, this, &Widget::ShowWindow);

    menu1->addAction(act1);
    menu1->addAction(act2);
    menu1->addAction(act3);
    menu1->addAction(act4);
    ui->pushButton_3->setMenu(menu1);

    QAction* act21 = new QAction("sin");
    connect(act21, &QAction::triggered, this, &Widget::ShowWindow);
    QAction* act22 = new QAction("прямоугольный");
    connect(act22, &QAction::triggered, this, &Widget::ShowWindow);
    QAction* act23 = new QAction("треугольный");
    connect(act23, &QAction::triggered, this, &Widget::ShowWindow);
    QAction* act24 = new QAction("задать свой сигнал...");
    connect(act24, &QAction::triggered, this, &Widget::ShowWindow);

    QMenu* menu2 = new QMenu(this);
    menu2->addAction(act21);
    menu2->addAction(act22);
    menu2->addAction(act23);
    menu2->addAction(act24);
    ui->pushButton_8->setMenu(menu2);

    QMenu* menu3 = new QMenu(this);
    menu3->addAction(tr("чевото там"));
    menu3->addAction(tr("И еще чтото (помощь)"));
    ui->pushButton_9->setMenu(menu3);

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







