#include <signal.h>
#include <iostream>
#include <time.h>
#include <pthread.h>

#include "TimeLib/TimeLib.h"

using namespace std;

struct Data 
{
    unsigned int nLoops;
    volatile double pCounter;
};

void incr(unsigned int nLoops, double* pCounter)
{
    for (unsigned int i = 0; i < nLoops; i++)
    {
        *pCounter = *pCounter + 1.0;
    }
}

void* call_incr(void* v_data) 
{
    Data* p_data = (Data*) v_data;

    incr(p_data->nLoops, (double*) &p_data->pCounter);
    
    return v_data;
}

int main(int argc, char* argv[])
{
    if (argc < 4)
    {
        cout<<"insuficient arguments \n1st argument: Number of loops iteration \n2nd argument: Number of tasks to be created \n3rd argument: specify ordering method (SCHED_RR, SCHED_FIFO or SCHED_OTHER)" << endl;
        return 0;
    }

    string schedArg(argv[3]);
    unsigned int nTasks = atoi(argv[2]);
    unsigned int nLoops = atoi(argv[1]);
    struct sched_param schedParam, schedParamMain;
    int schedPolicy;
    
    if(schedArg == "SCHED_RR") 
    {
		schedPolicy=1;
        std::cout << "Scheduler type set as SCHED_RR" << std::endl;	
    }
    else if(schedArg == "SCHED_FIFO") 
    {
        schedPolicy=2;
        std::cout << "Scheduler type set as SCHED_FIFO" << std::endl;	
    }
    else 
    {
        schedPolicy=0;
        std::cout << "Scheduler type set as SCHED_OTHER" << std::endl;	
    }

    schedParam.sched_priority = (schedPolicy == 0) ? 0 : 10;

    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setschedpolicy(&attr, schedPolicy);
    pthread_attr_setschedparam(&attr, &schedParam);
    
	schedParamMain.sched_priority = sched_get_priority_max(schedPolicy);
	pthread_setschedparam(pthread_self(), schedPolicy, &schedParamMain);
    
    timespec tInit, tEnd;

    Data data = {nLoops, 0.0};

    pthread_t incrementThread[nTasks];

    
    tInit = timespec_now();

    for (unsigned int i = 0; i < nTasks; i++)
    {
        pthread_create(&incrementThread[i], &attr, call_incr, (void*) &data);
        cout << "created thread " << i << endl;
    }

    cout << endl;

    for (unsigned int i = 0; i < nTasks; i++)
    {
        pthread_join(incrementThread[i], NULL);
        cout << "joined thread " << i << endl;
    }

    cout << endl;

    tEnd = timespec_now();
    cout << "Final counter: " << data.pCounter << endl;
    cout << "Execution time: " << (tEnd - tInit).tv_sec << "," << (tEnd - tInit).tv_nsec << " seconds" << endl;
    return 0;
}