#pragma once
#include "Signal.h"
#include <vector>
#include "block.h"

using std::vector;

class Transformer: public Block {
private:
    double ampl_coef;
    double T_coef;
public:
    Transformer(double ampl_coef, double T_coef);
    Transformer();
    void TransformSignal();
    Signal getSignal();
    void work();
};
