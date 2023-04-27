#include "../headers/Signal.h"





Signal::Signal(const vector<double>& U,double dt, double T) : U(U), dt(dt), T(T){}

Signal::Signal(std::string path): U({0, 0, 0, 0, 0, 0, 0, 0, 0, 0}), dt(0.01), T(0.1){}

Signal::Signal(): U({0, 0, 0, 0, 0, 0, 0, 0, 0, 0}), dt(0.01), T(0.1) {}

const vector<double>& Signal::getU() const {return U;}

double Signal::getdt() const{return dt;}

double Signal::getT() const {return T;}

