#include <signal.h>
#include <iostream>
#include <time.h>
#include <climits>
#include "TimeLib/TimeLib.h"

using namespace std;

unsigned int incr(unsigned int nLoops, double* pCounter, volatile bool* pStop)
{
    double& counter = *pCounter;
    timespec tInit, tEnd;
    tInit = timespec_now();
    for (unsigned int i = 0; i < nLoops; i++)
    {
        if (*pStop)
            break;
        counter ++;
    }
    return (unsigned int)counter;
}

void myHandler(int sig, siginfo_t* si, void*)
{
    volatile bool& stop = *((bool*)si->si_value.sival_ptr);
    stop = true;
    std::cout << "stop -> true" <<  std::endl;
}

double setIncrement(time_t sec){
    double counter = 0.0;
    unsigned int fCounter;
    volatile bool stop = false;
    
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = myHandler;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGRTMIN, &sa, nullptr);

    struct sigevent sev;
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGRTMIN;
    sev.sigev_value.sival_ptr = (void*) &stop;
    
    timer_t tid;
    timer_create(CLOCK_REALTIME, &sev, &tid);
    itimerspec its;
    its.it_value.tv_sec = sec;
    its.it_value.tv_nsec = 0;
    its.it_interval.tv_sec = 0;
    its.it_interval.tv_nsec = 0;
    timer_settime(tid, 0, &its, nullptr);

    fCounter = incr(UINT_MAX, &counter, &stop);

    cout << "Final counter: " << fCounter << endl;

    timer_delete(tid);

    return fCounter;
}

struct coef{
    double a;
    double b;
};

coef calib(){
    coef params;

    double iLoop_1sec = setIncrement((time_t) 1);
    double iLoop_4sec = setIncrement((time_t) 4);
    double iLoop_6sec = setIncrement((time_t) 6);
    
    double a1, a2, a3, b1, b2, b3;

    a1 = (iLoop_4sec - iLoop_1sec)/(4 - 1);
    b1 = (iLoop_4sec - a1*4);

    a2 = (iLoop_6sec - iLoop_4sec)/(6 - 4);
    b2 = (iLoop_6sec - a2*6);

    a3 = (iLoop_6sec - iLoop_1sec)/(6 - 1);
    b3 = (iLoop_6sec - a3*6);

    params.a = (a1 + a2 + a3)/3;
    params.b = (b1 + b2 + b3)/3;

    return params;
}

int main(int argc, char* argv[])
{
    coef params = calib();

    std::cout << "\na = " << params.a << " b = " << params.b << std::endl;

    std::cout << "\nFor a 12 seconds timer:" << std::endl;
    timespec tInit, tEnd;
    tInit = timespec_now();
    double coefCal = setIncrement((time_t) 9);
    tEnd = timespec_now();
    std::cout << "\nTime needed : " << (timespec_to_ms((const timespec) ((tEnd - tInit)))/1000) << " seconds" << std::endl; 
    std::cout << "\niLoop directed obtained = " << coefCal << std::endl; 

    double coefCalFunction = params.a*9 + params.b;
    std::cout << "\niLoop directed by the function= " << coefCalFunction << std::endl; 
    std::cout << "\nAccuracy: " << (1-(abs(coefCal - coefCalFunction) /coefCal))*100 << "%" << std::endl;

    return 0;
}