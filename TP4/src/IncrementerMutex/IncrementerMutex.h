#ifndef IncrThreadMutex_h_INCLUDED 
#define IncrThreadMutex_h_INCLUDED
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "../Thread/Thread.h"
#include "../Mutex/Mutex.h"

class IncrementerMutex : public Thread
{
public:
  IncrementerMutex(unsigned int nLoops, volatile double *pCounter, Mutex &mutex);
  ~IncrementerMutex();
  void run() override;


private:
  unsigned int m_nLoops;      
  volatile double *m_pCounter;
  Mutex &mutex;    

};

#endif