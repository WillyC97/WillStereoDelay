/*
  ==============================================================================

    RangeSlider.h
    Created: 25 Jun 2018 2:05:44pm
    Author:  william.chambers

  ==============================================================================
*/


#include "../JuceLibraryCode/JuceHeader.h"

class RangeSlider  : public Slider
{
public:
    RangeSlider();
    
    ~RangeSlider();
    
private:
    void mouseDown (const MouseEvent& event) override;
    void mouseDrag (const MouseEvent& event) override;
    void valueChanged() override;

    bool mouseDragBetweenThumbs;
    float xMinAtThumbDown;
    float xMaxAtThumbDown;
};