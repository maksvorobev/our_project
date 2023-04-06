#include "../headers/Reverse_fourier_decomposer.h"




Reverse_fourier_decomposer::Reverse_fourier_decomposer(const std::pair<vector<double>, vector<double>>& pr): pr(pr), size(pr.second.size()) {}

void Reverse_fourier_decomposer::Decompose(){

    for (double n = 0.0; n < size; ++n){
        double real = 0;
        double imag = 0;
        for (double m = 0.0; m < size; ++m){
            double theta  = m*(2*M_PI)*(n/size);
            real += (pr.first[m]*cos(theta) -(pr.second[m]*sin(theta)));
        }
        x_m.push_back(real);
    }
}


vector<double>  Reverse_fourier_decomposer::Get_array_of_values() const{
    return x_m;
}

