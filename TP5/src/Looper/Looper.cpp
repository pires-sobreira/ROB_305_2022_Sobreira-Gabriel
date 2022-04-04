#include <iostream>

#include "./Looper.h"

double Looper::runLoop(double nLoops)
{
  doStop = false;
  iLoop  = 0;
  
  while (iLoop < nLoops && not doStop)
  {
    iLoop ++;
  }

  return iLoop;
}

double Looper::getSample()
{
  return iLoop;
}

double Looper::stopLoop()
{
  doStop = true;

  return iLoop;
}