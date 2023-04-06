#pragma once
#include <vector>
#include <complex>
#include <math.h>
#include <iostream>
#include <utility>
#include "Signal.h"
using std::vector;



class Reverse_fourier_decomposer{
private:
    const std::pair<vector<double>, vector<double>>& pr; // вектор амлитут (real(X))
    vector<double> x_m;
    const size_t size;
                        
public:
    explicit Reverse_fourier_decomposer(const std::pair<vector<double>, vector<double>>& pr);

    void Decompose();

    vector<double>  Get_array_of_values() const; // возвращает массив отсчетов сигнала
};
