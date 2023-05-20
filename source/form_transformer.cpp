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
    close();
}

void Form_transformer::on_buttonBox_rejected()
{
    close();
}

void Form_transformer::nashSlot() {
    QString str31 =ui->lineEdit->text();
    QString str32 =ui->lineEdit_2->text();
}
