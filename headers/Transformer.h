#pragma once
#include "Signal.h"
#include <vector>

using std::vector;

class Transformer {
private:
    double ampl_coef;
    double T_coef;
    Signal input_signal;
    Signal output_signal;
public:
    Transformer(const Signal& input_signal, double ample_coef, double T_coef);
    Transformer();
    void TransformSignal();
    Signal GetOutputSignal();
    void Work();
};
