#include "../headers/block_low_pass_filter.h"


block_low_pass_filter::block_low_pass_filter(double cutoff_frequency): Block() {
    int max_input = 1;
    this->cutoff_frequency = cutoff_frequency;
}

void block_low_pass_filter::set_in_input_Signal(Signal* signal) {
    if (this->input_signals.size() < max_input)
        this->input_signals.push_back(signal);
}


Signal* block_low_pass_filter::getSignal() {
        return output_signal;
    
}

void block_low_pass_filter::work()
{
    if (ready()){
        Low_pass_filter filter(input_signals[0], cutoff_frequency);
        output_signal =  filter.Get_Signal();
        qDebug() << "filter work " << cutoff_frequency;
    }
}

bool block_low_pass_filter::ready(){
    if (this->input_signals.size() != max_input){
        return false;
    }
    return true;
}

void block_low_pass_filter::set_cutoff_frequency(double frequency)
{
    this->cutoff_frequency = frequency;
    qDebug() << frequency;
}
