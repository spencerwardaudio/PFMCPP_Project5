#include <iostream>
#include <string>
#include <cmath>
#include "LeakedObjectDetector.h"

struct TrainRide
{
    TrainRide(bool rainState) : rain(rainState)
    {
        std::cout << "construct TrainRide" << std::endl;
    }

    ~TrainRide()
    {
        std::cout << "destruct TrainRide" << std::endl;
    }

    double progressMade(double newDistance, double newSpeed, int newTime);
    bool wakeUp();
    bool goToSleep();
    double progressMadeThisFunction(double newDistance, double newSpeed, int newTime);

    bool awake {false};
    bool rain {false};
    int timeAsleep {0}; 
    double distanceTravelled {0.0};
    double trainSpeedPerHour {30.0};

    TeaParty teaParty;

    JUCE_LEAK_DETECTOR(TeaParty)
};

