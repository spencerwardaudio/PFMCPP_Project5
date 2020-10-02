#include <iostream>
#include <string>
#include <cmath>
#include "LeakedObjectDetector.h"

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

        JUCE_LEAK_DETECTOR(UIControls)
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

    JUCE_LEAK_DETECTOR(Synth)
};