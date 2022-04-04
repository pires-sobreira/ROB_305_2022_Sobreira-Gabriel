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
        *pCounter = *pCounter + 1;
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
    // Check if the necessary arguments were passed
    if (argc != 3)
    {
        std::cout << "invalid format, you must especify the number of loops and tasks desired in the format:\n./td2a [nloops] [nTasks]" << std::endl;
        return 1;
    }

    // Assign the input arguments to the corresponding variable
    unsigned int nTasks = atoi(argv[2]); 
    unsigned int nLoops = atoi(argv[1]);

    timespec tInit, tEnd;

    Data data = {nLoops, 0.0};

    // Create pthread_t vector with the size of the number of desired tasks
    pthread_t incrementThread[nTasks];

    
    tInit = timespec_now(); //Measure Initial time

    // Create the tasks
    for (unsigned int i = 0; i < nTasks; i++)
    {
        pthread_create(&incrementThread[i], NULL, call_incr, (void*) &data); // Each thread will call the call_incr function and will access the variables in the data struct
        cout << "created thread " << i << endl;
    }

    cout << endl;


    // After each thread finishes to execute it will joined
    for (unsigned int i = 0; i < nTasks; i++)
    {
        pthread_join(incrementThread[i], NULL);
        cout << "joined thread " << i << endl;
    }

    cout << endl;

    tEnd = timespec_now(); // Measure final time

    cout << "Final counter: " << data.pCounter << endl;
    cout << "Execution time: " << (tEnd - tInit).tv_sec << " seconds " << (tEnd - tInit).tv_nsec << " nanoseconds" << endl;
    return 0;
}