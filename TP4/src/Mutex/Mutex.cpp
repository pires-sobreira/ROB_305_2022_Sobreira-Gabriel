#include <iostream>
#include <stdexcept>
#include <string.h>
#include "Mutex.h"
#include "../TimeLib/TimeLib.h"

Mutex::Mutex()
{
	pthread_mutexattr_t mutexAttribute;									
	pthread_mutexattr_init(&mutexAttribute);							
																		
	pthread_mutexattr_settype(&mutexAttribute, PTHREAD_MUTEX_RECURSIVE);

	pthread_mutex_init(&posixId, &mutexAttribute);
	pthread_cond_init(&posixCondId, nullptr);
	pthread_mutexattr_destroy(&mutexAttribute);
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

void Mutex::unlock()
{
	pthread_mutex_unlock(&posixId);

}

bool Mutex::lock(double timeout_ms)
{
	timespec timeout_tspec = timespec_from_ms(timeout_ms)+timespec_now();
	
  	bool ret = pthread_cond_timedwait(&posixCondId, &posixId, &timeout_tspec);

	return ret;
}

bool Mutex::trylock()
{
	bool ret = pthread_mutex_trylock(&posixId);

	return (bool) ret;
}


Mutex::Monitor::Monitor(Mutex& m)
  : m(m)
{}

void Mutex::Monitor::notify()
{
	pthread_cond_signal(&m.posixCondId);								
										
}

void Mutex::Monitor::notifyAll()
{
	pthread_cond_broadcast(&m.posixCondId);	

}

bool Mutex::Monitor::wait(double timeout_ms)
{
	timespec timeout_tspec=(timespec_now())+timespec_from_ms(timeout_ms);
  
	bool ret=pthread_cond_timedwait(&m.posixCondId, &m.posixId, &timeout_tspec);	
																					
	return (bool)ret;																	
}

void Mutex::Monitor::wait()
{
	pthread_cond_wait(&m.posixCondId, &m.posixId);						
																		
}

Mutex::Lock::Lock(Mutex &m): Mutex::Monitor::Monitor(m)
{
	m.lock();

}

Mutex::Lock::~Lock()
{
	m.unlock();

}

Mutex::Lock::Lock(Mutex &m, double timeout_ms) : Mutex::Monitor::Monitor(m)
{
  int ret = m.lock(timeout_ms);

  if (ret != 0) 
  {
    throw Mutex::Monitor::TimeoutException();
  }
}


Mutex::TryLock::TryLock(Mutex& m): Mutex::Monitor::Monitor(m)
{
	int ret = m.trylock();
	if (ret != 0) 
	{
		throw Mutex::Monitor::TimeoutException();
	}
}

Mutex::TryLock::~TryLock(){}