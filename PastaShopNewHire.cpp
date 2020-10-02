#include "PastaShopNewHire.h"

void PastaShopNewHire::sellNoodles(int soldAmount)
{
    for(int i = 0; i < soldAmount; ++i)
    {
        pastaShop.makeCustomPasta(1.3, "New Shape", true, true, 1.0);
    }
}

int PastaShopNewHire::packNoodles(int newPackages)
{
    packages = newPackages;
    packagingPay = static_cast<int>(newPackages * pastaShop.pastaPrice / 3);

    return packagingPay;
}

int PastaShopNewHire::output()
{
    moneyMade = static_cast<int>(pastaShop.pastaProfit + packagingPay);

    for(int i = static_cast<int>(pastaShop.amountOfDoughlBS); i > 10; --i)
    {
        energy = energy - 0.1;
        std::cout << "total energy to make pasta left " << energy << std::endl;
    }

    return moneyMade;
}

void PastaShopNewHire::outputThisFunction()
{
    std::cout << "PastaShopNewHire output(): " << this->output() << std::endl << "and PastaShopNewHire packages made: " << this->packages << std::endl;
}