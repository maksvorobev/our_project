#pragma once

#include "./headers/form_generator.h"
#include "ui_form_generator.h"
#include <QLineEdit>
#include <QString>


Form_generator::Form_generator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_generator)
{
    ui->setupUi(this);

}

Form_generator::~Form_generator()
{
    delete ui;
}

void Form_generator::nashSlot() {
    QString str11 =ui->lineEdit->text();
    QString str12 =ui->lineEdit_2->text();
    QString str13 =ui->lineEdit_3->text();
    QString str14 =ui->lineEdit_4->text();
}

void Form_generator::on_buttonBox_accepted()
{
    close();
}

void Form_generator::on_buttonBox_rejected()
{
    close();
}
