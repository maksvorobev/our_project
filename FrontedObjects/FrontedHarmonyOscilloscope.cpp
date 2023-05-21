#include "FrontedHarmonyOscilloscope.h"
#include "./source/block_connector.cpp"

FrontedHarmonyOscilloscope::FrontedHarmonyOscilloscope(std::map<int, Block*>* m) : VirualLabel(nullptr, m)
{
    SetAppearance();
}

void FrontedHarmonyOscilloscope::mousePressEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton)) {
        qDebug() << "mousePressEvent";
        static_cast<Harmony_oscilloscope*> ((*myMap)[curr_index])->graphShow();
        this->setCursor(QCursor(Qt::ClosedHandCursor));
    }
    if (event->button() == Qt::RightButton) {
            qDebug() << "rrrrr";
            QAction *selectedAction = menu->exec(QCursor::pos());
            auto aray_of_actions  = menu->actions();

            if (selectedAction) {
                if (selectedAction->text() == "establish a connection") {
                    qDebug() << "Action 1 selected!";
                    // Создаем диалоговое окно
                    DialogWindow dialog(this);
                    connect(&dialog, &DialogWindow::textEntered, this, [=](QString text) {
                        qDebug() << "Entered text: " << text;
                        (*myMap)[curr_index]->addOutput((*myMap)[text.toInt()]);
                        (*myMap)[text.toInt()]->addInput((*myMap)[curr_index]);
                        qDebug() << "AAAAA" << (*myMap)[curr_index]->getOutput().size();
                        Block_connector* block_connector = new Block_connector();
                        block_connector->connect_blocks((*myMap)[text.toInt()], (*myMap)[curr_index]);
                        block_connector->paintEvent();
                    });

                    // Показываем диалоговое окно
                    dialog.exec();
                    } else {
                        qDebug() << "Диалоговое окно отменено";
                    }

                }
            }

    Q_UNUSED(event);
    return;
}

void FrontedHarmonyOscilloscope::SetAppearance()
{
    curr_index = VirualLabel::my_index;
    menu.reset(new QMenu(this));
    setText(QString("HarmonyOscilloscope") + QString::number(curr_index));

    setAlignment(Qt::AlignCenter);// выравнивание текста по центру
    QFont font;
    font.setPointSize(10);
    setFont(font);
    setStyleSheet("border: 1px solid black"); // устнвка черной границы
    setFixedSize(120, 50);
    adjustSize();

    // создание меню
    //this->menu = new QMenu(this);
    menu->addAction("establish a connection");

    qDebug() << menu->actions()[0]->text();
}

/*
void FrontedOscilloscope::paintEvent(QPaintEvent *event)
{
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
            //painter.drawText(rect(), Qt::AlignCenter,  QString::number(VirtualLabel::my_index));
            painter.drawText(rectangle,Qt::AlignCenter,  text);
}
*/


