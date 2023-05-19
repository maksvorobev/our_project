#include "FrontedHighPassFilter.h"


FrontedHighPassFilter::FrontedHighPassFilter(std::map<int, Block*>* m) : VirualLabel(nullptr, m)
{
    SetAppearance();
}

/*
void FrontedOscilloscope::mousePressEvent(QMouseEvent *event)
{

    qDebug() << "mousePressEventlabel";
    if (event->button() == Qt::RightButton) {
            QMenu menu(this);
            QAction *action1 = menu.addAction("Action 1");
            QAction *action2 = menu.addAction("Action 2");
            QAction *selectedAction = menu.exec(event->globalPos());
            if (selectedAction == action1) {
                // выполнение действия 1
            } else if (selectedAction == action2) {
                // выполнение действия 2
            }
        }

}
*/

void FrontedHighPassFilter::mousePressEvent(QMouseEvent *event)
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
                        qDebug() << "AAAAA" << (*myMap)[curr_index]->getOutput().size();

                       // ownBlock->addOutput(mp[int(text)])
                    });

                    // Показываем диалоговое окно
                    dialog.exec();
                    } else {
                        qDebug() << "Диалоговое окно отменено";
                    }

                }
            if (selectedAction) {
                if (selectedAction->text() == "set cutoff frequency") {
                    qDebug() << "set cutoff frequency!";
                    // Создаем диалоговое окно
                    DialogWindow dialog(this);
                    connect(&dialog, &DialogWindow::textEntered, this, [=](QString text) {
                        qDebug() << "Entered text: " << text;
                        PrintFrequencyInQLabel(text.toDouble());
                        // TODO

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

void FrontedHighPassFilter::SetAppearance()
{
    curr_index = VirualLabel::my_index;
    menu.reset(new QMenu(this));
    setText(QString("HighPassFilter") + QString::number(curr_index) + QString("\n")
            + QString("frequency = ") + QString("by-default"));
    //setText(QString("frequency = "));
    setAlignment(Qt::AlignCenter);// выравнивание текста по центру


    QFont font;
    font.setPointSize(10);
    setFont(font);
    setStyleSheet("border: 1px solid black"); // устнвка черной границы
    setFixedSize(160, 60);
    adjustSize();

    // создание меню
    //this->menu = new QMenu(this);
    menu->addAction("establish a connection");
    menu->addAction("set cutoff frequency");

    qDebug() << menu->actions()[0]->text();
}

void FrontedHighPassFilter::PrintFrequencyInQLabel(double frequency)
{
    setText(QString("HighPassFilter") + QString::number(curr_index) + QString("\n")
            + QString("frequency = ") + QString::number(frequency));
    //setText(QString("frequency = "));
    setAlignment(Qt::AlignCenter);// выравнивание текста по центру
    static_cast<block_low_pass_filter*>((*myMap)[curr_index])->set_cutoff_frequency(frequency);
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


