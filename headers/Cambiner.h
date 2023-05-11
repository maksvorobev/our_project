#pragma once
#include "Signal.h"
#include "Spline.h"
#include <vector>

using std::vector;

class Cambiner {
private:
    Signal input_signal_1;
    Signal input_signal_2;
    Signal output_signal;
public:
    Cambiner(const Signal& input_signal_1, const Signal& input_signal_2);
    Cambiner();
    Signal CambineSignals();
    Signal SummarizeEqualSignals(Signal signal1, Signal signal2);
    Signal GetOutputSignal();
    vector<double> ExtendSignal(Signal signal, double T);
    void Work();
    double NOK(double T1, double T2);
    vector<Signal> FillSignals(vector<double> extended_signal1, vector<double> extended_signal2, double T, double dt1, double dt2);
};