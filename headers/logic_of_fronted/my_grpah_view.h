#ifndef MY_GRPAH_VIEW_H
#define MY_GRPAH_VIEW_H
#include <QGraphicsView>
#include "MoveItem.h"
#include <QGraphicsProxyWidget>
#include <QSharedPointer>
#include "../../FrontedObjects/FrontedGenerator.h"


class QDropEvent;
class QDragEnterEvent;
class QDragLeaveEvent;


class my_grpah_view: public QGraphicsView{
    Q_OBJECT
public:
    my_grpah_view();
    explicit my_grpah_view(QWidget *parent = nullptr);


protected:
   // drag&drop
   void dropEvent(QDropEvent *event) override;
   void dragEnterEvent(QDragEnterEvent *event) override;
   void dragLeaveEvent (QDragLeaveEvent *event) override;
   void dragMoveEvent(QDragMoveEvent *event) override;



private:
   QSharedPointer<QGraphicsScene> scene;
};

#endif // MY_GRPAH_VIEW_H
