#include <QtWidgets>
#include <vector>
#include <QPointer>
#include <QPainter>
#include <./headers/block.h>

struct Line {
    QPoint start, end;
};

// Класс Block_connector
class Block_connector : public QWidget {
public:
    Block_connector(QWidget *parent = nullptr) : QWidget(parent) {}
    // Метод соединения блоков
    void connect_blocks(Block * block1, Block * block2) {
        // Создаем новую линию
        Line line;
        line.start = block1->mapToGlobal(block1->rect().center());
        line.end = block2->mapToGlobal(block2->rect().center());
        // Добавляем линию в вектор
        lines.push_back(line);
        qDebug() << "Coedenilis'";
    }
    // Метод переподключения блоков
    void reconnector(Block *block) {
        // Удаляем все линии, связанные с блоком

            // Получаем вектор всех блоков, на которые ссылается выход текущего блока
            std::vector<Block*> output_blocks = block->getOutput();
            // Проходим по всем линиям
            for (auto it = lines.begin(); it != lines.end();) {
                // Проверяем, есть ли в выходных блоках блок, центр которого совпадает с line.end
                bool found = false;
                for (Block * output_block : output_blocks) {
                    if (it->end == output_block->mapToGlobal(output_block->rect().center())) {
                        found = true;
                        break;
                    }
                }
                // Если нашли, удаляем линию
                if (found) {
                    it = lines.erase(it);
                } else {
                    ++it;
                }
            }
            // Получаем вектор всех блоков, на которые ссылается выход текущего блока
            std::vector<Block*> input_blocks = block->getInput();
            // Проходим по всем линиям
            for (auto it = lines.begin(); it != lines.end();) {
                // Проверяем, есть ли в выходных блоках блок, центр которого совпадает с line.start
                bool found = false;
                for (Block * input_block : input_blocks) {
                    if (it->start == input_block->mapToGlobal(input_block->rect().center())) {
                        found = true;
                        break;
                    }
                }
                // Если нашли, удаляем линию
                if (found) {
                    it = lines.erase(it);
                } else {
                    ++it;
                }
            }


        // Обновляем векторы input и output для всех блоков, связанных с этим блоком
        for (Block * input_block : block->getInput()) {
            for (Block * output_block : block->getOutput()) {
                connect_blocks(input_block, output_block);
            }
        }
    }

    void paintEvent() {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setPen(QPen(Qt::black, 2));
        // Рисуем все линии из вектора lines
        for (const auto &line : lines) {
            painter.drawLine(mapFromGlobal(line.start), mapFromGlobal(line.end));
        }


}
private:
    std::vector<Line> lines;
};
