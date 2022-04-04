#include "CountDown.h"

CountDown::CountDown(int nLoops) : PeriodicTimer()
{
    loops = nLoops;
}
void CountDown::callback()
{
    loops--;
    std::cout << "Count Down in: " << loops << std::endl;
    if (loops == 0)
        stop();
}

int CountDown::GetLoops()
{
    return loops;
}