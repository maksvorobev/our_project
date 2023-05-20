#pragma once
#include <vector>
#include <QString>

using std::vector;


class Signal{
private:
    vector<double> U;
    double dt;
    double T;
public:
    Signal(const vector<double> U,double dt, double T);
    Signal();
    vector<double> getU();
    double getdt();
    double getT();
    Signal(QString path);

};
