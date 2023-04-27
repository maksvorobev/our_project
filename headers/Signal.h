#pragma once
#include <vector>
#include <string>
using std::vector;


class Signal{
private:
    const vector<double> U;
    const double dt;
    const double T;
public:
    Signal(const vector<double>& U,double dt, double T);
    Signal();
    const vector<double>& getU() const;
    double getdt() const;
    double getT() const ;
    Signal(std::string path);

};
