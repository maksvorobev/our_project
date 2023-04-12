#include "Generator.h"

Generator::Generator(const Signal& signal) : signal(signal) {}

Generator::Generator() : signal() {}

Signal Generator::getsignal() { return signal; }

Signal Generator::CreateSignalfromObject(Signal signal) {
	this->signal = signal;
	return signal;
}

void Generator::CreateSignalfromFile(string path) {
	this->signal = Signal::Signal(path);
}