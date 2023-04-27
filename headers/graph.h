#pragma once

#include "Signal.h"
#include <QWidget>

namespace Ui {
class Graph;
}

class Graph : public QWidget
{
    Q_OBJECT

public:
    explicit Graph(QWidget *parent = nullptr);
    void makePlot(Signal* signal);

    ~Graph();

private:
    Ui::Graph *ui;
};
