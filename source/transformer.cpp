#include "./headers/transformer.h"
#include <vector>

Transformer::Transformer() : ampl_coef(0), T_coef(0) {}

Transformer::Transformer(double ampl_coef, double T_coef) : ampl_coef(ampl_coef), T_coef(T_coef) {}

Signal* Transformer::getSignal() { return output_signal; }

void Transformer::setT_coef(double newT_coef)
{
    T_coef = newT_coef;
}

void Transformer::setAmpl_coef(double newAmpl_coef)
{
    ampl_coef = newAmpl_coef;
}

void Transformer::TransformSignal() {
    double T = input_signals[0]->getT() / T_coef;
    double dt = input_signals[0]->getdt() / T_coef;
    vector<double> U;
    for (int i = 0; i < input_signals[0]->getU().size(); i++) {
        U.push_back(ampl_coef * input_signals[0]->getU()[i]);
    }
    this->output_signal = new Signal(U, dt, T);
}

void Transformer::work() {
    TransformSignal();
}

void Transformer::set_in_input_Signal(Signal* signal)
{
    input_signals = vector<Signal*>();
    input_signals.push_back(signal);
}
