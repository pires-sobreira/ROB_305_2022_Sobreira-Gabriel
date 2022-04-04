#ifndef Mutex_h_INCLUDED
#define Mutex_h_INCLUDED

#include <exception>
#include <pthread.h>
#include <cerrno>
#include <ctime>
#include <stdexcept>
#include <iostream>

using namespace std;

class Mutex
{
private:
	pthread_mutex_t posixId;
	pthread_cond_t posixCondId; 

public:
	class Monitor
	{
	public:
		class TimeoutException : exception
		{
		public:
			const char *error();
		};
	protected:
		Mutex &m;
		Monitor(Mutex& m);

	public:
		void wait();
		bool wait(double timeout_ms);

		void notify();
		void notifyAll();

	};

	class TryLock : public Monitor
	{
	public:
		TryLock(Mutex& m);
		~TryLock();

	};

	class Lock : public Monitor
	{
	public: 
		Lock(Mutex& m);
		Lock(Mutex& m, double timeout_ms);
		~Lock();
			
	};

public:
	Mutex();
	~Mutex();

private:
	void lock();

	bool lock(double timeout_ms);
	bool trylock();

	void unlock();

};


// class Mutex::Monitor
// {
// public:
// 	class TimeoutException 
// 		: std::exception
// 	{
//   public:
//     const char *error();
// 	};
// protected:
// 	Mutex &m;
// 	Monitor(Mutex& m);

// public:
// 	void wait();
// 	bool wait(double timeout_ms);

// 	void notify();
// 	void notifyAll();

// };


// class Mutex::TryLock 
//   : public Monitor
// {
// public:
// 	TryLock(Mutex& m);
// 	~TryLock();

// };

// class Mutex::Lock 
//   : public Monitor
// {
// public: 
// 	Lock(Mutex& m);
// 	Lock(Mutex& m, double timeout_ms);
// 	~Lock();
		
// };

#endif