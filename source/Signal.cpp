#include "../headers/Signal.h"





Signal::Signal(const vector<double>& U,double dt, double T) : U(U), dt(dt), T(T){}

const vector<double>& Signal::getU() const {return U;}

double Signal::getdt() const{return dt;}

double Signal::getT() const {return T;}

