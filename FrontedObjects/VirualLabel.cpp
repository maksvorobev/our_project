#include "VirualLabel.h"


int VirualLabel::my_index = 0;
VirualLabel::VirualLabel(QSharedPointer<QMenu> menu): menu(menu){
    ++VirualLabel::my_index;

}


void VirualLabel::paintEvent(QPaintEvent *event){
    QLabel::paintEvent(event);

    // Получаем размеры виджета
    int width = this->width();
    int height = this->height();

    // Рисуем квадратик
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::white);
    // это квдратик с индексом в правом нижнем углу
    QRectF rectangle(width - 15, height - 15, 15, 15);
    painter.drawRect(rectangle);

    QString text = QString::number(curr_index);
    painter.setPen(Qt::black);
    //painter.drawText(rect(), Qt::AlignCenter,  QString::number(VirualLabel::my_index));
    painter.drawText(rectangle,Qt::AlignCenter,  text);
}
