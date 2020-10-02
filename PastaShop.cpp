
#include "PastaShop.h"

void PastaShop::Style::pastaColor(bool color1, bool color2)
{
    if (color1 && color2)
        std::cout << "white & green swirl" << std::endl;
    else if(color1)
        std::cout << "white pasta" << std::endl;
    else if(color2)
        std::cout << "green pasta" << std::endl;
}

std::string PastaShop::Style::customShape(std::string s)
{
    name = s;
    return name;
}

double PastaShop::Style::addFlour(double doughWidth)
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

PastaShop::PastaShop() :
amountOfDoughlBS(5.0),
pastaProfit(0.0)
{
    std::cout << "construct PastaShop" << std::endl;
}

PastaShop::~PastaShop() 
{
    std::cout << "destruct PastaShop" << std::endl;
}

double PastaShop::makeCustomPasta(double newRequestedAmount, std::string nameOfShape  = "default", bool color1 = true, bool color2 = true, double doughWidth = 1.0)
{
    style.customShape(nameOfShape);
    std::cout << "pasta shape requested: " << style.name << std::endl;
    std::cout << "amount of requested pasta: " << newRequestedAmount << " lBs" << std::endl;
    style.pastaColor(color1, color2);
    style.addFlour(doughWidth);
    std::cout << "you need " << style.flour << " cup of flour" << std::endl;

    for(int i = 0; i <= newRequestedAmount; ++i)
    {
        amountOfDoughlBS -= 1.0;
        totalPastaWeight += 1.0;
        std::cout << "total pasta sliced " << totalPastaWeight << " lBs" << std::endl;
    }

    restockDough();

    return customRequestTotal += newRequestedAmount;
}

double PastaShop::restockDough()
{
    if (amountOfDoughlBS > 2.0)
    {
        std::cout << "you have enough dough ";
    }
    else 
    {
    std::cout << "not enough dough, make more!!";

    for(int i = 0; i < 3; ++i)
    {
        amountOfDoughlBS += 2.0;
        std::cout << "made 2 Lbs of dough" << std::endl;
        std::cout << "you have: " << amountOfDoughlBS << " Lbs of dough total" << std::endl;
    }
    }

    return amountOfDoughlBS;
}

void PastaShop::pastaProfitTotal()
{
    pastaProfit = customRequestTotal * pastaPrice;
    std::cout << "profit for the hour is: $ " << pastaProfit << std::endl;
}

void PastaShop::pastaStatThisFunc()
{
    std::cout << "PastaShop RestockDough(): " << this->restockDough() << std::endl << "and PastaShop pastaPrice is: " << pastaPrice << std::endl;
}