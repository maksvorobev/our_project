#include "FrontedGenerator.h"
#include "./source/block_connector.cpp"

FrontedGenerator::FrontedGenerator(std::map<int, Block*>* m) : VirualLabel(nullptr, m)
{
    SetAppearance();
}

void FrontedGenerator::mousePressEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton)) {
        qDebug() << "mousePressEvent";
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
                        Block_connector* block_connector = new Block_connector();
                        block_connector->connect_blocks((*myMap)[text.toInt()], (*myMap)[curr_index]);
                        block_connector->paintEvent();
                       // ownBlock->addOutput(mp[int(text)])
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

void FrontedGenerator::SetAppearance()
{
    curr_index = VirualLabel::my_index;
    menu.reset(new QMenu(this));
    setText(QString("Generator") + QString::number(curr_index));

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
            //painter.drawText(rect(), Qt::AlignCenter,  QString::number(VirualLabel::my_index));
            painter.drawText(rectangle,Qt::AlignCenter,  text);
}
*/


