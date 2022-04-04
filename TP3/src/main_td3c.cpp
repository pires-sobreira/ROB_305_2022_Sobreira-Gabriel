#include <iostream>
#include "./Calibrator/Calibrator.h"
#include "./CpuLoop/CpuLoop.h"
#include "./Chrono/Chrono.h"

int main()
{
  double samplingPeriod_ms = 1000;
  unsigned int nSamples = 10;
  double duration_ms = 10000;
  
  Calibrator callibrator(samplingPeriod_ms, nSamples);
  CpuLoop	loop(callibrator);
  
  std::cout << "Running estimation for 10 seconds " << std::endl;
  Chrono chrono;
  loop.runTime(duration_ms);
  chrono.stop();
  
  std::cout << "Result in seconds: " << chrono.lap()/1000 << std::endl;

  return 0;
}