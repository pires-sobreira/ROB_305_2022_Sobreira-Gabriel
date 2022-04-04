#ifndef Semaphore_Semaphore_h_INCLUDED
#define Semaphore_Semaphore_h_INCLUDED

#include "../Mutex/Mutex.h"
#include <limits.h>
#include <pthread.h>
#include <iostream>

class Semaphore
{
public:
    Semaphore(unsigned int initCount = 0, unsigned int maxCount = UINT_MAX);
    ~Semaphore();
    void give();
    void take();
    bool take(double timeout_ms);
    
private: //vermelho
    Mutex mutex;
    volatile unsigned int counter;
    unsigned int maxCount;

protected:
};

#endif