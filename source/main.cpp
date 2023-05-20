#include "../headers/widget.h"
#include <QApplication>
#include<QVector>
#include<vector>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <./headers/harmony_oscilloscope.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    std::vector<double> U = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.4, 0.3, 0.2, 0.1, 0.0};
    Signal* signal = new Signal(U, 1.0, 11.0);
    Harmony_oscilloscope* ho = new Harmony_oscilloscope();
    ho->set_in_input_Signal(signal);
    ho->work();
    ho->graphShow();
    w.show();
    return a.exec();
}
