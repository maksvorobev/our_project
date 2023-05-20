#pragma ones
#include "../Signal.h"
#include "../Forward_fourier_decomposer.h"
#include "../Reverse_fourier_decomposer.h"

class High_pass_filter{
private:
    const double cutoff_frequency;
    Signal* sg;

public:
    High_pass_filter(Signal* sg, double cutoff_frequency);
    Signal* Get_Signal();

};

