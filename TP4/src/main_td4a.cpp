#include <signal.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <pthread.h>
#include <vector>

#include "Incrementer/Incrementer.h"
#include "TimeLib/TimeLib.h"

using namespace std;

int main(int argc, char* argv[])
{
    // Check if the necessary arguments were passed
    if (argc != 3)
    {
        std::cout << "invalid format, you must especify the number of loops and tasks desired in the format:\n./td4a [nloops] [nTasks]" << std::endl;
        return 1;
    }

    unsigned int nLoops = (unsigned int) atoi(argv[1]);
    unsigned int nTasks = atoi(argv[2]);

    volatile double pCounter = 0;

    timespec tInit, tEnd;    

    vector<Incrementer> incrementer;
    
    for (unsigned int iThread = 0; iThread < nTasks; iThread++)
    {
        incrementer.push_back(Incrementer(nLoops, &pCounter));
		cout << "Thread " << iThread << " created" << endl;

    }

    tInit = timespec_now();

    for (unsigned int index = 0; index < nTasks; index++)
    {
        incrementer[index].start();
    }

    cout << endl;

    for (unsigned int index = 0; index < nTasks; index++)
    {
        incrementer[index].join();
		cout << "Thread " << index << " joined" << endl;
    }

    tEnd = timespec_now();

    cout << endl;    
    cout << "Final counter: " << pCounter << endl;
    cout << "Execution time: " << (tEnd - tInit).tv_sec << " seconds " << (tEnd - tInit).tv_nsec << " nanoseconds" << endl;
    return 0;
}