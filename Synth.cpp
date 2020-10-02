#include "Synth.h"

float Synth::UIControls::setKnob(float newknobPosition)
{
    knobPosition = newknobPosition;
    std::cout << "new knob position is " << knobPosition << std::endl;

    return knobPosition;
}
bool Synth::UIControls::buttonPress(bool newButtonState)
{
    if(buttonState != newButtonState)
    {
        std::cout << "button engaged" << std::endl;
        buttonState = newButtonState;
        buttonCounter++;
        std::cout << "button counter is " << buttonCounter << std::endl;
    }

    return buttonState;
}
int Synth::UIControls::updateLEDIndicator()
{
    while (ledGainIndicator != static_cast<int>(knobPosition))
    {
        if(ledGainIndicator < static_cast<int>(knobPosition))
        {
            ledGainIndicator++;
            std::cout << "ledGainIndicator blinks and increments" << std::endl;
        }
        else
        {
            ledGainIndicator--;
            std::cout << "ledGainIndicator blinks and decrements" << std::endl;
        }
    }

    std::cout << "ledGainIndicator is " << ledGainIndicator << std::endl;

    return (ledGainIndicator);
}

Synth::Synth() : frequency1(400), frequency2(600), gain(0), attack(0.1f), release(1.0f)
{
    std::cout << "construct Synth" << std::endl;
}

Synth::~Synth()
{
    std::cout << "destruct Synth" << std::endl;
}

int Synth::modulateBeatFrequency( int newFreq1, int newFreq2 )
{
    frequencyOutput = std::abs(newFreq1 - newFreq2);
    std::cout << "frequencyOutput is " << frequencyOutput << std::endl;
    return frequencyOutput;
}
float Synth::changeAttack(float newAttack)
{
    attack = newAttack;
    std::cout << "attack is ";
    return attack;
}
float Synth::changeRelease(float newRelease)
{
    release = newRelease;
    std::cout << "release is ";
    return release;
}

void Synth::setGain(int newLevel)
{
    uiControls.buttonPress(true);
    uiControls.setKnob(newLevel);
    uiControls.updateLEDIndicator();
}      

void Synth::freq1AttackThisFunc()
{
    std::cout << "Synth changeAttack(): " << this->changeAttack(0.f) << std::endl << "and Synth Frequency1 is " << this->frequency1 << std::endl;
}