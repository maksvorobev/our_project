#include "./headers/transformer.h"
#include <vector>

Transformer::Transformer() : ampl_coef(0), T_coef(0) {}

Transformer::Transformer(double ampl_coef, double T_coef) : ampl_coef(ampl_coef), T_coef(T_coef) {}

Signal Transformer::getSignal() { return output_signal; }

void Transformer::TransformSignal() {
    double T = input_signal.getT() / T_coef;
    double dt = input_signal.getdt() / T_coef;
    vector<double> U;
    for (int i = 0; i < input_signal.getU().size(); i++) {
        U.push_back(ampl_coef * input_signal.getU()[i]);
    }
    this->output_signal = Signal(U, dt, T);
}

void Transformer::Work() {
    TransformSignal();
}
