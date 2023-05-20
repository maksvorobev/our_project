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
    w.show();
    return a.exec();
}
