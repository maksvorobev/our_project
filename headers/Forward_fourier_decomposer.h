#pragma once
#include <vector>
#include <complex>
#include <math.h>
#include <iostream>
#include <utility>
#include "Signal.h"

using std::vector;





class Forward_fourier_decomposer{
private:
    const Signal& signal; // храним сигнал
    const double sampling_frequency; // храним частоту дискретизации
    vector<double> X_m_m; // вектор амлитут (магнитуд abs(X))
    vector<double> X_m_r; // вектор амлидут (реальная часть real(X))
    vector<double> X_m_im; // вектор мнимых частей амплитуд (im(X)) 
    vector<double> f_m; // ветор частот
    const int64_t N; // кол-во входный точек

public:
    explicit Forward_fourier_decomposer(const Signal& signal);
    void Decompose();
    void print_values() const; // функция виводит аплитуды с частотами 
    vector<double> Get_A_Magnitude() const;
    vector<double> Get_F() const;
    std::pair<vector<double>, vector<double>> Get_A_Real_and_Im() const; // возвращает прау из векторов real и img частей амлитуд 
      
};


