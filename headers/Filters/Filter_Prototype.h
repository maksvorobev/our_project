#pragma once
#include "../Signal.h"
#include "../Forward_fourier_decomposer.h"
#include "../Reverse_fourier_decomposer.h"
#include <string>


class Filter_Prototype
{
protected:
    const double cutoff_frequency;
    Signal* sg;
    Signal* Calc_Signal_Base(std::string checker);
public:
    Filter_Prototype(Signal* sg, double cutoff_frequency);
};

