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
 
// struct Raccoon
// {
//     struct RaccoonState
//     {
//         RaccoonState(float adrenaline_, bool cleanPaws_, double weight_) :
//         adrenaline_(adrenaline),
//         cleanPaws_(cleanPaws),
//         weight_(weight),
//         hungry(true),
//         crazyEyes(false)
//         {
//             cout << "construct RaccoonState" << endl;
//         }

//         ~RaccoonState() 
//         {
//             cout << "destroy RaccoonState" << endl;
//         }

//         void setEyes(bool newCrazyEyes) 
//         {
//             crazyEyes = newCrazyEyes; 
//         }

//         void setAdrenaline(float newAdrenaline)
//         {

//             adrenaline = newAdrenaline;
//         }

//         float adrenaline;
//         bool cleanPaws;
//         double weight;
//         bool hungry;
//         bool crazyEyes;
//     };

//     RaccoonState raccoonState;

//     Raccoon();
//     ~Raccoon();

//     double discover(bool trash);

//     bool rummage();

//     int climbDownChimney();

//     bool miracle {false};
//     bool trash {false};
//     bool food;
//     int shinyThings;
//     bool nightTime;
// };

// Raccoon::Raccoon() :
// food(true),
// shinyThings(5),
// nightTime(true)
// {
//     cout << "construct Raccoon" << endl;
// }

// Raccoon::~Raccoon()
// {
//     cout << "destroy Raccoon" << endl;
// }

// double Raccoon::discover(bool trash)
// {
//     if (trash = true)
//     {
//         cout << "has seen trash" << endl;
//         rummage();
//     }
// }

// bool Raccoon::rummage(bool trash)
// {
//     if(trash)
//         food = false;
// }

// int Raccoon::climbDownChimney()
// {
//     rummage();
// }


/*
 UDT 2:
 */

 struct PastaShop
 {
    struct Shape
    {
        Shape() : 
        whitePasta(false),
        greenPasta(false)
        {
            cout << "constructing Shape" << endl;
        }

        ~Shape()
        {
            cout << "destructing Shape" << endl;
        }

        void pastaColor(bool, bool)
        {
            if (whitePasta && greenPasta)
                cout << "white & green swirl" << endl;
            else if(whitePasta)
                cout << "white pasta" << endl;
            else if(greenPasta)
                cout << "green pasta" << endl;
        }

        string customShape(string s)
        {
            name = s;

            return name;
        }

        enum noodleType {fettucini, linguini, rigatoni} noodle;
        bool whitePasta;
        bool greenPasta;
        string name;


    };

    Shape shape;

    PastaShop();
    ~PastaShop();

    double makeCustomPasta(int typeOfCut, double requestedAmount);
    double restockDough();
    void pastaProfitTotal();

    double amountOfDoughlBS;
    double pastaProfit;
    double pastaPrice {8.0};
    double customRequestTotal {0.0};
    double totalPastaWeight {0.0};

 };

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

double PastaShop::makeCustomPasta(int newTypeOfCut, double newRequestedAmount)
{
    cout << "type of cut requested: " << newTypeOfCut << endl;
    cout << "amount of requested pasta: " << newRequestedAmount << " lBs" << endl;

    shape.pastaColor(true, true);

    shape.customShape("pappardelle");

    cout << shape.name << endl;

    shape.noodle = Shape::fettucini;
    cout << "noodle shape: " << shape.noodle << endl;

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
//  struct TeaParty
//  {
//     TeaParty() 
//     {
//         cout << "construct TeaParty" << endl;
//     }

//     ~TeaParty() 
//     {
//         cout << "destruct PastaShop" << endl;
//     }

//     int numberOfCups;
//     int participants;
//     bool tooMuchTea;
//     bool biscuits;
//     bool rain;

//     void serve();    
//     bool drink();
//     void spill();

//  };

// void TeaParty::serve()
// {

// }   

// bool TeaParty::drink()
// {

// }

// void TeaParty::spill()
// {

// }

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

    int traditionalNoodlesMade;
    int customShapesDesigned;
    int noodlesOnTheFloor {0};
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

// struct TrainRide
// {
//     TrainRide()
//     {
//         cout << "construct TrainRide" << endl;
//     }

//     ~TrainRide()
//     {
//         cout << "destruct TrainRide" << endl;
//     }

//     bool dayTimeTravel;
//     bool rain;
//     int loudness; 
//     double distance;
//     float trainSpeed;

//     double progressMade();
//     bool getExcited();
//     bool goToSleep();
//     //if crazyEyes { too much tea }

//     TeaParty teaParty;
// };

// double TrainRide::progressMade()
// {

// }

// bool TrainRide::getExcited()
// {

// }

// bool TrainRide::goToSleep()
// {
    
// }

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
    PastaShop pastaShop;

    pastaShop.makeCustomPasta(1, 1.0);
    pastaShop.makeCustomPasta(1, 3.0);
    pastaShop.pastaProfitTotal();


    std::cout << "good to go!" << std::endl;
}
