#include "Wrappers.h"
#include "Synth.h"
#include "UIControls.h"
#include "PastaShop.h"
#include "Style.h"
#include "TeaParty.h"
#include "PastaShopNewHire.h"
#include "TrainRide.h"

SynthWrapper::SynthWrapper ( Synth* ptr ) : pointerToSynth ( ptr ) { }
    
SynthWrapper::~SynthWrapper()
{
    delete pointerToSynth;
}

UIControlsWrapper::UIControlsWrapper ( UIControls* ptr ) : pointerToUIControls ( ptr ) { }

UIControlsWrapper::~UIControlsWrapper()
{
    delete pointerToUIControls;
}

PastaShopWrapper::PastaShopWrapper ( PastaShop* ptr) : pointerToPastaShop ( ptr ) { }

PastaShopWrapper::~PastaShopWrapper()
{
    delete pointerToPastaShop;
}

StyleWrapper::StyleWrapper ( Style* ptr ) : pointerToStyle ( ptr ) { }

StyleWrapper::~StyleWrapper()
{
    delete pointerToStyle;
}

TeaPartyWrapper::TeaPartyWrapper ( TeaParty* ptr ) : pointerToTeaParty ( ptr ) { }

TeaPartyWrapper::~TeaPartyWrapper()
{
    delete pointerToTeaParty;
}

PSNHWrapper::PSNHWrapper ( PastaShopNewHire* ptr ) : pointerToPSNH ( ptr ) { }

PSNHWrapper::~PSNHWrapper()
{
    delete pointerToPSNH;
}

TrainRideWrapper::TrainRideWrapper ( TrainRide* ptr ) : pointerToTrainRide ( ptr ) { }

TrainRideWrapper::~TrainRideWrapper()
{
    delete pointerToTrainRide;
}

