#ifndef Chrono_Chrono_h_INCLUDED
#define Chrono_Chrono_h_INCLUDED

#include "../TimeLib/TimeLib.h"

class Chrono
{
    private:

    //Variables
    timespec startTime_;
    timespec stopTime_;

    public:

    //Constructor
    Chrono();

    //Functions
    void stop();	
	void restart();
	bool isActive();	
	double startTime();
	double stopTime();
	double lap();

};

#endif