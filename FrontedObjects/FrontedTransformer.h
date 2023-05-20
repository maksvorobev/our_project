#pragma once
#include "VirualLabel.h"
#include <QLabel>
#include <QMenu>
#include <QMouseEvent>
#include <QDebug>
#include <QInputDialog>
#include <QMouseEvent>
#include <QPushButton>
#include <QString>
#include <QPainter>
#include "DialogWindow.h"
#include "./headers/transformer.h"


class FrontedTransformer : public VirualLabel{
    Q_OBJECT
public:
    explicit FrontedTransformer(std::map<int, Block*>* m);

    void mousePressEvent(QMouseEvent *event) override;

protected:
    void SetAppearance() override;
    //int curr_index = 0;
    //void paintEvent(QPaintEvent *event) override;
};
