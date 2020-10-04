#include <iostream>
#include "UIControls.h"

UIControls::UIControls(int newKnob, int newButton) : knob(newKnob), button(newButton)
{
    std::cout << "construct UIControls" << std::endl;
}

UIControls::~UIControls()
{
    std::cout << "destruct UIControls" << std::endl; 
}

float UIControls::setKnob(float newknobPosition)
{
    knobPosition = newknobPosition;
    std::cout << "new knob position is " << knobPosition << std::endl;

    return knobPosition;
}
bool UIControls::buttonPress(bool newButtonState)
{
    if(buttonState != newButtonState)
    {
        std::cout << "button engaged" << std::endl;
        buttonState = newButtonState;
        ++buttonCounter;
        std::cout << "button counter is " << buttonCounter << std::endl;
    }

    return buttonState;
}
int UIControls::updateLEDIndicator()
{
    while (ledGainIndicator != static_cast<int>(knobPosition))
    {
        if(ledGainIndicator < static_cast<int>(knobPosition))
        {
            ++ledGainIndicator;
            std::cout << "ledGainIndicator blinks and increments" << std::endl;
        }
        else
        {
            --ledGainIndicator;
            std::cout << "ledGainIndicator blinks and decrements" << std::endl;
        }
    }

    std::cout << "ledGainIndicator is " << ledGainIndicator << std::endl;

    return (ledGainIndicator);
}
