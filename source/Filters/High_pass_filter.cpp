#include "../../headers/Filters/High_pass_filter.h"



High_pass_filter::High_pass_filter(Signal* sg, double cutoff_frequency): Filter_Prototype(sg, cutoff_frequency) {}

Signal* High_pass_filter::Get_Signal(){
    return Calc_Signal_Base(">=");

}

