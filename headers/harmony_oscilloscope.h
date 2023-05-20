#pragma once

#include <QWidget>
#include "graph.h"
#include "Signal.h"
#include "block.h"


class Harmony_oscilloscope : public Block
{
    Q_OBJECT
public:
    Harmony_oscilloscope();
    void graphShow();
    void work() override;
    void set_in_input_Signal(Signal* signal) override;
    Signal* getSignal() override;

private:
    Graph graph;

    void makePlotFR();
};

