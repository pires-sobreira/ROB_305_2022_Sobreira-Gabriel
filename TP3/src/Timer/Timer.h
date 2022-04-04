#ifndef Timer_Timer_h_INCLUDED
#define Timer_Timer_h_INCLUDED

//#include "../Chrono/Chrono.h"
#include "../TimeLib/TimeLib.h"
#include <time.h>
#include <signal.h>

class Timer
{
private:
    static void call_callback(int, siginfo_t* si, void*);

protected:
    virtual void callback() = 0;
    timer_t tid;

public:
    Timer();
    virtual ~Timer();
    void start(double duration_ms);
    void stop();
};


#endif