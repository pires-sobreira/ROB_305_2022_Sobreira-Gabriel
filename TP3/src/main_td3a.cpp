#include "Chrono/Chrono.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    Chrono chrono; // Create chrono instance

    chrono.restart(); // Reset the chrono counting time and gives initial time reference

    cout << "Wait 2 seconds" << endl;
    sleep(2); // stop code execution for 2 sendos 
    cout << "chrono lap measure: " << chrono.lap() << " miliseconds" << endl; // Compare the initial time reference with the current to give the elapsed timed
    cout << "Wait more 1 second" << endl;
    sleep(1);
    cout << "chrono lap measure: " << chrono.lap() << " miliseconds" << endl; // Compare the initial time reference with the current to give the elapsed timed

    chrono.stop(); // Gives final reference time and stop counting time
    cout << "Stopping chrono" << endl;
    

    cout << "start time: " << chrono.startTime() << "\nstop time: " << chrono.stopTime() << endl;


    cout << "Wait 1 second" << endl;
    sleep(1);
    cout << "chrono lap measure: " << chrono.lap() << " miliseconds" << endl; // Wait one second and certify that the chrono has stopped

    cout << "Restarting chrono" << endl;
    chrono.restart();  // Reset the chrono counting time and gives initial time reference

    cout << "Wait 4 second" << endl;
    sleep(4);
    cout << "chrono lap measure: " << chrono.lap() << " miliseconds" << endl; // Certify the chrono is properly counting time after being reseted

    cout << "start time: " << chrono.startTime() << "\nstop time: " << chrono.stopTime() << endl;

    cout << "Stopping chrono.\nEnd of testing" << endl;
    chrono.stop();
    return 0;
}