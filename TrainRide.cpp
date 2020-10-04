#include <iostream>
#include "TrainRide.h"

TrainRide::TrainRide(bool rainState) : rain(rainState)
{
    std::cout << "construct TrainRide" << std::endl;
}

TrainRide::~TrainRide()
{
    std::cout << "destruct TrainRide" << std::endl;
}

double TrainRide::progressMade(double newDistance, double newSpeed, int newTime)
{
    if((newDistance > 0.0) && (newSpeed == 0.0))
    {
        goToSleep();
    }

    if(newDistance > (newSpeed * newTime))
        std::cout << "will not get to the destination on time " << std::endl;

    return newDistance;
}

bool TrainRide::wakeUp()
{
    if(!awake)
    {
        teaParty.drink(1, 1, true);
        std::cout << "wake up " << std::endl;
    }
    else if(!awake && !rain)
    {
        teaParty.drink(1, 2, true);
        std::cout << "wake up with 2 cups" << std::endl;
    }

    std::cout << "awake" << std::endl;
    awake = true;

    return awake;
}

bool TrainRide::goToSleep()
{
    std::cout << "go to sleep " << std::endl;
    auto sleepMiles = timeAsleep * trainSpeedPerHour;

    for (int i = 10; i < sleepMiles; ++i)
        std::cout << "slept through 10 miles " << std::endl;

    return !awake;
}

double TrainRide::progressMadeThisFunction(double newDistance, double newSpeed, int newTime)
{
    std::cout << "TrainRide progressMade is: " << this->progressMade(10.0, 35.0, 2) << std::endl;

    std::cout << "trainRide trainSpeedPerHour is " << this->trainSpeedPerHour << std::endl;

    std::cout << "progressMadeThisFunction newSpeed is: " << newSpeed << std::endl; 
    std::cout << "progressMadeThisFunction newTime is: " << newTime << std::endl; 

    return newDistance;
}