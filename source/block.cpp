#include "./headers/block.h"

Block::Block(QWidget *parent): QWidget(parent)
{

}

const std::vector<Block*>& Block::getOutput() {return output;}

const std::vector<Block*>& Block::getInput() {return input;}

bool Block::ready() {return true;}

bool Block::addOutput(Block* block)
{
    output.push_back(block);
    return true;
}

bool Block::addInput(Block* block)
{
    bool flag = input.size() < max_input;
    if (flag)
        input.push_back(block);
    return flag;
}

void Block::set_in_input_Signal(Signal* signal) {}

Signal* Block::getSignal()
{

}




void  Block::work() {}

Block::~Block()
{

}
