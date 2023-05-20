#pragma once

#include "Signal.h"
#include <QWidget>
#include "Forward_fourier_decomposer.h"

namespace Ui {
class Graph;
}

class Graph : public QWidget
{
    Q_OBJECT

public:
    explicit Graph(QWidget *parent = nullptr);

    void makePlot(Signal* signal);

    void makePlotFR(Signal* signal);

    ~Graph();

private:
    Ui::Graph *ui;
};
