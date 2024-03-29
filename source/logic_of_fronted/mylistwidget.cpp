#include "./headers/logic_of_fronted/mylistwidget.h"


MyListWidget::MyListWidget(QWidget *parent): QListWidget(parent){

    this->addItem("Oscilloscope");
    this->addItem("Generator");
    this->addItem("HighPassFilter");
    this->addItem("LowPassFilter");
    this->addItem("Combiner");
    this->addItem("Transformer");
    this->addItem("HarmonyOscilloscope");

}

void MyListWidget::startDrag(Qt::DropActions supportedActions)
{
   Q_UNUSED (supportedActions)

   auto mimeData = new QMimeData ();
   mimeData->setData("application/x-item", currentItem ()->text ().toUtf8 ());

   auto drag = new QDrag(this);
   drag->setMimeData (mimeData);
   drag->exec(Qt::MoveAction);
}

