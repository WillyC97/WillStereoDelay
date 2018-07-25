//
//  DigitalDelayLine.cpp
//  WillStereoDelay
//
//  Created by William Chambers on 11/05/2018.
//
//


#include "DigitalDelayLine.h"
#include <stdio.h>
#include <string.h>


inline float numSamplesFromMSf(const int sr, const float d_ms){
    return sr * d_ms * .001;
}

//----------------------------------------------------------------------
//  Linear Interpolation Function
//  x1  :  weighting 1
//  x2  :  weighting 2
//  y1  :  output y(n) at read index in buffer
//  y2  :  output y(n-1) at read index minus 1 in buffer
//  x   :  fractional value between samples
//----------------------------------------------------------------------
float DigitalDelayLine::linInterp(float x1, float x2, float y1, float y2, float x)
{
   	float denom = x2 - x1;
    if(denom == 0)
        return y1; // should not ever happen
    
    // calculate decimal position of x
    float dx = (x - x1)/(x2 - x1);
    
    // use weighted sum method of interpolating
    float result = dx*y2 + (1-dx)*y1;
    
    return result; 
}

DigitalDelayLine::DigitalDelayLine(const int sr, const float d_ms, const float fb, const float mix){
    //assert(d_ms <= d_ms_max);//check bound on delay time
    
    buffer = NULL;
    readIndex = writeIndex = feedback = wetLevel = 0;
   
    //max delay of 2 seconds
    float d_ms_max = 2000.0f;
    delayInSamples = 0.0f;
    delayInMs = d_ms;
    
    feedback = fb;
    wetLevel = mix;
    
    MAX_DELAY_SAMPLES = ceil(numSamplesFromMSf(sr, d_ms_max));
    MAX_DELAY_MS = MAX_DELAY_SAMPLES * 1000.0f / sr; //make sure float version is set with to integer-rounded buffer size
    
    float delayInSamplesf = numSamplesFromMSf(sr, d_ms);
    delayInSamples = floor(delayInSamplesf);
    fraction = delayInSamplesf - delayInSamples;//storing fractional delay time, will be interpolated
    
    buffer = new float[MAX_DELAY_SAMPLES];
    memset(buffer, 0, MAX_DELAY_SAMPLES*sizeof(float));
    
}

DigitalDelayLine::~DigitalDelayLine(){
    delete[] buffer;
}

void DigitalDelayLine::setSampleRate(float sr)
{
    sampleRate = sr;
}

float DigitalDelayLine::calculateDelay(double mins_in_ms, double bpm)
{
    //BPM = bpm;
    float delayInMsCalc = mins_in_ms / bpm;
    
    if (delayInMsCalc > 2000)
        delayInMsCalc = 2000;
    
    return delayInMsCalc;
    
}

void DigitalDelayLine::setDelayTimeMS(const int sr, const float d_ms){
    
    //function returns the number of samples from a delay in millsecond value
    //  number of samples = sr * d_ms * .001
    float delayInSamplesf = numSamplesFromMSf(sr, d_ms);
    delayInSamples = floor(delayInSamplesf);
    
    //storing fractional delay time, output will be interpolated
    fraction = delayInSamplesf - delayInSamples;
    
    //the read index is determined from the write index minus the number of
    //samples to delay by
    readIndex = writeIndex - (int)delayInSamples;
    if(readIndex < 0)
        readIndex += MAX_DELAY_SAMPLES;
    
}

// ----------- setting values --------------
void DigitalDelayLine::setFeedback(float f)
{
    feedback = f/100;
}

void DigitalDelayLine::setMixlevel(float m)
{
    wetLevel = m/100;
}

void DigitalDelayLine::setDelayTime(float dt)
{
    delayInMs = dt;
    setDelayTimeMS(sampleRate,delayInMs);
}

void DigitalDelayLine::setCrossFeedVal(float crossfeedval)
{
    crossFeedbackLevel = crossfeedval;
}
void DigitalDelayLine::setPostPreMixToggle(int val)
{
    postPreMix = val;
}
void DigitalDelayLine::setBitdepth(int bd)
{
    bitDepth = bd;
}
void DigitalDelayLine::setBitRate(int br)
{
    rateDivide = br;
}
void DigitalDelayLine::setHiPassCutOff(float hp)
{
    HPass1 = hp;
}
void DigitalDelayLine::setLowPassCutOff(float lp)
{
    LPass1 = lp;
}
void DigitalDelayLine::setResLowPassCutOff(float lp)
{
    RLPassCutoff = lp;
}
void DigitalDelayLine::setResLowPassq(float q)
{
    RLPassQ = q;
}
//-------------------------------------------

float DigitalDelayLine::next(float input, float channel, int i)
{
    ///----------------------------------------------------------------- ///
    ///======================= Tremolo ================================= ///
    ///----------------------------------------------------------------- ///
//    calculateTremolo();
    tremolo.updateAngleDelta(sampleRate);
    
    
    
    ///----------------------------------------------------------------- ///
    ///================================================================= ///
    ///----------------------------------------------------------------- ///
    
    float xn = input;
    
    float yn = buffer[readIndex];

    if(readIndex == writeIndex && delayInSamples < 1.00)
    {
        yn = xn;
    }
    
    int readPos_minus1 = readIndex - 1;
    if (readPos_minus1 < 0)
        readPos_minus1 = MAX_DELAY_SAMPLES - 1;
    
    float yn_minus1 = buffer[readPos_minus1];
    
    float interp = linInterp(0, 1, yn, yn_minus1, fraction);

    if(delayInSamples == 0)
        yn = xn;
    else
        yn = interp;
 
    // write the input to the delay
    buffer[writeIndex] = xn + feedback*yn + feedBackIn;
    // create the wet/dry mix and write to the output buffer
    // dry = 1 - wet
    
    
    
    //Filters///////////////////////////////////////////
    LowPassFilter.calcFilterLPF(sampleRate, LPass1);
    HiPassFilter.calcFilterHPF(sampleRate, HPass1);
    ResonantLPF.calcResonantLPF(sampleRate, RLPassCutoff, RLPassQ);
    
    yn = LowPassFilter.processChannelLPF(yn, channel);
    yn = HiPassFilter.processChannelHPF(yn, channel);
    yn = ResonantLPF.processChannelRLPF(yn, channel);
    //Filters///////////////////////////////////////////
    
    
    ///----------------------------------------------------------------- ///
    ///======================= Bitcrusher ============================== ///
    ///----------------------------------------------------------------- ///
    float totalQLevels = powf(2, bitDepth);
    float remainder = fmodf(yn, 1/totalQLevels);
    // Quantize ...
   yn = yn - remainder;
    
    if (rateDivide > 1)
    {
        if (i%rateDivide != 0){
            yn = buffer[readIndex - readIndex%rateDivide];
        }
    }
    
    ///----------------------------------------------------------------- ///
    ///================================================================= ///
    ///----------------------------------------------------------------- ///
    
    
    float tremoloMod = tremolo.calculateLFO();
    
    float outputBuffer = wetLevel*(yn*tremoloMod) + (1.0 - wetLevel)*xn;
    
    switch (postPreMix) {
        case 1:outputBuffer = wetLevel*(yn*tremoloMod) + (1.0 - wetLevel)*(xn*tremoloMod);
            
            break;
        case 2: outputBuffer = wetLevel*(yn*tremoloMod) + (1.0 - wetLevel)*xn;
            
            break;
        default:
            break;
    }
    
    
    
    // incremnent the pointers and wrap if necessary
    writeIndex++;
    if(writeIndex >= MAX_DELAY_SAMPLES)
        writeIndex = 0;
    readIndex++;
    if(readIndex >= MAX_DELAY_SAMPLES)
        readIndex = 0;
    
    return outputBuffer;
}

void DigitalDelayLine::createBuffer()
{
    if(buffer)
        delete [] buffer;
    
    buffer = new float[MAX_DELAY_SAMPLES];

    
    
    //reset
    resetDelay();
    setDelayTimeMS(sampleRate,delayInMs);
    
}

void DigitalDelayLine::resetDelay()
{
    if(buffer)
        memset(buffer, 0, MAX_DELAY_SAMPLES*sizeof(float));
    
    writeIndex = 0;
    readIndex = 0;
}








