#ifndef FORM_FILTERS_H
#define FORM_FILTERS_H

#include <QWidget>

namespace Ui {
class Form_filters;
}

class Form_filters : public QWidget
{
    Q_OBJECT

public:
    explicit Form_filters(QWidget *parent = nullptr);
    ~Form_filters();

public slots:
    void nashSlot();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Form_filters *ui;
};

#endif // FORM_FILTERS_H
