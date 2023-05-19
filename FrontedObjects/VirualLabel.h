#ifndef VIRUALLABEL_H
#define VIRUALLABEL_H
#include <QLabel>
#include <QMenu>
#include <QMouseEvent>
#include <QDebug>
#include <QSharedPointer>
#include <QPainter>
#include "./headers/block.h"
//#include "./headers/block_low_pass_filter.h"

class VirualLabel: public QLabel
{
public:
    static int my_index;
    VirualLabel(QSharedPointer<QMenu> menu = nullptr, std::map<int, Block*>* m = nullptr);
    int getIndex();

    QSharedPointer<QMenu> menu;
protected:
    int curr_index = 0;
    // эта функция общая для все label и она отрисовывает в правом нижне углу число
    void paintEvent(QPaintEvent *event) override;
    virtual void SetAppearance() = 0; // отвечает за внешний вид Label
    std::map<int, Block*>* myMap;

};

#endif // VIRUALLABEL_H
