#include "../headers/oscilloscope.h"

Oscilloscope::Oscilloscope()
{

}


void Oscilloscope::makePlot(){graph.makePlot(input_signals[0]);}

void Oscilloscope::graphShow()
{
    if(!input_signals.empty()) {graph.show();}
}

void Oscilloscope::work()
{
        makePlot();
        output_signal = input_signals[0];
}

void Oscilloscope::set_in_input_Signal(Signal* signal)
{
    input_signals = vector<Signal*>();
    input_signals.push_back(signal);
}

Signal* Oscilloscope::getSignal(){return output_signal;}
