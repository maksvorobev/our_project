#ifndef BLOCK_H
#define BLOCK_H

#include <QWidget>
#include <vector>
#include "Signal.h"
class Block: public QWidget
{
    Q_OBJECT
public:
    Block(QWidget *parent = nullptr);

    const std::vector<Block*>&  getOutput();   //?
    const std::vector<Block*>& getInput();     //?

    bool addOutput(Block* block);
    bool addInput(Block* block);

    virtual void setSignal(Signal* signal);

    virtual Signal* getSignal();

    bool ready();

    virtual Signal* work();




    virtual ~Block();

protected:
    std::vector<Signal*> all_signals;
    std::vector<Block*> input;
    std::vector<Block*> output;
    int max_input {1};


signals:

};

#endif // BLOCK_H
