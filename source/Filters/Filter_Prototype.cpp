#include "../../headers/Filters/Filter_Prototype.h"



Filter_Prototype::Filter_Prototype(Signal* sg, double cutoff_frequency): cutoff_frequency(cutoff_frequency), sg(sg) {}

Signal *Filter_Prototype::Calc_Signal_Base(std::string checker)
{
    if (checker == "<="){
        Forward_fourier_decomposer Forward(sg);
        Forward.Decompose();
        vector<double> Frequencies = Forward.Get_F();
        std::pair<vector<double>, vector<double>> p = Forward.Get_A_Real_and_Im();

        Reverse_fourier_decomposer R(p);
        R.Decompose();
        vector<double> aa = R.Get_array_of_values();
        vector<double> A_real_new;
        vector<double> A_imag_new;
        for (size_t i = 0; i < p.first.size(); ++i){
            if (Frequencies[i] <= cutoff_frequency){
                A_real_new.push_back(p.first[i]);
                A_imag_new.push_back(p.second[i]);
            }
            else {
                A_real_new.push_back(0);
                A_imag_new.push_back(0);
            }
        }
        std::pair<vector<double>, vector<double>> pp = make_pair(A_real_new, A_imag_new);
        Reverse_fourier_decomposer Reverse(pp);
        Reverse.Decompose();
        //vector<double> ans = Reverse.Get_array_of_values();
        return new Signal(Reverse.Get_array_of_values(), sg->getdt(), sg->getT());
    }
    if (checker == ">="){
        Forward_fourier_decomposer Forward(sg);
        Forward.Decompose();
        vector<double> Frequencies = Forward.Get_F();
        std::pair<vector<double>, vector<double>> p = Forward.Get_A_Real_and_Im();

        Reverse_fourier_decomposer R(p);
        R.Decompose();
        vector<double> aa = R.Get_array_of_values();
        vector<double> A_real_new;
        vector<double> A_imag_new;
        for (size_t i = 0; i < p.first.size(); ++i){
            if (Frequencies[i] >= cutoff_frequency){
                A_real_new.push_back(p.first[i]);
                A_imag_new.push_back(p.second[i]);
            }
            else {
                A_real_new.push_back(0);
                A_imag_new.push_back(0);
            }
        }
        std::pair<vector<double>, vector<double>> pp = make_pair(A_real_new, A_imag_new);
        Reverse_fourier_decomposer Reverse(pp);
        Reverse.Decompose();
        //vector<double> ans = Reverse.Get_array_of_values();
        return new Signal(Reverse.Get_array_of_values(), sg->getdt(), sg->getT());
    }
}

