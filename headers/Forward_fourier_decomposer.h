#pragma once
#include <vector>
#include <complex>
#include <math.h>
#include <iostream>
#include "Signal.h"
using std::vector;





class Forward_fourier_decomposer{
private:
    const Signal& signal; // храним сигнал
    const double sampling_frequency; // храним частоту дискретизации
    vector<double> X_m; // вектор амлитут
    vector<double> f_m; // ветор частот
    const int64_t N; // кол-во входный точек

public:
    Forward_fourier_decomposer(const Signal& signal);
    void Decompose();
    void print_values() const; // функция виводит аплитуды с частотами 
      
};


