/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */



/*
 UDT 1:
 */


/*
 UDT 2:
 */
 

/*
 UDT 3:
 */

/*
 new UDT 4:
 */
 

/*
 new UDT 5:
 */


/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.
 send me a DM to review your pull request when the project is ready for review.
 Wait for my code review.
 */

#include "Synth.h"
#include "PastaShop.h"
#include "PastaShopNewHire.h"
#include "TeaParty.h"
#include "TrainRide.h"
#include "Wrappers.cpp"

int main()
{
    SynthWrapper fmSynth ( new Synth() );
    PastaShopWrapper pastaShop ( new PastaShop() );
    TeaPartyWrapper teaParty ( new TeaParty() );
    PSNHWrapper pastaShopNewHire ( new PastaShopNewHire() );
    TrainRideWrapper trainRide ( new TrainRide(false) );

    std::cout << "synth changeAttack(): " << fmSynth.pointerToSynth->changeAttack(0.f) << std::endl << "and synth Frequency1 is " << fmSynth.pointerToSynth->frequency1 << std::endl;

    fmSynth.pointerToSynth->freq1AttackThisFunc();

    std::cout << "pastaShop RestockDough(): " << pastaShop.pointerToPastaShop->restockDough() << std::endl << "and pastaShop pastaPrice is: " << pastaShop.pointerToPastaShop->pastaPrice << std::endl;

    pastaShop.pointerToPastaShop->pastaStatThisFunc();

    std::cout << "teaParty serve(5): " << teaParty.pointerToTeaParty->serve(5) << std::endl << "and teaParty cupsOfTeaAvailable is: " << teaParty.pointerToTeaParty->cupsOfTeaAvailable << std::endl;

    teaParty.pointerToTeaParty->serveThisFunction();

    std::cout << "pastaShopNewHire output(): " << pastaShopNewHire.pointerToPSNH->output() << std::endl << "and pastaShopNewHire packages made: " << pastaShopNewHire.pointerToPSNH->packages << std::endl;

    pastaShopNewHire.pointerToPSNH->outputThisFunction();

    std::cout << "trainRide progressMade is: " << trainRide.pointerToTrainRide->progressMade(10.0, 35.0, 2) << std::endl << "trainRide trainSpeedPerHour is " << trainRide.pointerToTrainRide->trainSpeedPerHour << std::endl;

    trainRide.pointerToTrainRide->progressMadeThisFunction(10.0, 35.0, 2);
    
    std::cout << "good to go!" << std::endl;
}
