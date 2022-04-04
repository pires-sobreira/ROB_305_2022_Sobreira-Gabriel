#include <signal.h>
#include <iostream>
#include <time.h>

using namespace std;

//Define callback function that the timer will call
void myHandler(int sig, siginfo_t* si, void*)
{
    volatile int& countRef = *((int*)si->si_value.sival_ptr);
    cout << "counter " << countRef << endl;
    countRef += 1;
}
int main()
{
    // Define sigaction
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = myHandler;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGRTMIN, &sa, nullptr);

    // Define sigevent
    struct sigevent sev;
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGRTMIN;
    volatile int counter = 0;
    sev.sigev_value.sival_ptr = (void*) &counter;
    
    // Define timer
    timer_t tid;
    timer_create(CLOCK_REALTIME, &sev, &tid);
    itimerspec its;
    its.it_value.tv_sec = 0;        
    its.it_value.tv_nsec = 5e8; // define the delay time to call the first time the callback function
    its.it_interval.tv_sec = 0;
    its.it_interval.tv_nsec = 5e8; // define the time interval to regularly call the callback function after the first call. *if you only want to call the callback once set it to zero
    timer_settime(tid, 0, &its, nullptr);

    while (counter < 15) 
    {    
        continue;
    }

    // Destroy the timer
    timer_delete(tid);
}

