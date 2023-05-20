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

}

void Widget::on_button_create_cos_clicked()
{

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

}

void Widget::on_button_create_oscilloscope_clicked()
{

}

void Widget::on_button_create_sin_clicked()
{

}

void Widget::on_button_create_transformer_clicked()
{
    form_transformer.show();
}

void Widget::on_button_start_clicked()
{
    myController->startCircuit();
}

void Widget::on_button_create_harmonic_oscilloscope_clicked()
{

}
