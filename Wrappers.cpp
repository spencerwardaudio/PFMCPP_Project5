struct SynthWrapper
{
    SynthWrapper ( Synth* ptr ) : pointerToSynth ( ptr ) { }
    ~SynthWrapper()
    {
        delete pointerToSynth;
    }
    Synth* pointerToSynth = nullptr;
};

struct UIControlsWrapper
{
    UIControlsWrapper ( Synth::UIControls* ptr ) : pointerToUIControls ( ptr ) { }
    ~UIControlsWrapper()
    {
        delete pointerToUIControls;
    }
    Synth::UIControls* pointerToUIControls = nullptr;
};

struct PastaShopWrapper
{
    PastaShopWrapper ( PastaShop* ptr) : pointerToPastaShop ( ptr ) { }
    ~PastaShopWrapper()
    {
        delete pointerToPastaShop;
    }
    PastaShop* pointerToPastaShop = nullptr;
};

struct StyleWrapper
{
    StyleWrapper ( PastaShop::Style* ptr ) : pointerToStyle ( ptr ) { }
    ~StyleWrapper()
    {
        delete pointerToStyle;
    }
    PastaShop::Style* pointerToStyle = nullptr;
};

struct TeaPartyWrapper
{
    TeaPartyWrapper ( TeaParty* ptr ) : pointerToTeaParty ( ptr ) { }
    ~TeaPartyWrapper()
    {
        delete pointerToTeaParty;
    }
    TeaParty* pointerToTeaParty = nullptr;
};

struct PSNHWrapper
{
    PSNHWrapper ( PastaShopNewHire* ptr ) : pointerToPSNH ( ptr ) { }
    ~PSNHWrapper()
    {
        delete pointerToPSNH;
    }
    PastaShopNewHire* pointerToPSNH = nullptr;
};

struct TrainRideWrapper
{
    TrainRideWrapper ( TrainRide* ptr ) : pointerToTrainRide ( ptr ) { }
    ~TrainRideWrapper()
    {
        delete pointerToTrainRide;
    }
    TrainRide* pointerToTrainRide = nullptr;
};