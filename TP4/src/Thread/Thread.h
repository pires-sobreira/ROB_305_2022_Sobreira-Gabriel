#ifndef Thread_Thread_h_INCLUDED
#define Thread_Thread_h_INCLUDED

#include "../PosixThread/PosixThread.h"

class Thread: public PosixThread
{
public:
    //constructor
    Thread();
    //destructor
    ~Thread();
    //fonctions
    void start();
    static void sleep_ms(double delay_ms);
    double startTime_ms();
    double stopTime_ms();
    double execTime_ms();
    void setStopTime();

protected:
    virtual void run() = 0;

private:
    static void* call_run(void* v_thread);

    double startTime, stopTime;
    bool began = false;
};

#endif