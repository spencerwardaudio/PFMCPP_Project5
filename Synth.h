#pragma once
#include "UIControls.h"
#include "LeakedObjectDetector.h"

struct Synth
{
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

    JUCE_LEAK_DETECTOR(Synth)
};