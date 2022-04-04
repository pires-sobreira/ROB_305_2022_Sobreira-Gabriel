#include "test.h"

using namespace std;

void TestMs2Time()
{
    double ms = 12345.678;
    timespec t;

    t = timespec_from_ms(ms);

    cout << "#################################################################" << endl;
    cout << "###############  Test timespec_from_ms  #########################" << endl;
    cout << "#################################################################" << endl;
    cout << "miliseconds: " << ms << "\nseconds: " << t.tv_sec << "  nano seconds: " << t.tv_nsec << endl;
}

void TestTime2Ms()
{
    double ms;
    timespec t;
    
    t.tv_sec = 2;
    t.tv_nsec = 123456789;

    ms = timespec_to_ms(t);

    cout << "#################################################################" << endl;
    cout << "###############  Test timespec_to_ms  ###########################" << endl;
    cout << "#################################################################" << endl;
    cout << "seconds: " << t.tv_sec << "  nano seconds: " << t.tv_nsec << "\nmiliseconds: " << ms << endl;
}

void TestTimeNow()
{
    timespec t;

    t = timespec_now();

    cout << "#################################################################" << endl;
    cout << "###############  Test timespec_now  #############################" << endl;
    cout << "#################################################################" << endl;
    cout << "seconds: " << t.tv_sec << "  nano seconds: " << t.tv_nsec << endl;
}

void TestTimeNegate()
{
    timespec t = {2, -100000000};

    t = timespec_negate(t);

    cout << "#################################################################" << endl;
    cout << "###############  Test timespec_negate  ##########################" << endl;
    cout << "#################################################################" << endl;
    cout << "seconds: " << t.tv_sec << "  nano seconds: " << t.tv_nsec << endl;
}

void TestTimeAdd()
{
    timespec t1, t2, tAdd;

    t1.tv_sec = 6.;
    t1.tv_nsec = 600000000.;

    t2.tv_sec = 6.;
    t2.tv_nsec = 600000000.;

    tAdd = timespec_add(t1, t2);

    cout << "#################################################################" << endl;
    cout << "###############  Test timespec_add  #############################" << endl;
    cout << "#################################################################" << endl;

    cout << "### (T1.nsec + T2.nsec) >= 1000000000 ###" << endl;
    cout << "T1 -> seconds: " << t1.tv_sec << "  nano seconds: " << t1.tv_nsec << endl;
    cout << "T2 -> seconds: " << t2.tv_sec << "  nano seconds: " << t2.tv_nsec << endl;
    cout << "T1 + T2 -> seconds: " << tAdd.tv_sec << "  nano seconds: " << tAdd.tv_nsec << endl;

    cout << endl;

    t1.tv_sec = 6.;
    t1.tv_nsec = 600000000.;

    t2.tv_sec = 6.;
    t2.tv_nsec = 300000000.;

    tAdd = timespec_add(t1, t2);

    cout << "### (T1.nsec + T2.nsec) < 1000000000 ###" << endl;
    cout << "T1 -> seconds: " << t1.tv_sec << "  nano seconds: " << t1.tv_nsec << endl;
    cout << "T2 -> seconds: " << t2.tv_sec << "  nano seconds: " << t2.tv_nsec << endl;
    cout << "T1 + T2 -> seconds: " << tAdd.tv_sec << "  nano seconds: " << tAdd.tv_nsec << endl;
}

void TestTimeSub()
{
    timespec t1 = {7, 300000000}, t2 = {6, 200000000};
    timespec tSub;

    tSub = timespec_subtract(t1, t2);

    cout << "#################################################################" << endl;
    cout << "###############  Test timespec_subtract  ########################" << endl;
    cout << "#################################################################" << endl;

    cout << "### (T1.sec > T2.sec) && (T1.nsec > T2.nsec) ###" << endl;
    cout << "T1 -> seconds: " << t1.tv_sec << "  nano seconds: " << t1.tv_nsec << endl;
    cout << "T2 -> seconds: " << t2.tv_sec << "  nano seconds: " << t2.tv_nsec << endl;
    cout << "T1 - T2 -> seconds: " << tSub.tv_sec << "  nano seconds: " << tSub.tv_nsec << endl;
    cout << endl;

    t1.tv_sec = 7.;
    t1.tv_nsec = 300000000.;

    t2.tv_sec = 6.;
    t2.tv_nsec = 300000000.;

    tSub = timespec_subtract(t1, t2);

    cout << "### (T1.sec > T2.sec) && (T1.nsec == T2.nsec) ###" << endl;
    cout << "T1 -> seconds: " << t1.tv_sec << "  nano seconds: " << t1.tv_nsec << endl;
    cout << "T2 -> seconds: " << t2.tv_sec << "  nano seconds: " << t2.tv_nsec << endl;
    cout << "T1 - T2 -> seconds: " << tSub.tv_sec << "  nano seconds: " << tSub.tv_nsec << endl;
    cout << endl;

    t1.tv_sec = 7.;
    t1.tv_nsec = 300000000.;

    t2.tv_sec = 7.;
    t2.tv_nsec = 200000000.;

    tSub = timespec_subtract(t1, t2);

    cout << "### (T1.sec == T2.sec) && (T1.nsec > T2.nsec) ###" << endl;
    cout << "T1 -> seconds: " << t1.tv_sec << "  nano seconds: " << t1.tv_nsec << endl;
    cout << "T2 -> seconds: " << t2.tv_sec << "  nano seconds: " << t2.tv_nsec << endl;
    cout << "T1 - T2 -> seconds: " << tSub.tv_sec << "  nano seconds: " << tSub.tv_nsec << endl;
    cout << endl;

    t1.tv_sec = 7.;
    t1.tv_nsec = 300000000.;

    t2.tv_sec = 7.;
    t2.tv_nsec = 300000000.;

    tSub = timespec_subtract(t1, t2);

    cout << "### (T1.sec == T2.sec) && (T1.nsec == T2.nsec) ###" << endl;
    cout << "T1 -> seconds: " << t1.tv_sec << "  nano seconds: " << t1.tv_nsec << endl;
    cout << "T2 -> seconds: " << t2.tv_sec << "  nano seconds: " << t2.tv_nsec << endl;
    cout << "T1 - T2 -> seconds: " << tSub.tv_sec << "  nano seconds: " << tSub.tv_nsec << endl;
    cout << endl;

    t1.tv_sec = 8.;
    t1.tv_nsec = 200000000.;

    t2.tv_sec = 7.;
    t2.tv_nsec = 300000000.;

    tSub = timespec_subtract(t1, t2);

    cout << "### (T1.sec > T2.sec) && (T1.nsec < T2.nsec) ###" << endl;
    cout << "T1 -> seconds: " << t1.tv_sec << "  nano seconds: " << t1.tv_nsec << endl;
    cout << "T2 -> seconds: " << t2.tv_sec << "  nano seconds: " << t2.tv_nsec << endl;
    cout << "T1 - T2 -> seconds: " << tSub.tv_sec << "  nano seconds: " << tSub.tv_nsec << endl;
    cout << endl;

    t1.tv_sec = 7.;
    t1.tv_nsec = 200000000.;

    t2.tv_sec = 7.;
    t2.tv_nsec = 300000000.;

    tSub = timespec_subtract(t1, t2);

    cout << "### (T1.sec == T2.sec) && (T1.nsec < T2.nsec) ###" << endl;
    cout << "T1 -> seconds: " << t1.tv_sec << "  nano seconds: " << t1.tv_nsec << endl;
    cout << "T2 -> seconds: " << t2.tv_sec << "  nano seconds: " << t2.tv_nsec << endl;
    cout << "T1 - T2 -> seconds: " << tSub.tv_sec << "  nano seconds: " << tSub.tv_nsec << endl;
    cout << endl;

    t1.tv_sec = 7.;
    t1.tv_nsec = 500000000.;

    t2.tv_sec = 9.;
    t2.tv_nsec = 300000000.;

    tSub = timespec_subtract(t1, t2);

    cout << "### (T1.sec < T2.sec) && (T1.nsec > T2.nsec) ###" << endl;
    cout << "T1 -> seconds: " << t1.tv_sec << "  nano seconds: " << t1.tv_nsec << endl;
    cout << "T2 -> seconds: " << t2.tv_sec << "  nano seconds: " << t2.tv_nsec << endl;
    cout << "T1 - T2 -> seconds: " << tSub.tv_sec << "  nano seconds: " << tSub.tv_nsec << endl;
    cout << endl;

    t1.tv_sec = 7.;
    t1.tv_nsec = 100000000.;

    t2.tv_sec = 9.;
    t2.tv_nsec = 100000000.;

    tSub = timespec_subtract(t1, t2);

    cout << "### (T1.sec < T2.sec) && (T1.nsec == T2.nsec) ###" << endl;
    cout << "T1 -> seconds: " << t1.tv_sec << "  nano seconds: " << t1.tv_nsec << endl;
    cout << "T2 -> seconds: " << t2.tv_sec << "  nano seconds: " << t2.tv_nsec << endl;
    cout << "T1 - T2 -> seconds: " << tSub.tv_sec << "  nano seconds: " << tSub.tv_nsec << endl;
    cout << endl;

    t1.tv_sec = 7.;
    t1.tv_nsec = 200000000.;

    t2.tv_sec = 9.;
    t2.tv_nsec = 500000000.;

    tSub = timespec_subtract(t1, t2);

    cout << "### (T1.sec < T2.sec) && (T1.nsec < T2.nsec) ###" << endl;
    cout << "T1 -> seconds: " << t1.tv_sec << "  nano seconds: " << t1.tv_nsec << endl;
    cout << "T2 -> seconds: " << t2.tv_sec << "  nano seconds: " << t2.tv_nsec << endl;
    cout << "T1 - T2 -> seconds: " << tSub.tv_sec << "  nano seconds: " << tSub.tv_nsec << endl;
    cout << endl;
}

void TestTimeWait()
{
    const timespec wait = {1, 123456789};
    timespec real_wait;

    real_wait = timespec_wait(wait);

    cout << "#################################################################" << endl;
    cout << "###############  Test timespec_wait  ############################" << endl;
    cout << "#################################################################" << endl;

    cout << "Wait -> seconds: " << wait.tv_sec << "  nano seconds: " << wait.tv_nsec << endl;
    cout << "Real Wait -> seconds: " << real_wait.tv_sec << "  nano seconds: " << real_wait.tv_nsec << endl;
}

void TestOperators()
{
    const timespec time1 = {6, 500000000}, time2 = {4, 700000000}, tDelay = {5, 500000000};

    cout << "#################################################################" << endl;
    cout << "###############  Test operators  ################################" << endl;
    cout << "#################################################################" << endl;

    cout << "time1 -> " << time1.tv_sec << " seconds and " << time1.tv_nsec << " nanoseconds."<< endl;
    cout << "time2 -> " << time2.tv_sec << " seconds and " << time2.tv_nsec << " nanoseconds."<< endl;
    cout << "tDelay -> " << tDelay.tv_sec << " seconds and " << tDelay.tv_nsec << " nanoseconds."<< endl;

    cout << "Negative Only  (-time2): " << (-time2).tv_sec << " seconds and " << (-time2).tv_nsec << " nanoseconds."<< endl;
    cout << "Addition (time1 + time2) : " << (time1 + time2).tv_sec << " seconds and " << (time1 + time2).tv_nsec << " nanoseconds." << endl;
    cout << "Subtrating (time1 - time2) : " << (time1 - time2).tv_sec << " seconds and " << (time1 - time2).tv_nsec << " nanoseconds." << endl;

    timespec time3 = time1;
    cout << "time3 -> " << time3.tv_sec << " seconds and " << time3.tv_nsec << " nanoseconds."<< endl;
    time3 += tDelay;
    cout << "Addition Assignment (time3 += tDelay) : " << time3.tv_sec << " seconds and " << time3.tv_nsec << " nanoseconds." << endl;

    cout << "time3 -> " << time3.tv_sec << " seconds and " << time3.tv_nsec << " nanoseconds."<< endl;
    time3 -= tDelay;
    cout << "Subtration Assignment (time3 -= tDelay) : " << time3.tv_sec << " seconds and " << time3.tv_nsec << " nanoseconds." << endl;

    cout << "Equal (time1 == time2) : " << (time1 == time2) << endl;
    cout << "Different (time1 != time2) : " << (time1 != time2) << endl;
    cout << "Bigger than (time1 > time2) : " << (time1 > time2) << endl;
    cout << "Smaller than (time1 < time2) : " << (time1 < time2) << endl;
}