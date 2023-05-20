#pragma once
#include "Signal.h"
#include <vector>
#include "block.h"

using std::vector;

class Transformer: public Block {
private:
    double ampl_coef;
    double T_coef;
    void TransformSignal();
public:
    Transformer(double ampl_coef, double T_coef);
    Transformer();

    Signal* getSignal() override;
    void set_in_input_Signal (Signal* signal) override;
    void work() override;
};
