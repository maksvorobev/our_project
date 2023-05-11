#include "./headers/logic_of_fronted/my_grpah_view.h"
#include <QDropEvent>
#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QLayout>
#include <QMimeData>
#include <QLabel>


void my_grpah_view::dropEvent(QDropEvent *event)
{
    qDebug() << "drop";
   auto t = event->mimeData()->data("application/x-item");

   if (!t.isEmpty ())
   {
        if (t == "Oscilloscope"){
            FrontedOscilloscope* oscilloscope = new FrontedOscilloscope(&myMap);
            MoveItem *item = new MoveItem(nullptr, scene, oscilloscope);
            Oscilloscope* BackendOscilloscope = new Oscilloscope;
            myMap[item->getLabel()->getIndex()] = BackendOscilloscope;
            item->setPos(event->pos());
            qDebug() << event->pos().x() << "  " << event->pos().y() << " " << item->isVisible();
            scene->addItem(item);
        }
        if (t == "Generator"){
            FrontedGenerator* oscilloscope = new FrontedGenerator(&myMap);
            MoveItem *item = new MoveItem(nullptr, scene, oscilloscope);
            vector<double> U = {0, 1, 2, 3, 4, 3, 2, 1, 0};
            Signal* s = new Signal(U, 1, 9);
            Generator* BackendGenerator = new Generator(s);
            myController.addGenerator(BackendGenerator);
            myMap[item->getLabel()->getIndex()] = BackendGenerator;
            item->setPos(event->pos());
            qDebug() << event->pos().x() << "  " << event->pos().y() << " " << item->isVisible();
            scene->addItem(item);
        }
        else {
            /*
        VirualLabel* lb = new QLabel;
        MoveItem *item = new MoveItem(nullptr, scene, lb);
        item->setPos(event->pos());
        scene->addItem(item);
        //item->show();
        */
        }


/*
      auto label = new QLabel (t, this);
      label->setFixedSize(100, 50);
      label->setStyleSheet("background-color: green;");
      //label->move(event->pos());
      scene->addItem(label);
      label->show();
*/





      //setStyleSheet ("background-color: rgba(255, 0, 0, 1);");
       setStyleSheet ("background-color: white;");
   }
   //for (auto [x, y]: myMap->getMap()){
       //qDebug() << x << "   " << y;
   //}
   event->accept ();
}

void my_grpah_view::dragEnterEvent(QDragEnterEvent *event)
{
   event->accept ();

   //setStyleSheet ("background-color: rgba(0, 0, 0, 0.5);");
   setStyleSheet ("background-color: white;");
}

void my_grpah_view::dragLeaveEvent(QDragLeaveEvent *event)
{
   event->accept ();

   //setStyleSheet ("background-color: rgba(0, 0, 0, 1);");
   setStyleSheet ("background-color: white;");
}

void my_grpah_view::dragMoveEvent(QDragMoveEvent *event)
{
    event->acceptProposedAction();
}

my_grpah_view::my_grpah_view()
{
}

my_grpah_view::my_grpah_view(QWidget *parent): QGraphicsView(parent)
{
    setAcceptDrops(true);
    //setStyleSheet ("background-color: rgba(255, 0, 0, 1);");
    setStyleSheet ("background-color: white;");


    // работа со сценой

    scene.reset(new QGraphicsScene(this));   // Инициализируем графическую сцену
    scene->setItemIndexMethod(QGraphicsScene::NoIndex); // настраиваем индексацию элементов

    //this->resize(600,600);  // Устанавливаем размер graphicsView

    this->setScene(scene.get());  // Устанавливаем графическую сцену в graphicsView
    this->setRenderHint(QPainter::Antialiasing);    // Настраиваем рендер
    this->setCacheMode(QGraphicsView::CacheBackground); // Кэш фона
    this->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    scene->setSceneRect(0,0,1000,1000); // Устанавливаем размер сцены0, 0, 1000, 1000); // Устанавливаем размер сцены


}










