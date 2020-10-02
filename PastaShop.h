#include <iostream>
#include <string>
#include <cmath>
#include "LeakedObjectDetector.h"

struct PastaShop
 {
    struct Style
    {
        Style() : 
        whitePasta(false),
        greenPasta(false),
        flour(1.0),
        thicknessOfDough(1.0)
        {
            std::cout << "constructing Style" << std::endl;
        }

        ~Style()
        {
            std::cout << "destructing Style" << std::endl;
        }

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