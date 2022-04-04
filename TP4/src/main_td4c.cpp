#include <string>
#include <stdio.h> 
#include <signal.h>
#include <iostream>

#include "Chrono/Chrono.h"
#include "Semaphore/Semaphore.h"
#include "SemaProducer/SemaProducer.h"
#include "SemaConsumer/SemaConsumer.h"


int main(int argc, char* argv[])
{
    if (argc == 4)
    {
        unsigned nProd = stoi(argv[1]);
        unsigned nCons = stoi(argv[2]);
        unsigned nItems = stoi(argv[3]);

        Semaphore semaphore;
        double opThreadTimeProd = 0;
        double opThreadTimeCons = 0;
        unsigned prod = 0;
        unsigned cons = 0;

        Chrono chrono;
        
        SemaProducer *producer[nProd];
        SemaConsumer *consumer[nCons];

        // Create producers
        for (unsigned int i=0; i<nProd; i++)
        {
            producer[i] = new SemaProducer(&semaphore, nItems);
        }

        // Create consumers
        for (unsigned int i=0; i<nCons; i++)
        {
            consumer[i] = new SemaConsumer(&semaphore);
        }

        // Start producers
        for (unsigned int i=0; i<nProd; i++)
        {
            producer[i] -> start();
        }

        // Start consumers
        for (unsigned int i=0; i<nCons; i++)
        {
            consumer[i] -> start();
        }

        // Join producers
        for (unsigned int i=0; i<nProd; i++)
        {
            producer[i] -> join();
            opThreadTimeProd += producer[i] -> execTime_ms();  
            prod += producer[i] -> getCounter();
        }

        // Join consumers
        for (unsigned int i=0; i<nCons; i++)
        {
            consumer[i] -> join();
            opThreadTimeCons += consumer[i] -> execTime_ms(); 
            cons += consumer[i] -> getCounter();
        }
        
        chrono.stop();

        std::cout << "Tokens produced : " << prod << "\nTokens consumed : " << cons << std::endl;        

        if(prod == cons)
        {
            std::cout << "Number correct!!! \n" << std::endl;
        }
        else
        {
            std::cout << "Number Error :( \n" << std::endl;
        }

        std::cout << "Time taken by producers : " << opThreadTimeProd << " ms" << std::endl;
        std::cout << "Time taken by consumers : " << opThreadTimeCons << " ms" << std::endl;
        std::cout << "Main execution time : " << chrono.lap() << "ms" << std::endl;

    }
    else
    {
        std::cout << "Error: number of arguments. 3 expected : ./td4c [nProd] [nCons] [nItems]" << std::endl;
    }

    return 0;
}