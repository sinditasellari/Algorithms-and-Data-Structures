#include <iostream>
#include <algorithm>
#include <deque>
#include "WindGauge.h"
using namespace std;

// Constructor to declare period=12 as maximum history 
WindGauge::WindGauge(int period)
{
    this->period = period;
}

// Function to add current speed to the history
void WindGauge::currentWindSpeed(int speed)
{
    wind.push_back(speed);

    // Discard the oldest wind speed if history is longer than period
    if(wind.size() > (unsigned int) period){
        wind.pop_front();
    }
}

//return the highest wind speed
int WindGauge::highest() const
{
    return *max_element (wind.begin(), wind.end());
}

//return the lowest wind speed
int WindGauge::lowest() const
{
    return *min_element (wind.begin(), wind.end());
}

//return the average wind speed
int WindGauge::average() const
{
    int s = 0;
    
    for (unsigned int i = 0; i < wind.size(); i++) {
        s += wind[i];
    }

    int a = s/wind.size();
    return a;
}

//print out the lowest, highest, and average wind speed 
void WindGauge::dump()
{
    cout << "The highest: " << highest() << endl;
    cout << "The lowest: " << lowest() << endl;
    cout << "The average: " << average() << endl;
}