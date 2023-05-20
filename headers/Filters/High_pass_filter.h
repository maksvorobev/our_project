#pragma once
#include "Filter_Prototype.h"

class High_pass_filter: public Filter_Prototype{
public:
    High_pass_filter(Signal* sg, double cutoff_frequency);
    Signal* Get_Signal();

};

