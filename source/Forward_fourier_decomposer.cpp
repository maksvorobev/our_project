#include "../headers/Forward_fourier_decomposer.h"
#include <utility>


Forward_fourier_decomposer::Forward_fourier_decomposer(const Signal& signal): signal(signal), sampling_frequency(1.0/(signal.getdt())), N(signal.getU().size()){
    X_m_m.resize(N);
    X_m_r.resize(N);
    X_m_im.resize(N);
    f_m.resize(N);
}


void Forward_fourier_decomposer::Decompose(){
    vector<double> x_n = signal.getU();
    std::cout << '\n';
    for (double m = 0.0; m < N; ++m){
        double my_real = 0;
        double my_imag = 0;
        for (double n = 0.0; n < N; ++n){
            double theta  = -m*(2.0*M_PI)*(n/N);
            my_real += x_n[n]*cos(theta);
            my_imag += x_n[n]*sin(theta);

        }
        X_m_m[m] = pow(my_real*my_real + my_imag*my_imag, 0.5)/N;
        X_m_r[m] = my_real/N;
        X_m_im[m] = my_imag/N;
        f_m[m] = (m*sampling_frequency/N);
    }

}

void Forward_fourier_decomposer::print_values() const{
    for (int i = 0; i < N; ++i){
        std::cout << "Amplitude=" << X_m_m[i] << "  " << "Frequency=" << f_m[i] << '\n';
    }
}

vector<double> Forward_fourier_decomposer::Get_A_Magnitude() const{
    return X_m_m;
}



vector<double> Forward_fourier_decomposer::Get_F() const{
    return f_m;
}


std::pair<vector<double>, vector<double>> Forward_fourier_decomposer::Get_A_Real_and_Im() const{
    return std::make_pair(X_m_r, X_m_im);
}
