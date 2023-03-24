#pragma once
#include <vector>
using std::vector;


class Signal{
private:
    const vector<double> U;
    const double dt;
    const double T;
public:
    Signal(vector<double>& U,double dt, double T);
    const vector<double>& getU() const;
    double getdt() const;
    double getT() const ;

    
};