/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via 'this->' and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.
 
 2) For each std::cout statement in main() that accessed member variables of your types or printed out the results of your member function calls,
        a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
        b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
        c) call that member function after your std::cout statement in main.
        d) you should see 2 (almost) identical messages in the program output for each member function you add:
            one for the std::cout line, and one for the member function's output
 
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo() { std::cout << "creating MyFoo" << std::endl; }
        ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
		
		// 2a) the member function whose function body is almost identical to the std::cout statement in main.
        void memberFunc() 
		{ 
            // 2b) explicitly using 'this' inside this member function.
			std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
		}  
		
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
		
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
		
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.memberFunc();
        return 0;
    }
}


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
        std::cout << "you have enough dough ";
    }
    else 
    {
    std::cout << "not enough dough, make more!!";

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

void PastaShop::pastaStatThisFunc()
{
    std::cout << "PastaShop RestockDough(): " << this->restockDough() << std::endl << "and PastaShop pastaPrice is: " << pastaPrice << std::endl;
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

    std::cout << "synth changeAttack(): " << synth.changeAttack(0.f) << std::endl << "and synth Frequency1 is " << synth.frequency1 << std::endl;

    synth.freq1AttackThisFunc();

    // synth.modulateBeatFrequency(400, 500);
    // synth.changeAttack(0.5f);
    // synth.changeRelease(0.7f);
    // synth.setGain(5);

    PastaShop pastaShop;

    std::cout << "pastaShop RestockDough(): " << pastaShop.restockDough() << std::endl << "and pastaShop pastaPrice is: " << pastaShop.pastaPrice << std::endl;

    pastaShop.pastaStatThisFunc();

    // pastaShop.makeCustomPasta(1.3, "parapadelli", true, true, 1.0);
    // pastaShop.makeCustomPasta(3.0, "alphabet pasta", true, false, 2.0);
    // pastaShop.pastaProfitTotal();

    // TeaParty teaParty{15};

    // teaParty.serve(3);
    // teaParty.serve(4);
    // teaParty.drink(2, 6, true);
    // teaParty.serve(5);
    // teaParty.spill();

    // PastaShopNewHire pastaShopNewHire;

    // pastaShopNewHire.sellNoodles(7);
    // pastaShopNewHire.packNoodles(10);
    // pastaShopNewHire.output();

    // TrainRide trainRide{true};

    // trainRide.progressMade(10.0, 30.0, 1);
    // trainRide.wakeUp();
    // trainRide.goToSleep();

    std::cout << "good to go!" << std::endl;
}
