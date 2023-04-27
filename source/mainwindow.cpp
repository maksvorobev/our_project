#include "../headers/mainwindow.h"
#include "../ui_mainwindow.h"
#include "signal.h"
#include<algorithm>
#include<iostream>
#include "../headers/main_controller.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::vector<double> U = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.4, 0.3, 0.2, 0.1, 0.0};
    Signal* signal = new Signal(U, 1.0, 11.0);
    //Low_pass_filter* low_filter = new Low_pass_filter();
    Generator* generator = new Generator(signal);
    this->oscilloscope = new Oscilloscope();
    generator->addOutput(oscilloscope);
    main_controller.addGenerator(generator);
}


void MainWindow::on_pushButton_clicked()
{   
    oscilloscope->graphShow();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    main_controller.startCircuit();

}
