//
//  Filters.hpp
//  WillStereoDelay
//
//  Created by William Chambers on 24/07/2018.
//

#ifndef Filters_h
#define Filters_h

#include <stdio.h>
class Filters
{
public:
    
    Filters();
    ~Filters();
    
    
    float processChannelLPF(float input, int channelIdx);
    float processChannelHPF(float input, int channelIdx);
    void calcFilterLPF(float samplerate, int cutoff);
    void calcFilterHPF(float samplerate, int cutoff);
    
    
private:
    double a0LP, a1LP, a2LP, b1LP, b2LP;
    double a0HP, a1HP, a2HP, b1HP, b2HP;
    double z1_ALP[2], z2_ALP[2];
    double z1_AHP[2], z2_AHP[2];
    
    
    
    
};
#endif /* Filters_h */

