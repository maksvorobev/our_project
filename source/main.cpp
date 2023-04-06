#include "../headers/mainwindow.h"

#include <QApplication>
#include "../headers/Forward_fourier_decomposer.h"
#include "../headers//Signal.h"
#include <vector>
#include <../headers/qcustomplot.h>
#include "../headers/Reverse_fourier_decomposer.h"
int main(int argc, char *argv[])
{
    vector<double> v = {100, 12, 0.001, 0.25};

    Signal s(v, 100, 100);
    Forward_fourier_decomposer F(s);
    F.Decompose();
    F.print_values();
    std::pair<vector<double>, vector<double>> pr = F.Get_A_Real_and_Im();
    
    std::cout << '\n';
    //std::cout <<  pr.first[0] << ' ' << pr.second[0] << '\n';
    /*
    for (int i = 0; i < pr.first.size(); ++i){
        std::cout << pr.first[i] << "   " << pr.second[i]  << '\n';
    }
    */
    
    
    
    Reverse_fourier_decomposer R(pr);
    R.Decompose();
    vector<double> aa = R.Get_array_of_values();
    

     
    std::cout << '\n';

    for (auto x : aa){
        std::cout << x << '\n';
    }
    


    //QScatterSeries *series0 = new QScatterSeries();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
