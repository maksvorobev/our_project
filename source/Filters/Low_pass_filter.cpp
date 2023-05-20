#include "../../headers/Filters/Low_pass_filter.h"



Low_pass_filter::Low_pass_filter(Signal* sg, double cutoff_frequency): Filter_Prototype(sg, cutoff_frequency) {}

Signal* Low_pass_filter::Get_Signal(){
    return Calc_Signal_Base("<=");

}
