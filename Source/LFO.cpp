/*
  ==============================================================================

    LFO.cpp
    Created: 25 Jul 2018 10:39:00am
    Author:  William Chambers

  ==============================================================================
*/

#include "LFO.h"
#include <cmath>

LFO::LFO()
{
}

LFO::~LFO()
{
}
    void LFO::setLFORate(float rate)
    {
        LFORate = rate;
    }
    
    void LFO::setLFOAmount(float amount)
    {
        LFOAmount = amount;
    }
    
    void LFO::updateAngleDelta(float sampleRate)
    {
        intervalsPerCycle = LFORate / sampleRate; //sinewave coeffcient generation for standard vibrato shape
        angleDelta = intervalsPerCycle * (2 * M_PI);
    }
    
    float LFO::calculateLFO()
    {
        float offset = 1- LFOAmount;
        float LFOOutput = (offset + LFOAmount *(sin(currentAngle)));
        currentAngle += angleDelta;
        
        if (currentAngle >= (2 *M_PI))
        {
            currentAngle -= (2 *M_PI);
        }
        
        return LFOOutput;
    }

