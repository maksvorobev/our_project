#ifndef FORM_FILTERS_H
#define FORM_FILTERS_H

#include <QWidget>
#include "./headers/logic_of_fronted/my_grpah_view.h"

namespace Ui {
class Form_filters;
}

class Form_filters : public QWidget
{
    Q_OBJECT

public:
    explicit Form_filters(QWidget *parent = nullptr);
    my_grpah_view* my;
    ~Form_filters();

public slots:
    void nashSlot();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Form_filters *ui;
    double frequency;
};

#endif // FORM_FILTERS_H
