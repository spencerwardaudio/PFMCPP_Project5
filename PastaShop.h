#pragma once
#include "Style.h"
#include "LeakedObjectDetector.h"

struct Style;

struct PastaShop
{
    Style style;

    PastaShop();
    ~PastaShop();

    double makeCustomPasta(double requestedAmount, std::string nameOfShape, bool color1, bool color2, double doughWidth);
    double restockDough();
    void pastaProfitTotal();
    void pastaStatThisFunc();

    double amountOfDoughlBS {0.0};
    double pastaProfit {0.0};
    double pastaPrice {8.0};
    double customRequestTotal {0.0};
    double totalPastaWeight {0.0};

    JUCE_LEAK_DETECTOR(PastaShop)
};