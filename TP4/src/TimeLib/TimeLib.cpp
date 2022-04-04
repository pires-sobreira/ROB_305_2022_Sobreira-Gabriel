#include "TimeLib.h"

double timespec_to_ms(const timespec& time_ts)
{
    return 1000. * (time_ts.tv_sec) + (time_ts.tv_nsec) / 1000000.;
}

timespec timespec_from_ms(double time_ms)
{
    timespec t;
    t.tv_sec = (int) time_ms/1000.0;
    t.tv_nsec = time_ms * 1000000. - t.tv_sec * 1000000000.;
    return t;
}

timespec timespec_now()
{
    timespec t;
    clock_gettime(CLOCK_REALTIME, &t);
    return t;
}

timespec timespec_negate(const timespec& time_ts)
{
    timespec tNegate = (time_ts);
    if ((time_ts.tv_nsec < 0) && time_ts.tv_sec)
    {
        tNegate.tv_sec -= 1;
        tNegate.tv_nsec += 1000000000.;
    }

    return tNegate;
}

timespec timespec_add(const timespec& time1_ts, const timespec& time2_ts)
{
    timespec tAdd;

    tAdd.tv_nsec = (time1_ts.tv_nsec) + (time2_ts.tv_nsec);

    if (tAdd.tv_nsec >= 1000000000.)
    {
        tAdd.tv_sec = (int) tAdd.tv_nsec / 1000000000.;
        tAdd.tv_nsec = tAdd.tv_nsec - (tAdd.tv_sec * 1000000000.);
        tAdd.tv_sec += (time1_ts.tv_sec) + (time2_ts.tv_sec);
        return tAdd;
    }

    tAdd.tv_sec = (time1_ts.tv_sec) + (time2_ts.tv_sec);

    return tAdd;
}

timespec timespec_subtract(const timespec& time1_ts, const timespec& time2_ts)
{
    timespec tSub;

    if (((time1_ts.tv_sec) > (time2_ts.tv_sec)) || (((time1_ts.tv_sec) == (time2_ts.tv_sec)) && (time1_ts.tv_nsec) > (time2_ts.tv_nsec)))
    {
        tSub.tv_nsec = (time1_ts.tv_nsec) - (time2_ts.tv_nsec);
        tSub.tv_sec = (time1_ts.tv_sec) - (time2_ts.tv_sec);
        return timespec_negate(tSub);
    }

    else
    {
        tSub.tv_nsec = (time2_ts.tv_nsec) - (time1_ts.tv_nsec);
        tSub.tv_sec = (time2_ts.tv_sec) - (time1_ts.tv_sec);
        tSub = timespec_negate(tSub);

        tSub.tv_sec = -tSub.tv_sec;
        tSub.tv_nsec = -tSub.tv_nsec;

        return tSub;
    }
    
}

timespec timespec_wait(const timespec& delay_ts)
{
    timespec tInit, tFinal, tDuration, tDelay;

    tDelay = timespec_negate(delay_ts);

    clock_gettime(CLOCK_REALTIME, &tInit);
    nanosleep(&tDelay, NULL);
    clock_gettime(CLOCK_REALTIME, &tFinal);

    tDuration.tv_sec = tFinal.tv_sec - tInit.tv_sec;
    tDuration.tv_nsec = tFinal.tv_nsec - tInit.tv_nsec;

    return timespec_negate(tDuration);;

}

// Operators

timespec  operator- (const timespec& time_ts)
{
    timespec tMinus = time_ts;
    tMinus.tv_nsec = -tMinus.tv_nsec;
    tMinus.tv_sec = -tMinus.tv_sec;
    return tMinus;
}

timespec  operator+ (const timespec& time1_ts, const timespec& time2_ts)
{
    return timespec_add(time1_ts, time2_ts);
}

timespec  operator- (const timespec& time1_ts, const timespec& time2_ts)
{
    return timespec_subtract(time1_ts, time2_ts);
}

timespec& operator+= (timespec& time_ts, const timespec& delay_ts)
{
    time_ts = time_ts + delay_ts;
    return time_ts;
}

timespec& operator-= (timespec& time_ts, const timespec& delay_ts)
{
    time_ts = time_ts - delay_ts;
    return time_ts;
}

bool operator== (const timespec& time1_ts, const timespec& time2_ts)
{
    if ((time1_ts.tv_sec == time2_ts.tv_sec) && (time1_ts.tv_nsec == time2_ts.tv_nsec)) return true;
    else return false;
}

bool operator!= (const timespec& time1_ts, const timespec& time2_ts)
{
    return !(time1_ts == time2_ts);
}

bool operator< (const timespec& time1_ts, const timespec& time2_ts)
{
    timespec t = time1_ts - time2_ts;
    if((t.tv_sec < 0) || (t.tv_nsec < 0)) return true;
    return false;
}
bool operator> (const timespec& time1_ts, const timespec& time2_ts)
{
    timespec t = time2_ts - time1_ts;
    if((t.tv_sec < 0) || (t.tv_nsec < 0)) return true;
    return false;
}