#include <QtWidgets>
#include <vector>
#include <./headers/block.h>
#include <QPainter>

struct Line {
    QPoint start, end;
};

class Block_connector : public QWidget {
public:
    Block_connector(QWidget *parent = nullptr) : QWidget(parent) {}
    // Метод соединения блоков
    void connect_blocks(Block &block1, Block &block2) {
        // Создаем новую линию
        struct Line line;
        line.start = block1.mapToGlobal(block1.rect().center());
        line.end = block2.mapToGlobal(block2.rect().center());
        // Добавляем линию в вектор
        lines.push_back(line);
        // Обновляем векторы input и output
        block1.getOutput().push_back(&block2);
        block2.getInput().push_back(&block1);
    }
    // Метод переподключения блоков
    void reconnector(Block &block) {
        // Удаляем все линии, связанные с блоком
        for (auto it = lines.begin(); it != lines.end();) {
            if (it->start == block.mapToGlobal(block.rect().center()) || it->end == block.mapToGlobal(block.rect().center())) {
                it = lines.erase(it);
            } else {
                ++it;
            }
        }
        // Обновляем векторы input и output для всех блоков, связанных с этим блоком
        for (auto &input_block : block.getInput()) {
            for (auto &output_block : block.getOutput()) {
                connect_blocks(*input_block, *output_block);
            }
        }
    }
protected:
    void paintEvent(QPaintEvent *event) override {
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
