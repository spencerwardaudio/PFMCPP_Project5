/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 3) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 4) write the name of your class where it says "OwnerClass"
 
 5) write wrapper classes for each type similar to how it was shown in the video
 
 7) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 you can safely ignore any warnings about exit-time-destructors.
 if you would like to suppress them, add -Wno-exit-time-destructors to the .replit file 
   with the other warning suppression flags
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
    void freq1AttackThisFunc();

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
    std::cout << "attack is ";
    return attack;
}
float Synth::changeRelease(float newRelease)
{
    release = newRelease;
    std::cout << "release is ";
    return release;
}

void Synth::setGain(int newLevel)
{
    uiControls.buttonPress(true);
    uiControls.setKnob(newLevel);
    uiControls.updateLEDIndicator();
}      

void Synth::freq1AttackThisFunc()
{
    std::cout << "Synth changeAttack(): " << this->changeAttack(0.f) << std::endl << "and Synth Frequency1 is " << this->frequency1 << std::endl;
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
    void pastaStatThisFunc();

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

/*
 UDT 3:
 */
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
 };

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
    void outputThisFunction(); 

    int packages {0};
    int customShapesDesigned {0};
    int packagingPay {30};
    int moneyMade {0};
    double energy {1.0};
 };

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

    double progressMade(double newDistance, double newSpeed, int newTime);
    bool wakeUp();
    bool goToSleep();
    double progressMadeThisFunction(double newDistance, double newSpeed, int newTime);

    bool awake {false};
    bool rain {false};
    int timeAsleep {0}; 
    double distanceTravelled {0.0};
    double trainSpeedPerHour {30.0};

    TeaParty teaParty;
};

double TrainRide::progressMade(double newDistance, double newSpeed, int newTime)
{
    if((newDistance > 0.0) && (newSpeed == 0.0))
    {
        goToSleep();
    }

    if(newDistance > (newSpeed * newTime))
        std::cout << "will not get to the destination on time " << std::endl;

    return newDistance;
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

    for (int i = 10; i < sleepMiles; ++i)
        std::cout << "slept through 10 miles " << std::endl;

    return !awake;
}

double TrainRide::progressMadeThisFunction(double newDistance, double newSpeed, int newTime)
{
    std::cout << "TrainRide progressMade is: " << this->progressMade(10.0, 35.0, 2) << std::endl;

    std::cout << "trainRide trainSpeedPerHour is " << this->trainSpeedPerHour << std::endl;

    std::cout << "progressMadeThisFunction newSpeed is: " << newSpeed << std::endl; 
    std::cout << "progressMadeThisFunction newTime is: " << newTime << std::endl; 

    return newDistance;
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
    PastaShop pastaShop;
    TeaParty teaParty;
    PastaShopNewHire pastaShopNewHire;
    TrainRide trainRide{true};

    std::cout << "synth changeAttack(): " << synth.changeAttack(0.f) << std::endl << "and synth Frequency1 is " << synth.frequency1 << std::endl;

    synth.freq1AttackThisFunc();

    std::cout << "pastaShop RestockDough(): " << pastaShop.restockDough() << std::endl << "and pastaShop pastaPrice is: " << pastaShop.pastaPrice << std::endl;

    pastaShop.pastaStatThisFunc();

    std::cout << "teaParty serve(5): " << teaParty.serve(5) << std::endl << "and teaParty cupsOfTeaAvailable is: " << teaParty.cupsOfTeaAvailable << std::endl;

    teaParty.serveThisFunction();

    std::cout << "pastaShopNewHire output(): " << pastaShopNewHire.output() << std::endl << "and pastaShopNewHire packages made: " << pastaShopNewHire.packages << std::endl;

    pastaShopNewHire.outputThisFunction();

    std::cout << "trainRide progressMade is: " << trainRide.progressMade(10.0, 35.0, 2) << std::endl << "trainRide trainSpeedPerHour is " << trainRide.trainSpeedPerHour << std::endl;

    trainRide.progressMadeThisFunction(10.0, 35.0, 2);
    
    std::cout << "good to go!" << std::endl;
}
