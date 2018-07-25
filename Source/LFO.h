/*
  ==============================================================================

    LFO.h
    Created: 25 Jul 2018 10:39:00am
    Author:  William Chambers

  ==============================================================================
*/
#ifndef LFO_h
#define LFO_h

#include <stdio.h>


class LFO
{
public:
    
    LFO();
    ~LFO();
    
    
    void setLFORate(float rate);
    void setLFOAmount(float amount);
    float calculateLFO();
    void updateAngleDelta(float sampleRate);
    
private:
    
    float LFORate;
    float LFOAmount;
    float angleDelta;
    float currentAngle{0.0};
    float intervalsPerCycle;
};
    
#endif /* LFO_h */
