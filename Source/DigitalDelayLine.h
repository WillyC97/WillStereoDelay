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
    //void setCrossFeeedbackLevel(float cfb);
    float next(float input, float channel, int i);
    float linInterp(float x1, float x2, float y1, float y2, float x);

    float sampleRate;
    float delayInSamples, fraction, delayInMs, MAX_DELAY_MS, wetLevel, feedback, crossFeedbackLevel;
    float feedBackIn;
    int bitDepth;
    int rateDivide;
    
   
    

    float* buffer;
    int readIndex;
    int writeIndex;
    int bufferSize;
    int MAX_DELAY_SAMPLES;
    
    float processChannelLPF(float input, int channelIdx);
    float processChannelHPF(float input, int channelIdx);
    void calcFilterLPF(float samplerate, int cutoff);
    void calcFilterHPF(float samplerate, int cutoff);
    double a0LP, a1LP, a2LP, b1LP, b2LP;
    double a0HP, a1HP, a2HP, b1HP, b2HP;
    double z1_ALP[2], z2_ALP[2];
    double z1_AHP[2], z2_AHP[2];
    
    //Tremolo Stuff
    void updateAngleDelta();
    void calculateTremolo();
    void setTremoloRate(float rate);
    float tremoloRate;
    void setTremoloAmount(float amount);
    float tremoloAmount;
    
    float tremoloMod;
    float angleDelta;
    float currentAngle{0.0};
    float intervalsPerCycle;
    //
    
    void setPostPreMixToggle(int val);
    int postPreMix;
    
private:
    double BPM;
   
    
};

#endif // DIGITALDELAYLINE_H_INCLUDED
