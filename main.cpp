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

using namespace std;
 
struct Raccoon
{
    struct RaccoonState
    {
        RaccoonState(float adrenaline_, bool cleanPaws_, double weight_) :
        adrenaline_(adrenaline),
        cleanPaws_(cleanPaws),
        weight_(weight),
        hungry(true),
        crazyEyes(false)
        {
            cout << "construct RaccoonState" << endl;
        }

        ~RaccoonState() 
        {
            cout << "destroy RaccoonState" << endl;
        }

        void setHungryState();
        void setExcitement();

        float adrenaline;
        bool cleanPaws;
        double weight;
        bool hungry;
        bool crazyEyes;
    };

    RaccoonState raccoonState;

    Raccoon();
    ~Raccoon();

    double discover(bool trash);

    bool rummage();

    int climbDownChimney();

    void eat();

    bool miracle {false};
    bool trash {false};
    bool food;
    int shinyThings;
    bool nightTime;
};

Raccoon::Raccoon() :
food(true),
shinyThings(5),
nightTime(true)
{
    cout << "construct Raccoon" << endl;
}

Raccoon::~Raccoon()
{
    cout << "destroy Raccoon" << endl;
}

double Raccoon::discover(bool trash)
{

}

bool Raccoon::rummage()
{

}

int Raccoon::climbDownChimney()
{

}

void Raccoon::eat()
{

}

/*
 UDT 2:
 */
 struct PastaShop
 {
    struct Shape
    {
        string fettucini;
        string linguini;
        string customShape;
        bool whitePasta;
        bool greenPasta;
    };

    PastaShop() {}
    ~PastaShop() {}

    double amountOfDough;
    double amountOfFlower;
    int typeOfCut;
    bool tomatoSauce;
    double temperature;

    void makePasta();
    double restockDoughRefrigerator();
    void sellGoods();
 };

void PastaShop::makePasta()
{

}

double PastaShop::restockDoughRefrigerator()
{

}

void PastaShop::sellGoods()
{

}

/*
 UDT 3:
 */
 struct TeaParty
 {
    TeaParty() {}
    ~TeaParty() {}

    int numberOfCups;
    int participants;
    bool tooMuchTea;
    bool biscuits;
    bool rain;

    void serve();    
    bool drink();
    void spill();
    bool decideToCancel();

 };

void TeaParty::serve()
{

}   

bool TeaParty::drink()
{

}

void TeaParty::spill()
{

}

bool TeaParty::decideToCancel()
{

}

/*
 new UDT 4:
 */

 struct PastaShopNewHire
 {
    PastaShopNewHire(){}
    ~PastaShopNewHire(){}

    PastaShop pastaShop;
    Raccoon raccoon;

    int traditionalNoodlesMade;
    int customShapesDesigned;
    int noodlesOnTheFloor;
    bool dedicated;
    int moneyMade;

    void sellNoodles();
    int packNoodles();
    int output();

 };

void PastaShopNewHire::sellNoodles()
{

}

int PastaShopNewHire::packNoodles()
{

}

int PastaShopNewHire::output()
{

}

/*
 new UDT 5:
 */

struct TrainRide
{
    TrainRide(){}
    ~TrainRide(){}

    bool dayTimeTravel;
    bool rain;
    int loudness; 
    double distance;
    float trainSpeed;

    double progressMade();
    bool getExcited();
    bool goToSleep();
    //if crazyEyes { too much tea }

    TeaParty teaParty;
};

double TrainRide::progressMade()
{

}

bool TrainRide::getExcited()
{

}

bool TrainRide::goToSleep()
{
    
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
    std::cout << "good to go!" << std::endl;
}
