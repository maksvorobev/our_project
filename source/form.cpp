#pragma once

#include "./headers/form.h"
#include "./ui_form.h"
#include <QLineEdit>
#include <QString>


Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

}

Form::~Form()
{
    delete ui;
}

void Form::nashSlot() {
    QString str11 =ui->lineEdit->text();
    QString str12 =ui->lineEdit_2->text();
}

void Form::on_buttonBox_accepted()
{
    close();
}

void Form::on_buttonBox_rejected()
{
    close();
}
