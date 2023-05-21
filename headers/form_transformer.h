#ifndef FORM_TRANSFORMER_H
#define FORM_TRANSFORMER_H

#include <QWidget>
#include "./headers/logic_of_fronted/my_grpah_view.h"

namespace Ui {
class Form_transformer;
}

class Form_transformer : public QWidget
{
    Q_OBJECT

public:
    explicit Form_transformer(QWidget *parent = nullptr);
    my_grpah_view* my;
    ~Form_transformer();

public slots:
    void nashSlot();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Form_transformer *ui;
    double ampl_coef;
    double T_coef;
};

#endif // FORM_TRANSFORMER_H
