#include "./headers/Cambiner.h"


Cambiner::Cambiner() : input_signals(), output_signal() {}

Signal* Cambiner::GetOutputSignal() { return output_signal; }

double Cambiner::NOK(double T1, double T2)
{
	double T3;
	int t1 = trunc(T1);
	int t2 = trunc(T2);
	
	int max = (t1 > t2) ? t1 : t2;
	while (true)
	{ 
		if ((max % t1 == 0) & (max % t2 == 0)) 
		{ 
			T3 = trunc(max);
			break;
		}
		else 
			max++;
	};

	return T3;
}

void Cambiner::SummarizeEqualSignals(Signal* signal1, Signal* signal2)
{
	vector<double> U;
    vector<double> U1 = signal1->getU();
    vector<double> U2 = signal2->getU();
    qDebug() << "ABOBUS";
    qDebug() << U1.size();
    for (int i = 0; i < signal1->getU().size(); i++) {
		U.push_back(U1[i] + U2[i]);
	}

    output_signal = new Signal(U, signal1->getdt(), signal1->getT());
}

vector<Signal*> Cambiner::FillSignals(vector<double> extended_signal1, vector<double> extended_signal2, double T, double dt1, double dt2) {
    Signal* customized_signal;
    Signal* primal_signal;
	
	if (T / dt1 > T / dt2) {
        customized_signal = new Signal(extended_signal2, dt2, T);
        primal_signal = new Signal(extended_signal1, dt1, T);
	}
	else {
        customized_signal = new Signal(extended_signal1, dt1, T);
        primal_signal = new Signal(extended_signal2, dt2, T);
	}

    vector<Signal*> filled_signals;
    filled_signals.push_back(primal_signal);
    filled_signals.push_back(customized_signal);
    return filled_signals;
}

bool Cambiner::ready()
{
    qDebug() << (input_signals.size() == max_input);
    return input_signals.size() == max_input;
}

void Cambiner::set_in_input_Signal(Signal *signal)
{
    qDebug() << "signal";
    if (input_signals.size() < max_input)
        input_signals.push_back(signal);
}

Signal *Cambiner::getSignal()
{
    qDebug() << "BEGIN";
    qDebug() << output_signal->getdt();
    qDebug() << "END";
    return output_signal;
}

void Cambiner::addInput(Block *input)
{
    this->input.push_back(input);
}

void Cambiner::addOutput(Block *output)
{
    this->output.push_back(output);
}

void Cambiner::setSignal(Signal *signal)
{
    if (input_signals.size() < max_input)
        input_signals.push_back(signal);
}

vector<double> Cambiner::ExtendSignal(Signal* signal, double T) {
	vector<double> extended_signal;

    for (int i = 0; i < int(T / signal->getT()); i++) {
        for (int j = 0; j < signal->getU().size(); j++) {
            extended_signal.push_back(signal->getU()[j]);
		}
	}

	return extended_signal;
}


Signal* Cambiner::CambineSignals() {
    Signal* input_signal_1 = input_signals[0];
    Signal* input_signal_2 = input_signals[1];
    qDebug() << "KUKU";
    if ((input_signal_1->getdt() == input_signal_2->getdt()) and (input_signal_1->getT() == input_signal_2->getT())) {
        SummarizeEqualSignals(input_signal_1, input_signal_2);
	}



    if ((input_signal_1->getdt() != input_signal_2->getdt()) and (input_signal_1->getT() == input_signal_2->getT())) {
        double T = input_signal_1->getT();
        double dt = std::max(input_signal_1->getdt(), input_signal_2->getdt());
        double dt_min = std::min(input_signal_1->getdt(), input_signal_2->getdt());
		vector<double> dt_x;
		double t = 0;

        Signal* customized_signal;
        Signal* primal_signal;

        vector<Signal*> filled_signals = FillSignals(input_signal_1->getU(), input_signal_2->getU(), T, input_signal_1->getdt(), input_signal_2->getdt());
        primal_signal = filled_signals[0];
        customized_signal = filled_signals[1];

        for (int i = 0; i < customized_signal->getU().size(); i++) {
			dt_x.push_back(t);
			t += dt;
		}

        tk::spline s(dt_x, customized_signal->getU());

		vector<double> fittable_signal;
		t = 0;
        for (int i = 0; i < primal_signal->getU().size(); i++) {
			fittable_signal.push_back(s(t));
			t += dt_min;
		}

        Signal* fitted_signal = new Signal(fittable_signal, primal_signal->getdt(), T);
        SummarizeEqualSignals(fitted_signal, primal_signal);
	}



    if ((input_signal_1->getdt() == input_signal_2->getdt()) and (input_signal_1->getT() != input_signal_2->getT())) {
        double T = NOK(input_signal_1->getT(), input_signal_2->getT());

		vector<double> extended_signal1;
		extended_signal1 = ExtendSignal(input_signal_1, T);

		vector<double> extended_signal2;
		extended_signal2 = ExtendSignal(input_signal_2, T);

        Signal* signal1 = new Signal(extended_signal1, input_signal_1->getdt(), T);
        Signal* signal2 = new Signal(extended_signal2, input_signal_2->getdt(), T);
        SummarizeEqualSignals(signal1, signal2);
	}



    if ((input_signal_1->getdt() != input_signal_2->getdt()) and (input_signal_1->getT() != input_signal_2->getT())) {
        double T = NOK(input_signal_1->getT(), input_signal_2->getT());

		vector<double> extended_signal1;
		extended_signal1 = ExtendSignal(input_signal_1, T);

		vector<double> extended_signal2;
		extended_signal2 = ExtendSignal(input_signal_2, T);

        Signal* customized_signal;
        Signal* primal_signal;

        vector<Signal*> filled_signals = FillSignals(extended_signal1, extended_signal2, T, input_signal_1->getdt(), input_signal_2->getdt());
        primal_signal = filled_signals[0];
        customized_signal = filled_signals[1];

		vector<double> dt_x;
		double t = 0;
        for (int i = 0; i < customized_signal->getU().size(); i++) {
			dt_x.push_back(t);
            t += customized_signal->getdt();
		}

        tk::spline s(dt_x, customized_signal->getU());

		vector<double> fittable_signal;
		t = 0;
        for (int i = 0; i < primal_signal->getU().size(); i++) {
			fittable_signal.push_back(s(t));
            t += primal_signal->getdt();
		}

        Signal* fitted_signal = new Signal(fittable_signal, primal_signal->getdt(), T);
        SummarizeEqualSignals(primal_signal, fitted_signal);
	}



	return output_signal;
}

void Cambiner::work(){
    if (ready())
        CambineSignals();
}
