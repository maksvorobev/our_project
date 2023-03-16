#include "../headers/Forward_fourier_decomposer.h"


Forward_fourier_decomposer::Forward_fourier_decomposer(const Signal& signal): signal(signal), sampling_frequency(1.0/(signal.getdt())), N(signal.getU().size()){
    X_m.resize(N);
    f_m.resize(N);
}


void Forward_fourier_decomposer::Decompose(){
    vector<double> x_n = signal.getU();
    //std::cout << 1.0/signal.getdt();
    /*
    for (auto x : x_n){
        std::cout << x << ' ';
    }
    */
    for (double m = 0.0; m < N; ++m){
        //double X_m = 0.0;
        std::complex<double> ans = {0, 0};
        for (double n = 0.0; n < N; ++n){
            std::complex<double> curr = {cos((2.0*M_PI*n*m)/(N)), -sin((2.0*M_PI*n*m)/(N))};
            curr *= x_n[n];
            ans += curr;
            //X_m[m] = abs(ans);
            //cout << typeid(abs(ans)).name();
            
        }
        //cout << ans << '\n';
        X_m[m] = abs(ans);
        //cout << atan(ans.imag()/ans.real())*(180/PI) << '\n'; // grade
        f_m[m] = (m*sampling_frequency/N);
    }

}

void Forward_fourier_decomposer::print_values() const{
    for (int i = 0; i < N; ++i){
        std::cout << "Amplitude=" << X_m[i] << "  " << "Frequency=" << f_m[i] << '\n';
    }
}

