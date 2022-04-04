# include "Thread.h"

//constructor
Thread::Thread(): PosixThread()
{

}
//destructor
Thread::~Thread()
{

}
//fonctions
void Thread::start()
{
    if(!began)
    {	
        startTime = timespec_to_ms(timespec_now());
        PosixThread::start(call_run, (void*) this);
        began = true;
    }
}

void Thread::sleep_ms(double delay_ms)
{
    timespec_wait(timespec_from_ms(delay_ms));
}

void Thread::setStopTime()
{
    stopTime = timespec_to_ms(timespec_now());
}


double Thread::startTime_ms()
{
    return startTime;
}

double Thread::stopTime_ms()
{
    return stopTime;
}

double Thread::execTime_ms()
{
    return stopTime - startTime;
}


void* Thread::call_run(void* v_thread)
{
    Thread* thread = (Thread*) v_thread;
    thread->run();
    thread->setStopTime();
    return (void*) thread;
}