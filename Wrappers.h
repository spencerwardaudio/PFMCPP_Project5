#pragma once

struct Synth;
struct UIControls;
struct PastaShop;
struct Style;
struct TeaParty;
struct PastaShopNewHire;
struct TrainRide;

struct SynthWrapper
{
    SynthWrapper ( Synth* ptr );
    ~SynthWrapper();

    Synth* pointerToSynth = nullptr;
};

struct UIControlsWrapper
{
    UIControlsWrapper ( UIControls* ptr );
    ~UIControlsWrapper();

    UIControls* pointerToUIControls = nullptr;
};

struct PastaShopWrapper
{
    PastaShopWrapper ( PastaShop* ptr);
    ~PastaShopWrapper();
    
    PastaShop* pointerToPastaShop = nullptr;
};

struct StyleWrapper
{
    StyleWrapper ( Style* ptr );
    ~StyleWrapper();

    Style* pointerToStyle = nullptr;
};

struct TeaPartyWrapper
{
    TeaPartyWrapper ( TeaParty* ptr );
    ~TeaPartyWrapper();

    TeaParty* pointerToTeaParty = nullptr;
};

struct PSNHWrapper
{
    PSNHWrapper ( PastaShopNewHire* ptr );
    ~PSNHWrapper();

    PastaShopNewHire* pointerToPSNH = nullptr;
};

struct TrainRideWrapper
{
    TrainRideWrapper ( TrainRide* ptr );
    ~TrainRideWrapper();
  
    TrainRide* pointerToTrainRide = nullptr;
};


