#ifndef CountDown_CountDown_h_INCLUDED
#define CountDown_CountDown_h_INCLUDED

#include "../PeriodicTimer/PeriodicTimer.h"
#include "../TimeLib/TimeLib.h"
#include <iostream>

class CountDown: public PeriodicTimer
{
private:
    int loops;
protected:
    void callback();

public:
    int GetLoops();
    CountDown(int nLoops);
};


#endif