
#include "../TimeLib/TimeLib.h"
#include "Mutex.h"

#include <pthread.h>
#include <exception>

Mutex::Mutex(bool isInversionSafe)
{
    pthread_mutexattr_t mutexAttr;
    pthread_mutexattr_init(&mutexAttr);
    pthread_mutexattr_settype(&mutexAttr, PTHREAD_MUTEX_RECURSIVE);
    if(isInversionSafe)
    {
        pthread_mutexattr_setprotocol(&mutexAttr, PTHREAD_PRIO_INHERIT); //adding the possibility to invert the priority
    }
    pthread_mutex_init(&posixId, &mutexAttr);
    pthread_cond_init(&posixCondId, nullptr);
    pthread_mutexattr_destroy(&mutexAttr);
}

Mutex::~Mutex()
{
    pthread_mutex_destroy(&posixId);
    pthread_cond_destroy(&posixCondId);
}

void Mutex::lock()
{
    pthread_mutex_lock(&posixId);
}

bool Mutex::lock(double timeout_ms)
{
	timespec timeout(timespec_now() + timespec_from_ms(timeout_ms));
	return ! (bool) pthread_mutex_timedlock(&posixId, &timeout);
}

bool Mutex::trylock()
{
    return ! (bool) pthread_mutex_trylock(&posixId);
}

void Mutex::unlock()
{
    pthread_mutex_unlock(&posixId);
}