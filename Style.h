#pragma once
#include "LeakedObjectDetector.h"

struct Style
{
    Style();
    ~Style();

    void pastaColor(bool color1, bool color2);
    std::string customShape(std::string s);
    double addFlour(double doughWidth);

    bool whitePasta {false};
    bool greenPasta {true};
    std::string name {"default"};
    double flour {0};
    double thicknessOfDough {1.0};

    JUCE_LEAK_DETECTOR(Style)
};
