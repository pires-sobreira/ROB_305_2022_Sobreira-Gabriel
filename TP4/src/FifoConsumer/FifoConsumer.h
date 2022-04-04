#ifndef FifoConsumer_h_INCLUDED
#define FifoConsumer_h_INCLUDED

#include <pthread.h>
#include <iostream>

#include "../Mutex/Mutex.h"
#include "../Thread/Thread.h"
#include "../Fifo/Fifo.hpp"
#include "../TimeLib/TimeLib.h"

class FifoConsumer : public Thread
{
private:
	// Pointer to the object fifo 
	Fifo<int> *fifo;

	// Number of tokens that have been consumed
	unsigned counter;	
	
public:
	// Constructor 
	FifoConsumer(Fifo<int> *fif);

	// Destructor
	~FifoConsumer();

	// Handling function
	void run();

	// Get tne number of tokens already consumed
	unsigned getCounter();
};

#endif