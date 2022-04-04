#include "SemaProducer.h"

SemaProducer::SemaProducer(Semaphore *semaphore, unsigned int toGive) : Thread(), semaphore(semaphore), toGive(toGive), counter(0){}

SemaProducer::~SemaProducer(){}

void SemaProducer::run()
{
    for (unsigned int i = 0; i < toGive; i++)
    {
        semaphore->give();
        ++counter;
    }
}

unsigned int SemaProducer::getCounter()
{
    return counter;
}