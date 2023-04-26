#pragma ones
#include "Signal.h"
#include "Forward_fourier_decomposer.h"
#include "Reverse_fourier_decomposer.h"

class Low_pass_filter{
private:
    const double cutoff_frequency;
    const Signal& sg;

public:
    Low_pass_filter();
    Low_pass_filter(const Signal& sg, double cutoff_frequency);
    Signal Get_Signal();

};


