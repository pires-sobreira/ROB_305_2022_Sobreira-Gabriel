#include "Chrono.h"

//Constructor
Chrono::Chrono()
{
    startTime_ = timespec_now();
    stopTime_ = startTime_;
}

//Functions
void Chrono::stop()
{
    stopTime_ = timespec_now();
}
void Chrono::restart()
{
    startTime_ = timespec_now();
    stopTime_ = startTime_;
}
bool Chrono::isActive()
{
    return (stopTime_ == startTime_);
}	
double Chrono::startTime()
{
    return timespec_to_ms(startTime_);
}
double Chrono::stopTime()
{
    return timespec_to_ms(stopTime_);
}
double Chrono::lap()
{
    if (isActive())
    {
        return timespec_to_ms((timespec_now()-startTime_));
    }    
    return timespec_to_ms((stopTime_-startTime_));
}