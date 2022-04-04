#include <iostream>
#include <vector>

#include "IncrementerMutex/IncrementerMutex.h"

int main(int argc, char* argv[])
{
    if(argc != 3){
        std::cout << "Value 'nLoops' 'nTasks' required." << std::endl;
        return 1;
    }

    int nLoops = strtoul(argv[1], NULL, 10);
    int nTasks = strtoul(argv[2], NULL, 10);

    Mutex mutex;
    timespec tEnd, tInit;

    tInit = timespec_now();

    volatile double pCounter = 0;
    std::vector<IncrementerMutex> incrementer;

	for (int i = 0; i < nTasks; i++){
        incrementer.push_back(IncrementerMutex((unsigned int)nLoops, &pCounter, mutex));
		std::cout << "Thread " << i << " created" << std::endl;
    }

    for (int j = 0; j < nTasks; j++){
        incrementer[j].start();
        //std::cout << "test" << std::endl;
    }

    std::cout << std::endl;
    for (int k = 0; k < nTasks; k++){
        incrementer[k].join();
        std::cout << "Thread " << k << " joined" << std::endl;
    }

    std::cout << std::endl;

    for (int i = 0; i < nTasks; i++)
    {
        std::cout << "Thread " << i << " execution time: " << incrementer[i].execTime_ms() << " ms" << std::endl;
    }

    tEnd = timespec_now();
    double totalExecTime = timespec_to_ms(tEnd - tInit);

    std::cout << "Final counter value: " << pCounter << std::endl;    
    std::cout << "Execution time: " << totalExecTime << std::endl; //(tEnd - tInit).tv_sec << " seconds " << (tEnd - tInit).tv_nsec << " nanoseconds" << endl;    
    return 0;
}