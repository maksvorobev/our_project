#include "../headers/graph.h"
#include "ui_graph.h"
#include <algorithm>

Graph::Graph(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Graph)
{
    ui->setupUi(this);
}


void Graph::makePlot(Signal* signal)
{
    ui->customPlot->clearGraphs();
    QVector<double> x,y;
    std::vector<double> U = signal->getU();
    double h = signal->getdt();

    int N = U.size() - 1;
    double widgh = N * h;
    double xBegin = 0;
    double xEnd = widgh;
    double max_elem = *max_element(U.begin(), U.end());
    double min_elem = *min_element(U.begin(), U.end());
    ui->customPlot->xAxis->setRange(-1, widgh*3 + h);
    ui->customPlot->yAxis->setRange(-std::max(abs(min_elem), abs(max_elem)),std::max(abs(min_elem), abs(max_elem)));

    for (int i = 0; i < 3*N; i++){
        double X = h * i;
        x.push_back(X);
        y.push_back(U[i % N + 1]);
    }
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->addData(x,y);
    ui->customPlot->replot();

    ui->customPlot->yAxis->setLabel("Amplitude");
    ui->customPlot->xAxis->setLabel("Time(mcs)");
}

Graph::~Graph()
{
    delete ui;
}
