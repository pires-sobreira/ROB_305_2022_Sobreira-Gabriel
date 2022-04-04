#ifndef PosixThread_PosixThread_h_INCLUDED
#define PosixThread_PosixThread_h_INCLUDED

#include <exception>
#include <pthread.h>
#include <cerrno>
#include <ctime>
#include <iostream>
#include <stdexcept>

#include"../TimeLib/TimeLib.h"

using namespace std;

class PosixThread
{
public:
    using Func = void* (*) (void*);

    class Exception : exception
	{
	public:	
		const char* what() const noexcept;
	};

    //constructor
    PosixThread();
    PosixThread(pthread_t posixId);

    //destructor
    ~PosixThread();

    //functions
    void start(Func threadFunc, void* threadArg);
    void join();
    bool join(double timeout_ms);
    bool setScheduling(int schedPolicy, int priority);
    bool getScheduling(int* pSchedPolicy = nullptr, int* pPriority = nullptr);

protected: //amarelo
    bool isActive;

private:
    pthread_t posixId;
    pthread_attr_t posixAttr;

    
};

#endif