#include "Semaphore.h"

Semaphore::Semaphore(unsigned int initCount, unsigned int maxCount): counter(initCount), maxCount(maxCount) {}

Semaphore::~Semaphore(){}

void Semaphore::give()
{
    Mutex::Lock Lock(mutex);
    if (counter < maxCount)
        ++counter;
}

void Semaphore::take()
{
    Mutex::Lock Lock(mutex);
    while (counter == 0)
    {
        Lock.wait();
    }
    --counter;
}

bool Semaphore::take(double timeout_ms)
{
    Mutex::Lock Lock(mutex);
	
	if (counter == 0) { Lock.wait(timeout_ms); }
		if (counter == 0) { return false; }

	--counter;

	return true;
}