#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMenu>
#include <QPushButton>
#include <QPixmap>
#include "./headers/form.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void ShowWindow();
    void on_pushButton_2_clicked();


private slots:
    void on_pushButton_4_clicked();

private:
    Ui::Widget *ui;
    Form form;
};
#endif // WIDGET_H
