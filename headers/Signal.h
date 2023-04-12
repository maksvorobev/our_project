#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using std::vector;
using std::string;


class Signal {
private:
    vector<double> U;
    double dt;
    double T;
public:
    Signal(vector<double>& U, double dt, double T);
    Signal(string path);
    Signal();
    const vector<double>& getU();
    double getdt();
    double getT();
};