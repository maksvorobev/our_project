#ifndef MAIN_CONTROLLER_H
#define MAIN_CONTROLLER_H
#include<QQueue>
#include"generator.h"
//#include"Low_pass_filter.h"

class Main_Controller
{
public:
    Main_Controller();
    void startCircuit();
    void addGenerator(Generator* generator);

private:
    vector<Generator *> Generators;
    //vector<Block *> Blocks;
};

#endif // MAIN_CONTROLLER_H
