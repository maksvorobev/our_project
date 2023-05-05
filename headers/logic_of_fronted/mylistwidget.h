#ifndef MYLISTWIDGET_H
#define MYLISTWIDGET_H
#include <QListWidget>
#include <QMouseEvent>
#include <QDrag>
#include <QMimeData>
#include <QApplication>
#include <QDebug>
#include <iostream>
#include <string>

class MyListWidget : public QListWidget{
    Q_OBJECT

public:
   explicit MyListWidget (QWidget *parent = nullptr);

protected:
   void startDrag(Qt::DropActions supportedActions) override;
};

#endif // MYLISTWIDGET_H
