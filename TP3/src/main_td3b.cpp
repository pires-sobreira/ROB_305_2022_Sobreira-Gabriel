#include "CountDown/CountDown.h"
#include <iostream>

using namespace std;

// Command line: 
int main(int argc, char* argv[])
{
    // Check if the input arguments were passed in the command line
    if(argc != 2){
        cout << "Missing number of loops, must be: ./td3b [nLoops]" << endl;
        return 1;
    }

    // Assign the input argument to the corresponding variable
    int nLoops = atoi(argv[1]);

    CountDown countDown(nLoops); // initializate countDown object with the desired number of loops
    countDown.start(1000); // start the countdown, and passes as argument the interval (in miliseconds) to do the counting
    while (countDown.GetLoops() > 0) // Wait until the count down gets to zero
    {

    }
    return 0;
}