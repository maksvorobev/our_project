#include "../headers/widget.h"
#include <QApplication>
#include<QVector>
#include<vector>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::vector<double> signal = {0.1, 0, 0.01, 0.02, 0.03, 0.04, 0.05, 0.04, 0.03, 0.02, 0.01};
    Widget w;
    w.show();
    return a.exec();
}
