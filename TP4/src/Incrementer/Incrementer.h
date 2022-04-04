#ifndef Incrementer_Incrementer_h_INCLUDED
#define Incrementer_Incrementer_h_INCLUDED

#include "../Thread/Thread.h"

class Incrementer: public Thread
{
public:
    Incrementer(unsigned int nLoops, volatile double *pCounter);
    ~Incrementer();

    void run() override;

private:
    unsigned int nLoops;    
    volatile double *pCounter;
};

#endif