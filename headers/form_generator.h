#pragma once
#ifndef FORM_GENERATOR_H
#define FORM_GENERATOR_H

#include <QWidget>
#include <QLineEdit>

namespace Ui {
class Form_generator;
}

class Form_generator : public QWidget
{
    Q_OBJECT

public:
    explicit Form_generator(QWidget *parent = nullptr);
    ~Form_generator();


public slots:
    void nashSlot();


private slots:


    void on_buttonBox_accepted();

    void on_buttonBox_rejected();


private:
    Ui::Form_generator *ui;


};

#endif // FORM_GENERATOR_H
