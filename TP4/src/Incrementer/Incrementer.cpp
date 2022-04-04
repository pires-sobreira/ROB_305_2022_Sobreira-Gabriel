#include "Incrementer.h"

Incrementer::Incrementer(unsigned int nLoops, volatile double *pCounter): Thread(), nLoops(nLoops), pCounter(pCounter){}

Incrementer::~Incrementer(){}

void Incrementer::run()
{
    for (unsigned int i = 0; i < nLoops; i++)
    {
        *pCounter = *pCounter + 1;
    }
}