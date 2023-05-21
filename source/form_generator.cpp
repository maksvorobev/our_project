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

void Form_generator::on_buttonBox_accepted()
{
    if (ui->way_to_set_signal_nums->isChecked())
    {
        dt = ui->lineEdit->text().toDouble();
        T = ui->lineEdit_2->text().toDouble();
        QString temp_str = ui->lineEdit_3->text();
        QStringList list_str = temp_str.split(' ');
        for (int i = 0; i < list_str.size(); i++)
        {
            U.push_back(list_str[i].toDouble());
        }
    }
    if (ui->way_to_set_signal_path->isChecked())
    {
        path = ui->lineEdit_4->text();
    }
    close();
}

void Form_generator::on_buttonBox_rejected()
{
    close();
}
