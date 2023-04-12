#include "Signal.h"

Signal::Signal(vector<double>& U, double dt, double T) : U(U), dt(dt), T(T) {}

Signal::Signal() : U(vector <double> ()), dt(0), T(0) {}

Signal::Signal(string path) {
	std::ifstream signal(path);
	int i = 1;
	char tmp;
	string tmpstr;
	double tm;
	while (!signal.eof()) {
		signal.get(tmp);
		if (tmp != ' ') {
			tmpstr.push_back(tmp);
		}
		else{
			tm = atof(tmpstr.c_str());
			tmpstr = "";
			if (i == 1) {
				this->T = tm;
			}
			if (i == 2) {
				this->dt = tm;
			}
			if (i > 2) {
				U.push_back(tm);
			}
			i++;
		}
	}
	tmpstr.erase(tmpstr.size() - 1);
	tm = atof(tmpstr.c_str());
	U.push_back(tm);
}

const vector<double>& Signal::getU() { return U; }

double Signal::getdt() { return dt; }

double Signal::getT() { return T; }