#include "./ui_widget.h"
#include "./headers/widget.h"
#include <QPixmap>
#include <QMenu>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QCheckBox>
#include "./headers/logic_of_fronted/my_grpah_view.h"

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

void Widget::on_button_create_combiner_clicked()
{
    ui->graphicsView->create_combiner();
}

void Widget::on_button_create_cos_clicked()
{
    Signal* s = new Signal("/home/vboxuser/Documents/GitHub/our_project5/signals/Cos.txt");
    ui->graphicsView->create_generator(s);
}

void Widget::on_button_create_generator_clicked()
{
    form_generator.show();
}

void Widget::on_button_create_highfilter_clicked()
{
    form_filters.show();
}

void Widget::on_button_create_lowfilter_clicked()
{
    form_filters.show();
}

void Widget::on_button_create_meandr_clicked()
{
    Signal* s = new Signal("/home/vboxuser/Documents/GitHub/our_project5/signals/Meander.txt");
    ui->graphicsView->create_generator(s);
}

void Widget::on_button_create_oscilloscope_clicked()
{
    ui->graphicsView->create_oscilloscope();
}

void Widget::on_button_create_sin_clicked()
{
    Signal* s = new Signal(QString("/home/vboxuser/Documents/GitHub/our_project5/signals/Sin.txt"));
    ui->graphicsView->create_generator(s);
}

void Widget::on_button_create_transformer_clicked()
{
    form_transformer.show();
}

void Widget::on_button_start_clicked()
{
    myController->startCircuit();
}
