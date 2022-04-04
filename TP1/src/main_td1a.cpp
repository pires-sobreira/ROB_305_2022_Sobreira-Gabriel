#include "tests/test.h"

int main()
{
    TestMs2Time();
    TestTime2Ms();
    TestTimeNow(); 
    TestTimeNegate();
    TestTimeAdd();
    TestTimeSub();
    TestTimeWait();
    TestOperators();
    return 0;
}