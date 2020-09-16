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

using namespace std;

struct Synth
{
    struct UIControls
    {
        UIControls(int Knob_, int Button_) : Knob(Knob_), Button(Button_)
        {
            cout << "construct UIControls" << endl;
        }
        ~UIControls()
        {
            cout << "destruct UIControls" << endl; 
        }
        float setKnob(float newknobPosition);
        bool buttonPress(bool newButtonState);
        int updateLEDIndicator();

        int Knob;
        float knobPosition {0.f};
        int Button;
        bool buttonState = false;
        int ledGainIndicator = 0;
        int buttonCounter = 0;
    };

    UIControls uiControls{3, 4};

    Synth();
    ~Synth();

    int modulateBeatFrequency( int newFreq1, int newFreq2 );
    float changeAttack(float newAttack);
    float changeRelease(float newRelease);
    void setGain(int newLevel);

    int frequency1;
    int frequency2;
    int frequencyOutput;
    int gain;
    float attack;
    float release;
};

float Synth::UIControls::setKnob(float newknobPosition)
{
    knobPosition = newknobPosition;
    cout << "new knob position is " << knobPosition << endl;
    return knobPosition;
}
bool Synth::UIControls::buttonPress(bool newButtonState)
{
    if(buttonState != newButtonState)
    {
        cout << "button engaged" << endl;
        buttonState = newButtonState;
        buttonCounter++;
        cout << "button counter is " << buttonCounter << endl;
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
            cout << "ledGainIndicator blinks and increments" << endl;
        }
        else
        {
            ledGainIndicator--;
            cout << "ledGainIndicator blinks and decrements" << endl;
        }
    }

    cout << "ledGainIndicator is " << ledGainIndicator << endl;

    return (ledGainIndicator);
}

Synth::Synth() : frequency1(400), frequency2(600), gain(0), attack(0.1f), release(1.0f)
{
    cout << "construct Synth" << endl;
}
Synth::~Synth()
{
    cout << "destruct Synth" << endl;
}

int Synth::modulateBeatFrequency( int newFreq1, int newFreq2 )
{
    frequencyOutput = std::abs(newFreq1 - newFreq2);
    cout << "frequencyOutput is " << frequencyOutput << endl;
    return frequencyOutput;

}
float Synth::changeAttack(float newAttack)
{
    attack = newAttack;
    cout << "attack is " << attack << endl;
    return attack;
}
float Synth::changeRelease(float newRelease)
{
    release = newRelease;
    cout << "release is " << release << endl;
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
            cout << "constructing Style" << endl;
        }

        ~Style()
        {
            cout << "destructing Style" << endl;
        }

        void pastaColor(bool color1, bool color2);
        string customShape(string s);
        double addFlour(double doughWidth);

        bool whitePasta;
        bool greenPasta;
        string name;
        double flour;
        double thicknessOfDough;
    };

    Style style;

    PastaShop();
    ~PastaShop();

    double makeCustomPasta(double requestedAmount, string nameOfShape, bool color1, bool color2, double doughWidth);
    double restockDough();
    void pastaProfitTotal();

    double amountOfDoughlBS;
    double pastaProfit;
    double pastaPrice {8.0};
    double customRequestTotal {0.0};
    double totalPastaWeight {0.0};

 };

void PastaShop::Style::pastaColor(bool color1, bool color2)
{
    if (color1 && color2)
        cout << "white & green swirl" << endl;
    else if(color1)
        cout << "white pasta" << endl;
    else if(color2)
        cout << "green pasta" << endl;
}

string PastaShop::Style::customShape(string s)
{
    name = s;
    return name;
}

double PastaShop::Style::addFlour(double doughWidth)
{
    if(doughWidth < 2.0 && doughWidth > 1.0)
    {
        cout << "add 1 cup flour" << endl;
        flour = flour + 1.0;
    }
    else if(doughWidth > 2.0)
    {
        cout << "use a half cup less" << endl;
        flour = flour - 0.5;
    }
    return flour;
}

PastaShop::PastaShop() :
amountOfDoughlBS(5.0),
pastaProfit(0.0)
{
    cout << "construct PastaShop" << endl;
}

PastaShop::~PastaShop() 
{
    cout << "destruct PastaShop" << endl;
}

double PastaShop::makeCustomPasta(double newRequestedAmount, string nameOfShape  = "default", bool color1 = true, bool color2 = true, double doughWidth = 1.0)
{
    style.customShape(nameOfShape);
    cout << "pasta shape requested: " << style.name << endl;
    cout << "amount of requested pasta: " << newRequestedAmount << " lBs" << endl;
    style.pastaColor(color1, color2);
    style.addFlour(doughWidth);
    cout << "you need " << style.flour << " cup of flour" << endl;

    for(int i = 0; i <= newRequestedAmount; i++)
    {
        amountOfDoughlBS -= 1.0;
        totalPastaWeight += 1.0;
        cout << "total pasta sliced " << totalPastaWeight << " lBs" << endl;
    }
    restockDough();
    return customRequestTotal += newRequestedAmount;

}

double PastaShop::restockDough()
{
    if (amountOfDoughlBS > 2.0)
    {
        cout << "you have enough dough" << endl;
    }
    else 
    {
    cout << "not enough dough, make more!!" << endl;

    for(int i = 0; i < 3; i++)
    {
        amountOfDoughlBS += 2.0;
        cout << "made 2 Lbs of dough" << endl;
        cout << "you have: " << amountOfDoughlBS << " Lbs of dough total" << endl;
    }
    }
    return amountOfDoughlBS;
}

void PastaShop::pastaProfitTotal()
{
    pastaProfit = customRequestTotal * pastaPrice;
    cout << "profit for the hour is: $ " << pastaProfit << endl;
}


/*
 UDT 3:
 */
 struct TeaParty
 {
    TeaParty(int cupsOfTeaAvailable_) : cupsOfTeaAvailable(cupsOfTeaAvailable_)
    {
        cout << "construct TeaParty" << endl;
    }

    ~TeaParty() 
    {
        cout << "destruct TeaParty" << endl;
    }

    int serve(int cups);    
    bool drink(int individuals, int cups, bool food);
    void spill();

    int totalNumberOfCupsServed = 0;
    int cupsOfTeaAvailable;
    int participants = 3;
    bool tooMuchTea = false;
    bool biscuits = false;
    bool rain = false;
 };

int TeaParty::serve(int cups)
{
    if(!tooMuchTea || (cupsOfTeaAvailable < 3))
    {
    cout << "serve " << cups << " cups of tea"<< endl;
    totalNumberOfCupsServed = totalNumberOfCupsServed + cups;
    cout << "total amount of tea served " << totalNumberOfCupsServed << " cups of tea"<< endl;
    }
    else
        cout << "no more tea" << endl;
    return totalNumberOfCupsServed;
}   

bool TeaParty::drink(int individuals, int cups, bool food)
{
    auto amountPerIndividual = cups / individuals;
    cout << "all of the participants have had " << amountPerIndividual << " cups of tea"<< endl;

    if(amountPerIndividual <= 2)
        cout << "they can have more tea" << endl;
    else
    {
        tooMuchTea = true;
        cout << "too much tea" << endl;
    }
    if (food)
        cout << "they should eat something" << endl;
    return tooMuchTea;
}

void TeaParty::spill()
{
    auto amountSpilled = (totalNumberOfCupsServed / participants);
    for(int i = 0; i < amountSpilled; i++)
    {
        cout << " 1 cup is spilled " << endl;
    }
}

/*
 new UDT 4:
 */
 struct PastaShopNewHire
 {
    PastaShopNewHire()
    {
        cout << "construct PastaShopNewHire" << endl;
    }

    ~PastaShopNewHire()
    {
        cout << "destruct PastaShopNewHire" << endl;
    }

    PastaShop pastaShop;

    void sellNoodles(int soldAmount);
    int packNoodles(int packages_);
    int output();

    int packages;
    int customShapesDesigned;
    int packagingPay;
    int moneyMade;
    double energy {1.0f};
 };

void PastaShopNewHire::sellNoodles(int soldAmount)
{
    for(int i = 0; i < soldAmount; i++)
    {
        pastaShop.makeCustomPasta(1.3, "New Shape", true, true, 1.0);
    }
}

int PastaShopNewHire::packNoodles(int packages_)
{
    packages = packages_;
    packagingPay = static_cast<int>(packages_ * pastaShop.pastaPrice / 3);
    return packagingPay;
}

int PastaShopNewHire::output()
{
    moneyMade = pastaShop.pastaProfit + packagingPay;

    for(int i = static_cast<int>(pastaShop.amountOfDoughlBS); i > 10; i--)
    {
       energy = energy - 0.1;
       cout << "total energy to make pasta left " << energy << endl;
    }
    return moneyMade;
}

/*
 new UDT 5:
 */
struct TrainRide
{
    TrainRide()
    {
        cout << "construct TrainRide" << endl;
    }

    ~TrainRide()
    {
        cout << "destruct TrainRide" << endl;
    }

    bool awake;
    bool rain;
    int timeAsleep; 
    double distanceTravelled = 0.0;
    double trainSpeedPerHour = 30.0;

    double progressMade(double distance_, double trainSpeed_, int time_);
    bool wakeUp();
    bool goToSleep();

    TeaParty teaParty{15};
};

double TrainRide::progressMade(double distance_, double trainSpeed_, int time_)
{
    if((distance_ > 0) && (trainSpeed_ = 0.0))
    {
        goToSleep();
    }

    if(distance_ < (trainSpeed_ * time_))
        cout << "will get to the destination on time " << endl;
    else
       cout << "will not get to the destination on time " << endl; 

    distanceTravelled = distanceTravelled + distance_;
    return distanceTravelled;

}

bool TrainRide::wakeUp()
{
    if(!awake)
    {
        teaParty.drink(1, 1, true);
        cout << "wake up " << endl;
    }
    else if(!awake && rain)
    {
        teaParty.drink(1, 2, true);
        cout << "wake up with 2 cups" << endl;
    }
    else
        cout << "awake" << endl;
    return awake = true;
}

bool TrainRide::goToSleep()
{
    cout << "go to sleep " << endl;
    auto sleepMiles = timeAsleep * trainSpeedPerHour;
    for (int i = 10; i < sleepMiles; i++)
        cout << "slept through 10 miles " << endl;
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

    TrainRide trainRide;

    trainRide.progressMade(10.0, 30.0, 1);
    trainRide.wakeUp();
    trainRide.goToSleep();

    std::cout << "good to go!" << std::endl;
}
