#include "./headers/form_transformer.h"
#include "ui_form_transformer.h"

Form_transformer::Form_transformer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_transformer)
{
    ui->setupUi(this);
}

Form_transformer::~Form_transformer()
{
    delete ui;
}

void Form_transformer::on_buttonBox_accepted()
{
    ampl_coef = ui->lineEdit->text().toDouble();
    T_coef =ui->lineEdit_2->text().toDouble();
    my->create_transformer(T_coef, ampl_coef);
    close();
}

void Form_transformer::on_buttonBox_rejected()
{
    close();
}

void Form_transformer::nashSlot() {

}
