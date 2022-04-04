#include "IncrementerMutex.h"

IncrementerMutex::IncrementerMutex(unsigned int nLoops, volatile double *pCounter, Mutex &mutex)
  : Thread(),
   m_nLoops(nLoops),
   m_pCounter(pCounter),
   mutex(mutex)
{}

IncrementerMutex::~IncrementerMutex(){}

void IncrementerMutex::run()
{
  for (unsigned int i = 0; i < m_nLoops; i++)
  {
    Mutex::Lock lock(mutex);
    *m_pCounter += 1;
    lock.~Lock();
  }
}