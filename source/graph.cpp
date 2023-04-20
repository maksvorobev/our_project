#include "../headers/graph.h"
#include "ui_graph.h"

Graph::Graph(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Graph)
{
    ui->setupUi(this);
}

void Graph::makePlot(Signal* signal)
{
    QVector<double> x,y;
    std::vector<double> U = signal->getU();
    double h = signal->getdt();

    int N = U.size() - 1;
    double widgh = N * h;
    double xBegin = 0;
    double xEnd = widgh;

    ui->customPlot->xAxis->setRange(-1, widgh*3 + h);
    ui->customPlot->yAxis->setRange(-1, 1);

    for (int i = 0; i < 3*N; i++){
        double X = h * i;
        x.push_back(X);
        y.push_back(U[i % N + 1]);
    }
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->addData(x,y);
    ui->customPlot->replot();
}

Graph::~Graph()
{
    delete ui;
}
