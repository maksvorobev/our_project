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
    block_low_pass_filter* low_filter = new block_low_pass_filter(0.15);
    this->oscilloscope1 = new Oscilloscope();
    this->oscilloscope2 = new Oscilloscope();
    generator->addOutput(oscilloscope1);
    oscilloscope1->addOutput(low_filter);
    low_filter->addOutput(oscilloscope2);
    main_controller.addGenerator(generator);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    main_controller.startCircuit();

}

<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes
void MainWindow::on_Oscilloscope1_clicked()
{
    oscilloscope1->graphShow();
}

<<<<<<< Updated upstream
=======


>>>>>>> Stashed changes
void MainWindow::on_Oscilloscope2_clicked()
{
    oscilloscope2->graphShow();
}
