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


private slots:


    void on_buttonBox_accepted();

    void on_buttonBox_rejected();


    void on_way_to_set_signal_nums_toggled(bool checked);

    void on_way_to_set_signal_path_toggled(bool checked);

private:
    Ui::Form_generator *ui;
    double dt;
    double T;
    std::vector<double> U;
    QString path;

};

#endif // FORM_GENERATOR_H
