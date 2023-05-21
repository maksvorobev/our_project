#include "./headers/form_filters.h"
#include "ui_form_filters.h"

Form_filters::Form_filters(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_filters)
{
    ui->setupUi(this);
}

Form_filters::~Form_filters()
{
    delete ui;
}

void Form_filters::nashSlot() {
    frequency =ui->lineEdit->text().toDouble();
}

void Form_filters::on_buttonBox_accepted()
{
    close();
}

void Form_filters::on_buttonBox_rejected()
{
    close();
}

