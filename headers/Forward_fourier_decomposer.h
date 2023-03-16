#pragma once
#include <vector>
#include <complex>
#include <math.h>
#include <iostream>
using std::vector;


class Signal{
private:
    const vector<double> U;
    const double dt;
    const double T;
public:
    Signal(vector<double>& U,double dt, double T) : U(U), dt(dt), T(T){}
    const vector<double>& getU() const {return U;}
    double getdt() const{return dt;}
    double getT() const {return T;}

    
};



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


