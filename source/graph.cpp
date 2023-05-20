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

void Graph::makePlotFR(Signal* signal)
{
    ui->customPlot->clearGraphs();
    QVector<double> x,y;

    Forward_fourier_decomposer *  fourier_decomposer = new Forward_fourier_decomposer(signal);
    fourier_decomposer->Decompose();
    vector<double> frequency = fourier_decomposer->Get_F();
    vector<double> amplitude = fourier_decomposer->Get_A_Magnitude();

    double max_elem = *max_element(amplitude.begin(), amplitude.begin()+9);



    ui->customPlot->xAxis->setRange(0, frequency[9]);
    ui->customPlot->yAxis->setRange(0, max_elem + 0.5);

    for (int i = 0; i < 10; i++){
        x.push_back(frequency[i]);
        y.push_back(amplitude[i]);
    }

    QCPBars *Bars = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    ui->customPlot->hasPlottable(Bars);
    Bars->setData(x, y);

    Bars->setWidth(0.001);
    ui->customPlot->yAxis->setLabel("Amplitude");
    ui->customPlot->xAxis->setLabel("Frequency");

    ui->customPlot->replot();


}

Graph::~Graph()
{
    delete ui;
}
