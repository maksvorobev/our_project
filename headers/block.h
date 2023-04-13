#ifndef BLOCK_H
#define BLOCK_H

#include <QWidget>
#include <vector>
class Block : public QWidget
{
    Q_OBJECT
public:
    explicit Block(QWidget *parent = nullptr);

    const std::vector<Block*>&  getOutput();
    const std::vector<Block*>& getInput();

    bool addOutput(Block* block);
    bool addInput(Block* block);

    virtual bool ready();

    virtual ~Block();
private:
    std::vector<Block*> input;
    std::vector<Block*> output;
    int max_input {1};


signals:

};

#endif // BLOCK_H
