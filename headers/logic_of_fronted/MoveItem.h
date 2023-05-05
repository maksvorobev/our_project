#ifndef MOVEITEM_H
#define MOVEITEM_H

#include "./FrontedObjects/VirualLabel.h"
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include <QLabel>
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include "./FrontedObjects/FrontedOscilloscope.h"
#include <QMenu>
#include <QMouseEvent>
#include <QSharedPointer>

class MoveItem : public QGraphicsProxyWidget
{
    Q_OBJECT
public:
    MoveItem(QGraphicsItem *parent, QSharedPointer<QGraphicsScene> scene, VirualLabel* label);
    ~MoveItem();

signals:

private:
    //void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);


    QPointF cursor_offset; // смещение курсора


    //QLabel* label;
    QSharedPointer<QGraphicsScene> scene;
public slots:
};

#endif // MOVEITEM_H
