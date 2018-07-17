/*
  ==============================================================================

    RangeSlider.cpp
    Created: 25 Jun 2018 2:05:44pm
    Author:  william.chambers

  ==============================================================================
*/

#include "RangeSlider.h"
RangeSlider::RangeSlider ()
  : mouseDragBetweenThumbs {false}
{
    setSliderStyle (Slider::TwoValueHorizontal);
}

RangeSlider::~RangeSlider ()
{
}

// To enable the section between the two thumbs to be draggable.
void RangeSlider::mouseDown (const MouseEvent& event)
{
    const float currentMouseX = event.getPosition().getX();
    const int thumbRadius = getLookAndFeel().getSliderThumbRadius (*this);
    xMinAtThumbDown = valueToProportionOfLength (getMinValue()) * getWidth();
    xMaxAtThumbDown = valueToProportionOfLength (getMaxValue()) * getWidth();

    if (currentMouseX > xMinAtThumbDown + thumbRadius && currentMouseX < xMaxAtThumbDown - thumbRadius)
    {
        mouseDragBetweenThumbs = true;
    }
    else
    {
        mouseDragBetweenThumbs = false;
        Slider::mouseDown (event);
    }
}

// To enable the section between the two thumbs to be draggable.
void RangeSlider::mouseDrag (const MouseEvent& event)
{
    const float distanceFromStart = event.getDistanceFromDragStartX();
    
    if (mouseDragBetweenThumbs)
    {        
        setMinValue (proportionOfLengthToValue ((xMinAtThumbDown + distanceFromStart) / getWidth()));   
        setMaxValue (proportionOfLengthToValue ((xMaxAtThumbDown + distanceFromStart) / getWidth()));    
    }
    else
    {
        Slider::mouseDrag (event);
    }  
}

// This makes one thumb slide if the other is moved against it.
void RangeSlider::valueChanged()
{   
    if (getMinValue() == getMaxValue())
    {
        const int minimalIntervalBetweenMinAndMax = 0;
        if (getMaxValue() + minimalIntervalBetweenMinAndMax <= getMaximum())
        {
            setMaxValue(getMaxValue() + minimalIntervalBetweenMinAndMax);
        }
        else
        {
            setMinValue(getMinValue() - minimalIntervalBetweenMinAndMax);
        }
    }
}