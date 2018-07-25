//
//  DigitalDelayLine.h
//  WillStereoDelay
//
//  Created by William Chambers on 11/05/2018.
//
//

#ifndef DigitalDelayLine_h
#define DigitalDelayLine_h

#include <algorithm>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include "Filters.h"
#include "LFO.h"




class DigitalDelayLine{

public:
    
    DigitalDelayLine(const int sr = 44100, const float d_ms = 0.0f, const float feedback = 0.0f, const float wetLevel = 0.5f);
    ~DigitalDelayLine();
    

    
    void setSampleRate(float sr);
    float calculateDelay(double mins_in_ms, double bpm);
    void createBuffer();
    void resetDelay();
    void setDelayTimeMS(const int sr, const float d_ms);

    void setCrossFeedVal(float crossfeedval);
    float getCurrentFeedbackOutput(){return (crossFeedbackLevel/100)*buffer[readIndex];}
    void setCurrentFeedbackInput(float f){feedBackIn = f;}
    
    void setFeedback(float f);
    void setDelayTime(float dt);
    void setMixlevel(float mix);
    void setBitdepth(int bd);
    void setBitRate(int br);
    void setHiPassCutOff(float hp);
    void setLowPassCutOff(float lp);
    void setResLowPassCutOff(float lp);
    void setResLowPassq(float q);
    //void setCrossFeeedbackLevel(float cfb);
    float next(float input, float channel, int i);
    float linInterp(float x1, float x2, float y1, float y2, float x);

    
    
   
    

    float* buffer;
    int readIndex;
    int writeIndex;
    int bufferSize;
    int MAX_DELAY_SAMPLES;
    
    
    
    //Tremolo Stuff
   
    
    void setPostPreMixToggle(int val);
    int postPreMix;
    
    LFO tremolo;
    
private:
    Filters HiPassFilter;
    Filters LowPassFilter;
    Filters ResonantLPF;
    
    float sampleRate;
    float delayInSamples, fraction, delayInMs, MAX_DELAY_MS, wetLevel, feedback, crossFeedbackLevel;
    float feedBackIn;
    int bitDepth;
    int rateDivide;
    float HPass1, LPass1, RLPassCutoff, RLPassQ;
    
    double BPM;
    
    
   
    
};

#endif // DIGITALDELAYLINE_H_INCLUDED
