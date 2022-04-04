#include <signal.h>
#include <iostream>
#include <time.h>
#include "TimeLib/TimeLib.h"

using namespace std;

// Define the increment function
void incr(unsigned int nLoops, double* pCounter)
{
    double& counter = *pCounter;
    for (unsigned int i = 0; i < nLoops; i++)
    {
        counter ++;
    }
}

int main(int argc, char* argv[])
{   
    // check if the required argument (number of loops) was properly assigned
    if (argc != 2)
    {
        std::cout << "invalid format, you must especify the number of loops desired in the format:\n./td1c [nloops]" << std::endl;
        return 1;
    }

    double counter = 0;
    unsigned int nLoops = atoi(argv[1]);
    timespec tInit, tEnd;
    tInit = timespec_now(); //get time just before the function is executed  
    incr(nLoops, &counter);
    tEnd = timespec_now(); //get time just after the function is executed
    cout << "Final counter: " << counter << endl;
    cout << "Execution time: " << (tEnd - tInit).tv_sec << "," << (tEnd - tInit).tv_nsec << " seconds" << endl; //subtract the initial time from the final to get the execution time.
    return 0;
}