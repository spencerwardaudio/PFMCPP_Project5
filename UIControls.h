#pragma once
#include "LeakedObjectDetector.h"

struct UIControls
{
    UIControls(int newKnob, int newButton);
    ~UIControls();

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