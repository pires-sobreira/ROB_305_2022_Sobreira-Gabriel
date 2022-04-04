#ifndef Producer_h_INCLUDED
#define Producer_h_INCLUDED

#include "../Thread/Thread.h"
#include "../Semaphore/Semaphore.h"

class SemaProducer : public Thread
{
public:
    SemaProducer(Semaphore *semaphore, unsigned int toGive);
    ~SemaProducer();
    void run();
    unsigned int getCounter();

private:
    Semaphore *semaphore;
    unsigned int counter, toGive;
};

#endif