#pragma once
#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QLineEdit>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();


public slots:
    void nashSlot();


private slots:


    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Form *ui;


};

#endif // FORM_H
