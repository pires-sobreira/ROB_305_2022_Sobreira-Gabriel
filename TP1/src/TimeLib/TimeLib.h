#ifndef TimeLib_h_INCLUDED
#define TimeLib_h_INCLUDED

#include <time.h>
#include <unistd.h>

/**
 * take as input a timespec object and convert to miliseconds as an double
 *
 * @param time_ts timespec object
 * @return time in milisecond
 */
double timespec_to_ms(const timespec& time_ts);

/**
 * take as input time in miliseconds and convert to timespec object
 *
 * @param time_ms time in miliseconds (double variable)
 * @return timespec object
 */
timespec timespec_from_ms(double time_ms);

/**
 * saves in a timespec object the current time when the function is called
 *
 * @return timespec object
 */
timespec timespec_now();

/**
 * Inverse time (does not allows negative numbers for nsec)
 *
 * @param time_ts timespec object
 * @return timespec object
 */
timespec timespec_negate(const timespec& time_ts);

/**
 * add two timespec object
 *
 * @param time1_ts timespec object
 * @param time2_ts timespec object
 * @return timespec object
 */
timespec timespec_add(const timespec& time1_ts, const timespec& time2_ts);

/**
 * Subtract two timespecs (time1_ts - time2_ts)
 *
 * @param time1_ts timespec object
 * @param time2_ts timespec object
 * @return timespec object
 */
timespec timespec_subtract(const timespec& time1_ts, const timespec& time2_ts);

/**
 * Creating a time stopper
 *
 * @param delay_ts timespec object
 * @return timespec object
 */
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