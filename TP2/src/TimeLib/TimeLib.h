#ifndef TimeLib_h_INCLUDED
#define TimeLib_h_INCLUDED

#include <time.h>
#include <unistd.h>

//timespec to miliseconds
double timespec_to_ms(const timespec& time_ts);

// miliseconds to timespec
timespec timespec_from_ms(double time_ms);

// Get current time
timespec timespec_now();

// Get negative time
timespec timespec_negate(const timespec& time_ts);

// Add two timespecs
timespec timespec_add(const timespec& time1_ts, const timespec& time2_ts);

// Subtract two timespecs (time1_ts - time2_ts)
timespec timespec_subtract(const timespec& time1_ts, const timespec& time2_ts);

// Wait por a period of delay_ts 
timespec timespec_wait(const timespec& delay_ts);

// Operators
timespec  operator- (const timespec& time_ts);
timespec  operator+ (const timespec& time1_ts, const timespec& time2_ts);
timespec  operator- (const timespec& time1_ts, const timespec& time2_ts);
timespec& operator+= (timespec& time_ts, const timespec& delay_ts);
timespec& operator-= (timespec& time_ts, const timespec& delay_ts);
bool operator== (const timespec& time1_ts, const timespec& time2_ts);
bool operator!= (const timespec& time1_ts, const timespec& time2_ts);
bool operator< (const timespec& time1_ts, const timespec& time2_ts);
bool operator> (const timespec& time1_ts, const timespec& time2_ts);

#endif