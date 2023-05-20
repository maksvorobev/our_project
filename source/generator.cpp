#include "../headers/generator.h"

Generator::Generator(Signal* signal)
{
    output_signal = signal;
}

Generator::Generator(){}

Generator::Generator(QString path)
{
    Signal* signal = new Signal(path);
    output_signal = signal;
}

void Generator::setSignal(Signal* signal)
{
    output_signal = signal;
}

Signal* Generator::getSignal() { return output_signal; }

void Generator::work() {}
