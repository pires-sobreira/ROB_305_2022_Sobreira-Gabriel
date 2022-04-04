#ifndef FifoProducer_h_INCLUDED
#define FifoProducer_h_INCLUDED

#include "../TimeLib/TimeLib.h"
#include "../Fifo/Fifo.hpp"
#include "../Thread/Thread.h"
#include "../Mutex/Mutex.h"


class FifoProducer : public Thread
{
private:
	// Pointer to the object fifo
	Fifo<int> *fifo;
	
	// Number of tokens that have been given
	unsigned counter;	

	// Number of tokens wanted
	unsigned maxCount;
		
public:
	// Constructor 
	FifoProducer(Fifo<int> *fif, unsigned numItem);

	// Destructor
	~FifoProducer();

	// Handling function
	void run();

	// Get tne number of tokens already given
	unsigned getCounter();
};

#endif