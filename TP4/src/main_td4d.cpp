#include <iostream>
#include <vector>

#include "Chrono/Chrono.h"
#include "FifoProducer/FifoProducer.h"
#include "FifoConsumer/FifoConsumer.h"

int main(int argc, char* argv[])
{
    if (argc == 4)
    {
        unsigned nProd = stoi(argv[1]);
        unsigned nCons = stoi(argv[2]);
        unsigned nItems = stoi(argv[3]);

        Fifo<int> fifo;
        double opThreadTimeProd = 0;
        double opThreadTimeCons = 0;
        unsigned prod = 0;
        unsigned cons = 0;

        Chrono chrono;
        
        FifoProducer *producer[nProd];
        FifoConsumer *consumer[nCons];

        // Create producers
        for (unsigned int i=0; i<nProd; i++)
        {
            producer[i] = new FifoProducer(&fifo, nItems);
        }

        // Create consumers
        for (unsigned int i=0; i<nCons; i++)
        {
            consumer[i] = new FifoConsumer(&fifo);
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
            std::cout << "\nNumber correct!!!\n" << std::endl;
        }
        else
        {
            std::cout << "\nNumber Error\n" << std::endl;
        }

        std::cout << "Time taken by producers : " << opThreadTimeProd << " ms" << std::endl;
        std::cout << "Time taken by consumers : " << opThreadTimeCons << " ms" << std::endl;
        std::cout << "Main execution time : " << chrono.lap() << "ms" << std::endl;

    }
    else
    {
        std::cout << "Error: number of arguments. 3 expected : ./td4d [nProd] [nCons] [nItems]" << std::endl;
    }

    return 0;
}