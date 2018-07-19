/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.2.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "GUI/FilmstripToggleButton.h"
#include "GUI/FilmstripSlider.h"
#include "GUI/RangeSlider.h"
#include <string.h>

//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class WillStereoDelayAudioProcessorEditor  : public AudioProcessorEditor,
                                             public Slider::Listener,
                                             public Button::Listener,
                                             public ComboBox::Listener,
public Timer
{
public:
    //==============================================================================
    WillStereoDelayAudioProcessorEditor (WillStereoDelayAudioProcessor& p);
    ~WillStereoDelayAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.


    class OtherLookAndFeel : public LookAndFeel_V4
    {
    public:
        OtherLookAndFeel()
        {
            setColour (Slider::thumbColourId, Colours::red);
        }


        void drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                               const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider) override
        {
            //...
        }


    };

    float setDelayFraction(int comboBoxVal);
    void setComboBoxText(float sliderVal, ComboBox* combobox);
    bool toggleState;
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;

    // Binary resources:
    static const char* multimedia_png;
    static const int multimedia_pngSize;
    static const char* minim_png;
    static const int minim_pngSize;
    static const char* quaver_png;
    static const int quaver_pngSize;
    static const char* kisspngquarternotemusicalnoteeighthnoterestmusicnotes5ad2c34d6918e6_3884611415237619974305_png;
    static const int kisspngquarternotemusicalnoteeighthnoterestmusicnotes5ad2c34d6918e6_3884611415237619974305_pngSize;
    static const char* semiquaver_png;
    static const int semiquaver_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    void timerCallback() override;

    FilmstripToggleButton Bypass;
    FilmstripSlider crossfeedLeft;
    FilmstripSlider crossfeedRight;
    FilmstripSlider leftFdbckSlider;
    FilmstripSlider rightFdbckSlider;
    FilmstripSlider tremoloAmount;
    FilmstripSlider tremoloRate;

    Image image_sslRotary;
    Image image_bypass;
    RangeSlider leftRangeSlider;
    RangeSlider rightRangeSlider;
    int comboboxValLeft;
    int comboboxValRight;

    //void custombuttonClicked (Button* buttonThatWasClicked);



    WillStereoDelayAudioProcessor& processor;

    DigitalDelayLine delayLine;
    bool visible;
    LookAndFeel_V4 otherLookAndFeel;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> leftMixSlider;
    ScopedPointer<Slider> rightMixSlider;
    ScopedPointer<ImageButton> crotchetButton;
    ScopedPointer<ImageButton> minimButton;
    ScopedPointer<ImageButton> quaverButton;
    ScopedPointer<ImageButton> semiquaverButton;
    ScopedPointer<ImageButton> minimButtonRight;
    ScopedPointer<ImageButton> crotchetButtonRight;
    ScopedPointer<ImageButton> quaverButtonRight;
    ScopedPointer<ImageButton> semiquaverButtonRight;
    ScopedPointer<ComboBox> comboBoxLeft;
    ScopedPointer<ComboBox> comboBoxRight;
    ScopedPointer<Label> leftDelayLabel;
    ScopedPointer<Label> rightDelayLabel;
    ScopedPointer<Slider> leftDelayTimeslider;
    ScopedPointer<Slider> rightDelayTimeslider;
    ScopedPointer<ComboBox> leftInputSelector;
    ScopedPointer<ComboBox> rightInputSelector;
    ScopedPointer<TextButton> mainButton;
    ScopedPointer<TextButton> feedbackButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WillStereoDelayAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
