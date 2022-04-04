#include "FifoConsumer.h"

FifoConsumer::FifoConsumer(Fifo<int> *fif) : Thread(), fifo(fif), counter(0)
{}

FifoConsumer::~FifoConsumer()
{}

void FifoConsumer::run()
{
	while(isActive)
    {
        try
        {
            fifo->pop(1000);
            counter++;
        }
        catch(const Fifo<int>::EmptyException& e)
        {
            isActive = false;
        }
    }
}

unsigned FifoConsumer::getCounter()
{
    return counter;
}