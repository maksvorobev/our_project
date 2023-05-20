#include "../headers/main_controller.h"
#include<QQueue>


Main_Controller::Main_Controller()
{

}


void Main_Controller::startCircuit()
{
    QQueue<Block*> queue;
    for (int i = 0; i < Generators.size(); i++)
    {
        queue.enqueue(Generators[i]);
    }

    while (!queue.isEmpty())
    {
        Block* temp_block = queue.dequeue();
        temp_block->work();
        Signal* outSignal = temp_block->getSignal();
        vector <Block*> out = temp_block->getOutput();
        if (!out.empty())
        {
            for (Block* block : out)
            {
                block->set_in_input_Signal(outSignal);
                if (block->ready())
                {
                    queue.enqueue(block);
                }
            }
        }
    }

}
void Main_Controller::addGenerator(Generator* generator)
{
    Generators.push_back(generator);
}
