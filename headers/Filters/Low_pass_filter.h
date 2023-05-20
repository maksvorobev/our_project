#pragma once
#include "Filter_Prototype.h"

class Low_pass_filter: public Filter_Prototype{
public:
    Low_pass_filter(Signal* sg, double cutoff_frequency);
    Signal* Get_Signal();

};


