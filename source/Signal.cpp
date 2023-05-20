#include "../headers/Signal.h"
#include<QFile>
#include<QTextStream>





Signal::Signal(const vector<double> U,double dt, double T) : U(U), dt(dt), T(T){}

Signal::Signal(QString path)
{
    QFile file(path);
    QTextStream stream(&file);
    if (file.open(QFile::ReadOnly | QFile::Text))
    {
        this->dt = stream.readLine().toDouble();
        this->T = stream.readLine().toDouble();
        while (!stream.atEnd())
        {
            this->U.push_back(stream.readLine().toDouble());
        }
        file.close();
    }
}

Signal::Signal(): U({0, 0, 0, 0, 0, 0, 0, 0, 0, 0}), dt(0.01), T(0.1) {}

vector<double> Signal::getU() {return U;}

double Signal::getdt() {return dt;}

double Signal::getT() {return T;}

