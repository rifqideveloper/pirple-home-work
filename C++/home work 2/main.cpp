#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    const int MINUTES_PER_HOUR = 60;
    int numHours = 4;
    int Hours_to_minutes = numHours*MINUTES_PER_HOUR;
    //MINUTES_PER_HOUR++;
    numHours++;
    cout << "There are "<< Hours_to_minutes << " minutes in "<< numHours << " hours" << endl;
    unsigned int zeroHour = 0;
    zeroHour--;
    cout << "1 hour before zero hour is "<< zeroHour<< endl;
    return 0;
} 
