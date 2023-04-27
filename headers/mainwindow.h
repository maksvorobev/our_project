#pragma once
#include<QVector>
#include<QMainWindow>
#include"graph.h"
#include"oscilloscope.h"
#include"generator.h"
#include"main_controller.h"

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

private:
    Ui::MainWindow *ui;
    Oscilloscope* oscilloscope;
    Main_Controller main_controller;
};
