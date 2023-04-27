#pragma once
#include<QVector>
#include<QMainWindow>
#include"graph.h"
#include"oscilloscope.h"
#include"generator.h"
#include"main_controller.h"
#include"block_low_pass_filter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_startButton_clicked();

    void on_Oscilloscope1_clicked();

    void on_Oscilloscope2_clicked();

private:
    Ui::MainWindow *ui;
    Oscilloscope* oscilloscope1;               //KOSTYL
    Oscilloscope* oscilloscope2;
    Main_Controller main_controller;
};
