#pragma once
#include "Signal.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream> 

using std::vector;
using std::string;

class Generator {
private:
    Signal signal;
public:
    Generator(const Signal& signal);
    Generator();
    Signal CreateSignalfromObject(Signal signal);
    void CreateSignalfromFile(string path);
    Signal getsignal();
};
