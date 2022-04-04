#include "FifoProducer.h"

FifoProducer::FifoProducer(Fifo<int> *fif, unsigned maxNum) : Thread(), fifo(fif), counter(0), maxCount(maxNum)
{}

FifoProducer::~FifoProducer()
{}

void FifoProducer::run()
{
    for(unsigned i = 0; i < maxCount; i++)
    {
    	fifo -> push(i);
    	counter++;
    }
}

unsigned FifoProducer::getCounter()
{
    return counter;
}