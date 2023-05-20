#pragma once
#include "./headers/block.h"
#include "./Filters/High_pass_filter.h"
#include <QSharedPointer>
#include <QDebug>



class block_high_pass_filter: public Block{
private:
    double cutoff_frequency;
public:
    block_high_pass_filter(double cutoff_frequency = 1e9);
    void set_in_input_Signal(Signal* signal) override ;
    Signal* getSignal() override;
    void work() override;
    bool ready();
    void set_cutoff_frequency(double frequency);


};


