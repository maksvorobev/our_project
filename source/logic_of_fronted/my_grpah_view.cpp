#include "./headers/logic_of_fronted/my_grpah_view.h"
#include <QDropEvent>
#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QLayout>
#include <QMimeData>
#include <QLabel>

void my_grpah_view::create_oscilloscope()
{
    FrontedOscilloscope* oscilloscope = new FrontedOscilloscope(&myMap);
    MoveItem *item = new MoveItem(nullptr, scene, oscilloscope);
    Oscilloscope* BackendOscilloscope = new Oscilloscope;
    myMap[item->getLabel()->getIndex()] = BackendOscilloscope;
    item->setPos(QPoint(50, 50));
    scene->addItem(item);
}
void my_grpah_view::create_generator(Signal* s)
{
    FrontedGenerator* generator = new FrontedGenerator(&myMap);
    MoveItem *item = new MoveItem(nullptr, scene, generator);
    Generator* BackendGenerator = new Generator(s);
    myController->addGenerator(BackendGenerator);
    myMap[item->getLabel()->getIndex()] = BackendGenerator;
    item->setPos(QPoint(50, 50));
    scene->addItem(item);
}
void my_grpah_view::create_high_pass_filter()
{
    FrontedHighPassFilter* high_pass_filter = new FrontedHighPassFilter(&myMap);
    MoveItem *item = new MoveItem(nullptr, scene, high_pass_filter);
    block_high_pass_filter* high_filter = new block_high_pass_filter;
    myMap[item->getLabel()->getIndex()] = high_filter;
    item->setPos(QPoint(50, 50));
    scene->addItem(item);
}
void my_grpah_view::create_low_pass_filter()
{
    FrontedLowPassFilter* low_pass_filter = new FrontedLowPassFilter(&myMap);
    MoveItem *item = new MoveItem(nullptr, scene, low_pass_filter);
    block_low_pass_filter* low_filter = new block_low_pass_filter;
    myMap[item->getLabel()->getIndex()] = low_filter;
    item->setPos(QPoint(50, 50));
    scene->addItem(item);
}
void my_grpah_view::create_combiner()
{
    FrontedCombiner* fronted_combiner = new FrontedCombiner(&myMap);
    MoveItem *item = new MoveItem(nullptr, scene, fronted_combiner);
    Cambiner* combiner = new Cambiner;
    myMap[item->getLabel()->getIndex()] = combiner;
    item->setPos(QPoint(50, 50));
    scene->addItem(item);
}
void my_grpah_view::create_harmony_oscilloscope()
{
    FrontedHarmonyOscilloscope* oscilloscope = new FrontedHarmonyOscilloscope(&myMap);
    MoveItem *item = new MoveItem(nullptr, scene, oscilloscope);
    Harmony_oscilloscope* BackendOscilloscope = new Harmony_oscilloscope;
    myMap[item->getLabel()->getIndex()] = BackendOscilloscope;
    item->setPos(QPoint(50, 50));
    scene->addItem(item);
}
void my_grpah_view::create_transformer(double T_coef, double a_coef)
{
    FrontedTransformer* transformer = new FrontedTransformer(&myMap);
    MoveItem *item = new MoveItem(nullptr, scene, transformer);
    Transformer* BackendTransformer= new Transformer;
    myMap[item->getLabel()->getIndex()] = BackendTransformer;
    BackendTransformer->setAmpl_coef(a_coef);
    BackendTransformer->setT_coef(T_coef);
    item->setPos(QPoint(50, 50));
    scene->addItem(item);
}
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
            myController->addGenerator(BackendGenerator);
            myMap[item->getLabel()->getIndex()] = BackendGenerator;
            item->setPos(event->pos());
            qDebug() << event->pos().x() << "  " << event->pos().y() << " " << item->isVisible();
            scene->addItem(item);
        }
        if (t == "HighPassFilter"){
            FrontedHighPassFilter* oscilloscope = new FrontedHighPassFilter(&myMap);
            MoveItem *item = new MoveItem(nullptr, scene, oscilloscope);
            block_high_pass_filter* high_filter = new block_high_pass_filter;
            myMap[item->getLabel()->getIndex()] = high_filter;
            item->setPos(event->pos());
            qDebug() << event->pos().x() << "  " << event->pos().y() << " " << item->isVisible();
            scene->addItem(item);
        }
        if (t == "LowPassFilter"){
            FrontedLowPassFilter* oscilloscope = new FrontedLowPassFilter(&myMap);
            MoveItem *item = new MoveItem(nullptr, scene, oscilloscope);
            block_low_pass_filter* low_filter = new block_low_pass_filter;
            myMap[item->getLabel()->getIndex()] = low_filter;
            item->setPos(event->pos());
            qDebug() << event->pos().x() << "  " << event->pos().y() << " " << item->isVisible();
            scene->addItem(item);
        }
        if (t == "Combiner"){
            FrontedCombiner* fronted_combiner = new FrontedCombiner(&myMap);
            MoveItem *item = new MoveItem(nullptr, scene, fronted_combiner);
            Cambiner* combiner = new Cambiner;
            myMap[item->getLabel()->getIndex()] = combiner;
            item->setPos(event->pos());
            qDebug() << event->pos().x() << "  " << event->pos().y() << " " << item->isVisible();
            scene->addItem(item);
        }

       setStyleSheet ("background-color: white;");
   }

   event->accept ();
}

void my_grpah_view::dragEnterEvent(QDragEnterEvent *event)
{
   event->accept ();
   setStyleSheet ("background-color: white;");
}

void my_grpah_view::dragLeaveEvent(QDragLeaveEvent *event)
{
   event->accept ();
   setStyleSheet ("background-color: white;");
}

void my_grpah_view::dragMoveEvent(QDragMoveEvent *event)
{
    event->acceptProposedAction();
}

my_grpah_view::my_grpah_view() {}

my_grpah_view::my_grpah_view(QWidget *parent): QGraphicsView(parent)
{
    setAcceptDrops(true);
    setStyleSheet ("background-color: white;");


    // работа со сценой

    scene.reset(new QGraphicsScene(this));   // Инициализируем графическую сцену
    scene->setItemIndexMethod(QGraphicsScene::NoIndex); // настраиваем индексацию элементов

    this->setScene(scene.get());  // Устанавливаем графическую сцену в graphicsView
    this->setRenderHint(QPainter::Antialiasing);    // Настраиваем рендер
    this->setCacheMode(QGraphicsView::CacheBackground); // Кэш фона
    this->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    scene->setSceneRect(0,0,1000,1000); // Устанавливаем размер сцены0, 0, 1000, 1000); // Устанавливаем размер сцены


}

void my_grpah_view::set_main_controller(Main_Controller *controller)
{
    myController = controller;
}










