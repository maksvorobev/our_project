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
    std::pair<vector<double>, vector<double>>& pr; // вектор амлитут (real(X))
    vector<double> x_m;
    size_t size;
                        
public:
    Reverse_fourier_decomposer(std::pair<vector<double>, vector<double>>& pr);

    void Decompose();

    vector<double>  Get_array_of_values() const; // возвращает массив отсчетов сигнала
};
