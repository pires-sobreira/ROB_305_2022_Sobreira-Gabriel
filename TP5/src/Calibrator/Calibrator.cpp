#include <vector>
#include <iostream>
#include "./Calibrator.h"

Calibrator::Calibrator(double samplingPeriod_ms, unsigned int nSamples) : pCounter(nSamples)
{
	std::cout << "Beginning of Calibrator"  << std::endl; 
	PeriodicTimer::start(samplingPeriod_ms);
  looper->runLoop();
  
  std::vector<double> times;
  for (unsigned int i = 1; i<=nSamples; i++)
  {
    times.push_back(samplingPeriod_ms*i);
  }

  double ySum = 0;
  double x2Sum = 0;
  double xSum = 0;
  double xySum = 0;
  
  for (unsigned int i = 0; i<nSamples; i++)
  {
    ySum += samples[i]; 
    xSum += times[i]; 
    x2Sum += times[i]*times[i];
    xySum += times[i]*samples[i];
  }
  a = (nSamples*xySum - xSum*ySum)/(nSamples*x2Sum - xSum*xSum);
  b = (x2Sum*ySum - xSum*xySum)/(nSamples*x2Sum - xSum*xSum);

}

void Calibrator::callback()
{
	--pCounter;

  if (pCounter == 0)
  {
    samples.push_back(looper->stopLoop());
    stop();
  }
  else
  {
    samples.push_back(looper->getSample());
  }
}

double Calibrator::nLoops(double duration_ms)
{
	return (a*duration_ms + b);
}