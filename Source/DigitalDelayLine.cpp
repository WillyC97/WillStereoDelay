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
//-------------------------------------------

float DigitalDelayLine::next(float input, float channel)
{
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
    
    yn = processChannelLPF(yn, channel);
    yn = processChannelHPF(yn, channel);
    
    
    float outputBuffer= wetLevel*yn + (1.0 - wetLevel)*xn;
    
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

///----------------------------------------------------------------- ///
///======================= Filter Calculation ====================== ///
///----------------------------------------------------------------- ///

float DigitalDelayLine::processChannelHPF(float input, int channelIdx)
{
    double out = input * a0HP + z1_AHP[channelIdx];
    z1_AHP[channelIdx] = (input * a1HP) + z2_AHP[channelIdx] - (b1HP * out);
    z2_AHP[channelIdx] = (input * a2HP) - (b2HP * out);
    return out;
}

float DigitalDelayLine::processChannelLPF(float input, int channelIdx)
{
    double out = input * a0LP + z1_ALP[channelIdx];
    z1_ALP[channelIdx] = (input * a1LP) + z2_ALP[channelIdx] - (b1LP * out);
    z2_ALP[channelIdx] = (input * a2LP) - (b2LP * out);
    return out;
}

void DigitalDelayLine::calcFilterLPF(float samplerate, int cutoff)
{
    
    //----------------second order LPF ------------
    float theta_c = 2.0*M_PI*cutoff/samplerate;
    float d = 1.0/0.707;
    // intermediate values
    float fBetaNumerator = 1.0 - ((d/2.0)*(sin(theta_c)));
    float fBetaDenominator = 1.0 + ((d/2.0)*(sin(theta_c)));
    //beta
    float fBeta = 0.5*(fBetaNumerator/fBetaDenominator);
    // gamma
    float fGamma = (0.5 + fBeta)*(cos(theta_c));
    // alpha
    float fAlpha = (0.5 + fBeta - fGamma)/2.0;
    //filter coefficients
    a0LP = fAlpha;
    a1LP = 2.0*fAlpha;
    
    a2LP = fAlpha;
    b1LP = -2.0*fGamma;
    b2LP = 2.0*fBeta;
    
}

void DigitalDelayLine::calcFilterHPF(float samplerate, int cutoff)
{
    
    float theta_c = 2.0*M_PI*cutoff/samplerate;
    float d = 1.0/0.707;
    // intermediate values
    float fBetaNumerator = 1.0 - ((d/2.0)*(sin(theta_c)));
    float fBetaDenominator = 1.0 + ((d/2.0)*(sin(theta_c)));
    //beta
    float fBeta = 0.5*(fBetaNumerator/fBetaDenominator);
    // gamma
    float fGamma = (0.5 + fBeta)*(cos(theta_c));
    
    float fAlpha = (0.5 + fBeta + fGamma)/2.0;
    
    a0HP = fAlpha;
    a1HP = -(2.0*fAlpha);
    a2HP = fAlpha;
    b1HP = -2.0*fGamma;
    b2HP = 2.0*fBeta;
    
    
}


