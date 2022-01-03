/*
  Sindi Tasellari
  stasellari@jacobs-university.de
  a1.p5.cpp
*/

#include <iostream>
#include "WindGauge.h"
using namespace std;

int main()
{
    // Creating a WindGauge object
    WindGauge w1;

    // Adding wind speeds
    w1.currentWindSpeed(15);
    w1.currentWindSpeed(16);
    w1.currentWindSpeed(12);
    w1.currentWindSpeed(15);
    w1.currentWindSpeed(15);

    // Dump the gauge
    w1.dump();

    // Adding more wind speeds.
    w1.currentWindSpeed(16);
    w1.currentWindSpeed(17);
    w1.currentWindSpeed(16);
    w1.currentWindSpeed(16);
    w1.currentWindSpeed(20);
    w1.currentWindSpeed(17);
    w1.currentWindSpeed(16);
    w1.currentWindSpeed(15);
    w1.currentWindSpeed(16);
    w1.currentWindSpeed(20);

    cout << endl;
    //Dump the gauge
    w1.dump(); 

    return 0;
}