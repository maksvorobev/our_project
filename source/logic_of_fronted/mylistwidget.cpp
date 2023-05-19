#include "./headers/logic_of_fronted/mylistwidget.h"


MyListWidget::MyListWidget(QWidget *parent): QListWidget(parent){

    this->addItem("Oscilloscope");
    this->addItem("Generator");
    this->addItem("");
    this->addItem("HighPassFilter");



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

