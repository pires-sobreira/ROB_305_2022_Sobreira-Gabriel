
#ifndef Mutex_TryLock_h_INCLUDED
#define Mutex_TryLock_h_INCLUDED

#include "Monitor.h"

/**
 * @brief class Trylock that derives from Monitor and will give the possiblity to use the trylock function on a mutex
 * 
 */
class Mutex::TryLock : public Monitor
{
public:
	/**
	 * @brief Construct a new Try Lock object
	 * 
	 * @param m reference to the mutex that will be locked
	 */
	TryLock(Mutex &m);

	/**
	 * @brief Destroy the Try Lock object
	 * 
	 */
	~TryLock();
};

#endif
