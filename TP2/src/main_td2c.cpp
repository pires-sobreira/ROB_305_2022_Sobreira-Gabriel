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
    string protec;
    pthread_mutex_t mutex;
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
    if(p_data->protec.compare("protected")==0) pthread_mutex_lock(&p_data->mutex); // Check if the protected parameter was passed as protected to activate the mutex and lock
    incr(p_data->nLoops, (double*) &p_data->pCounter);
    if(p_data->protec.compare("protected")==0) pthread_mutex_unlock(&p_data->mutex); // Check if the protected parameter was passed as protected to unlock
    return v_data;
}

int main(int argc, char* argv[])
{
    string input;

    // Check if were passed only two arguments, in this case assume the input as an empty string 
    if (argc == 3) input = "";
    
    // Check if were passed enougth arguments in command line
    else if (argc == 4) input = argv[3];

    else
    {
        cout<<"insuficient arguments \n1st argument: Number of loops iteration \n2nd argument: Number of tasks to be created \n3rd argument: if passed activates mutex (use as agument: protected)" << endl;
        return 1;
    }

    // Assign the values passed in command line to variables
    unsigned int nTasks = atoi(argv[2]);
    unsigned int nLoops = atoi(argv[1]);
    timespec tInit, tEnd;
    Data data = {nLoops, 0.0, input};

    pthread_mutex_init(&data.mutex, nullptr); // Create mutex object
    pthread_t incrementThread[nTasks]; // Create pthread_t vector with the size of the number of desired tasks

    tInit = timespec_now();

    // Starts all the threads
    for (unsigned int i = 0; i < nTasks; i++)
    {
        pthread_create(&incrementThread[i], NULL, call_incr, (void*) &data);
        cout << "created thread " << i << endl;
    }

    cout << endl;

    // Join the threads when they are finished
    for (unsigned int i = 0; i < nTasks; i++)
    {
        pthread_join(incrementThread[i], NULL);
        cout << "joined thread " << i << endl;
    }

    // Destroy mutex object
    pthread_mutex_destroy(&data.mutex);

    tEnd = timespec_now();

    cout << endl;
    
    cout << "Final counter: " << data.pCounter << endl;
    cout << "Execution time: " << (tEnd - tInit).tv_sec << " seconds " << (tEnd - tInit).tv_nsec << " nanoseconds" << endl;
    return 0;
}