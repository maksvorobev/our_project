#pragma once

#include <QWidget>
#include "graph.h"
#include "Signal.h"
#include "block.h"

class Oscilloscope : public Block
{
    Q_OBJECT
public:
    Oscilloscope();
    void makePlot();
    void graphShow();
    void work() override;
    void setSignal(Signal* signal) override;
    Signal* getSignal() override;







private:
    Graph graph;

};

