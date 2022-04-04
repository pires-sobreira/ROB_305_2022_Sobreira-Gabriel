#ifndef Consumer_h_INCLUDED
#define Consumer_h_INCLUDED

#include "../Thread/Thread.h"
#include "../Semaphore/Semaphore.h"

class SemaConsumer : public Thread
{
public:
    SemaConsumer(Semaphore *semaphore);
    ~SemaConsumer();
    void run();
    unsigned int getCounter();

private:
    Semaphore *semaphore;
    unsigned int counter;
};

#endif