#include "./headers/logic_of_fronted/mylistwidget.h"


MyListWidget::MyListWidget(QWidget *parent): QListWidget(parent){

    this->addItem("Oscilloscope");
    this->addItem("Generator");
    this->addItem("2");
    this->addItem("3");
    this->addItem("4");

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
