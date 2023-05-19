#ifndef MY_GRPAH_VIEW_H
#define MY_GRPAH_VIEW_H
#include <QGraphicsView>
#include "MoveItem.h"
#include <QGraphicsProxyWidget>
#include <QSharedPointer>
#include "../../FrontedObjects/FrontedGenerator.h"
#include "../../FrontedObjects/FrontedOscilloscope.h"
#include "./headers/generator.h"
#include "./headers/oscilloscope.h"
#include <map>
#include "./headers/main_controller.h"


class QDropEvent;
class QDragEnterEvent;
class QDragLeaveEvent;


class my_grpah_view: public QGraphicsView{
    Q_OBJECT
public:
    my_grpah_view();
    explicit my_grpah_view(QWidget *parent = nullptr);
    void set_main_controller(Main_Controller* controller);


protected:
   // drag&drop
   void dropEvent(QDropEvent *event) override;
   void dragEnterEvent(QDragEnterEvent *event) override;
   void dragLeaveEvent (QDragLeaveEvent *event) override;
   void dragMoveEvent(QDragMoveEvent *event) override;
   std::map<int, Block*> myMap;
   Main_Controller* myController;



private:
   QSharedPointer<QGraphicsScene> scene;
};

#endif // MY_GRPAH_VIEW_H
