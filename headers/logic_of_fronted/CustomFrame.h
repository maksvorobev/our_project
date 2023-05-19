#ifndef CUSTOMFRAME_H
#define CUSTOMFRAME_H


#include <QFrame>
#include <QGraphicsItem>
#include "MoveItem.h"

class QDropEvent; //?????
class QDragEnterEvent; //?????
class QDragLeaveEvent; //????

class CustomFrame : public QFrame
{
   public:
      explicit CustomFrame(QWidget *parent = nullptr);

   protected:
      void dropEvent(QDropEvent *event) override;
      void dragEnterEvent(QDragEnterEvent *event) override;
      void dragLeaveEvent (QDragLeaveEvent *event) override;
};



#endif // CUSTOMFRAME_H
