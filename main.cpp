/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12
 Create a branch named Part1
Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 
Since you didn't do Project 3:
write 3 UDTs below (where it asks for Copied UDTs) that EACH have: 
        5 member variables
            the member variable names and types should be relevant to the work the UDT will perform.
        3 member functions with an arbitrary number of parameters
            give some of those parameters default values.
        constructors that initialize some of these member variables
            the remaining member variables should be initialized in-class
        for() or while() loops that modify member variables
 1) 2 of your 3 UDTs need to have a nested UDT.
    this nested UDT should fulfill the same requirements as above:
        5 member variables  
        3 member functions
        constructors and loops.
        
 2) Define your implementations of all functions OUTSIDE of the class. 
 NO IN-CLASS IMPLEMENTATION ALLOWED
 3) add destructors to all of your UDTs
        make the destructors do something like print out the name of the class.
 
 4) add 2 new UDTs that use only the types you copied above as member variables.
 
 5) Add destructors to these 2 new types that do something.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 6) use at least 2 instances of each of your UDTs in main. 
        add some std::cout statements in main() that use your UDT's member variables.
 
 7) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
If you need inspiration for what to write, take a look at previously approved student projects in the Slack Workspace channel for this project part.
 */

/*
 UDT 1:
 */
#include <iostream>
#include <string>
#include <cmath>

struct Synth
{
    struct UIControls
    {
        UIControls(int newKnob, int newButton) : knob(newKnob), button(newButton)
        {
            std::cout << "construct UIControls" << std::endl;
        }
        ~UIControls()
        {
            std::cout << "destruct UIControls" << std::endl; 
        }

        float setKnob(float newknobPosition);
        bool buttonPress(bool newButtonState);
        int updateLEDIndicator();

        int knob {1};
        float knobPosition {0.f};
        int button {3};
        bool buttonState {false};
        int ledGainIndicator {0};
        int buttonCounter {0};
    };

    UIControls uiControls{3, 4};

    Synth();
    ~Synth();

    int modulateBeatFrequency( int newFreq1, int newFreq2 );
    float changeAttack(float newAttack);
    float changeRelease(float newRelease);
    void setGain(int newLevel);

    int frequency1 {400};
    int frequency2 {500};
    int frequencyOutput {0};
    int gain {3};
    float attack {0.f};
    float release {0.f};
};

float Synth::UIControls::setKnob(float newknobPosition)
{
    knobPosition = newknobPosition;
    std::cout << "new knob position is " << knobPosition << std::endl;

    return knobPosition;
}
bool Synth::UIControls::buttonPress(bool newButtonState)
{
    if(buttonState != newButtonState)
    {
        std::cout << "button engaged" << std::endl;
        buttonState = newButtonState;
        buttonCounter++;
        std::cout << "button counter is " << buttonCounter << std::endl;
    }

    return buttonState;
}
int Synth::UIControls::updateLEDIndicator()
{
    while (ledGainIndicator != static_cast<int>(knobPosition))
    {
        if(ledGainIndicator < static_cast<int>(knobPosition))
        {
            ledGainIndicator++;
            std::cout << "ledGainIndicator blinks and increments" << std::endl;
        }
        else
        {
            ledGainIndicator--;
            std::cout << "ledGainIndicator blinks and decrements" << std::endl;
        }
    }

    std::cout << "ledGainIndicator is " << ledGainIndicator << std::endl;

    return (ledGainIndicator);
}

Synth::Synth() : frequency1(400), frequency2(600), gain(0), attack(0.1f), release(1.0f)
{
    std::cout << "construct Synth" << std::endl;
}
Synth::~Synth()
{
    std::cout << "destruct Synth" << std::endl;
}

int Synth::modulateBeatFrequency( int newFreq1, int newFreq2 )
{
    frequencyOutput = std::abs(newFreq1 - newFreq2);
    std::cout << "frequencyOutput is " << frequencyOutput << std::endl;
    return frequencyOutput;

}
float Synth::changeAttack(float newAttack)
{
    attack = newAttack;
    std::cout << "attack is " << attack << std::endl;
    return attack;
}
float Synth::changeRelease(float newRelease)
{
    release = newRelease;
    std::cout << "release is " << release << std::endl;
    return release;
}

void Synth::setGain(int newLevel)
{
    uiControls.buttonPress(true);
    uiControls.setKnob(newLevel);
    uiControls.updateLEDIndicator();
}           

/*
 UDT 2:
 */
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
    };

    Style style;

    PastaShop();
    ~PastaShop();

    double makeCustomPasta(double requestedAmount, std::string nameOfShape, bool color1, bool color2, double doughWidth);
    double restockDough();
    void pastaProfitTotal();

    double amountOfDoughlBS {0.0};
    double pastaProfit {0.0};
    double pastaPrice {8.0};
    double customRequestTotal {0.0};
    double totalPastaWeight {0.0};

 };

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
        flour = flour + 1.0;
    }
    else if(doughWidth > 2.0)
    {
        std::cout << "use a half cup less" << std::endl;
        flour = flour - 0.5;
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

    for(int i = 0; i <= newRequestedAmount; i++)
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
        std::cout << "you have enough dough" << std::endl;
    }
    else 
    {
    std::cout << "not enough dough, make more!!" << std::endl;

    for(int i = 0; i < 3; i++)
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


/*
 UDT 3:
 */
 struct TeaParty
 {
    TeaParty(int cupsAvailable) : cupsOfTeaAvailable(cupsAvailable)
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

    int totalNumberOfCupsServed {0};
    int cupsOfTeaAvailable {10};
    int participants {3};
    bool tooMuchTea {false};
    bool biscuits {false};
    bool rain {false};
 };

int TeaParty::serve(int cups)
{
    if(!tooMuchTea || (cupsOfTeaAvailable < 3))
    {
        std::cout << "serve " << cups << " cups of tea"<< std::endl;
        
        totalNumberOfCupsServed = totalNumberOfCupsServed + cups;
        std::cout << "total amount of tea served " << totalNumberOfCupsServed << " cups of tea"<< std::endl;
    }
    else
    {
        std::cout << "no more tea" << std::endl;
    }

    return totalNumberOfCupsServed;
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

    for(int i = 0; i < amountSpilled; i++)
    {
        std::cout << " 1 cup is spilled " << std::endl;
    }
}

/*
 new UDT 4:
 */
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

    int packages {0};
    int customShapesDesigned {0};
    int packagingPay {30};
    int moneyMade {0};
    double energy {1.0};
 };

void PastaShopNewHire::sellNoodles(int soldAmount)
{
    for(int i = 0; i < soldAmount; i++)
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

    for(int i = static_cast<int>(pastaShop.amountOfDoughlBS); i > 10; i--)
    {
        energy = energy - 0.1;
        std::cout << "total energy to make pasta left " << energy << std::endl;
    }

    return moneyMade;
}

/*
 new UDT 5:
 */
struct TrainRide
{
    TrainRide(bool rainState) : rain(rainState)
    {
        std::cout << "construct TrainRide" << std::endl;
    }

    ~TrainRide()
    {
        std::cout << "destruct TrainRide" << std::endl;
    }

    bool awake {false};
    bool rain {false};
    int timeAsleep {0}; 
    double distanceTravelled {0.0};
    double trainSpeedPerHour {30.0};

    double progressMade(double newDistance, double newSpeed, int newTime);
    bool wakeUp();
    bool goToSleep();

    TeaParty teaParty{15};
};

double TrainRide::progressMade(double newDistance, double newSpeed, int newTime)
{
    if((newDistance > 0.0) && (newSpeed == 0.0))
    {
        goToSleep();
    }

    if(newDistance > (newSpeed * newTime))
        std::cout << "will not get to the destination on time " << std::endl;

    distanceTravelled = distanceTravelled + newDistance;

    return distanceTravelled;
}

bool TrainRide::wakeUp()
{
    if(!awake)
    {
        teaParty.drink(1, 1, true);
        std::cout << "wake up " << std::endl;
    }
    else if(!awake && !rain)
    {
        teaParty.drink(1, 2, true);
        std::cout << "wake up with 2 cups" << std::endl;
    }

    std::cout << "awake" << std::endl;
    awake = true;

    return awake;
}

bool TrainRide::goToSleep()
{
    std::cout << "go to sleep " << std::endl;
    auto sleepMiles = timeAsleep * trainSpeedPerHour;

    for (int i = 10; i < sleepMiles; i++)
        std::cout << "slept through 10 miles " << std::endl;

    return !awake;
}

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.
 send me a DM to review your pull request when the project is ready for review.
 Wait for my code review.
 */

#include <iostream>
int main()
{
    Synth synth;

    synth.modulateBeatFrequency(400, 500);
    synth.changeAttack(0.5f);
    synth.changeRelease(0.7f);
    synth.setGain(5);

    PastaShop pastaShop;

    pastaShop.makeCustomPasta(1.3, "parapadelli", true, true, 1.0);
    pastaShop.makeCustomPasta(3.0, "alphabet pasta", true, false, 2.0);
    pastaShop.pastaProfitTotal();

    TeaParty teaParty{15};

    teaParty.serve(3);
    teaParty.serve(4);
    teaParty.drink(2, 6, true);
    teaParty.serve(5);
    teaParty.spill();

    PastaShopNewHire pastaShopNewHire;

    pastaShopNewHire.sellNoodles(7);
    pastaShopNewHire.packNoodles(10);
    pastaShopNewHire.output();

    TrainRide trainRide{true};

    trainRide.progressMade(10.0, 30.0, 1);
    trainRide.wakeUp();
    trainRide.goToSleep();

    std::cout << "good to go!" << std::endl;
}
