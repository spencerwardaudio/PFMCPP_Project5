#include <iostream>
#include <string>
#include <cmath>
#include "LeakedObjectDetector.h"

struct PastaShopNewHire
 {
    PastaShopNewHire()
    {
        std::cout << "construct PastaShopNewHire" << std::endl;
    }

    ~PastaShopNewHire()
    {
        std::cout << "destruct PastaShopNewHire" << std::endl;
    }

    PastaShop pastaShop;

    void sellNoodles(int soldAmount);
    int packNoodles(int newPackages);
    int output();
    void outputThisFunction(); 

    int packages {0};
    int customShapesDesigned {0};
    int packagingPay {30};
    int moneyMade {0};
    double energy {1.0};

    JUCE_LEAK_DETECTOR(PastaShopNewHire)
 };