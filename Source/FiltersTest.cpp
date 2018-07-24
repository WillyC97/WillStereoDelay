//
//  Filters.cpp
//  WillStereoDelay
//
//  Created by William Chambers on 24/07/2018.
//

#include "Filters.hpp"
#include <cmath>

float Filters::processChannelHPF(float input, int channelIdx)
{
    double out = input * a0HP + z1_AHP[channelIdx];
    z1_AHP[channelIdx] = (input * a1HP) + z2_AHP[channelIdx] - (b1HP * out);
    z2_AHP[channelIdx] = (input * a2HP) - (b2HP * out);
    return out;
}

float Filters::processChannelLPF(float input, int channelIdx)
{
    double out = input * a0LP + z1_ALP[channelIdx];
    z1_ALP[channelIdx] = (input * a1LP) + z2_ALP[channelIdx] - (b1LP * out);
    z2_ALP[channelIdx] = (input * a2LP) - (b2LP * out);
    return out;
}

void Filters::calcFilterLPF(float samplerate, int cutoff)
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

void Filters::calcFilterHPF(float samplerate, int cutoff)
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
