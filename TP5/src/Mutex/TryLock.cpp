
#include "TryLock.h"

Mutex::TryLock::TryLock(Mutex &m) : Monitor(m)
{
    if(mutex.trylock() == false)
    {
        throw TimeoutException();   
    }
}

Mutex::TryLock::~TryLock()
{
    mutex.unlock();
}
