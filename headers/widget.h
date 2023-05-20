#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMenu>
#include <QPushButton>
#include <QPixmap>
#include "form_generator.h"
#include "form_filters.h"
#include "form_transformer.h"
#include "main_controller.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT


public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_button_create_combiner_clicked();

    void on_button_create_cos_clicked();

    void on_button_create_generator_clicked();

    void on_button_create_highfilter_clicked();

    void on_button_create_lowfilter_clicked();

    void on_button_create_meandr_clicked();

    void on_button_create_oscilloscope_clicked();

    void on_button_create_sin_clicked();

    void on_button_create_transformer_clicked();

    void on_button_start_clicked();

private:
    Ui::Widget *ui;
    Form_generator form_generator;
    Form_filters form_filters;
    Form_transformer form_transformer;
    Main_Controller* myController;
};


#endif // WIDGET_H

