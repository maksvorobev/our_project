#pragma ones
#include "./block.h"
#include "Low_pass_filter.h"
#include <QSharedPointer>



class block_low_pass_filter: public Block{
private:
    double cutoff_frequency;    
public:
    block_low_pass_filter(double cutoff_frequency);
    void set_in_input_Signal(Signal* signal) override ;
    Signal* getSignal() override;
    void work() override;
    bool ready();


};


