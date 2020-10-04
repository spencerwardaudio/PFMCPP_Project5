#pragma once
#include "LeakedObjectDetector.h"

struct TeaParty
 {
    TeaParty();
    ~TeaParty();

    int serve(int cups);    
    bool drink(int individuals, int cups, bool food);
    void spill();
    void serveThisFunction();

    int totalNumberOfCupsServed {0};
    int cupsOfTeaAvailable {10};
    int participants {3};
    bool tooMuchTea {false};
    bool biscuits {false};
    bool rain {false};

    JUCE_LEAK_DETECTOR(TeaParty)
 };