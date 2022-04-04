#include "PosixThread.h"

//constructor
PosixThread::PosixThread()
{
    this->isActive = false;
    this->posixId = 0;
    struct sched_param schedParam;
    schedParam.sched_priority = 0;
    pthread_attr_init(&posixAttr);
    pthread_attr_setschedpolicy(&posixAttr, SCHED_OTHER);
    pthread_attr_setinheritsched(&posixAttr, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setschedparam(&posixAttr, &schedParam);

}

PosixThread::PosixThread(pthread_t posixId): posixId(posixId)
{
    struct sched_param schedParam;
    int policy = SCHED_RR;
    int param = pthread_getschedparam(this -> posixId, &policy, &schedParam);
    pthread_attr_init(&posixAttr);
    pthread_attr_setinheritsched(&posixAttr, PTHREAD_EXPLICIT_SCHED);

    if(param == ESRCH) 
    {
        throw PosixThread::Exception();
    }
    else 
    {
        this->isActive = true;
        pthread_attr_setschedpolicy(&posixAttr, policy);
        pthread_attr_setschedparam(&posixAttr, &schedParam); 
    }
}

//destructor
PosixThread::~PosixThread()
{
    pthread_attr_destroy(&posixAttr);
}

//functions
void PosixThread::start(Func threadFunc, void* threadArg)
{
    pthread_create(&posixId, &posixAttr, threadFunc, threadArg);
    isActive = true;
}

void PosixThread::join()
{
    pthread_join(posixId, NULL);
}
bool PosixThread::join(double timeout_ms)
{
    timespec timeout(timespec_from_ms(timeout_ms));
    return pthread_timedjoin_np(posixId, NULL, &timeout); 
}
bool PosixThread::setScheduling(int schedPolicy, int priority)
{
    struct sched_param schedParam;
    schedParam.sched_priority = priority; 

    if(isActive) 
    {
        pthread_setschedparam(posixId, schedPolicy, &schedParam);
    } 

    else
    {
        pthread_attr_setschedpolicy(&posixAttr, schedPolicy);
        pthread_attr_setschedparam(&posixAttr, &schedParam);
    }

    return isActive;
}

bool PosixThread::getScheduling(int* pSchedPolicy , int* pPriority )
{
    struct sched_param schedParam;
    *pPriority = schedParam.sched_priority; 

    if(isActive) 
    {
        pthread_getschedparam(posixId, pSchedPolicy, &schedParam);
    } 
    else 
    {
        pthread_attr_getschedpolicy(&posixAttr, pSchedPolicy);
        pthread_attr_getschedparam(&posixAttr, &schedParam);
    }

    return isActive;
}

const char *PosixThread::Exception::what() const noexcept
{
  return "\nInvalid thread! Does not exist\n";
}