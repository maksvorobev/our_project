#include "./headers/harmony_oscilloscope.h"

Harmony_oscilloscope::Harmony_oscilloscope() {}


void Harmony_oscilloscope::makePlotFR(){graph.makePlotFR(input_signals[0]);}

void Harmony_oscilloscope::graphShow()
{
    if(!input_signals.empty()) {graph.show();}
}

void Harmony_oscilloscope::work()
{
        makePlotFR();
        output_signal = input_signals[0];
}

void Harmony_oscilloscope::set_in_input_Signal(Signal* signal)
{
    input_signals = vector<Signal*>();
    input_signals.push_back(signal);
}

Signal* Harmony_oscilloscope::getSignal(){return output_signal;}
