#ifndef PeriodicTimer_PeriodicTimer_h_INCLUDED
#define PeriodicTimer_PeriodicTimer_h_INCLUDED

#include "../TimeLib/TimeLib.h"
#include "../Timer/Timer.h"

class PeriodicTimer: public Timer
{
public:
    //PeriodicTimer();
    void start(double duration_ms);
};

#endif