#ifndef VIRUALLABEL_H
#define VIRUALLABEL_H
#include <QLabel>
#include <QMenu>
#include <QMouseEvent>
#include <QDebug>
#include <QSharedPointer>
#include <QPainter>

class VirualLabel: public QLabel
{
public:
    static int my_index;
    VirualLabel(QSharedPointer<QMenu> menu = nullptr);

    QSharedPointer<QMenu> menu;
protected:
    int curr_index = 0;
    // эта функция общая для все label и она отрисовывает в правом нижне углу число
    void paintEvent(QPaintEvent *event) override;
    virtual void SetAppearance() = 0; // отвечает за внешний вид Label

};

#endif // VIRUALLABEL_H
