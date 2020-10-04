#pragma once
#include "TeaParty.h"
#include "LeakedObjectDetector.h"

struct TrainRide
{
    TeaParty teaParty;

    TrainRide(bool rainState);
    ~TrainRide();

    double progressMade(double newDistance, double newSpeed, int newTime);
    bool wakeUp();
    bool goToSleep();
    double progressMadeThisFunction(double newDistance, double newSpeed, int newTime);

    bool awake {false};
    bool rain {false};
    int timeAsleep {0}; 
    double distanceTravelled {0.0};
    double trainSpeedPerHour {30.0};

    JUCE_LEAK_DETECTOR(TeaParty)
};

