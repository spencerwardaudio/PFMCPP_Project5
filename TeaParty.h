#include <iostream>
#include <string>
#include <cmath>
#include "LeakedObjectDetector.h"

struct TeaParty
 {
    TeaParty()
    {
        std::cout << "construct TeaParty" << std::endl;
    }

    ~TeaParty() 
    {
        std::cout << "destruct TeaParty" << std::endl;
    }

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