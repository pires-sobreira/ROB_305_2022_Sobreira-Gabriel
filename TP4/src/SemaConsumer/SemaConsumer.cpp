#include "SemaConsumer.h"

SemaConsumer::SemaConsumer(Semaphore *semaphore) : Thread(), semaphore(semaphore), counter(0){}

SemaConsumer::~SemaConsumer(){}

void SemaConsumer::run()
{
    while(semaphore->take(150))
    {
        ++counter;
    }
   
}

unsigned int SemaConsumer::getCounter()
{
    return counter;
}