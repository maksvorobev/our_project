#include "./headers/logic_of_fronted/MoveItem.h"

MoveItem::MoveItem(QGraphicsItem *parent, QSharedPointer<QGraphicsScene> scene, VirualLabel* label) :
    QGraphicsProxyWidget(parent), scene(scene)
{
    //prepareGeometryChange();

    //label = new FrontedOscilloscope;
    /*
    label.setText(text);
    label.setStyleSheet("border: 1px solid black"); // устнвка черной границы
    label.setFixedSize(50, 50);
    label.adjustSize();
    */

    // ???
    // установили label в QGraphicsProxyWidget
    setWidget(label);
    //setGeometry(label->geometry());
    myLabel = label;

}

VirualLabel* MoveItem::getLabel()
{
    return myLabel;
}

MoveItem::~MoveItem()
{

}

/*
void MoveItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setPen(Qt::black);
    //painter->setBrush(Qt::green);
    //painter->drawRect(-30,-30,60,60);
    //painter->drawText(boundingRect().center(), "ojiojojo");

    //this->widget()->render(painter, QPoint(), QRegion(), QWidget::DrawChildren);
    //Q_UNUSED(option);
    //Q_UNUSED(widget);
    //label.render(painter, QPoint(), QRegion(), QWidget::DrawChildren);
}
*/


void MoveItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    /* Устанавливаем позицию графического элемента
     * в графической сцене, транслировав координаты
     * курсора внутри графического элемента
     * в координатную систему графической сцены
     * */
    /*
    if (event->buttons() & Qt::LeftButton) {
        this->setPos(mapToScene(event->pos()));
    }
    */

        if (event->buttons() & Qt::LeftButton) {
            this->setPos(mapToParent(event->pos() - cursor_offset));
        }




}


void MoveItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
            //qDebug() << "event->pos() = " << event->pos() << "pos() = " << pos();
            cursor_offset = event->pos();
        }
    // вызываем базовую реализацию (для VirtualLabel)
    QGraphicsProxyWidget::mousePressEvent(event);
    //Q_UNUSED(event);
    //return;
}

void MoveItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    /* При отпускании мышью элемента
     * заменяем на обычный курсор стрелку
     * */
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}

/*
QVariant MoveItem::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (change == QGraphicsItem::ItemSelectedChange && scene) {
            if (value.toBool()) {
                // Включение обработки нажатия на любую область внутри прокси-виджета.
                setAcceptedMouseButtons(Qt::LeftButton);
            } else {
                // Отключение обработки нажатия на прокси-виджете, когда он не выделен.
                setAcceptedMouseButtons(0);
            }
        }

        return QGraphicsProxyWidget::itemChange(change, value);
}
*/






