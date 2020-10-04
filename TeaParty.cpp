#include <iostream>
#include "TeaParty.h"

TeaParty::TeaParty()
{
    std::cout << "construct TeaParty" << std::endl;
}

TeaParty::~TeaParty() 
{
    std::cout << "destruct TeaParty" << std::endl;
}

int TeaParty::serve(int cups)
{
    if(!tooMuchTea || (cupsOfTeaAvailable < 3))
        std::cout << "serve " << cups << " cups of tea" << std::endl;
    else
        std::cout << "no more tea";
        
    return 10;
}   

bool TeaParty::drink(int individuals, int cups, bool food)
{
    auto amountPerIndividual = cups / individuals;
    std::cout << "all of the participants have had " << amountPerIndividual << " cups of tea"<< std::endl;

    if(amountPerIndividual <= 2)
    {
        std::cout << "they can have more tea" << std::endl;
    }
    else
    {
        tooMuchTea = true;
        std::cout << "too much tea" << std::endl;
    }

    if(food)
    {
        std::cout << "they should eat something" << std::endl;
    }

    return tooMuchTea;
}

void TeaParty::spill()
{
    auto amountSpilled = (totalNumberOfCupsServed / participants);

    for(int i = 0; i < amountSpilled; ++i)
    {
        std::cout << " 1 cup is spilled " << std::endl;
    }
}

void TeaParty::serveThisFunction()
{
    std::cout << "TeaParty serve(5): " << this->serve(5) << std::endl << "and TeaParty cupsOfTeaAvailable is: " << this->cupsOfTeaAvailable << std::endl;
}


