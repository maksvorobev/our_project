#pragma once
#include "Signal.h"
#include "block.h"
#include <vector>
#include <QString>
#include <fstream>
#include <iostream>

using std::vector;
using std::string;

class Generator: public Block {

public:
    Generator(Signal* signal);
    Generator();
    Generator(QString path);
    void setSignal(Signal* signal);
    void work() override;
    Signal* getSignal() override;
};
