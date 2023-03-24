#include "../headers/mainwindow.h"

#include <QApplication>

#include "../headers/Forward_fourier_decomposer.h"

int main(int argc, char *argv[])
{

    vector<double> v = {0, -0.00637057, -0.0127409, -0.0191107, -0.0254797, -0.0318477, -0.0382144, -0.0445795};
    Signal sg(v, 1.0/8000, 8.0*(1/8000));
    Forward_fourier_decomposer four(sg);
    four.Decompose();
    four.print_values();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
