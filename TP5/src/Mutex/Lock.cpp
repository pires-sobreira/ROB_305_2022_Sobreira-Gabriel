
#include "Lock.h"

Mutex::Lock::Lock(Mutex &m) : Monitor(m)
{
    mutex.lock();
}

Mutex::Lock::Lock(Mutex &m, double timeout_ms) : Mutex::Monitor::Monitor(m) 
{
    if(mutex.lock(timeout_ms) == false)
    {
        throw TimeoutException();
    }
}

Mutex::Lock::~Lock()
{
    mutex.unlock();
}