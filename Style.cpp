#include <iostream>
#include "Style.h"

Style::Style() : 
whitePasta(false),
greenPasta(false),
flour(1.0),
thicknessOfDough(1.0)
{
    std::cout << "constructing Style" << std::endl;
}

Style::~Style()
{
    std::cout << "destructing Style" << std::endl;
}

void Style::pastaColor(bool color1, bool color2)
{
    if (color1 && color2)
        std::cout << "white & green swirl" << std::endl;
    else if(color1)
        std::cout << "white pasta" << std::endl;
    else if(color2)
        std::cout << "green pasta" << std::endl;
}

std::string Style::customShape(std::string s)
{
    name = s;
    return name;
}

double Style::addFlour(double doughWidth)
{
    if(doughWidth < 2.0 && doughWidth > 1.0)
    {
        std::cout << "add 1 cup flour" << std::endl;
        flour += 1.0;
    }
    else if(doughWidth > 2.0)
    {
        std::cout << "use a half cup less" << std::endl;
        flour -= 0.5;
    }

    return flour;
}
