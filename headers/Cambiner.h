#pragma once
#include "Signal.h"
#include "Spline.h"
#include "block.h"
#include <vector>
#include <QDebug>

using std::vector;

class Cambiner : public Block {
private:
    std::vector<Signal*> input_signals;
    Signal* output_signal;
    std::vector<Block*> input;
    std::vector<Block*> output;
    int max_input {2};
public:
    Cambiner(Signal* input_signal_1, Signal* input_signal_2);
    Cambiner();
    Signal* CambineSignals();
    void SummarizeEqualSignals(Signal* signal1, Signal* signal2);
    Signal* GetOutputSignal();
    vector<double> ExtendSignal(Signal* signal, double T);
    void work() override;
    double NOK(double T1, double T2);
    vector<Signal*> FillSignals(vector<double> extended_signal1, vector<double> extended_signal2, double T, double dt1, double dt2);
    bool ready();
    void set_in_input_Signal(Signal* signal) override;
    Signal* getSignal() override;
    void addInput(Block* input);
    void addOutput(Block* output);
    void setSignal(Signal* signal);
};
