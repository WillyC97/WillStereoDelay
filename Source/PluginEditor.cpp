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

//[Headers] You can add your own extra header files here...
#include "PluginProcessor.h"
#include "DigitalDelayLine.h"
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
WillStereoDelayAudioProcessorEditor::WillStereoDelayAudioProcessorEditor (WillStereoDelayAudioProcessor& p)
    : AudioProcessorEditor (&p), processor(p)
{
    //[Constructor_pre] You can add your own custom stuff here..


    //[/Constructor_pre]

    addAndMakeVisible (leftMixSlider = new Slider ("Left Mix slider"));
    leftMixSlider->setRange (0, 100, 1);
    leftMixSlider->setSliderStyle (Slider::LinearVertical);
    leftMixSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    leftMixSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    leftMixSlider->addListener (this);

    leftMixSlider->setBounds (352, 112, 48, 200);

    addAndMakeVisible (rightMixSlider = new Slider ("Right Mix slider"));
    rightMixSlider->setRange (0, 100, 1);
    rightMixSlider->setSliderStyle (Slider::LinearVertical);
    rightMixSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    rightMixSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    rightMixSlider->addListener (this);

    rightMixSlider->setBounds (424, 112, 54, 200);

    addAndMakeVisible (crotchetButton = new ImageButton ("crotchet button"));
    crotchetButton->setButtonText (TRANS("new button"));
    crotchetButton->addListener (this);

    crotchetButton->setImages (false, true, true,
                               ImageCache::getFromMemory (kisspngquarternotemusicalnoteeighthnoterestmusicnotes5ad2c34d6918e6_3884611415237619974305_png, kisspngquarternotemusicalnoteeighthnoterestmusicnotes5ad2c34d6918e6_3884611415237619974305_pngSize), 1.000f, Colour (0x00000000),
                               ImageCache::getFromMemory (kisspngquarternotemusicalnoteeighthnoterestmusicnotes5ad2c34d6918e6_3884611415237619974305_png, kisspngquarternotemusicalnoteeighthnoterestmusicnotes5ad2c34d6918e6_3884611415237619974305_pngSize), 1.000f, Colour (0xff999999),
                               Image(), 1.000f, Colour (0x00000000));
    crotchetButton->setBounds (136, 48, 32, 32);

    addAndMakeVisible (minimButton = new ImageButton ("minim button"));
    minimButton->setButtonText (TRANS("new button"));
    minimButton->addListener (this);

    minimButton->setImages (false, true, true,
                            ImageCache::getFromMemory (minim_png, minim_pngSize), 1.000f, Colour (0x00e90b0b),
                            ImageCache::getFromMemory (minim_png, minim_pngSize), 1.000f, Colour (0xff999999),
                            Image(), 1.000f, Colour (0x00000000));
    minimButton->setBounds (160, 88, 32, 32);

    addAndMakeVisible (quaverButton = new ImageButton ("quaver button"));
    quaverButton->setButtonText (TRANS("new button"));
    quaverButton->addListener (this);

    quaverButton->setImages (false, true, true,
                             ImageCache::getFromMemory (quaver_png, quaver_pngSize), 0.999f, Colour (0x00000000),
                             ImageCache::getFromMemory (quaver_png, quaver_pngSize), 1.000f, Colour (0xff999999),
                             Image(), 1.000f, Colour (0x00000000));
    quaverButton->setBounds (72, 48, 32, 32);

    addAndMakeVisible (semiquaverButton = new ImageButton ("semi quaver button"));
    semiquaverButton->setButtonText (TRANS("new button"));
    semiquaverButton->addListener (this);

    semiquaverButton->setImages (false, true, true,
                                 ImageCache::getFromMemory (semiquaver_png, semiquaver_pngSize), 1.000f, Colour (0x00000000),
                                 ImageCache::getFromMemory (semiquaver_png, semiquaver_pngSize), 1.000f, Colour (0xff999999),
                                 Image(), 1.000f, Colour (0x00000000));
    semiquaverButton->setBounds (48, 88, 40, 40);

    addAndMakeVisible (minimButtonRight = new ImageButton ("minim button"));
    minimButtonRight->setButtonText (TRANS("new button"));
    minimButtonRight->addListener (this);

    minimButtonRight->setImages (false, true, true,
                                 ImageCache::getFromMemory (minim_png, minim_pngSize), 1.000f, Colour (0x00999999),
                                 ImageCache::getFromMemory (minim_png, minim_pngSize), 1.000f, Colour (0xff999999),
                                 Image(), 1.000f, Colour (0x00000000));
    minimButtonRight->setBounds (640, 104, 32, 32);

    addAndMakeVisible (crotchetButtonRight = new ImageButton ("crotchet button"));
    crotchetButtonRight->setButtonText (TRANS("new button"));
    crotchetButtonRight->addListener (this);

    crotchetButtonRight->setImages (false, true, true,
                                    ImageCache::getFromMemory (kisspngquarternotemusicalnoteeighthnoterestmusicnotes5ad2c34d6918e6_3884611415237619974305_png, kisspngquarternotemusicalnoteeighthnoterestmusicnotes5ad2c34d6918e6_3884611415237619974305_pngSize), 1.000f, Colour (0x00000000),
                                    ImageCache::getFromMemory (kisspngquarternotemusicalnoteeighthnoterestmusicnotes5ad2c34d6918e6_3884611415237619974305_png, kisspngquarternotemusicalnoteeighthnoterestmusicnotes5ad2c34d6918e6_3884611415237619974305_pngSize), 1.000f, Colour (0xff999999),
                                    Image(), 1.000f, Colour (0x00000000));
    crotchetButtonRight->setBounds (624, 56, 32, 32);

    addAndMakeVisible (quaverButtonRight = new ImageButton ("quaver button"));
    quaverButtonRight->setButtonText (TRANS("new button"));
    quaverButtonRight->addListener (this);

    quaverButtonRight->setImages (false, true, true,
                                  ImageCache::getFromMemory (quaver_png, quaver_pngSize), 0.999f, Colour (0x00000000),
                                  ImageCache::getFromMemory (quaver_png, quaver_pngSize), 1.000f, Colour (0xff999999),
                                  Image(), 1.000f, Colour (0x00000000));
    quaverButtonRight->setBounds (552, 56, 32, 32);

    addAndMakeVisible (semiquaverButtonRight = new ImageButton ("semi quaver button"));
    semiquaverButtonRight->setButtonText (TRANS("new button"));
    semiquaverButtonRight->addListener (this);

    semiquaverButtonRight->setImages (false, true, true,
                                      ImageCache::getFromMemory (semiquaver_png, semiquaver_pngSize), 1.000f, Colour (0x00000000),
                                      ImageCache::getFromMemory (semiquaver_png, semiquaver_pngSize), 1.000f, Colour (0xff999999),
                                      Image(), 1.000f, Colour (0x00000000));
    semiquaverButtonRight->setBounds (536, 104, 40, 40);

    addAndMakeVisible (comboBoxLeft = new ComboBox ("Left combo box"));
    comboBoxLeft->setEditableText (false);
    comboBoxLeft->setJustificationType (Justification::centredLeft);
    comboBoxLeft->setTextWhenNothingSelected (String());
    comboBoxLeft->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBoxLeft->addItem (TRANS("1/16 triplet"), 1);
    comboBoxLeft->addItem (TRANS("1/32 dotted"), 2);
    comboBoxLeft->addItem (TRANS("1/16"), 3);
    comboBoxLeft->addItem (TRANS("1/8 triplet"), 4);
    comboBoxLeft->addItem (TRANS("1/16 dotted"), 5);
    comboBoxLeft->addItem (TRANS("1/8"), 6);
    comboBoxLeft->addItem (TRANS("1/4 triplet"), 7);
    comboBoxLeft->addItem (TRANS("1/8 dotted"), 8);
    comboBoxLeft->addItem (TRANS("1/4"), 9);
    comboBoxLeft->addItem (TRANS("1/2 triplet"), 10);
    comboBoxLeft->addItem (TRANS("1/4 dotted"), 11);
    comboBoxLeft->addItem (TRANS("1/2"), 12);
    comboBoxLeft->addItem (TRANS("1/1 triplet"), 13);
    comboBoxLeft->addItem (TRANS("1/2 dotted"), 14);
    comboBoxLeft->addListener (this);

    comboBoxLeft->setBounds (216, 64, 104, 24);

    addAndMakeVisible (comboBoxRight = new ComboBox ("Right combo box"));
    comboBoxRight->setEditableText (false);
    comboBoxRight->setJustificationType (Justification::centredLeft);
    comboBoxRight->setTextWhenNothingSelected (String());
    comboBoxRight->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBoxRight->addItem (TRANS("1/16 triplet"), 1);
    comboBoxRight->addItem (TRANS("1/32 dotted"), 2);
    comboBoxRight->addItem (TRANS("1/16"), 3);
    comboBoxRight->addItem (TRANS("1/8 triplet"), 4);
    comboBoxRight->addItem (TRANS("1/16 dotted"), 5);
    comboBoxRight->addItem (TRANS("1/8"), 6);
    comboBoxRight->addItem (TRANS("1/4 triplet"), 7);
    comboBoxRight->addItem (TRANS("1/8 dotted"), 8);
    comboBoxRight->addItem (TRANS("1/4"), 9);
    comboBoxRight->addItem (TRANS("1/2 triplet"), 10);
    comboBoxRight->addItem (TRANS("1/4 dotted"), 11);
    comboBoxRight->addItem (TRANS("1/2"), 12);
    comboBoxRight->addItem (TRANS("1/1 triplet"), 13);
    comboBoxRight->addItem (TRANS("1/2 dotted"), 14);
    comboBoxRight->addListener (this);

    comboBoxRight->setBounds (680, 64, 104, 24);

    addAndMakeVisible (leftDelayLabel = new Label ("Left label",
                                                   String()));
    leftDelayLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    leftDelayLabel->setJustificationType (Justification::centred);
    leftDelayLabel->setEditable (false, false, false);
    leftDelayLabel->setColour (TextEditor::textColourId, Colours::black);
    leftDelayLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    leftDelayLabel->setBounds (88, 160, 56, 24);

    addAndMakeVisible (rightDelayLabel = new Label ("Left label",
                                                    String()));
    rightDelayLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    rightDelayLabel->setJustificationType (Justification::centred);
    rightDelayLabel->setEditable (false, false, false);
    rightDelayLabel->setColour (TextEditor::textColourId, Colours::black);
    rightDelayLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    rightDelayLabel->setBounds (576, 176, 56, 24);

    addAndMakeVisible (leftDelayTimeslider = new Slider ("LeftDelayTimeslider"));
    leftDelayTimeslider->setRange (0, 200000, 1);
    leftDelayTimeslider->setSliderStyle (Slider::RotaryVerticalDrag);
    leftDelayTimeslider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    leftDelayTimeslider->setColour (Slider::backgroundColourId, Colour (0xff449c3a));
    leftDelayTimeslider->setColour (Slider::thumbColourId, Colour (0x37c84242));
    leftDelayTimeslider->setColour (Slider::trackColourId, Colour (0xff181f22));
    leftDelayTimeslider->setColour (Slider::rotarySliderFillColourId, Colour (0xff181f22));
    leftDelayTimeslider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff263238));
    leftDelayTimeslider->addListener (this);

    leftDelayTimeslider->setBounds (72, 72, 88, 88);

    addAndMakeVisible (rightDelayTimeslider = new Slider ("RightDelayTimeslider"));
    rightDelayTimeslider->setRange (0, 200000, 1);
    rightDelayTimeslider->setSliderStyle (Slider::RotaryVerticalDrag);
    rightDelayTimeslider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    rightDelayTimeslider->setColour (Slider::backgroundColourId, Colour (0xff449c3a));
    rightDelayTimeslider->setColour (Slider::thumbColourId, Colour (0x37c84242));
    rightDelayTimeslider->setColour (Slider::trackColourId, Colour (0xff181f22));
    rightDelayTimeslider->setColour (Slider::rotarySliderFillColourId, Colour (0xff181f22));
    rightDelayTimeslider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff263238));
    rightDelayTimeslider->addListener (this);

    rightDelayTimeslider->setBounds (560, 80, 88, 88);

    addAndMakeVisible (leftInputSelector = new ComboBox ("left input selector"));
    leftInputSelector->setEditableText (false);
    leftInputSelector->setJustificationType (Justification::centredLeft);
    leftInputSelector->setTextWhenNothingSelected (TRANS("Left"));
    leftInputSelector->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    leftInputSelector->addItem (TRANS("Left"), 1);
    leftInputSelector->addItem (TRANS("Right"), 2);
    leftInputSelector->addItem (TRANS("L+R"), 3);
    leftInputSelector->addItem (TRANS("None"), 4);
    leftInputSelector->addListener (this);

    leftInputSelector->setBounds (8, 8, 72, 24);

    addAndMakeVisible (rightInputSelector = new ComboBox ("right input selector"));
    rightInputSelector->setEditableText (false);
    rightInputSelector->setJustificationType (Justification::centredLeft);
    rightInputSelector->setTextWhenNothingSelected (TRANS("Right"));
    rightInputSelector->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    rightInputSelector->addItem (TRANS("Right"), 1);
    rightInputSelector->addItem (TRANS("Left"), 2);
    rightInputSelector->addItem (TRANS("R+L"), 3);
    rightInputSelector->addItem (TRANS("None"), 4);
    rightInputSelector->addListener (this);

    rightInputSelector->setBounds (720, 8, 68, 24);

    addAndMakeVisible (mainButton = new TextButton ("main button"));
    mainButton->setButtonText (TRANS("Main"));
    mainButton->setRadioGroupId (1001);
    mainButton->addListener (this);

    mainButton->setBounds (832, 328, 66, 24);

    addAndMakeVisible (feedbackButton = new TextButton ("feedback button"));
    feedbackButton->setButtonText (TRANS("feedback"));
    feedbackButton->setRadioGroupId (1001);
    feedbackButton->addListener (this);

    feedbackButton->setBounds (904, 328, 66, 24);

    addAndMakeVisible (deviationLabelLeft = new Label ("deviation label left",
                                                       String()));
    deviationLabelLeft->setFont (Font (16.00f, Font::plain).withTypefaceStyle ("Regular"));
    deviationLabelLeft->setJustificationType (Justification::centredLeft);
    deviationLabelLeft->setEditable (false, false, false);
    deviationLabelLeft->setColour (TextEditor::textColourId, Colours::black);
    deviationLabelLeft->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    deviationLabelLeft->setBounds (216, 96, 104, 24);

    addAndMakeVisible (deviationLabelRight = new Label ("deviation label right",
                                                        String()));
    deviationLabelRight->setFont (Font (16.00f, Font::plain).withTypefaceStyle ("Regular"));
    deviationLabelRight->setJustificationType (Justification::centredLeft);
    deviationLabelRight->setEditable (false, false, false);
    deviationLabelRight->setColour (TextEditor::textColourId, Colours::black);
    deviationLabelRight->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    deviationLabelRight->setBounds (680, 96, 104, 24);

    addAndMakeVisible (effectCombobox = new ComboBox ("effect combo box"));
    effectCombobox->setEditableText (false);
    effectCombobox->setJustificationType (Justification::centredLeft);
    effectCombobox->setTextWhenNothingSelected (TRANS("Effects"));
    effectCombobox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    effectCombobox->addItem (TRANS("Tremolo"), 1);
    effectCombobox->addItem (TRANS("Bitcrusher"), 2);
    effectCombobox->addItem (TRANS("Resonant LPF"), 3);
    effectCombobox->addListener (this);

    effectCombobox->setBounds (840, 8, 128, 24);


    //[UserPreSize]

    //[/UserPreSize]

    setSize (1020, 450);


    //[Constructor] You can add your own custom stuff here..
    mainButton->setClickingTogglesState (true);
    feedbackButton->setClickingTogglesState(true);

    startTimer (30);

    Image image_sslRotary = ImageCache::getFromMemory(BinaryData::sslknob_png, BinaryData::sslknob_pngSize);

    leftFdbckSlider.setImage(image_sslRotary, image_sslRotary.getHeight() / image_sslRotary.getWidth(), false);
    leftFdbckSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    leftFdbckSlider.setRange(0, 100, 1);
    leftFdbckSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
    leftFdbckSlider.setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    addAndMakeVisible(&leftFdbckSlider);
    leftFdbckSlider.addListener(this);

    rightFdbckSlider.setImage(image_sslRotary, image_sslRotary.getHeight() / image_sslRotary.getWidth(), false);
    rightFdbckSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    rightFdbckSlider.setRange(0, 100, 1);
    rightFdbckSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
    rightFdbckSlider.setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    addAndMakeVisible(&rightFdbckSlider);
    rightFdbckSlider.addListener(this);

    crossfeedLeft.setImage(image_sslRotary, image_sslRotary.getHeight() / image_sslRotary.getWidth(), false);
    crossfeedLeft.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    crossfeedLeft.setRange(0, 100, 1);
    crossfeedLeft.setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
    crossfeedLeft.setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    addAndMakeVisible(&crossfeedLeft);
    crossfeedLeft.addListener(this);

    crossfeedRight.setImage(image_sslRotary, image_sslRotary.getHeight() / image_sslRotary.getWidth(), false);
    crossfeedRight.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    crossfeedRight.setRange(0, 100, 1);
    crossfeedRight.setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
    crossfeedRight.setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    addAndMakeVisible(&crossfeedRight);
    crossfeedRight.addListener(this);

    tremoloRate.setImage(image_sslRotary, image_sslRotary.getHeight() / image_sslRotary.getWidth(), false);
    tremoloRate.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    tremoloRate.setRange(0, 20, 0.1);
    tremoloRate.setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
    tremoloRate.setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    tremoloRate.setSkewFactorFromMidPoint(3.0);
    addAndMakeVisible(&tremoloRate);
    tremoloRate.addListener(this);
    tremoloRate.setVisible(false);

    tremoloAmount.setImage(image_sslRotary, image_sslRotary.getHeight() / image_sslRotary.getWidth(), false);
    tremoloAmount.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    tremoloAmount.setRange(0, 0.5, 0.05);
    tremoloAmount.setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
    tremoloAmount.setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    addAndMakeVisible(&tremoloAmount);
    tremoloAmount.addListener(this);
    tremoloAmount.setVisible(false);

    bitRateSlider.setImage(image_sslRotary, image_sslRotary.getHeight() / image_sslRotary.getWidth(), false);
    bitRateSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    bitRateSlider.setRange(1, 50, 1);
    bitRateSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
    bitRateSlider.setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    addAndMakeVisible(&bitRateSlider);
    bitRateSlider.addListener(this);
    bitRateSlider.setVisible(false);

    bitDepthSlider.setImage(image_sslRotary, image_sslRotary.getHeight() / image_sslRotary.getWidth(), false);
    bitDepthSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    bitDepthSlider.setRange(4, 24, 1);
    bitDepthSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
    bitDepthSlider.setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    addAndMakeVisible(&bitDepthSlider);
    bitDepthSlider.addListener(this);
    bitDepthSlider.setVisible(false);
    
    resLPFcutOffSlider.setImage(image_sslRotary, image_sslRotary.getHeight() / image_sslRotary.getWidth(), false);
    resLPFcutOffSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    resLPFcutOffSlider.setRange(20, 20000, 1);
    resLPFcutOffSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
    resLPFcutOffSlider.setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    addAndMakeVisible(&resLPFcutOffSlider);
    resLPFcutOffSlider.addListener(this);
    resLPFcutOffSlider.setVisible(false);
    
    resLPFqSlider.setImage(image_sslRotary, image_sslRotary.getHeight() / image_sslRotary.getWidth(), false);
    resLPFqSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    resLPFqSlider.setRange(0.5, 20, 0);
    resLPFqSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
    resLPFqSlider.setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    addAndMakeVisible(&resLPFqSlider);
    resLPFqSlider.addListener(this);
    resLPFqSlider.setVisible(false);

//time sync button
        Image image_bypass = ImageCache::getFromMemory(BinaryData::switch_toggle_sub_png, BinaryData::SimpleEqualizer_bypass_pngSize);
        Bypass.setImage(image_bypass, image_bypass.getWidth() / image_bypass.getHeight());
        addAndMakeVisible(&Bypass);
        Bypass.addListener(this);


    //left range slider
        addAndMakeVisible(&leftRangeSlider);
        leftRangeSlider.addListener(this);

    //right slider slider
        addAndMakeVisible(&rightRangeSlider);
        rightRangeSlider.addListener(this);

    leftDelayTimeslider->setSkewFactorFromMidPoint(40000);
    rightDelayTimeslider->setSkewFactorFromMidPoint(40000);

    tremAmountLabel.setFont (Font (16.00f, Font::plain).withTypefaceStyle ("Regular"));
    tremAmountLabel.setText(("Amount"), sendNotification);
    tremAmountLabel.setJustificationType (Justification::centredLeft);
    tremAmountLabel.setEditable (false, false, false);
    tremAmountLabel.setColour (TextEditor::textColourId, Colours::black);
    tremAmountLabel.setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    addAndMakeVisible(tremAmountLabel);
    tremAmountLabel.setBounds(860, 64, 64, 64);
    tremAmountLabel.setVisible(false);

    tremRateLabel.setFont (Font (16.00f, Font::plain).withTypefaceStyle ("Regular"));
    tremRateLabel.setText(("Rate (Hz)"), sendNotification);
    tremRateLabel.setJustificationType (Justification::centredLeft);
    tremRateLabel.setEditable (false, false, false);
    tremRateLabel.setColour (TextEditor::textColourId, Colours::black);
    tremRateLabel.setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    addAndMakeVisible(tremRateLabel);
    tremRateLabel.setBounds(860, 160, 64, 64);
    tremRateLabel.setVisible(false);

    bitDepthLabel.setFont (Font (16.00f, Font::plain).withTypefaceStyle ("Regular"));
    bitDepthLabel.setText(("Downsampling"), sendNotification);
    bitDepthLabel.setJustificationType (Justification::centredLeft);
    bitDepthLabel.setEditable (false, false, false);
    bitDepthLabel.setColour (TextEditor::textColourId, Colours::black);
    bitDepthLabel.setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    addAndMakeVisible(bitDepthLabel);
    bitDepthLabel.setBounds(860, 64, 96, 64);
    bitDepthLabel.setVisible(false);

    bitRateLabel.setFont (Font (16.00f, Font::plain).withTypefaceStyle ("Regular"));
    bitRateLabel.setText(("Resolution"), sendNotification);
    bitRateLabel.setJustificationType (Justification::centredLeft);
    bitRateLabel.setEditable (false, false, false);
    bitRateLabel.setColour (TextEditor::textColourId, Colours::black);
    bitRateLabel.setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    addAndMakeVisible(bitRateLabel);
    bitRateLabel.setBounds(860, 160, 64, 64);
    bitRateLabel.setVisible(false);

    //[/Constructor]
}

WillStereoDelayAudioProcessorEditor::~WillStereoDelayAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    leftMixSlider = nullptr;
    rightMixSlider = nullptr;
    crotchetButton = nullptr;
    minimButton = nullptr;
    quaverButton = nullptr;
    semiquaverButton = nullptr;
    minimButtonRight = nullptr;
    crotchetButtonRight = nullptr;
    quaverButtonRight = nullptr;
    semiquaverButtonRight = nullptr;
    comboBoxLeft = nullptr;
    comboBoxRight = nullptr;
    leftDelayLabel = nullptr;
    rightDelayLabel = nullptr;
    leftDelayTimeslider = nullptr;
    rightDelayTimeslider = nullptr;
    leftInputSelector = nullptr;
    rightInputSelector = nullptr;
    mainButton = nullptr;
    feedbackButton = nullptr;
    deviationLabelLeft = nullptr;
    deviationLabelRight = nullptr;
    effectCombobox = nullptr;


    //[Destructor]. You can add your own custom destruction code here..

    //[/Destructor]
}

//==============================================================================
void WillStereoDelayAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void WillStereoDelayAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..

        //time sync button
    Bypass.setBounds(328, 24, 64, 64);

        //crossfeed button
    crossfeedLeft.setBounds (224, 328, 64, 64);
    crossfeedRight.setBounds (650, 328, 64, 64);

        //feedback rotaries
    leftFdbckSlider.setBounds(48, 328, 64, 64);
    rightFdbckSlider.setBounds(550, 328, 64, 64);

        //tremolo rotaries
    tremoloAmount.setBounds(800, 64, 64, 64);
    tremoloRate.setBounds(800, 160, 64, 64);

    bitRateSlider.setBounds(800, 64, 64, 64);
    bitDepthSlider.setBounds(800, 160, 64, 64);
    
    resLPFcutOffSlider.setBounds(800, 64, 64, 64);
    resLPFqSlider.setBounds(800, 160, 64, 64);


        //Left hi-low pass Slider
    leftRangeSlider.setBounds(68, 220, 180, 40);
	leftRangeSlider.setTextBoxStyle(RangeSlider::NoTextBox, false, 80, 20);
    leftRangeSlider.setRange(20, 20000);
    leftRangeSlider.setSkewFactorFromMidPoint(1000);

        //right hi-low pass slider
    rightRangeSlider.setBounds(500, 220, 180, 40);
    rightRangeSlider.setTextBoxStyle(RangeSlider::NoTextBox, false, 80, 20);
    rightRangeSlider.setRange(20, 20000);
    rightRangeSlider.setSkewFactorFromMidPoint(1000);


    //[/UserResized]
}

void WillStereoDelayAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == leftMixSlider)
    {
        //[UserSliderCode_leftMixSlider] -- add your slider handling code here..
        *processor.leftMix_param = sliderThatWasMoved->getValue();
        //[/UserSliderCode_leftMixSlider]
    }
    else if (sliderThatWasMoved == rightMixSlider)
    {
        //[UserSliderCode_rightMixSlider] -- add your slider handling code here..
        *processor.rightMix_param = sliderThatWasMoved->getValue();
        //[/UserSliderCode_rightMixSlider]
    }
    else if (sliderThatWasMoved == leftDelayTimeslider)
    {
        //[UserSliderCode_leftDelayTimeslider] -- add your slider handling code here..
        *processor.leftDelayTime_param = sliderThatWasMoved->getValue();
        deviationValueLeft = setComboBoxText(sliderThatWasMoved->getValue(), comboBoxLeft);

        //[/UserSliderCode_leftDelayTimeslider]
    }
    else if (sliderThatWasMoved == rightDelayTimeslider)
    {
        //[UserSliderCode_rightDelayTimeslider] -- add your slider handling code here..
         *processor.rightDelayTime_param = sliderThatWasMoved->getValue();
        deviationValueRight = setComboBoxText(sliderThatWasMoved->getValue(), comboBoxRight);


        //[/UserSliderCode_rightDelayTimeslider]
    }

    //[UsersliderValueChanged_Post]
    else if (sliderThatWasMoved == &leftFdbckSlider)
    {
        //[UserSliderCode_leftFdbckSlider] -- add your slider handling code here..
        *processor.leftFeedback_param = sliderThatWasMoved->getValue();

        //[/UserSliderCode_leftFdbckSlider]
    }
    else if (sliderThatWasMoved == &rightFdbckSlider)
    {
        //[UserSliderCode_rightFdbckSlider] -- add your slider handling code here..
        *processor.rightFeedback_param = sliderThatWasMoved->getValue();
        //[/UserSliderCode_rightFdbckSlider]
    }
    else if (sliderThatWasMoved == &crossfeedLeft)
    {
        //[UserSliderCode_rightFdbckSlider] -- add your slider handling code here..
        *processor.leftCrossLevel_param = sliderThatWasMoved->getValue();
        //[/UserSliderCode_rightFdbckSlider]
    }
    else if (sliderThatWasMoved == &crossfeedRight)
    {
        //[UserSliderCode_rightFdbckSlider] -- add your slider handling code here..
        *processor.rightCrossLevel_param = sliderThatWasMoved->getValue();
        //[/UserSliderCode_rightFdbckSlider]
    }
    else if (sliderThatWasMoved == &tremoloAmount)
    {
        //[UserSliderCode_rightFdbckSlider] -- add your slider handling code here..
        *processor.tremoloAmount_param = sliderThatWasMoved->getValue();
        //[/UserSliderCode_rightFdbckSlider]
    }
    else if (sliderThatWasMoved == &tremoloRate)
    {
        //[UserSliderCode_rightFdbckSlider] -- add your slider handling code here..
        *processor.tremoloRate_param = sliderThatWasMoved->getValue();
        //[/UserSliderCode_rightFdbckSlider]
    }
    else if (sliderThatWasMoved == &bitDepthSlider)
    {
        //[UserSliderCode_rightFdbckSlider] -- add your slider handling code here..
        *processor.bitDepth_param = sliderThatWasMoved->getValue();
        //[/UserSliderCode_rightFdbckSlider]
    }
    else if (sliderThatWasMoved == &bitRateSlider)
    {
        //[UserSliderCode_rightFdbckSlider] -- add your slider handling code here..
        *processor.bitRate_param = sliderThatWasMoved->getValue();

        //[/UserSliderCode_rightFdbckSlider]
    }
    else if (sliderThatWasMoved == &resLPFcutOffSlider)
    {
        //[UserSliderCode_rightFdbckSlider] -- add your slider handling code here..
        *processor.RLPFcutoff_param = sliderThatWasMoved->getValue();
        
        //[/UserSliderCode_rightFdbckSlider]
    }
    else if (sliderThatWasMoved == &resLPFqSlider)
    {
        //[UserSliderCode_rightFdbckSlider] -- add your slider handling code here..
        *processor.RLPFq_param = sliderThatWasMoved->getValue();
        
        //[/UserSliderCode_rightFdbckSlider]
    }
    else if (sliderThatWasMoved == &leftRangeSlider)
    {
        *processor.leftLPF_param = sliderThatWasMoved->getMaxValue();
        *processor.leftHPF_param = sliderThatWasMoved->getMinValue();

    }
    else if (sliderThatWasMoved == &rightRangeSlider)
    {
        *processor.rightLPF_param = sliderThatWasMoved->getMaxValue();
        *processor.rightHPF_param = sliderThatWasMoved->getMinValue();

    }
    //[/UsersliderValueChanged_Post]
}

void WillStereoDelayAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == crotchetButton)
    {
        //[UserButtonCode_crotchetButton] -- add your button handler code here..
//        *processor.leftDelayTime_param = 60000;
        comboBoxLeft->setSelectedId(9);
        //processor.leftDelayTime_param = processor.noteValDelayL;
        //[/UserButtonCode_crotchetButton]
    }
    else if (buttonThatWasClicked == minimButton)
    {
        //[UserButtonCode_minimButton] -- add your button handler code here..
//        *processor.leftDelayTime_param = 120000;

        comboBoxLeft->setSelectedId(12);
//        leftDelayTimeslider->setValue(processor.noteValDelayL);

        //[/UserButtonCode_minimButton]
    }
    else if (buttonThatWasClicked == quaverButton)
    {
        //[UserButtonCode_quaverButton] -- add your button handler code here..
//        *processor.leftDelayTime_param = 30000;
        comboBoxLeft->setSelectedId(6);

//        leftDelayTimeslider->setValue(processor.noteValDelayL);

        //[/UserButtonCode_quaverButton]
    }
    else if (buttonThatWasClicked == semiquaverButton)
    {
        //[UserButtonCode_semiquaverButton] -- add your button handler code here..
//        *processor.leftDelayTime_param = 15000;
        comboBoxLeft->setSelectedId(3);
//
        //[/UserButtonCode_semiquaverButton]
    }
    else if (buttonThatWasClicked == minimButtonRight)
    {
        //[UserButtonCode_minimButtonRight] -- add your button handler code here..
       *processor.rightDelayTime_param = 120000;
        comboBoxRight->setSelectedId(12);
        //[/UserButtonCode_minimButtonRight]
    }
    else if (buttonThatWasClicked == crotchetButtonRight)
    {
        //[UserButtonCode_crotchetButtonRight] -- add your button handler code here..
        *processor.rightDelayTime_param = 60000;
        comboBoxRight->setSelectedId(9);
        //[/UserButtonCode_crotchetButtonRight]
    }
    else if (buttonThatWasClicked == quaverButtonRight)
    {
        //[UserButtonCode_quaverButtonRight] -- add your button handler code here..
       *processor.rightDelayTime_param = 30000;
        comboBoxRight->setSelectedId(6);
        //[/UserButtonCode_quaverButtonRight]
    }
    else if (buttonThatWasClicked == semiquaverButtonRight)
    {
        //[UserButtonCode_semiquaverButtonRight] -- add your button handler code here..
        *processor.rightDelayTime_param = 15000;
        comboBoxRight->setSelectedId(3);
        //[/UserButtonCode_semiquaverButtonRight]
    }
    else if (buttonThatWasClicked == mainButton)
    {
        //[UserButtonCode_mainButton] -- add your button handler code here..
        processor.postPreMix = 1;
        //[/UserButtonCode_mainButton]
    }
    else if (buttonThatWasClicked == feedbackButton)
    {
        //[UserButtonCode_feedbackButton] -- add your button handler code here..
        processor.postPreMix = 2;
        //[/UserButtonCode_feedbackButton]
    }

    //[UserbuttonClicked_Post]
    else if (buttonThatWasClicked == &Bypass)
    {
        toggleState =Bypass.getToggleState();
        if (toggleState == false)
        {
            visible = true;
            minimButton->setVisible(visible);
            minimButtonRight->setVisible(visible);
            crotchetButton->setVisible(visible);
            crotchetButtonRight->setVisible(visible);
            quaverButton->setVisible(visible);
            quaverButtonRight->setVisible(visible);
            semiquaverButton->setVisible(visible);
            semiquaverButtonRight->setVisible(visible);
            comboBoxLeft->setVisible(visible);
            comboBoxRight->setVisible(visible);
            leftDelayTimeslider->setColour (Slider::thumbColourId, Colour (0x37c84242));
            leftDelayTimeslider->setColour (Slider::rotarySliderOutlineColourId, Colour (0x57263238));
            rightDelayTimeslider->setColour (Slider::thumbColourId, Colour (0x37c84242));
            rightDelayTimeslider->setColour (Slider::rotarySliderOutlineColourId, Colour (0x57263238));
        }
        else if (toggleState == true)
        {
            visible = false;
            minimButton->setVisible(visible);
            minimButtonRight->setVisible(visible);
            crotchetButton->setVisible(visible);
            crotchetButtonRight->setVisible(visible);
            quaverButton->setVisible(visible);
            quaverButtonRight->setVisible(visible);
            semiquaverButton->setVisible(visible);
            semiquaverButtonRight->setVisible(visible);
            comboBoxLeft->setVisible(visible);
            comboBoxRight->setVisible(visible);
            leftDelayTimeslider->setColour (Slider::thumbColourId, Colour (0xffc84242));
            leftDelayTimeslider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff263238));
            rightDelayTimeslider->setColour (Slider::thumbColourId, Colour (0xffc84242));
            rightDelayTimeslider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff263238));
        }

    }
}


    //[/UserbuttonClicked_Post]


void WillStereoDelayAudioProcessorEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == comboBoxLeft)
    {
        //[UserComboBoxCode_comboBoxLeft] -- add your combo box handling code here..
       comboboxValLeft = comboBoxThatHasChanged->getSelectedId();
        *processor.leftDelayTime_param = setDelayFraction(comboboxValLeft);
        deviationValueLeft = 0;
        //[/UserComboBoxCode_comboBoxLeft]
    }
    else if (comboBoxThatHasChanged == comboBoxRight)
    {
        //[UserComboBoxCode_comboBoxRight] -- add your combo box handling code here..
        comboboxValRight = comboBoxThatHasChanged->getSelectedId();
        *processor.rightDelayTime_param = setDelayFraction(comboboxValRight);
        deviationValueRight = 0;
        //[/UserComboBoxCode_comboBoxRight]
    }
    else if (comboBoxThatHasChanged == leftInputSelector)
    {
        //[UserComboBoxCode_leftInputSelector] -- add your combo box handling code here..
        processor.leftInputSelection = comboBoxThatHasChanged->getSelectedId();
        //[/UserComboBoxCode_leftInputSelector]
    }
    else if (comboBoxThatHasChanged == rightInputSelector)
    {
        //[UserComboBoxCode_rightInputSelector] -- add your combo box handling code here..
        processor.rightInputSelection = comboBoxThatHasChanged->getSelectedId();
        //[/UserComboBoxCode_rightInputSelector]
    }
    else if (comboBoxThatHasChanged == effectCombobox)
    {
        //[UserComboBoxCode_effectCombobox] -- add your combo box handling code here..
        switch (comboBoxThatHasChanged->getSelectedId()) {
            case 1:
                resLPFcutOffSlider.setVisible(false);
                resLPFqSlider.setVisible(false);
                bitDepthSlider.setVisible(false);
                bitRateSlider.setVisible(false);
                bitDepthLabel.setVisible(false);
                bitRateLabel.setVisible(false);
                tremoloRate.setVisible(true);
                tremoloAmount.setVisible(true);
                tremRateLabel.setVisible(true);
                tremAmountLabel.setVisible(true);
                
                break;
            case 2:
                resLPFcutOffSlider.setVisible(false);
                resLPFqSlider.setVisible(false);
                tremoloRate.setVisible(false);
                tremoloAmount.setVisible(false);
                tremRateLabel.setVisible(false);
                tremAmountLabel.setVisible(false);
                bitDepthSlider.setVisible(true);
                bitRateSlider.setVisible(true);
                bitDepthLabel.setVisible(true);
                bitRateLabel.setVisible(true);
                break;
                
            case 3:
                resLPFcutOffSlider.setVisible(true);
                resLPFqSlider.setVisible(true);
                tremoloRate.setVisible(false);
                tremoloAmount.setVisible(false);
                tremRateLabel.setVisible(false);
                tremAmountLabel.setVisible(false);
                bitDepthSlider.setVisible(false);
                bitRateSlider.setVisible(false);
                bitDepthLabel.setVisible(false);
                bitRateLabel.setVisible(false);
            default:
                break;
        }
        //[/UserComboBoxCode_effectCombobox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

float WillStereoDelayAudioProcessorEditor::setDelayFraction(int comboBoxVal)
{
    switch (comboBoxVal) {
        case 1:return 9996;break;
        case 2:return 11250;break;
        case 3:return 15000;break;
        case 4:return 19272;break;
        case 5:return 22500;break;
        case 6:return 30000;break;
        case 7:return 39996;break;
        case 8:return 45000;break;
        case 9:return 60000;break;
        case 10:return 79992;break;
        case 11:return 90000;break;
        case 12:return 120000;break;
        default:break;
    }
}

float WillStereoDelayAudioProcessorEditor::setComboBoxText(float sliderVal, ComboBox* combobox)
{

    float deviationValue;
    if (sliderVal > 0 && sliderVal < 9996)
    {
        combobox->setSelectedId(0, dontSendNotification);
        deviationValue = (((sliderVal - 9996)/9996)*100);
    }

    else if (sliderVal > 9996 && sliderVal < 11250){
       combobox->setSelectedId(1, dontSendNotification);
        deviationValue = (((sliderVal - 9996)/9996)*100);
    }
    else if (sliderVal > 11250 && sliderVal < 15000){
            combobox->setSelectedId(2, dontSendNotification);
        deviationValue = (((sliderVal - 11250)/11250)*100);
    }
    else if (sliderVal > 15000 && sliderVal < 19272){
       combobox->setSelectedId(3, dontSendNotification);
        deviationValue = (((sliderVal - 15000)/15000)*100);
    }
    else if (sliderVal > 19272 && sliderVal < 22500){
       combobox->setSelectedId(4, dontSendNotification);
        deviationValue = ((sliderVal - 19272)/19272*100);
    }
    else if (sliderVal > 22500 && sliderVal < 30000){
       combobox->setSelectedId(5, dontSendNotification);
        deviationValue = ((sliderVal - 22500)/22500*100);
    }
    else if (sliderVal > 30000 && sliderVal < 39996){
       combobox->setSelectedId(6, dontSendNotification);
        deviationValue = ((sliderVal - 30000)/30000*100);

    }

    else if (sliderVal > 39996 && sliderVal < 45000){
       combobox->setSelectedId(7, dontSendNotification);
        deviationValue = ((sliderVal - 39996)/39996*100);
    }

    else if (sliderVal > 45000 && sliderVal < 60000){
       combobox->setSelectedId(8, dontSendNotification);
        deviationValue = ((sliderVal - 45000)/45000*100);
    }

    else if (sliderVal > 60000 && sliderVal < 79992){
       combobox->setSelectedId(9, dontSendNotification);
        deviationValue = ((sliderVal - 60000)/60000*100);
    }


    else if (sliderVal > 79992 && sliderVal < 90000){
       combobox->setSelectedId(10, dontSendNotification);
        deviationValue = ((sliderVal - 79992)/79992*100);
    }

    else if (sliderVal > 90000 && sliderVal < 120000){
       combobox->setSelectedId(11, dontSendNotification);
        deviationValue = ((sliderVal - 90000)/90000*100);
    }


    else
    {
       combobox->setSelectedId(12, dontSendNotification);
    deviationValue = ((sliderVal - 12000)/12000*100);
    }


return deviationValue;

}


void WillStereoDelayAudioProcessorEditor::timerCallback()
{
    leftMixSlider        ->setValue(*processor.leftMix_param, dontSendNotification);
    rightMixSlider        ->setValue(*processor.rightMix_param,     dontSendNotification);

    leftFdbckSlider        .setValue(*processor.leftFeedback_param,dontSendNotification);
    rightFdbckSlider        .setValue(*processor.rightFeedback_param, dontSendNotification);
    leftRangeSlider.setMinAndMaxValues(*processor.leftHPF_param, *processor.leftLPF_param);
    rightRangeSlider.setMinAndMaxValues(*processor.rightHPF_param, *processor.rightLPF_param);
    leftDelayLabel->setText(String(floor(processor.noteValDelayL)), sendNotification);
    rightDelayLabel->setText(String(floor(processor.noteValDelayR)), sendNotification);
    deviationLabelLeft->setText(String(deviationValueLeft), sendNotification);
    deviationLabelRight->setText(String(deviationValueRight), sendNotification);


    leftDelayTimeslider        ->setValue(*processor.leftDelayTime_param,    dontSendNotification);
    rightDelayTimeslider        ->setValue(*processor.rightDelayTime_param,   dontSendNotification);

    tremoloAmount.setValue(*processor.tremoloAmount_param, dontSendNotification);
    tremoloRate.setValue(*processor.tremoloRate_param, dontSendNotification);

    crossfeedLeft.setValue(*processor.leftCrossLevel_param, dontSendNotification);
    crossfeedRight.setValue(*processor.rightCrossLevel_param, dontSendNotification);

}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="WillStereoDelayAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor"
                 constructorParams="WillStereoDelayAudioProcessor&amp; p" variableInitialisers="AudioProcessorEditor (&amp;p), processor(p)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="1020" initialHeight="450">
  <BACKGROUND backgroundColour="ff323e44"/>
  <SLIDER name="Left Mix slider" id="15fba5bd03d265f9" memberName="leftMixSlider"
          virtualName="" explicitFocusOrder="0" pos="352 112 48 200" textboxoutline="8e989b"
          min="0.00000000000000000000" max="100.00000000000000000000" int="1.00000000000000000000"
          style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <SLIDER name="Right Mix slider" id="75f055da00daa91e" memberName="rightMixSlider"
          virtualName="" explicitFocusOrder="0" pos="424 112 54 200" textboxoutline="8e989b"
          min="0.00000000000000000000" max="100.00000000000000000000" int="1.00000000000000000000"
          style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <IMAGEBUTTON name="crotchet button" id="84b1d69ca2cb8008" memberName="crotchetButton"
               virtualName="" explicitFocusOrder="0" pos="136 48 32 32" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="kisspngquarternotemusicalnoteeighthnoterestmusicnotes5ad2c34d6918e6_3884611415237619974305_png"
               opacityNormal="1.00000000000000000000" colourNormal="0" resourceOver="kisspngquarternotemusicalnoteeighthnoterestmusicnotes5ad2c34d6918e6_3884611415237619974305_png"
               opacityOver="1.00000000000000000000" colourOver="ff999999" resourceDown=""
               opacityDown="1.00000000000000000000" colourDown="0"/>
  <IMAGEBUTTON name="minim button" id="d5f4a631e161b80b" memberName="minimButton"
               virtualName="" explicitFocusOrder="0" pos="160 88 32 32" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="minim_png" opacityNormal="1.00000000000000000000"
               colourNormal="e90b0b" resourceOver="minim_png" opacityOver="1.00000000000000000000"
               colourOver="ff999999" resourceDown="" opacityDown="1.00000000000000000000"
               colourDown="0"/>
  <IMAGEBUTTON name="quaver button" id="8bc9c2380ebf1d15" memberName="quaverButton"
               virtualName="" explicitFocusOrder="0" pos="72 48 32 32" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="quaver_png" opacityNormal="0.99941408634185791016"
               colourNormal="0" resourceOver="quaver_png" opacityOver="1.00000000000000000000"
               colourOver="ff999999" resourceDown="" opacityDown="1.00000000000000000000"
               colourDown="0"/>
  <IMAGEBUTTON name="semi quaver button" id="cfe8f1009e955dd8" memberName="semiquaverButton"
               virtualName="" explicitFocusOrder="0" pos="48 88 40 40" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="semiquaver_png" opacityNormal="1.00000000000000000000"
               colourNormal="0" resourceOver="semiquaver_png" opacityOver="1.00000000000000000000"
               colourOver="ff999999" resourceDown="" opacityDown="1.00000000000000000000"
               colourDown="0"/>
  <IMAGEBUTTON name="minim button" id="44901090fcfda0be" memberName="minimButtonRight"
               virtualName="" explicitFocusOrder="0" pos="640 104 32 32" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="minim_png" opacityNormal="1.00000000000000000000"
               colourNormal="999999" resourceOver="minim_png" opacityOver="1.00000000000000000000"
               colourOver="ff999999" resourceDown="" opacityDown="1.00000000000000000000"
               colourDown="0"/>
  <IMAGEBUTTON name="crotchet button" id="a4b56fae982b0aff" memberName="crotchetButtonRight"
               virtualName="" explicitFocusOrder="0" pos="624 56 32 32" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="kisspngquarternotemusicalnoteeighthnoterestmusicnotes5ad2c34d6918e6_3884611415237619974305_png"
               opacityNormal="1.00000000000000000000" colourNormal="0" resourceOver="kisspngquarternotemusicalnoteeighthnoterestmusicnotes5ad2c34d6918e6_3884611415237619974305_png"
               opacityOver="1.00000000000000000000" colourOver="ff999999" resourceDown=""
               opacityDown="1.00000000000000000000" colourDown="0"/>
  <IMAGEBUTTON name="quaver button" id="521d3d385d214930" memberName="quaverButtonRight"
               virtualName="" explicitFocusOrder="0" pos="552 56 32 32" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="quaver_png" opacityNormal="0.99941408634185791016"
               colourNormal="0" resourceOver="quaver_png" opacityOver="1.00000000000000000000"
               colourOver="ff999999" resourceDown="" opacityDown="1.00000000000000000000"
               colourDown="0"/>
  <IMAGEBUTTON name="semi quaver button" id="b1aaacb53f926e2b" memberName="semiquaverButtonRight"
               virtualName="" explicitFocusOrder="0" pos="536 104 40 40" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="semiquaver_png" opacityNormal="1.00000000000000000000"
               colourNormal="0" resourceOver="semiquaver_png" opacityOver="1.00000000000000000000"
               colourOver="ff999999" resourceDown="" opacityDown="1.00000000000000000000"
               colourDown="0"/>
  <COMBOBOX name="Left combo box" id="6f4e4bf5075043b0" memberName="comboBoxLeft"
            virtualName="" explicitFocusOrder="0" pos="216 64 104 24" editable="0"
            layout="33" items="1/16 triplet&#10;1/32 dotted&#10;1/16&#10;1/8 triplet&#10;1/16 dotted&#10;1/8&#10;1/4 triplet&#10;1/8 dotted&#10;1/4&#10;1/2 triplet&#10;1/4 dotted&#10;1/2&#10;1/1 triplet&#10;1/2 dotted"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="Right combo box" id="43407717b14f3e8e" memberName="comboBoxRight"
            virtualName="" explicitFocusOrder="0" pos="680 64 104 24" editable="0"
            layout="33" items="1/16 triplet&#10;1/32 dotted&#10;1/16&#10;1/8 triplet&#10;1/16 dotted&#10;1/8&#10;1/4 triplet&#10;1/8 dotted&#10;1/4&#10;1/2 triplet&#10;1/4 dotted&#10;1/2&#10;1/1 triplet&#10;1/2 dotted"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="Left label" id="bc10247c68a04841" memberName="leftDelayLabel"
         virtualName="" explicitFocusOrder="0" pos="88 160 56 24" edTextCol="ff000000"
         edBkgCol="0" labelText="" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="36"/>
  <LABEL name="Left label" id="6fbb3e4fae8ef18c" memberName="rightDelayLabel"
         virtualName="" explicitFocusOrder="0" pos="576 176 56 24" edTextCol="ff000000"
         edBkgCol="0" labelText="" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="36"/>
  <SLIDER name="LeftDelayTimeslider" id="5ca0d66952a5c03e" memberName="leftDelayTimeslider"
          virtualName="" explicitFocusOrder="0" pos="72 72 88 88" bkgcol="ff449c3a"
          thumbcol="37c84242" trackcol="ff181f22" rotarysliderfill="ff181f22"
          rotaryslideroutline="ff263238" min="0.00000000000000000000" max="200000.00000000000000000000"
          int="1.00000000000000000000" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <SLIDER name="RightDelayTimeslider" id="3ecf61bcb9ef3c99" memberName="rightDelayTimeslider"
          virtualName="" explicitFocusOrder="0" pos="560 80 88 88" bkgcol="ff449c3a"
          thumbcol="37c84242" trackcol="ff181f22" rotarysliderfill="ff181f22"
          rotaryslideroutline="ff263238" min="0.00000000000000000000" max="200000.00000000000000000000"
          int="1.00000000000000000000" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <COMBOBOX name="left input selector" id="523b0570375aa023" memberName="leftInputSelector"
            virtualName="" explicitFocusOrder="0" pos="8 8 72 24" editable="0"
            layout="33" items="Left&#10;Right&#10;L+R&#10;None" textWhenNonSelected="Left"
            textWhenNoItems="(no choices)"/>
  <COMBOBOX name="right input selector" id="25c1a41c1686bd3a" memberName="rightInputSelector"
            virtualName="" explicitFocusOrder="0" pos="720 8 68 24" editable="0"
            layout="33" items="Right&#10;Left&#10;R+L&#10;None" textWhenNonSelected="Right"
            textWhenNoItems="(no choices)"/>
  <TEXTBUTTON name="main button" id="3b4d08f5c2f2f175" memberName="mainButton"
              virtualName="" explicitFocusOrder="0" pos="832 328 66 24" buttonText="Main"
              connectedEdges="0" needsCallback="1" radioGroupId="1001"/>
  <TEXTBUTTON name="feedback button" id="12cff3675bab067e" memberName="feedbackButton"
              virtualName="" explicitFocusOrder="0" pos="904 328 66 24" buttonText="feedback"
              connectedEdges="0" needsCallback="1" radioGroupId="1001"/>
  <LABEL name="deviation label left" id="34c796cf321175ce" memberName="deviationLabelLeft"
         virtualName="" explicitFocusOrder="0" pos="216 96 104 24" edTextCol="ff000000"
         edBkgCol="0" labelText="" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="16.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="33"/>
  <LABEL name="deviation label right" id="550990735c26d8b5" memberName="deviationLabelRight"
         virtualName="" explicitFocusOrder="0" pos="680 96 104 24" edTextCol="ff000000"
         edBkgCol="0" labelText="" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="16.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="effect combo box" id="36245f6b9ed3440f" memberName="effectCombobox"
            virtualName="" explicitFocusOrder="0" pos="840 8 128 24" editable="0"
            layout="33" items="Tremolo&#10;Bitcrusher&#10;Resonant LPF" textWhenNonSelected="Effects"
            textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: multimedia_png, 1348, "../../../Downloads/multimedia.png"
static const unsigned char resource_WillStereoDelayAudioProcessorEditor_multimedia_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,128,0,0,0,128,8,6,0,0,0,195,62,97,203,0,0,0,1,115,82,71,
66,0,174,206,28,233,0,0,0,4,103,65,77,65,0,0,177,143,11,252,97,5,0,0,0,9,112,72,89,115,0,0,14,195,0,0,14,195,1,199,111,168,100,0,0,4,217,73,68,65,84,120,94,237,156,203,139,78,113,28,198,39,162,88,200,
134,133,68,20,69,17,133,44,208,216,73,33,118,114,43,69,40,22,74,178,81,248,11,20,91,197,198,2,107,151,149,133,75,46,217,136,66,73,174,165,36,164,92,27,223,111,157,169,73,131,223,115,222,203,188,231,241,
57,245,109,166,119,158,243,59,231,121,158,207,188,115,230,157,121,79,95,31,91,171,9,172,138,5,6,10,38,117,108,134,9,0,128,97,169,138,37,0,80,210,50,212,2,128,97,169,138,37,0,80,210,50,212,2,128,97,169,
138,37,0,80,210,50,212,2,128,97,169,138,37,0,80,210,50,212,2,128,97,169,138,37,0,80,210,50,212,2,128,97,169,138,37,0,80,210,50,212,2,128,97,169,138,37,0,80,210,50,212,2,128,97,169,138,37,0,80,210,50,212,
2,128,97,169,138,37,0,80,210,50,212,2,128,97,169,138,37,0,80,210,50,212,2,128,97,169,138,37,0,80,210,50,212,2,128,97,169,138,37,0,80,210,50,212,2,128,97,169,138,37,0,80,210,50,212,2,128,97,169,138,37,
0,80,210,50,212,2,128,97,169,138,37,0,80,210,50,212,2,128,97,169,138,37,0,80,210,50,212,2,128,97,169,138,37,0,80,210,50,212,2,128,97,169,138,37,0,80,210,50,212,2,128,97,169,138,37,0,80,210,50,212,2,128,
97,169,138,37,0,80,210,50,212,2,128,97,169,138,37,0,80,210,50,212,2,128,97,169,138,37,0,80,210,50,212,2,128,97,169,138,37,0,80,210,50,212,2,128,97,169,138,37,0,80,210,50,212,2,128,97,169,138,37,0,80,210,
50,212,2,128,97,169,138,37,0,80,210,50,212,2,128,97,169,138,37,0,80,210,50,212,2,128,97,169,138,37,0,80,210,50,212,2,128,97,169,138,37,0,80,210,50,212,2,128,97,169,138,37,0,80,210,50,212,2,128,97,169,
138,37,0,80,210,50,212,2,128,97,169,138,37,0,80,210,50,212,2,128,97,169,138,37,0,80,210,50,212,2,128,97,169,138,37,0,80,210,50,212,2,128,97,169,138,37,0,80,210,50,212,2,128,97,169,138,37,0,80,210,50,212,
2,128,97,169,138,37,0,80,210,50,212,2,128,97,169,138,37,0,80,210,50,212,2,128,97,169,138,37,0,80,210,50,212,2,128,97,169,138,37,0,80,210,234,1,237,248,56,135,41,49,179,98,230,87,51,187,122,44,191,166,
110,0,160,38,214,69,253,152,56,214,226,152,61,49,103,98,110,196,60,143,249,20,243,53,102,160,154,111,213,99,47,226,227,173,152,211,49,251,170,125,115,141,191,109,0,208,197,66,75,15,213,31,194,19,49,143,
134,148,60,88,182,250,241,113,172,113,50,102,197,31,14,14,0,165,173,116,88,55,58,214,223,22,115,189,13,165,255,9,146,155,177,246,214,152,161,207,10,0,208,225,98,75,150,223,16,162,187,29,44,254,119,32,
238,197,177,214,87,39,182,188,240,184,9,10,91,155,19,152,26,235,157,45,44,64,125,234,47,209,159,138,99,111,143,249,89,112,14,0,208,230,242,87,199,122,175,11,130,47,41,178,21,205,15,0,104,115,179,5,203,
237,239,129,226,85,104,120,6,40,40,182,68,114,184,129,229,39,44,0,80,210,238,63,52,135,26,90,62,0,180,161,252,141,13,46,31,0,90,4,32,95,170,253,12,0,45,166,216,208,221,71,197,121,119,242,197,29,245,98,
174,174,158,107,128,154,0,238,108,248,119,254,32,48,0,80,3,128,9,177,207,43,0,168,145,156,201,46,123,77,202,231,34,176,6,144,249,199,157,251,0,80,35,57,147,93,150,26,149,207,51,64,13,40,143,0,64,141,212,
140,118,185,10,0,70,109,138,86,198,133,254,37,0,136,169,25,201,243,31,54,191,3,128,81,163,162,149,252,71,206,186,175,184,245,234,126,188,16,36,64,176,18,0,132,180,12,165,253,134,0,36,212,108,133,9,44,
50,4,32,127,172,177,21,38,48,35,116,95,140,32,200,55,161,204,44,244,142,44,18,24,27,243,212,8,128,103,149,39,202,21,18,184,100,4,192,21,193,55,210,42,129,3,70,0,28,164,85,61,129,121,70,0,228,187,144,217,
106,36,112,205,0,130,124,71,50,91,205,4,54,25,0,176,185,166,119,118,171,174,156,31,52,24,130,135,92,253,183,206,241,186,6,3,48,248,14,226,214,83,248,207,87,56,223,64,8,46,252,231,157,181,213,254,164,88,
173,23,222,9,92,250,151,198,55,113,190,147,219,154,0,139,245,45,139,12,134,222,215,167,180,140,110,235,242,126,67,121,211,8,182,14,36,208,132,247,7,230,111,46,108,29,76,32,3,46,185,35,71,183,191,243,243,
120,91,58,232,155,165,135,36,176,38,62,127,215,67,23,134,121,46,107,105,168,187,9,204,137,195,221,238,1,8,238,196,57,204,237,174,117,142,54,152,64,254,217,248,232,8,93,28,230,5,233,177,152,60,7,182,17,
78,96,65,28,255,92,23,159,13,242,117,137,133,35,236,153,195,15,147,64,254,170,152,183,121,253,208,1,24,62,198,154,121,187,89,126,197,107,0,122,211,226,28,119,197,92,140,121,223,2,12,185,111,174,177,59,
102,122,3,124,115,138,195,36,48,49,30,203,127,200,220,17,115,60,230,114,204,147,152,183,49,249,115,60,39,63,207,199,242,107,169,201,155,82,44,137,201,125,173,183,95,67,163,216,119,79,30,157,120,0,0,0,
0,73,69,78,68,174,66,96,130,0,0};

const char* WillStereoDelayAudioProcessorEditor::multimedia_png = (const char*) resource_WillStereoDelayAudioProcessorEditor_multimedia_png;
const int WillStereoDelayAudioProcessorEditor::multimedia_pngSize = 1348;

// JUCER_RESOURCE: minim_png, 1910, "../../../Documents/minim.png"
static const unsigned char resource_WillStereoDelayAudioProcessorEditor_minim_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,200,0,0,0,200,8,6,0,0,0,173,88,174,158,0,0,0,4,115,66,73,84,
8,8,8,8,124,8,100,136,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,7,24,73,68,65,84,120,156,237,221,107,136,29,103,29,199,241,111,154,110,188,109,99,75,211,136,41,213,26,72,104,193,106,
140,247,8,162,20,81,223,8,74,172,130,138,72,35,10,141,149,10,226,27,17,44,8,162,16,148,130,74,177,136,21,36,168,160,130,16,188,129,162,86,145,82,69,141,17,181,165,173,197,154,214,75,215,104,52,245,178,
190,120,140,110,114,230,252,206,109,102,158,115,206,126,63,48,111,194,238,158,255,146,249,50,103,231,204,60,3,218,108,86,129,245,243,182,195,85,39,154,99,23,212,30,64,154,103,6,34,5,6,34,5,6,34,5,6,34,
5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,
34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,
6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,
5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,
34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,34,5,6,178,56,46,0,182,1,91,107,
15,178,153,92,88,123,0,253,207,10,176,15,216,15,92,13,236,1,174,0,118,2,23,3,143,217,240,181,167,129,135,129,251,128,19,192,143,128,239,1,199,129,245,254,70,150,186,181,7,120,55,240,13,202,78,191,62,227,
246,32,112,43,240,82,96,203,144,215,92,109,248,190,195,173,255,102,210,148,46,1,222,9,220,197,236,65,164,237,215,192,13,156,123,228,1,3,209,156,186,18,248,24,237,28,41,38,217,238,5,94,179,97,14,3,209,
92,121,18,240,9,224,81,250,13,227,252,237,40,176,29,3,209,156,216,10,188,11,248,51,117,195,216,184,157,0,158,209,240,239,6,162,94,93,5,252,144,126,119,254,127,143,249,117,15,55,252,155,129,12,225,231,
32,237,187,158,242,7,248,115,59,124,141,187,129,91,128,215,81,78,9,175,82,254,47,87,128,167,2,175,166,156,205,90,107,248,222,29,29,206,37,13,181,66,217,41,187,58,66,252,149,242,183,204,254,9,102,90,5,
222,15,156,25,241,179,61,130,168,83,219,129,111,210,77,24,107,192,205,192,165,51,204,247,108,202,103,36,6,162,222,93,10,220,73,251,97,156,1,142,48,91,24,27,61,29,56,53,228,181,12,68,157,184,152,114,153,
71,219,113,28,163,124,202,222,182,195,67,94,207,64,212,186,199,2,223,165,221,48,30,4,174,235,112,230,21,224,183,13,175,107,32,106,221,81,218,141,227,54,202,17,169,107,31,109,120,109,3,81,171,222,67,123,
97,220,15,188,188,199,217,95,223,48,131,129,168,53,7,128,127,210,78,28,159,164,156,1,235,211,129,134,57,222,215,243,12,90,82,79,160,92,37,219,198,81,227,21,61,207,126,214,115,26,230,57,90,105,22,45,153,
35,204,30,199,237,244,127,212,216,232,101,13,51,221,81,113,30,45,137,107,152,237,173,213,31,128,215,246,62,245,160,27,24,156,237,68,213,137,180,20,190,206,244,113,124,21,216,213,255,200,141,62,199,224,
124,247,84,157,72,11,239,90,166,11,227,111,192,141,12,191,253,181,111,23,1,127,97,112,206,95,212,28,74,139,239,219,76,30,199,207,40,151,119,204,147,155,104,158,245,7,53,135,210,98,123,62,147,199,113,27,
240,184,26,195,6,23,1,39,105,158,247,75,21,231,210,130,187,157,241,195,248,59,229,126,144,121,116,11,195,231,62,82,113,46,45,176,75,40,59,253,56,113,156,4,94,88,103,204,145,94,73,190,227,240,80,189,209,
180,200,14,49,94,28,191,2,118,87,154,113,148,61,192,31,201,243,63,171,218,116,90,104,95,97,116,28,63,165,172,92,50,143,118,49,250,147,255,71,112,57,83,77,97,27,229,54,215,180,115,157,0,46,171,53,224,8,
87,0,191,100,116,224,95,168,53,160,22,219,11,200,59,214,239,128,167,84,155,46,187,154,114,189,215,56,111,15,223,80,105,70,45,184,97,119,223,173,83,46,57,121,113,189,209,162,107,129,63,49,94,28,167,40,
23,96,74,19,251,56,195,119,172,15,86,156,43,185,9,248,7,227,159,150,190,181,206,152,90,6,199,104,222,169,238,103,254,62,4,220,78,243,53,86,163,182,107,106,12,171,229,240,99,154,119,170,183,213,28,170,
193,243,152,238,30,149,99,53,134,213,242,184,135,193,157,106,141,249,57,122,108,5,222,203,100,111,169,54,110,243,250,161,166,22,196,111,24,220,169,62,91,117,162,255,219,77,121,162,212,52,97,172,3,95,238,
127,100,45,155,123,25,220,177,222,94,115,160,255,58,196,240,5,224,198,217,206,0,123,123,159,90,75,231,39,12,238,92,47,169,56,207,14,224,139,13,51,77,186,221,220,247,224,90,78,77,103,177,158,89,105,150,
131,12,191,84,125,146,237,56,131,143,100,147,166,210,180,192,90,151,143,52,104,114,25,211,157,190,29,246,214,106,95,191,227,107,153,189,145,193,157,236,96,143,175,127,16,120,168,97,134,105,183,119,244,
56,187,54,129,93,12,222,67,209,199,141,69,59,129,207,211,94,24,235,192,167,122,152,91,155,208,247,57,119,71,123,128,178,0,116,23,182,0,111,161,44,15,212,102,28,95,235,112,102,109,114,215,51,184,195,117,
177,142,237,62,218,95,41,126,157,242,89,201,106,7,243,74,64,57,227,243,0,231,238,116,167,104,239,26,166,203,41,235,243,254,139,246,227,248,14,117,87,112,212,38,241,38,6,119,190,147,204,118,70,235,114,
224,35,148,117,179,218,14,99,157,242,73,249,227,103,152,79,154,72,211,173,183,143,2,31,0,158,56,230,207,216,66,185,135,228,51,140,126,168,230,44,219,135,241,233,197,234,217,14,154,47,94,60,251,150,235,
211,148,231,110,236,165,188,231,223,70,121,182,224,126,224,205,148,183,81,231,191,85,107,123,91,163,219,167,83,73,209,30,154,31,95,54,15,219,183,128,167,117,246,155,75,99,218,77,89,199,182,118,16,103,
183,223,83,46,94,156,151,181,127,37,182,83,46,123,175,25,198,105,224,67,244,243,76,67,105,42,175,162,157,167,77,77,178,61,66,9,227,201,61,252,126,210,204,86,40,111,113,142,211,109,24,119,0,111,197,21,
72,180,192,14,80,22,136,190,143,217,131,88,163,156,90,190,17,184,178,199,223,65,231,241,143,187,110,236,5,94,68,89,243,246,42,202,2,115,59,41,71,128,11,41,235,106,157,166,132,240,16,101,165,148,187,41,
71,162,187,128,159,83,46,148,84,101,255,1,94,155,53,79,117,106,116,246,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* WillStereoDelayAudioProcessorEditor::minim_png = (const char*) resource_WillStereoDelayAudioProcessorEditor_minim_png;
const int WillStereoDelayAudioProcessorEditor::minim_pngSize = 1910;

// JUCER_RESOURCE: quaver_png, 16608, "../../../Documents/quaver.png"
static const unsigned char resource_WillStereoDelayAudioProcessorEditor_quaver_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,2,208,0,0,2,208,8,6,0,0,0,185,87,71,156,0,0,64,167,73,68,65,84,
120,218,237,221,121,124,173,107,89,223,255,79,118,246,57,204,156,195,60,136,204,160,32,130,32,160,50,8,226,136,136,19,82,149,138,162,86,173,179,181,117,170,250,171,86,235,80,107,157,231,9,21,45,34,21,
172,117,70,173,212,42,78,168,40,42,138,8,8,130,12,50,200,124,50,252,254,120,158,155,172,179,78,118,146,125,78,146,157,100,189,223,175,215,122,173,100,237,76,251,201,147,60,223,117,229,186,175,187,0,88,
69,107,14,1,128,95,160,0,103,197,122,181,89,125,117,245,225,213,219,231,199,46,230,119,251,249,125,222,230,134,213,47,85,95,94,157,171,182,28,118,128,131,57,239,16,0,156,56,163,184,113,191,234,125,143,
240,243,188,200,161,6,16,160,1,206,146,183,52,85,134,55,186,184,10,244,98,8,223,205,230,252,241,222,230,16,3,8,208,0,103,201,185,133,219,250,33,126,220,237,249,99,106,227,3,184,150,191,156,1,88,77,155,
243,189,32,13,32,64,3,112,0,22,14,2,8,208,0,0,32,64,3,0,128,0,13,192,37,167,133,3,64,128,6,224,0,182,231,251,13,135,2,64,128,6,0,0,1,26,0,0,4,104,0,46,181,109,135,0,64,128,6,224,224,244,64,3,8,208,0,0,
32,64,3,0,128,0,13,192,37,167,7,26,64,128,6,224,34,232,129,6,16,160,1,0,64,128,6,0,0,1,26,128,75,78,15,52,128,0,13,192,69,88,115,8,0,4,104,0,14,238,50,135,0,64,128,6,56,75,142,186,197,98,221,33,6,16,160,
1,206,146,171,142,248,227,171,64,3,8,208,0,28,192,154,0,13,32,64,3,112,241,110,50,223,155,198,1,32,64,3,112,0,55,21,160,1,4,104,0,246,55,90,56,174,112,40,0,4,104,0,14,238,134,213,249,166,10,180,153,208,
0,2,52,0,23,48,194,242,77,83,133,6,16,160,1,56,176,43,171,155,45,133,106,0,4,104,0,150,172,53,181,109,92,79,128,6,16,160,1,56,152,49,121,227,93,28,10,0,1,26,128,131,7,232,187,205,247,42,208,0,2,52,0,7,
8,208,119,117,40,0,4,104,0,246,55,42,206,119,153,239,55,29,18,0,1,26,128,253,3,244,221,230,107,129,89,208,0,2,52,0,7,8,208,183,155,111,0,8,208,0,236,19,160,183,171,155,84,119,116,77,0,16,160,1,216,223,
214,124,111,18,7,128,0,13,192,1,140,73,28,239,225,80,0,8,208,0,28,220,187,47,5,106,0,4,104,0,246,184,6,220,163,90,111,26,101,167,141,3,64,128,6,224,2,70,88,190,83,117,43,135,3,64,128,6,96,255,0,189,93,
221,184,186,187,235,2,128,0,13,192,254,198,14,132,247,90,8,213,0,8,208,0,236,227,126,243,189,133,132,0,2,52,0,123,24,21,231,251,8,208,0,2,52,0,7,191,14,220,189,105,87,194,173,180,113,0,8,208,0,92,208,
8,203,183,175,238,188,244,24,0,2,52,0,187,24,243,159,239,235,218,0,32,64,3,176,191,209,247,124,127,135,2,64,128,6,96,127,163,101,227,1,243,253,166,67,2,32,64,3,156,70,199,53,17,99,92,11,222,189,186,98,
254,188,250,160,1,4,104,128,83,103,227,152,62,207,8,203,183,171,238,185,244,24,0,2,52,0,187,24,109,27,15,116,125,0,16,160,1,216,223,104,23,121,240,210,235,0,8,208,0,236,113,61,120,224,252,178,133,132,
0,2,52,0,123,24,61,207,247,168,238,234,26,1,32,64,3,176,127,128,222,172,174,151,62,104,0,1,26,128,3,25,125,207,15,115,40,0,4,104,0,14,126,77,120,232,252,242,70,198,217,1,8,208,0,92,208,8,203,247,174,238,
182,244,24,0,2,52,0,187,4,232,205,234,242,234,33,174,19,0,2,52,0,251,27,125,208,143,90,122,29,0,1,26,128,61,174,11,15,175,174,223,84,145,214,198,1,32,64,3,176,199,117,97,187,186,75,245,0,215,10,0,1,26,
128,253,141,93,8,63,100,190,87,129,6,16,160,1,56,192,181,225,67,218,89,88,8,128,0,13,192,5,140,138,243,3,170,187,55,181,116,184,94,0,8,208,0,236,17,160,199,182,222,31,230,122,1,32,64,3,112,112,31,57,223,
111,57,20,0,2,52,0,251,95,31,30,82,221,113,14,208,174,25,0,126,25,2,112,1,163,141,227,134,213,99,93,51,0,4,104,0,14,238,95,205,247,166,113,0,8,208,0,236,115,141,216,174,222,183,186,103,166,113,0,8,208,
0,236,105,180,113,92,94,61,222,117,3,192,47,66,0,14,126,157,248,196,234,252,28,168,237,76,8,248,197,8,0,123,92,39,182,170,247,168,30,230,218,1,224,151,32,0,251,27,51,160,63,165,169,15,26,64,128,6,128,
61,172,207,247,31,83,221,174,169,141,195,245,3,16,160,1,224,2,198,98,194,43,154,122,161,93,63,0,1,26,0,14,16,162,171,62,189,186,44,51,161,1,1,26,0,246,189,94,108,85,247,174,62,164,169,23,122,221,97,1,
4,104,0,78,146,173,19,246,245,140,5,132,95,184,244,58,128,0,13,192,137,176,113,194,190,158,245,57,52,63,170,122,239,84,161,1,1,26,0,246,181,57,135,230,47,72,5,26,16,160,1,96,95,163,10,253,248,234,30,77,
109,38,174,37,128,0,13,0,23,48,70,218,221,160,250,119,115,152,182,181,55,32,64,3,192,30,70,21,250,147,171,59,166,10,13,8,208,0,176,167,181,57,52,223,168,250,247,169,66,3,2,52,0,28,232,250,177,221,180,
177,202,157,83,133,6,4,104,0,216,211,232,133,190,81,245,21,169,66,3,2,52,0,236,107,189,169,242,252,201,213,187,165,10,13,8,208,0,176,167,181,166,202,243,245,171,175,77,21,26,16,160,1,224,64,215,145,173,
166,185,208,15,105,103,163,21,0,1,26,0,118,49,170,208,231,170,111,112,56,0,1,26,0,246,183,222,84,121,126,68,245,184,84,161,1,1,26,0,246,53,42,209,223,220,52,153,67,63,52,32,64,3,192,62,215,147,173,234,
110,213,23,103,34,7,32,64,3,192,129,67,244,151,84,119,17,162,1,1,26,0,246,54,218,56,110,82,125,107,218,56,0,1,26,0,246,53,22,20,126,76,245,81,89,80,8,8,208,0,176,175,81,137,254,239,77,213,104,149,104,
64,128,6,128,125,174,45,91,213,93,171,255,52,191,172,10,13,8,208,0,176,207,245,101,179,250,162,234,125,171,13,33,26,16,160,1,224,194,214,230,219,122,245,253,213,229,11,143,3,8,208,0,112,129,107,204,102,
117,191,234,63,206,47,187,238,0,2,52,0,28,32,68,127,121,245,128,76,229,0,4,104,0,216,211,104,217,184,94,245,195,243,253,226,227,0,2,52,0,44,89,111,90,68,120,255,166,169,28,170,208,128,0,13,0,7,8,209,155,
213,151,86,15,205,84,14,64,128,6,128,61,45,78,229,248,145,166,13,86,198,227,0,2,52,0,92,224,154,179,81,189,91,245,109,105,229,0,4,104,0,216,215,249,57,68,127,122,245,241,105,229,0,4,104,0,14,209,214,25,
253,127,173,207,255,183,239,169,238,152,249,208,128,0,13,192,33,217,60,163,255,175,181,106,187,186,69,245,228,249,90,52,122,164,1,4,104,0,216,197,152,202,241,1,213,215,164,31,26,16,160,1,224,64,215,160,
205,234,171,170,15,78,63,52,32,64,3,192,158,22,219,54,126,172,186,109,83,111,180,107,19,32,64,3,192,30,215,161,173,234,93,154,250,161,183,219,233,137,6,16,160,1,96,23,99,171,239,15,173,254,115,90,57,0,
1,26,0,14,20,162,55,171,175,174,30,51,135,232,243,14,11,32,64,3,192,238,70,63,244,118,83,63,244,157,230,16,237,58,5,8,208,0,176,199,53,105,171,186,85,245,63,170,203,22,194,53,128,0,13,0,187,24,253,208,
239,87,125,231,28,168,245,67,3,2,52,0,236,225,252,28,162,255,109,245,153,233,135,6,4,104,0,216,215,122,83,245,249,187,170,247,205,100,14,64,128,6,128,61,141,190,231,203,171,167,102,147,21,64,128,6,128,
3,93,163,54,155,38,114,252,143,118,54,88,177,168,16,16,160,1,224,2,198,162,194,71,54,45,42,220,76,43,7,32,64,3,192,158,198,162,194,207,105,90,88,104,81,33,32,64,3,192,62,198,78,133,223,85,61,34,139,10,
1,1,26,0,246,52,122,159,207,87,63,83,221,101,14,212,174,99,128,0,13,0,123,92,179,54,171,219,84,79,175,110,180,16,174,1,4,104,0,218,116,8,174,97,44,42,124,64,245,228,118,118,42,20,162,1,1,26,128,182,28,
130,93,141,69,133,31,87,125,125,250,161,1,1,26,0,246,53,42,209,95,89,125,74,38,115,0,2,52,0,236,105,173,157,201,28,63,80,189,127,42,209,128,0,13,0,251,134,232,181,234,122,213,207,86,119,205,70,43,128,
0,13,0,251,94,199,54,171,91,87,207,168,110,218,212,59,238,250,6,8,208,0,112,1,163,149,227,190,213,83,218,169,76,155,204,1,8,208,0,176,71,136,222,168,30,91,125,71,90,57,0,1,26,0,246,53,198,219,125,94,245,
239,51,153,3,16,160,1,96,95,163,157,227,191,53,205,137,22,162,1,1,26,0,246,48,122,159,183,170,159,168,222,55,227,237,0,1,26,0,14,116,109,187,65,245,63,171,187,52,85,165,93,243,0,1,26,0,246,184,190,109,
86,183,175,158,89,221,60,227,237,0,1,26,0,246,52,38,115,220,183,122,90,117,217,252,184,241,118,128,0,13,0,23,48,38,115,124,96,245,99,77,85,232,117,33,26,16,160,1,96,255,16,253,175,171,111,202,162,66,64,
128,6,128,125,141,118,142,47,171,62,55,227,237,0,1,26,224,76,218,112,8,14,205,90,59,51,162,191,187,250,88,33,26,16,160,1,206,158,45,135,224,208,67,244,185,249,184,254,100,245,208,180,115,0,2,52,0,236,
27,162,171,110,216,52,35,250,158,77,85,105,33,26,16,160,1,96,143,107,223,102,117,155,166,25,209,183,200,70,43,128,0,13,0,123,26,253,208,247,170,158,94,93,62,63,110,188,29,32,64,3,192,30,33,122,163,122,
100,245,83,237,236,84,40,68,3,2,52,0,92,192,152,17,253,113,77,211,57,244,67,3,2,52,0,28,48,68,127,110,245,213,25,111,7,8,208,0,176,175,209,206,241,159,171,207,18,162,1,1,26,0,246,182,184,209,202,247,86,
31,35,68,3,2,52,0,236,31,162,199,34,194,159,170,30,46,68,3,2,52,0,236,31,162,183,171,27,84,63,87,189,71,118,43,4,4,104,0,216,247,218,184,89,221,178,250,249,234,14,217,104,5,16,160,1,96,79,163,31,250,110,
77,187,21,94,209,206,156,104,64,128,6,0,46,16,162,55,170,247,174,158,86,93,54,63,110,163,21,16,160,1,128,11,24,51,162,63,164,122,114,118,43,4,4,104,0,56,112,136,126,66,245,173,237,236,86,40,68,131,0,13,
192,9,179,225,16,156,184,16,253,197,213,151,102,50,7,8,208,0,156,72,219,14,193,137,50,122,162,191,185,122,82,102,68,131,0,13,0,236,105,113,183,194,31,174,62,92,136,6,1,26,0,216,63,68,143,29,11,127,166,
122,176,16,13,2,52,0,176,255,181,115,187,186,113,211,140,232,123,166,39,26,4,104,0,96,223,235,231,102,117,187,166,221,10,111,147,221,10,65,128,6,0,246,52,250,161,223,189,122,70,117,163,249,113,227,237,
64,128,6,0,246,8,209,27,213,251,85,63,158,141,86,64,128,6,0,246,53,102,68,63,174,250,206,108,180,2,2,52,0,112,224,16,253,249,213,151,101,81,33,8,208,0,192,190,70,79,244,55,85,79,204,120,59,16,160,1,128,
61,141,249,208,91,77,27,173,124,128,16,13,2,52,0,176,127,136,174,186,188,250,217,234,62,105,231,0,1,26,0,216,247,218,186,85,221,162,105,70,244,237,50,35,26,4,104,0,96,223,235,235,102,117,215,234,233,213,
245,93,119,65,128,6,0,246,54,102,68,63,164,122,114,83,85,122,45,227,237,64,128,6,0,46,104,140,183,251,248,166,233,28,99,70,52,32,64,3,112,4,174,114,8,206,84,136,254,178,234,179,230,151,47,115,88,64,128,
6,224,240,109,59,4,103,198,152,17,253,61,213,163,231,39,71,42,209,32,64,3,0,23,48,122,159,207,85,63,93,189,103,218,57,64,128,6,0,246,189,230,110,85,87,86,207,172,110,157,241,118,32,64,3,0,123,26,173,28,
119,173,158,214,180,225,138,201,28,32,64,3,0,251,132,232,141,234,17,213,247,181,211,202,33,68,131,0,13,192,41,176,57,223,182,178,104,241,56,141,201,28,159,86,125,121,182,251,6,1,26,128,83,99,125,190,157,
107,167,2,186,57,7,186,77,161,250,200,143,253,70,245,141,213,227,230,151,207,59,44,112,58,158,1,3,176,154,54,170,223,157,131,243,109,171,155,87,183,232,154,149,208,173,118,118,209,91,12,218,92,55,107,
243,177,222,106,218,169,240,197,213,31,183,211,39,13,8,208,0,156,16,219,115,120,123,75,245,248,234,85,243,245,224,202,234,46,213,221,171,7,87,247,175,238,91,221,172,171,255,197,114,132,59,97,250,112,66,
244,118,117,227,234,233,77,219,126,191,162,157,137,29,0,0,28,192,40,110,124,249,28,174,174,154,239,15,235,54,250,157,223,88,221,177,189,167,64,220,170,105,227,143,111,172,126,191,122,199,210,199,218,152,
111,91,135,252,53,174,218,109,99,190,127,246,252,253,247,228,4,0,224,132,6,232,119,157,63,215,152,2,49,122,162,207,95,32,192,221,163,250,140,234,231,171,215,10,211,135,122,27,223,231,31,92,58,15,0,0,56,
129,1,250,66,139,202,23,67,245,178,219,87,159,84,253,92,245,186,93,194,224,166,80,124,173,67,244,23,10,209,0,0,167,51,64,47,59,215,78,139,193,162,59,84,255,166,250,181,234,237,75,159,75,85,250,226,190,
55,99,2,202,7,207,199,214,120,59,0,128,83,28,160,23,141,234,244,242,251,222,171,250,202,234,207,186,102,139,135,170,244,254,183,49,151,251,85,213,221,174,195,247,7,0,64,128,62,97,1,122,209,185,174,185,
155,222,122,245,168,234,71,170,87,167,42,125,109,22,21,62,183,186,81,22,21,194,137,226,25,45,192,201,117,154,54,49,217,106,167,186,60,218,60,54,171,223,172,62,189,105,28,222,23,54,205,57,94,91,8,219,35,
72,115,117,99,147,149,251,207,79,64,182,210,202,1,0,112,65,163,2,253,239,59,218,10,244,63,55,45,4,172,163,41,168,236,182,0,113,189,250,144,234,103,171,183,166,189,227,160,139,10,191,98,233,220,0,0,224,
12,6,232,229,48,189,28,254,238,89,125,93,211,14,124,139,253,191,27,130,243,174,237,46,143,94,120,18,2,0,192,25,15,208,139,65,122,121,225,225,149,213,103,87,127,146,62,233,189,22,21,190,186,186,235,49,
127,191,128,93,248,1,4,224,56,45,6,194,209,43,253,250,234,251,170,7,86,143,173,126,181,171,247,73,143,214,142,85,190,86,111,85,183,172,158,90,93,127,225,201,8,32,64,3,176,66,70,149,121,132,229,205,234,
127,87,31,86,61,162,122,122,83,245,125,113,193,225,170,6,233,177,168,240,65,213,247,102,81,33,0,192,213,156,229,22,142,189,44,86,157,135,251,86,63,220,213,23,28,94,213,234,182,118,140,115,225,243,151,
206,21,0,0,1,122,5,3,244,162,229,233,29,239,94,125,103,245,134,174,62,185,99,213,130,244,168,218,95,85,61,108,225,88,1,199,72,11,7,0,39,209,230,124,27,27,180,252,117,245,5,213,123,47,4,233,85,236,145,
94,107,103,162,201,83,170,91,207,161,90,63,52,8,208,0,80,237,108,208,50,130,244,11,155,54,100,25,65,250,95,150,130,244,170,92,187,55,171,59,85,63,54,63,121,88,23,162,65,128,6,224,232,141,182,128,211,22,
164,207,87,127,55,7,233,7,84,223,95,189,189,157,86,134,85,8,210,99,81,225,135,87,255,223,252,178,86,14,0,96,101,29,87,15,244,171,171,219,204,159,235,180,85,47,207,45,5,198,123,55,85,99,71,59,199,42,108,
200,178,181,240,127,252,176,133,96,13,28,195,47,32,0,56,109,150,91,59,254,178,250,212,234,125,170,103,46,60,62,102,78,159,69,163,31,122,187,122,114,245,174,11,199,4,16,160,1,224,64,65,250,143,170,143,
169,62,184,250,237,118,118,61,60,171,51,164,199,38,43,183,105,90,84,184,190,16,172,1,1,26,0,14,20,164,207,85,207,170,30,89,61,161,169,58,125,190,179,187,25,203,232,135,126,255,234,235,230,227,160,149,
3,0,88,41,122,160,15,39,84,142,255,211,141,170,47,169,94,217,213,103,72,159,181,126,232,113,158,60,122,225,24,0,71,64,5,26,128,179,104,44,38,92,175,222,92,125,75,211,232,187,239,109,167,66,123,150,250,
163,215,230,107,250,118,245,35,77,27,228,108,185,206,131,0,13,176,106,182,28,130,67,9,210,99,227,145,151,87,159,91,189,95,245,107,157,189,254,232,209,15,125,187,234,71,231,255,147,126,104,16,160,1,86,
46,252,37,0,93,103,163,101,99,109,14,205,127,88,125,104,245,175,155,230,73,143,254,232,179,48,63,122,244,67,127,104,245,31,211,15,13,0,172,136,209,3,253,5,29,77,191,238,42,244,64,239,229,220,194,255,247,
202,234,155,171,119,44,28,235,173,206,198,124,232,177,176,48,33,26,14,255,151,8,0,171,105,76,174,88,197,255,247,232,143,126,125,245,101,213,251,86,191,218,217,216,22,124,180,109,172,55,205,135,190,178,
157,118,14,64,128,6,224,58,56,77,91,121,31,133,205,133,160,249,220,166,221,252,62,163,105,90,199,122,59,213,220,211,122,125,223,172,238,82,125,87,22,20,130,0,13,0,135,248,36,98,113,126,244,15,87,15,170,
126,188,157,201,22,27,167,244,255,54,250,161,63,169,122,226,252,255,60,239,91,14,2,52,0,28,134,173,249,182,94,189,172,122,82,245,216,234,111,230,208,121,90,171,209,235,243,215,253,93,213,93,231,64,237,
218,15,2,52,0,28,154,197,182,142,255,93,189,79,245,221,157,222,106,244,218,28,254,175,104,26,109,103,171,111,16,160,1,224,208,141,182,142,177,200,240,243,155,198,194,189,160,169,26,61,170,213,167,197,
104,229,120,68,70,219,1,0,103,212,113,141,177,123,101,117,139,249,115,169,72,238,110,109,33,108,94,217,180,147,225,105,220,14,124,140,182,187,170,169,170,158,16,13,215,158,10,52,0,92,216,114,53,250,115,
170,143,170,254,190,157,237,192,79,195,36,147,209,182,113,190,250,161,234,6,158,56,129,0,13,0,71,105,177,55,250,127,53,205,141,126,106,167,107,110,244,232,225,126,207,234,235,210,202,1,0,156,33,199,213,
194,241,138,234,230,243,231,82,137,60,184,197,208,249,153,213,27,230,227,121,85,167,167,149,99,171,122,228,46,255,31,224,128,207,70,1,88,45,163,229,224,180,45,134,59,41,70,53,250,92,245,131,213,67,171,
231,180,179,192,240,36,183,116,172,45,220,126,168,186,73,118,41,4,1,26,0,142,233,73,200,214,28,154,255,162,250,128,166,113,119,231,230,48,122,146,159,152,140,93,10,239,94,253,215,118,230,95,3,0,156,90,
71,221,194,49,22,190,189,188,105,178,68,169,64,94,215,64,58,60,161,250,231,78,126,75,199,214,194,121,245,161,243,215,46,68,195,181,248,161,7,0,46,222,86,59,11,12,127,186,122,120,245,220,249,137,208,73,
157,210,49,218,56,182,171,239,169,110,156,86,14,16,160,1,206,128,77,135,224,212,24,149,253,243,213,243,155,22,232,61,165,157,170,238,73,12,209,231,230,240,127,183,234,235,231,151,229,2,0,224,84,26,45,
28,255,54,45,28,167,209,98,8,253,15,237,44,44,60,169,27,175,108,204,183,135,207,95,179,86,14,184,136,31,114,0,224,186,91,108,233,248,111,77,27,175,188,174,157,45,181,79,154,241,181,126,95,54,88,1,1,26,
0,46,145,197,150,142,95,104,106,233,248,235,249,245,147,22,162,199,84,142,247,168,190,42,27,172,128,0,13,0,151,208,198,28,154,159,87,61,172,122,214,9,15,209,95,82,189,215,252,245,9,209,32,64,3,176,100,
43,11,21,143,43,68,175,87,175,173,30,211,180,184,240,252,9,59,246,163,101,227,178,234,187,228,3,16,160,1,216,221,88,68,198,209,219,156,175,185,239,168,158,88,125,203,28,170,79,210,152,187,241,245,60,172,
250,140,180,114,0,0,167,200,113,77,225,120,105,211,252,223,178,104,236,184,172,45,132,210,47,89,248,126,108,117,50,38,114,108,206,183,215,86,183,111,103,203,114,96,129,31,10,0,56,62,139,91,128,127,75,
245,217,11,215,226,147,80,137,62,55,127,29,55,111,218,230,219,230,42,32,64,3,192,137,8,209,99,113,225,247,55,181,116,108,205,255,182,117,2,190,190,209,202,241,175,171,15,73,43,7,8,208,0,112,66,140,16,
253,148,57,172,110,47,4,236,75,109,84,157,191,173,186,126,42,209,32,64,3,192,9,11,209,63,83,125,210,28,82,79,194,226,206,49,214,238,222,213,231,53,85,198,85,161,65,128,6,128,19,21,162,255,71,245,201,243,
181,121,235,132,132,232,173,234,43,171,59,180,51,73,4,4,104,135,0,0,78,68,136,190,172,169,157,227,115,155,170,189,151,58,68,143,106,248,149,213,55,166,141,3,4,104,0,56,97,174,106,170,68,127,111,245,255,
181,179,152,239,82,26,95,195,19,170,247,207,130,66,16,160,1,86,220,102,118,34,60,105,70,59,199,215,85,223,221,201,217,246,251,92,245,173,115,120,86,137,70,128,118,8,0,224,196,61,177,89,175,62,191,250,
197,19,16,162,71,21,250,129,237,140,220,147,31,16,160,1,56,177,65,138,213,51,166,112,172,53,141,183,123,222,28,162,47,229,249,48,250,161,191,166,186,73,170,208,8,208,0,156,80,91,14,193,74,127,239,215,
170,55,84,31,91,189,170,157,169,24,151,42,47,108,85,119,170,254,93,170,208,8,208,0,192,9,13,209,231,171,191,107,170,68,215,165,157,17,61,66,244,23,87,239,42,68,35,64,3,0,39,209,88,84,248,172,234,203,186,
180,147,57,70,27,199,21,213,127,74,27,7,0,112,130,156,159,239,63,125,14,41,27,237,84,30,15,227,182,57,223,255,125,117,131,133,112,196,201,180,182,112,78,60,245,136,206,137,131,222,182,230,243,231,170,
234,126,243,215,102,172,29,43,71,5,26,0,78,182,17,92,207,85,159,81,253,101,59,27,173,92,138,48,191,61,7,250,81,133,6,1,26,0,56,113,198,162,194,127,105,26,37,247,246,46,93,63,244,8,239,31,85,189,95,54,
87,65,128,6,96,197,66,153,73,31,167,199,102,83,229,247,185,213,151,118,105,251,161,183,231,12,241,181,190,45,8,208,0,172,146,109,1,250,212,25,139,10,191,179,122,102,151,110,62,244,168,66,127,112,245,65,
169,66,35,64,3,0,39,216,104,231,248,172,234,229,93,186,249,208,163,125,228,107,231,175,65,63,52,2,52,0,112,98,3,244,185,166,205,85,62,167,157,133,125,199,109,84,161,31,82,61,122,126,89,21,26,1,26,0,56,
145,70,203,196,255,170,126,116,126,121,227,18,124,29,35,184,127,197,37,12,242,32,64,3,0,7,14,175,231,154,118,6,252,251,46,205,104,187,241,57,31,90,125,72,170,208,8,208,0,192,9,54,122,161,223,80,125,118,
59,21,224,227,174,2,47,86,161,75,21,26,1,26,0,56,193,198,104,187,95,173,158,220,165,173,66,63,162,250,192,84,161,17,160,1,128,19,110,44,42,252,178,234,149,93,154,137,24,227,243,125,249,210,235,32,64,3,
0,39,50,64,175,53,77,229,248,146,249,229,75,85,133,126,84,245,62,169,66,35,64,3,112,137,108,28,195,199,183,145,202,217,48,166,114,60,165,250,149,46,205,46,133,163,18,254,239,124,59,16,160,1,184,84,142,
35,220,250,83,251,217,49,190,151,95,92,189,173,227,31,43,183,62,127,190,143,170,238,185,16,168,65,128,6,0,78,236,19,174,243,213,95,85,223,62,95,227,143,179,10,189,54,127,190,235,87,159,55,135,233,53,223,
22,4,104,0,224,36,219,156,175,237,223,88,189,164,227,159,202,49,170,208,79,172,110,155,42,52,2,52,0,112,194,141,170,239,27,155,166,114,28,119,27,199,168,66,95,89,61,169,157,205,94,64,128,6,0,78,172,81,
133,254,153,234,217,29,255,130,194,145,45,62,189,169,157,99,211,183,4,1,26,0,56,233,70,239,241,151,183,51,230,238,56,179,197,86,117,247,234,195,155,170,208,70,218,33,64,3,0,39,218,24,107,247,123,213,211,
58,254,5,133,99,75,241,207,94,120,29,4,104,0,224,68,27,253,208,95,93,189,185,227,237,135,30,21,231,71,86,247,203,198,42,8,208,0,156,161,128,165,50,120,118,141,9,24,47,172,190,191,157,214,138,227,178,217,
52,86,239,51,124,43,16,160,1,56,75,1,107,123,33,76,115,54,159,36,173,85,223,82,253,243,124,221,63,174,239,245,200,24,31,215,52,149,99,51,115,161,17,160,1,128,83,240,36,233,92,245,79,213,119,206,1,246,
184,170,208,163,239,250,54,213,99,231,199,180,113,32,64,3,0,167,34,68,175,85,223,85,189,178,227,111,229,168,105,38,116,151,224,243,130,0,13,0,92,180,177,153,201,63,87,223,218,241,47,38,220,174,30,94,189,
71,22,19,34,64,3,0,167,196,168,66,255,96,245,242,142,183,23,122,179,186,172,250,164,249,117,125,208,8,208,0,192,137,55,170,208,111,172,190,163,227,239,133,174,122,124,211,206,132,27,66,52,2,52,0,112,26,
140,42,244,15,119,188,189,208,227,243,220,173,122,152,252,129,0,13,192,81,216,94,8,60,112,152,231,213,185,234,117,213,119,119,188,189,208,99,100,226,199,251,54,32,64,3,112,148,54,29,2,142,32,68,175,85,
63,80,189,186,227,235,133,94,159,63,239,71,84,87,100,38,52,2,52,0,167,212,168,112,11,50,171,245,61,63,87,189,166,250,145,249,123,127,28,79,212,70,207,245,109,171,15,146,65,16,160,1,56,173,236,62,184,186,
223,247,181,234,251,170,55,183,51,106,238,56,194,251,118,245,175,156,127,8,208,0,192,105,50,170,208,47,173,158,218,241,85,161,71,27,199,163,170,155,181,179,168,17,4,104,0,224,84,88,107,26,105,119,85,199,
83,133,30,109,28,183,172,30,57,191,46,135,32,64,3,0,167,194,88,196,247,231,213,47,119,124,115,161,199,231,248,232,180,112,32,64,3,0,167,204,104,159,248,238,165,215,143,35,119,124,80,117,227,76,227,64,
128,6,0,78,145,17,94,127,171,250,211,142,167,10,61,54,85,185,125,54,85,65,128,6,0,78,161,245,166,173,181,191,191,227,219,88,101,132,244,15,159,239,85,160,17,160,1,128,83,99,84,161,159,214,180,189,247,
113,44,38,28,217,227,3,170,243,115,128,7,1,26,128,83,193,34,46,22,183,247,254,169,133,80,125,148,70,165,251,94,243,77,30,65,128,6,224,212,80,249,99,241,137,212,147,231,115,226,168,171,208,99,238,244,122,
211,76,104,121,4,1,26,0,56,85,198,198,42,127,81,253,118,199,179,152,112,244,61,127,200,194,215,0,2,52,0,112,234,242,192,15,31,243,231,123,159,234,230,217,149,16,1,26,0,56,101,70,223,243,47,84,255,208,
212,94,113,148,85,225,209,7,125,139,234,1,50,9,2,52,0,112,218,108,207,161,249,205,213,83,231,199,142,186,173,98,132,246,247,95,8,213,32,64,3,112,157,67,13,28,247,249,246,211,237,44,242,59,234,197,132,
85,15,95,10,212,32,64,3,112,173,153,146,193,113,26,125,200,127,90,253,65,71,191,152,112,100,144,251,85,183,158,195,186,42,52,2,52,0,112,170,172,207,247,79,57,134,207,53,2,250,205,170,251,203,37,8,208,
0,192,105,52,42,206,207,168,222,208,209,183,113,140,207,247,126,11,161,26,4,104,0,78,124,88,130,197,115,98,189,122,69,245,107,115,120,62,202,222,228,17,152,31,228,156,68,128,6,224,36,27,21,69,139,182,
216,43,216,62,117,190,63,202,172,176,216,7,125,195,204,131,70,128,6,0,78,161,173,249,73,214,111,84,175,156,179,194,81,181,113,140,121,208,183,173,222,77,54,65,128,6,0,78,163,49,19,250,13,213,47,117,244,
109,28,99,100,222,123,47,132,106,16,160,1,128,83,233,105,29,125,27,199,240,32,135,27,1,26,0,56,173,198,98,190,103,87,47,153,243,194,81,45,240,27,21,231,123,207,247,122,243,17,160,1,128,83,103,180,113,
188,181,250,229,165,80,125,84,89,228,221,170,155,102,67,21,4,104,0,224,148,123,230,17,103,134,177,144,240,150,213,221,23,30,3,1,26,0,56,85,70,197,249,119,170,151,119,180,211,56,54,231,208,124,111,249,
4,1,26,0,56,173,70,27,199,155,171,95,89,8,186,71,233,126,14,59,2,52,0,39,217,85,14,1,7,176,86,253,252,17,231,134,209,178,113,175,249,222,142,132,8,208,0,192,169,52,54,85,249,157,234,53,29,93,27,199,8,
208,119,174,206,103,71,66,4,104,0,224,148,218,158,179,194,235,170,255,187,16,170,143,42,64,223,177,186,133,195,142,0,13,0,156,246,172,176,214,180,43,225,81,25,1,250,38,213,157,150,30,3,1,26,128,3,211,
163,204,73,48,218,56,126,163,122,91,211,194,194,163,104,227,24,11,20,239,41,163,32,64,3,112,109,109,59,4,156,144,0,189,86,189,184,250,227,133,199,142,234,124,191,171,67,142,0,13,0,156,118,163,234,252,
172,99,120,114,119,103,79,32,17,160,1,128,211,110,132,217,223,92,8,212,135,109,244,60,223,69,128,70,128,6,0,78,187,209,178,241,220,166,93,9,215,58,252,54,142,17,160,111,87,93,150,81,118,8,208,0,156,224,
80,4,251,25,187,18,190,169,250,221,35,58,127,70,88,190,117,59,163,236,4,104,4,104,0,78,148,13,33,133,107,17,112,127,253,136,63,254,149,213,45,29,110,4,104,0,224,180,27,21,231,223,153,159,124,157,239,240,
251,148,71,219,198,109,61,185,67,128,6,0,78,187,17,150,255,182,122,225,210,99,135,253,57,110,231,112,35,64,3,0,103,33,64,175,55,85,159,127,111,126,108,235,8,62,199,98,128,86,129,70,128,6,0,78,181,17,104,
127,251,136,3,174,10,52,2,52,0,112,38,140,138,243,115,154,182,154,95,63,162,207,51,2,180,89,208,8,208,0,192,169,54,2,237,11,219,233,131,62,204,54,142,197,81,118,135,253,177,65,128,6,0,46,73,128,94,175,
54,171,63,60,194,0,125,243,165,192,14,2,52,0,112,106,141,144,251,156,165,215,15,211,21,77,187,17,30,213,199,7,1,26,128,107,101,211,33,224,90,24,21,231,63,104,167,34,125,216,225,252,134,213,77,28,106,4,
104,0,78,106,16,130,139,49,218,42,94,80,253,227,17,157,75,139,1,90,5,26,1,26,128,3,83,33,230,164,6,232,115,213,155,170,231,45,133,234,195,114,131,234,166,14,53,2,52,0,23,75,133,152,147,158,31,254,240,
144,3,244,90,59,109,33,55,92,120,12,4,104,0,224,76,248,147,35,200,19,227,137,227,13,28,94,4,104,0,224,172,24,33,247,207,155,54,84,57,215,225,183,113,88,68,136,0,13,0,156,25,35,44,255,67,245,247,75,143,
9,208,8,208,0,0,187,4,232,245,234,29,213,243,143,40,64,223,120,190,215,3,141,0,13,0,156,9,35,216,254,201,17,7,104,16,160,1,56,49,108,147,204,97,248,139,165,64,125,88,231,229,245,29,90,4,104,0,78,154,13,
135,128,235,96,44,36,124,65,211,204,242,245,67,126,82,118,61,135,24,1,26,0,56,75,70,88,126,113,245,202,35,248,248,2,52,2,52,0,112,230,2,244,90,245,150,234,111,230,199,14,115,243,159,203,29,98,4,104,0,
224,172,89,159,239,95,176,16,170,15,139,10,52,2,52,0,112,102,253,213,17,124,204,243,14,43,2,52,0,112,214,140,138,243,11,228,10,4,104,0,128,131,7,232,151,52,109,170,114,152,91,122,171,64,35,64,3,0,103,
54,64,255,67,245,218,165,199,174,43,59,16,34,64,3,0,103,50,64,175,85,111,110,26,103,119,152,1,26,4,104,0,174,85,56,129,211,146,37,4,104,4,104,0,46,185,205,35,254,248,87,57,196,28,130,209,106,241,18,135,
2,1,26,0,224,224,254,126,41,80,123,130,135,0,13,0,176,139,209,178,241,162,67,14,208,27,14,45,2,52,0,112,150,3,244,203,231,208,123,88,217,226,109,14,45,2,52,0,112,150,3,244,107,171,215,47,61,118,93,188,
201,161,69,128,6,0,206,178,215,29,114,128,126,179,67,138,0,13,0,156,69,99,22,244,85,213,171,15,33,64,143,30,234,55,58,180,8,208,0,192,89,207,19,47,63,196,143,249,207,135,16,198,65,128,6,0,78,180,151,31,
98,232,125,157,195,137,0,13,0,156,85,163,237,226,159,14,49,155,188,193,97,69,128,6,0,206,186,215,44,5,234,139,53,250,169,223,222,225,46,72,4,1,26,128,67,177,229,16,112,72,182,15,41,64,15,111,106,167,2,
45,64,35,64,3,112,98,108,58,4,28,178,195,168,64,87,253,75,122,160,17,160,1,128,51,236,176,43,208,175,174,222,177,244,177,65,128,6,0,206,156,55,85,111,189,14,193,119,188,207,43,228,20,4,104,0,224,44,27,
193,247,109,93,183,29,4,199,199,121,185,156,130,0,13,0,172,130,183,85,111,89,10,195,215,198,75,29,74,4,104,0,174,141,177,200,111,205,161,224,148,120,251,66,128,190,54,214,4,104,4,104,0,174,11,139,167,
56,109,231,234,59,174,99,128,30,185,228,37,126,6,16,160,1,128,85,201,20,215,118,17,225,216,68,229,173,29,238,150,224,32,64,3,0,39,210,104,191,120,251,181,124,255,197,9,28,255,36,64,35,64,3,0,171,226,186,
6,232,127,108,170,66,159,19,160,17,160,1,128,85,240,182,235,248,254,127,59,223,91,60,139,0,13,192,137,179,33,168,112,130,2,244,168,54,191,208,121,137,0,13,192,73,229,207,227,28,133,119,92,203,247,27,129,
249,239,156,159,8,208,0,0,7,207,36,127,43,64,35,64,3,0,171,100,251,90,190,207,90,245,218,234,197,2,52,2,52,0,176,74,54,174,69,0,222,154,239,95,84,189,110,14,211,2,52,2,52,0,192,5,140,176,252,55,243,203,
242,9,2,52,0,176,114,217,226,218,76,209,120,222,117,120,95,16,160,1,128,83,233,122,215,33,143,252,149,195,135,0,13,0,8,208,123,27,45,27,27,77,45,28,181,211,19,13,2,52,0,32,64,239,18,160,171,94,94,189,
100,233,49,16,160,1,0,1,250,2,1,250,249,77,187,24,158,19,160,17,160,1,184,182,198,159,177,143,106,65,149,144,194,81,156,79,215,191,150,239,247,103,178,9,2,52,0,135,21,160,143,42,232,92,229,16,115,4,231,
213,141,46,242,253,198,19,196,63,246,196,14,1,26,0,88,21,99,227,147,243,213,13,151,130,241,126,161,123,125,126,50,247,151,2,52,2,52,0,176,106,110,176,16,160,15,98,113,1,225,139,4,104,4,104,0,96,213,92,
191,139,175,64,215,180,128,240,237,89,64,136,0,13,0,172,136,17,150,111,80,221,228,34,222,111,132,229,231,202,37,8,208,0,192,42,186,89,59,83,56,14,82,129,30,57,228,247,151,2,53,8,208,0,192,153,54,194,242,
173,231,251,131,76,144,25,59,16,190,185,122,158,0,141,0,13,0,172,114,128,62,72,16,30,111,243,55,77,139,8,215,178,133,55,2,52,0,176,98,46,38,64,143,176,252,199,243,203,50,9,2,52,0,176,114,110,127,17,111,
59,170,214,191,191,244,58,8,208,0,192,153,55,170,201,119,190,136,48,188,222,84,169,254,163,165,143,1,2,52,0,39,62,244,192,117,53,90,54,238,116,192,0,61,206,189,151,85,127,187,244,49,64,128,6,224,196,218,
116,8,56,4,99,27,239,27,86,183,185,200,192,253,220,166,41,28,54,80,65,128,6,0,86,42,64,215,180,128,240,150,75,143,237,23,160,159,45,143,32,64,3,0,171,26,160,239,208,84,133,222,58,64,128,94,159,239,159,
179,20,168,65,128,6,0,86,38,64,191,219,1,195,240,246,252,62,175,168,254,124,126,76,63,62,2,52,0,135,66,85,142,211,228,160,1,122,132,229,231,86,255,146,254,103,4,104,0,14,145,69,126,156,6,91,75,1,250,160,
79,12,127,71,22,65,128,6,0,86,205,216,126,123,189,186,215,1,179,197,248,247,223,93,10,212,32,64,3,0,43,17,160,107,90,64,248,46,75,143,237,102,123,206,30,175,170,254,108,126,76,255,51,2,52,0,176,114,1,
250,110,29,108,2,199,8,203,191,95,189,33,253,207,8,208,0,192,138,6,232,251,46,5,228,11,25,97,249,255,200,33,8,208,0,192,42,26,129,248,1,7,124,251,245,57,100,63,123,233,253,65,128,6,224,84,216,112,8,184,
14,214,154,38,197,156,171,222,243,0,185,98,180,119,188,180,250,139,133,199,64,128,6,224,212,80,253,227,48,220,166,186,199,66,168,222,43,64,215,52,125,227,109,77,213,104,231,32,2,52,0,176,114,25,226,62,
213,141,218,127,1,225,248,183,223,58,64,216,6,1,26,0,56,115,70,0,126,224,124,191,95,59,198,122,117,85,59,27,168,104,223,64,128,6,0,86,202,8,192,239,179,20,168,247,122,219,191,170,94,56,191,173,246,13,
4,104,0,96,101,140,29,8,175,223,206,8,187,253,2,244,118,83,251,198,70,250,159,17,160,1,128,21,12,208,53,45,30,188,211,1,50,197,185,249,125,126,125,126,93,120,70,128,6,0,86,50,63,188,207,252,242,230,30,
111,59,182,239,254,231,234,57,243,99,250,159,17,160,1,128,149,50,42,200,15,93,122,125,55,139,219,119,191,54,219,119,35,64,3,0,43,104,179,58,95,61,248,0,121,98,132,229,95,151,61,16,160,1,128,85,206,14,
119,107,255,13,84,182,219,217,190,123,204,127,214,190,129,0,13,192,169,229,207,232,92,151,236,240,126,213,101,77,213,232,189,2,244,90,245,55,213,243,157,119,8,208,0,28,87,192,61,170,29,219,54,142,248,
227,115,182,207,203,71,28,32,16,143,106,243,111,52,109,162,114,94,128,70,128,6,224,40,109,58,4,156,48,107,243,121,121,89,245,144,3,100,137,241,111,191,124,128,176,13,2,52,0,112,38,3,116,213,189,170,187,
182,211,162,177,155,49,190,238,213,213,239,206,143,233,127,70,128,6,0,86,50,55,60,162,169,29,99,107,143,0,61,194,242,255,173,94,151,221,7,17,160,1,128,21,52,2,240,163,46,226,125,126,101,14,217,122,237,
17,160,1,128,149,50,250,159,111,218,52,129,99,175,28,49,198,215,189,173,105,1,225,118,218,55,16,160,1,128,21,205,12,15,170,110,211,193,218,55,254,164,250,251,249,237,4,104,4,104,0,96,165,140,176,252,193,
75,33,121,55,163,213,227,151,219,169,70,131,0,13,0,172,148,177,97,202,7,30,32,67,140,5,131,191,180,20,168,65,128,6,0,86,38,47,108,55,109,223,125,223,249,177,189,218,55,214,170,191,170,158,151,246,13,4,
104,0,96,133,243,194,7,86,151,55,237,98,185,95,255,243,47,55,237,62,104,124,29,2,52,0,103,134,157,14,57,168,17,138,63,98,190,95,59,64,182,248,197,249,94,120,70,128,6,224,204,133,34,216,203,104,193,184,
85,245,176,125,242,195,214,252,111,47,173,126,223,121,134,0,13,0,172,162,49,65,227,17,213,149,29,108,124,221,175,85,111,73,251,6,2,52,0,176,130,70,0,254,136,246,223,16,101,228,138,95,152,239,237,62,136,
0,13,0,172,148,177,251,224,141,154,182,239,94,107,239,221,7,207,85,255,84,253,246,252,152,62,123,4,104,0,96,37,115,194,131,171,119,109,167,199,121,55,155,115,136,254,245,234,13,105,223,64,128,6,0,86,216,
99,230,251,253,218,55,214,170,103,206,247,218,55,16,160,1,128,149,50,218,55,206,87,143,222,39,55,140,246,141,215,84,191,57,191,174,125,3,1,26,0,88,201,140,240,222,213,189,22,66,242,110,70,251,198,179,
170,215,165,125,3,1,26,0,88,65,163,5,227,35,219,169,70,239,245,182,107,213,51,210,190,129,0,13,0,172,104,120,222,108,170,36,127,228,62,153,97,123,126,187,127,78,251,6,2,52,0,103,156,63,177,179,87,62,216,
174,238,95,221,187,189,219,55,182,230,127,255,141,166,30,104,237,27,8,208,0,156,89,27,14,1,23,176,216,190,113,174,253,43,202,107,213,211,211,190,129,0,13,0,172,168,229,246,141,11,133,226,209,190,241,154,
166,5,132,218,55,16,160,1,128,149,204,6,219,213,125,171,247,92,8,201,23,10,218,219,213,175,54,245,64,107,223,64,128,6,0,86,54,27,124,84,251,183,111,140,205,83,126,214,97,67,128,6,0,86,209,226,230,41,31,
187,79,86,24,219,122,191,178,250,173,133,199,64,128,6,0,86,42,23,108,55,109,158,114,159,14,54,125,227,151,170,55,166,125,3,1,26,0,88,65,99,177,224,199,181,255,230,41,163,125,227,233,75,239,11,2,52,0,176,
50,225,121,163,186,94,245,209,251,228,132,209,190,241,210,234,183,231,199,76,223,64,128,6,224,146,243,231,112,46,69,38,120,72,117,247,133,144,124,161,0,93,245,204,234,45,77,61,211,206,87,4,104,0,46,121,
112,222,92,120,89,56,225,184,60,126,41,36,239,102,140,181,251,25,231,39,2,52,0,176,138,70,191,243,141,170,199,238,147,17,182,230,183,255,139,234,15,218,191,87,26,4,104,0,206,12,35,199,88,204,3,107,213,
7,84,119,232,96,237,27,79,111,234,153,94,119,248,16,160,1,88,21,27,14,1,11,182,171,79,152,239,247,122,114,117,126,62,119,158,238,137,24,2,52,0,176,170,89,96,179,186,85,245,225,77,149,232,189,182,238,174,
250,253,234,249,243,251,10,208,8,208,0,192,74,102,129,143,168,110,54,135,228,253,102,58,63,85,142,192,15,13,0,176,170,70,5,249,9,237,61,77,99,187,169,50,253,166,234,25,75,239,11,2,52,0,176,50,57,96,171,
105,238,243,195,155,42,207,23,202,6,99,172,226,175,85,47,159,195,180,0,141,0,13,0,172,100,14,120,92,211,14,132,123,181,111,172,205,183,167,100,219,110,252,224,0,0,43,106,179,169,146,252,241,251,188,221,
214,252,118,47,107,170,64,239,55,169,3,4,104,0,224,204,89,159,131,240,123,87,239,213,78,143,243,133,2,116,213,207,85,111,94,120,95,16,160,1,128,149,243,132,246,223,77,112,244,59,255,180,195,5,2,52,0,172,
162,197,173,187,31,183,16,146,119,51,250,162,255,172,250,195,108,221,13,2,52,0,172,160,245,57,8,127,88,59,91,119,239,183,48,240,39,219,233,133,6,1,26,128,149,100,43,239,213,181,61,223,158,56,191,190,181,
199,219,141,217,207,63,187,207,219,130,0,13,192,153,14,79,139,247,172,222,181,127,179,186,99,245,193,243,99,123,45,30,220,174,126,185,105,2,135,217,207,32,64,3,192,202,94,251,63,174,186,97,211,95,34,246,
155,253,252,100,135,13,4,104,0,88,85,99,246,243,191,94,8,201,187,217,154,115,194,11,171,223,156,223,78,245,25,4,104,0,88,41,99,126,243,3,171,7,116,176,217,207,79,173,222,150,217,207,32,64,3,192,10,26,
213,230,177,120,240,66,227,232,70,176,190,170,250,169,165,64,13,2,180,67,0,0,43,19,158,55,170,43,218,153,253,124,161,28,48,198,218,253,70,245,215,243,219,9,208,32,64,3,192,74,25,173,26,143,169,110,219,
84,125,62,183,71,216,174,250,145,165,215,1,1,26,0,86,198,168,32,63,169,189,123,153,199,226,193,151,86,191,180,244,190,128,0,13,0,43,115,189,223,170,222,173,122,255,125,50,192,8,215,63,85,189,165,58,159,
197,131,32,64,3,192,138,94,239,159,80,93,175,169,125,99,109,143,183,189,170,250,137,249,117,213,103,16,160,1,152,169,42,174,134,181,57,48,95,175,250,196,125,174,255,99,42,135,197,131,32,64,3,176,20,168,
106,154,200,192,217,55,230,55,63,170,186,71,59,61,206,123,157,31,63,44,39,128,0,13,0,171,106,252,165,225,83,230,251,11,85,148,183,230,176,253,162,118,22,15,110,58,124,32,64,3,192,42,25,237,27,239,210,
52,190,174,246,223,121,240,201,213,91,179,120,16,4,104,0,88,65,35,44,127,124,117,227,46,188,120,112,236,60,248,230,44,30,4,1,26,0,86,216,102,83,37,249,147,231,215,215,246,120,187,181,234,23,170,151,204,
97,90,128,6,1,26,224,212,217,72,15,42,215,222,168,62,63,180,186,95,83,149,249,220,62,121,224,7,28,54,16,160,1,96,149,109,55,237,60,216,30,79,198,198,150,222,207,173,158,221,78,223,52,32,64,3,192,202,24,
33,248,214,213,71,207,143,173,239,243,62,63,208,206,36,14,64,128,6,128,149,50,66,240,227,170,43,187,240,226,193,49,19,250,21,213,207,164,250,12,2,52,0,172,168,17,152,159,180,207,219,109,205,111,247,19,
213,27,230,92,96,116,29,8,208,0,176,82,198,206,131,15,174,30,212,206,136,186,221,156,111,154,249,252,67,243,235,194,51,8,208,0,176,178,158,212,222,45,25,227,241,95,168,254,110,206,4,70,215,129,0,13,0,
43,101,4,230,155,53,245,63,215,133,171,207,163,39,250,123,230,151,215,28,62,16,160,1,96,213,140,176,252,49,213,173,186,240,226,193,49,186,238,57,213,239,100,241,32,8,208,0,176,162,70,11,198,147,14,248,
246,223,209,206,66,66,64,128,6,128,149,50,182,223,126,175,234,33,93,120,241,224,24,93,247,194,234,153,115,120,214,251,12,2,52,0,172,156,81,69,254,148,57,56,95,168,37,99,84,156,191,167,122,91,59,83,59,
0,1,26,0,86,42,60,111,84,55,173,254,213,30,215,248,81,149,126,85,211,236,103,189,207,32,64,3,192,74,26,173,26,143,169,110,223,206,34,193,101,99,81,225,143,85,255,156,141,83,64,128,6,224,162,232,123,61,
123,223,203,79,221,35,16,143,234,243,91,170,239,159,131,180,240,12,2,52,0,23,193,159,238,207,206,181,124,171,186,119,245,136,61,174,239,163,247,249,167,171,23,103,227,20,16,160,1,96,197,175,229,159,84,
93,222,238,179,159,183,231,183,123,71,245,109,169,62,131,0,13,0,43,106,44,30,188,97,245,137,123,92,219,71,245,249,25,213,95,166,250,12,2,52,0,172,168,177,120,240,67,171,59,183,51,227,121,209,118,59,179,
158,191,213,33,3,1,26,0,86,217,168,34,127,218,210,235,139,198,68,142,95,173,254,112,126,89,255,59,8,208,0,176,146,215,240,173,234,238,213,7,117,225,157,7,199,168,186,111,154,95,183,109,55,8,208,0,176,
210,215,240,39,84,215,111,247,197,131,163,250,252,235,213,179,83,125,6,1,26,0,86,212,216,65,240,122,77,211,55,46,116,77,31,129,250,191,44,189,14,8,208,0,176,82,214,155,218,50,30,85,221,163,221,23,15,142,
234,243,179,82,125,6,1,26,0,86,220,88,44,248,233,243,253,110,51,157,71,181,249,235,151,94,7,4,104,0,88,185,107,247,86,117,199,166,241,117,187,93,207,71,245,249,215,170,223,78,245,25,4,104,0,112,237,238,
19,170,27,55,109,164,178,92,93,30,59,13,126,205,194,235,128,0,13,0,43,103,44,30,60,95,61,241,2,225,120,84,159,159,89,253,94,170,207,32,64,3,128,235,118,239,95,221,167,169,149,99,125,151,144,125,85,170,
207,32,64,3,0,213,212,154,241,169,243,203,203,59,15,110,204,215,246,255,81,61,111,14,215,170,207,32,64,3,192,202,94,179,55,171,219,85,31,57,63,182,190,20,172,207,85,111,170,190,182,157,62,104,64,128,6,
88,25,155,2,16,187,92,179,63,174,186,105,215,220,121,112,244,62,127,87,245,162,118,166,117,0,2,52,192,202,216,22,160,217,37,32,63,113,151,127,27,189,208,47,175,254,171,240,12,2,52,0,184,94,79,79,166,30,
84,61,112,126,121,185,125,99,173,250,207,213,235,211,190,1,2,52,0,172,184,209,170,241,201,237,140,178,27,54,231,48,253,199,213,143,166,250,12,2,52,0,8,207,109,86,87,84,143,155,31,27,213,231,237,133,251,
47,106,103,83,21,213,103,16,160,1,56,2,27,14,193,169,48,194,242,99,171,219,116,245,197,131,163,250,252,163,213,239,100,108,29,8,208,0,28,41,85,202,211,97,180,99,124,202,210,247,108,107,190,142,191,186,
250,143,169,60,131,0,13,0,188,179,159,249,94,77,187,15,46,94,187,199,220,231,255,80,189,42,189,207,32,64,3,0,239,188,78,127,98,117,121,59,237,27,163,117,227,153,213,79,164,117,3,4,104,0,160,181,166,62,
245,203,171,79,88,184,110,111,205,255,246,154,234,243,210,186,1,2,52,0,80,77,85,229,181,234,145,213,61,218,233,121,30,247,159,215,180,113,138,214,13,56,102,231,29,2,0,56,145,198,78,148,99,231,193,173,
249,118,190,250,222,234,103,230,151,77,83,129,99,166,2,13,0,39,207,232,115,190,117,245,17,11,129,250,124,245,127,155,102,62,235,123,6,1,26,0,152,141,217,207,31,85,93,89,189,189,186,172,122,97,245,248,
234,170,118,42,212,128,0,13,0,43,111,84,150,63,177,169,69,227,122,213,223,87,143,174,254,105,14,216,250,158,65,128,6,0,230,112,188,93,61,168,250,128,166,182,141,223,173,30,213,84,129,214,186,1,151,152,
69,132,0,112,50,221,165,250,245,234,127,85,63,88,189,163,169,240,37,60,131,0,13,112,65,107,23,184,95,126,249,186,88,236,35,93,190,135,75,97,4,228,167,205,183,193,184,58,16,160,1,225,248,157,247,107,11,
175,143,64,187,117,9,3,237,250,210,215,179,37,84,115,137,156,107,167,234,44,60,131,0,13,172,88,88,94,107,103,221,197,118,59,85,182,189,130,233,77,170,27,206,183,27,87,55,107,154,72,112,195,234,6,75,183,
243,243,199,63,191,16,130,215,155,166,21,108,44,220,143,151,223,90,189,169,122,125,245,234,166,133,89,175,159,111,155,23,248,63,140,201,8,91,153,128,192,241,216,18,156,65,128,6,86,39,44,143,219,102,87,
175,42,183,16,112,175,168,110,223,212,235,121,167,234,14,243,235,183,175,110,81,221,124,14,209,55,110,26,225,117,148,222,209,180,53,242,171,154,118,119,251,139,234,175,171,191,153,111,175,233,154,27,86,
172,47,60,9,16,114,0,4,104,128,3,59,215,78,203,195,8,204,139,174,172,238,222,180,29,241,125,171,247,168,238,60,7,230,43,58,248,68,160,237,118,239,89,190,182,65,127,49,240,95,190,16,222,223,171,122,204,
194,219,190,174,122,126,245,231,213,115,170,63,156,67,245,230,210,199,27,163,197,84,167,1,4,104,128,107,132,207,17,154,55,186,122,245,245,92,117,207,234,62,213,251,85,15,152,3,243,173,246,248,120,139,
127,166,94,219,227,126,177,87,250,176,45,7,243,237,133,223,147,55,171,30,54,223,62,187,169,90,253,194,234,247,171,223,172,254,95,211,140,222,197,10,245,114,187,7,0,2,52,176,162,161,185,166,202,235,98,
245,245,174,115,88,126,68,245,208,166,74,243,110,45,23,163,58,189,28,134,207,117,233,231,210,239,21,206,23,23,18,142,106,245,189,231,219,167,54,245,82,255,73,245,172,234,87,170,231,238,18,166,151,171,
231,0,0,156,209,208,188,190,203,147,237,27,86,15,175,254,75,83,59,195,91,151,2,226,118,87,95,184,183,213,213,91,27,78,251,109,107,126,50,48,254,127,203,255,254,252,234,91,231,39,20,151,239,82,184,216,
239,201,194,248,247,119,111,218,194,121,251,144,143,223,216,6,250,115,21,83,0,0,14,199,185,11,132,230,71,55,109,232,240,183,123,4,230,205,51,22,150,15,26,168,55,22,130,233,114,152,254,198,234,193,187,
28,227,197,113,121,2,52,0,192,41,51,170,205,139,213,209,203,171,15,172,190,167,122,209,46,161,113,85,3,243,126,183,81,157,94,62,46,191,87,125,113,211,212,145,69,203,65,250,168,3,244,168,154,255,91,1,26,
0,224,226,141,74,232,162,123,85,255,169,169,122,186,28,12,55,186,250,104,58,183,131,133,233,197,199,254,165,250,217,234,35,186,122,139,199,120,2,115,92,1,250,51,5,104,0,128,131,91,174,54,223,184,250,132,
234,151,171,183,237,18,0,133,230,195,105,243,88,238,153,254,179,234,139,170,219,44,124,47,206,207,223,31,1,26,0,224,18,27,109,26,139,237,2,247,170,190,161,105,12,219,114,200,18,154,143,54,76,47,30,223,
87,85,223,91,61,112,233,123,35,64,3,0,92,194,224,188,232,145,213,211,186,250,4,141,81,33,213,211,124,188,45,30,27,75,175,63,179,122,255,166,113,128,111,21,160,1,0,46,93,112,190,65,245,132,234,217,93,115,
42,131,106,243,165,175,74,47,247,74,255,105,59,21,232,195,188,9,208,0,215,129,95,154,112,182,131,243,104,19,184,162,250,164,234,115,154,54,255,104,33,180,157,243,187,224,196,124,207,198,247,97,115,254,
190,220,207,97,1,16,160,129,163,15,97,231,218,105,11,184,117,245,233,213,103,85,119,90,8,103,205,1,123,221,33,59,145,22,183,1,63,231,112,0,8,208,192,209,6,231,205,234,246,213,103,207,225,249,118,11,193,
121,77,104,62,85,132,103,0,1,26,56,226,224,124,187,166,205,49,62,171,157,177,104,163,29,64,112,6,0,1,26,4,231,249,118,235,166,254,230,207,158,95,174,169,133,67,155,6,0,8,208,176,242,214,23,130,243,21,
115,104,254,194,234,182,75,193,217,207,55,0,8,208,176,242,193,121,107,14,206,215,171,62,163,250,146,234,142,243,191,143,86,13,63,215,0,32,64,195,74,59,215,212,178,49,166,103,124,66,245,149,213,125,150,
130,179,86,13,0,16,160,97,165,45,206,114,174,122,68,245,53,77,59,8,142,224,108,170,6,0,8,208,64,59,125,206,27,77,219,57,127,117,245,196,249,223,182,22,222,6,0,16,160,97,165,141,185,191,155,213,141,170,
47,174,254,67,117,211,118,118,14,20,156,1,64,128,134,149,183,56,150,174,234,113,213,215,85,247,90,8,212,70,210,1,128,0,13,116,245,177,116,247,172,190,177,250,216,133,224,108,129,32,0,8,208,64,87,95,36,
120,121,83,187,198,87,52,181,107,232,115,6,0,1,26,88,176,184,72,240,33,213,183,85,15,158,255,109,83,112,6,128,147,235,156,67,0,199,106,109,33,60,223,184,250,230,234,183,231,240,188,209,180,80,80,120,230,
184,108,59,4,0,23,79,5,26,142,247,9,235,216,73,240,81,213,119,180,179,25,202,150,159,71,46,129,13,135,0,224,218,93,208,129,227,121,178,186,85,221,176,250,150,234,55,230,240,60,170,206,126,22,1,224,20,
93,212,129,163,125,146,186,61,7,229,7,87,223,95,221,127,126,108,219,207,32,0,156,206,139,59,112,52,214,155,170,206,219,213,151,86,207,158,195,243,70,59,115,159,1,128,83,70,245,11,14,223,226,166,40,239,
218,84,117,254,240,249,223,244,58,3,192,41,167,2,6,71,243,51,181,89,125,116,245,251,115,120,214,235,12,0,2,52,176,100,180,108,156,171,190,169,122,70,117,187,57,76,159,111,170,76,3,0,167,156,63,37,195,
225,253,44,109,84,119,172,126,180,250,192,236,38,8,0,2,52,112,13,163,223,121,99,14,205,79,174,238,48,191,238,231,11,0,206,32,45,28,112,221,126,126,182,155,90,52,190,160,250,21,225,25,0,206,62,23,121,184,
118,198,118,220,151,87,223,83,253,155,57,76,155,178,1,0,2,52,176,203,207,205,70,211,2,193,159,170,62,96,14,211,231,242,87,29,0,16,160,129,93,195,243,253,171,167,85,119,79,203,6,0,172,20,213,50,184,248,
240,252,152,234,183,132,103,0,16,160,129,221,173,53,245,60,111,84,159,89,253,124,117,69,59,243,157,1,0,1,26,88,8,207,107,115,88,254,143,213,15,204,63,55,91,153,239,12,0,43,73,245,12,246,14,207,205,97,
249,219,171,47,204,98,65,0,16,160,29,2,216,213,168,50,159,171,126,164,250,212,244,59,3,0,194,0,236,25,158,47,111,26,83,247,113,213,85,213,101,14,13,0,32,64,195,133,195,243,255,172,62,162,169,242,44,60,
3,0,239,12,11,192,213,195,243,13,170,103,44,132,103,79,52,1,128,119,18,12,96,39,60,111,87,215,111,170,60,63,90,120,102,5,108,56,4,0,215,46,52,128,159,131,41,60,95,214,180,187,160,240,204,170,216,118,8,
0,4,104,184,88,107,11,247,63,93,61,86,120,6,0,246,34,36,176,234,225,249,92,211,108,231,31,173,30,39,60,3,0,251,81,129,102,149,173,207,225,249,219,154,230,60,95,37,60,3,0,2,52,236,238,124,83,181,249,43,
170,47,202,168,58,0,64,128,134,125,195,243,167,84,223,48,191,188,238,176,176,130,182,28,2,0,1,26,246,179,62,7,230,71,85,63,52,7,136,245,118,22,19,194,42,24,231,251,219,231,123,211,56,0,4,104,184,96,120,
222,172,238,81,253,76,59,45,27,194,51,171,234,141,14,1,128,0,13,23,178,214,84,109,190,105,211,46,131,183,156,195,180,159,1,86,249,119,255,107,231,123,21,104,0,1,26,174,17,158,215,231,144,240,228,234,61,
210,247,204,234,26,97,249,109,213,171,29,14,0,1,26,118,51,250,158,255,115,245,49,153,245,140,0,93,245,170,234,117,75,143,1,32,64,195,59,195,243,99,171,175,78,229,25,70,88,126,89,245,166,166,191,208,8,
208,0,2,52,188,243,252,222,172,238,92,253,88,83,15,244,185,44,26,132,170,191,113,29,0,16,160,97,209,90,59,189,207,63,81,221,162,169,202,230,156,103,213,141,106,243,159,45,252,172,0,112,17,244,129,114,
86,141,214,141,175,175,30,158,190,103,88,252,217,168,122,222,82,160,6,224,128,84,30,56,171,1,97,179,105,179,148,103,165,117,3,90,8,203,107,213,27,154,230,161,191,58,61,208,0,23,205,159,179,57,139,79,10,
183,171,43,154,118,26,92,91,184,193,170,27,91,119,255,133,240,12,32,64,195,226,57,189,85,125,75,117,215,108,150,2,139,70,88,254,221,249,222,68,26,0,1,154,21,55,90,55,62,172,250,140,140,172,131,11,253,
206,255,63,75,129,26,128,139,224,207,218,156,165,115,121,173,186,81,245,167,77,213,231,45,79,18,225,157,70,255,243,235,170,123,86,175,73,11,7,192,181,34,92,112,150,206,229,173,234,107,211,186,1,187,217,
156,239,127,111,14,207,231,132,103,0,1,154,213,53,90,55,30,80,125,158,240,12,123,250,101,191,255,1,4,104,24,231,242,119,84,151,205,175,107,79,130,29,219,77,115,208,223,182,16,160,183,28,22,0,1,154,213,
52,170,207,159,88,61,108,126,217,194,65,184,186,17,150,255,160,250,187,249,9,166,0,13,32,64,179,130,198,2,168,155,54,237,56,56,22,73,1,187,251,249,133,39,158,0,8,208,172,232,249,187,85,125,65,117,231,
76,221,128,221,108,207,129,249,29,213,47,206,143,169,62,3,92,7,170,117,156,246,115,247,54,213,95,86,87,206,65,65,128,134,171,27,139,106,255,79,211,246,246,231,4,104,128,235,70,216,224,52,159,187,219,213,
151,86,55,75,245,25,246,123,194,249,83,126,239,3,28,222,47,85,56,173,225,249,14,213,243,155,54,79,89,115,62,195,53,140,117,1,175,175,222,173,122,85,54,79,1,56,148,32,2,167,241,137,223,118,245,197,213,
77,154,170,207,194,51,92,211,216,60,229,151,230,240,188,46,60,3,8,208,172,230,57,187,85,221,174,250,180,118,22,72,1,23,254,29,255,227,14,5,128,0,205,234,26,213,231,207,106,26,95,167,250,12,187,27,235,
2,158,95,253,214,252,115,178,233,176,0,8,208,172,94,120,222,170,174,168,62,51,115,159,97,191,0,93,245,163,213,85,249,75,13,128,0,205,74,26,253,155,143,111,106,225,48,121,3,118,55,182,238,126,99,245,211,
243,99,170,207,0,2,52,43,102,252,249,249,92,83,251,134,133,80,112,97,163,250,252,115,213,43,179,120,16,64,128,102,101,207,213,237,234,253,170,7,102,241,32,236,247,243,178,89,125,79,218,156,0,4,104,86,
222,147,230,123,59,169,193,238,54,231,208,252,127,170,63,202,226,65,0,1,154,149,52,2,192,205,171,143,158,31,83,125,134,11,255,188,84,125,251,210,235,0,8,208,172,144,17,150,63,172,186,101,59,21,54,224,
234,198,207,198,95,84,191,154,234,51,128,0,205,202,26,139,159,62,97,126,217,98,40,184,176,181,166,234,243,85,126,199,3,28,221,47,90,56,233,231,232,118,117,219,234,5,77,155,167,152,255,12,215,52,54,21,
250,251,234,61,171,183,46,61,1,5,224,144,168,78,112,210,141,246,141,15,154,195,179,246,13,216,221,120,98,249,237,213,91,50,186,14,64,128,102,165,67,65,213,71,164,125,3,46,100,108,42,244,178,234,201,233,
125,6,16,160,89,89,35,4,220,184,122,216,252,186,115,22,118,127,162,185,86,125,103,245,47,169,62,3,8,208,172,252,249,249,222,213,187,204,129,192,57,11,87,183,88,125,254,193,84,159,1,4,104,86,218,232,117,
126,216,124,47,20,192,53,141,234,243,127,171,222,208,206,174,157,0,8,208,172,160,177,219,224,195,151,2,53,176,243,51,114,174,122,113,245,35,243,207,136,93,58,1,4,104,86,212,8,2,55,173,238,235,124,133,
93,141,234,243,55,85,111,74,239,51,128,0,205,202,7,232,170,123,52,205,128,54,251,25,174,110,115,254,29,254,87,213,143,207,47,107,115,2,16,160,113,110,118,255,252,89,26,246,122,162,249,85,213,219,218,217,
116,8,0,1,154,21,119,159,249,94,48,128,29,155,77,237,26,191,83,61,35,213,103,0,1,26,22,194,192,189,231,123,237,27,176,99,252,60,124,69,218,155,0,4,104,152,109,87,231,171,187,10,208,112,141,39,151,231,
170,167,54,85,160,215,83,125,6,56,86,66,9,39,245,188,220,110,218,60,229,249,213,21,169,178,193,120,98,185,93,189,165,122,207,234,37,89,35,0,112,236,84,160,57,201,79,236,110,211,52,198,206,147,61,152,140,
185,207,255,181,105,246,243,57,225,25,64,128,134,197,176,124,171,108,75,12,203,225,249,133,213,127,23,158,1,4,104,216,45,64,223,222,161,128,119,26,109,76,95,92,189,57,99,235,0,4,104,216,197,45,28,2,168,
118,198,214,61,189,250,133,44,28,4,16,160,225,2,110,62,223,171,178,177,202,182,154,170,205,175,111,170,62,171,60,3,8,208,112,65,55,117,8,224,157,189,207,95,85,253,67,122,159,1,4,104,216,195,229,14,1,43,
110,179,105,30,250,111,86,223,219,212,186,33,60,3,8,208,32,64,195,46,198,162,193,55,85,159,221,206,12,104,237,27,0,2,52,236,25,32,96,85,141,29,7,191,162,250,155,84,159,1,4,104,16,160,97,207,240,124,190,
105,226,198,119,207,47,155,186,1,32,64,195,190,222,238,16,176,130,198,162,193,87,84,159,153,173,186,1,4,104,184,8,111,114,8,88,49,163,199,121,173,250,180,234,149,153,186,1,32,64,195,69,120,131,67,192,
138,217,104,234,117,254,170,234,87,210,186,1,32,64,195,69,122,245,124,191,230,80,176,34,225,249,178,166,221,6,255,75,118,27,4,16,160,225,34,140,197,131,175,114,40,88,17,99,209,224,31,85,79,106,167,239,
217,66,90,0,1,26,46,202,63,58,79,89,145,240,188,222,180,203,224,199,84,111,206,118,221,0,2,52,92,164,197,10,180,48,193,89,182,53,135,231,55,84,31,93,189,44,243,158,1,4,104,184,14,1,250,21,213,107,150,
30,131,179,118,158,95,85,125,66,245,220,244,61,3,8,208,112,29,130,197,90,245,182,234,69,2,52,103,244,28,31,243,158,63,45,19,55,0,4,104,56,4,235,243,253,95,9,208,156,209,240,188,94,125,126,245,148,57,60,
111,56,52,0,2,52,28,134,231,206,247,70,217,113,86,140,69,131,95,217,206,54,221,194,51,128,0,13,215,217,168,56,255,201,252,178,115,149,179,96,99,14,204,95,95,125,131,240,12,32,64,195,97,26,83,8,94,208,
52,222,107,45,147,9,56,221,79,8,71,120,254,230,234,171,179,96,16,64,128,134,35,8,28,235,77,99,236,254,104,225,49,56,141,198,70,41,255,173,250,242,118,70,213,57,167,1,4,104,56,84,163,239,249,55,5,104,78,
241,19,193,17,158,191,185,250,18,225,25,64,128,134,163,52,90,54,158,213,52,43,247,188,67,194,41,11,207,99,218,198,215,167,242,12,32,64,195,49,5,144,181,234,111,171,63,91,10,213,112,210,207,221,209,134,
244,21,237,244,60,11,207,0,2,52,28,121,8,25,161,227,231,5,104,78,137,173,249,137,223,185,234,11,170,111,106,250,235,137,240,12,112,70,152,173,203,105,120,146,183,85,189,71,245,167,115,160,118,222,114,
146,195,243,185,166,150,163,79,173,126,42,163,234,0,206,100,56,129,211,16,72,158,95,253,238,252,152,209,95,156,68,155,243,185,250,198,234,35,133,103,128,179,107,221,33,224,148,156,167,35,72,127,84,54,
86,225,228,25,51,158,95,90,61,166,122,182,240,12,112,118,249,83,56,167,229,60,221,174,174,172,254,186,186,77,59,11,12,225,164,132,231,63,174,62,174,122,177,240,12,112,182,169,64,115,154,206,213,183,86,
183,174,30,218,206,159,203,225,82,25,99,234,206,55,45,114,253,232,234,159,178,195,32,192,153,167,130,199,105,113,110,14,44,119,173,158,87,221,192,57,204,37,52,38,109,172,53,237,46,248,37,11,231,169,73,
49,0,103,156,10,52,167,197,24,105,247,218,234,110,213,3,218,233,139,134,227,180,49,159,139,27,213,231,52,141,169,59,55,135,105,225,25,96,5,168,222,113,154,140,42,244,187,85,127,82,93,222,78,21,16,142,
43,60,159,175,94,82,125,82,245,59,217,32,5,96,229,168,64,115,154,140,42,244,171,171,119,173,30,148,94,104,142,239,220,27,231,223,175,55,141,169,123,254,28,166,245,59,3,0,39,218,248,83,249,187,54,205,219,
221,108,167,250,231,230,118,20,183,141,133,151,191,121,161,240,160,0,1,176,162,92,0,56,109,70,21,240,245,77,213,191,71,165,10,205,209,25,45,27,175,169,158,84,125,199,194,19,57,253,206,0,43,74,239,40,167,
245,188,93,107,154,196,241,167,77,139,10,109,174,194,97,90,156,178,241,219,213,103,84,127,155,126,103,0,224,20,27,127,61,249,240,57,204,92,149,86,3,183,195,185,45,158,75,223,208,84,129,94,60,231,0,0,78,
125,136,254,201,174,217,171,234,230,118,177,183,205,249,182,93,189,176,250,224,249,252,90,203,95,55,0,128,51,226,220,124,187,85,245,178,166,63,173,111,10,130,110,93,183,133,130,63,86,221,114,62,199,206,
167,213,13,0,56,99,70,21,250,49,105,229,112,187,110,85,231,151,85,31,191,203,185,5,0,187,134,15,56,173,182,155,170,132,47,168,174,168,30,218,84,77,244,39,119,246,51,118,20,92,171,158,50,135,231,231,44,
252,94,52,101,3,0,56,179,214,230,208,115,190,250,189,244,67,187,237,95,117,30,147,52,94,92,61,94,81,1,0,88,69,163,226,124,231,234,149,233,135,118,187,230,109,107,233,137,213,247,53,245,207,143,224,172,
215,25,0,88,57,163,122,56,54,87,177,75,161,219,110,139,4,255,176,250,128,93,206,27,0,128,149,52,102,246,126,102,22,21,186,77,193,121,60,137,122,109,245,31,170,203,23,130,179,170,51,0,192,66,136,254,122,
33,122,165,251,156,151,71,211,221,121,225,28,81,117,6,0,88,176,182,16,162,127,96,14,80,239,16,42,87,178,207,249,217,213,35,151,130,179,170,51,0,192,5,66,244,88,88,248,211,66,244,202,5,231,23,84,159,188,
20,156,141,54,4,0,56,64,136,30,35,238,158,150,118,142,179,26,156,23,191,167,175,168,190,172,186,209,194,57,160,93,3,0,224,90,132,232,115,66,244,153,14,206,175,175,190,177,186,245,194,247,94,112,6,0,184,
150,206,45,132,232,31,91,8,209,70,220,157,254,86,141,55,86,223,86,221,101,41,56,235,115,6,0,184,142,214,22,66,213,183,183,51,169,193,102,43,167,51,56,191,190,250,206,234,30,130,51,0,192,209,134,232,177,
144,236,75,219,125,147,13,183,147,61,142,238,53,213,183,86,119,91,10,206,22,8,2,0,28,97,136,30,189,177,255,170,169,146,169,47,250,100,86,155,23,255,58,240,210,234,171,171,219,11,206,0,0,151,198,152,19,
125,191,234,79,219,169,68,107,233,56,57,11,3,183,171,63,174,62,167,186,185,224,12,0,112,233,141,74,244,77,218,217,112,69,53,250,210,84,155,23,219,52,54,171,95,172,62,170,171,79,210,208,227,12,0,112,2,
44,86,50,63,190,169,85,96,4,59,213,232,163,237,109,94,126,162,242,15,77,11,60,239,191,244,61,58,47,56,3,0,156,44,139,125,209,183,169,126,168,171,47,48,20,164,143,174,183,121,163,122,86,245,196,234,202,
165,39,54,42,206,0,0,39,220,98,187,192,163,170,223,19,164,143,36,52,143,173,182,191,161,169,7,125,249,123,160,191,25,0,224,20,89,172,70,159,171,62,181,250,43,65,250,90,141,158,91,62,78,255,88,253,72,245,
161,213,245,119,57,230,170,205,0,0,167,216,98,53,250,198,213,231,53,85,77,151,43,171,118,51,220,233,23,223,109,119,199,127,172,126,178,250,216,234,102,75,199,248,124,170,205,0,0,103,202,218,82,144,190,
126,245,41,93,189,181,99,84,165,87,41,76,47,6,230,221,54,161,121,81,245,195,213,71,239,18,154,215,83,109,6,0,88,185,32,189,86,125,112,245,148,234,117,75,225,241,170,51,24,166,247,11,204,111,158,159,84,
124,125,245,136,234,70,66,51,0,103,61,24,0,7,255,121,57,55,135,201,225,14,213,99,170,199,87,15,169,110,176,240,111,91,243,109,188,223,105,248,121,91,14,199,231,186,102,155,197,85,213,223,85,207,169,126,
99,190,127,225,46,161,185,133,39,18,0,32,64,195,138,27,1,113,49,76,223,189,169,50,253,232,234,125,171,91,237,18,78,55,23,126,246,22,111,199,29,146,151,195,242,94,33,255,45,77,11,41,255,164,250,127,213,
31,54,245,131,111,44,253,46,89,111,167,98,45,52,3,32,64,3,187,26,161,115,57,52,222,188,122,159,234,161,243,237,62,213,45,47,240,49,22,219,61,22,127,46,215,174,197,207,233,246,210,203,219,75,63,239,35,
40,95,200,155,155,122,152,255,118,14,202,207,155,111,47,219,227,73,196,8,205,0,32,64,3,23,29,166,207,181,211,186,177,232,86,77,21,234,247,158,195,244,125,170,59,86,183,173,46,187,4,95,235,171,231,219,
139,171,191,158,3,243,95,206,225,249,31,47,16,136,207,95,32,240,3,128,0,13,28,202,207,214,98,117,122,183,64,122,227,234,118,213,237,171,59,85,239,58,191,124,171,234,22,77,85,236,155,52,77,255,184,108,
14,176,203,219,90,143,182,144,177,200,239,29,77,45,23,175,171,222,80,189,118,14,202,255,52,7,227,151,206,175,191,170,122,205,30,95,255,88,244,183,220,19,13,0,46,242,14,1,28,123,160,190,152,62,225,243,
213,13,155,22,39,94,62,223,22,39,130,140,77,75,174,170,222,58,135,231,171,58,120,75,197,226,34,65,97,25,0,14,224,255,7,221,193,18,229,49,167,16,59,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* WillStereoDelayAudioProcessorEditor::quaver_png = (const char*) resource_WillStereoDelayAudioProcessorEditor_quaver_png;
const int WillStereoDelayAudioProcessorEditor::quaver_pngSize = 16608;

// JUCER_RESOURCE: kisspngquarternotemusicalnoteeighthnoterestmusicnotes5ad2c34d6918e6_3884611415237619974305_png, 57706, "../../../Downloads/kisspng-quarter-note-musical-note-eighth-note-rest-music-notes-5ad2c34d6918e6.3884611415237619974305.png"
static const unsigned char resource_WillStereoDelayAudioProcessorEditor_kisspngquarternotemusicalnoteeighthnoterestmusicnotes5ad2c34d6918e6_3884611415237619974305_png[] = { 137,80,78,71,13,10,26,10,0,
0,0,13,73,72,68,82,0,0,11,184,0,0,11,184,8,6,0,0,0,113,21,245,121,0,0,0,9,112,72,89,115,0,0,46,35,0,0,46,35,1,120,165,63,118,0,0,2,238,105,67,67,80,73,67,67,32,80,114,111,102,105,108,101,0,0,120,156,99,
96,96,158,224,232,226,228,202,36,192,192,80,80,84,82,228,30,228,24,25,17,25,165,192,126,158,129,141,129,153,1,12,18,147,139,11,28,3,2,124,64,236,188,252,188,84,6,84,192,200,192,240,237,26,136,100,96,184,
172,11,50,139,129,52,192,154,12,180,24,72,31,0,98,163,148,212,226,100,32,253,5,136,211,203,75,10,128,226,140,49,64,182,72,82,54,152,93,0,98,103,135,4,57,3,217,45,12,12,76,60,37,169,21,32,189,12,206,249,
5,149,69,153,233,25,37,10,134,150,150,150,10,142,41,249,73,169,10,193,149,197,37,169,185,197,10,158,121,201,249,69,5,249,69,137,37,169,41,64,181,80,59,64,128,215,37,191,68,193,61,49,51,79,193,200,64,149,
68,119,19,4,160,112,132,176,16,225,131,16,67,128,228,210,162,50,8,11,172,72,128,65,129,193,128,193,129,33,128,33,145,161,158,97,1,195,81,134,55,140,226,140,46,140,165,140,43,24,239,49,137,49,5,49,77,96,
186,192,44,204,28,201,188,144,249,13,139,37,75,7,203,45,86,61,214,86,214,123,108,150,108,211,216,190,177,135,179,239,230,80,226,232,226,248,194,153,200,121,129,203,145,107,11,183,38,247,2,30,41,158,169,
188,66,188,147,248,132,249,166,241,203,240,47,22,208,17,216,33,232,42,120,69,40,85,232,135,112,175,136,138,200,94,209,112,209,47,98,147,196,141,196,175,72,84,72,202,73,30,147,202,151,150,150,62,33,83,
38,171,46,123,75,174,79,222,69,254,143,194,86,197,66,37,61,165,183,202,107,85,10,84,77,84,127,170,29,84,239,210,8,213,84,210,252,160,117,64,123,146,78,170,174,149,158,160,222,43,253,35,6,11,12,107,141,
98,140,109,77,228,77,153,77,95,154,93,48,223,105,177,196,114,130,85,157,117,174,77,156,109,160,157,171,189,181,131,177,163,142,147,154,179,146,139,130,171,188,155,130,187,178,135,186,167,174,151,137,183,
141,143,187,111,176,95,130,127,126,64,125,224,196,160,165,193,187,66,46,134,190,12,103,138,144,139,180,138,138,136,174,136,153,25,187,39,238,65,2,91,162,110,82,88,114,67,202,154,212,155,233,28,25,22,153,
153,89,115,179,47,230,178,231,217,231,87,20,108,42,124,87,172,93,146,85,186,170,236,77,133,126,101,73,213,174,26,198,90,175,186,169,245,15,27,245,154,106,154,207,182,202,181,21,182,31,237,148,238,42,234,
62,221,171,218,215,216,127,119,162,205,164,217,147,255,78,141,159,118,120,134,198,204,254,89,223,231,36,204,61,61,223,124,193,210,69,34,139,91,151,124,91,150,185,252,222,202,144,85,167,215,184,172,221,
183,222,114,195,182,77,38,155,183,108,53,217,182,125,135,213,206,253,187,93,247,156,221,23,182,255,193,193,156,67,63,143,180,31,19,63,190,226,164,245,169,115,103,146,207,254,58,63,233,162,246,165,163,
87,18,175,254,187,62,231,166,205,173,187,119,234,239,41,223,63,241,48,239,177,216,147,253,207,50,95,136,188,60,248,58,255,173,252,187,11,31,154,62,153,126,126,245,117,193,247,240,159,2,191,78,253,105,
253,231,248,255,63,0,13,0,15,52,222,28,180,136,0,0,210,127,73,68,65,84,120,218,236,218,177,13,194,80,20,192,192,151,136,30,137,85,104,25,141,33,24,135,237,62,59,164,8,86,116,55,130,107,111,107,173,1,0,
0,0,0,0,0,0,0,0,0,128,127,219,37,0,0,0,0,0,0,0,0,0,0,0,160,192,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,
0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,
0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,
0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,
0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,
0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,
0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,
130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,
7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,
0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,
0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,220,36,0,0,0,0,0,0,128,243,108,219,246,154,153,143,18,135,189,215,90,95,25,0,0,0,0,174,201,224,14,0,0,0,0,0,0,231,186,207,204,83,134,195,30,18,0,0,0,
0,92,215,46,1,0,0,0,0,0,0,0,0,0,0,0,5,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,
224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,
3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,
0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,
0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,
0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,
0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,
0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,
0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,
130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,
7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,
0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,
0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,
0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,
0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,
0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,
18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,
4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,
14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,
0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,
0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,
0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,
0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,
0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,
36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,
9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,
193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,
0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,
0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,
0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,
0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,
0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,
72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,
12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,
131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,
0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,
0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,
0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,
0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,
0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,
96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,
220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,
0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,
0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,
0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,
0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,
0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,
0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,
224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,
3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,
0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,
0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,
0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,
0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,
0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,
0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,
130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,
7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,
0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,
0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,
0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,
0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,
0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,
18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,
4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,
14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,
0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,
0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,
0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,
0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,
0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,
36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,
9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,
193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,
0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,
0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,
0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,
0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,
0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,
72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,
12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,
131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,
0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,
0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,
0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,
0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,
0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,
96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,
220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,
0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,
0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,
0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,
0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,
0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,
0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,
224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,
3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,
0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,
0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,
0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,
0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,
0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,130,193,29,0,0,0,0,0,0,0,0,0,0,128,4,131,59,0,0,0,0,0,0,0,0,0,
0,0,9,6,119,0,0,0,0,0,0,0,0,0,0,0,18,12,238,0,0,0,0,0,0,0,0,0,0,0,36,24,220,1,0,0,0,0,0,0,0,0,0,0,72,48,184,3,0,0,0,0,0,0,0,0,0,0,144,96,112,7,0,0,0,0,0,0,0,0,0,0,32,193,224,14,0,0,0,0,0,0,0,0,0,0,64,
130,193,29,0,0,0,0,0,128,31,187,118,44,0,0,0,0,48,200,223,122,26,59,138,35,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,
0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,
0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,
0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,
0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,
0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,
0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,
0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,
128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,
5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,
193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,
29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,
0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,
0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,
0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,
0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,
0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,
0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,
0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,
0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,
0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,
0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,
128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,
5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,
193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,
29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,
0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,
0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,
0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,
0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,
0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,
0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,
0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,
0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,
0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,
0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,
128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,
5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,
193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,
29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,
0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,
0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,
0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,
0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,
0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,
0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,
0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,
0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,
0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,
0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,
128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,
5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,
193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,
29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,
0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,
0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,
0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,
0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,
0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,
0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,
0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,
0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,
0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,
0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,
128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,
5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,
193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,
29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,
0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,
0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,
0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,
0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,
0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,
0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,
0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,
0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,
0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,
0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,
128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,
5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,
193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,
29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,
0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,
0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,
0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,
0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,
0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,
0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,
0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,
0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,
0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,
0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,
128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,
5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,
193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,
29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,
0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,
0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,
0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,
0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,
0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,
0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,
0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,
0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,
0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,
0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,
128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,
5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,
193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,
29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,
0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,
0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,
0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,
0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,
0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,0,0,0,128,5,193,29,0,0,0,0,0,
0,0,0,0,0,128,5,193,29,0,0,0,0,0,0,0,128,216,181,99,1,0,0,0,128,65,254,214,211,216,81,28,1,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,
0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,
0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,
0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,
0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,
0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,
0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,0,44,8,238,0,0,0,0,0,0,0,0,0,0,196,222,253,135,248,93,216,123,190,127,126,51,97,96,150,
129,44,89,114,8,228,144,75,46,89,188,164,228,18,240,144,139,224,146,75,46,130,32,8,130,23,47,94,44,46,89,92,188,184,8,93,60,120,176,184,116,241,208,210,210,197,197,131,7,139,139,139,197,131,197,98,177,
88,44,150,22,15,149,150,30,42,74,75,165,82,105,57,114,100,165,82,65,144,43,8,97,246,143,239,228,152,196,153,152,31,243,227,243,253,124,30,15,248,50,147,153,36,19,95,82,211,47,223,103,222,1,24,4,129,59,
0,0,0,0,0,0,0,0,0,0,0,131,32,112,7,0,0,0,0,0,0,0,0,0,0,96,16,4,238,0,0,0,0,0,0,0,0,0,0,0,12,130,192,29,0,0,0,0,0,0,0,0,0,0,128,65,16,184,3,0,0,0,0,0,0,0,0,0,0,48,8,2,119,0,0,0,0,0,0,0,0,0,0,0,6,65,224,
14,0,0,0,0,0,0,0,0,0,0,192,32,8,220,1,0,0,0,0,0,0,0,0,0,0,24,4,129,59,0,0,0,0,0,0,0,0,0,0,0,131,32,112,7,0,0,0,0,0,0,0,0,0,0,96,16,4,238,0,0,0,0,0,0,0,0,0,0,0,12,130,192,29,0,0,0,0,0,0,0,0,0,0,128,65,
16,184,3,0,0,0,0,0,0,0,0,0,0,48,8,2,119,0,0,0,0,0,0,0,0,0,0,0,6,65,224,14,0,0,0,0,0,0,0,0,0,0,192,32,8,220,1,0,0,0,0,0,0,0,0,0,0,24,4,129,59,0,0,0,0,0,0,0,0,0,0,0,131,32,112,7,0,0,0,0,0,0,0,0,0,0,96,16,
4,238,0,0,0,0,0,0,0,0,0,0,0,12,130,192,29,0,0,0,0,0,0,0,0,0,0,128,65,16,184,3,0,0,0,0,0,0,0,0,0,0,48,8,2,119,0,0,0,0,0,0,0,0,0,0,0,6,65,224,14,0,0,0,0,0,0,0,0,0,0,192,32,8,220,1,0,0,0,0,0,0,0,0,0,0,24,
4,129,59,0,0,0,0,0,0,0,0,0,0,0,131,32,112,7,0,0,0,0,0,0,0,0,0,0,96,16,4,238,0,0,0,0,0,0,0,0,0,0,0,12,130,192,29,0,0,0,0,0,0,0,0,0,0,128,65,16,184,3,0,0,0,0,0,0,0,0,0,0,48,8,2,119,0,0,0,0,0,0,0,0,0,0,0,
6,65,224,14,0,0,0,0,0,0,0,0,0,0,192,32,8,220,1,0,0,0,0,0,0,0,0,0,0,24,4,129,59,0,0,0,0,0,0,0,0,0,0,0,131,32,112,7,0,0,0,0,0,0,0,0,0,0,96,16,4,238,0,0,0,0,0,0,0,0,0,0,0,12,130,192,29,0,0,0,0,0,0,0,0,0,
0,128,65,16,184,3,0,0,0,0,0,0,0,0,0,0,48,8,2,119,0,0,0,0,0,0,0,0,0,0,0,6,65,224,14,0,0,0,0,0,0,0,0,0,0,192,32,8,220,1,0,0,0,0,0,0,0,0,0,0,24,4,129,59,0,0,0,0,0,0,0,0,0,0,0,131,32,112,7,0,0,0,0,0,0,0,0,
0,0,96,16,4,238,0,0,0,0,0,0,0,0,0,0,0,12,130,192,29,0,0,0,0,0,0,0,0,0,0,128,65,16,184,3,0,0,0,0,0,0,0,0,0,0,48,8,2,119,0,0,0,0,0,0,0,0,0,0,0,6,65,224,14,0,0,0,0,0,0,0,0,0,0,192,32,8,220,1,0,0,0,0,0,0,
0,0,0,0,24,4,129,59,0,0,0,0,0,0,0,0,0,0,0,131,32,112,7,0,0,0,0,0,0,0,0,0,0,96,16,4,238,0,0,0,0,0,0,0,0,0,0,0,12,130,192,29,0,0,0,0,0,0,0,0,0,0,128,65,16,184,3,0,0,0,0,0,0,0,0,0,0,48,8,2,119,0,0,0,0,0,
0,0,0,0,0,0,6,65,224,14,0,0,0,0,0,0,0,0,0,0,192,32,8,220,1,0,0,0,0,0,0,0,0,0,0,24,4,129,59,0,0,0,0,0,0,0,0,0,0,0,131,32,112,7,0,0,0,0,0,0,0,0,0,0,96,16,4,238,0,0,0,0,0,0,0,0,0,0,0,12,130,192,29,0,0,0,
0,0,0,0,0,0,0,128,65,16,184,3,0,0,0,0,0,0,0,0,0,0,48,8,2,119,0,0,0,0,0,0,0,0,0,0,0,6,65,224,14,0,0,0,0,0,0,0,0,0,0,192,32,8,220,1,0,0,0,0,0,0,0,0,0,0,24,4,129,59,0,0,0,0,0,0,0,0,0,0,0,131,32,112,7,0,0,
0,0,0,0,0,0,0,0,96,16,4,238,0,0,0,0,0,0,0,0,0,0,0,12,130,192,29,0,0,0,0,0,0,0,0,0,0,128,65,16,184,3,0,0,0,0,0,0,0,0,0,0,48,8,2,119,0,0,0,0,0,0,0,0,0,0,0,6,65,224,14,0,0,0,0,0,0,0,0,0,0,192,32,8,220,1,
0,0,0,0,0,0,0,0,0,0,24,4,129,59,0,0,0,0,0,0,0,0,0,0,0,131,32,112,7,0,0,0,0,0,0,0,0,0,0,96,16,4,238,0,0,0,0,0,0,0,0,0,0,0,12,130,192,29,0,0,0,0,0,0,0,0,0,0,128,65,16,184,3,0,0,0,0,0,0,0,0,0,0,48,8,2,119,
0,0,0,0,0,0,0,0,0,0,0,6,65,224,14,0,0,0,0,0,0,0,0,0,0,192,32,8,220,1,0,0,0,0,0,0,0,0,0,0,24,4,129,59,0,0,0,0,0,0,0,0,0,0,0,131,32,112,7,0,0,0,0,0,0,0,0,0,0,96,16,4,238,0,0,0,0,0,0,0,0,0,0,0,12,130,192,
29,0,0,0,0,0,0,0,0,0,0,128,65,16,184,3,0,0,0,0,0,0,0,0,0,0,48,8,2,119,0,0,0,0,0,0,0,0,0,0,0,6,65,224,14,0,0,0,0,0,0,0,0,0,0,192,32,8,220,1,0,0,0,0,0,0,0,0,0,0,24,4,129,59,0,0,0,0,0,0,0,0,0,0,0,131,32,
112,7,0,0,0,0,0,0,0,0,0,0,96,16,4,238,0,0,0,0,0,0,0,0,0,0,0,12,130,192,29,0,0,0,0,0,0,0,0,0,0,128,65,16,184,3,0,0,0,0,0,0,0,0,0,0,48,8,2,119,0,0,0,0,0,0,0,0,0,0,0,6,65,224,14,0,0,0,0,0,0,0,0,0,0,192,32,
8,220,1,0,0,0,0,0,0,0,0,0,0,24,4,129,59,0,0,0,0,0,0,0,0,0,0,0,131,32,112,7,0,0,0,0,0,0,0,0,0,0,96,16,4,238,0,0,0,0,0,0,0,0,0,0,0,12,130,192,29,0,0,0,0,0,0,0,0,0,0,128,65,16,184,3,0,0,0,0,0,0,0,0,0,0,48,
8,2,119,0,0,0,0,0,0,0,0,0,0,0,6,65,224,14,0,0,0,0,0,0,0,0,0,0,192,32,8,220,1,0,0,0,0,0,0,0,0,0,0,24,4,129,59,0,0,0,0,0,0,0,0,0,0,0,131,176,215,4,0,0,0,0,0,140,209,108,54,51,2,0,0,0,0,0,44,24,23,220,1,
0,0,0,0,0,0,0,0,0,0,24,4,129,59,0,0,0,0,0,0,0,0,0,0,0,131,32,112,7,0,0,0,0,0,0,0,0,0,0,96,16,4,238,0,0,0,0,0,0,0,0,0,0,0,12,130,192,29,0,0,0,0,0,0,0,0,0,0,128,65,16,184,3,0,0,0,0,0,0,0,0,0,0,48,8,2,119,
0,0,0,0,0,0,0,0,0,0,0,6,65,224,14,0,0,0,0,0,0,0,0,0,0,192,32,8,220,1,0,0,0,0,0,0,0,0,0,0,24,4,129,59,0,0,0,0,0,0,0,0,0,0,0,131,32,112,7,0,0,0,0,0,0,0,0,0,0,96,16,4,238,0,0,0,0,0,0,0,0,0,0,0,12,130,192,
29,0,0,0,0,0,0,0,0,0,0,128,65,16,184,3,0,0,0,0,0,0,0,0,0,0,48,8,2,119,0,0,0,0,0,0,0,0,0,0,0,6,65,224,14,0,0,0,0,0,0,0,0,0,0,192,32,8,220,1,0,0,0,0,0,0,0,0,0,0,24,4,129,59,0,0,0,0,0,0,0,0,0,0,0,131,32,
112,7,0,0,0,0,0,0,0,0,0,0,96,16,4,238,0,0,0,0,0,0,0,0,0,0,0,12,130,192,29,0,0,0,0,0,0,0,0,0,0,128,65,16,184,3,0,0,0,0,0,0,0,0,0,0,48,8,123,77,0,0,0,0,0,0,151,109,181,186,110,7,191,222,59,213,251,102,7,
0,0,0,0,96,42,4,238,0,0,0,0,0,140,217,177,106,101,253,253,19,213,210,250,251,215,95,244,253,142,87,203,231,125,123,105,253,251,47,138,119,171,247,46,241,249,215,46,241,185,55,170,179,231,125,251,237,234,
195,243,190,253,222,250,207,15,0,0,0,0,0,219,78,224,14,0,0,0,240,57,102,179,153,17,0,134,227,92,152,126,46,72,63,90,237,171,14,85,7,215,63,119,93,243,75,235,83,114,104,253,241,121,187,109,133,143,170,
183,46,250,216,107,151,248,252,27,125,26,208,159,255,62,0,0,0,0,0,124,134,192,29,0,0,0,0,128,33,56,23,170,95,191,254,246,104,181,191,58,210,252,2,251,49,19,13,198,106,159,13,230,175,52,160,63,219,60,118,
175,11,47,196,191,89,125,220,133,145,252,107,38,7,0,0,0,0,152,14,129,59,0,0,0,0,0,219,237,92,160,126,238,202,250,177,230,17,251,241,234,64,117,216,68,147,179,212,149,71,241,111,52,15,227,207,69,240,111,
53,15,225,223,174,62,172,254,80,125,96,90,0,0,0,0,128,197,38,112,7,0,0,0,0,96,43,172,86,215,53,143,215,15,175,63,174,95,127,123,192,60,108,129,19,235,111,63,47,140,127,167,122,191,79,47,195,191,191,254,
177,115,31,119,17,30,0,0,0,0,96,192,4,238,0,0,0,0,0,92,174,165,230,145,241,177,234,72,243,120,253,196,250,251,251,205,195,64,156,251,3,22,151,114,46,122,127,115,253,253,183,250,244,2,188,0,30,0,0,0,0,
96,23,9,220,1,0,0,0,0,184,216,114,117,124,253,113,172,249,101,246,115,15,24,131,3,235,143,205,174,193,111,22,192,191,95,189,97,62,0,0,0,0,128,237,35,112,7,0,0,0,0,152,174,115,23,217,79,52,143,215,207,
197,236,71,77,195,196,125,94,0,255,102,245,118,243,240,253,237,230,87,223,223,170,62,50,29,0,0,0,0,192,181,17,184,3,0,0,0,0,76,195,129,230,23,217,79,156,247,56,110,22,184,42,199,214,31,23,123,175,121,
232,254,86,243,75,239,231,2,248,119,76,6,0,0,0,0,112,121,4,238,0,0,0,0,0,227,115,180,11,67,246,19,213,33,179,192,182,59,184,254,56,117,209,199,63,110,126,245,253,215,93,120,245,253,15,38,3,0,0,0,0,184,
144,192,29,0,0,0,0,96,177,29,169,174,175,78,158,247,88,49,11,12,202,202,250,255,78,175,191,232,227,31,54,15,221,223,88,127,251,90,243,0,30,0,0,0,0,96,178,4,238,0,0,0,0,0,139,99,127,23,134,236,39,171,3,
102,129,133,181,175,58,189,254,56,231,227,62,141,221,223,88,127,251,107,83,1,0,0,0,0,83,33,112,7,0,0,0,0,24,166,229,62,27,179,31,49,11,140,222,74,117,227,250,227,156,179,125,54,122,127,205,84,0,0,0,0,
192,24,9,220,1,0,0,0,0,134,225,64,117,67,243,168,245,134,245,199,146,89,128,245,255,22,156,251,131,46,231,251,249,69,143,119,77,5,0,0,0,0,44,58,129,59,0,0,0,0,192,238,56,218,60,102,63,181,254,246,168,
73,128,43,116,238,15,195,156,243,78,159,198,238,175,230,202,59,0,0,0,0,176,128,4,238,0,0,0,0,0,59,227,220,101,246,115,111,15,152,4,216,98,135,215,31,119,172,127,251,163,234,239,155,199,238,127,223,60,
124,7,0,0,0,0,24,52,129,59,0,0,0,0,192,246,184,161,249,117,246,115,143,21,147,0,59,108,181,186,101,253,81,243,224,253,92,236,254,234,250,3,0,0,0,0,96,80,4,238,0,0,0,0,0,91,227,250,234,116,243,152,253,
198,106,159,73,128,129,89,173,110,94,127,212,60,120,255,81,245,131,234,135,213,187,38,2,0,0,0,0,118,155,192,29,0,0,0,0,224,234,28,107,30,137,158,11,218,247,155,4,88,48,171,213,109,235,143,170,55,171,239,
87,63,89,127,156,53,17,0,0,0,0,176,211,4,238,0,0,0,0,0,151,231,80,243,11,237,183,54,143,218,15,152,4,24,153,99,235,143,7,115,221,29,0,0,0,0,216,37,2,119,0,0,0,0,128,141,173,52,15,217,79,87,183,52,143,
62,1,166,194,117,119,0,0,0,0,96,87,8,220,1,0,0,0,0,62,117,172,79,47,180,159,174,150,77,2,240,207,255,125,188,248,186,251,247,215,31,31,152,7,0,0,0,0,216,42,2,119,0,0,0,0,96,202,246,87,55,53,143,218,79,
87,7,77,2,240,185,206,191,238,126,182,250,97,245,157,230,177,251,135,230,1,0,0,0,0,174,133,192,29,0,0,0,0,152,154,99,205,163,204,155,154,95,106,7,224,234,45,85,183,172,63,62,105,30,187,127,187,250,65,
245,177,121,0,0,0,0,128,43,37,112,7,0,0,0,0,198,110,185,121,204,126,115,243,75,237,135,77,2,176,109,255,189,189,117,253,241,81,243,200,253,239,154,71,239,159,152,7,0,0,0,0,184,28,2,119,0,0,0,0,96,140,
14,54,191,38,124,107,117,186,90,53,9,192,142,90,173,238,88,127,124,88,125,191,250,78,243,216,253,172,121,0,0,0,0,128,205,8,220,1,0,0,0,128,177,56,81,221,214,60,108,191,222,28,0,131,177,175,186,107,253,
241,65,245,189,230,177,251,143,76,3,0,0,0,0,92,76,224,14,0,0,0,0,44,178,83,205,131,246,59,170,195,230,0,24,188,253,213,153,245,199,219,213,183,170,255,94,189,111,26,0,0,0,0,160,106,143,9,0,0,0,0,128,5,
178,212,60,104,127,162,250,99,245,74,245,64,226,118,128,69,116,180,250,122,245,79,213,179,205,255,208,18,0,0,0,0,48,113,46,184,3,0,0,0,0,67,183,90,221,84,221,185,254,118,159,73,0,70,101,185,249,223,196,
113,71,245,86,245,183,213,183,171,15,76,3,0,0,0,0,211,227,130,59,0,0,0,0,48,68,251,170,187,171,23,170,63,85,207,87,183,39,110,7,24,187,235,170,71,155,95,117,127,186,186,193,36,0,0,0,0,48,45,2,119,0,0,
0,0,96,40,86,154,71,236,47,84,127,172,158,170,110,109,126,217,23,128,233,253,158,112,87,245,179,234,87,213,125,249,67,78,0,0,0,0,48,9,2,119,0,0,0,0,96,55,45,85,183,84,207,54,143,218,159,75,212,14,192,
133,142,87,143,53,191,234,254,228,250,183,1,0,0,0,128,145,18,184,3,0,0,0,0,187,225,116,245,68,243,168,253,197,234,142,106,213,44,0,92,194,106,117,166,249,69,247,151,171,83,38,1,0,0,0,128,241,217,107,2,
0,0,0,0,96,135,156,172,110,175,238,170,14,154,3,128,107,112,211,250,227,181,234,191,84,223,169,206,154,5,0,0,0,0,22,159,11,238,0,0,0,0,192,118,58,86,125,165,250,125,245,139,234,129,196,237,0,108,157,235,
171,103,214,127,159,185,175,90,49,9,0,0,0,0,44,54,129,59,0,0,0,0,176,213,14,85,15,85,175,87,191,169,30,174,142,152,5,128,109,116,184,122,172,250,199,234,75,213,170,73,0,0,0,0,96,49,9,220,1,0,0,0,128,173,
112,160,249,229,220,159,86,255,84,61,82,157,48,11,0,187,240,251,209,55,155,95,116,23,186,3,0,0,0,192,2,18,184,3,0,0,0,0,87,107,95,117,119,245,82,245,199,230,151,115,111,52,11,0,3,112,46,116,119,209,29,
0,0,0,0,22,140,192,29,0,0,0,0,184,18,203,213,109,213,11,205,163,246,167,170,155,205,2,192,64,237,239,211,208,253,190,245,223,199,0,0,0,0,128,1,19,184,3,0,0,0,0,151,227,88,243,64,240,127,84,207,87,183,
38,18,4,96,113,236,111,254,55,141,252,182,186,203,28,0,0,0,0,48,92,2,119,0,0,0,0,96,51,171,213,153,234,103,213,111,170,47,53,15,4,1,96,81,29,169,158,174,94,175,110,50,7,0,0,0,0,12,143,192,29,0,0,0,0,184,
216,13,213,19,205,175,181,63,185,254,109,0,24,147,19,213,203,213,143,215,223,7,0,0,0,0,6,66,224,14,0,0,0,0,212,252,50,251,253,213,175,154,95,108,191,167,249,5,119,0,24,179,211,205,175,185,63,158,191,165,
4,0,0,0,0,6,65,224,14,0,0,0,0,211,118,83,245,108,243,107,237,143,86,199,77,2,192,4,221,91,253,126,253,237,146,57,0,0,0,0,96,247,8,220,1,0,0,0,96,122,14,86,15,55,15,249,94,174,238,168,150,205,2,192,196,
237,107,126,201,253,245,234,148,57,0,0,0,0,96,119,8,220,1,0,0,0,96,26,150,170,91,171,23,155,95,107,255,74,117,196,44,0,240,25,199,171,87,170,103,170,3,230,0,0,0,0,128,157,37,112,7,0,0,0,128,113,59,90,
125,181,121,212,254,66,117,139,73,0,224,178,220,89,253,174,186,219,20,0,0,0,0,176,115,4,238,0,0,0,0,48,62,43,213,93,205,175,207,254,174,122,48,23,104,1,224,106,236,171,158,170,126,220,252,15,141,1,0,0,
0,0,219,76,224,14,0,0,0,0,227,113,162,122,172,249,181,246,167,171,83,38,1,128,45,113,186,250,85,245,80,181,108,14,0,0,0,0,216,62,2,119,0,0,0,0,88,108,203,205,175,181,255,180,122,189,186,175,249,181,89,
0,96,107,173,84,143,84,191,172,142,155,3,0,0,0,0,182,135,192,29,0,0,0,0,22,211,193,230,145,221,63,53,191,214,126,163,73,0,96,71,28,111,30,185,63,100,10,0,0,0,0,216,122,2,119,0,0,0,0,88,44,167,171,103,
155,135,237,15,85,7,76,2,0,59,110,185,249,31,52,123,165,58,98,14,0,0,0,0,216,58,2,119,0,0,0,0,24,190,213,234,222,234,55,213,143,171,59,170,37,179,0,192,174,59,85,253,170,186,199,20,0,0,0,0,176,53,4,238,
0,0,0,0,48,92,215,85,143,54,191,214,254,120,117,204,36,0,48,56,171,213,19,213,139,213,62,115,0,0,0,0,192,181,17,184,3,0,0,0,192,240,220,220,252,82,251,111,171,251,19,203,1,192,34,184,165,250,101,117,220,
20,0,0,0,0,112,245,4,238,0,0,0,0,48,12,43,213,61,213,111,170,151,170,211,38,1,128,133,115,180,250,69,117,167,41,0,0,0,0,224,234,236,53,1,0,0,0,0,236,170,131,205,175,180,223,83,237,55,7,0,44,188,149,234,
153,234,100,245,151,213,39,38,1,0,0,0,128,203,231,130,59,0,0,0,0,236,142,235,171,167,171,127,172,30,76,220,14,0,99,115,127,245,227,230,127,152,13,0,0,0,0,184,76,2,119,0,0,0,0,216,89,183,85,63,173,126,
89,221,85,45,155,4,0,70,235,198,234,245,245,183,0,0,0,0,192,101,16,184,3,0,0,0,192,246,91,109,126,197,245,119,213,243,137,220,0,96,74,14,54,191,228,126,191,41,0,0,0,0,224,243,237,53,1,0,0,0,0,108,155,
3,213,151,170,123,171,125,230,0,128,201,90,174,30,173,78,86,255,206,28,0,0,0,0,176,57,23,220,1,0,0,0,96,235,29,173,158,168,254,177,122,48,113,59,0,48,119,103,245,139,245,255,175,0,0,0,0,0,108,192,5,119,
0,0,0,0,216,58,215,87,15,84,119,152,2,0,216,196,241,230,215,220,1,0,0,0,128,13,8,220,1,0,0,0,224,218,221,84,61,84,157,50,5,0,0,0,0,0,0,92,61,129,59,0,0,0,0,92,157,165,234,206,234,75,213,9,115,0,0,0,0,
0,0,192,181,19,184,3,0,0,0,192,149,89,169,206,84,15,84,135,205,1,0,0,0,0,0,0,91,71,224,14,0,0,0,0,151,103,95,117,111,243,139,237,7,204,1,0,0,0,0,0,0,91,79,224,14,0,0,0,0,151,182,191,121,212,126,95,243,
200,29,0,0,0,0,0,0,216,38,2,119,0,0,0,0,216,216,129,234,193,234,158,106,213,28,0,0,0,0,0,0,176,253,4,238,0,0,0,0,112,161,67,205,195,246,51,213,138,57,0,0,0,0,0,0,96,231,8,220,1,0,0,0,96,238,72,243,176,
253,238,106,217,28,0,0,0,0,0,0,176,243,4,238,0,0,0,0,76,221,117,205,195,246,187,170,37,115,0,0,0,0,0,0,192,238,17,184,3,0,0,0,48,85,215,85,15,53,15,219,1,0,0,0,0,0,128,1,16,184,3,0,0,0,48,53,231,46,182,
223,109,10,0,0,0,0,0,0,24,22,129,59,0,0,0,0,83,113,164,122,184,249,197,246,37,115,0,0,0,0,0,0,192,240,8,220,1,0,0,0,24,187,35,213,67,205,47,182,11,219,1,0,0,0,0,0,96,192,4,238,0,0,0,0,140,213,225,230,
97,251,153,132,237,0,0,0,0,0,0,176,16,4,238,0,0,0,0,140,205,161,234,225,230,23,219,151,205,1,0,0,0,0,0,0,139,67,224,14,0,0,0,192,88,28,108,30,182,159,73,216,14,0,0,0,0,0,0,11,73,224,14,0,0,0,192,162,219,
87,61,88,221,87,173,154,3,0,0,0,0,0,0,22,151,192,29,0,0,0,128,69,181,82,221,223,60,110,223,103,14,0,0,0,0,0,0,88,124,2,119,0,0,0,0,22,205,114,117,166,122,184,58,104,14,0,0,0,0,0,0,24,15,129,59,0,0,0,0,
139,228,174,234,43,213,17,83,0,0,0,0,0,0,192,248,8,220,1,0,0,0,88,4,183,86,143,84,199,77,1,0,0,0,0,0,0,227,37,112,7,0,0,0,96,200,110,172,190,89,157,52,5,0,0,0,0,0,0,140,159,192,29,0,0,0,128,33,58,214,
60,108,191,217,20,0,0,0,0,0,0,48,29,123,76,0,0,0,0,192,128,28,172,158,172,126,149,184,29,0,0,0,0,0,0,38,199,5,119,0,0,0,0,134,96,181,122,176,186,127,253,125,0,0,0,0,0,0,96,130,4,238,0,0,0,0,236,166,165,
234,158,234,225,230,215,219,1,0,0,0,0,0,128,9,19,184,3,0,0,0,176,91,110,171,30,169,142,153,2,0,0,0,0,0,0,40,129,59,0,0,0,0,59,239,100,245,245,234,148,41,0,0,0,0,0,0,128,243,237,49,1,0,0,0,0,59,228,72,
245,76,245,139,196,237,0,0,0,0,0,0,192,6,92,112,7,0,0,0,96,187,173,86,15,86,15,84,203,230,0,0,0,0,0,0,0,54,35,112,7,0,0,0,96,59,157,169,30,169,14,154,2,0,0,0,0,0,0,248,60,2,119,0,0,0,0,182,195,169,234,
209,234,132,41,0,0,0,0,0,0,128,203,181,199,4,0,0,0,0,108,161,163,213,243,213,43,137,219,1,0,0,0,0,0,128,43,228,130,59,0,0,0,0,91,97,181,122,168,250,82,181,108,14,0,0,0,0,0,0,224,106,8,220,1,0,0,0,184,
86,103,170,71,170,131,166,0,0,0,0,0,0,0,174,133,192,29,0,0,0,128,171,117,170,122,180,58,97,10,0,0,0,0,0,0,96,43,236,49,1,0,0,0,0,87,232,96,245,76,245,74,226,118,0,0,0,0,0,0,96,11,9,220,1,0,0,0,184,92,
75,213,253,213,111,171,59,205,1,0,0,0,0,0,0,108,181,189,38,0,0,0,0,224,50,220,80,61,158,139,237,0,0,0,0,0,0,192,54,114,193,29,0,0,0,128,75,217,95,61,89,253,44,113,59,0,0,0,0,0,0,176,205,4,238,0,0,0,0,
108,230,158,234,119,213,25,83,0,0,0,0,0,0,0,59,97,175,9,0,0,0,0,184,200,137,234,137,234,164,41,0,0,0,0,0,0,128,157,228,130,59,0,0,0,0,231,236,171,30,171,126,153,184,29,0,0,0,0,0,0,216,5,46,184,3,0,0,0,
80,117,103,245,205,234,160,41,0,0,0,0,0,0,128,221,34,112,7,0,0,0,152,182,99,205,175,182,159,54,5,0,0,0,0,0,0,176,219,246,152,0,0,0,0,96,146,86,171,175,86,175,39,110,7,0,0,0,0,0,0,6,194,5,119,0,0,0,128,
233,185,173,122,180,58,108,10,0,0,0,0,0,0,96,72,4,238,0,0,0,0,211,113,180,121,216,126,139,41,0,0,0,0,0,0,128,33,18,184,3,0,0,0,140,223,74,245,64,245,224,250,251,0,0,0,0,0,0,0,131,36,112,7,0,0,0,24,183,
155,171,199,154,95,111,7,0,0,0,0,0,0,24,180,61,38,0,0,0,0,24,165,67,213,115,213,75,137,219,1,0,0,0,0,0,128,5,33,112,7,0,0,0,24,159,123,170,223,84,183,155,2,0,0,0,0,0,0,88,36,123,77,0,0,0,0,48,26,215,85,
79,84,167,76,1,0,0,0,0,0,0,44,34,23,220,1,0,0,0,22,223,82,245,96,245,122,226,118,0,0,0,0,0,0,96,129,185,224,14,0,0,0,176,216,142,87,79,87,39,76,1,0,0,0,0,0,0,44,58,23,220,1,0,0,0,22,211,74,245,213,230,
87,219,79,152,3,0,0,0,0,0,0,24,3,23,220,1,0,0,0,22,207,169,234,137,234,58,83,0,0,0,0,0,0,0,99,226,130,59,0,0,0,192,226,216,87,61,94,189,146,184,29,0,0,0,0,0,0,24,33,23,220,1,0,0,0,22,195,205,213,147,213,
33,83,0,0,0,0,0,0,0,99,229,130,59,0,0,0,192,176,237,171,158,170,94,74,220,14,0,0,0,0,0,0,140,156,11,238,0,0,0,0,195,229,106,59,0,0,0,0,0,0,48,41,46,184,3,0,0,0,12,207,190,234,137,92,109,7,0,0,0,0,0,0,
38,198,5,119,0,0,0,128,97,113,181,29,0,0,0,0,0,0,152,44,23,220,1,0,0,0,134,97,53,87,219,1,0,0,0,0,0,128,137,115,193,29,0,0,0,96,247,221,92,61,94,29,49,5,0,0,0,0,0,0,48,101,46,184,3,0,0,0,236,158,243,175,
182,139,219,1,0,0,0,0,0,128,201,115,193,29,0,0,0,96,119,156,170,158,74,216,14,0,0,0,0,0,0,240,207,92,112,7,0,0,0,216,89,203,213,87,171,87,18,183,3,0,0,0,0,0,0,92,192,5,119,0,0,0,128,157,115,188,122,102,
253,45,0,0,0,0,0,0,0,23,113,193,29,0,0,0,96,103,124,169,250,101,226,118,0,0,0,0,0,0,128,77,185,224,14,0,0,0,176,189,14,87,79,87,167,76,1,0,0,0,0,0,0,112,105,46,184,3,0,0,0,108,159,59,171,95,37,110,7,0,
0,0,0,0,0,184,44,46,184,3,0,0,0,108,189,125,213,83,213,109,166,0,0,0,0,0,0,0,184,124,46,184,3,0,0,0,108,173,155,171,223,36,110,7,0,0,0,0,0,0,184,98,2,119,0,0,0,128,173,177,82,61,86,189,84,29,50,7,0,0,
0,0,0,0,192,149,219,107,2,0,0,0,128,107,118,93,245,92,117,220,20,0,0,0,0,0,0,0,87,207,5,119,0,0,0,128,107,115,111,245,122,226,118,0,0,0,0,0,0,128,107,230,130,59,0,0,0,192,213,217,87,61,85,221,102,10,0,
0,0,0,0,0,128,173,33,112,7,0,0,0,184,114,167,170,103,170,67,166,0,0,0,0,0,0,0,216,58,123,76,0,0,0,0,112,217,150,170,175,84,63,78,220,14,0,0,0,0,0,0,176,229,92,112,7,0,0,0,184,60,71,154,95,109,191,193,
20,0,0,0,0,0,0,0,219,195,5,119,0,0,0,128,207,119,123,245,122,226,118,0,0,0,0,0,0,128,109,229,130,59,0,0,0,219,102,54,155,25,129,69,183,90,61,86,221,109,10,0,0,0,0,0,0,128,237,39,112,7,0,0,0,216,216,137,
234,217,234,58,83,0,0,0,0,0,0,0,236,140,61,38,0,0,0,0,248,140,251,171,95,36,110,7,0,0,0,0,0,0,216,81,46,184,3,0,0,0,124,234,64,245,84,117,139,41,0,0,0,0,0,0,0,118,158,192,29,0,0,0,96,238,116,245,116,117,
200,20,0,0,0,0,0,0,0,187,99,143,9,0,0,0,128,137,91,170,30,169,126,156,184,29,0,0,0,0,0,0,96,87,185,224,14,0,0,0,76,217,145,234,153,234,6,83,0,0,0,0,0,0,0,236,62,23,220,1,0,0,128,169,186,189,122,61,113,
59,0,0,0,0,0,0,192,96,8,220,1,0,0,128,169,89,169,158,170,158,171,246,153,3,0,0,0,0,0,0,96,56,246,154,0,0,0,0,152,144,235,170,231,171,99,166,0,0,0,0,0,0,0,24,30,23,220,1,0,0,128,169,184,179,250,101,226,
118,0,0,0,0,0,0,128,193,18,184,3,0,0,0,99,183,82,61,81,61,83,173,154,3,0,0,0,0,0,0,96,184,246,154,0,0,0,0,24,177,163,213,115,213,9,83,0,0,0,0,0,0,0,12,159,11,238,0,0,0,192,88,221,94,189,158,184,29,0,0,
0,0,0,0,96,97,8,220,1,0,0,128,177,89,174,30,107,126,185,125,213,28,0,0,0,0,0,0,0,139,99,175,9,0,0,0,128,17,57,210,60,108,191,222,20,0,0,0,0,0,0,0,139,199,5,119,0,0,0,96,44,110,173,94,79,220,14,0,0,0,0,
0,0,176,176,4,238,0,0,0,192,162,91,170,190,94,189,80,237,51,7,0,0,0,0,0,0,192,226,218,107,2,0,0,0,96,129,29,168,158,173,78,155,2,0,0,0,0,0,0,96,241,9,220,1,0,0,128,69,117,178,122,174,58,108,10,0,0,0,0,
0,0,128,113,216,99,2,0,0,0,96,1,221,83,253,52,113,59,0,0,0,0,0,0,192,168,184,224,14,0,0,0,44,146,229,234,177,230,129,59,0,0,0,0,0,0,0,35,35,112,7,0,0,0,22,197,225,234,185,234,164,41,0,0,0,0,0,0,0,198,
105,143,9,0,0,0,128,5,112,186,250,101,226,118,0,0,0,0,0,0,128,81,19,184,3,0,0,0,67,247,64,245,114,117,192,20,0,0,0,0,0,0,0,227,182,215,4,0,0,0,192,64,173,86,79,87,183,153,2,0,0,0,0,0,0,96,26,4,238,0,0,
0,192,16,29,174,94,172,142,155,2,0,0,0,0,0,0,96,58,246,152,0,0,0,0,24,152,83,213,235,137,219,1,0,0,0,0,0,0,38,71,224,14,0,0,0,12,201,125,213,203,213,126,83,0,0,0,0,0,0,0,76,207,94,19,0,0,0,0,3,176,92,
61,90,221,107,10,0,0,0,0,0,0,128,233,18,184,3,0,0,0,187,237,64,245,92,117,202,20,0,0,0,0,0,0,0,211,38,112,7,0,0,0,118,211,241,234,197,234,176,41,0,0,0,0,0,0,0,216,99,2,0,0,0,96,151,220,94,253,44,113,59,
0,0,0,0,0,0,0,235,4,238,0,0,0,192,110,248,74,245,92,181,106,10,0,0,0,0,0,0,0,206,217,107,2,0,0,0,96,7,173,84,79,55,191,222,14,0,0,0,0,0,0,0,23,16,184,3,0,0,0,59,229,96,245,66,117,210,20,0,0,0,0,0,0,0,
108,68,224,14,0,0,0,236,132,227,213,139,213,97,83,0,0,0,0,0,0,0,176,153,61,38,0,0,0,0,182,217,205,213,207,18,183,3,0,0,0,0,0,0,240,57,4,238,0,0,0,192,118,186,175,249,229,246,85,83,0,0,0,0,0,0,0,240,121,
246,154,0,0,0,0,216,6,75,213,163,205,3,119,0,0,0,0,0,0,0,184,44,2,119,0,0,0,96,171,173,86,207,85,55,155,2,0,0,0,0,0,0,128,43,33,112,7,0,0,0,182,210,225,234,197,234,184,41,0,0,0,0,0,0,0,184,82,123,76,0,
0,0,0,108,145,147,213,47,18,183,3,0,0,0,0,0,0,112,149,4,238,0,0,0,192,86,184,185,122,165,58,104,10,0,0,0,0,0,0,0,174,150,192,29,0,0,0,184,86,103,170,23,171,21,83,0,0,0,0,0,0,0,112,45,4,238,0,0,0,192,181,
248,74,245,100,181,100,10,0,0,0,0,0,0,0,174,213,94,19,0,0,0,0,87,97,169,121,216,126,183,41,0,0,0,0,0,0,0,216,42,2,119,0,0,0,224,74,173,86,207,85,55,155,2,0,0,0,0,0,0,128,173,36,112,7,0,0,0,174,196,193,
234,133,234,164,41,0,0,0,0,0,0,0,216,106,2,119,0,0,0,224,114,29,173,94,174,142,152,2,0,0,0,0,0,0,128,237,176,199,4,0,0,0,192,101,56,89,253,44,113,59,0,0,0,0,0,0,0,219,72,224,14,0,0,0,124,158,91,170,87,
170,3,166,0,0,0,0,0,0,0,96,59,9,220,1,0,0,128,75,57,83,189,80,173,152,2,0,0,0,0,0,0,128,237,38,112,7,0,0,0,54,243,165,234,201,106,201,20,0,0,0,0,0,0,0,236,4,129,59,0,0,0,176,145,175,87,223,52,3,0,0,0,
0,0,0,0,59,105,175,9,0,0,0,128,243,44,85,79,84,103,76,1,0,0,0,0,0,0,192,78,19,184,3,0,0,0,231,44,87,207,86,183,153,2,0,0,0,0,0,0,128,221,32,112,7,0,0,0,170,86,171,23,170,211,166,0,0,0,0,0,0,0,96,183,8,
220,1,0,0,128,253,213,75,213,73,83,0,0,0,0,0,0,0,176,155,4,238,0,0,0,48,109,135,170,151,171,99,166,0,0,0,0,0,0,0,96,183,9,220,1,0,0,96,186,142,86,63,174,14,155,2,0,0,0,0,0,0,128,33,216,99,2,0,0,0,152,
164,19,213,79,19,183,3,0,0,0,0,0,0,48,32,46,184,3,0,0,192,244,92,95,189,92,237,55,5,0,0,0,0,0,0,0,67,226,130,59,0,0,0,76,203,13,213,143,19,183,3,0,0,0,0,0,0,48,64,2,119,0,0,0,152,142,83,205,47,183,239,
51,5,0,0,0,0,0,0,0,67,36,112,7,0,0,128,105,184,185,122,169,90,53,5,0,0,0,0,0,0,0,67,37,112,7,0,0,128,241,187,181,122,161,90,49,5,0,0,0,0,0,0,0,67,38,112,7,0,0,128,113,187,189,122,174,90,54,5,0,0,0,0,0,
0,0,67,39,112,7,0,0,128,241,186,179,122,54,113,59,0,0,0,0,0,0,0,11,66,224,14,0,0,0,227,116,166,122,186,90,50,5,0,0,0,0,0,0,0,139,66,224,14,0,0,0,227,115,95,245,100,226,118,0,0,0,0,0,0,0,22,140,192,29,
0,0,0,198,229,222,234,49,51,0,0,0,0,0,0,0,176,136,4,238,0,0,0,48,30,247,86,143,155,1,0,0,0,0,0,0,128,69,37,112,7,0,0,128,113,184,39,113,59,0,0,0,0,0,0,0,11,78,224,14,0,0,0,139,239,76,245,132,25,0,0,0,
0,0,0,0,88,116,2,119,0,0,0,88,108,119,87,79,154,1,0,0,0,0,0,0,128,49,16,184,3,0,0,192,226,186,187,122,202,12,0,0,0,0,0,0,0,140,133,192,29,0,0,0,22,211,93,185,220,14,0,0,0,0,0,0,192,200,8,220,1,0,0,96,
241,220,213,252,114,251,146,41,0,0,0,0,0,0,0,24,19,129,59,0,0,0,44,150,59,18,183,3,0,0,0,0,0,0,48,82,2,119,0,0,0,88,28,183,87,207,36,110,7,0,0,0,0,0,0,96,164,4,238,0,0,0,176,24,110,73,220,14,0,0,0,0,0,
0,192,200,9,220,1,0,0,96,248,78,85,207,85,203,166,0,0,0,0,0,0,0,96,204,4,238,0,0,0,48,108,39,171,23,171,21,83,0,0,0,0,0,0,0,48,118,2,119,0,0,0,24,174,227,213,75,213,170,41,0,0,0,0,0,0,0,152,2,129,59,0,
0,0,12,211,209,234,199,213,126,83,0,0,0,0,0,0,0,48,21,2,119,0,0,0,24,158,195,213,43,213,1,83,0,0,0,0,0,0,0,48,37,2,119,0,0,0,24,150,131,205,47,183,31,50,5,0,0,0,0,0,0,0,83,35,112,7,0,0,128,225,56,80,189,
92,29,53,5,0,0,0,0,0,0,0,83,36,112,7,0,0,128,97,216,87,189,88,29,55,5,0,0,0,0,0,0,0,83,37,112,7,0,0,128,221,183,92,61,95,157,52,5,0,0,0,0,0,0,0,83,38,112,7,0,0,128,221,181,84,61,83,157,54,5,0,0,0,0,0,
0,0,83,39,112,7,0,0,128,221,245,88,117,187,25,0,0,0,0,0,0,0,64,224,14,0,0,0,187,233,193,234,94,51,0,0,0,0,0,0,0,192,156,192,29,0,0,0,118,199,189,213,87,205,0,0,0,0,0,0,0,0,159,18,184,3,0,0,192,206,187,
181,122,204,12,0,0,0,0,0,0,0,112,33,129,59,0,0,0,236,172,27,171,103,171,37,83,0,0,0,0,0,0,0,192,133,4,238,0,0,0,176,115,142,87,47,86,43,166,0,0,0,0,0,0,0,128,207,18,184,3,0,0,192,206,56,84,189,84,237,
51,5,0,0,0,0,0,0,0,108,76,224,14,0,0,0,219,239,64,245,74,243,200,29,0,0,0,0,0,0,0,216,132,192,29,0,0,0,182,215,114,245,92,117,212,20,0,0,0,0,0,0,0,112,105,2,119,0,0,0,216,94,79,85,167,204,0,0,0,0,0,0,
0,0,159,79,224,14,0,0,0,219,231,171,213,157,102,0,0,0,0,0,0,0,128,203,35,112,7,0,0,128,237,113,166,122,208,12,0,0,0,91,238,35,19,0,0,0,0,140,151,192,29,0,0,0,182,222,233,234,113,51,0,0,0,108,139,179,38,
0,0,0,0,24,47,129,59,0,0,0,108,173,227,213,243,213,178,41,0,0,0,0,0,0,0,224,202,8,220,1,0,0,96,235,28,170,94,170,246,153,2,0,0,0,0,0,0,0,174,156,192,29,0,0,0,182,198,74,243,203,237,135,76,1,0,0,0,0,0,
0,0,87,71,224,14,0,0,0,215,110,169,122,182,58,105,10,0,0,128,109,247,161,9,0,0,0,0,198,75,224,14,0,0,0,215,238,155,213,173,102,0,0,0,216,17,103,77,0,0,0,0,48,94,2,119,0,0,0,184,54,103,170,251,205,0,0,
0,176,99,62,50,1,0,0,0,192,120,9,220,1,0,0,224,234,221,88,61,110,6,0,0,128,29,229,130,59,0,0,0,192,136,9,220,1,0,0,224,234,28,174,158,175,150,77,1,0,0,176,163,92,112,7,0,0,0,24,49,129,59,0,0,0,92,185,
149,234,197,234,128,41,0,0,0,118,220,39,38,0,0,0,0,24,47,129,59,0,0,0,92,185,103,170,227,102,0,0,0,216,21,46,184,3,0,0,0,140,152,192,29,0,0,0,174,204,195,213,109,102,0,0,0,216,21,103,19,184,3,0,0,0,140,
218,108,109,109,205,10,0,0,0,108,207,147,206,217,108,108,255,72,183,85,207,251,55,11,0,0,176,107,62,172,254,165,215,56,1,0,0,0,198,203,5,119,0,0,0,184,60,199,171,103,204,0,0,0,176,171,62,52,1,0,0,0,192,
184,9,220,1,0,0,224,243,29,168,94,172,86,76,1,0,0,176,171,4,238,0,0,0,0,35,39,112,7,0,0,128,75,91,174,158,175,14,155,2,0,0,96,215,125,100,2,0,0,0,128,113,19,184,3,0,0,192,165,125,189,186,209,12,0,0,0,
131,224,130,59,0,0,0,192,200,9,220,1,0,0,96,115,119,84,247,155,1,0,0,96,48,222,55,1,0,0,0,192,184,9,220,1,0,0,96,99,199,170,39,205,0,0,0,48,40,31,152,0,0,0,0,96,220,4,238,0,0,0,240,89,251,170,231,171,
85,83,0,0,0,12,138,192,29,0,0,0,96,228,4,238,0,0,0,240,89,79,85,215,153,1,0,0,96,112,4,238,0,0,0,0,35,39,112,7,0,0,128,11,61,88,221,102,6,0,0,128,65,122,223,4,0,0,0,0,227,38,112,7,0,0,128,79,221,84,61,
98,6,0,0,128,193,18,184,3,0,0,0,140,156,192,29,0,0,0,230,14,85,207,84,75,166,0,0,0,24,172,119,77,0,0,0,0,48,110,2,119,0,0,0,168,229,234,185,234,128,41,0,0,0,6,205,5,119,0,0,0,128,145,19,184,3,0,0,64,61,
90,221,96,6,0,0,128,65,251,164,250,192,12,0,0,0,0,227,38,112,7,0,0,96,234,238,168,238,53,3,0,0,192,224,189,103,2,0,0,0,128,241,19,184,3,0,0,48,101,71,170,39,204,0,0,0,176,16,4,238,0,0,0,0,19,32,112,7,
0,0,96,170,150,171,103,171,125,166,0,0,0,88,8,239,154,0,0,0,0,96,252,4,238,0,0,0,76,213,35,213,73,51,0,0,0,44,140,119,76,0,0,0,0,48,126,2,119,0,0,0,166,232,150,234,1,51,0,0,0,44,20,129,59,0,0,0,192,4,
8,220,1,0,0,152,154,195,213,211,102,0,0,0,88,56,239,154,0,0,0,0,96,252,4,238,0,0,0,76,201,82,245,76,181,223,20,0,0,0,11,199,5,119,0,0,0,128,9,16,184,3,0,0,48,37,95,169,110,52,3,0,0,192,66,18,184,3,0,0,
0,76,192,108,109,109,205,10,0,0,0,108,207,147,206,217,108,72,191,156,211,213,203,205,175,184,3,0,0,176,88,62,169,254,69,117,182,202,107,156,0,0,0,0,227,229,130,59,0,0,0,83,112,160,122,38,113,59,0,0,192,
162,122,187,245,184,29,0,0,0,128,113,19,184,3,0,0,48,5,79,85,7,205,0,0,0,176,176,222,49,1,0,0,0,192,52,8,220,1,0,0,24,187,123,170,91,204,0,0,0,176,208,222,54,1,0,0,0,192,52,8,220,1,0,0,24,179,235,170,
111,154,1,0,0,96,225,253,193,4,0,0,0,0,211,32,112,7,0,0,96,172,150,170,167,171,85,83,0,0,0,44,60,23,220,1,0,0,0,38,66,224,14,0,0,192,88,61,92,157,52,3,0,0,192,40,8,220,1,0,0,0,38,98,182,182,182,102,5,
0,0,0,182,231,73,231,108,182,91,95,250,100,245,179,230,87,220,1,0,0,88,108,103,171,127,81,125,114,238,3,94,227,4,0,0,0,24,47,23,220,1,0,0,24,155,213,234,153,196,237,0,0,0,99,241,86,231,197,237,0,0,0,0,
140,155,192,29,0,0,128,177,121,180,58,106,6,0,0,128,209,120,219,4,0,0,0,0,211,33,112,7,0,0,96,76,110,173,206,152,1,0,0,96,84,222,50,1,0,0,0,192,116,8,220,1,0,0,24,139,3,213,147,102,0,0,0,24,29,129,59,
0,0,0,192,132,8,220,1,0,0,24,139,39,154,71,238,0,0,0,140,203,175,77,0,0,0,0,48,29,2,119,0,0,0,198,224,142,234,54,51,0,0,0,140,206,217,234,77,51,0,0,0,0,76,199,108,109,109,205,10,0,0,0,108,207,147,206,
217,108,39,190,204,254,234,183,185,222,14,0,0,48,70,111,87,255,250,226,15,122,141,19,0,0,0,96,188,92,112,7,0,0,96,209,61,158,184,29,0,0,96,172,126,109,2,0,0,0,128,105,17,184,3,0,0,176,200,110,171,238,
48,3,0,0,192,104,189,105,2,0,0,0,128,105,17,184,3,0,0,176,168,246,55,191,222,14,0,0,192,120,189,97,2,0,0,0,128,105,17,184,3,0,0,176,168,30,173,14,154,1,0,0,96,212,222,48,1,0,0,0,192,180,204,214,214,214,
172,0,0,0,192,246,60,233,156,205,182,235,167,190,181,122,193,194,0,0,0,163,246,97,245,47,55,250,132,215,56,1,0,0,0,198,203,5,119,0,0,0,22,205,190,234,113,51,0,0,0,140,222,107,38,0,0,0,0,152,30,129,59,
0,0,0,139,230,155,213,33,51,0,0,0,140,222,27,38,0,0,0,0,152,30,129,59,0,0,0,139,228,116,117,198,12,0,0,0,147,224,130,59,0,0,0,192,4,9,220,1,0,0,88,20,203,213,19,102,0,0,0,152,12,129,59,0,0,0,192,4,9,220,
1,0,0,88,20,15,85,71,205,0,0,0,48,9,31,86,111,155,1,0,0,0,96,122,4,238,0,0,0,44,130,163,213,131,102,0,0,0,152,140,127,168,206,154,1,0,0,0,96,122,4,238,0,0,0,44,130,39,171,101,51,0,0,0,76,198,207,77,0,
0,0,0,48,77,2,119,0,0,0,134,238,206,234,148,25,0,0,0,38,229,53,19,0,0,0,0,76,211,108,109,109,205,10,0,0,0,108,207,147,206,217,236,90,127,138,253,213,111,171,3,214,4,0,0,152,148,63,171,222,223,236,147,
94,227,4,0,0,0,24,47,23,220,1,0,0,24,178,71,18,183,3,0,0,76,205,219,93,34,110,7,0,0,0,96,220,4,238,0,0,0,12,213,141,213,189,102,0,0,0,152,156,87,77,0,0,0,0,48,93,2,119,0,0,0,134,104,169,122,204,12,0,0,
0,147,36,112,7,0,0,0,152,48,129,59,0,0,0,67,244,64,117,194,12,0,0,0,147,36,112,7,0,0,0,152,176,217,218,218,154,21,0,0,0,216,158,39,157,179,217,213,252,176,67,213,111,171,85,11,2,0,0,76,206,251,107,107,
107,127,102,6,0,0,0,128,233,114,193,29,0,0,128,161,249,122,226,118,0,0,128,169,114,189,29,0,0,0,96,226,4,238,0,0,0,12,201,137,234,78,51,0,0,0,76,214,223,155,0,0,0,0,96,218,4,238,0,0,0,12,201,99,38,0,0,
0,152,180,159,152,0,0,0,0,96,218,4,238,0,0,0,12,197,157,213,141,102,0,0,0,152,172,15,170,55,205,0,0,0,0,48,109,2,119,0,0,0,134,96,181,250,186,25,0,0,0,38,237,39,213,89,51,0,0,0,0,76,155,192,29,0,0,128,
33,120,168,58,100,6,0,0,128,73,251,137,9,0,0,0,0,152,173,173,173,89,1,0,0,128,237,121,210,57,155,93,206,119,59,82,253,182,90,182,24,0,0,192,164,125,161,122,211,235,151,0,0,0,0,211,230,130,59,0,0,0,187,
237,145,196,237,0,0,0,83,247,78,245,166,25,0,0,0,0,16,184,3,0,0,176,155,110,172,238,52,3,0,0,192,228,253,200,4,0,0,0,0,148,192,29,0,0,128,221,179,84,61,102,6,0,0,0,170,159,152,0,0,0,0,128,18,184,3,0,0,
176,123,238,168,78,152,1,0,0,96,242,206,86,63,52,3,0,0,0,0,37,112,7,0,0,96,119,44,87,143,152,1,0,0,128,234,231,213,7,102,0,0,0,0,160,4,238,0,0,0,236,142,123,171,35,102,0,0,0,160,122,213,4,0,0,0,0,156,
51,91,91,91,179,2,0,0,0,219,243,164,115,54,219,232,195,171,213,63,86,251,45,4,0,0,64,245,23,213,107,231,190,225,245,75,0,0,0,128,105,115,193,29,0,0,128,157,246,64,226,118,0,0,0,230,222,233,188,184,29,
0,0,0,0,4,238,0,0,0,236,164,131,213,151,204,0,0,0,192,186,31,152,0,0,0,0,128,243,9,220,1,0,0,216,73,15,87,171,102,0,0,0,96,157,192,29,0,0,0,128,11,204,214,214,214,172,0,0,0,192,246,60,233,156,205,206,
255,230,209,234,55,213,178,101,0,0,0,168,62,174,254,213,250,219,127,230,245,75,0,0,0,128,105,115,193,29,0,0,128,157,242,72,226,118,0,0,0,62,245,131,46,138,219,1,0,0,0,64,224,14,0,0,192,78,184,190,186,
195,12,0,0,0,156,231,123,38,0,0,0,0,224,98,51,127,197,31,0,0,0,219,246,164,115,54,59,247,238,75,213,205,22,1,0,0,96,221,217,234,207,170,15,46,254,132,215,47,1,0,0,0,166,205,5,119,0,0,0,182,219,201,196,
237,0,0,0,92,232,231,109,16,183,3,0,0,0,128,192,29,0,0,128,237,246,176,9,0,0,0,184,200,15,76,0,0,0,0,192,70,102,254,138,63,0,0,0,182,237,73,231,108,118,178,250,133,37,0,0,0,184,200,255,90,253,97,163,79,
120,253,18,0,0,0,96,218,246,154,0,0,0,96,156,102,179,217,16,126,25,174,183,3,0,0,112,177,95,175,173,173,253,193,12,0,0,0,0,108,100,143,9,0,0,0,216,38,215,87,183,152,1,0,0,128,139,252,157,9,0,0,0,0,216,
140,192,29,0,0,128,237,242,21,19,0,0,0,176,129,239,152,0,0,0,0,128,205,8,220,1,0,0,216,14,174,183,3,0,0,176,145,159,87,127,48,3,0,0,0,0,155,17,184,3,0,0,176,29,30,54,1,0,0,0,27,112,189,29,0,0,0,128,75,
154,173,173,173,89,1,0,0,96,140,79,248,102,179,221,250,210,215,87,191,244,111,0,0,0,128,139,156,173,254,188,122,207,107,148,0,0,0,0,108,198,5,119,0,0,0,182,218,67,38,0,0,0,96,3,127,95,189,103,6,0,0,0,
0,46,69,224,14,0,0,192,86,58,86,221,102,6,0,0,0,54,240,29,19,0,0,0,0,240,121,4,238,0,0,0,108,165,251,77,0,0,0,192,6,62,169,190,107,6,0,0,0,0,62,143,192,29,0,0,128,173,114,176,186,219,12,0,0,0,108,224,
71,213,7,102,0,0,0,0,224,243,8,220,1,0,0,216,42,247,85,203,102,0,0,0,96,3,127,103,2,0,0,0,0,46,199,108,109,109,205,10,0,0,0,99,124,194,55,155,237,228,151,91,173,254,169,218,103,121,0,0,0,46,242,113,245,
175,214,223,86,229,53,74,0,0,0,0,54,227,130,59,0,0,0,91,225,76,226,118,0,0,0,54,246,157,206,139,219,1,0,0,0,224,82,92,112,7,0,0,24,235,19,190,157,187,224,190,84,253,190,58,108,117,0,0,0,54,240,111,170,
87,207,255,128,215,40,1,0,0,0,216,140,11,238,0,0,0,92,171,59,18,183,3,0,0,176,177,183,186,40,110,7,0,0,0,128,75,17,184,3,0,0,112,173,30,48,1,0,0,0,155,248,150,9,0,0,0,0,184,18,51,127,253,31,0,0,192,72,
159,240,205,102,59,241,101,110,170,94,182,54,0,0,0,27,56,91,253,121,245,222,197,159,240,26,37,0,0,0,0,155,113,193,29,0,0,128,107,241,37,19,0,0,0,176,137,239,183,65,220,14,0,0,0,0,151,34,112,7,0,0,224,
106,29,109,126,193,29,0,0,0,54,242,223,76,0,0,0,0,192,149,18,184,3,0,0,112,181,238,169,150,204,0,0,0,192,6,222,173,126,104,6,0,0,0,0,174,148,192,29,0,0,128,171,177,82,157,49,3,0,0,0,155,248,118,117,214,
12,0,0,0,0,92,41,129,59,0,0,0,87,227,142,106,191,25,0,0,0,216,196,127,51,1,0,0,0,0,87,67,224,14,0,0,192,213,184,215,4,0,0,0,108,226,39,213,219,102,0,0,0,0,224,106,8,220,1,0,0,184,82,39,215,31,0,0,0,176,
145,111,153,0,0,0,0,128,171,37,112,7,0,0,224,74,185,222,14,0,0,192,102,222,173,190,107,6,0,0,0,0,174,150,192,29,0,0,128,43,113,160,186,195,12,0,0,0,108,226,111,171,179,102,0,0,0,0,224,106,9,220,1,0,0,
184,18,119,87,43,102,0,0,0,96,3,31,87,223,50,3,0,0,0,0,215,66,224,14,0,0,192,229,90,170,238,49,3,0,0,0,155,248,110,245,190,25,0,0,0,0,184,22,2,119,0,0,0,46,215,233,234,168,25,0,0,0,216,196,127,49,1,0,
0,0,0,215,74,224,14,0,0,192,229,186,219,4,0,0,0,108,226,231,213,27,102,0,0,0,0,224,90,9,220,1,0,0,184,28,251,170,219,204,0,0,0,192,38,254,171,9,0,0,0,0,216,10,2,119,0,0,0,46,199,237,213,138,25,0,0,0,216,
192,123,213,119,205,0,0,0,0,192,86,16,184,3,0,0,112,57,206,152,0,0,0,128,77,252,77,117,214,12,0,0,0,0,108,133,217,218,218,154,21,0,0,0,198,248,132,111,54,219,170,159,234,104,245,59,139,2,0,0,176,129,79,
170,63,175,222,191,146,31,228,53,74,0,0,0,0,54,227,130,59,0,0,0,159,231,46,19,0,0,0,176,137,111,119,133,113,59,0,0,0,0,92,138,11,238,0,0,0,99,125,194,183,53,23,220,151,170,223,87,135,45,10,0,0,192,69,
206,86,95,168,222,186,210,31,232,53,74,0,0,0,0,54,227,130,59,0,0,0,151,114,42,113,59,0,0,0,27,251,94,87,17,183,3,0,0,0,192,165,8,220,1,0,0,184,148,187,77,0,0,0,192,38,190,97,2,0,0,0,0,182,218,204,95,255,
7,0,0,48,210,39,124,179,217,181,254,20,171,213,31,171,21,107,2,0,0,112,145,159,84,255,215,213,254,96,175,81,2,0,0,0,176,25,23,220,1,0,0,216,204,173,137,219,1,0,0,216,216,215,76,0,0,0,0,192,118,16,184,
3,0,0,176,153,59,77,0,0,0,192,6,94,171,126,100,6,0,0,0,0,182,131,192,29,0,0,128,141,236,171,78,155,1,0,0,128,13,184,222,14,0,0,0,192,182,17,184,3,0,0,176,145,91,170,21,51,0,0,0,112,145,183,170,239,153,
1,0,0,0,128,237,34,112,7,0,0,96,35,119,154,0,0,0,128,13,124,163,58,107,6,0,0,0,0,182,203,108,109,109,205,10,0,0,0,99,124,194,55,155,93,237,15,221,87,253,143,92,112,7,0,0,224,66,239,85,255,75,245,201,181,
254,68,94,163,4,0,0,0,96,51,46,184,3,0,0,112,177,91,18,183,3,0,0,240,89,223,104,11,226,118,0,0,0,0,184,20,129,59,0,0,0,23,187,211,4,0,0,0,92,228,221,234,111,205,0,0,0,0,192,118,19,184,3,0,0,112,190,125,
213,105,51,0,0,0,112,145,175,85,31,155,1,0,0,0,128,237,38,112,7,0,0,224,124,183,84,43,102,0,0,0,224,60,239,86,223,50,3,0,0,0,0,59,65,224,14,0,0,192,249,238,48,1,0,0,0,23,249,207,213,39,102,0,0,0,0,96,
39,204,214,214,214,172,0,0,0,48,198,39,124,179,217,149,254,144,149,234,79,185,224,14,0,0,192,167,254,80,253,111,109,113,224,238,53,74,0,0,0,0,54,227,130,59,0,0,0,231,156,78,220,14,0,0,192,133,254,58,215,
219,1,0,0,0,216,65,2,119,0,0,0,206,185,197,4,0,0,0,156,231,237,234,191,155,1,0,0,0,128,157,36,112,7,0,0,224,28,129,59,0,0,0,231,251,235,234,172,25,0,0,0,0,216,73,179,181,181,53,43,0,0,0,140,241,9,223,
108,118,37,223,253,120,245,43,171,1,0,0,176,238,173,234,11,109,83,224,238,53,74,0,0,0,0,54,227,130,59,0,0,0,229,122,59,0,0,0,23,250,79,185,222,14,0,0,0,192,46,16,184,3,0,0,80,2,119,0,0,0,62,245,70,245,
93,51,0,0,0,0,176,27,4,238,0,0,0,172,84,215,155,1,0,0,128,117,127,149,235,237,0,0,0,0,236,18,129,59,0,0,0,167,155,71,238,0,0,0,240,195,245,7,0,0,0,0,236,10,129,59,0,0,0,183,152,0,0,0,128,230,87,219,255,
202,12,0,0,0,0,236,38,129,59,0,0,0,2,119,0,0,0,170,190,93,189,97,6,0,0,0,0,118,211,108,109,109,205,10,0,0,0,99,124,194,55,155,93,206,119,59,94,253,202,90,0,0,0,147,247,113,245,175,171,119,119,226,139,
121,141,18,0,0,0,128,205,184,224,14,0,0,48,109,55,154,0,0,0,128,234,191,182,67,113,59,0,0,0,0,92,138,192,29,0,0,96,218,110,50,1,0,0,192,228,125,80,253,181,25,0,0,0,0,24,2,129,59,0,0,192,116,45,85,167,
204,0,0,0,48,121,95,174,62,50,3,0,0,0,0,67,48,91,91,91,179,2,0,0,192,24,159,240,205,102,159,247,93,78,84,175,91,10,0,0,96,210,222,174,190,80,125,178,147,95,212,107,148,0,0,0,0,108,198,5,119,0,0,128,233,
58,109,2,0,0,128,201,251,203,118,56,110,7,0,0,0,128,75,17,184,3,0,0,76,215,141,38,0,0,0,152,180,87,171,239,153,1,0,0,0,128,33,153,249,235,255,0,0,0,70,250,132,111,54,251,188,239,242,167,106,191,165,0,
0,0,38,233,108,245,23,213,27,187,241,197,189,70,9,0,0,0,192,102,92,112,7,0,0,152,166,99,137,219,1,0,0,166,236,91,237,82,220,14,0,0,0,0,151,34,112,7,0,0,152,166,27,77,0,0,0,48,89,31,84,95,54,3,0,0,0,0,
67,36,112,7,0,0,152,38,129,59,0,0,192,116,125,185,121,228,14,0,0,0,0,131,51,91,91,91,179,2,0,0,192,24,159,240,205,102,151,250,244,239,170,163,86,2,0,0,152,156,87,171,255,179,58,187,155,191,8,175,81,2,
0,0,0,176,25,129,59,0,0,192,88,159,240,109,30,184,239,175,254,100,33,0,0,128,201,57,91,253,69,245,198,110,255,66,188,70,9,0,0,0,192,102,246,152,0,0,0,96,114,78,154,0,0,0,96,146,190,213,0,226,118,0,0,0,
0,184,20,129,59,0,0,192,244,220,96,2,0,0,128,201,249,160,250,178,25,0,0,0,0,24,58,129,59,0,0,192,244,184,224,14,0,0,48,61,95,110,30,185,3,0,0,0,192,160,205,214,214,214,172,0,0,0,48,198,39,124,179,217,
102,159,250,99,117,192,66,0,0,0,147,241,70,245,23,213,217,161,252,130,188,70,9,0,0,0,192,102,92,112,7,0,0,152,150,195,137,219,1,0,0,166,228,108,245,31,26,80,220,14,0,0,0,0,151,34,112,7,0,0,152,150,235,
77,0,0,0,48,41,223,170,94,53,3,0,0,0,0,139,66,224,14,0,0,48,45,39,76,0,0,0,48,25,239,86,127,105,6,0,0,0,0,22,137,192,29,0,0,96,90,92,112,7,0,0,152,142,255,175,250,200,12,0,0,0,0,44,18,129,59,0,0,192,180,
156,48,1,0,0,192,36,124,175,250,190,25,0,0,0,0,88,52,179,181,181,53,43,0,0,0,140,241,9,223,108,118,241,135,246,87,127,178,12,0,0,192,232,125,88,125,161,122,119,168,191,64,175,81,2,0,0,0,176,25,23,220,
1,0,0,166,227,58,19,0,0,0,76,194,95,53,224,184,29,0,0,0,0,46,69,224,14,0,0,48,29,199,76,0,0,0,48,122,175,86,127,107,6,0,0,0,0,22,149,192,29,0,0,96,58,92,112,7,0,0,24,183,79,170,127,111,6,0,0,0,0,22,153,
192,29,0,0,96,58,92,112,7,0,0,24,183,175,85,111,154,1,0,0,0,128,69,54,91,91,91,179,2,0,0,192,24,159,240,205,102,23,127,232,247,213,17,203,0,0,0,140,210,91,213,255,222,252,138,251,224,121,141,18,0,0,0,
128,205,184,224,14,0,0,48,13,203,213,97,51,0,0,0,140,210,217,234,139,45,72,220,14,0,0,0,0,151,34,112,7,0,0,152,134,99,213,146,25,0,0,0,70,233,107,213,63,152,1,0,0,0,128,49,16,184,3,0,0,76,195,117,38,0,
0,0,24,165,95,87,255,217,12,0,0,0,0,140,133,192,29,0,0,96,26,142,153,0,0,0,96,116,62,169,190,184,254,22,0,0,0,0,70,65,224,14,0,0,48,13,46,184,3,0,0,140,207,95,87,111,152,1,0,0,0,128,49,17,184,3,0,0,76,
131,192,29,0,0,96,92,94,171,190,102,6,0,0,0,0,198,70,224,14,0,0,48,13,135,77,0,0,0,48,26,159,84,95,92,127,11,0,0,0,0,163,34,112,7,0,0,24,191,125,213,126,51,0,0,0,140,198,127,170,222,52,3,0,0,0,0,99,36,
112,7,0,0,24,191,35,38,0,0,0,24,141,159,87,223,48,3,0,0,0,0,99,37,112,7,0,0,24,191,195,38,0,0,0,24,133,143,171,127,91,157,53,5,0,0,0,0,99,37,112,7,0,0,24,63,23,220,1,0,0,198,225,47,171,183,204,0,0,0,0,
192,152,9,220,1,0,0,198,239,160,9,0,0,0,22,222,15,170,191,49,3,0,0,0,0,99,39,112,7,0,0,24,191,195,38,0,0,0,88,104,239,85,255,214,12,0,0,0,0,76,129,192,29,0,0,96,252,92,112,7,0,0,88,108,95,172,222,55,3,
0,0,0,0,83,32,112,7,0,0,24,191,67,38,0,0,0,88,88,223,168,126,100,6,0,0,0,0,166,98,182,182,182,102,5,0,0,128,49,62,225,155,205,206,189,251,255,87,43,22,1,0,0,88,56,111,84,255,71,245,201,216,254,193,188,
70,9,0,0,0,192,102,92,112,7,0,0,24,183,149,196,237,0,0,0,139,232,163,234,255,105,132,113,59,0,0,0,0,92,138,192,29,0,0,96,220,14,154,0,0,0,96,33,253,199,234,45,51,0,0,0,0,48,53,2,119,0,0,128,113,59,96,
2,0,0,128,133,243,221,234,91,102,0,0,0,0,96,138,4,238,0,0,0,227,182,223,4,0,0,0,11,229,157,234,223,155,1,0,0,0,128,169,18,184,3,0,0,140,219,65,19,0,0,0,44,140,179,213,255,91,125,96,10,0,0,0,0,166,74,224,
14,0,0,48,110,46,184,3,0,0,44,142,47,87,175,154,1,0,0,0,128,41,19,184,3,0,0,140,219,62,19,0,0,0,44,132,31,84,95,51,3,0,0,0,0,83,39,112,7,0,0,24,55,129,59,0,0,192,240,189,83,125,209,12,0,0,0,0,32,112,7,
0,0,24,59,129,59,0,0,192,176,125,82,253,223,213,7,166,0,0,0,0,0,129,59,0,0,192,216,9,220,1,0,0,134,237,63,86,255,96,6,0,0,0,0,152,19,184,3,0,0,140,155,192,29,0,0,96,184,190,83,253,141,25,0,0,0,0,224,83,
2,119,0,0,128,113,91,53,1,0,0,192,32,189,85,253,59,51,0,0,0,0,192,133,4,238,0,0,0,227,182,98,2,0,0,128,193,249,184,255,217,222,221,135,216,121,159,119,30,254,28,11,4,2,131,193,96,8,4,12,94,92,12,9,46,
54,49,14,13,45,9,49,49,54,53,9,107,106,106,18,26,34,26,18,106,106,18,18,26,214,212,108,105,104,168,217,176,166,6,179,161,162,102,77,205,138,154,138,24,76,77,69,205,138,53,43,42,42,106,86,84,172,64,84,
68,84,84,84,84,172,168,96,216,129,97,135,217,63,158,81,228,216,58,214,219,188,60,231,57,215,5,135,25,73,163,121,249,30,255,225,251,247,251,234,62,245,116,181,34,10,0,0,0,0,248,69,10,238,0,0,0,211,166,
224,14,0,0,48,62,207,85,167,196,0,0,0,0,0,31,165,224,14,0,0,48,109,123,69,0,0,0,48,42,175,85,175,139,1,0,0,0,0,174,109,182,177,177,33,5,0,0,128,41,14,124,179,89,213,191,85,119,73,3,0,0,96,20,142,87,191,
86,173,45,123,16,238,40,1,0,0,0,152,199,6,119,0,0,0,0,0,0,216,126,23,170,167,83,110,7,0,0,0,128,143,165,224,14,0,0,48,109,182,183,3,0,0,236,190,181,234,153,234,188,40,0,0,0,0,224,227,41,184,3,0,0,0,0,
0,192,246,122,190,58,42,6,0,0,0,0,184,62,5,119,0,0,0,0,0,0,216,62,7,54,31,0,0,0,0,192,13,152,109,108,108,72,1,0,0,96,138,3,223,108,86,101,232,3,0,0,216,61,71,171,199,170,53,81,252,34,119,148,0,0,0,0,204,
163,224,14,0,0,48,213,129,111,54,219,83,253,63,73,0,0,0,236,138,243,213,35,213,5,81,124,148,59,74,0,0,0,0,230,185,67,4,0,0,0,147,181,71,4,0,0,0,187,98,173,122,58,229,118,0,0,0,0,184,105,10,238,0,0,0,211,
181,38,2,0,0,128,93,241,237,234,184,24,0,0,0,0,224,230,41,184,3,0,0,0,0,0,192,214,121,165,122,93,12,0,0,0,0,112,107,102,27,27,27,82,0,0,0,152,226,192,55,155,85,25,250,0,0,0,118,206,145,234,241,106,93,
20,31,207,29,37,0,0,0,0,243,216,224,14,0,0,48,109,43,34,0,0,0,216,17,39,171,167,83,110,7,0,0,0,128,219,162,224,14,0,0,48,109,138,21,0,0,0,219,239,98,67,185,253,178,40,0,0,0,0,224,246,40,184,3,0,0,0,0,
0,192,173,91,171,158,170,206,136,2,0,0,0,0,110,159,130,59,0,0,192,180,173,138,0,0,0,96,91,237,175,142,139,1,0,0,0,0,182,134,130,59,0,0,192,180,41,184,3,0,0,108,159,23,171,131,98,0,0,0,0,128,173,163,224,
14,0,0,48,109,43,34,0,0,0,216,22,7,171,31,137,1,0,0,0,0,182,150,130,59,0,0,192,180,41,184,3,0,0,108,189,163,213,126,49,0,0,0,0,192,214,83,112,7,0,0,152,54,5,119,0,0,128,173,117,166,122,186,90,19,5,0,0,
0,0,108,61,5,119,0,0,128,105,91,21,1,0,0,192,150,185,92,61,85,93,20,5,0,0,0,0,108,15,5,119,0,0,128,105,179,193,29,0,0,96,107,172,53,108,110,63,45,10,0,0,0,0,216,62,10,238,0,0,0,211,118,73,4,0,0,0,183,
109,189,122,182,58,34,10,0,0,0,0,216,94,10,238,0,0,0,211,166,224,14,0,0,112,251,158,175,222,18,3,0,0,0,0,108,63,5,119,0,0,128,105,83,112,7,0,0,184,61,47,85,63,17,3,0,0,0,0,236,12,5,119,0,0,128,105,83,
112,7,0,0,184,117,7,171,23,196,0,0,0,0,0,59,71,193,29,0,0,96,218,46,138,0,0,0,224,150,188,91,237,23,3,0,0,0,0,236,44,5,119,0,0,128,105,179,193,29,0,0,224,230,29,175,190,82,173,137,2,0,0,0,0,118,150,130,
59,0,0,192,180,41,184,3,0,0,220,156,51,213,83,213,170,40,0,0,0,0,96,231,41,184,3,0,0,76,219,121,17,0,0,0,220,176,139,213,147,155,111,1,0,0,0,128,93,160,224,14,0,0,48,109,171,213,101,49,0,0,0,92,215,74,
195,230,246,51,162,0,0,0,0,128,221,163,224,14,0,0,48,125,182,184,3,0,0,124,188,213,234,43,213,113,81,0,0,0,0,192,238,82,112,7,0,0,152,62,5,119,0,0,128,249,214,170,103,171,35,162,0,0,0,0,128,221,167,224,
14,0,0,48,125,10,238,0,0,0,215,182,94,237,175,222,22,5,0,0,0,0,140,131,130,59,0,0,192,244,41,184,3,0,0,92,219,115,213,65,49,0,0,0,0,192,120,40,184,3,0,0,76,159,130,59,0,0,192,71,189,80,29,16,3,0,0,0,0,
140,139,130,59,0,0,192,244,157,19,1,0,0,192,47,120,105,243,1,0,0,0,0,140,140,130,59,0,0,192,244,157,21,1,0,0,192,207,253,164,97,123,59,0,0,0,0,48,66,179,141,141,13,41,0,0,0,76,113,224,155,205,174,188,
187,175,250,191,18,1,0,0,232,96,245,53,49,236,62,119,148,0,0,0,0,204,99,131,59,0,0,192,244,173,86,231,197,0,0,0,44,185,183,171,175,139,1,0,0,0,0,198,77,193,29,0,0,96,57,156,17,1,0,0,176,196,222,173,158,
169,214,69,1,0,0,0,0,227,166,224,14,0,0,176,28,78,139,0,0,0,88,82,239,86,95,169,214,68,1,0,0,0,0,227,167,224,14,0,0,176,28,206,138,0,0,0,88,66,239,53,148,219,87,69,1,0,0,0,0,139,65,193,29,0,0,96,57,156,
18,1,0,0,176,100,142,86,79,166,220,14,0,0,0,0,11,69,193,29,0,0,96,57,156,20,1,0,0,176,68,142,86,143,167,220,14,0,0,0,0,11,103,182,177,177,33,5,0,0,128,41,14,124,179,217,7,127,185,167,250,183,234,78,201,
0,0,0,19,119,172,161,220,190,34,138,241,114,71,9,0,0,0,192,60,54,184,3,0,0,44,135,245,234,180,24,0,0,128,137,83,110,7,0,0,0,128,5,167,224,14,0,0,176,60,78,137,0,0,0,152,176,227,213,147,41,183,3,0,0,0,
192,66,83,112,7,0,0,88,30,39,69,0,0,0,76,212,251,13,155,219,47,139,2,0,0,0,0,22,155,130,59,0,0,192,242,56,33,2,0,0,96,130,222,175,30,75,185,29,0,0,0,0,38,65,193,29,0,0,96,121,156,16,1,0,0,48,49,199,179,
185,29,0,0,0,0,38,69,193,29,0,0,96,121,92,172,206,137,1,0,0,152,136,163,13,155,219,47,137,2,0,0,0,0,166,67,193,29,0,0,96,185,188,47,2,0,0,96,2,142,52,108,110,95,17,5,0,0,0,0,76,139,130,59,0,0,192,114,
57,33,2,0,0,96,193,29,174,158,170,86,69,1,0,0,0,0,211,163,224,14,0,0,176,92,108,112,7,0,0,22,217,219,213,87,82,110,7,0,0,0,128,201,82,112,7,0,0,88,46,10,238,0,0,192,162,122,179,122,166,90,19,5,0,0,0,0,
76,151,130,59,0,0,192,114,185,80,157,17,3,0,0,176,96,94,175,190,150,114,59,0,0,0,0,76,158,130,59,0,0,192,242,57,38,2,0,0,96,129,28,168,246,87,235,162,0,0,0,0,128,233,83,112,7,0,0,88,62,71,69,0,0,0,44,
136,87,171,111,139,1,0,0,0,0,150,135,130,59,0,0,192,242,81,112,7,0,0,22,193,75,213,243,98,0,0,0,0,128,229,50,219,216,216,144,2,0,0,192,20,7,190,217,108,222,31,237,169,254,181,186,91,74,0,0,192,72,125,
191,122,89,12,211,229,142,18,0,0,0,128,121,108,112,7,0,0,88,62,235,213,49,49,0,0,0,35,157,87,190,153,114,59,0,0,0,0,44,45,5,119,0,0,128,229,116,84,4,0,0,192,200,172,86,79,87,175,137,2,0,0,0,0,150,151,
130,59,0,0,192,114,58,44,2,0,0,96,68,86,170,39,171,183,69,1,0,0,0,0,203,109,182,177,177,33,5,0,0,128,41,14,124,179,217,199,253,241,158,234,95,171,187,37,5,0,0,236,178,139,13,229,246,247,69,177,60,220,
81,2,0,0,0,48,143,13,238,0,0,0,203,105,189,122,87,12,0,0,192,46,59,87,253,90,202,237,0,0,0,0,192,38,5,119,0,0,128,229,245,158,8,0,0,128,93,116,186,161,220,126,90,20,0,0,0,0,192,21,10,238,0,0,0,203,203,
6,119,0,0,96,183,28,175,62,215,176,193,29,0,0,0,0,224,231,20,220,1,0,0,150,215,153,148,73,0,0,128,157,119,164,122,172,186,36,10,0,0,0,0,224,195,20,220,1,0,0,150,219,59,34,0,0,0,118,208,235,213,147,213,
138,40,0,0,0,0,128,107,81,112,7,0,0,88,110,10,238,0,0,192,78,121,169,218,95,173,137,2,0,0,0,0,152,103,182,177,177,33,5,0,0,128,41,14,124,179,217,141,124,216,190,234,255,108,190,5,0,0,216,14,235,213,115,
213,1,81,112,133,59,74,0,0,0,0,230,177,193,29,0,0,96,185,173,86,71,196,0,0,0,108,227,204,241,84,202,237,0,0,0,0,192,13,82,112,7,0,0,224,29,17,0,0,0,219,224,66,245,133,234,176,40,0,0,0,0,128,27,53,243,
242,127,0,0,0,19,29,248,102,179,27,253,208,123,171,159,85,123,164,6,0,0,108,145,51,213,227,213,89,81,112,45,238,40,1,0,0,0,152,199,6,119,0,0,0,206,85,199,196,0,0,0,108,145,99,213,103,83,110,7,0,0,0,0,
110,129,130,59,0,0,0,85,135,68,0,0,0,108,209,108,241,88,117,73,20,0,0,0,0,192,173,80,112,7,0,0,160,234,173,106,93,12,0,0,192,109,120,181,122,182,90,21,5,0,0,0,0,112,171,20,220,1,0,0,168,58,87,29,19,3,
0,0,112,11,214,171,231,55,31,254,225,44,0,0,0,0,112,91,20,220,1,0,0,184,226,144,8,0,0,128,155,180,82,61,213,176,189,29,0,0,0,0,224,182,205,54,54,54,164,0,0,0,48,197,129,111,54,187,217,191,114,111,245,
79,146,3,0,0,110,208,153,234,233,234,164,40,184,89,238,40,1,0,0,0,152,199,6,119,0,0,0,174,56,87,189,39,6,0,0,224,6,188,87,125,54,229,118,0,0,0,0,96,139,41,184,3,0,0,240,65,111,136,0,0,0,184,142,215,171,
199,171,75,162,0,0,0,0,0,182,218,204,203,255,1,0,0,76,116,224,155,205,110,229,175,221,85,253,75,181,79,130,0,0,192,53,188,80,189,36,6,110,151,59,74,0,0,0,0,230,177,193,29,0,0,128,15,186,92,189,45,6,0,
0,224,67,86,171,103,82,110,7,0,0,0,0,182,153,130,59,0,0,0,31,246,186,8,0,0,128,15,184,80,125,161,58,36,10,0,0,0,0,96,187,205,188,252,31,0,0,192,68,7,190,217,236,86,255,234,158,234,95,170,123,164,8,0,0,
75,239,120,245,116,117,94,20,108,37,119,148,0,0,0,0,204,99,131,59,0,0,0,31,182,94,189,33,6,0,0,88,122,111,52,108,110,87,110,7,0,0,0,0,118,140,13,238,0,0,0,83,29,248,110,125,131,123,213,253,213,63,74,17,
0,0,150,210,122,245,131,234,101,81,176,93,220,81,2,0,0,0,48,143,13,238,0,0,0,92,203,153,234,136,24,0,0,96,233,92,170,158,76,185,29,0,0,0,0,216,37,10,238,0,0,0,204,243,19,17,0,0,192,82,57,89,61,82,189,
43,10,0,0,0,0,96,183,204,188,252,31,0,0,192,68,7,190,217,236,118,63,197,222,234,159,171,123,164,9,0,0,147,119,168,218,95,173,136,130,157,224,142,18,0,0,0,128,121,108,112,7,0,0,96,158,181,234,53,49,0,0,
192,228,189,88,61,147,114,59,0,0,0,0,48,2,54,184,3,0,0,76,117,224,187,253,13,238,85,247,86,63,171,246,72,20,0,0,38,103,165,122,182,122,71,20,236,52,119,148,0,0,0,0,204,99,131,59,0,0,0,31,231,92,245,182,
24,0,0,96,114,206,84,15,167,220,14,0,0,0,0,140,140,130,59,0,0,0,215,243,138,8,0,0,96,82,222,110,40,183,159,17,5,0,0,0,0,48,54,10,238,0,0,0,92,207,123,213,9,49,0,0,192,194,91,175,94,168,190,82,173,136,
3,0,0,0,0,24,35,5,119,0,0,0,110,196,203,34,0,0,128,133,118,177,122,188,122,73,20,0,0,0,0,192,152,205,54,54,54,164,0,0,0,48,197,129,111,54,219,202,79,183,183,250,167,234,19,146,5,0,128,133,115,172,122,
166,58,47,10,198,194,29,37,0,0,0,0,243,216,224,14,0,0,192,141,88,171,94,17,3,0,0,44,156,87,170,47,164,220,14,0,0,0,0,44,8,27,220,1,0,0,166,58,240,109,237,6,247,170,59,171,127,174,238,146,46,0,0,140,222,
74,245,205,234,77,81,48,70,238,40,1,0,0,0,152,199,6,119,0,0,0,110,212,74,245,170,24,0,0,96,244,78,87,143,164,220,14,0,0,0,0,44,32,27,220,1,0,0,166,58,240,109,253,6,247,170,123,170,159,53,108,115,7,0,0,
198,231,80,181,191,225,31,168,194,104,185,163,4,0,0,0,96,30,27,220,1,0,0,184,25,23,171,215,196,0,0,0,163,179,86,125,191,122,38,229,118,0,0,0,0,96,129,217,224,14,0,0,48,213,129,111,123,54,184,87,221,91,
253,99,181,87,202,0,0,48,10,103,171,175,85,199,68,193,162,112,71,9,0,0,0,192,60,54,184,3,0,0,112,179,206,85,175,139,1,0,0,70,225,173,234,225,148,219,1,0,0,0,128,137,176,193,29,0,0,96,170,3,223,246,109,
112,175,250,100,245,179,108,113,7,0,128,221,178,90,253,160,122,85,20,44,34,119,148,0,0,0,0,204,99,131,59,0,0,0,183,226,124,245,19,49,0,0,192,174,56,93,125,46,229,118,0,0,0,0,96,130,108,112,7,0,0,152,234,
192,183,189,27,220,171,62,81,253,99,117,167,180,1,0,96,199,28,172,190,93,173,136,130,69,230,142,18,0,0,0,128,121,108,112,7,0,0,224,86,93,200,22,119,0,0,216,41,171,213,254,234,107,41,183,3,0,0,0,0,19,102,
131,59,0,0,192,84,7,190,237,223,224,94,117,119,245,179,234,46,137,3,0,192,182,57,85,61,93,157,22,5,83,225,142,18,0,0,0,128,121,108,112,7,0,0,224,118,92,170,94,18,3,0,0,108,155,3,213,35,41,183,3,0,0,0,
0,75,194,6,119,0,0,128,169,14,124,59,179,193,189,106,111,195,22,247,79,74,29,0,0,182,204,229,234,155,213,33,81,48,69,238,40,1,0,0,0,152,199,6,119,0,0,0,110,215,90,245,3,49,0,0,192,150,121,175,250,116,
202,237,0,0,0,0,192,18,82,112,7,0,0,96,43,188,89,157,16,3,0,0,220,150,181,234,197,234,11,213,121,113,0,0,0,0,0,203,104,230,229,255,0,0,0,38,58,240,205,102,59,253,37,191,88,253,119,201,3,0,192,45,57,93,
125,173,122,95,20,44,3,119,148,0,0,0,0,204,99,131,59,0,0,0,91,229,72,245,142,24,0,0,224,166,29,168,30,73,185,29,0,0,0,0,192,6,119,0,0,128,201,14,124,59,191,193,189,234,254,234,127,87,123,61,3,0,0,112,
93,151,170,111,86,111,137,130,101,227,142,18,0,0,0,128,121,108,112,7,0,0,96,43,157,169,94,22,3,0,0,92,215,187,213,47,167,220,14,0,0,0,0,240,11,108,112,7,0,0,152,234,192,183,59,27,220,171,238,108,216,226,
126,175,103,1,0,0,62,98,173,122,33,255,48,148,37,231,142,18,0,0,0,128,121,108,112,7,0,0,96,171,173,84,207,137,1,0,0,62,226,84,245,72,202,237,0,0,0,0,0,115,41,184,3,0,0,176,29,222,217,124,0,0,0,131,151,
27,202,237,39,69,1,0,0,0,0,48,223,204,203,255,1,0,0,76,116,224,155,205,118,251,91,184,191,250,135,106,159,103,3,0,128,37,118,190,250,122,117,68,20,112,149,59,74,0,0,0,0,230,177,193,29,0,0,128,237,114,
166,250,161,24,0,0,88,98,7,171,79,167,220,14,0,0,0,0,112,195,108,112,7,0,0,152,234,192,183,251,27,220,171,246,84,127,95,61,228,25,1,0,96,137,92,174,158,107,40,184,3,215,224,142,18,0,0,0,128,121,108,112,
7,0,0,96,59,173,87,223,222,124,11,0,0,203,224,72,195,214,118,229,118,0,0,0,0,128,91,160,224,14,0,0,192,118,59,94,189,42,6,0,0,38,110,181,250,126,245,88,117,94,28,0,0,0,0,0,183,102,230,229,255,0,0,0,38,
58,240,205,102,99,250,118,238,172,254,161,186,207,51,3,0,192,4,157,172,158,169,78,139,2,110,140,59,74,0,0,0,0,230,177,193,29,0,0,128,157,176,82,237,175,214,69,1,0,192,132,172,87,63,170,30,73,185,29,0,
0,0,0,96,75,40,184,3,0,0,176,83,222,171,94,21,3,0,0,19,113,170,250,92,245,98,181,38,14,0,0,0,0,128,173,49,243,242,127,0,0,0,19,29,248,102,179,49,126,91,251,170,255,85,61,224,25,2,0,96,65,173,87,47,85,
63,76,177,29,110,153,59,74,0,0,0,0,230,81,112,7,0,0,152,234,192,55,206,130,123,213,163,213,223,86,123,60,75,0,0,44,152,83,213,254,234,184,40,224,246,184,163,4,0,0,0,96,158,59,68,0,0,0,192,14,59,222,176,
241,18,0,0,22,197,122,245,163,234,225,148,219,1,0,0,0,0,182,149,13,238,0,0,0,83,29,248,198,187,193,189,106,111,245,63,27,182,185,3,0,192,152,157,174,190,158,98,59,108,41,119,148,0,0,0,0,204,99,131,59,
0,0,0,187,97,173,122,182,90,17,5,0,0,35,117,101,107,251,47,167,220,14,0,0,0,0,176,99,20,220,1,0,0,216,45,103,171,231,196,0,0,192,8,157,174,62,87,189,216,240,143,51,1,0,0,0,0,216,33,10,238,0,0,0,236,166,
55,54,31,0,0,48,6,107,217,218,14,0,0,0,0,176,171,102,27,27,27,82,0,0,0,152,226,192,55,155,45,202,183,122,103,245,15,213,125,158,53,0,0,118,209,241,234,155,213,73,81,192,246,115,71,9,0,0,0,192,60,54,184,
3,0,0,176,219,86,170,103,26,182,101,2,0,192,110,252,255,232,119,171,207,166,220,14,0,0,0,0,176,235,20,220,1,0,0,24,131,247,171,231,197,0,0,192,14,123,167,250,116,245,138,40,0,0,0,0,0,198,65,193,29,0,0,
128,177,56,80,189,46,6,0,0,118,192,197,234,217,234,169,234,156,56,0,0,0,0,0,198,99,182,177,177,33,5,0,0,128,41,14,124,179,217,34,126,219,251,170,191,171,30,244,12,2,0,176,77,222,168,190,91,93,18,5,236,
30,119,148,0,0,0,0,204,163,224,14,0,0,48,213,129,111,49,11,238,85,247,87,127,95,221,229,89,4,0,96,11,157,173,190,93,189,43,10,216,125,238,40,1,0,0,0,152,231,14,17,0,0,0,48,50,103,170,175,87,235,162,0,
0,96,11,172,87,63,174,62,157,114,59,0,0,0,0,192,232,41,184,3,0,0,48,70,111,87,47,138,1,0,128,219,116,172,122,184,250,65,181,42,14,0,0,0,0,128,241,83,112,7,0,0,96,172,94,170,94,19,3,0,0,183,224,82,181,
191,250,92,117,82,28,0,0,0,0,0,139,99,182,177,177,33,5,0,0,128,41,14,124,179,217,20,126,140,189,213,95,87,95,244,140,2,0,112,131,14,84,47,52,148,220,129,145,114,71,9,0,0,0,192,60,10,238,0,0,0,83,29,248,
166,81,112,175,186,187,250,187,234,126,207,42,0,0,31,227,68,245,92,117,76,20,48,126,238,40,1,0,0,0,152,231,14,17,0,0,0,48,114,151,170,39,179,129,19,0,128,107,91,169,190,91,61,146,114,59,0,0,0,0,192,194,
83,112,7,0,0,96,17,156,169,158,169,214,68,1,0,192,7,188,89,253,82,245,74,181,46,14,0,0,0,0,128,197,167,224,14,0,0,192,162,56,82,61,47,6,0,0,170,211,213,227,213,179,213,5,113,0,0,0,0,0,76,135,130,59,0,
0,0,139,228,64,245,99,49,0,0,44,173,149,234,133,234,151,171,119,197,1,0,0,0,0,48,61,179,141,141,13,41,0,0,0,76,113,224,155,205,166,250,163,237,169,126,90,125,217,179,12,0,176,84,14,86,223,207,198,118,
152,4,119,148,0,0,0,0,204,163,224,14,0,0,48,213,129,111,186,5,247,170,125,213,255,168,30,245,76,3,0,76,222,137,234,185,234,152,40,96,58,220,81,2,0,0,0,48,207,29,34,0,0,0,96,1,173,86,79,85,39,69,1,0,48,
89,151,170,111,86,15,167,220,14,0,0,0,0,176,52,20,220,1,0,0,88,84,23,171,199,171,51,162,0,0,152,148,245,234,149,234,223,85,175,137,3,0,0,0,0,96,185,204,188,252,31,0,0,192,68,7,190,217,108,89,126,212,123,
171,191,173,62,233,89,7,0,88,120,239,86,223,173,78,137,2,166,205,29,37,0,0,0,0,243,216,224,14,0,0,192,162,59,87,125,161,186,32,10,0,128,133,117,182,122,186,225,21,122,148,219,1,0,0,0,0,150,152,130,59,
0,0,0,83,112,166,161,12,117,73,20,0,0,11,101,165,122,177,250,116,245,150,56,0,0,0,0,0,152,121,249,63,0,0,128,137,14,124,179,217,50,254,216,143,86,127,83,221,229,191,0,0,128,81,91,175,14,84,127,80,93,20,
7,44,31,119,148,0,0,0,0,204,163,224,14,0,0,48,213,129,111,57,11,238,85,159,175,254,186,218,231,191,2,0,128,81,58,92,125,191,58,37,10,88,94,238,40,1,0,0,0,152,231,14,17,0,0,0,48,49,239,85,79,87,107,162,
0,0,24,149,19,213,99,213,147,41,183,3,0,0,0,0,48,135,130,59,0,0,0,83,116,184,250,90,181,46,10,0,128,93,119,161,250,102,245,112,117,68,28,0,0,0,0,0,124,156,153,151,255,3,0,0,152,232,192,55,155,9,161,190,
90,253,121,181,71,20,0,0,59,110,165,122,169,122,101,243,125,128,159,115,71,9,0,0,0,192,60,10,238,0,0,0,83,29,248,20,220,175,248,141,234,191,85,123,69,1,0,176,99,94,171,94,108,216,222,14,240,17,238,40,
1,0,0,0,152,71,193,29,0,0,96,170,3,159,130,251,7,125,185,250,203,148,220,1,0,182,219,59,213,11,213,73,81,0,31,199,29,37,0,0,0,0,243,40,184,3,0,0,76,117,224,83,112,255,176,47,86,127,85,237,19,5,0,192,150,
59,86,253,160,58,42,10,224,70,184,163,4,0,0,0,96,158,59,68,0,0,0,192,146,56,82,61,94,173,136,2,0,96,203,156,170,190,82,125,46,229,118,0,0,0,0,0,182,128,130,59,0,0,0,203,228,104,245,88,117,81,20,0,0,183,
229,92,181,191,250,116,245,182,56,0,0,0,0,0,216,42,51,47,255,7,0,0,48,209,129,111,54,19,194,124,15,84,127,83,221,43,10,0,128,155,114,169,250,97,245,147,106,77,28,192,173,114,71,9,0,0,0,192,60,10,238,0,
0,0,83,29,248,20,220,175,231,147,13,37,247,79,137,2,0,224,186,86,170,151,171,31,111,190,15,112,91,220,81,2,0,0,0,48,143,130,59,0,0,192,84,7,62,5,247,27,113,119,245,87,213,175,136,2,0,224,154,214,170,3,
13,91,219,47,138,3,216,42,238,40,1,0,0,0,152,71,193,29,0,0,96,170,3,159,130,251,141,218,87,253,180,122,66,20,0,0,63,183,94,189,86,253,168,58,39,14,96,171,185,163,4,0,0,0,96,158,59,68,0,0,0,192,146,91,
173,158,172,94,18,5,0,64,235,213,235,213,47,85,223,78,185,29,0,0,0,0,128,29,102,131,59,0,0,192,84,7,62,27,220,111,197,55,170,63,173,246,138,2,0,88,66,111,52,108,108,63,45,10,96,187,185,163,4,0,0,0,96,
30,5,119,0,0,128,169,14,124,10,238,183,234,243,213,79,171,187,69,1,0,44,137,55,171,31,86,167,68,1,236,20,119,148,0,0,0,0,204,163,224,14,0,0,48,213,129,79,193,253,118,220,95,253,245,230,91,0,128,169,122,
171,250,131,234,164,40,128,157,230,142,18,0,0,0,128,121,238,16,1,0,0,0,124,196,153,234,179,213,123,162,0,0,38,232,157,234,145,234,233,148,219,1,0,0,0,0,24,25,5,119,0,0,0,184,182,75,213,227,213,235,162,
0,0,38,226,112,195,63,226,123,170,122,95,28,0,0,0,0,0,140,145,130,59,0,0,0,204,183,86,237,175,158,175,214,197,1,0,44,168,183,26,54,182,63,89,29,23,7,0,0,0,0,0,99,54,219,216,216,144,2,0,0,192,20,7,190,
217,76,8,91,235,137,234,47,171,59,69,1,0,44,136,131,213,75,213,73,81,0,99,227,142,18,0,0,0,128,121,20,220,1,0,0,166,58,240,41,184,111,135,79,85,63,173,30,16,5,0,48,82,235,213,27,13,197,246,211,226,0,198,
202,29,37,0,0,0,0,243,220,33,2,0,0,0,184,97,167,170,71,26,182,161,2,0,140,201,90,117,160,250,165,106,127,202,237,0,0,0,0,0,44,40,27,220,1,0,0,166,58,240,217,224,190,221,190,85,253,73,181,79,20,0,192,46,
90,173,94,107,216,216,126,94,28,192,162,112,71,9,0,0,0,192,60,10,238,0,0,0,83,29,248,20,220,119,194,67,213,95,84,15,136,2,0,216,97,43,213,235,213,15,171,139,226,0,22,141,59,74,0,0,0,0,230,81,112,7,0,0,
152,234,192,167,224,190,83,238,172,254,180,250,170,40,0,128,29,112,177,122,117,243,113,73,28,192,162,114,71,9,0,0,0,192,60,10,238,0,0,0,83,29,248,20,220,119,218,183,170,63,169,246,137,2,0,216,6,103,171,
31,55,108,109,95,21,7,176,232,220,81,2,0,0,0,48,143,130,59,0,0,192,84,7,62,5,247,221,240,80,245,151,213,253,162,0,0,182,200,251,213,203,213,65,81,0,83,226,142,18,0,0,0,128,121,238,16,1,0,0,0,108,153,19,
213,195,213,33,81,0,0,183,233,72,245,88,245,72,202,237,0,0,0,0,0,44,17,5,119,0,0,0,216,90,43,213,51,213,243,213,170,56,0,128,155,116,176,161,212,254,88,67,201,29,0,0,0,0,0,150,202,204,203,255,1,0,0,76,
116,224,155,205,132,176,251,62,85,253,69,245,160,40,0,128,143,177,90,189,94,253,184,58,43,14,96,25,184,163,4,0,0,0,96,30,5,119,0,0,128,169,14,124,10,238,99,177,175,250,227,234,59,162,0,0,62,228,66,245,
74,117,160,186,36,14,96,153,184,163,4,0,0,0,96,30,5,119,0,0,128,169,14,124,10,238,99,243,68,245,231,213,61,162,0,128,165,119,162,122,185,122,179,90,19,7,176,140,220,81,2,0,0,0,48,143,130,59,0,0,192,84,
7,62,5,247,49,186,167,161,228,254,132,40,0,96,41,189,213,80,108,63,42,10,96,217,185,163,4,0,0,0,96,30,5,119,0,0,128,169,14,124,10,238,99,246,157,234,143,171,125,162,0,128,201,91,169,94,175,94,169,206,
136,3,96,224,142,18,0,0,0,128,121,20,220,1,0,0,166,58,240,41,184,143,221,131,213,95,84,159,18,5,0,76,210,185,234,213,234,64,117,89,28,0,191,200,29,37,0,0,0,0,243,40,184,3,0,0,76,117,224,83,112,95,4,251,
170,255,84,253,174,40,0,96,50,142,54,20,219,15,85,235,226,0,184,54,119,148,0,0,0,0,204,163,224,14,0,0,48,213,129,79,193,125,145,60,81,253,89,245,73,81,0,192,66,90,173,14,54,20,219,79,136,3,224,250,220,
81,2,0,0,0,48,143,130,59,0,0,192,84,7,62,5,247,69,115,103,195,54,247,223,17,5,0,44,140,51,13,165,246,55,170,75,226,0,184,113,238,40,1,0,0,0,152,71,193,29,0,0,96,170,3,159,130,251,162,250,213,134,109,238,
15,136,2,0,70,235,112,245,202,230,91,0,110,129,59,74,0,0,0,0,230,81,112,7,0,0,152,234,192,167,224,190,200,246,85,191,95,253,94,181,87,28,0,48,10,151,170,215,170,159,84,103,197,1,112,123,220,81,2,0,0,0,
48,143,130,59,0,0,192,84,7,62,5,247,41,120,176,250,175,213,103,68,1,0,187,230,68,245,106,117,176,90,21,7,192,214,112,71,9,0,0,0,192,60,10,238,0,0,0,83,29,248,20,220,167,98,79,245,189,234,15,27,54,187,
3,0,219,239,114,245,102,195,198,246,227,226,0,216,122,238,40,1,0,0,0,152,71,193,29,0,0,96,170,3,159,130,251,212,220,87,253,89,245,69,81,0,192,182,57,218,80,106,63,84,173,136,3,96,251,184,163,4,0,0,0,96,
30,5,119,0,0,128,169,14,124,10,238,83,245,141,234,79,170,187,68,1,0,91,226,98,245,122,67,177,253,180,56,0,118,134,59,74,0,0,0,0,230,81,112,7,0,0,152,234,192,167,224,62,101,119,87,127,84,125,171,218,35,
14,0,184,37,239,52,20,219,223,170,214,197,1,176,179,220,81,2,0,0,0,48,143,130,59,0,0,192,84,7,62,5,247,101,240,80,195,54,247,207,139,2,0,110,200,185,134,77,237,175,85,231,197,1,176,123,220,81,2,0,0,0,
48,143,130,59,0,0,192,84,7,62,5,247,101,242,27,213,127,174,238,21,5,0,124,196,90,195,150,246,215,170,119,197,1,48,14,238,40,1,0,0,0,152,71,193,29,0,0,96,170,3,159,130,251,178,217,87,125,175,250,253,205,
247,1,96,217,157,108,40,181,191,81,93,18,7,192,184,184,163,4,0,0,0,96,30,5,119,0,0,128,169,14,124,10,238,203,234,222,234,143,171,175,138,2,128,37,116,185,122,179,161,216,126,220,249,55,0,0,0,0,0,44,30,
5,119,0,0,128,169,14,124,10,238,203,238,87,170,255,82,61,36,10,0,150,192,209,134,82,251,161,106,229,202,111,58,255,6,0,0,0,0,128,197,163,224,14,0,0,48,213,129,79,193,157,193,111,55,108,116,191,71,20,0,
76,204,197,234,141,234,64,117,250,90,31,224,252,27,0,0,0,0,0,22,143,130,59,0,0,192,84,7,62,5,119,174,186,179,250,222,230,227,46,113,0,176,192,214,170,195,13,197,246,183,170,245,143,251,96,231,223,0,0,
0,0,0,176,120,20,220,1,0,0,166,58,240,41,184,243,81,119,85,255,161,250,221,134,210,59,0,44,138,195,213,155,13,165,246,203,55,250,151,156,127,3,0,0,0,0,192,226,81,112,7,0,0,152,234,192,167,224,206,124,
247,84,255,177,250,86,181,87,28,0,140,212,209,234,80,117,176,186,120,43,159,192,249,55,0,0,0,0,0,44,30,5,119,0,0,128,169,14,124,10,238,92,223,189,13,69,247,111,84,123,196,1,192,8,156,104,40,181,191,81,
157,187,221,79,230,252,27,0,0,0,0,0,22,143,130,59,0,0,192,84,7,62,5,119,110,220,3,213,31,86,191,41,10,0,118,193,217,134,66,251,155,213,169,173,252,196,206,191,1,0,0,0,0,96,241,40,184,3,0,0,76,117,224,
83,112,231,230,61,84,253,81,245,235,162,0,96,155,93,168,14,54,148,218,143,111,215,23,113,254,13,0,0,0,0,0,139,71,193,29,0,0,96,170,3,159,130,59,183,238,87,26,54,186,127,73,20,0,108,161,75,213,161,134,
82,251,145,157,248,130,206,191,1,0,0,0,0,96,241,40,184,3,0,0,76,117,224,83,112,231,246,125,166,250,94,245,85,81,0,112,139,86,170,119,170,55,170,195,213,250,78,126,113,231,223,0,0,0,0,0,176,120,20,220,
1,0,0,166,58,240,41,184,179,117,238,175,126,175,250,173,106,159,56,0,184,142,181,134,50,251,193,234,237,106,117,183,190,17,231,223,0,0,0,0,0,176,120,20,220,1,0,0,166,58,240,41,184,179,245,238,105,40,186,
127,171,186,75,28,0,124,200,225,234,208,230,227,242,24,190,33,231,223,0,0,0,0,0,176,120,20,220,1,0,0,166,58,240,41,184,179,125,238,106,40,185,255,94,67,233,29,128,229,116,101,83,251,91,13,155,218,47,141,
237,27,116,254,13,0,0,0,0,0,139,71,193,29,0,0,96,170,3,159,130,59,219,111,111,245,141,134,162,251,253,226,0,88,10,151,171,119,171,131,155,111,87,198,252,205,58,255,6,0,0,0,0,128,197,163,224,14,0,0,48,
213,129,79,193,157,157,245,213,234,59,213,163,162,0,152,156,139,93,221,210,126,184,90,95,148,111,220,249,55,0,0,0,0,0,44,30,5,119,0,0,128,169,14,124,10,238,236,142,71,171,111,53,20,222,247,137,3,96,97,
157,171,14,53,148,218,223,91,212,31,194,249,55,0,0,0,0,0,44,30,5,119,0,0,128,169,14,124,10,238,236,174,187,171,223,174,126,167,186,79,28,0,11,225,120,245,78,195,182,246,147,83,248,129,156,127,3,0,0,0,
0,192,226,81,112,7,0,0,152,234,192,167,224,206,120,60,81,125,103,243,45,0,227,177,82,189,219,176,165,253,112,117,97,106,63,160,243,111,0,0,0,0,0,88,60,10,238,0,0,0,83,29,248,20,220,25,159,123,171,223,
109,216,236,126,183,56,0,118,197,185,134,13,237,135,171,35,213,218,148,127,88,231,223,0,0,0,0,0,176,120,20,220,1,0,0,166,58,240,41,184,51,94,251,170,223,172,126,167,122,84,28,0,219,238,189,134,77,237,
135,170,211,203,244,131,59,255,6,0,0,0,0,128,197,163,224,14,0,0,48,213,129,79,193,157,197,240,104,245,141,134,194,187,173,238,0,91,227,92,195,118,246,119,54,223,94,90,214,32,156,127,3,0,0,0,0,192,226,
81,112,7,0,0,152,234,192,167,224,206,98,217,91,125,185,161,236,254,68,181,71,36,0,55,236,114,195,150,246,43,165,246,51,34,25,56,255,6,0,0,0,0,128,197,163,224,14,0,0,48,213,129,79,193,157,197,117,79,245,
91,13,101,247,7,197,1,112,77,87,10,237,239,109,62,184,6,231,223,0,0,0,0,0,176,120,20,220,1,0,0,166,58,240,41,184,51,13,15,54,20,221,127,171,161,248,14,176,172,206,84,111,119,181,216,190,34,146,235,115,
254,13,0,0,0,0,0,139,71,193,29,0,0,96,170,3,159,130,59,211,243,235,13,101,247,47,87,123,197,1,76,220,133,134,50,251,59,13,133,246,243,34,185,121,206,191,1,0,0,0,0,96,241,40,184,3,0,0,76,117,224,83,112,
103,186,238,174,126,99,243,241,37,113,0,19,177,218,213,237,236,135,171,147,34,185,125,206,191,1,0,0,0,0,96,241,40,184,3,0,0,76,117,224,83,112,103,57,220,211,176,209,253,74,217,125,143,72,128,5,114,188,
122,183,171,197,246,117,145,108,45,231,223,0,0,0,0,0,176,120,20,220,1,0,0,166,58,240,41,184,179,124,238,174,126,189,161,236,254,68,181,87,36,192,200,156,106,40,179,95,41,181,95,18,201,246,114,254,13,0,
0,0,0,0,139,71,193,29,0,0,96,170,3,159,130,59,203,237,206,134,178,251,111,54,148,221,247,137,4,216,97,171,213,177,15,61,20,218,119,152,243,111,0,0,0,0,0,88,60,10,238,0,0,0,83,29,248,20,220,225,138,125,
13,37,247,43,101,247,187,68,2,108,131,243,93,45,178,31,173,142,139,100,247,57,255,6,0,0,0,0,128,197,163,224,14,0,0,48,213,129,79,193,29,174,101,111,245,165,205,199,151,171,251,68,2,220,162,147,213,123,
13,101,246,99,213,57,145,140,143,243,111,0,0,0,0,0,88,60,10,238,0,0,0,83,29,248,20,220,225,70,220,215,80,116,255,82,245,197,134,109,239,0,31,182,210,47,110,103,63,182,249,123,140,156,243,111,0,0,0,0,0,
88,60,10,238,0,0,0,83,29,248,20,220,225,102,237,109,40,185,127,177,250,247,213,253,34,129,165,117,174,171,101,246,247,26,182,181,179,128,156,127,3,0,0,0,0,192,226,81,112,7,0,0,152,234,192,167,224,14,183,
235,222,134,162,187,237,238,48,125,199,187,186,153,253,88,117,94,36,211,224,252,27,0,0,0,0,0,22,143,130,59,0,0,0,192,117,204,102,179,43,219,221,63,95,253,234,230,3,88,76,39,170,247,63,244,88,23,203,52,
57,255,6,0,0,0,0,128,197,163,224,14,0,0,0,112,29,215,120,69,132,125,93,45,186,95,121,236,149,20,140,206,137,148,217,151,154,243,111,0,0,0,0,0,88,60,10,238,0,0,0,0,215,113,141,130,251,135,237,233,163,133,
247,59,37,7,59,102,189,161,204,126,34,101,118,62,192,249,55,0,0,0,0,0,44,30,5,119,0,0,0,128,109,48,155,205,30,173,62,223,213,194,251,221,82,129,45,113,182,58,249,193,199,198,198,198,41,177,0,0,0,0,0,0,
76,131,130,59,0,0,0,192,54,184,198,214,247,7,170,71,171,207,108,62,30,173,246,74,10,230,90,109,216,200,126,178,97,27,251,149,66,251,202,135,63,208,25,39,0,0,0,0,0,192,116,40,184,3,0,0,0,108,131,107,20,
220,175,229,193,174,150,221,175,20,223,247,72,143,37,115,118,243,113,166,161,208,126,230,3,191,190,33,206,56,1,0,0,0,0,0,166,67,193,29,0,0,0,96,27,220,96,193,253,90,30,234,106,225,253,209,205,95,195,162,
187,220,181,11,236,39,170,245,219,253,228,206,56,1,0,0,0,0,0,166,67,193,29,0,0,0,96,27,220,70,193,253,195,246,52,148,220,63,83,125,170,122,96,243,113,159,148,25,161,19,125,180,192,126,166,186,180,157,
95,212,25,39,0,0,0,0,0,192,116,40,184,3,0,0,0,108,131,45,44,184,207,179,175,161,240,254,80,67,225,253,74,249,253,126,233,179,205,206,246,209,2,251,149,95,239,10,103,156,0,0,0,0,0,0,211,161,224,14,0,0,
0,176,13,118,160,224,62,207,222,234,193,205,199,149,226,251,125,155,191,134,27,241,126,181,90,157,106,216,188,126,182,186,80,157,111,40,180,175,143,237,27,118,198,9,0,0,0,0,0,48,29,10,238,0,0,0,0,219,
96,23,11,238,31,231,222,234,158,234,51,213,39,170,79,54,20,223,63,209,80,130,103,218,62,92,90,63,223,80,92,63,83,93,222,252,179,213,69,252,193,156,113,2,0,0,0,0,0,76,135,130,59,0,0,0,192,54,24,105,193,
253,122,30,104,40,192,95,217,250,126,79,245,80,87,203,240,140,215,197,234,92,31,45,173,159,108,40,173,159,152,242,15,239,140,19,0,0,0,0,0,96,58,20,220,1,0,0,0,182,193,130,22,220,175,231,174,234,254,106,
79,67,241,189,134,13,240,123,27,10,241,119,167,12,191,21,78,87,43,215,120,255,131,27,214,175,188,191,178,249,49,75,205,25,39,0,0,0,0,0,192,116,40,184,3,0,0,0,108,131,137,22,220,111,198,157,13,27,225,63,
88,134,175,171,133,248,15,126,204,21,247,54,108,141,159,130,43,27,212,63,238,253,121,69,118,110,146,51,78,0,0,0,0,0,128,233,80,112,7,0,0,0,216,6,10,238,91,226,161,134,130,252,21,123,27,10,242,55,234,51,
115,126,127,181,97,3,250,199,185,84,157,189,206,199,156,175,46,120,154,118,159,51,78,0,0,0,0,0,128,233,80,112,7,0,0,0,0,0,0,0,0,0,0,96,20,238,16,1,0,0,0,0,0,0,0,0,0,0,0,99,160,224,14,0,0,0,0,0,0,0,0,0,
0,192,40,40,184,3,0,0,0,0,0,0,0,0,0,0,48,10,10,238,0,0,0,0,0,0,0,0,0,0,0,140,130,130,59,0,0,0,0,0,0,0,0,0,0,0,163,160,224,14,0,0,0,0,0,0,0,0,0,0,192,40,40,184,3,0,0,0,0,0,0,0,0,0,0,48,10,10,238,0,0,0,
0,0,0,0,0,0,0,0,140,130,130,59,0,0,0,0,0,0,0,0,0,0,0,163,160,224,14,0,0,0,0,0,0,0,0,0,0,192,40,40,184,3,0,0,0,0,0,0,0,0,0,0,48,10,10,238,0,0,0,0,0,0,0,0,0,0,0,140,130,130,59,0,0,0,0,0,0,0,0,0,0,0,163,
160,224,14,0,0,0,0,0,0,0,0,0,0,192,40,40,184,3,0,0,0,0,0,0,0,0,0,0,48,10,10,238,0,0,0,0,0,0,0,0,0,0,0,140,130,130,59,0,0,0,0,0,0,0,0,0,0,0,163,160,224,14,0,0,0,0,0,0,0,0,0,0,192,40,40,184,3,0,0,0,0,0,
0,0,0,0,0,48,10,10,238,0,0,0,0,0,0,0,0,0,0,0,140,130,130,59,0,0,0,0,0,0,0,0,0,0,0,163,160,224,14,0,0,0,0,0,0,0,0,0,0,192,40,40,184,3,0,0,0,0,0,0,0,0,0,0,48,10,10,238,0,0,0,0,0,0,0,0,0,0,0,140,130,130,
59,0,0,0,0,0,0,0,0,0,0,0,163,160,224,14,0,0,0,0,0,0,0,0,0,0,192,40,40,184,3,0,0,0,0,0,0,0,0,0,0,48,10,10,238,0,0,0,0,0,0,0,0,0,0,0,140,130,130,59,0,0,0,0,0,0,0,0,0,0,0,163,160,224,14,0,0,0,0,0,0,0,0,0,
0,192,40,40,184,3,0,0,0,0,0,0,0,0,0,0,48,10,10,238,0,0,0,0,0,0,0,0,0,0,0,140,130,130,59,0,0,0,0,0,0,0,0,0,0,0,163,160,224,14,0,0,0,0,0,0,0,0,0,0,192,40,40,184,3,0,0,0,0,0,0,0,0,0,0,48,10,10,238,0,0,0,
0,0,0,0,0,0,0,0,140,130,130,59,0,0,0,0,0,0,0,0,0,0,0,163,160,224,14,0,0,0,0,0,0,0,0,0,0,192,40,40,184,3,0,0,0,0,0,0,0,0,0,0,48,10,10,238,0,0,0,0,0,0,0,0,0,0,0,140,130,130,59,0,0,0,0,0,0,0,0,0,0,0,163,
160,224,14,0,0,0,0,0,0,0,0,0,0,192,40,40,184,3,0,0,0,0,0,0,0,0,0,0,48,10,10,238,0,0,0,0,0,0,0,0,0,0,0,140,130,130,59,0,0,0,0,0,0,0,0,0,0,0,163,160,224,14,0,0,0,0,0,0,0,0,0,0,192,40,40,184,3,0,0,0,0,0,
0,0,0,0,0,48,10,10,238,0,0,0,0,0,0,0,0,0,0,0,140,130,130,59,0,0,0,0,0,0,0,0,0,0,0,163,160,224,14,0,0,0,0,0,0,0,0,0,0,192,40,40,184,3,0,0,0,0,0,0,0,0,0,0,48,10,10,238,0,0,0,0,0,0,0,0,0,0,0,140,130,130,
59,0,0,0,0,0,0,0,0,0,0,0,163,160,224,14,0,0,0,0,0,0,0,0,0,0,192,40,40,184,3,0,0,0,0,0,0,0,0,0,0,48,10,10,238,0,0,0,0,0,0,0,0,0,0,0,140,130,130,59,0,0,0,0,0,0,0,0,0,0,0,163,160,224,14,0,0,0,0,0,0,0,0,0,
0,192,40,40,184,3,0,0,0,0,0,0,0,0,0,0,48,10,255,31,45,160,69,154,115,126,175,19,0,0,3,255,116,69,88,116,82,97,119,32,112,114,111,102,105,108,101,32,116,121,112,101,32,105,112,116,99,0,10,73,80,84,67,32,
112,114,111,102,105,108,101,10,32,32,32,32,32,52,56,50,10,51,56,52,50,52,57,52,100,48,52,48,52,48,48,48,48,48,48,48,48,48,49,100,54,49,99,48,50,48,53,48,48,50,49,52,101,54,102,55,52,54,53,50,48,52,100,
55,53,55,51,54,57,54,51,50,48,52,51,54,99,54,53,54,54,50,48,52,100,54,53,54,99,10,54,102,54,52,55,57,50,48,52,54,55,50,54,53,54,53,54,52,54,102,54,100,50,48,52,101,51,51,49,99,48,50,49,57,48,48,57,50,
54,101,54,102,55,52,54,53,50,99,54,100,55,53,55,51,54,57,54,51,50,99,54,51,54,99,54,53,54,54,50,99,54,100,10,54,53,54,99,54,102,54,52,55,57,50,99,54,54,55,50,54,53,54,53,54,52,54,102,54,100,50,99,54,100,
55,53,55,51,54,57,54,51,54,49,54,99,50,48,54,101,54,102,55,52,54,53,50,99,55,52,54,53,55,56,55,52,55,53,55,50,54,53,50,99,54,50,10,55,53,55,52,55,52,54,102,54,101,50,99,54,101,54,102,55,52,54,53,54,101,
54,50,54,99,54,49,55,52,55,52,50,99,55,51,55,52,54,102,54,101,54,53,50,99,54,99,54,57,54,55,54,56,55,52,50,48,54,53,54,54,54,54,54,53,54,51,55,52,55,51,10,50,99,54,50,54,49,54,51,54,98,54,55,55,50,54,
102,55,53,54,101,54,52,50,99,55,51,55,52,55,50,54,57,54,101,54,55,55,51,50,99,54,55,55,53,54,57,55,52,54,49,55,50,55,51,50,99,55,50,54,53,54,99,54,57,54,53,54,54,50,99,55,51,10,54,102,55,53,54,101,54,
52,50,99,54,57,54,51,54,102,54,101,50,99,55,52,55,50,54,53,54,50,54,99,54,53,50,48,54,51,54,99,54,53,54,54,49,99,48,50,50,56,48,48,51,48,52,54,55,50,54,53,54,53,50,48,54,54,54,102,55,50,50,48,54,51,10,
54,102,54,100,54,100,54,53,55,50,54,51,54,57,54,49,54,99,50,48,55,53,55,51,54,53,50,101,50,48,52,101,54,102,50,48,54,49,55,52,55,52,55,50,54,57,54,50,55,53,55,52,54,57,54,102,54,101,50,48,55,50,54,53,
55,49,55,53,54,57,55,50,10,54,53,54,52,49,99,48,50,53,48,48,48,48,56,55,48,54,57,55,56,55,57,50,101,54,102,55,50,54,55,49,99,48,50,54,55,48,48,48,56,55,48,54,57,55,56,55,57,50,101,54,102,55,50,54,55,49,
99,48,50,54,57,48,48,53,56,52,101,54,102,55,52,10,54,53,50,48,52,100,55,53,55,51,54,57,54,51,50,48,52,51,54,99,54,53,54,54,50,48,52,100,54,53,54,99,54,102,54,52,55,57,50,48,52,54,55,50,54,53,54,53,54,
52,54,102,54,100,50,48,52,101,51,51,50,48,54,57,54,100,54,49,54,55,54,53,10,50,48,54,57,54,101,50,48,52,50,54,49,54,51,54,98,54,55,55,50,54,102,55,53,54,101,54,52,55,51,50,48,54,49,54,101,54,52,50,48,
53,52,54,53,55,56,55,52,55,53,55,50,54,53,55,51,50,48,54,51,54,49,55,52,54,53,54,55,54,102,55,50,10,55,57,50,48,54,49,55,52,50,48,55,48,54,57,55,56,55,57,50,101,54,102,55,50,54,55,49,99,48,50,55,52,48,
48,48,51,52,51,52,51,51,48,49,99,48,50,55,56,48,48,53,57,52,54,55,50,54,53,54,53,50,48,54,57,54,100,54,49,54,55,54,53,10,50,102,55,48,54,101,54,55,50,99,50,48,53,50,54,53,55,51,54,102,54,99,55,53,55,52,
54,57,54,102,54,101,51,97,50,48,51,51,51,48,51,48,51,48,55,56,51,51,51,48,51,48,51,48,50,99,50,48,52,54,54,57,54,99,54,53,50,48,55,51,54,57,10,55,97,54,53,51,97,50,48,51,53,51,51,52,98,54,50,50,99,50,
48,52,101,54,102,55,52,54,53,50,48,52,100,55,53,55,51,54,57,54,51,50,48,52,51,54,99,54,53,54,54,50,48,52,100,54,53,54,99,54,102,54,52,55,57,50,48,52,54,55,50,54,53,10,54,53,54,52,54,102,54,100,50,48,52,
101,51,51,49,99,48,50,48,48,48,48,48,50,48,48,48,52,10,247,10,70,137,0,0,7,140,105,84,88,116,88,77,76,58,99,111,109,46,97,100,111,98,101,46,120,109,112,0,0,0,0,0,60,63,120,112,97,99,107,101,116,32,98,
101,103,105,110,61,39,239,187,191,39,32,105,100,61,39,87,53,77,48,77,112,67,101,104,105,72,122,114,101,83,122,78,84,99,122,107,99,57,100,39,63,62,10,60,120,58,120,109,112,109,101,116,97,32,120,109,108,
110,115,58,120,61,39,97,100,111,98,101,58,110,115,58,109,101,116,97,47,39,32,120,58,120,109,112,116,107,61,39,73,109,97,103,101,58,58,69,120,105,102,84,111,111,108,32,49,48,46,50,48,39,62,10,60,114,100,
102,58,82,68,70,32,120,109,108,110,115,58,114,100,102,61,39,104,116,116,112,58,47,47,119,119,119,46,119,51,46,111,114,103,47,49,57,57,57,47,48,50,47,50,50,45,114,100,102,45,115,121,110,116,97,120,45,110,
115,35,39,62,10,10,32,60,114,100,102,58,68,101,115,99,114,105,112,116,105,111,110,32,114,100,102,58,97,98,111,117,116,61,39,39,10,32,32,120,109,108,110,115,58,73,112,116,99,52,120,109,112,67,111,114,101,
61,39,104,116,116,112,58,47,47,105,112,116,99,46,111,114,103,47,115,116,100,47,73,112,116,99,52,120,109,112,67,111,114,101,47,49,46,48,47,120,109,108,110,115,47,39,62,10,32,32,60,73,112,116,99,52,120,
109,112,67,111,114,101,58,67,114,101,97,116,111,114,67,111,110,116,97,99,116,73,110,102,111,32,114,100,102,58,112,97,114,115,101,84,121,112,101,61,39,82,101,115,111,117,114,99,101,39,62,10,32,32,32,60,
73,112,116,99,52,120,109,112,67,111,114,101,58,67,105,85,114,108,87,111,114,107,62,104,116,116,112,115,58,47,47,112,105,120,121,46,111,114,103,47,115,114,99,47,52,55,52,47,52,55,52,53,55,55,52,46,112,
110,103,60,47,73,112,116,99,52,120,109,112,67,111,114,101,58,67,105,85,114,108,87,111,114,107,62,10,32,32,60,47,73,112,116,99,52,120,109,112,67,111,114,101,58,67,114,101,97,116,111,114,67,111,110,116,
97,99,116,73,110,102,111,62,10,32,60,47,114,100,102,58,68,101,115,99,114,105,112,116,105,111,110,62,10,10,32,60,114,100,102,58,68,101,115,99,114,105,112,116,105,111,110,32,114,100,102,58,97,98,111,117,
116,61,39,39,10,32,32,120,109,108,110,115,58,97,99,100,115,101,101,61,39,104,116,116,112,58,47,47,110,115,46,97,99,100,115,101,101,46,99,111,109,47,105,112,116,99,47,49,46,48,47,39,62,10,32,32,60,97,99,
100,115,101,101,58,99,97,112,116,105,111,110,62,78,111,116,101,32,77,117,115,105,99,32,67,108,101,102,32,77,101,108,111,100,121,32,70,114,101,101,100,111,109,32,78,51,60,47,97,99,100,115,101,101,58,99,
97,112,116,105,111,110,62,10,32,60,47,114,100,102,58,68,101,115,99,114,105,112,116,105,111,110,62,10,10,32,60,114,100,102,58,68,101,115,99,114,105,112,116,105,111,110,32,114,100,102,58,97,98,111,117,116,
61,39,39,10,32,32,120,109,108,110,115,58,100,99,61,39,104,116,116,112,58,47,47,112,117,114,108,46,111,114,103,47,100,99,47,101,108,101,109,101,110,116,115,47,49,46,49,47,39,62,10,32,32,60,100,99,58,99,
114,101,97,116,111,114,62,10,32,32,32,60,114,100,102,58,83,101,113,62,10,32,32,32,32,60,114,100,102,58,108,105,62,112,105,120,121,46,111,114,103,60,47,114,100,102,58,108,105,62,10,32,32,32,60,47,114,100,
102,58,83,101,113,62,10,32,32,60,47,100,99,58,99,114,101,97,116,111,114,62,10,32,32,60,100,99,58,100,101,115,99,114,105,112,116,105,111,110,62,10,32,32,32,60,114,100,102,58,65,108,116,62,10,32,32,32,32,
60,114,100,102,58,108,105,32,120,109,108,58,108,97,110,103,61,39,120,45,100,101,102,97,117,108,116,39,62,70,114,101,101,32,105,109,97,103,101,47,112,110,103,44,32,82,101,115,111,108,117,116,105,111,110,
58,32,51,48,48,48,120,51,48,48,48,44,32,70,105,108,101,32,115,105,122,101,58,32,53,51,75,98,44,32,78,111,116,101,32,77,117,115,105,99,32,67,108,101,102,32,77,101,108,111,100,121,32,70,114,101,101,100,
111,109,32,78,51,60,47,114,100,102,58,108,105,62,10,32,32,32,60,47,114,100,102,58,65,108,116,62,10,32,32,60,47,100,99,58,100,101,115,99,114,105,112,116,105,111,110,62,10,32,32,60,100,99,58,114,105,103,
104,116,115,62,10,32,32,32,60,114,100,102,58,65,108,116,62,10,32,32,32,32,60,114,100,102,58,108,105,32,120,109,108,58,108,97,110,103,61,39,120,45,100,101,102,97,117,108,116,39,62,67,67,48,60,47,114,100,
102,58,108,105,62,10,32,32,32,60,47,114,100,102,58,65,108,116,62,10,32,32,60,47,100,99,58,114,105,103,104,116,115,62,10,32,32,60,100,99,58,115,117,98,106,101,99,116,62,10,32,32,32,60,114,100,102,58,66,
97,103,62,10,32,32,32,32,60,114,100,102,58,108,105,62,110,111,116,101,44,109,117,115,105,99,44,99,108,101,102,44,109,101,108,111,100,121,44,102,114,101,101,100,111,109,44,109,117,115,105,99,97,108,32,
110,111,116,101,44,116,101,120,116,117,114,101,44,98,117,116,116,111,110,44,110,111,116,101,110,98,108,97,116,116,44,115,116,111,110,101,44,108,105,103,104,116,32,101,102,102,101,99,116,115,44,98,97,99,
107,103,114,111,117,110,100,44,115,116,114,105,110,103,115,44,103,117,105,116,97,114,115,44,114,101,108,105,101,102,44,115,111,117,110,100,44,105,99,111,110,44,116,114,101,98,108,101,32,99,108,101,102,
60,47,114,100,102,58,108,105,62,10,32,32,32,60,47,114,100,102,58,66,97,103,62,10,32,32,60,47,100,99,58,115,117,98,106,101,99,116,62,10,32,32,60,100,99,58,116,105,116,108,101,62,10,32,32,32,60,114,100,
102,58,65,108,116,62,10,32,32,32,32,60,114,100,102,58,108,105,32,120,109,108,58,108,97,110,103,61,39,120,45,100,101,102,97,117,108,116,39,62,78,111,116,101,32,77,117,115,105,99,32,67,108,101,102,32,77,
101,108,111,100,121,32,70,114,101,101,100,111,109,32,78,51,60,47,114,100,102,58,108,105,62,10,32,32,32,60,47,114,100,102,58,65,108,116,62,10,32,32,60,47,100,99,58,116,105,116,108,101,62,10,32,60,47,114,
100,102,58,68,101,115,99,114,105,112,116,105,111,110,62,10,10,32,60,114,100,102,58,68,101,115,99,114,105,112,116,105,111,110,32,114,100,102,58,97,98,111,117,116,61,39,39,10,32,32,120,109,108,110,115,58,
120,109,112,82,105,103,104,116,115,61,39,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,120,97,112,47,49,46,48,47,114,105,103,104,116,115,47,39,62,10,32,32,60,120,109,112,82,105,
103,104,116,115,58,85,115,97,103,101,84,101,114,109,115,62,10,32,32,32,60,114,100,102,58,65,108,116,62,10,32,32,32,32,60,114,100,102,58,108,105,32,120,109,108,58,108,97,110,103,61,39,120,45,100,101,102,
97,117,108,116,39,62,70,114,101,101,32,102,111,114,32,99,111,109,109,101,114,99,105,97,108,32,117,115,101,46,32,78,111,32,97,116,116,114,105,98,117,116,105,111,110,32,114,101,113,117,105,114,101,100,60,
47,114,100,102,58,108,105,62,10,32,32,32,60,47,114,100,102,58,65,108,116,62,10,32,32,60,47,120,109,112,82,105,103,104,116,115,58,85,115,97,103,101,84,101,114,109,115,62,10,32,32,60,120,109,112,82,105,
103,104,116,115,58,87,101,98,83,116,97,116,101,109,101,110,116,62,104,116,116,112,115,58,47,47,112,105,120,121,46,111,114,103,47,108,105,99,101,110,99,101,46,112,104,112,60,47,120,109,112,82,105,103,104,
116,115,58,87,101,98,83,116,97,116,101,109,101,110,116,62,10,32,60,47,114,100,102,58,68,101,115,99,114,105,112,116,105,111,110,62,10,60,47,114,100,102,58,82,68,70,62,10,60,47,120,58,120,109,112,109,101,
116,97,62,10,60,63,120,112,97,99,107,101,116,32,101,110,100,61,39,114,39,63,62,182,2,131,42,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* WillStereoDelayAudioProcessorEditor::kisspngquarternotemusicalnoteeighthnoterestmusicnotes5ad2c34d6918e6_3884611415237619974305_png = (const char*) resource_WillStereoDelayAudioProcessorEditor_kisspngquarternotemusicalnoteeighthnoterestmusicnotes5ad2c34d6918e6_3884611415237619974305_png;
const int WillStereoDelayAudioProcessorEditor::kisspngquarternotemusicalnoteeighthnoterestmusicnotes5ad2c34d6918e6_3884611415237619974305_pngSize = 57706;

// JUCER_RESOURCE: semiquaver_png, 55201, "../../../Documents/semi-quaver.png"
static const unsigned char resource_WillStereoDelayAudioProcessorEditor_semiquaver_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,9,155,0,0,9,196,8,6,0,0,0,102,108,40,248,0,0,0,9,112,72,89,
115,0,2,226,48,0,2,226,48,1,231,44,91,252,0,0,10,77,105,67,67,80,80,104,111,116,111,115,104,111,112,32,73,67,67,32,112,114,111,102,105,108,101,0,0,120,218,157,83,119,88,147,247,22,62,223,247,101,15,86,
66,216,240,177,151,108,129,0,34,35,172,8,200,16,89,162,16,146,0,97,132,16,18,64,197,133,136,10,86,20,21,17,156,72,85,196,130,213,10,72,157,136,226,160,40,184,103,65,138,136,90,139,85,92,56,238,31,220,
167,181,125,122,239,237,237,251,215,251,188,231,156,231,252,206,121,207,15,128,17,18,38,145,230,162,106,0,57,82,133,60,58,216,31,143,79,72,196,201,189,128,2,21,72,224,4,32,16,230,203,194,103,5,197,0,0,
240,3,121,120,126,116,176,63,252,1,175,111,0,2,0,112,213,46,36,18,199,225,255,131,186,80,38,87,0,32,145,0,224,34,18,231,11,1,144,82,0,200,46,84,200,20,0,200,24,0,176,83,179,100,10,0,148,0,0,108,121,124,
66,34,0,170,13,0,236,244,73,62,5,0,216,169,147,220,23,0,216,162,28,169,8,0,141,1,0,153,40,71,36,2,64,187,0,96,85,129,82,44,2,192,194,0,160,172,64,34,46,4,192,174,1,128,89,182,50,71,2,128,189,5,0,118,142,
88,144,15,64,96,0,128,153,66,44,204,0,32,56,2,0,67,30,19,205,3,32,76,3,160,48,210,191,224,169,95,112,133,184,72,1,0,192,203,149,205,151,75,210,51,20,184,149,208,26,119,242,240,224,226,33,226,194,108,177,
66,97,23,41,16,102,9,228,34,156,151,155,35,19,72,231,3,76,206,12,0,0,26,249,209,193,254,56,63,144,231,230,228,225,230,102,231,108,239,244,197,162,254,107,240,111,34,62,33,241,223,254,188,140,2,4,0,16,
78,207,239,218,95,229,229,214,3,112,199,1,176,117,191,107,169,91,0,218,86,0,104,223,249,93,51,219,9,160,90,10,208,122,249,139,121,56,252,64,30,158,161,80,200,60,29,28,10,11,11,237,37,98,161,189,48,227,
139,62,255,51,225,111,224,139,126,246,252,64,30,254,219,122,240,0,113,154,64,153,173,192,163,131,253,113,97,110,118,174,82,142,231,203,4,66,49,110,247,231,35,254,199,133,127,253,142,41,209,226,52,177,
92,44,21,138,241,88,137,184,80,34,77,199,121,185,82,145,68,33,201,149,226,18,233,127,50,241,31,150,253,9,147,119,13,0,172,134,79,192,78,182,7,181,203,108,192,126,238,1,2,139,14,88,210,118,0,64,126,243,
45,140,26,11,145,0,16,103,52,50,121,247,0,0,147,191,249,143,64,43,1,0,205,151,164,227,0,0,188,232,24,92,168,148,23,76,198,8,0,0,68,160,129,42,176,65,7,12,193,20,172,192,14,156,193,29,188,192,23,2,97,6,
68,64,12,36,192,60,16,66,6,228,128,28,10,161,24,150,65,25,84,192,58,216,4,181,176,3,26,160,17,154,225,16,180,193,49,56,13,231,224,18,92,129,235,112,23,6,96,24,158,194,24,188,134,9,4,65,200,8,19,97,33,
58,136,17,98,142,216,34,206,8,23,153,142,4,34,97,72,52,146,128,164,32,233,136,20,81,34,197,200,114,164,2,169,66,106,145,93,72,35,242,45,114,20,57,141,92,64,250,144,219,200,32,50,138,252,138,188,71,49,
148,129,178,81,3,212,2,117,64,185,168,31,26,138,198,160,115,209,116,52,15,93,128,150,162,107,209,26,180,30,61,128,182,162,167,209,75,232,117,116,0,125,138,142,99,128,209,49,14,102,140,217,97,92,140,135,
69,96,137,88,26,38,199,22,99,229,88,53,86,143,53,99,29,88,55,118,21,27,192,158,97,239,8,36,2,139,128,19,236,8,94,132,16,194,108,130,144,144,71,88,76,88,67,168,37,236,35,180,18,186,8,87,9,131,132,49,194,
39,34,147,168,79,180,37,122,18,249,196,120,98,58,177,144,88,70,172,38,238,33,30,33,158,37,94,39,14,19,95,147,72,36,14,201,146,228,78,10,33,37,144,50,73,11,73,107,72,219,72,45,164,83,164,62,210,16,105,
156,76,38,235,144,109,201,222,228,8,178,128,172,32,151,145,183,144,15,144,79,146,251,201,195,228,183,20,58,197,136,226,76,9,162,36,82,164,148,18,74,53,101,63,229,4,165,159,50,66,153,160,170,81,205,169,
158,212,8,170,136,58,159,90,73,109,160,118,80,47,83,135,169,19,52,117,154,37,205,155,22,67,203,164,45,163,213,208,154,105,103,105,247,104,47,233,116,186,9,221,131,30,69,151,208,151,210,107,232,7,233,231,
233,131,244,119,12,13,134,13,131,199,72,98,40,25,107,25,123,25,167,24,183,25,47,153,76,166,5,211,151,153,200,84,48,215,50,27,153,103,152,15,152,111,85,88,42,246,42,124,21,145,202,18,149,58,149,86,149,
126,149,231,170,84,85,115,85,63,213,121,170,11,84,171,85,15,171,94,86,125,166,70,85,179,80,227,169,9,212,22,171,213,169,29,85,187,169,54,174,206,82,119,82,143,80,207,81,95,163,190,95,253,130,250,99,13,
178,134,133,70,160,134,72,163,84,99,183,198,25,141,33,22,198,50,101,241,88,66,214,114,86,3,235,44,107,152,77,98,91,178,249,236,76,118,5,251,27,118,47,123,76,83,67,115,170,102,172,102,145,102,157,230,113,
205,1,14,198,177,224,240,57,217,156,74,206,33,206,13,206,123,45,3,45,63,45,177,214,106,173,102,173,126,173,55,218,122,218,190,218,98,237,114,237,22,237,235,218,239,117,112,157,64,157,44,157,245,58,109,
58,247,117,9,186,54,186,81,186,133,186,219,117,207,234,62,211,99,235,121,233,9,245,202,245,14,233,221,209,71,245,109,244,163,245,23,234,239,214,239,209,31,55,48,52,8,54,144,25,108,49,56,99,240,204,144,
99,232,107,152,105,184,209,240,132,225,168,17,203,104,186,145,196,104,163,209,73,163,39,184,38,238,135,103,227,53,120,23,62,102,172,111,28,98,172,52,222,101,220,107,60,97,98,105,50,219,164,196,164,197,
228,190,41,205,148,107,154,102,186,209,180,211,116,204,204,200,44,220,172,216,172,201,236,142,57,213,156,107,158,97,190,217,188,219,252,141,133,165,69,156,197,74,139,54,139,199,150,218,150,124,203,5,150,
77,150,247,172,152,86,62,86,121,86,245,86,215,172,73,214,92,235,44,235,109,214,87,108,80,27,87,155,12,155,58,155,203,182,168,173,155,173,196,118,155,109,223,20,226,20,143,41,210,41,245,83,110,218,49,236,
252,236,10,236,154,236,6,237,57,246,97,246,37,246,109,246,207,29,204,28,18,29,214,59,116,59,124,114,116,117,204,118,108,112,188,235,164,225,52,195,169,196,169,195,233,87,103,27,103,161,115,157,243,53,
23,166,75,144,203,18,151,118,151,23,83,109,167,138,167,110,159,122,203,149,229,26,238,186,210,181,211,245,163,155,187,155,220,173,217,109,212,221,204,61,197,125,171,251,77,46,155,27,201,93,195,61,239,
65,244,240,247,88,226,113,204,227,157,167,155,167,194,243,144,231,47,94,118,94,89,94,251,189,30,79,179,156,38,158,214,48,109,200,219,196,91,224,189,203,123,96,58,62,61,101,250,206,233,3,62,198,62,2,159,
122,159,135,190,166,190,34,223,61,190,35,126,214,126,153,126,7,252,158,251,59,250,203,253,143,248,191,225,121,242,22,241,78,5,96,1,193,1,229,1,189,129,26,129,179,3,107,3,31,4,153,4,165,7,53,5,141,5,187,
6,47,12,62,21,66,12,9,13,89,31,114,147,111,192,23,242,27,249,99,51,220,103,44,154,209,21,202,8,157,21,90,27,250,48,204,38,76,30,214,17,142,134,207,8,223,16,126,111,166,249,76,233,204,182,8,136,224,71,
108,136,184,31,105,25,153,23,249,125,20,41,42,50,170,46,234,81,180,83,116,113,116,247,44,214,172,228,89,251,103,189,142,241,143,169,140,185,59,219,106,182,114,118,103,172,106,108,82,108,99,236,155,184,
128,184,170,184,129,120,135,248,69,241,151,18,116,19,36,9,237,137,228,196,216,196,61,137,227,115,2,231,108,154,51,156,228,154,84,150,116,99,174,229,220,162,185,23,230,233,206,203,158,119,60,89,53,89,144,
124,56,133,152,18,151,178,63,229,131,32,66,80,47,24,79,229,167,110,77,29,19,242,132,155,133,79,69,190,162,141,162,81,177,183,184,74,60,146,230,157,86,149,246,56,221,59,125,67,250,104,134,79,70,117,198,
51,9,79,82,43,121,145,25,146,185,35,243,77,86,68,214,222,172,207,217,113,217,45,57,148,156,148,156,163,82,13,105,150,180,43,215,48,183,40,183,79,102,43,43,147,13,228,121,230,109,202,27,147,135,202,247,
228,35,249,115,243,219,21,108,133,76,209,163,180,82,174,80,14,22,76,47,168,43,120,91,24,91,120,184,72,189,72,90,212,51,223,102,254,234,249,35,11,130,22,124,189,144,176,80,184,176,179,216,184,120,89,241,
224,34,191,69,187,22,35,139,83,23,119,46,49,93,82,186,100,120,105,240,210,125,203,104,203,178,150,253,80,226,88,82,85,242,106,121,220,242,142,82,131,210,165,165,67,43,130,87,52,149,169,148,201,203,110,
174,244,90,185,99,21,97,149,100,85,239,106,151,213,91,86,127,42,23,149,95,172,112,172,168,174,248,176,70,184,230,226,87,78,95,213,124,245,121,109,218,218,222,74,183,202,237,235,72,235,164,235,110,172,
247,89,191,175,74,189,106,65,213,208,134,240,13,173,27,241,141,229,27,95,109,74,222,116,161,122,106,245,142,205,180,205,202,205,3,53,97,53,237,91,204,182,172,219,242,161,54,163,246,122,157,127,93,203,
86,253,173,171,183,190,217,38,218,214,191,221,119,123,243,14,131,29,21,59,222,239,148,236,188,181,43,120,87,107,189,69,125,245,110,210,238,130,221,143,26,98,27,186,191,230,126,221,184,71,119,79,197,158,
143,123,165,123,7,246,69,239,235,106,116,111,108,220,175,191,191,178,9,109,82,54,141,30,72,58,112,229,155,128,111,218,155,237,154,119,181,112,90,42,14,194,65,229,193,39,223,166,124,123,227,80,232,161,
206,195,220,195,205,223,153,127,183,245,8,235,72,121,43,210,58,191,117,172,45,163,109,160,61,161,189,239,232,140,163,157,29,94,29,71,190,183,255,126,239,49,227,99,117,199,53,143,87,158,160,157,40,61,241,
249,228,130,147,227,167,100,167,158,157,78,63,61,212,153,220,121,247,76,252,153,107,93,81,93,189,103,67,207,158,63,23,116,238,76,183,95,247,201,243,222,231,143,93,240,188,112,244,34,247,98,219,37,183,
75,173,61,174,61,71,126,112,253,225,72,175,91,111,235,101,247,203,237,87,60,174,116,244,77,235,59,209,239,211,127,250,106,192,213,115,215,248,215,46,93,159,121,189,239,198,236,27,183,110,38,221,28,184,
37,186,245,248,118,246,237,23,119,10,238,76,220,93,122,143,120,175,252,190,218,253,234,7,250,15,234,127,180,254,177,101,192,109,224,248,96,192,96,207,195,89,15,239,14,9,135,158,254,148,255,211,135,225,
210,71,204,71,213,35,70,35,141,143,157,31,31,27,13,26,189,242,100,206,147,225,167,178,167,19,207,202,126,86,255,121,235,115,171,231,223,253,226,251,75,207,88,252,216,240,11,249,139,207,191,174,121,169,
243,114,239,171,169,175,58,199,35,199,31,188,206,121,61,241,166,252,173,206,219,125,239,184,239,186,223,199,189,31,153,40,252,64,254,80,243,209,250,99,199,167,208,79,247,62,231,124,254,252,47,247,132,
243,251,37,210,159,51,0,0,0,4,103,65,77,65,0,0,177,142,124,251,81,147,0,0,0,32,99,72,82,77,0,0,122,37,0,0,128,131,0,0,249,255,0,0,128,233,0,0,117,48,0,0,234,96,0,0,58,152,0,0,23,111,146,95,197,70,0,0,
204,190,73,68,65,84,120,218,236,221,223,113,20,215,218,246,225,91,95,237,243,221,25,188,67,4,110,34,96,136,192,67,4,110,34,0,34,0,71,32,50,24,101,128,50,64,25,88,25,188,10,97,50,224,59,88,195,107,140,
129,53,255,167,187,215,117,85,77,201,7,187,108,233,102,91,85,174,250,213,179,110,190,124,249,18,0,0,0,0,0,0,0,0,0,248,149,27,177,25,0,0,0,0,0,0,0,0,0,53,98,51,0,0,0,0,0,0,0,0,0,170,196,102,0,0,0,0,0,0,
0,0,0,84,137,205,0,0,0,0,0,0,0,0,0,168,18,155,1,0,0,0,0,0,0,0,0,80,37,54,3,0,0,0,0,0,0,0,0,160,74,108,6,0,0,0,0,0,0,0,0,64,149,216,12,0,0,0,0,0,0,0,0,128,42,177,25,0,0,0,0,0,0,0,0,0,85,98,51,0,0,0,0,0,
0,0,0,0,170,196,102,0,0,0,0,0,0,0,0,0,84,137,205,0,0,0,0,0,0,0,0,0,168,18,155,1,0,0,0,0,0,0,0,0,80,37,54,3,0,0,0,0,0,0,0,0,160,74,108,6,0,0,0,0,0,0,0,0,64,149,216,12,0,0,0,0,0,0,0,0,128,42,177,25,0,0,
0,0,0,0,0,0,0,85,98,51,0,0,0,0,0,0,0,0,0,170,196,102,0,0,0,0,0,0,0,0,0,84,137,205,0,0,0,0,0,0,0,0,0,168,18,155,1,0,0,0,0,0,0,0,0,80,37,54,3,0,0,0,0,0,0,0,0,160,74,108,6,0,0,0,0,0,0,0,0,64,149,216,12,0,
0,0,0,0,0,0,0,128,42,177,25,0,0,0,0,0,0,0,0,0,85,98,51,0,0,0,0,0,0,0,0,0,170,196,102,0,0,0,0,0,0,0,0,0,84,137,205,0,0,0,0,0,0,0,0,0,168,18,155,1,0,0,0,0,0,0,0,0,80,37,54,3,0,0,0,0,0,0,0,0,160,74,108,6,
0,0,0,0,0,0,0,0,64,149,216,12,0,0,0,0,0,0,0,0,128,42,177,25,0,0,0,0,0,0,0,0,0,85,98,51,0,0,0,0,0,0,0,0,0,170,196,102,0,0,0,0,0,0,0,0,0,84,137,205,0,0,0,0,0,0,0,0,0,168,18,155,1,0,0,0,0,0,0,0,0,80,37,54,
3,0,0,0,0,0,0,0,0,160,74,108,6,0,0,0,0,0,0,0,0,64,149,216,12,0,0,0,0,0,0,0,0,128,42,177,25,0,0,0,0,0,0,0,0,0,85,98,51,0,0,0,0,0,0,0,0,0,170,196,102,0,0,0,0,0,0,0,0,0,84,137,205,0,0,0,0,0,0,0,0,0,168,18,
155,1,0,0,0,0,0,0,0,0,80,37,54,3,0,0,0,0,0,0,0,0,160,74,108,6,0,0,0,0,0,0,0,0,64,149,216,12,0,0,0,0,0,0,0,0,128,42,177,25,0,0,0,0,0,0,0,0,0,85,98,51,0,0,0,0,0,0,0,0,0,170,196,102,0,0,0,0,0,0,0,0,0,84,
137,205,0,0,0,0,0,0,0,0,0,168,18,155,1,0,0,0,0,0,0,0,0,80,37,54,3,0,0,0,0,0,0,0,0,160,74,108,6,0,0,0,0,0,0,0,0,64,149,216,12,0,0,0,0,0,0,0,0,128,42,177,25,0,0,0,0,0,0,0,0,0,85,98,51,0,0,0,0,0,0,0,0,0,
170,196,102,0,0,0,0,0,0,0,0,0,84,137,205,0,0,0,0,0,0,0,0,0,168,18,155,1,0,0,0,0,0,0,0,0,80,37,54,3,0,0,0,0,0,0,0,0,160,74,108,6,0,0,0,0,0,0,0,0,64,149,216,12,0,0,0,0,0,0,0,0,128,42,177,25,0,0,0,0,0,0,
0,0,0,85,98,51,0,0,0,0,0,0,0,0,0,170,196,102,0,0,0,0,0,0,0,0,0,84,137,205,0,0,0,0,0,0,0,0,0,168,18,155,1,0,0,0,0,0,0,0,0,80,37,54,3,0,0,0,0,0,0,0,0,160,74,108,6,0,0,0,0,0,0,0,0,64,149,216,12,0,0,0,0,0,
0,0,0,128,42,177,25,0,0,0,0,0,0,0,0,0,85,98,51,0,0,0,0,0,0,0,0,0,170,196,102,0,0,0,0,0,0,0,0,0,84,137,205,0,0,0,0,0,0,0,0,0,168,18,155,1,0,0,0,0,0,0,0,0,80,37,54,3,0,0,0,0,0,0,0,0,160,74,108,6,0,0,0,0,
0,0,0,0,64,149,216,12,0,0,0,0,0,0,0,0,128,42,177,25,0,0,0,0,0,0,0,0,0,85,98,51,0,0,0,0,0,0,0,0,0,170,196,102,0,0,0,0,0,0,0,0,0,84,137,205,0,0,0,0,0,0,0,0,0,168,18,155,1,0,0,0,0,0,0,0,0,80,37,54,3,0,0,
0,0,0,0,0,0,160,74,108,6,0,0,0,0,0,0,0,0,64,149,216,12,0,0,0,0,0,0,0,0,128,42,177,25,0,0,0,0,0,0,0,0,0,85,98,51,0,0,0,0,0,0,0,0,0,170,196,102,0,0,0,0,0,0,0,0,0,84,137,205,0,0,0,0,0,0,0,0,0,168,18,155,
1,0,0,0,0,0,0,0,0,80,37,54,3,0,0,0,0,0,0,0,0,160,74,108,6,0,0,0,0,0,0,0,0,64,149,216,12,0,0,0,0,0,0,0,0,128,42,177,25,0,0,0,0,0,0,0,0,0,85,98,51,0,0,0,0,0,0,0,0,0,170,196,102,0,0,0,0,0,0,0,0,0,84,137,
205,0,0,0,0,0,0,0,0,0,168,18,155,1,0,0,0,0,0,0,0,0,80,37,54,3,0,0,0,0,0,0,0,0,160,74,108,6,0,0,0,0,0,0,0,0,64,149,216,12,0,0,0,0,0,0,0,0,128,42,177,25,0,0,0,0,0,0,0,0,0,85,98,51,0,0,0,0,0,0,0,0,0,170,
196,102,0,0,0,0,0,0,0,0,0,84,137,205,0,0,0,0,0,0,0,0,0,168,18,155,1,0,0,0,0,0,0,0,0,80,37,54,3,0,0,0,0,0,0,0,0,160,74,108,6,0,0,0,0,0,0,0,0,64,149,216,12,0,0,0,0,0,0,0,0,128,42,177,25,0,0,0,0,0,0,0,0,
0,85,98,51,0,0,0,0,0,0,0,0,0,170,196,102,0,0,0,0,0,0,0,0,0,84,137,205,0,0,0,0,0,0,0,0,0,168,18,155,1,0,0,0,0,0,0,0,0,80,37,54,3,0,0,0,0,0,0,0,0,160,74,108,6,0,0,0,0,0,0,0,0,64,149,216,12,0,0,0,0,0,0,0,
0,128,42,177,25,0,0,0,0,0,0,0,0,0,85,98,51,0,0,0,0,0,0,0,0,0,170,196,102,0,0,0,0,0,0,0,0,0,84,137,205,0,0,0,0,0,0,0,0,0,168,18,155,1,0,0,0,0,0,0,0,0,80,37,54,3,0,0,0,0,0,0,0,0,160,74,108,6,0,0,0,0,0,0,
0,0,64,149,216,12,0,0,0,0,0,0,0,0,128,42,177,25,0,0,0,0,0,0,0,0,0,85,98,51,0,0,0,0,0,0,0,0,0,170,196,102,0,0,0,0,0,0,0,0,0,84,137,205,0,0,0,0,0,0,0,0,0,168,18,155,1,0,0,0,0,0,0,0,0,80,37,54,3,0,0,0,0,
0,0,0,0,160,74,108,6,0,0,0,0,0,0,0,0,64,149,216,12,0,0,0,0,0,0,0,0,128,42,177,25,0,0,0,0,0,0,0,0,0,85,98,51,0,0,0,0,0,0,0,0,0,170,196,102,0,0,0,0,0,0,0,0,0,84,137,205,0,0,0,0,0,0,0,0,0,168,18,155,1,0,
0,0,0,0,0,0,0,80,37,54,3,0,0,0,0,0,0,0,0,160,74,108,6,0,0,0,0,0,0,0,0,64,149,216,12,0,0,0,0,0,0,0,0,128,42,177,25,0,0,0,0,0,0,0,0,0,85,98,51,0,0,0,0,0,0,0,0,0,170,196,102,0,0,0,0,0,0,0,0,0,84,137,205,
0,0,0,0,0,0,0,0,0,168,18,155,1,0,0,0,0,0,0,0,0,80,37,54,3,0,0,0,0,0,0,0,0,160,74,108,6,0,0,0,0,0,0,0,0,64,149,216,12,0,0,0,0,0,0,0,0,128,42,177,25,0,0,0,0,0,0,0,0,0,85,98,51,0,0,0,0,0,0,0,0,0,170,196,
102,0,0,0,0,0,0,0,0,0,84,137,205,0,0,0,0,0,0,0,0,0,168,18,155,1,0,0,0,0,0,0,0,0,80,37,54,3,0,0,0,0,0,0,0,0,160,74,108,6,0,0,0,0,0,0,0,0,64,149,216,12,0,0,0,0,0,0,0,0,128,42,177,25,0,0,0,0,0,0,0,0,0,85,
98,51,0,0,0,0,0,0,0,0,0,170,196,102,0,0,0,0,0,0,0,0,0,84,137,205,0,0,0,0,0,0,0,0,0,168,18,155,1,0,0,0,0,0,0,0,0,80,37,54,3,0,0,0,0,0,0,0,0,160,74,108,6,0,0,0,0,0,0,0,0,64,149,216,12,0,0,0,0,0,0,0,0,128,
42,177,25,0,0,0,0,0,0,0,0,0,85,98,51,0,0,0,0,0,0,0,0,0,170,196,102,0,0,0,0,0,0,0,0,0,84,137,205,0,0,0,0,0,0,0,0,0,168,18,155,1,0,0,0,0,0,0,0,0,80,37,54,3,0,0,0,0,0,0,0,0,160,74,108,6,0,0,0,0,0,0,0,0,64,
149,216,12,0,0,0,0,0,0,0,0,128,42,177,25,0,0,0,0,0,0,0,0,0,85,98,51,0,0,0,0,0,0,0,0,0,170,196,102,0,0,0,0,0,0,0,0,0,84,137,205,0,0,0,0,0,0,0,0,0,168,18,155,1,0,0,0,0,0,0,0,0,80,37,54,3,0,0,0,0,0,0,0,0,
160,74,108,6,0,0,0,0,0,0,0,0,64,149,216,12,0,0,0,0,0,0,0,0,128,42,177,25,0,0,0,0,0,0,0,0,0,85,98,51,0,0,0,0,0,0,0,0,0,170,196,102,0,0,0,0,0,0,0,0,0,84,137,205,0,0,0,0,0,0,0,0,0,168,18,155,1,0,0,0,0,0,
0,0,0,80,37,54,3,0,0,0,0,0,0,0,0,160,74,108,6,0,0,0,0,0,0,0,0,64,149,216,12,0,0,0,0,0,0,0,0,128,42,177,25,0,0,0,0,0,0,0,0,0,85,98,51,0,0,0,0,0,0,0,0,0,170,196,102,0,0,0,0,0,0,0,0,0,84,137,205,0,0,0,0,
0,0,0,0,0,168,18,155,1,0,0,0,0,0,0,0,0,80,37,54,3,0,0,0,0,0,0,0,0,160,74,108,6,0,0,0,0,0,0,0,0,64,149,216,12,0,0,0,0,0,0,0,0,128,42,177,25,0,0,0,0,0,0,0,0,0,85,98,51,0,0,0,0,0,0,0,0,0,170,196,102,0,0,
0,0,0,0,0,0,0,84,137,205,0,0,0,0,0,0,0,0,0,168,18,155,1,0,0,0,0,0,0,0,0,80,37,54,3,0,0,0,0,0,0,0,0,160,74,108,6,0,0,0,0,0,0,0,0,64,149,216,12,0,0,0,0,0,0,0,0,128,42,177,25,0,0,0,0,0,0,0,0,0,85,98,51,0,
0,0,0,0,0,0,0,0,170,196,102,0,0,0,0,0,0,0,0,0,84,137,205,0,0,0,0,0,0,0,0,0,168,18,155,1,0,0,0,0,0,0,0,0,80,37,54,3,0,0,0,0,0,0,0,0,160,74,108,6,0,0,0,0,0,0,0,0,64,149,216,12,0,0,0,0,0,0,0,0,128,42,177,
25,0,0,0,0,0,0,0,0,0,85,98,51,0,0,0,0,0,0,0,0,0,170,196,102,0,0,0,0,0,0,0,0,0,84,137,205,0,0,0,0,0,0,0,0,0,168,18,155,1,0,0,0,0,0,0,0,0,80,37,54,3,0,0,0,0,0,0,0,0,160,74,108,6,0,0,0,0,0,0,0,0,64,149,216,
12,0,0,0,0,0,0,0,0,128,42,177,25,0,0,0,0,0,0,0,0,0,85,98,51,0,0,0,0,0,0,0,0,0,170,196,102,0,0,0,0,0,0,0,0,0,84,137,205,0,0,0,0,0,0,0,0,0,168,18,155,1,0,0,0,0,0,0,0,0,80,37,54,3,0,0,0,0,0,0,0,0,160,74,
108,6,0,0,0,0,0,0,0,0,64,149,216,12,0,0,0,0,0,0,0,0,128,42,177,25,0,0,0,0,0,0,0,0,0,85,98,51,0,0,0,0,0,0,0,0,0,170,196,102,0,0,0,0,0,0,0,0,0,84,137,205,0,0,0,0,0,0,0,0,0,168,18,155,1,0,0,0,0,0,0,0,0,80,
37,54,3,0,0,0,0,0,0,0,0,160,74,108,6,0,0,0,0,0,0,0,0,64,149,216,12,0,0,0,0,0,0,0,0,128,42,177,25,0,0,0,0,0,0,0,0,0,85,98,51,0,0,0,0,0,0,0,0,0,170,196,102,0,0,0,0,0,0,0,0,0,84,137,205,0,0,0,0,0,0,0,0,0,
168,18,155,1,0,0,0,0,0,0,0,0,80,37,54,3,0,0,0,0,0,0,0,0,160,74,108,6,0,0,0,0,0,0,0,0,64,149,216,12,0,0,0,0,0,0,0,0,128,42,177,25,0,0,0,0,0,0,0,0,0,85,98,51,0,0,0,0,0,0,0,0,0,170,196,102,0,0,0,0,0,0,0,
0,0,84,137,205,0,0,0,0,0,0,0,0,0,168,18,155,1,0,0,0,0,0,0,0,0,80,37,54,3,0,0,0,0,0,0,0,0,160,74,108,6,0,0,0,0,0,0,0,0,64,149,216,12,0,0,0,0,0,0,0,0,128,42,177,25,0,0,0,0,0,0,0,0,0,85,98,51,0,0,0,0,0,0,
0,0,0,170,196,102,0,0,0,0,0,0,0,0,0,84,137,205,0,0,0,0,0,0,0,0,0,168,18,155,1,0,0,0,0,0,0,0,0,80,37,54,3,0,0,0,0,0,0,0,0,160,74,108,6,0,0,0,0,0,0,0,0,64,149,216,12,0,0,0,0,0,0,0,0,128,42,177,25,0,0,0,
0,0,0,0,0,0,85,98,51,0,0,128,93,254,227,233,230,102,72,242,199,4,191,245,151,254,187,15,0,0,0,0,0,56,133,255,152,0,0,0,96,39,139,36,203,137,126,223,79,254,248,0,0,0,0,0,128,99,253,63,19,0,0,0,204,218,
194,4,0,0,0,0,0,192,41,136,205,0,0,0,0,0,0,0,0,0,168,18,155,1,0,0,0,0,0,0,0,0,80,37,54,3,0,0,152,183,206,4,0,0,0,0,0,192,41,136,205,0,0,0,230,173,191,185,185,201,33,31,0,0,0,0,0,128,111,137,205,0,0,0,
0,0,0,0,0,0,168,18,155,1,0,0,0,0,0,0,0,0,80,37,54,3,0,0,152,183,255,154,0,0,0,0,0,0,56,5,177,25,0,0,192,188,245,38,0,0,0,0,0,0,78,65,108,6,0,0,0,0,0,0,0,0,64,149,216,12,0,0,0,0,0,0,0,0,128,42,177,25,0,
0,192,188,45,76,0,0,0,0,0,0,156,130,216,12,0,0,96,222,22,38,0,0,0,0,0,0,78,65,108,6,0,0,0,0,0,0,0,0,64,149,216,12,0,0,96,254,58,19,0,0,0,0,0,0,199,18,155,1,0,0,204,95,111,2,0,0,0,0,0,224,88,98,51,0,0,
0,0,0,0,0,0,0,170,196,102,0,0,0,0,0,0,0,0,0,84,137,205,0,0,0,230,111,105,2,0,0,0,0,0,224,88,98,51,0,0,0,0,0,0,0,0,0,170,196,102,0,0,0,0,0,0,0,0,0,84,137,205,0,0,0,230,239,133,9,0,0,0,0,0,128,99,137,205,
0,0,0,0,0,0,0,0,0,168,18,155,1,0,0,0,0,0,0,0,0,80,37,54,3,0,0,152,191,165,9,0,0,0,0,0,128,99,137,205,0,0,0,0,0,0,0,0,0,168,18,155,1,0,0,180,97,97,2,0,0,0,0,0,224,24,98,51,0,0,128,54,44,76,0,0,0,0,0,0,
28,67,108,6,0,0,0,0,0,0,0,0,64,149,216,12,0,0,160,13,189,9,0,0,0,0,0,128,99,136,205,0,0,0,218,208,153,0,0,0,0,0,0,56,134,216,12,0,0,160,13,255,53,1,0,0,0,0,0,112,12,177,25,0,0,64,27,122,19,0,0,0,0,0,0,
199,16,155,1,0,0,0,0,0,0,0,0,80,37,54,3,0,0,104,195,210,4,0,0,0,0,0,192,49,196,102,0,0,0,0,0,0,0,0,0,84,137,205,0,0,0,218,209,155,0,0,0,0,0,0,56,148,216,12,0,0,160,29,157,9,0,0,0,0,0,128,67,137,205,0,
0,0,218,177,48,1,0,0,0,0,0,112,40,177,25,0,0,64,59,22,38,0,0,0,0,0,0,14,37,54,3,0,0,104,199,255,152,0,0,0,0,0,0,56,148,216,12,0,0,160,29,11,19,0,0,0,0,0,0,135,18,155,1,0,0,180,99,97,2,0,0,0,0,0,224,80,
98,51,0,0,128,118,44,76,0,0,0,0,0,0,28,74,108,6,0,0,208,150,133,9,0,0,0,0,0,128,67,136,205,0,0,0,218,178,48,1,0,0,0,0,0,112,8,177,25,0,0,64,91,122,19,0,0,0,0,0,0,135,16,155,1,0,0,180,165,51,1,0,0,0,0,
0,112,8,177,25,0,0,64,91,126,51,1,0,0,0,0,0,112,8,177,25,0,0,64,91,58,19,0,0,0,0,0,0,135,16,155,1,0,0,180,101,105,2,0,0,0,0,0,224,16,98,51,0,0,128,246,116,38,0,0,0,0,0,0,246,37,54,3,0,0,104,79,111,2,0,
0,0,0,0,96,95,98,51,0,0,128,246,244,38,0,0,0,0,0,0,246,37,54,3,0,0,104,79,103,2,0,0,0,0,0,96,95,98,51,0,0,128,246,188,48,1,0,0,0,0,0,176,47,177,25,0,0,64,123,22,38,0,0,0,0,0,0,246,37,54,3,0,0,104,207,
194,4,0,0,0,0,0,192,190,196,102,0,0,0,109,90,154,0,0,0,0,0,0,216,135,216,12,0,0,160,77,11,19,0,0,0,0,0,0,251,16,155,1,0,0,180,105,97,2,0,0,0,0,0,96,31,98,51,0,0,128,54,189,48,1,0,0,0,0,0,176,15,177,25,
0,0,64,155,22,38,0,0,0,0,0,0,246,33,54,3,0,0,104,211,194,4,0,0,0,0,0,192,62,196,102,0,0,0,237,90,154,0,0,0,0,0,0,216,149,216,12,0,0,160,93,189,9,0,0,0,0,0,128,93,137,205,0,0,0,218,245,63,38,0,0,0,0,0,
0,118,37,54,3,0,0,104,87,111,2,0,0,0,0,0,96,87,98,51,0,0,128,118,45,77,0,0,0,0,0,0,236,74,108,6,0,0,208,182,222,4,0,0,0,0,0,192,46,196,102,0,0,0,109,235,77,0,0,0,0,0,0,236,66,108,6,0,0,208,182,223,76,
0,0,0,0,0,0,236,66,108,6,0,0,208,182,222,4,0,0,0,0,0,192,46,196,102,0,0,0,109,91,154,0,0,0,0,0,0,216,133,216,12,0,0,128,222,4,0,0,0,0,0,64,141,216,12,0,0,128,222,4,0,0,0,0,0,64,141,216,12,0,0,128,223,
76,0,0,0,0,0,0,212,136,205,0,0,0,88,154,0,0,0,0,0,0,168,17,155,1,0,0,208,155,0,0,0,0,0,0,168,17,155,1,0,0,144,184,110,6,0,0,0,0,0,84,136,205,0,0,0,72,196,102,0,0,0,0,0,64,133,216,12,0,0,128,36,249,205,
4,0,0,0,0,0,192,175,136,205,0,0,0,72,92,54,3,0,0,0,0,0,42,196,102,0,0,0,36,73,151,164,55,3,0,0,0,0,0,240,51,98,51,0,0,0,190,234,77,0,0,0,0,0,0,252,140,216,12,0,0,128,175,94,152,0,0,0,0,0,0,248,25,177,
25,0,0,0,95,45,77,0,0,0,0,0,0,252,140,216,12,0,0,128,175,22,219,15,0,0,0,0,0,192,191,136,205,0,0,0,248,214,210,4,0,0,0,0,0,192,143,136,205,0,0,0,248,214,11,19,0,0,0,0,0,0,63,34,54,3,0,0,224,91,75,19,0,
0,0,0,0,0,63,34,54,3,0,0,224,91,139,237,7,0,0,0,0,0,224,31,196,102,0,0,0,124,111,105,2,0,0,0,0,0,224,123,98,51,0,0,0,190,247,187,9,0,0,0,0,0,128,239,137,205,0,0,0,248,222,210,4,0,0,0,0,0,192,247,196,102,
0,0,0,124,175,75,210,155,1,0,0,0,0,0,248,150,216,12,0,0,128,31,89,153,0,0,0,0,0,0,248,150,216,12,0,0,128,31,249,221,4,0,0,0,0,0,192,183,254,99,2,0,0,0,126,160,191,185,185,233,146,108,76,49,15,95,190,124,
49,2,0,0,0,0,0,71,113,217,12,0,0,128,159,89,153,0,0,0,0,0,0,248,74,108,6,0,0,192,207,188,48,1,0,0,0,0,0,240,149,216,12,0,0,128,159,89,153,0,0,0,0,0,0,248,74,108,6,0,0,192,207,116,73,122,51,0,0,0,0,0,0,
137,216,12,0,0,128,95,251,195,4,0,0,0,0,0,64,34,54,3,0,0,224,215,150,38,0,0,0,0,0,0,18,177,25,0,0,0,191,214,39,89,152,1,0,0,0,0,0,16,155,1,0,0,80,179,50,1,0,0,0,0,0,32,54,3,0,0,160,230,15,19,0,0,0,0,0,
0,98,51,0,0,0,106,250,120,74,19,0,0,0,0,0,154,39,54,3,0,0,96,23,75,19,0,0,0,0,0,64,219,196,102,0,0,0,236,226,119,19,0,0,0,0,0,64,219,196,102,0,0,0,236,98,149,164,51,3,0,0,0,0,0,180,75,108,6,0,0,192,174,
86,38,0,0,0,0,0,128,118,137,205,0,0,0,216,149,167,52,1,0,0,0,0,160,97,98,51,0,0,0,118,181,74,178,48,3,0,0,0,0,0,180,73,108,6,0,0,192,62,86,38,0,0,0,0,0,128,54,137,205,0,0,0,216,199,31,38,0,0,0,0,0,128,
54,137,205,0,0,0,216,71,31,79,105,2,0,0,0,0,64,147,196,102,0,0,0,236,107,48,1,0,0,0,0,0,180,71,108,6,0,0,192,190,60,165,9,0,0,0,0,0,13,18,155,1,0,0,176,175,69,202,115,154,0,0,0,0,0,64,67,196,102,0,0,0,
28,226,141,9,0,0,0,0,0,160,45,98,51,0,0,0,14,177,50,1,0,0,0,0,0,180,69,108,6,0,0,192,33,186,36,131,25,0,0,0,0,0,160,29,98,51,0,0,0,14,245,135,9,0,0,0,0,0,160,29,98,51,0,0,0,14,181,76,178,48,3,0,0,0,0,
0,180,65,108,6,0,0,192,49,222,152,0,0,0,0,0,0,218,32,54,3,0,0,224,24,131,9,0,0,0,0,0,160,13,98,51,0,0,0,142,209,69,112,6,0,0,0,0,0,77,16,155,1,0,0,112,172,63,76,0,0,0,0,0,0,243,39,54,3,0,0,224,88,203,
36,11,51,0,0,0,0,0,192,188,137,205,0,0,0,56,133,55,38,0,0,0,0,0,128,121,19,155,1,0,0,112,10,67,146,206,12,0,0,0,0,0,48,95,98,51,0,0,0,78,161,75,178,50,3,0,0,0,0,0,204,151,216,12,0,0,128,83,121,111,2,0,
0,0,0,0,152,47,177,25,0,0,0,167,178,72,178,52,3,0,0,0,0,0,204,147,216,12,0,0,128,83,114,221,12,0,0,0,0,0,102,74,108,6,0,0,192,41,45,83,46,156,1,0,0,0,0,0,51,35,54,3,0,0,224,212,92,55,3,0,0,0,0,128,25,
18,155,1,0,0,112,106,67,146,206,12,0,0,0,0,0,48,47,98,51,0,0,0,206,225,173,9,0,0,0,0,0,96,94,196,102,0,0,0,156,195,155,184,110,6,0,0,0,0,0,179,34,54,3,0,0,224,28,186,148,231,52,1,0,0,0,0,128,153,16,155,
1,0,0,112,46,111,76,0,0,0,0,0,0,243,33,54,3,0,0,224,92,22,113,221,12,0,0,0,0,0,102,67,108,6,0,0,192,57,189,55,1,0,0,0,0,0,204,131,216,12,0,0,128,115,90,196,117,51,0,0,0,0,0,152,5,177,25,0,0,0,231,230,
186,25,0,0,0,0,0,204,128,216,12,0,0,128,115,91,196,117,51,0,0,0,0,0,152,60,177,25,0,0,0,151,224,186,25,0,0,0,0,0,76,156,216,12,0,0,128,75,88,196,117,51,0,0,0,0,0,152,52,177,25,0,0,0,151,226,186,25,0,0,
0,0,0,76,152,216,12,0,0,128,75,89,196,117,51,0,0,0,0,0,152,44,177,25,0,0,0,151,244,62,73,103,6,0,0,0,0,0,152,30,177,25,0,0,0,151,180,72,242,214,12,0,0,0,0,0,48,61,98,51,0,0,0,46,237,77,92,55,3,0,0,0,0,
128,201,17,155,1,0,0,112,105,93,92,55,3,0,0,0,0,128,201,17,155,1,0,0,112,13,239,83,158,212,4,0,0,0,0,0,38,66,108,6,0,0,192,181,188,55,1,0,0,0,0,0,76,135,216,12,0,0,128,107,25,146,44,205,0,0,0,0,0,0,211,
32,54,3,0,0,224,154,92,55,3,0,0,0,0,128,137,16,155,1,0,0,112,77,203,148,11,103,0,0,0,0,0,192,200,137,205,0,0,0,184,182,247,73,58,51,0,0,0,0,0,192,184,137,205,0,0,0,184,182,69,146,183,102,0,0,0,0,0,128,
113,19,155,1,0,0,48,6,111,82,162,51,0,0,0,0,0,96,164,196,102,0,0,0,140,65,151,228,214,12,0,0,0,0,0,48,94,98,51,0,0,0,198,98,149,100,105,6,0,0,0,0,0,24,39,177,25,0,0,0,99,178,78,185,114,6,0,0,0,0,0,140,
140,216,12,0,0,128,49,89,36,121,107,6,0,0,0,0,0,24,31,177,25,0,0,0,99,243,62,37,58,3,0,0,0,0,0,70,68,108,6,0,0,192,24,173,77,0,0,0,0,0,0,227,34,54,3,0,0,96,140,150,241,156,38,0,0,0,0,0,140,138,216,12,
0,0,128,177,122,159,164,51,3,0,0,0,0,0,140,131,216,12,0,0,128,177,234,226,57,77,0,0,0,0,0,24,13,177,25,0,0,0,99,182,218,126,0,0,0,0,0,128,43,19,155,1,0,0,48,118,235,120,78,19,0,0,0,0,0,174,78,108,6,0,
0,192,216,117,241,156,38,0,0,0,0,0,92,157,216,12,0,0,128,41,88,197,115,154,0,0,0,0,0,112,85,98,51,0,0,0,166,194,115,154,0,0,0,0,0,112,69,98,51,0,0,0,166,162,139,231,52,1,0,0,0,0,224,106,196,102,0,0,0,
76,201,42,201,96,6,0,0,0,0,0,184,60,177,25,0,0,0,83,115,155,100,97,6,0,0,0,0,0,184,44,177,25,0,0,0,83,211,37,249,100,6,0,0,0,0,0,184,44,177,25,0,0,0,83,212,39,249,96,6,0,0,0,0,0,184,28,177,25,0,0,0,83,
245,62,201,210,12,0,0,0,0,0,112,25,98,51,0,0,0,166,108,157,242,172,38,0,0,0,0,0,112,102,98,51,0,0,0,166,108,145,18,156,1,0,0,0,0,0,103,38,54,3,0,0,96,234,86,73,222,154,1,0,0,0,0,0,206,75,108,6,0,0,192,
28,220,38,233,205,0,0,0,0,0,0,231,35,54,3,0,0,96,46,62,37,233,204,0,0,0,0,0,0,231,33,54,3,0,0,96,46,22,73,214,102,0,0,0,0,0,128,243,16,155,1,0,0,48,39,171,36,31,204,0,0,0,0,0,0,167,39,54,3,0,0,96,110,
222,39,89,154,1,0,0,0,0,0,78,75,108,6,0,0,192,28,125,74,121,86,19,0,0,0,0,0,56,17,177,25,0,0,0,115,212,165,4,103,157,41,0,0,0,0,0,224,52,196,102,0,0,0,204,85,159,228,214,12,0,0,0,0,0,112,26,98,51,0,0,
0,230,108,72,242,193,12,0,0,0,0,0,112,60,177,25,0,0,0,115,247,62,201,202,12,0,0,0,0,0,112,28,177,25,0,0,0,45,88,167,60,171,9,0,0,0,0,0,28,72,108,6,0,0,64,11,186,36,159,183,95,1,0,0,0,0,128,3,136,205,0,
0,0,104,69,23,193,25,0,0,0,0,0,28,76,108,6,0,0,64,75,250,36,183,102,0,0,0,0,0,128,253,137,205,0,0,0,104,205,144,100,109,6,0,0,0,0,0,216,143,216,12,0,0,128,22,13,219,15,0,0,0,0,0,176,35,177,25,0,0,0,173,
90,71,112,6,0,0,0,0,0,59,19,155,1,0,0,208,178,117,146,222,12,0,0,0,0,0,80,39,54,3,0,0,160,117,159,35,56,3,0,0,0,0,128,42,177,25,0,0,0,173,235,34,56,3,0,0,0,0,128,42,177,25,0,0,0,148,224,108,189,253,10,
0,0,0,0,0,252,128,216,12,0,0,0,138,62,229,194,89,103,10,0,0,0,0,0,248,55,177,25,0,0,0,252,173,143,224,12,0,0,0,0,0,126,72,108,6,0,0,0,255,212,71,112,6,0,0,0,0,0,255,34,54,3,0,0,128,127,235,147,172,205,
0,0,0,0,0,0,127,19,155,1,0,0,192,143,173,34,56,3,0,0,0,0,128,255,35,54,3,0,0,128,159,27,34,56,3,0,0,0,0,128,36,98,51,0,0,0,168,25,34,56,3,0,0,0,0,0,177,25,0,0,0,236,96,136,224,12,0,0,0,0,128,198,137,205,
0,0,0,96,55,67,4,103,0,0,0,0,0,52,76,108,6,0,0,0,187,27,34,56,3,0,0,0,0,160,81,98,51,0,0,0,216,207,144,228,175,36,157,41,0,0,0,0,0,104,137,216,12,0,0,0,246,215,39,249,28,193,25,0,0,0,0,0,13,17,155,1,0,
0,192,97,250,8,206,0,0,0,0,0,104,136,216,12,0,0,0,14,215,71,112,6,0,0,0,0,64,35,196,102,0,0,0,112,156,62,201,95,219,175,0,0,0,0,0,48,91,98,51,0,0,0,56,222,34,229,194,89,111,10,0,0,0,0,0,230,74,108,6,0,
0,0,167,209,165,4,103,43,83,0,0,0,0,0,48,71,98,51,0,0,0,56,157,46,201,167,36,131,41,0,0,0,0,0,152,27,177,25,0,0,0,156,222,58,201,7,51,0,0,0,0,0,48,39,98,51,0,0,0,56,143,247,41,209,25,0,0,0,0,0,204,130,
216,12,0,0,0,206,103,72,242,57,229,121,77,0,0,0,0,0,152,52,177,25,0,0,0,156,215,50,130,51,0,0,0,0,0,102,64,108,6,0,0,0,231,215,39,249,223,237,87,0,0,0,0,0,152,36,177,25,0,0,0,92,70,151,114,225,172,55,
5,0,0,0,0,0,83,36,54,3,0,0,128,203,233,146,252,149,100,48,5,0,0,0,0,0,83,35,54,3,0,0,128,203,91,39,121,107,6,0,0,0,0,0,166,68,108,6,0,0,0,215,113,155,18,157,1,0,0,0,0,192,36,136,205,0,0,0,224,122,134,
148,224,172,51,5,0,0,0,0,0,99,39,54,3,0,0,128,235,26,146,124,142,224,12,0,0,0,0,128,145,19,155,1,0,0,192,245,245,41,193,217,194,20,0,0,0,0,0,140,149,216,12,0,0,0,198,161,79,242,215,246,43,0,0,0,0,0,140,
142,216,12,0,0,0,198,163,75,185,112,182,52,5,0,0,0,0,0,99,35,54,3,0,0,128,113,233,82,130,179,193,20,0,0,0,0,0,140,137,216,12,0,0,0,198,105,157,228,173,25,0,0,0,0,0,24,11,177,25,0,0,0,140,215,109,74,116,
6,0,0,0,0,0,87,39,54,3,0,0,128,113,27,82,130,179,206,20,0,0,0,0,0,92,147,216,12,0,0,0,198,111,72,242,57,130,51,0,0,0,0,0,174,72,108,6,0,0,0,211,208,167,4,103,11,83,0,0,0,0,0,112,13,98,51,0,0,0,152,142,
62,201,95,219,175,0,0,0,0,0,112,81,98,51,0,0,0,152,150,46,229,194,217,210,20,0,0,0,0,0,92,146,216,12,0,0,0,166,167,75,9,206,6,83,0,0,0,0,0,112,41,98,51,0,0,0,152,174,117,4,103,0,0,0,0,0,92,136,216,12,
0,0,0,166,109,189,253,0,0,0,0,0,192,89,137,205,0,0,0,96,250,134,8,206,0,0,0,0,0,56,51,177,25,0,0,0,204,195,144,228,175,36,157,41,0,0,0,0,0,56,7,177,25,0,0,0,204,71,159,228,115,4,103,0,0,0,0,0,156,129,
216,12,0,0,0,230,165,79,185,112,214,155,2,0,0,0,0,128,83,18,155,1,0,0,192,252,44,82,46,156,245,166,0,0,0,0,0,224,84,196,102,0,0,0,48,79,93,74,112,182,50,5,0,0,0,0,0,167,32,54,3,0,0,128,249,234,146,124,
74,50,152,2,0,0,0,0,128,99,253,199,4,0,0,0,48,123,235,155,155,155,46,201,199,83,252,205,190,124,249,98,81,0,0,0,0,128,6,185,108,6,0,0,0,109,184,77,178,54,3,0,0,0,0,0,135,18,155,1,0,0,64,59,134,8,206,0,
0,0,0,0,56,144,216,12,0,0,0,218,50,36,249,43,73,103,10,0,0,0,0,0,246,33,54,3,0,0,128,246,244,73,62,71,112,6,0,0,0,0,192,30,196,102,0,0,0,208,166,62,37,56,235,77,1,0,0,0,0,192,46,196,102,0,0,0,208,174,
62,130,51,0,0,0,0,0,118,36,54,3,0,0,128,182,117,41,193,217,210,20,0,0,0,0,0,252,138,216,12,0,0,0,232,82,130,179,193,20,0,0,0,0,0,252,140,216,12,0,0,0,248,106,29,193,25,0,0,0,0,0,63,33,54,3,0,0,0,190,181,
78,114,107,6,0,0,0,0,0,190,39,54,3,0,0,0,190,247,54,37,58,3,0,0,0,0,128,255,35,54,3,0,0,0,126,100,72,9,206,58,83,0,0,0,0,0,144,136,205,0,0,0,128,159,27,146,124,142,224,12,0,0,0,0,128,136,205,0,0,0,128,
95,235,35,56,3,0,0,0,0,32,98,51,0,0,0,160,174,79,9,206,122,83,0,0,0,0,0,180,75,108,6,0,0,0,236,162,143,224,12,0,0,0,0,160,105,255,49,1,0,0,0,176,163,46,201,231,155,155,155,151,73,30,91,250,193,191,124,
249,226,79,31,0,0,0,0,104,158,203,102,0,0,0,192,62,186,148,11,103,131,41,0,0,0,0,0,218,34,54,3,0,0,0,246,213,37,89,71,112,6,0,0,0,0,208,20,177,25,0,0,0,112,40,193,25,0,0,0,0,64,67,196,102,0,0,0,192,49,
214,219,15,0,0,0,0,0,51,39,54,3,0,0,0,142,53,68,112,6,0,0,0,0,48,123,98,51,0,0,0,224,20,134,148,224,172,51,5,0,0,0,0,192,60,137,205,0,0,0,128,83,25,146,124,142,224,12,0,0,0,0,96,150,196,102,0,0,0,192,
41,245,17,156,1,0,0,0,0,204,146,216,12,0,0,0,56,181,62,37,56,91,152,2,0,0,0,0,96,62,196,102,0,0,0,192,57,244,73,254,218,126,5,0,0,0,0,96,6,196,102,0,0,0,192,185,116,41,23,206,122,83,0,0,0,0,0,76,159,216,
12,0,0,0,56,167,46,130,51,0,0,0,0,128,89,16,155,1,0,0,0,231,214,165,60,169,57,152,2,0,0,0,0,96,186,196,102,0,0,0,192,165,172,35,56,3,0,0,0,0,152,44,177,25,0,0,0,112,73,130,51,0,0,0,0,128,137,18,155,1,
0,0,0,151,182,78,114,107,6,0,0,0,0,128,105,17,155,1,0,0,0,215,240,54,37,58,3,0,0,0,0,96,34,196,102,0,0,0,192,181,12,17,156,1,0,0,0,0,76,134,216,12,0,0,0,184,166,33,201,167,36,157,41,0,0,0,0,0,198,77,108,
6,0,0,0,92,219,42,201,231,8,206,0,0,0,0,0,70,77,108,6,0,0,0,140,65,31,193,25,0,0,0,0,192,168,137,205,0,0,0,128,177,232,35,56,3,0,0,0,0,24,45,177,25,0,0,0,48,38,125,146,191,182,95,1,0,0,0,0,24,17,177,25,
0,0,0,48,54,139,148,11,103,189,41,0,0,0,0,0,198,67,108,6,0,0,0,140,81,23,193,25,0,0,0,0,192,168,136,205,0,0,0,128,177,234,34,56,3,0,0,0,0,24,13,177,25,0,0,0,48,102,93,146,191,146,12,166,0,0,0,0,0,184,
46,177,25,0,0,0,48,5,235,8,206,0,0,0,0,0,174,74,108,6,0,0,0,76,133,224,12,0,0,0,0,224,138,196,102,0,0,0,192,148,8,206,0,0,0,0,0,174,68,108,6,0,0,0,76,205,58,201,173,25,0,0,0,0,0,46,75,108,6,0,0,0,76,209,
219,148,232,12,0,0,0,0,128,11,17,155,1,0,0,0,83,53,68,112,6,0,0,0,0,112,49,98,51,0,0,0,96,202,134,8,206,0,0,0,0,0,46,66,108,6,0,0,0,76,221,144,18,156,117,166,0,0,0,0,0,56,31,177,25,0,0,0,48,7,67,146,207,
17,156,1,0,0,0,0,156,141,216,12,0,0,0,152,139,62,130,51,0,0,0,0,128,179,17,155,1,0,0,0,115,210,71,112,6,0,0,0,0,112,22,98,51,0,0,0,96,110,250,8,206,0,0,0,0,0,78,78,108,6,0,0,0,204,81,31,193,25,0,0,0,0,
192,73,137,205,0,0,0,128,185,234,147,252,239,246,43,0,0,0,0,0,71,18,155,1,0,0,0,115,214,165,92,56,235,77,1,0,0,0,0,112,28,177,25,0,0,0,48,119,93,4,103,0,0,0,0,0,71,19,155,1,0,0,0,45,232,34,56,3,0,0,0,
0,56,138,216,12,0,0,0,104,69,23,193,25,0,0,0,0,192,193,196,102,0,0,0,64,75,186,8,206,0,0,0,0,0,14,34,54,3,0,0,0,90,211,165,4,103,131,41,0,0,0,0,0,118,39,54,3,0,0,0,90,212,37,89,71,112,6,0,0,0,0,176,51,
177,25,0,0,0,208,50,193,25,0,0,0,0,192,142,196,102,0,0,0,64,235,4,103,0,0,0,0,0,59,16,155,1,0,0,0,8,206,0,0,0,0,0,170,196,102,0,0,0,0,133,224,12,0,0,0,0,224,23,196,102,0,0,0,0,127,19,156,1,0,0,0,0,252,
132,216,12,0,0,0,224,159,4,103,0,0,0,0,0,63,32,54,3,0,0,0,248,183,117,146,91,51,0,0,0,0,0,252,77,108,6,0,0,48,111,31,77,0,7,123,155,18,157,1,0,0,0,0,16,177,25,0,0,192,220,189,75,242,44,201,131,41,224,
32,67,4,103,0,0,0,0,0,73,146,255,152,0,0,0,96,214,22,73,158,146,188,76,178,76,137,102,22,102,129,189,12,55,55,55,73,242,218,20,243,242,229,203,23,35,0,0,0,0,192,30,92,54,3,0,0,152,183,197,55,127,253,144,
114,229,236,93,146,141,105,96,47,67,92,56,3,0,0,0,0,26,39,54,3,0,0,104,207,199,148,232,236,163,41,96,47,67,4,103,0,0,0,0,64,195,196,102,0,0,0,109,218,164,92,56,123,158,114,241,12,216,205,16,193,25,0,0,
0,0,208,40,177,25,0,0,64,219,30,147,188,76,242,42,201,147,57,96,39,67,4,103,0,0,0,0,64,131,196,102,0,0,0,36,201,125,202,211,154,127,166,92,61,3,126,109,136,224,12,0,0,0,0,104,140,216,12,0,0,96,222,150,
123,254,239,63,164,68,103,119,166,131,170,33,130,51,0,0,0,0,160,33,98,51,0,0,0,190,183,73,242,58,229,121,205,7,115,192,47,13,17,156,1,0,0,0,0,141,16,155,1,0,0,240,51,15,41,193,217,235,36,79,230,128,159,
26,34,56,3,0,0,0,0,26,32,54,3,0,0,160,230,46,201,243,36,127,154,2,126,106,136,224,12,0,0,0,0,152,57,177,25,0,0,192,188,253,118,162,191,207,38,201,135,36,207,146,220,155,21,126,104,136,224,12,0,0,0,0,152,
49,177,25,0,0,192,188,117,39,254,251,61,37,121,149,242,188,230,147,121,225,95,134,8,206,0,0,0,0,128,153,18,155,1,0,0,112,136,135,148,43,103,239,82,174,158,1,127,27,34,56,3,0,0,0,0,102,72,108,6,0,0,48,
111,221,153,255,254,31,83,162,179,59,83,195,63,12,17,156,1,0,0,0,0,51,35,54,3,0,0,152,183,254,2,255,140,77,146,215,73,158,167,92,60,3,138,33,130,51,0,0,0,0,96,70,196,102,0,0,0,156,202,99,146,151,41,225,
217,198,28,144,68,112,6,0,0,0,0,204,136,216,12,0,0,96,254,186,11,255,243,238,82,158,214,252,211,244,144,68,112,6,0,0,0,0,204,132,216,12,0,0,96,254,250,43,252,51,55,73,62,164,68,103,15,254,8,64,112,6,0,
0,0,0,76,159,216,12,0,0,128,115,122,74,121,90,243,213,246,175,161,101,67,4,103,0,0,0,0,192,132,137,205,0,0,0,230,111,49,130,239,225,62,201,243,148,167,53,55,254,72,104,216,16,193,25,0,0,0,0,48,81,98,51,
0,0,128,249,91,140,228,251,216,164,60,173,249,60,37,62,131,86,13,17,156,1,0,0,0,0,19,36,54,3,0,0,224,210,158,82,158,213,124,25,79,107,210,174,33,130,51,0,0,0,0,96,98,196,102,0,0,0,243,247,98,164,223,215,
67,146,103,241,180,38,237,26,34,56,3,0,0,0,0,38,68,108,6,0,0,192,181,125,136,167,53,105,215,16,193,25,0,0,0,0,48,17,98,51,0,0,128,249,91,76,224,123,124,138,167,53,105,215,16,193,25,0,0,0,0,48,1,98,51,
0,0,128,249,91,76,232,123,125,136,167,53,105,211,16,193,25,0,0,0,0,48,114,98,51,0,0,128,54,116,19,251,126,63,196,211,154,180,103,136,224,12,0,0,0,0,24,49,177,25,0,0,64,27,250,9,126,207,79,241,180,38,237,
25,34,56,3,0,0,0,0,70,74,108,6,0,0,208,134,110,194,223,251,67,60,173,73,91,134,8,206,0,0,0,0,128,17,18,155,1,0,0,180,161,159,193,207,240,33,158,214,164,29,67,4,103,0,0,0,0,192,200,136,205,0,0,0,218,240,
223,153,252,28,79,241,180,38,237,24,34,56,3,0,0,0,0,70,68,108,6,0,0,208,134,126,102,63,207,67,60,173,73,27,134,8,206,0,0,0,0,128,145,16,155,1,0,0,180,161,155,233,207,245,33,229,105,205,7,127,196,204,216,
176,253,255,58,0,0,0,0,192,85,137,205,0,0,0,218,208,207,248,103,123,74,121,86,243,85,60,173,201,124,189,79,137,206,0,0,0,0,0,174,70,108,6,0,0,208,142,197,204,127,190,251,148,43,103,127,250,163,102,166,
214,17,156,1,0,0,0,0,87,36,54,3,0,0,104,199,162,129,159,113,19,79,107,50,111,130,51,0,0,0,0,224,106,196,102,0,0,0,237,232,27,250,89,31,83,158,214,124,157,18,160,193,156,8,206,0,0,0,0,128,171,16,155,1,
0,0,180,163,107,240,103,190,75,242,108,251,21,230,68,112,6,0,0,0,0,92,156,216,12,0,0,160,29,47,26,253,185,55,41,23,206,94,166,92,60,131,185,16,156,1,0,0,0,0,23,37,54,3,0,0,104,71,215,248,207,255,144,228,
121,146,63,227,105,77,230,99,157,100,101,6,0,0,0,0,224,18,196,102,0,0,0,237,232,77,144,36,249,144,18,157,221,155,130,153,88,251,247,27,0,0,0,0,184,4,177,25,0,0,64,91,122,19,36,73,158,146,188,218,126,158,
204,193,196,117,73,62,251,247,27,0,0,0,0,56,55,177,25,0,0,64,91,22,38,248,135,251,148,43,103,31,77,193,196,117,17,156,1,0,0,0,0,103,38,54,3,0,0,104,75,111,130,127,217,36,121,151,18,157,61,154,131,9,235,
34,56,3,0,0,0,0,206,72,108,6,0,0,208,150,223,76,240,83,143,41,193,217,187,148,0,13,166,168,139,224,12,0,0,0,0,56,19,177,25,0,0,64,91,22,38,168,250,152,18,157,221,155,130,137,234,82,130,179,206,20,0,0,
0,0,192,41,137,205,0,0,0,218,210,155,96,39,79,73,94,109,63,79,230,96,130,186,8,206,0,0,0,0,128,19,19,155,1,0,0,180,167,55,193,206,238,83,174,156,125,52,5,19,253,119,93,112,6,0,0,0,0,156,140,216,12,0,0,
160,61,11,19,236,101,147,228,93,74,116,246,104,14,38,166,143,224,12,0,0,0,0,56,17,177,25,0,0,64,123,122,19,28,228,49,37,56,251,51,37,64,131,41,253,59,47,56,3,0,0,0,0,142,38,54,3,0,0,104,207,11,19,28,229,
67,74,116,246,96,10,38,164,79,114,107,6,0,0,0,0,224,24,98,51,0,0,128,246,244,38,56,218,83,146,151,73,94,199,149,51,166,99,72,178,54,3,0,0,0,0,112,40,177,25,0,0,64,123,186,120,78,239,84,238,146,60,75,114,
111,10,38,98,136,224,12,0,0,0,0,56,144,216,12,0,0,160,77,189,9,78,102,147,228,85,202,165,179,39,115,48,1,67,4,103,0,0,0,0,192,1,196,102,0,0,0,109,90,154,224,228,30,146,60,79,242,209,20,76,192,144,228,
173,25,0,0,0,0,128,125,136,205,0,0,0,218,244,155,9,206,98,147,228,93,74,116,246,104,14,70,238,54,37,58,3,0,0,0,0,216,137,216,12,0,0,160,77,189,9,206,234,49,37,56,251,211,20,140,220,58,130,51,0,0,0,0,96,
71,98,51,0,0,128,54,45,146,116,102,56,187,15,41,209,217,131,41,24,177,117,146,149,25,0,0,0,0,128,26,177,25,0,0,64,187,122,19,92,196,99,146,151,41,207,107,110,204,193,72,173,253,78,0,0,0,0,0,106,196,102,
0,0,0,237,90,154,224,162,62,198,149,51,198,171,75,242,57,130,51,0,0,0,0,224,23,196,102,0,0,0,237,250,205,4,23,247,148,114,229,236,117,92,57,99,124,186,8,206,0,0,0,0,128,95,16,155,1,0,0,180,107,105,130,
171,185,75,242,44,201,189,41,24,153,46,229,73,205,206,20,0,0,0,0,192,247,196,102,0,0,0,237,234,146,44,204,112,53,155,36,175,182,159,141,57,24,145,62,229,194,89,103,10,0,0,0,0,224,91,98,51,0,0,128,182,
245,38,184,186,251,184,114,198,56,127,55,8,206,0,0,0,0,128,127,16,155,1,0,0,180,237,133,9,70,97,19,87,206,24,159,62,229,73,77,0,0,0,0,128,36,98,51,0,0,128,214,45,77,48,42,247,41,87,206,238,76,193,72,172,
34,56,3,0,0,0,0,182,196,102,0,0,0,109,235,77,48,58,155,36,175,147,188,76,242,100,14,70,96,136,224,12,0,0,0,0,136,216,12,0,0,0,215,205,198,234,33,201,243,36,31,77,193,8,12,219,15,0,0,0,0,208,48,177,25,
0,0,0,75,19,140,214,38,201,187,184,114,198,56,172,35,56,3,0,0,0,128,166,137,205,0,0,0,120,97,130,209,123,136,43,103,140,195,58,201,202,12,0,0,0,0,208,38,177,25,0,0,0,189,9,38,97,19,87,206,24,135,181,223,
27,0,0,0,0,208,38,177,25,0,0,0,93,132,35,83,242,16,87,206,184,254,239,140,207,126,111,0,0,0,0,64,123,196,102,0,0,0,36,201,210,4,147,178,73,185,114,246,106,251,215,112,105,93,146,79,219,175,0,0,0,0,64,
35,196,102,0,0,0,36,201,11,19,76,210,125,146,103,219,175,112,105,139,148,11,103,157,41,0,0,0,0,160,13,98,51,0,0,0,18,151,205,166,108,147,114,225,204,149,51,174,161,79,9,206,0,0,0,0,128,6,136,205,0,0,0,
72,202,101,162,222,12,147,118,31,87,206,184,142,62,201,218,12,0,0,0,0,48,127,98,51,0,0,0,190,90,154,96,242,54,113,229,140,235,24,34,56,3,0,0,0,128,217,19,155,1,0,0,240,213,11,19,204,198,125,202,149,179,
7,83,112,65,195,246,3,0,0,0,0,204,148,216,12,0,0,128,175,150,38,152,149,77,146,151,73,222,197,149,51,46,103,29,193,25,0,0,0,0,204,150,216,12,0,0,128,175,186,36,189,25,102,231,99,146,231,113,229,140,203,
89,251,93,2,0,0,0,0,243,36,54,3,0,0,224,91,43,19,204,210,83,202,149,179,63,77,193,133,124,142,224,12,0,0,0,0,102,71,108,6,0,0,192,183,94,152,96,214,62,164,92,57,123,52,5,103,214,165,4,103,157,41,0,0,0,
0,96,62,196,102,0,0,0,124,107,105,130,217,123,76,9,206,92,57,227,220,186,8,206,0,0,0,0,96,86,196,102,0,0,0,124,111,101,130,38,124,72,121,90,243,201,20,156,81,159,228,147,25,0,0,0,0,96,30,196,102,0,0,0,
124,207,83,154,237,120,72,185,114,118,103,10,206,104,153,100,109,6,0,0,0,0,152,62,177,25,0,0,0,223,91,153,160,41,155,36,175,147,188,218,254,53,156,195,144,114,77,15,0,0,0,0,152,48,177,25,0,0,0,223,91,
108,63,180,229,62,201,179,148,107,103,112,14,239,83,162,51,0,0,0,0,96,162,196,102,0,0,0,252,200,210,4,77,218,36,121,153,228,93,92,57,227,60,214,73,122,51,0,0,0,0,192,52,137,205,0,0,0,248,145,223,77,208,
180,143,41,209,217,163,41,56,131,207,17,156,1,0,0,0,192,36,137,205,0,0,0,248,145,149,9,154,247,152,228,121,74,120,6,167,212,37,249,180,253,10,0,0,0,0,76,136,216,12,0,0,128,159,89,153,128,148,39,53,95,
198,179,154,156,214,34,229,194,89,103,10,0,0,0,0,152,14,177,25,0,0,0,63,243,194,4,108,61,36,121,150,228,222,20,156,80,159,228,214,12,0,0,0,0,48,29,98,51,0,0,0,126,102,101,2,190,177,73,242,42,229,210,217,
198,28,156,200,16,193,25,0,0,0,0,76,134,216,12,0,0,128,159,89,164,92,30,130,111,125,76,121,86,243,209,20,156,200,219,148,232,12,0,0,0,0,24,57,177,25,0,0,0,191,178,52,1,63,240,152,228,121,74,120,6,167,
176,246,251,6,0,0,0,0,198,79,108,6,0,0,192,175,252,97,2,126,225,93,202,149,179,141,41,56,129,79,113,77,17,0,0,0,0,70,77,108,6,0,0,192,175,244,73,58,51,240,11,15,73,158,109,191,194,49,186,148,224,204,239,
28,0,0,0,0,24,41,177,25,0,0,0,53,43,19,80,177,73,185,112,246,206,20,28,105,145,228,179,25,0,0,0,0,96,156,196,102,0,0,0,212,252,110,2,118,244,49,201,243,36,79,166,224,8,125,146,181,25,0,0,0,0,96,124,196,
102,0,0,0,212,172,226,89,59,118,247,152,18,156,221,153,130,35,12,73,222,154,1,0,0,0,0,198,69,108,6,0,0,192,46,150,38,96,15,155,36,175,183,159,141,57,56,208,109,74,116,6,0,0,0,0,140,132,216,12,0,0,128,
93,120,74,147,67,220,37,121,153,114,237,12,14,113,155,242,172,38,0,0,0,0,48,2,98,51,0,0,0,118,177,50,1,7,122,76,121,86,243,163,41,56,64,151,228,115,60,229,11,0,0,0,0,163,32,54,3,0,0,96,23,93,4,103,28,
231,93,146,87,241,172,38,135,253,254,17,156,1,0,0,0,192,8,136,205,0,0,0,216,149,167,52,57,214,125,202,149,179,71,83,176,167,62,229,73,77,0,0,0,0,224,138,196,102,0,0,0,236,106,101,2,78,224,41,158,213,228,
48,67,146,183,102,0,0,0,0,128,235,17,155,1,0,0,176,171,46,130,51,78,199,179,154,28,226,214,239,33,0,0,0,0,184,30,177,25,0,0,0,251,240,148,38,167,116,31,207,106,178,191,117,202,179,154,0,0,0,0,192,133,
137,205,0,0,0,216,199,202,4,156,216,83,60,171,201,126,186,36,159,182,95,1,0,0,0,128,11,18,155,1,0,0,176,143,46,130,51,206,195,179,154,236,99,145,18,156,1,0,0,0,0,23,36,54,3,0,0,96,95,158,210,228,92,238,
227,89,77,118,183,76,114,107,6,0,0,0,0,184,28,177,25,0,0,0,251,90,153,128,51,122,74,9,206,238,76,193,14,222,38,25,204,0,0,0,0,0,151,33,54,3,0,0,96,95,93,196,29,156,223,235,237,103,99,10,42,214,73,122,
51,0,0,0,0,192,249,137,205,0,0,0,56,132,167,52,185,132,187,36,47,227,89,77,234,62,167,132,176,0,0,0,0,192,25,137,205,0,0,0,56,196,42,194,14,46,227,49,37,56,187,51,5,191,208,165,4,103,0,0,0,0,192,25,137,
205,0,0,0,56,212,202,4,92,200,38,229,73,205,119,166,224,23,250,148,39,53,1,0,0,0,128,51,17,155,1,0,0,112,168,55,38,224,194,62,38,121,158,18,159,193,143,12,219,15,0,0,0,0,112,6,98,51,0,0,0,14,213,39,89,
152,129,11,123,76,242,44,201,131,41,248,137,245,246,247,19,0,0,0,0,112,98,98,51,0,0,0,142,177,50,1,87,176,73,242,50,229,210,25,252,200,231,36,157,25,0,0,0,0,224,180,196,102,0,0,0,28,195,83,154,92,211,
187,36,175,226,89,77,254,173,75,9,206,0,0,0,0,128,19,18,155,1,0,0,112,140,69,60,87,199,117,221,167,92,57,123,52,5,223,233,83,158,212,4,0,0,0,0,78,68,108,6,0,0,192,177,92,55,227,218,30,83,130,179,123,83,
240,157,97,251,1,0,0,0,0,78,64,108,6,0,0,192,177,86,38,96,4,54,41,79,106,254,105,10,190,179,142,11,140,0,0,0,0,112,18,98,51,0,0,0,142,213,197,229,32,198,227,67,202,149,179,141,41,248,198,167,237,239,42,
0,0,0,0,224,8,98,51,0,0,0,78,225,119,19,48,34,15,73,158,167,60,175,9,73,178,72,9,206,0,0,0,0,128,35,136,205,0,0,0,56,133,85,74,204,1,99,241,148,114,225,236,206,20,108,45,147,220,154,1,0,0,0,0,14,39,54,
3,0,0,224,84,6,19,48,50,155,36,175,147,188,51,5,91,111,83,226,88,0,0,0,0,224,0,98,51,0,0,0,78,229,15,19,48,82,31,147,188,74,137,207,96,157,164,55,3,0,0,0,0,236,79,108,6,0,0,192,169,44,82,158,169,131,49,
186,79,121,86,243,209,20,205,235,82,130,179,206,20,0,0,0,0,176,31,177,25,0,0,0,167,228,186,25,99,246,152,18,156,221,155,162,121,125,146,91,51,0,0,0,0,192,126,196,102,0,0,0,156,210,16,215,130,24,183,77,
202,147,154,31,77,225,247,213,205,205,205,112,115,115,147,57,126,0,0,0,0,224,28,196,102,0,0,0,156,218,96,2,38,224,93,146,215,41,241,25,237,186,77,185,114,6,0,0,0,0,236,64,108,6,0,0,192,169,189,49,1,19,
113,151,242,172,230,198,20,205,234,146,124,138,139,140,0,0,0,0,176,19,177,25,0,0,0,167,182,72,178,52,3,19,241,152,228,217,246,43,237,254,206,90,155,1,0,0,0,0,234,196,102,0,0,0,156,195,31,38,96,66,54,41,
23,206,238,76,209,172,85,146,183,102,0,0,0,0,128,95,19,155,1,0,0,112,14,67,60,75,199,180,108,146,188,78,242,167,41,154,117,155,164,55,3,0,0,0,0,252,156,216,12,0,0,128,115,25,76,192,4,125,72,137,206,54,
166,104,210,167,8,101,1,0,0,0,224,167,196,102,0,0,0,156,203,27,19,48,81,119,41,207,106,110,76,209,156,69,146,181,25,0,0,0,0,224,199,196,102,0,0,0,156,203,34,201,202,12,76,212,99,146,103,219,175,180,101,
149,228,173,25,0,0,0,0,224,223,196,102,0,0,0,156,211,31,38,96,194,54,41,23,206,238,76,209,156,247,73,122,51,0,0,0,0,192,63,137,205,0,0,0,56,167,85,202,133,51,152,170,77,146,215,73,62,154,162,41,93,202,
115,154,157,41,0,0,0,0,224,111,98,51,0,0,0,206,237,141,9,152,129,119,41,209,25,237,232,147,220,154,1,0,0,0,0,254,38,54,3,0,0,224,220,134,184,14,196,60,220,165,60,171,185,49,69,83,191,191,86,102,0,0,0,
0,128,66,108,6,0,0,192,185,117,17,107,48,31,15,41,193,217,147,41,154,177,142,231,128,1,0,0,0,32,137,216,12,0,0,128,203,120,111,2,102,228,49,201,243,237,87,230,175,75,242,201,12,0,0,0,0,32,54,3,0,0,224,
50,22,73,150,102,96,70,54,41,23,206,238,76,209,132,62,201,7,51,0,0,0,0,208,58,177,25,0,0,0,151,242,198,4,204,204,38,201,235,8,206,90,241,62,162,89,0,0,0,0,26,39,54,3,0,0,224,82,86,41,23,206,96,110,94,
111,63,204,223,58,229,89,77,0,0,0,0,104,146,216,12,0,0,128,75,122,111,2,102,234,46,37,56,219,152,98,214,22,41,193,25,0,0,0,0,52,73,108,6,0,0,192,37,173,226,42,16,243,117,151,228,101,4,103,45,252,30,27,
204,0,0,0,0,64,139,196,102,0,0,0,92,82,151,228,173,25,152,177,199,148,224,236,201,20,179,118,27,207,2,3,0,0,0,208,32,177,25,0,0,0,151,246,135,9,152,185,199,36,207,183,95,153,167,46,201,39,51,0,0,0,0,208,
26,177,25,0,0,0,151,182,136,39,232,152,191,77,202,133,179,7,83,204,86,159,228,131,25,0,0,0,0,104,137,216,12,0,0,128,107,120,111,2,26,176,73,9,206,238,76,49,235,223,101,189,25,0,0,0,0,104,133,216,12,0,
0,128,107,88,36,89,154,129,70,188,142,224,108,206,62,165,60,171,9,0,0,0,0,179,39,54,3,0,0,224,90,92,55,163,37,175,183,31,230,103,225,247,25,0,0,0,0,173,16,155,1,0,0,112,45,203,120,126,142,182,220,69,112,
54,87,111,227,90,35,0,0,0,0,13,16,155,1,0,0,112,77,111,76,64,99,238,146,188,74,178,49,197,236,120,78,19,0,0,0,128,217,19,155,1,0,0,112,77,67,202,19,116,208,146,251,36,47,35,56,155,155,46,201,218,12,0,
0,0,0,204,153,216,12,0,0,128,107,123,111,2,26,244,24,193,217,28,173,182,31,0,0,0,0,152,37,177,25,0,0,0,215,54,196,211,115,180,233,49,201,243,237,87,230,99,237,119,26,0,0,0,0,115,37,54,3,0,0,96,12,222,
154,128,70,61,165,92,56,123,52,197,108,116,241,156,38,0,0,0,0,51,37,54,3,0,0,96,12,222,196,37,32,218,181,137,224,108,110,86,241,156,38,0,0,0,0,51,36,54,3,0,0,96,12,186,184,110,70,219,54,41,193,217,131,
41,102,195,115,154,0,0,0,0,204,142,216,12,0,0,128,177,112,221,140,214,109,82,130,179,59,83,204,66,23,207,105,2,0,0,0,48,51,98,51,0,0,0,198,162,139,235,102,144,36,175,35,56,155,139,85,60,167,9,0,0,0,192,
140,136,205,0,0,0,24,147,55,38,128,36,130,179,57,241,156,38,0,0,0,0,179,33,54,3,0,0,96,76,186,36,131,25,32,137,224,108,78,191,215,60,167,9,252,127,246,238,246,184,141,236,218,26,240,82,213,253,239,206,
192,80,4,134,34,24,40,130,151,138,96,192,8,70,140,64,100,4,162,35,32,28,129,232,8,4,69,224,158,8,12,103,208,142,96,222,31,135,99,141,70,164,248,1,244,199,233,126,158,42,20,93,101,151,167,207,58,64,187,
238,173,85,123,3,0,0,192,44,40,155,1,0,0,48,53,31,68,0,255,115,158,228,66,12,213,59,139,117,154,0,0,0,0,204,128,178,25,0,0,0,83,179,138,233,102,240,71,215,41,165,51,234,102,157,38,0,0,0,0,213,83,54,3,
0,0,96,138,76,55,131,111,237,162,112,86,187,38,214,105,2,0,0,0,80,57,101,51,0,0,0,166,104,21,211,205,224,207,118,81,56,171,221,89,172,211,4,0,0,0,160,98,202,102,0,0,0,76,149,233,102,240,189,93,20,206,
106,103,157,38,0,0,0,0,213,82,54,3,0,0,96,170,86,49,221,12,238,179,139,194,89,205,154,40,211,2,0,0,0,80,41,101,51,0,0,0,166,76,33,3,238,183,139,194,89,205,222,39,217,136,1,0,0,0,128,218,40,155,1,0,0,48,
101,171,152,110,6,15,217,69,225,172,102,55,34,0,0,0,0,160,54,202,102,0,0,0,76,221,199,148,181,115,192,247,118,81,56,171,213,42,201,165,24,0,0,0,0,168,137,178,25,0,0,0,83,215,164,172,156,3,238,183,139,
194,89,173,62,36,89,139,1,0,0,0,128,90,40,155,1,0,0,80,131,95,98,186,25,252,200,46,10,103,181,250,40,2,0,0,0,0,106,161,108,6,0,0,64,13,154,152,110,6,143,217,69,225,172,70,27,239,55,0,0,0,0,106,161,108,
6,0,0,64,45,76,55,131,199,237,162,112,86,163,15,222,111,0,0,0,0,212,64,217,12,0,0,128,90,52,49,253,7,158,98,23,133,179,26,223,111,55,98,0,0,0,0,96,234,148,205,0,0,0,168,201,47,73,86,98,128,71,237,162,
112,86,155,179,148,149,154,0,0,0,0,48,89,202,102,0,0,0,212,164,73,89,55,7,60,110,23,133,179,218,220,196,58,77,0,0,0,0,38,76,217,12,0,0,128,218,108,99,186,25,60,213,46,10,103,53,89,197,186,96,0,0,0,0,38,
76,217,12,0,0,128,26,153,110,6,79,183,139,194,89,109,239,183,149,24,0,0,0,0,152,34,101,51,0,0,0,106,180,77,178,17,3,60,217,238,238,67,29,110,68,0,0,0,0,192,20,41,155,1,0,0,80,43,211,205,224,121,206,163,
112,86,139,77,74,169,22,0,0,0,0,38,69,217,12,0,0,128,90,109,98,186,25,60,151,194,89,61,62,38,105,196,0,0,0,0,192,148,40,155,1,0,0,80,51,171,230,224,249,20,206,234,208,196,4,71,0,0,0,0,38,70,217,12,0,0,
128,154,173,98,213,28,188,196,121,146,91,49,76,222,251,36,107,49,0,0,0,0,48,21,202,102,0,0,0,212,238,67,172,154,131,151,56,79,210,138,97,242,62,138,0,0,0,0,128,169,80,54,3,0,0,160,118,171,148,233,63,192,
243,116,73,222,70,225,108,234,54,49,193,17,0,0,0,128,137,80,54,3,0,0,96,14,126,137,233,102,240,18,93,20,206,106,240,209,59,14,0,0,0,128,41,80,54,3,0,0,96,14,154,88,53,7,47,213,165,172,212,236,68,49,233,
119,220,123,49,0,0,0,0,48,54,101,51,0,0,0,230,98,155,178,82,19,120,190,54,101,194,89,39,138,201,250,224,29,7,0,0,0,192,216,148,205,0,0,0,152,147,27,17,192,139,181,81,56,243,142,3,0,0,0,128,31,80,54,3,
0,0,96,78,54,119,31,224,101,218,36,23,98,240,142,3,0,0,0,128,251,40,155,1,0,0,48,55,38,255,192,113,118,73,206,197,224,29,7,0,0,0,0,127,166,108,6,0,0,192,220,172,146,188,23,3,28,101,151,228,74,12,147,125,
199,93,138,1,0,0,0,128,49,40,155,1,0,0,48,71,31,146,52,98,128,163,92,166,148,206,152,158,95,188,227,0,0,0,0,24,131,178,25,0,0,0,115,212,164,20,206,128,227,156,39,217,139,97,146,239,184,143,98,0,0,0,0,
96,104,202,102,0,0,0,204,213,251,36,107,49,192,209,222,37,105,197,48,57,91,239,56,0,0,0,0,134,166,108,6,0,0,192,156,153,252,3,199,235,146,188,77,114,16,133,119,28,0,0,0,0,203,166,108,6,0,0,192,156,109,
146,156,137,1,142,214,165,76,56,235,68,225,29,7,0,0,0,192,114,41,155,1,0,0,48,119,31,147,52,98,128,163,181,41,133,51,166,247,142,3,0,0,0,128,65,40,155,1,0,0,48,119,171,36,239,197,0,39,177,79,114,46,6,
239,56,0,0,0,0,150,73,217,12,0,0,128,37,248,144,82,200,0,142,183,75,114,45,134,201,189,227,26,49,0,0,0,0,208,55,101,51,0,0,0,150,226,70,4,112,50,23,41,165,51,166,161,137,233,102,0,0,0,0,12,64,217,12,0,
0,128,165,216,220,125,128,211,184,72,210,138,97,50,76,112,4,0,0,0,160,119,202,102,0,0,0,44,201,77,172,154,131,83,233,146,188,189,251,203,52,124,16,1,0,0,0,0,125,82,54,3,0,0,96,73,86,177,106,14,78,169,
139,194,217,148,108,99,130,35,0,0,0,0,61,82,54,3,0,0,96,105,172,154,131,211,106,83,86,106,50,157,119,28,0,0,0,0,244,66,217,12,0,0,128,37,186,17,1,156,212,46,201,149,24,38,97,19,211,205,0,0,0,0,232,137,
178,25,0,0,0,75,180,73,114,38,6,56,169,203,148,210,25,227,187,121,245,234,85,126,255,0,0,0,0,192,169,40,155,1,0,0,176,84,55,73,26,49,192,73,93,164,172,213,100,92,171,36,91,49,0,0,0,0,112,106,202,102,0,
0,0,44,85,147,228,131,24,224,164,186,36,239,238,254,50,46,239,55,0,0,0,0,78,78,217,12,0,0,128,37,123,159,100,45,6,56,169,67,74,225,140,113,173,82,86,155,2,0,0,0,192,201,40,155,1,0,0,176,116,55,34,128,
147,219,167,172,212,100,92,191,196,186,96,0,0,0,0,78,72,217,12,0,0,128,165,91,167,76,56,3,78,235,58,201,78,12,163,106,188,223,0,0,0,0,56,165,87,191,253,246,155,20,0,0,0,30,251,63,158,94,189,186,76,242,
65,18,179,213,37,121,147,178,254,15,56,157,38,201,231,88,87,59,246,251,237,245,221,223,69,240,255,239,4,0,0,0,232,143,201,102,0,0,0,80,10,49,214,105,194,233,117,73,222,101,65,69,167,137,190,223,222,139,
1,0,0,0,128,83,80,54,3,0,0,128,98,147,228,76,12,112,114,135,148,194,25,227,249,144,100,37,6,0,0,0,0,142,165,108,6,0,0,0,95,221,164,76,1,2,78,107,159,228,66,12,163,178,10,26,0,0,0,128,163,41,155,1,0,0,
192,87,77,146,143,98,128,94,92,39,217,137,97,52,219,152,110,6,0,0,0,192,145,148,205,0,0,0,224,91,219,148,149,154,192,233,93,36,105,197,48,26,211,205,0,0,0,0,56,138,178,25,0,0,0,124,207,58,77,232,71,151,
228,221,221,95,134,183,141,233,102,0,0,0,0,28,65,217,12,0,0,0,190,183,138,9,64,208,151,67,74,225,140,113,120,183,1,0,0,0,240,98,202,102,0,0,0,112,191,247,177,78,19,250,178,79,89,169,201,240,182,49,221,
12,0,0,0,128,23,82,54,3,0,0,128,135,125,20,1,244,230,58,201,173,24,70,97,186,25,0,0,0,0,47,162,108,6,0,0,0,15,91,39,185,20,3,244,230,60,73,43,134,193,109,99,186,25,0,0,0,0,47,160,108,6,0,0,0,63,246,33,
165,116,6,156,94,151,82,56,235,68,49,202,187,13,0,0,0,0,158,69,217,12,0,0,0,30,119,35,2,232,77,155,82,56,99,88,219,152,110,6,0,0,0,192,51,41,155,1,0,0,192,227,214,177,78,19,250,116,155,228,90,12,131,51,
221,12,0,0,0,128,103,81,54,3,0,0,128,167,177,78,19,250,117,145,100,47,134,65,109,99,186,25,0,0,0,0,207,160,108,6,0,0,0,79,103,157,38,244,235,93,146,78,12,131,50,221,12,0,0,0,128,39,83,54,3,0,0,128,167,
91,199,58,77,232,83,151,228,173,24,6,181,141,233,102,0,0,0,0,60,145,178,25,0,0,0,60,207,135,36,27,49,64,111,218,148,149,154,12,251,94,3,0,0,0,128,71,41,155,1,0,0,192,243,221,36,105,196,0,189,185,78,114,
43,134,193,108,99,186,25,0,0,0,0,79,160,108,6,0,0,0,207,183,138,73,64,208,183,243,148,41,103,12,195,59,13,0,0,0,128,71,41,155,1,0,0,192,203,188,143,117,154,208,167,46,165,112,214,137,98,16,219,152,216,
8,0,0,0,192,35,148,205,0,0,0,224,229,172,211,132,126,181,73,46,196,48,152,247,34,0,0,0,0,224,71,148,205,0,0,0,224,229,86,41,133,51,160,63,187,187,15,253,251,37,10,180,0,0,0,0,252,128,178,25,0,0,0,28,231,
236,238,3,244,231,34,101,202,25,253,106,98,186,25,0,0,0,0,63,160,108,6,0,0,0,199,187,73,153,114,6,244,163,75,114,126,247,151,126,153,110,6,0,0,0,192,131,148,205,0,0,0,224,120,77,172,211,132,190,181,41,
133,51,250,127,159,157,137,1,0,0,0,128,251,40,155,1,0,0,192,105,108,98,253,28,244,237,54,201,181,24,122,247,65,4,0,0,0,0,220,71,217,12,0,0,0,78,231,99,146,181,24,160,87,23,41,83,206,232,207,42,201,86,
12,0,0,0,0,252,153,178,25,0,0,0,156,214,77,202,26,58,160,63,239,146,116,98,232,213,47,34,0,0,0,0,224,207,148,205,0,0,0,224,180,214,177,130,14,250,118,72,114,46,134,222,223,101,27,49,0,0,0,0,240,71,202,
102,0,0,0,112,122,239,147,156,137,1,122,117,155,100,39,134,94,41,206,2,0,0,0,240,13,101,51,0,0,0,232,199,77,146,149,24,160,87,23,73,90,49,244,102,227,61,6,0,0,0,192,31,41,155,1,0,0,64,63,154,148,194,25,
208,159,46,101,157,102,39,138,222,152,110,6,0,0,0,192,255,40,155,1,0,0,64,127,54,73,46,197,0,189,106,83,38,156,209,143,109,76,55,3,0,0,0,224,142,178,25,0,0,0,244,235,67,74,233,12,232,207,238,238,67,63,
182,34,0,0,0,0,32,81,54,3,0,0,128,33,220,164,172,213,4,250,115,145,228,32,134,94,252,226,29,6,0,0,0,64,162,108,6,0,0,0,67,88,165,20,206,128,254,116,73,222,137,161,23,77,146,51,49,0,0,0,0,160,108,6,0,0,
0,195,56,75,242,94,12,208,171,54,101,194,25,167,247,65,4,0,0,0,0,40,155,1,0,0,192,112,62,38,89,139,1,122,117,157,100,47,134,147,91,37,217,136,1,0,0,0,96,217,148,205,0,0,0,96,88,159,82,86,210,1,253,121,
151,178,86,147,211,50,221,12,0,0,0,96,225,148,205,0,0,0,96,88,171,36,55,98,128,94,117,73,206,197,112,114,155,187,119,24,0,0,0,0,11,165,108,6,0,0,0,195,59,75,242,94,12,208,171,219,148,149,154,156,150,233,
102,0,0,0,0,11,166,108,6,0,0,0,227,248,152,100,45,6,232,213,69,146,86,12,39,117,22,171,128,1,0,0,0,22,75,217,12,0,0,0,198,243,41,74,27,208,55,235,52,79,171,73,178,21,3,0,0,0,192,50,41,155,1,0,0,192,120,
86,41,133,51,160,63,109,202,132,51,78,231,23,17,0,0,0,0,44,147,178,25,0,0,0,140,107,147,228,82,12,208,171,235,36,123,49,156,204,234,238,221,5,0,0,0,192,194,40,155,1,0,0,192,248,62,68,113,3,250,246,46,
73,39,134,147,49,221,12,0,0,0,96,129,148,205,0,0,0,96,26,62,165,76,11,2,250,209,37,57,23,195,201,156,121,103,1,0,0,0,44,143,178,25,0,0,0,76,67,147,82,56,3,250,115,155,100,39,134,147,217,138,0,0,0,0,96,
89,148,205,0,0,0,96,58,214,73,110,196,0,189,186,72,114,16,195,73,88,165,9,0,0,0,176,48,202,102,0,0,0,48,45,219,152,22,4,125,234,98,157,230,169,52,222,87,0,0,0,0,203,162,108,6,0,0,0,211,115,147,50,229,
12,232,199,62,201,181,24,78,226,103,17,0,0,0,0,44,135,178,25,0,0,0,76,211,231,148,169,65,64,63,46,146,180,98,56,218,38,201,74,12,0,0,0,0,203,160,108,6,0,0,0,211,212,36,249,36,6,232,149,117,154,167,241,
139,8,0,0,0,0,150,65,217,12,0,0,0,166,107,147,178,82,19,232,71,155,228,74,12,71,219,138,0,0,0,0,96,25,148,205,0,0,0,96,218,182,81,228,128,62,93,198,58,205,99,53,222,83,0,0,0,0,203,160,108,6,0,0,0,211,
119,147,100,45,6,232,205,121,146,78,12,71,249,89,4,0,0,0,0,243,167,108,6,0,0,0,117,248,156,50,61,8,56,189,54,214,105,30,107,147,100,37,6,0,0,0,128,121,83,54,3,0,0,128,58,52,41,133,51,160,31,215,73,246,
98,56,202,47,34,0,0,0,0,152,55,101,51,0,0,0,168,199,58,101,165,38,208,15,235,52,143,115,38,2,0,0,0,128,121,83,54,3,0,0,128,186,108,147,188,23,3,244,226,16,235,52,143,177,138,194,25,0,0,0,192,172,41,155,
1,0,0,64,125,62,70,161,3,250,114,29,235,52,143,241,179,8,0,0,0,0,230,75,217,12,0,0,0,234,116,147,178,86,19,56,189,115,17,188,216,89,146,70,12,0,0,0,0,243,164,108,6,0,0,0,117,106,146,124,138,82,7,244,225,
16,235,52,143,177,21,1,0,0,0,192,60,41,155,1,0,0,64,189,86,73,62,139,1,122,113,153,164,21,195,139,88,165,9,0,0,0,48,83,202,102,0,0,0,80,183,117,202,74,77,224,244,172,211,124,249,123,105,45,6,0,0,0,128,
249,81,54,3,0,0,128,250,109,83,166,48,1,167,213,198,58,205,151,50,221,12,0,0,0,96,134,148,205,0,0,0,96,30,62,164,148,206,128,211,186,76,114,16,195,179,121,31,1,0,0,0,204,144,178,25,0,0,0,204,199,199,88,
93,7,125,176,78,243,249,154,36,103,98,0,0,0,0,152,23,101,51,0,0,0,152,143,38,201,231,40,156,193,169,237,147,92,139,225,217,172,210,4,0,0,0,152,25,101,51,0,0,0,152,151,38,201,205,221,95,224,116,174,146,
116,98,120,150,51,239,34,0,0,0,128,121,81,54,3,0,0,128,249,89,167,76,56,3,78,167,139,117,154,47,113,38,2,0,0,0,128,249,80,54,3,0,0,128,121,90,167,76,56,3,78,231,246,238,195,211,89,165,9,0,0,0,48,35,202,
102,0,0,0,48,95,219,36,31,197,0,39,117,17,235,52,159,99,147,100,37,6,0,0,0,128,121,80,54,3,0,0,128,121,123,159,82,58,3,78,227,144,228,74,12,207,114,38,2,0,0,0,128,121,80,54,3,0,0,128,249,187,137,194,25,
156,210,117,146,86,12,79,102,149,38,0,0,0,192,76,40,155,1,0,0,192,50,124,76,178,22,3,156,204,133,8,158,108,29,171,52,1,0,0,0,102,65,217,12,0,0,0,150,161,73,242,57,10,103,112,42,251,148,9,103,60,205,47,
34,0,0,0,0,168,159,178,25,0,0,0,44,71,147,82,56,107,68,1,39,113,149,164,19,195,147,156,137,0,0,0,0,160,126,202,102,0,0,0,176,44,77,20,206,224,84,186,88,167,249,84,171,152,172,8,0,0,0,80,61,101,51,0,0,
0,88,158,117,20,206,224,84,118,41,43,53,121,220,207,34,0,0,0,0,168,155,178,25,0,0,0,44,211,58,201,141,24,224,36,76,55,123,154,51,17,0,0,0,0,212,77,217,12,0,0,0,150,235,44,10,103,112,10,109,146,107,49,
60,106,21,171,52,1,0,0,0,170,166,108,6,0,0,0,203,182,141,194,25,156,194,85,146,78,12,143,178,74,19,0,0,0,160,98,202,102,0,0,0,192,54,201,165,24,224,40,93,172,211,124,138,51,17,0,0,0,0,212,75,217,12,0,
0,0,72,146,15,41,165,51,224,229,118,73,246,98,248,161,85,172,210,4,0,0,0,168,150,178,25,0,0,0,240,187,155,40,156,193,177,174,68,240,40,171,52,1,0,0,0,42,165,108,6,0,0,0,252,145,194,25,28,103,159,50,225,
140,135,157,137,0,0,0,0,160,78,202,102,0,0,0,192,159,221,68,25,4,142,113,149,164,19,195,131,86,177,74,19,0,0,0,160,74,202,102,0,0,0,192,125,110,162,12,2,47,117,72,242,119,49,252,208,153,8,0,0,0,0,234,
163,108,6,0,0,0,220,167,73,242,57,10,103,240,82,151,41,165,51,238,247,255,68,0,0,0,0,80,31,101,51,0,0,0,224,33,77,20,206,224,24,87,34,120,208,58,101,157,38,0,0,0,0,21,81,54,3,0,0,0,126,164,137,194,25,
188,212,46,201,94,12,15,58,19,1,0,0,0,64,93,148,205,0,0,0,128,199,52,81,56,131,151,50,221,236,97,86,105,2,0,0,0,84,70,217,12,0,0,0,120,138,38,10,103,240,18,251,148,9,103,124,111,115,247,110,1,0,0,0,160,
18,202,102,0,0,0,192,83,53,81,56,131,151,48,221,236,97,103,34,0,0,0,0,168,135,178,25,0,0,0,240,28,77,20,206,224,185,14,81,56,123,136,85,154,0,0,0,0,21,81,54,3,0,0,0,158,171,137,194,25,60,215,117,146,78,
12,223,217,136,0,0,0,0,160,30,202,102,0,0,0,192,75,52,81,56,131,231,232,146,252,93,12,247,190,75,206,196,0,0,0,0,80,7,101,51,0,0,0,224,165,154,40,156,193,115,92,166,172,212,228,91,63,137,0,0,0,0,160,14,
202,102,0,0,0,192,49,154,40,156,193,115,92,137,224,59,103,34,0,0,0,0,168,131,178,25,0,0,0,112,172,38,10,103,240,84,187,152,110,246,103,171,187,15,0,0,0,0,19,167,108,6,0,0,0,156,66,19,133,51,120,170,11,
17,124,231,76,4,0,0,0,0,211,167,108,6,0,0,0,156,74,19,133,51,120,138,219,36,123,49,124,227,39,17,0,0,0,0,76,159,178,25,0,0,0,112,74,77,74,225,108,35,10,248,161,43,17,124,227,76,4,0,0,0,0,211,167,108,6,
0,0,0,156,90,147,82,56,219,138,2,30,180,143,233,102,127,118,38,2,0,0,0,128,105,83,54,3,0,0,0,250,114,19,133,51,248,17,211,205,190,101,149,38,0,0,0,192,196,41,155,1,0,0,0,125,82,56,131,135,237,99,186,217,
31,157,137,0,0,0,0,96,218,148,205,0,0,0,128,190,221,36,121,47,6,184,151,233,102,95,173,238,62,0,0,0,0,76,148,178,25,0,0,0,48,132,143,41,165,51,224,91,251,152,110,246,71,27,17,0,0,0,0,76,151,178,25,0,0,
0,48,148,109,20,206,224,62,166,155,125,245,255,68,0,0,0,0,48,93,202,102,0,0,0,192,144,182,73,62,37,105,68,1,255,179,143,233,102,191,219,136,0,0,0,0,96,186,148,205,0,0,0,128,161,157,37,249,28,133,51,248,
35,211,205,138,38,201,90,12,0,0,0,0,211,164,108,6,0,0,0,140,97,157,228,95,81,42,129,223,237,99,186,217,239,206,68,0,0,0,0,48,77,202,102,0,0,0,192,88,86,41,19,206,214,162,128,36,166,155,253,238,39,17,0,
0,0,0,76,147,178,25,0,0,0,48,166,38,101,194,217,86,20,96,186,217,157,141,8,0,0,0,0,166,73,217,12,0,0,0,152,130,155,40,156,65,98,186,217,239,54,34,0,0,0,0,152,30,101,51,0,0,0,96,42,110,238,62,176,100,251,
152,110,150,40,155,1,0,0,0,76,146,178,25,0,0,0,48,37,219,148,194,89,35,10,22,204,116,179,228,39,17,0,0,0,0,76,143,178,25,0,0,0,48,53,219,36,159,163,112,198,114,237,147,28,22,158,193,198,215,0,0,0,0,96,
122,148,205,0,0,0,128,41,90,167,20,206,214,162,96,161,76,55,83,56,3,0,0,0,152,28,101,51,0,0,0,96,170,214,81,56,99,185,118,49,221,108,227,107,0,0,0,0,48,45,202,102,0,0,0,192,148,53,41,133,179,51,81,176,
64,75,159,110,246,147,175,0,0,0,0,192,180,40,155,1,0,0,0,83,215,36,249,148,100,43,10,22,230,54,73,183,224,243,111,124,5,0,0,0,0,166,69,217,12,0,0,0,168,197,77,146,143,98,96,65,186,36,127,95,120,6,27,95,
3,0,0,0,128,233,80,54,3,0,0,0,106,242,62,165,116,6,75,113,189,240,243,111,124,5,0,0,0,0,166,67,217,12,0,0,0,168,205,54,201,231,148,245,154,48,119,93,146,221,130,207,255,55,95,1,0,0,0,128,233,80,54,3,0,
0,0,106,180,137,194,25,203,113,181,240,223,58,0,0,0,0,19,161,108,6,0,0,0,212,106,157,228,223,119,127,97,206,14,73,246,11,61,123,227,55,14,0,0,0,48,29,202,102,0,0,0,64,205,154,148,9,103,107,81,48,115,127,
95,240,217,253,190,1,0,0,0,38,66,217,12,0,0,0,168,93,147,228,95,73,182,162,96,198,110,83,38,156,45,209,79,174,31,0,0,0,96,26,148,205,0,0,0,128,185,184,137,194,25,243,182,212,233,102,27,87,15,0,0,0,48,
13,202,102,0,0,0,192,156,220,220,125,96,142,118,73,186,5,158,123,149,50,193,16,0,0,0,128,145,41,155,1,0,0,0,115,179,141,194,25,243,212,165,172,211,92,162,181,235,7,0,0,0,24,159,178,25,0,0,0,48,71,219,
36,255,138,105,72,204,143,85,154,0,0,0,0,140,70,217,12,0,0,0,152,171,117,146,207,81,56,99,94,218,36,251,5,158,251,39,87,15,0,0,0,48,62,101,51,0,0,0,96,206,214,73,254,29,43,248,152,151,127,44,244,183,12,
0,0,0,192,200,148,205,0,0,0,128,185,107,82,38,156,173,69,193,76,236,146,116,11,252,29,175,92,61,0,0,0,192,184,148,205,0,0,0,128,37,104,146,252,43,201,86,20,204,196,110,129,103,222,184,118,0,0,0,128,113,
41,155,1,0,0,0,75,114,19,133,51,230,225,239,11,60,243,223,92,59,0,0,0,192,184,148,205,0,0,0,128,165,185,185,251,64,205,14,73,246,11,59,243,218,181,3,0,0,0,140,75,217,12,0,0,0,88,162,109,20,206,168,223,
63,22,118,222,141,43,7,0,0,0,24,151,178,25,0,0,0,176,84,219,36,255,74,210,136,130,74,237,146,116,11,59,243,218,181,3,0,0,0,140,71,217,12,0,0,0,88,178,117,146,207,81,56,163,94,183,11,59,239,202,149,3,0,
0,0,140,71,217,12,0,0,0,88,186,117,202,132,179,181,40,168,208,223,23,248,123,5,0,0,0,96,36,202,102,0,0,0,0,101,90,210,231,40,178,80,159,246,238,179,20,63,185,114,0,0,0,128,241,40,155,1,0,0,0,20,77,74,
225,108,43,10,42,243,143,5,157,117,237,186,1,0,0,0,198,163,108,6,0,0,0,240,85,147,228,38,10,103,212,229,118,97,191,209,149,43,7,0,0,0,24,135,178,25,0,0,0,192,247,110,146,92,138,129,74,28,178,172,194,217,
202,149,3,0,0,0,140,67,217,12,0,0,0,224,126,31,82,74,103,80,131,127,46,232,172,27,215,13,0,0,0,48,14,101,51,0,0,0,128,135,109,83,10,103,141,40,152,184,219,36,221,66,206,250,55,215,13,0,0,0,48,14,101,51,
0,0,0,128,31,219,38,249,28,133,51,166,173,203,114,86,105,174,92,55,0,0,0,192,56,148,205,0,0,0,0,30,183,142,194,25,211,247,207,5,253,30,1,0,0,0,24,129,178,25,0,0,0,192,211,172,147,252,59,138,46,76,215,
109,150,179,74,211,239,16,0,0,0,96,4,202,102,0,0,0,0,79,215,164,76,56,91,139,130,137,186,93,200,57,87,174,26,0,0,0,96,120,202,102,0,0,0,0,207,211,164,20,206,182,162,96,130,172,210,4,0,0,0,160,55,202,102,
0,0,0,0,207,215,36,185,137,194,25,211,115,155,228,176,128,115,254,205,85,3,0,0,0,12,79,217,12,0,0,0,224,229,110,146,188,23,3,19,115,187,128,51,174,92,51,0,0,0,192,240,148,205,0,0,0,0,142,243,49,165,116,
6,83,177,132,85,154,107,215,12,0,0,0,48,60,101,51,0,0,0,128,227,109,163,112,198,116,236,147,116,11,56,231,218,85,3,0,0,0,12,75,217,12,0,0,0,224,52,182,73,254,149,164,17,5,19,112,187,128,51,250,173,1,0,
0,0,12,76,217,12,0,0,0,224,116,214,73,62,71,9,134,241,45,97,149,230,198,53,3,0,0,0,12,75,217,12,0,0,0,224,180,214,41,133,179,149,40,24,209,109,230,191,74,243,175,174,25,0,0,0,96,88,202,102,0,0,0,0,167,
183,78,89,169,185,22,5,35,186,157,249,249,86,174,24,0,0,0,96,88,202,102,0,0,0,243,214,137,0,70,211,164,76,56,91,139,130,145,124,153,249,249,252,182,0,0,0,0,6,166,108,6,0,0,48,111,175,51,255,201,54,48,
101,77,74,225,108,43,10,70,112,187,128,223,23,0,0,0,0,3,82,54,3,0,0,152,183,46,201,187,36,231,49,229,12,198,210,36,185,137,194,25,227,252,111,192,126,230,103,220,184,102,0,0,0,128,225,40,155,1,0,0,44,
195,46,201,155,204,191,116,0,83,166,112,198,24,254,57,243,243,53,174,24,0,0,0,96,56,202,102,0,0,0,203,113,72,242,54,201,69,76,57,131,177,220,220,125,96,40,183,51,63,223,218,21,3,0,0,0,12,71,217,12,0,0,
96,121,174,83,74,103,173,40,96,20,219,40,156,49,156,195,221,103,174,254,234,138,1,0,0,0,134,163,108,6,0,0,176,76,109,202,90,205,43,81,192,40,182,81,56,99,56,183,51,62,219,202,245,2,0,0,0,12,71,217,12,
0,0,96,217,46,83,74,103,173,40,96,112,219,36,255,74,210,136,130,158,125,153,241,217,86,174,23,0,0,0,96,56,202,102,0,0,0,180,49,229,12,198,178,78,242,57,10,103,244,235,118,198,103,91,185,94,0,0,0,128,225,
40,155,1,0,0,240,187,203,152,114,6,99,88,71,225,140,254,237,103,124,182,149,235,5,0,0,0,24,134,178,25,0,0,0,127,212,198,148,51,24,195,58,201,191,239,254,66,31,254,57,227,179,173,92,47,0,0,0,192,48,148,
205,0,0,0,184,207,101,76,57,131,161,53,41,19,206,214,162,160,7,251,25,159,109,229,122,1,0,0,0,134,161,108,6,0,0,192,67,218,152,114,6,67,107,162,112,70,127,239,244,110,166,103,91,185,94,0,0,0,128,97,40,
155,1,0,0,240,152,203,152,114,6,67,106,82,10,103,91,81,112,98,251,153,158,235,47,174,22,0,0,0,96,24,202,102,0,0,0,60,69,27,83,206,96,72,77,146,155,40,156,113,90,95,102,122,174,181,171,5,0,0,0,24,134,178,
25,0,0,0,207,113,25,83,206,96,72,10,103,156,210,173,8,0,0,0,0,56,134,178,25,0,0,0,207,213,230,235,148,179,78,28,208,187,155,36,239,197,192,9,28,238,62,115,179,113,181,0,0,0,0,195,80,54,3,0,0,224,165,46,
83,74,103,123,81,64,239,62,166,148,206,224,88,222,217,0,0,0,0,188,152,178,25,0,0,0,199,56,36,121,155,228,34,166,156,65,223,182,81,56,227,120,191,206,244,92,107,87,11,0,0,0,208,63,101,51,0,0,0,78,225,58,
166,156,193,16,182,81,56,227,56,115,125,79,55,174,22,0,0,0,160,127,202,102,0,0,0,156,202,33,101,202,217,187,152,114,6,125,218,38,249,20,229,26,94,166,157,233,59,218,239,1,0,0,0,96,0,202,102,0,0,0,156,
218,109,146,215,119,127,129,126,156,37,249,28,5,27,94,102,63,195,51,173,93,43,0,0,0,64,255,148,205,0,0,0,232,67,151,50,225,236,109,202,196,51,224,244,214,81,56,227,101,126,21,1,0,0,0,0,47,161,108,6,0,
0,64,159,246,73,222,36,185,22,5,244,98,29,133,51,94,246,110,158,155,191,186,86,0,0,0,128,254,41,155,1,0,0,208,183,46,201,69,202,148,179,86,28,112,114,235,40,156,241,60,251,25,158,105,229,90,1,0,0,0,250,
167,108,6,0,0,192,80,246,41,83,206,174,68,1,39,183,78,242,239,187,191,240,20,173,8,0,0,0,0,120,46,101,51,0,0,0,134,118,153,228,117,230,57,89,7,198,212,164,76,56,91,139,130,39,152,219,59,120,229,74,1,0,
0,0,250,167,108,6,0,0,192,24,14,41,107,53,47,82,214,108,2,167,209,68,225,140,167,249,117,102,231,89,185,82,0,0,0,128,254,41,155,1,0,0,48,166,235,148,41,103,183,162,128,147,105,162,112,198,227,90,17,0,
0,0,0,240,92,202,102,0,0,0,140,173,75,242,46,101,210,217,65,28,112,18,77,20,206,248,177,118,134,103,90,185,86,0,0,0,128,126,41,155,1,0,0,48,21,251,36,111,82,166,157,1,199,107,82,10,103,91,81,240,131,247,
238,156,172,92,41,0,0,0,64,191,148,205,0,0,0,152,146,46,201,69,74,233,172,21,7,28,173,73,114,19,133,51,238,231,61,11,0,0,0,192,179,40,155,1,0,0,48,69,109,74,225,236,34,165,128,6,28,71,225,140,251,252,
42,2,0,0,0,0,158,67,217,12,0,0,128,41,187,78,41,157,221,138,2,142,166,112,198,159,181,51,59,207,198,149,2,0,0,0,244,75,217,12,0,0,128,169,59,36,121,119,247,57,136,3,142,162,112,198,31,181,34,0,0,0,0,224,
57,148,205,0,0,0,168,197,109,202,148,179,107,81,192,81,20,206,248,163,86,4,0,0,0,0,60,149,178,25,0,0,0,53,233,146,92,164,148,206,90,113,192,139,41,156,241,59,239,82,0,0,0,0,158,76,217,12,0,0,128,26,181,
41,133,179,139,148,2,26,240,124,55,73,46,197,176,120,255,153,209,89,126,114,157,0,0,0,0,253,82,54,3,0,0,160,102,215,41,165,179,91,81,192,139,124,72,41,157,177,92,123,17,0,0,0,0,240,84,202,102,0,0,0,212,
238,144,228,221,221,231,32,14,120,182,109,20,206,150,254,14,5,0,0,0,128,39,81,54,3,0,0,96,46,110,83,166,156,93,137,2,158,109,27,133,179,165,58,136,0,0,0,0,128,167,82,54,3,0,0,96,78,186,36,151,41,165,179,
189,56,224,89,182,81,56,91,42,239,75,0,0,0,0,158,68,217,12,0,0,128,57,106,147,188,77,114,158,82,64,3,158,102,27,133,179,37,58,204,228,28,27,87,9,0,0,0,208,47,101,51,0,0,0,230,108,151,228,245,221,95,224,
105,182,81,56,91,154,255,136,0,0,0,0,128,167,80,54,3,0,0,96,238,186,148,9,103,111,51,159,233,61,208,183,109,20,206,150,100,47,2,0,0,0,0,158,66,217,12,0,0,128,165,216,167,76,57,187,138,213,154,240,20,219,
40,156,45,133,119,34,0,0,0,0,79,162,108,6,0,0,192,210,92,38,121,147,228,86,20,240,168,109,20,206,150,160,21,1,0,0,0,0,79,161,108,6,0,0,192,18,29,146,188,187,251,28,196,1,63,180,141,194,217,82,222,139,
0,0,0,0,240,67,202,102,0,0,0,44,217,109,202,148,179,43,81,192,15,109,163,112,54,119,135,153,156,163,113,149,0,0,0,0,253,81,54,3,0,0,96,233,186,124,93,173,185,23,7,60,104,27,133,179,57,107,103,114,142,
181,171,4,0,0,0,232,143,178,25,0,0,0,20,109,146,183,73,206,83,10,104,192,247,182,81,56,155,171,255,138,0,0,0,0,128,199,40,155,1,0,0,192,183,118,73,94,39,185,22,5,220,107,27,133,179,57,106,69,0,0,0,0,192,
99,148,205,0,0,0,224,123,93,146,139,148,73,103,173,56,224,59,219,40,156,205,241,189,7,0,0,0,0,63,164,108,6,0,0,0,15,219,39,121,147,82,60,235,196,1,223,216,70,225,108,78,90,17,0,0,0,0,240,24,101,51,0,0,
0,120,220,117,202,106,205,91,81,192,55,182,81,56,155,139,78,4,0,0,0,0,60,70,217,12,0,0,0,158,166,75,242,46,101,181,230,65,28,240,63,219,40,156,205,133,119,27,0,0,0,0,63,164,108,6,0,0,0,207,179,79,153,
114,118,21,147,128,224,119,219,40,156,205,193,65,4,0,0,0,0,252,136,178,25,0,0,0,188,204,101,146,55,177,90,19,126,183,141,194,89,237,58,17,0,0,0,0,240,35,202,102,0,0,0,240,114,135,148,213,154,239,98,34,
16,36,165,112,246,81,12,213,250,85,4,0,0,0,0,252,136,178,25,0,0,0,28,239,54,101,202,217,149,40,32,239,83,74,103,0,0,0,0,192,204,40,155,1,0,0,192,105,116,41,171,53,95,39,217,139,131,133,187,137,194,89,
141,90,17,0,0,0,0,240,35,202,102,0,0,0,112,90,135,36,111,99,181,38,40,156,213,167,19,1,0,0,0,0,63,162,108,6,0,0,0,253,184,77,89,173,121,45,10,22,76,225,172,46,157,8,0,0,0,0,248,17,101,51,0,0,0,232,79,
151,228,34,165,116,182,23,7,11,165,112,86,143,86,4,0,0,0,0,252,136,178,25,0,0,0,244,175,77,89,173,121,30,147,131,88,38,133,51,0,0,0,0,152,1,101,51,0,0,0,24,206,46,201,235,88,173,201,50,221,36,57,19,195,
228,117,34,0,0,0,0,224,33,202,102,0,0,0,48,172,46,86,107,178,92,55,73,214,98,152,180,86,4,0,0,0,0,60,68,217,12,0,0,0,198,209,166,172,214,188,136,73,66,44,71,147,228,115,20,206,0,0,0,0,160,74,202,102,0,
0,0,48,174,235,148,213,154,59,81,176,16,77,20,206,0,0,0,0,160,74,202,102,0,0,0,48,190,46,201,121,202,164,179,86,28,44,64,19,133,179,169,242,14,2,0,0,0,224,65,202,102,0,0,0,48,29,251,36,111,98,181,38,203,
208,164,20,206,26,81,76,202,127,69,0,0,0,0,192,67,148,205,0,0,0,96,122,174,99,181,38,203,208,68,225,12,0,0,0,0,170,161,108,6,0,0,0,211,212,197,106,77,150,97,29,133,51,0,0,0,0,168,130,178,25,0,0,0,76,219,
62,101,181,230,85,172,214,100,190,214,81,56,155,138,86,4,0,0,0,0,60,68,217,12,0,0,0,234,112,153,82,58,187,21,5,51,181,78,242,73,12,163,235,42,127,254,214,21,2,0,0,0,244,71,217,12,0,0,0,234,113,72,242,
46,101,181,230,65,28,204,208,38,201,141,24,56,66,39,2,0,0,0,128,254,40,155,1,0,0,64,125,246,73,94,199,106,77,230,105,27,133,51,0,0,0,0,152,36,101,51,0,0,0,168,215,101,172,214,100,158,182,81,56,3,0,0,0,
128,201,81,54,3,0,0,128,186,29,98,181,38,243,180,189,251,48,172,78,4,0,0,0,0,60,68,217,12,0,0,0,230,97,159,50,229,236,74,20,204,200,77,20,206,134,214,138,0,0,0,0,128,135,40,155,1,0,0,192,124,116,41,171,
53,95,167,148,207,96,14,20,206,0,0,0,0,96,34,148,205,0,0,0,96,126,14,41,107,53,223,197,106,77,230,225,99,146,181,24,0,0,0,0,96,92,202,102,0,0,0,48,95,183,177,90,147,121,104,146,124,142,194,25,63,214,137,
0,0,0,0,160,95,202,102,0,0,0,48,111,93,202,106,205,55,177,90,147,186,53,41,133,179,149,40,122,119,168,244,185,91,87,7,0,0,0,208,47,101,51,0,0,0,88,134,54,101,181,230,121,76,255,161,94,77,146,79,119,127,
233,207,65,4,0,0,0,0,220,71,217,12,0,0,0,150,101,151,228,117,146,107,81,80,169,117,202,132,179,70,20,0,0,0,0,48,44,101,51,0,0,0,88,158,46,201,69,172,214,164,94,235,148,9,103,0,0,0,0,192,128,148,205,0,
0,0,96,185,218,148,213,154,23,177,90,147,250,108,146,220,136,1,0,0,0,0,134,163,108,6,0,0,0,92,167,172,214,220,137,130,202,108,147,124,20,3,119,58,17,0,0,0,0,244,75,217,12,0,0,0,72,74,73,227,60,101,210,
89,43,14,42,242,62,165,116,6,191,138,0,0,0,0,160,95,202,102,0,0,0,192,31,237,147,188,137,213,154,212,229,38,10,103,167,228,183,15,0,0,0,192,189,148,205,0,0,0,128,251,92,167,148,206,110,69,65,37,110,146,
172,197,112,18,38,132,1,0,0,0,112,47,101,51,0,0,0,224,33,135,36,239,82,86,107,30,196,65,5,62,71,225,12,0,0,0,0,122,163,108,6,0,0,0,60,102,159,228,117,146,171,88,175,199,180,53,73,62,221,253,101,121,14,
34,0,0,0,0,232,151,178,25,0,0,0,240,84,151,41,171,53,247,162,96,194,86,41,19,206,26,81,44,206,65,4,0,0,0,0,253,82,54,3,0,0,0,158,227,144,178,86,243,93,20,59,152,174,117,202,132,51,0,0,0,0,224,132,148,
205,0,0,0,128,151,184,77,153,114,118,45,10,38,106,147,228,70,12,0,0,0,0,112,58,202,102,0,0,0,192,75,117,73,46,98,181,38,211,181,77,89,255,10,0,0,0,0,156,128,178,25,0,0,0,112,172,54,101,181,230,121,74,
1,13,166,228,67,74,233,140,249,219,139,0,0,0,0,160,95,202,102,0,0,0,192,169,236,146,188,190,251,11,83,114,147,178,86,19,0,0,0,0,56,130,178,25,0,0,0,112,74,93,202,132,179,183,41,19,207,96,42,62,37,89,139,
1,0,0,0,0,94,78,217,12,0,0,0,232,195,62,201,155,36,87,177,90,147,105,104,82,10,103,141,40,102,201,123,6,0,0,0,96,0,255,39,2,0,0,128,249,250,237,183,223,132,192,216,46,95,189,122,181,75,242,49,201,153,
56,24,217,42,201,231,148,201,123,157,56,102,165,21,1,0,0,0,64,255,76,54,3,0,0,0,250,118,72,242,238,238,115,16,7,35,91,39,185,17,3,0,0,0,0,60,159,178,25,0,0,0,48,148,219,124,93,173,9,99,58,139,194,25,0,
0,0,0,60,155,178,25,0,0,0,48,164,46,201,101,74,233,108,47,14,70,180,189,251,48,15,7,17,0,0,0,0,244,79,217,12,0,0,0,24,67,155,228,109,146,243,148,2,26,140,225,38,101,202,25,245,251,143,8,0,0,0,0,250,167,
108,6,0,0,0,140,105,151,228,245,221,95,24,195,77,146,181,24,0,0,0,0,224,113,202,102,0,0,0,192,216,186,148,9,103,111,99,21,30,195,107,146,124,186,251,75,221,239,17,0,0,0,0,122,166,108,6,0,0,0,76,197,62,
101,202,217,149,40,24,216,42,201,231,40,156,213,172,21,1,0,0,0,64,255,148,205,0,0,0,128,169,185,76,41,157,237,69,193,128,214,73,62,138,1,0,0,0,0,30,166,108,6,0,0,0,76,209,33,101,173,230,187,88,143,199,
112,182,81,56,171,149,247,4,0,0,0,192,0,148,205,0,0,0,128,41,187,77,153,114,118,45,10,6,242,62,165,116,70,93,218,223,255,197,171,87,175,142,254,0,0,0,0,112,63,101,51,0,0,0,96,234,186,36,23,41,147,206,
90,113,48,128,155,148,181,154,0,0,0,0,192,31,40,155,1,0,0,0,181,216,39,121,147,228,42,86,230,209,191,207,73,86,98,168,130,247,1,0,0,0,192,64,148,205,0,0,0,128,218,92,166,148,206,246,162,160,71,77,146,
79,119,127,153,182,86,4,0,0,0,0,195,80,54,3,0,0,0,106,116,72,89,171,249,46,166,26,209,159,117,202,74,77,0,0,0,0,32,202,102,0,0,0,64,221,110,147,188,78,178,19,5,61,57,75,242,81,12,147,118,16,1,0,0,0,192,
48,148,205,0,0,0,128,218,117,73,206,83,38,157,29,196,65,15,222,39,217,138,97,178,254,35,2,0,0,0,128,97,40,155,1,0,0,0,115,177,79,153,114,118,37,10,122,112,147,178,86,19,0,0,0,0,22,75,217,12,0,0,0,152,
155,203,148,210,217,94,20,156,216,231,36,43,49,76,78,43,2,0,0,0,128,97,40,155,1,0,0,0,115,116,72,89,171,121,145,178,102,19,78,161,73,242,233,238,47,211,225,55,14,0,0,0,48,16,101,51,0,0,0,96,206,174,83,
166,156,221,138,130,19,89,39,249,40,134,73,233,68,0,0,0,0,48,12,101,51,0,0,0,96,238,186,36,239,82,38,157,29,196,193,9,108,83,214,181,206,213,95,43,123,222,214,87,18,0,0,0,96,24,202,102,0,0,0,192,82,236,
147,188,73,153,118,6,199,250,144,82,58,155,163,149,235,5,0,0,0,224,62,202,102,0,0,0,192,146,116,73,46,82,74,103,173,56,56,210,199,148,181,154,140,199,239,24,0,0,0,96,64,202,102,0,0,0,192,18,181,41,133,
179,43,81,112,132,38,201,167,187,191,140,163,19,1,0,0,0,192,112,148,205,0,0,0,128,37,187,76,242,58,101,197,38,188,196,42,165,112,198,56,14,34,0,0,0,0,24,142,178,25,0,0,0,176,116,135,36,111,83,214,107,
118,226,224,5,54,73,110,196,48,138,255,136,0,0,0,0,96,56,202,102,0,0,0,0,197,117,202,148,179,91,81,240,2,219,187,15,195,234,68,0,0,0,0,48,28,101,51,0,0,0,128,175,186,36,239,238,62,157,56,120,166,155,36,
107,49,12,170,21,1,0,0,0,192,112,148,205,0,0,0,0,190,119,155,50,229,236,90,20,60,211,231,36,141,24,0,0,0,0,152,35,101,51,0,0,0,128,251,117,73,46,146,188,77,114,16,7,79,212,164,254,194,217,170,162,103,
221,251,202,1,0,0,0,12,71,217,12,0,0,0,224,199,246,73,222,196,148,51,158,110,157,228,99,197,207,191,114,133,0,0,0,0,220,71,217,12,0,0,0,224,113,93,202,148,179,55,73,90,113,240,4,219,36,239,197,208,43,
191,69,0,0,0,128,129,41,155,1,0,0,0,60,93,155,82,56,187,18,5,79,240,49,201,70,12,189,233,68,0,0,0,0,48,44,101,51,0,0,0,128,231,187,140,41,103,60,205,167,88,75,217,23,191,63,0,0,0,128,129,41,155,1,0,0,
0,188,76,155,175,83,206,58,113,240,128,38,165,112,214,136,226,228,254,43,2,0,0,0,128,97,41,155,1,0,0,0,28,231,50,165,116,182,23,5,15,88,167,172,212,228,180,90,17,0,0,0,0,12,75,217,12,0,0,0,224,120,135,
36,111,147,92,196,148,51,238,183,77,242,190,130,231,92,85,148,169,223,26,0,0,0,192,192,148,205,0,0,0,0,78,231,58,166,156,241,176,143,41,83,206,166,108,85,81,158,173,175,20,0,0,0,192,176,148,205,0,0,0,
0,78,235,16,83,206,120,216,231,36,141,24,78,194,239,11,0,0,0,96,96,202,102,0,0,0,0,253,184,142,41,103,124,175,73,242,73,12,71,107,69,0,0,0,0,48,60,101,51,0,0,0,128,254,28,98,202,25,223,219,36,185,20,195,
81,252,158,0,0,0,0,70,160,108,6,0,0,0,208,191,235,152,114,198,183,62,36,57,19,195,139,181,34,0,0,0,0,24,158,178,25,0,0,0,192,48,14,49,229,140,111,221,36,89,77,236,153,86,149,100,247,95,95,31,0,0,0,128,
225,41,155,1,0,0,0,12,235,58,166,156,81,52,73,62,77,236,153,86,149,100,231,247,3,0,0,0,48,2,101,51,0,0,0,128,225,29,98,202,25,197,58,201,71,49,60,155,223,13,0,0,0,192,8,148,205,0,0,0,0,198,115,29,83,206,
72,222,39,57,19,195,179,180,34,0,0,0,0,24,158,178,25,0,0,0,192,184,14,49,229,140,228,38,245,172,176,28,155,223,9,0,0,0,192,72,148,205,0,0,0,0,166,225,58,166,156,45,89,147,82,56,27,219,95,42,200,170,245,
117,1,0,0,0,24,135,178,25,0,0,0,192,116,28,98,202,217,146,109,146,92,142,252,12,235,74,126,39,0,0,0,0,140,64,217,12,0,0,0,96,122,174,99,202,217,82,125,72,41,157,241,176,255,136,0,0,0,0,96,28,202,102,0,
0,0,0,211,116,72,153,114,118,37,138,197,249,148,178,86,147,251,237,69,0,0,0,0,48,14,101,51,0,0,0,128,105,187,76,153,114,214,138,98,49,154,36,55,98,120,80,39,2,0,0,0,128,113,40,155,1,0,0,0,76,95,155,82,
56,51,229,108,57,206,146,188,31,225,159,187,170,228,247,0,0,0,0,192,8,148,205,0,0,0,0,234,113,153,82,58,59,136,98,17,62,36,89,15,252,207,92,77,60,19,223,125,0,0,0,128,17,41,155,1,0,0,0,212,165,77,41,156,
93,139,98,246,154,88,167,249,103,7,17,0,0,0,0,140,71,217,12,0,0,0,160,62,93,146,139,36,111,239,254,53,243,181,78,242,81,12,255,243,69,4,0,0,0,0,227,81,54,3,0,0,0,168,215,62,201,235,36,183,162,152,181,
247,73,54,3,252,115,154,10,178,232,124,29,0,0,0,0,198,163,108,6,0,0,0,80,183,46,201,187,187,79,39,142,217,250,148,254,203,96,235,10,114,104,125,21,0,0,0,0,198,163,108,6,0,0,0,48,15,183,73,222,164,76,59,
99,126,154,36,55,98,80,54,3,0,0,0,24,147,178,25,0,0,0,192,124,28,146,188,77,114,33,138,89,58,75,178,93,240,249,187,152,222,7,0,0,0,48,42,101,51,0,0,0,128,249,185,78,153,114,214,138,98,118,62,38,89,45,
244,236,190,207,0,0,0,0,35,83,54,3,0,0,0,152,167,54,101,202,217,181,40,102,165,73,127,235,52,55,19,63,251,193,245,3,0,0,0,140,75,217,12,0,0,0,96,190,186,148,149,154,111,99,253,224,156,108,146,92,46,240,
220,255,113,245,0,0,0,0,227,82,54,3,0,0,0,152,191,125,146,215,73,110,69,49,27,31,146,172,23,248,61,6,0,0,0,96,68,202,102,0,0,0,0,203,208,37,121,151,50,233,172,19,199,44,156,122,157,230,95,38,126,222,131,
43,7,0,0,0,24,151,178,25,0,0,0,192,178,92,167,172,213,108,69,81,189,117,78,187,78,115,61,241,243,30,92,57,0,0,0,192,184,148,205,0,0,0,0,150,167,77,242,38,165,120,70,221,150,178,78,115,239,170,1,0,0,0,
198,167,108,6,0,0,0,176,92,23,41,83,206,58,81,84,237,83,146,102,230,103,108,93,51,0,0,0,192,248,148,205,0,0,0,0,150,109,159,228,117,76,142,170,217,42,101,194,217,41,254,123,166,234,63,174,25,0,0,0,96,
124,202,102,0,0,0,0,116,41,19,206,46,68,81,173,247,73,54,71,254,119,172,38,124,190,214,21,3,0,0,0,140,79,217,12,0,0,0,128,223,93,39,121,147,228,32,138,42,221,100,190,235,52,91,215,11,0,0,0,48,62,101,51,
0,0,0,0,254,168,77,41,156,237,68,81,157,85,94,190,78,179,153,240,185,14,41,211,247,0,0,0,0,24,153,178,25,0,0,0,0,127,214,37,57,191,251,116,226,168,202,251,188,108,157,230,122,194,103,58,184,86,0,0,0,128,
105,80,54,3,0,0,0,224,33,187,36,111,99,133,97,109,230,182,78,243,139,43,5,0,0,0,152,6,101,51,0,0,0,0,126,164,77,41,156,237,68,81,141,85,94,190,78,115,170,223,65,0,0,0,0,38,64,217,12,0,0,0,128,199,116,
41,43,53,223,197,90,205,90,188,207,243,214,105,174,39,124,150,131,235,4,0,0,0,152,6,101,51,0,0,0,0,158,234,54,201,155,152,52,85,139,231,172,211,108,38,124,14,223,55,0,0,0,128,137,80,54,3,0,0,0,224,57,
14,41,133,179,107,81,76,222,42,245,175,211,220,187,70,0,0,0,128,233,80,54,3,0,0,0,224,37,46,98,173,102,13,222,231,105,235,52,255,54,209,231,63,184,66,0,0,0,128,233,80,54,3,0,0,0,224,165,110,147,188,141,
53,135,83,247,241,9,255,153,102,162,207,254,171,235,3,0,0,0,152,14,101,51,0,0,0,0,142,209,166,20,206,118,162,152,172,117,146,203,138,191,95,0,0,0,0,76,132,178,25,0,0,0,0,199,234,146,156,223,125,58,113,
76,210,135,148,210,217,67,86,19,125,238,189,171,3,0,0,0,152,14,101,51,0,0,0,0,78,101,23,107,53,167,236,230,7,255,222,106,130,207,235,123,4,0,0,0,48,49,202,102,0,0,0,0,156,82,155,82,56,187,21,197,228,172,
83,215,58,205,214,149,1,0,0,0,76,139,178,25,0,0,0,0,167,214,37,121,151,228,66,20,147,243,75,190,159,98,182,158,232,179,254,234,186,0,0,0,0,166,69,217,12,0,0,0,128,190,92,167,76,57,235,68,49,25,77,190,
95,167,217,76,244,89,91,215,5,0,0,0,48,45,202,102,0,0,0,0,244,105,159,228,117,20,135,166,100,147,228,125,37,223,29,0,0,0,0,38,68,217,12,0,0,0,128,190,117,73,222,164,76,58,99,26,62,228,235,68,179,245,4,
159,175,117,69,0,0,0,0,211,163,108,6,0,0,0,192,80,46,146,156,199,90,205,41,104,242,117,157,102,51,193,231,107,93,17,0,0,0,192,244,40,155,1,0,0,0,48,164,93,146,183,73,14,162,24,221,217,221,231,47,19,124,
182,95,93,15,0,0,0,192,244,40,155,1,0,0,0,48,180,54,101,173,230,94,20,163,187,73,178,153,232,119,4,0,0,0,128,137,81,54,3,0,0,0,96,12,93,202,132,179,107,81,140,170,73,178,158,224,115,237,93,13,0,0,0,192,
244,40,155,1,0,0,0,48,166,139,36,231,41,229,51,72,76,53,3,0,0,0,152,44,101,51,0,0,0,0,198,182,75,153,114,214,137,130,152,106,6,0,0,0,48,89,202,102,0,0,0,0,76,65,155,228,117,76,181,34,249,85,4,0,0,0,0,
211,164,108,6,0,0,0,192,84,116,73,222,164,76,58,99,185,90,17,0,0,0,0,76,147,178,25,0,0,0,0,83,115,126,247,97,121,186,40,155,1,0,0,0,76,150,178,25,0,0,0,0,83,180,75,242,54,165,124,196,114,180,34,0,0,0,
0,152,46,101,51,0,0,0,0,166,106,159,82,56,107,69,177,24,95,68,0,0,0,0,48,93,202,102,0,0,0,0,76,89,155,82,56,219,139,98,17,220,51,0,0,0,192,132,41,155,1,0,0,0,48,117,93,74,225,108,39,138,217,107,69,0,0,
0,0,48,93,202,102,0,0,0,0,212,226,60,201,133,24,102,171,77,41,22,2,0,0,0,48,81,202,102,0,0,0,0,212,228,58,201,187,40,37,205,81,43,2,0,0,0,128,105,83,54,3,0,0,0,160,54,183,41,107,53,59,81,204,202,23,17,
0,0,0,0,76,155,178,25,0,0,0,0,53,106,147,188,142,105,88,115,178,23,1,0,0,0,192,180,41,155,1,0,0,0,80,171,46,101,194,217,94,20,179,184,203,131,24,0,0,0,0,166,77,217,12,0,0,0,128,154,117,41,133,179,157,
40,170,182,23,1,0,0,0,192,244,41,155,1,0,0,0,48,7,231,73,174,196,80,173,47,34,0,0,0,0,152,62,101,51,0,0,0,0,230,226,50,165,116,70,125,90,17,0,0,0,0,76,159,178,25,0,0,0,0,115,178,75,89,171,217,137,162,
42,123,17,0,0,0,0,76,159,178,25,0,0,0,0,115,179,143,194,89,109,247,5,0,0,0,64,5,148,205,0,0,0,0,152,163,54,165,112,214,138,98,242,190,136,0,0,0,0,160,14,202,102,0,0,0,0,204,85,27,133,179,26,236,69,0,0,
0,0,80,7,101,51,0,0,0,0,230,172,139,194,217,212,237,69,0,0,0,0,80,7,101,51,0,0,0,0,230,174,75,242,38,201,78,20,147,179,23,1,0,0,0,64,61,148,205,0,0,0,0,88,138,243,40,156,77,205,23,17,0,0,0,0,212,67,217,
12,0,0,0,128,37,81,56,155,150,189,8,0,0,0,0,234,161,108,6,0,0,0,192,210,156,39,185,18,195,36,236,69,0,0,0,0,80,15,101,51,0,0,0,0,150,232,50,165,116,198,120,246,34,0,0,0,0,168,139,178,25,0,0,0,0,75,181,
139,194,217,152,190,136,0,0,0,0,160,46,202,102,0,0,0,0,44,217,46,10,103,99,217,139,0,0,0,0,160,46,202,102,0,0,0,0,44,221,46,10,103,99,216,139,0,0,0,0,160,46,202,102,0,0,0,0,160,112,54,180,189,8,0,0,0,
0,234,163,108,6,0,0,0,0,197,46,10,103,67,249,34,2,0,0,0,128,250,40,155,1,0,0,0,192,87,187,40,156,13,97,47,2,0,0,0,128,250,40,155,1,0,0,0,192,183,118,81,56,235,219,94,4,0,0,0,0,245,81,54,3,0,0,0,128,239,
237,162,112,214,151,91,17,0,0,0,0,212,73,217,12,0,0,0,0,238,183,139,194,89,31,190,136,0,0,0,0,160,78,202,102,0,0,0,0,240,176,93,20,206,78,109,47,2,0,0,0,128,58,41,155,1,0,0,0,192,143,237,162,112,118,42,
93,146,86,12,0,0,0,0,117,82,54,3,0,0,0,128,199,237,162,112,118,10,183,34,0,0,0,0,168,151,178,25,0,0,0,0,60,205,46,10,103,199,250,34,2,0,0,0,128,122,41,155,1,0,0,0,192,211,237,146,92,137,225,197,246,34,
0,0,0,0,168,151,178,25,0,0,0,0,60,207,101,74,233,140,231,105,147,28,196,0,0,0,0,80,47,101,51,0,0,0,0,120,190,243,40,156,61,215,94,4,0,0,0,0,117,83,54,3,0,0,0,128,151,57,79,114,43,134,39,251,167,8,0,0,
0,0,234,166,108,6,0,0,0,0,47,119,158,178,30,146,199,237,69,0,0,0,0,80,55,101,51,0,0,0,0,120,185,46,201,219,40,156,61,197,70,4,0,0,0,0,117,83,54,3,0,0,0,128,227,116,73,222,221,253,229,97,31,68,0,0,0,0,
80,55,101,51,0,0,0,0,56,222,33,101,194,89,39,138,7,109,98,186,25,0,0,0,64,213,148,205,0,0,0,0,224,52,218,36,231,98,248,33,211,205,0,0,0,0,42,166,108,6,0,0,0,0,167,115,27,133,179,31,217,196,116,51,0,0,
0,128,106,41,155,1,0,0,0,192,105,237,238,62,220,207,116,51,0,0,0,128,74,41,155,1,0,0,0,192,233,157,39,217,139,225,94,155,152,110,6,0,0,0,80,37,101,51,0,0,0,0,232,199,187,36,173,24,238,245,139,8,0,0,0,
0,234,163,108,6,0,0,0,0,253,232,82,38,156,117,162,248,206,89,146,149,24,0,0,0,0,234,162,108,6,0,0,0,0,253,105,83,10,103,124,239,131,8,0,0,0,0,234,162,108,6,0,0,0,0,253,186,77,114,33,134,239,108,99,186,
25,0,0,0,64,85,148,205,0,0,0,0,160,127,215,73,118,98,248,142,233,102,0,0,0,0,21,81,54,3,0,0,0,128,97,92,164,172,213,228,171,179,36,141,24,0,0,0,0,234,160,108,6,0,0,0,0,195,232,146,156,223,253,165,104,
146,188,23,3,0,0,0,64,29,148,205,0,0,0,0,96,56,109,74,225,140,175,126,137,233,102,0,0,0,0,85,80,54,3,0,0,0,128,97,221,38,185,18,195,255,52,41,235,52,1,0,0,0,152,56,101,51,0,0,0,0,24,222,101,146,189,24,
254,231,131,8,0,0,0,0,166,79,217,12,0,0,0,0,198,241,46,201,65,12,73,146,85,146,173,24,0,0,0,0,166,77,217,12,0,0,0,0,198,209,165,20,206,40,126,22,1,0,0,0,192,180,41,155,1,0,0,0,192,120,218,36,23,98,72,
146,108,238,62,0,0,0,0,76,148,178,25,0,0,0,0,140,235,58,201,173,24,146,152,110,6,0,0,0,48,105,202,102,0,0,0,0,48,190,243,36,7,49,100,155,100,37,6,0,0,0,128,105,82,54,3,0,0,0,128,241,117,73,222,137,33,
73,41,156,1,0,0,0,48,65,202,102,0,0,0,0,48,13,109,146,11,49,228,151,36,141,24,0,0,0,0,166,71,217,12,0,0,0,0,166,227,58,201,237,194,51,104,146,156,249,42,0,0,0,0,76,143,178,25,0,0,0,0,76,203,121,146,195,
194,51,248,224,107,0,0,0,0,48,61,202,102,0,0,0,0,48,45,93,146,119,11,207,96,149,100,227,171,0,0,0,0,48,45,202,102,0,0,0,0,48,61,109,146,171,133,103,240,179,175,1,0,0,0,192,180,40,155,1,0,0,0,192,52,93,
38,217,47,248,252,219,148,9,103,0,0,0,0,76,132,178,25,0,0,0,0,76,215,121,202,90,205,165,218,250,10,0,0,0,0,76,135,178,25,0,0,0,0,76,215,33,165,112,182,84,86,105,2,0,0,0,76,136,178,25,0,0,0,0,76,219,109,
146,221,66,207,190,138,233,102,0,0,0,0,147,161,108,6,0,0,0,0,211,119,145,50,229,108,137,76,55,3,0,0,0,152,8,101,51,0,0,0,0,152,190,46,203,93,167,185,73,153,112,6,0,0,0,192,200,148,205,0,0,0,0,160,14,251,
36,215,11,61,251,47,174,31,0,0,0,96,124,202,102,0,0,0,0,80,143,139,36,237,2,207,189,117,245,0,0,0,0,227,83,54,3,0,0,0,128,186,44,113,157,102,19,133,51,0,0,0,128,209,41,155,1,0,0,0,64,93,218,36,87,11,60,
247,207,174,30,0,0,0,96,92,202,102,0,0,0,0,80,159,203,44,111,157,230,38,201,202,213,3,0,0,0,140,71,217,12,0,0,0,0,234,180,196,117,154,191,184,118,0,0,0,128,241,40,155,1,0,0,0,64,157,218,44,111,157,230,
153,107,7,0,0,0,24,143,178,25,0,0,0,0,212,235,50,203,90,167,185,138,194,25,0,0,0,192,104,148,205,0,0,0,0,160,110,75,91,167,249,179,43,7,0,0,0,24,135,178,25,0,0,0,0,212,173,77,114,189,160,243,158,37,105,
92,59,0,0,0,192,240,148,205,0,0,0,0,160,126,87,73,14,11,58,239,214,149,3,0,0,0,12,79,217,12,0,0,0,0,234,215,101,89,235,52,173,210,4,0,0,0,24,129,178,25,0,0,0,0,204,195,62,201,237,66,206,186,190,251,0,
0,0,0,48,32,101,51,0,0,0,0,152,143,243,148,41,103,75,96,186,25,0,0,0,192,192,148,205,0,0,0,0,96,62,186,36,87,11,57,235,153,235,6,0,0,0,24,150,178,25,0,0,0,0,204,203,117,202,74,205,185,91,69,225,12,0,0,
0,96,80,202,102,0,0,0,0,48,63,23,11,57,231,255,115,213,0,0,0,0,195,81,54,3,0,0,0,128,249,105,83,38,156,205,221,153,171,6,0,0,0,24,142,178,25,0,0,0,0,204,211,85,146,110,230,103,108,146,108,93,53,0,0,0,
192,48,148,205,0,0,0,0,96,158,186,44,99,157,166,85,154,0,0,0,0,3,249,63,17,0,0,0,0,125,250,237,183,223,132,0,227,217,189,122,245,234,231,36,155,25,159,241,44,101,194,89,231,186,1,0,0,0,250,101,178,25,
0,0,0,0,204,219,213,2,206,120,230,154,1,0,0,0,250,167,108,6,0,0,0,0,243,182,79,178,155,249,25,173,210,4,0,0,0,24,128,178,25,0,0,0,0,204,223,85,230,189,102,242,44,101,149,38,0,0,0,0,61,82,54,3,0,0,0,128,
249,59,36,249,251,204,207,120,230,154,1,0,0,0,250,165,108,6,0,0,0,0,203,112,157,82,58,155,43,171,52,1,0,0,0,122,166,108,6,0,0,0,0,203,208,165,172,211,156,171,179,88,165,9,0,0,0,208,43,101,51,0,0,0,0,88,
142,93,230,61,221,236,204,21,3,0,0,0,244,71,217,12,0,0,0,0,150,229,124,198,103,179,74,19,0,0,0,160,71,202,102,0,0,0,0,176,44,251,187,207,28,157,197,42,77,0,0,0,128,222,40,155,1,0,0,0,192,242,92,205,248,
108,103,174,23,0,0,0,160,31,202,102,0,0,0,0,176,60,251,36,183,51,61,155,85,154,0,0,0,0,61,81,54,3,0,0,0,128,101,186,152,233,185,206,92,45,0,0,0,64,63,148,205,0,0,0,0,96,153,14,73,118,51,61,219,153,235,
5,0,0,0,56,61,101,51,0,0,0,0,88,174,171,153,158,203,42,77,0,0,0,128,30,40,155,1,0,0,0,192,114,29,50,207,233,102,103,174,22,0,0,0,224,244,148,205,0,0,0,0,96,217,230,56,221,172,73,178,118,181,0,0,0,0,167,
165,108,6,0,0,0,0,203,118,200,60,167,155,253,236,106,1,0,0,0,78,75,217,12,0,0,0,0,152,227,116,179,141,107,5,0,0,0,56,45,101,51,0,0,0,0,224,144,249,77,55,91,39,89,185,90,0,0,0,128,211,81,54,3,0,0,0,0,146,
121,78,55,59,115,173,0,0,0,0,167,163,108,6,0,0,0,0,36,243,156,110,246,147,107,5,0,0,0,56,29,101,51,0,0,0,0,224,119,255,152,217,121,206,92,41,0,0,0,192,233,40,155,1,0,0,0,0,191,219,223,125,230,228,204,
181,2,0,0,0,156,134,178,25,0,0,0,0,240,71,87,51,59,143,85,154,0,0,0,0,39,162,108,6,0,0,0,0,252,209,62,201,97,70,231,57,115,165,0,0,0,0,167,161,108,6,0,0,0,0,252,217,156,166,155,173,238,62,0,0,0,0,28,73,
217,12,0,0,0,0,248,179,93,146,110,70,231,57,115,165,0,0,0,0,199,83,54,3,0,0,0,0,238,243,247,25,157,229,39,215,9,0,0,0,112,60,101,51,0,0,0,0,224,62,215,51,58,203,198,117,2,0,0,0,28,79,217,12,0,0,0,0,184,
79,151,178,78,115,14,154,36,107,87,10,0,0,0,112,28,101,51,0,0,0,0,224,33,115,90,165,121,230,58,1,0,0,0,142,163,108,6,0,0,0,0,60,164,189,251,204,193,79,174,19,0,0,0,224,56,202,102,0,0,0,0,192,143,204,101,
186,217,198,85,2,0,0,0,28,71,217,12,0,0,0,0,248,145,93,146,110,38,103,217,184,78,0,0,0,128,151,83,54,3,0,0,0,0,30,179,155,201,57,54,174,18,0,0,0,224,229,148,205,0,0,0,0,128,199,204,101,149,230,79,174,
18,0,0,0,224,229,148,205,0,0,0,0,128,199,28,146,236,103,112,142,141,171,4,0,0,0,120,57,101,51,0,0,0,0,224,41,254,49,147,115,108,92,37,0,0,0,192,203,40,155,1,0,0,0,0,79,113,155,164,155,193,57,54,174,18,
0,0,0,224,101,148,205,0,0,0,0,128,167,232,82,10,103,181,251,201,85,2,0,0,0,188,140,178,25,0,0,0,0,240,84,115,88,165,185,113,141,0,0,0,0,47,163,108,6,0,0,0,0,60,213,62,201,97,6,231,216,184,74,0,0,0,128,
231,83,54,3,0,0,0,0,158,195,116,51,0,0,0,128,133,82,54,3,0,0,0,0,158,99,55,131,51,252,205,53,2,0,0,0,60,159,178,25,0,0,0,0,240,28,135,36,109,229,103,216,184,70,0,0,0,128,231,83,54,3,0,0,0,0,158,171,246,
85,154,77,146,181,107,4,0,0,0,120,30,101,51,0,0,0,0,224,185,110,103,112,134,181,107,4,0,0,0,120,30,101,51,0,0,0,0,224,185,14,73,246,149,159,225,39,215,8,0,0,0,240,60,202,102,0,0,0,0,192,75,212,190,74,
115,237,10,1,0,0,0,158,71,217,12,0,0,0,0,120,137,219,202,159,127,237,10,1,0,0,0,158,71,217,12,0,0,0,0,120,137,46,245,175,210,220,184,70,0,0,0,128,167,83,54,3,0,0,0,0,94,234,159,149,63,255,198,21,2,0,0,
0,60,157,178,25,0,0,0,0,240,82,183,149,63,255,223,92,33,0,0,0,192,211,41,155,1,0,0,0,0,47,117,72,210,86,252,252,107,87,8,0,0,0,240,116,202,102,0,0,0,0,192,49,254,81,241,179,175,146,52,174,16,0,0,0,224,
105,148,205,0,0,0,0,128,99,236,43,127,254,181,43,4,0,0,0,120,26,101,51,0,0,0,0,224,24,109,202,58,205,90,109,92,33,0,0,0,192,211,40,155,1,0,0,0,0,199,186,173,248,217,255,230,250,0,0,0,0,158,70,217,12,0,
0,0,0,56,214,151,138,159,125,237,250,0,0,0,0,158,70,217,12,0,0,0,0,56,214,109,197,207,190,74,210,184,66,0,0,0,128,199,41,155,1,0,0,0,0,167,112,91,241,179,175,93,31,0,0,0,192,227,148,205,0,0,0,0,128,83,
168,121,149,230,198,245,1,0,0,0,60,78,217,12,0,0,0,0,56,133,125,197,207,254,87,215,7,0,0,0,240,56,101,51,0,0,0,0,224,20,218,36,135,74,159,125,237,250,0,0,0,0,30,167,108,6,0,0,0,0,156,202,190,210,231,94,
187,58,0,0,0,128,199,41,155,1,0,0,0,0,167,242,165,226,103,95,187,62,0,0,0,128,31,83,54,3,0,0,0,0,78,101,95,241,179,175,92,31,0,0,0,192,143,41,155,1,0,0,0,0,167,114,184,251,212,104,237,250,0,0,0,0,126,
76,217,12,0,0,0,0,56,165,125,165,207,253,147,171,3,0,0,0,248,49,101,51,0,0,0,0,224,148,190,84,250,220,43,87,7,0,0,0,240,99,202,102,0,0,0,0,192,41,237,43,125,238,149,171,3,0,0,0,248,49,101,51,0,0,0,0,224,
148,14,119,159,26,109,92,31,0,0,0,192,195,148,205,0,0,0,0,128,83,219,87,250,220,141,171,3,0,0,0,120,152,178,25,0,0,0,0,112,106,191,86,250,220,107,87,7,0,0,0,240,48,101,51,0,0,0,0,224,212,246,149,62,247,
223,92,29,0,0,0,192,195,148,205,0,0,0,0,128,83,107,147,116,21,62,247,202,213,1,0,0,0,60,76,217,12,0,0,0,0,232,67,91,225,51,175,93,27,0,0,0,192,195,148,205,0,0,0,0,128,62,124,169,244,185,87,174,14,0,0,
0,224,126,202,102,0,0,0,0,64,31,218,74,159,123,229,234,0,0,0,0,238,167,108,6,0,0,0,0,51,246,219,111,191,61,249,115,98,251,74,35,91,191,122,245,42,127,252,0,0,0,0,80,40,155,1,0,0,0,0,125,232,146,28,42,
124,238,198,213,1,0,0,0,220,79,217,12,0,0,0,0,232,75,91,225,51,255,228,218,0,0,0,0,238,167,108,6,0,0,0,0,244,229,215,10,159,185,113,109,0,0,0,0,247,83,54,3,0,0,0,0,250,178,175,240,153,215,174,13,0,0,0,
224,126,202,102,0,0,0,0,64,95,218,74,159,187,113,117,0,0,0,0,223,83,54,3,0,0,0,0,250,210,37,57,84,248,220,107,87,7,0,0,0,240,61,101,51,0,0,0,0,160,79,135,10,159,185,113,109,0,0,0,0,223,83,54,3,0,0,0,0,
250,244,165,194,103,94,187,54,0,0,0,128,239,41,155,1,0,0,0,0,125,106,43,124,230,191,184,54,0,0,0,128,239,41,155,1,0,0,0,0,125,58,84,248,204,107,215,6,0,0,0,240,61,101,51,0,0,0,0,160,79,109,133,207,220,
184,54,0,0,0,128,239,41,155,1,0,0,0,0,125,107,43,123,222,181,43,3,0,0,0,248,158,178,25,0,0,0,0,208,183,131,8,0,0,0,0,234,167,108,6,0,0,0,0,244,237,215,10,159,121,227,218,0,0,0,0,190,165,108,6,0,0,0,0,
244,173,21,1,0,0,0,64,253,148,205,0,0,0,0,128,190,29,42,124,230,181,107,3,0,0,0,248,150,178,25,0,0,0,0,208,183,182,194,103,110,92,27,0,0,0,192,183,148,205,0,0,0,0,128,33,180,149,61,239,95,93,25,0,0,0,
192,183,148,205,0,0,0,0,128,33,116,149,61,239,202,149,1,0,0,0,124,75,217,12,0,0,0,0,24,194,23,17,0,0,0,0,212,77,217,12,0,0,0,0,24,66,87,217,243,110,92,25,0,0,0,192,183,148,205,0,0,0,0,128,33,180,34,0,
0,0,0,168,155,178,25,0,0,0,0,48,132,67,133,207,220,184,54,0,0,0,128,175,148,205,0,0,0,0,128,33,28,42,124,230,181,107,3,0,0,0,248,74,217,12,0,0,0,0,24,74,43,2,0,0,0,128,122,41,155,1,0,0,0,0,67,233,42,123,
222,198,149,1,0,0,0,124,165,108,6,0,0,0,0,12,229,75,101,207,187,118,101,0,0,0,0,95,41,155,1,0,0,0,0,0,0,0,0,240,40,101,51,0,0,0,0,96,40,251,202,158,247,47,174,12,0,0,0,224,43,101,51,0,0,0,0,128,251,173,
69,0,0,0,0,240,149,178,25,0,0,0,0,48,148,189,8,0,0,0,0,234,165,108,6,0,0,0,0,0,0,0,0,192,163,148,205,0,0,0,0,128,33,237,43,122,214,181,235,2,0,0,0,248,74,217,12,0,0,0,0,224,126,141,8,0,0,0,0,190,82,54,
3,0,0,0,0,134,212,138,0,0,0,0,160,78,202,102,0,0,0,0,192,144,254,43,2,0,0,0,128,58,41,155,1,0,0,0,0,67,58,84,246,188,27,87,6,0,0,0,80,40,155,1,0,0,0,0,67,58,136,0,0,0,0,160,78,202,102,0,0,0,0,0,0,0,0,
0,60,74,217,12,0,0,0,0,24,210,94,4,0,0,0,0,117,82,54,3,0,0,0,0,120,216,90,4,0,0,0,0,133,178,25,0,0,0,0,48,180,182,162,103,109,92,23,0,0,0,64,161,108,6,0,0,0,0,12,173,19,1,0,0,0,64,125,148,205,0,0,0,0,
0,0,0,0,0,120,148,178,25,0,0,0,0,48,180,47,34,0,0,0,0,168,143,178,25,0,0,0,0,192,195,254,34,2,0,0,0,128,66,217,12,0,0,0,0,24,218,161,162,103,93,187,46,0,0,0,128,66,217,12,0,0,0,0,24,218,65,4,0,0,0,0,245,
81,54,3,0,0,0,0,0,0,0,0,224,81,202,102,0,0,0,0,192,208,14,34,0,0,0,0,168,143,178,25,0,0,0,0,48,180,131,8,0,0,0,0,234,163,108,6,0,0,0,0,0,0,0,0,192,163,148,205,0,0,0,0,128,49,28,68,0,0,0,0,80,23,101,51,
0,0,0,0,96,12,135,74,158,115,237,170,0,0,0,0,10,101,51,0,0,0,0,128,135,53,34,0,0,0,0,40,148,205,0,0,0,0,128,49,116,34,0,0,0,0,168,139,178,25,0,0,0,0,48,134,95,69,0,0,0,0,80,23,101,51,0,0,0,0,0,0,0,0,0,
30,165,108,6,0,0,0,0,0,0,0,0,192,163,148,205,0,0,0,0,128,49,236,69,0,0,0,0,80,23,101,51,0,0,0,0,0,0,0,0,0,30,165,108,6,0,0,0,0,0,0,0,0,192,163,148,205,0,0,0,0,128,49,28,68,0,0,0,0,80,23,101,51,0,0,0,0,
96,12,7,17,0,0,0,0,212,69,217,12,0,0,0,0,0,0,0,0,128,71,41,155,1,0,0,0,0,0,0,0,0,240,40,101,51,0,0,0,0,96,44,7,17,0,0,0,0,212,67,217,12,0,0,0,0,24,203,65,4,0,0,0,0,245,80,54,3,0,0,0,0,0,0,0,0,224,81,202,
102,0,0,0,0,0,0,0,0,0,60,74,217,12,0,0,0,0,24,203,65,4,0,0,0,0,245,80,54,3,0,0,0,0,198,242,31,17,0,0,0,0,212,67,217,12,0,0,0,0,0,0,0,0,128,71,41,155,1,0,0,0,0,0,0,0,0,240,40,101,51,0,0,0,0,0,0,0,0,0,30,
165,108,6,0,0,0,0,140,101,47,2,0,0,0,128,122,40,155,1,0,0,0,0,0,0,0,0,240,40,101,51,0,0,0,0,0,0,0,0,0,30,165,108,6,0,0,0,0,0,0,0,0,192,163,148,205,0,0,0,0,128,177,116,34,0,0,0,0,168,135,178,25,0,0,0,0,
48,150,182,130,103,236,92,19,0,0,0,64,161,108,6,0,0,0,0,240,176,86,4,0,0,0,0,133,178,25,0,0,0,0,0,0,0,0,0,143,82,54,3,0,0,0,0,0,0,0,0,224,81,202,102,0,0,0,0,192,152,58,17,0,0,0,0,212,65,217,12,0,0,0,0,
24,83,43,2,0,0,0,128,58,40,155,1,0,0,0,0,0,0,0,0,240,40,101,51,0,0,0,0,0,0,0,0,0,30,165,108,6,0,0,0,0,0,0,0,0,192,163,148,205,0,0,0,0,0,30,246,69,4,0,0,0,0,133,178,25,0,0,0,0,48,166,131,8,0,0,0,0,234,
160,108,6,0,0,0,0,140,233,63,34,0,0,0,0,168,131,178,25,0,0,0,0,0,0,0,0,0,143,82,54,3,0,0,0,0,0,0,0,0,224,81,202,102,0,0,0,0,0,0,0,0,0,60,74,217,12,0,0,0,0,224,97,173,8,0,0,0,0,10,101,51,0,0,0,0,96,76,
237,196,159,175,115,69,0,0,0,0,133,178,25,0,0,0,0,48,166,78,4,0,0,0,0,117,80,54,3,0,0,0,0,0,0,0,0,224,81,202,102,0,0,0,0,0,0,0,0,0,60,74,217,12,0,0,0,0,224,97,123,17,0,0,0,0,20,202,102,0,0,0,0,0,0,0,0,
0,60,74,217,12,0,0,0,0,24,83,39,2,0,0,0,128,58,252,159,8,0,0,96,57,94,189,122,37,4,0,96,106,218,41,63,220,111,191,253,230,134,0,0,0,0,238,152,108,6,0,0,0,0,112,191,131,8,0,0,0,0,190,82,54,3,0,0,0,0,184,
223,65,4,0,0,0,0,95,41,155,1,0,0,0,0,0,0,0,0,240,40,101,51,0,0,0,0,0,0,0,0,0,30,165,108,6,0,0,0,0,112,191,86,4,0,0,0,0,95,41,155,1,0,0,0,0,220,239,191,34,0,0,0,0,248,74,217,12,0,0,0,0,0,0,0,0,128,71,41,
155,1,0,0,0,0,220,175,19,1,0,0,0,192,87,202,102,0,0,0,0,0,247,107,69,0,0,0,0,240,149,178,25,0,0,0,0,0,0,0,0,0,143,82,54,3,0,0,0,0,0,0,0,0,224,81,202,102,0,0,0,0,0,247,219,139,0,0,0,0,224,43,101,51,0,0,
0,128,255,207,222,221,94,57,113,108,109,3,190,197,242,255,167,79,4,150,35,176,28,129,69,4,30,71,224,33,2,15,17,128,35,0,34,96,28,1,227,8,16,17,160,19,1,58,17,160,55,2,189,63,90,179,6,204,71,207,71,171,
187,170,251,186,214,154,53,120,14,160,98,215,184,84,109,238,179,55,0,0,0,0,0,157,132,205,0,0,0,0,0,0,0,0,0,232,36,108,6,0,0,0,0,240,165,173,18,0,0,0,0,124,78,216,12,0,0,0,0,224,75,123,37,0,0,0,0,248,156,
176,25,0,0,0,0,0,0,0,0,0,157,132,205,0,0,0,0,0,190,244,78,9,0,0,0,0,62,39,108,6,0,0,0,0,140,169,81,2,0,0,0,128,58,8,155,1,0,0,0,0,99,90,21,186,174,189,173,1,0,0,0,248,156,176,25,0,0,0,0,192,151,182,74,
0,0,0,0,240,57,97,51,0,0,0,0,0,0,0,0,0,58,9,155,1,0,0,0,0,124,105,167,4,0,0,0,0,159,19,54,3,0,0,0,0,248,210,78,9,0,0,0,0,62,39,108,6,0,0,0,0,140,105,165,4,0,0,0,0,117,16,54,3,0,0,0,0,198,212,20,184,166,
141,109,1,0,0,0,248,146,176,25,0,0,0,0,0,0,0,0,0,157,132,205,0,0,0,0,0,62,183,85,2,0,0,0,128,47,9,155,1,0,0,0,0,99,250,177,192,53,253,63,219,2,0,0,0,240,37,97,51,0,0,0,0,96,76,203,2,215,180,179,45,0,0,
0,0,95,18,54,3,0,0,0,0,248,220,78,9,0,0,0,0,190,36,108,6,0,0,0,0,240,185,189,18,0,0,0,0,124,73,216,12,0,0,0,0,24,211,186,192,53,109,109,11,0,0,0,192,151,132,205,0,0,0,0,0,0,0,0,0,232,36,108,6,0,0,0,0,
112,99,163,4,0,0,0,0,95,39,108,6,0,0,0,0,140,101,173,4,0,0,0,0,245,16,54,3,0,0,0,0,184,241,78,9,0,0,0,0,190,78,216,12,0,0,0,0,0,0,0,0,128,78,194,102,0,0,0,0,192,88,214,5,174,105,107,91,0,0,0,0,190,78,
216,12,0,0,0,0,224,198,94,9,0,0,0,0,190,78,216,12,0,0,0,0,24,203,143,5,174,105,99,91,0,0,0,0,190,78,216,12,0,0,0,0,24,203,82,9,0,0,0,0,234,33,108,6,0,0,0,0,208,218,40,1,0,0,0,192,183,9,155,1,0,0,0,0,99,
89,43,1,0,0,0,64,61,132,205,0,0,0,0,0,90,239,148,0,0,0,0,224,219,132,205,0,0,0,0,128,49,172,10,92,211,222,182,0,0,0,0,124,155,176,25,0,0,0,0,48,134,166,192,53,109,109,11,0,0,0,192,183,9,155,1,0,0,0,0,
99,88,22,184,166,157,109,1,0,0,0,248,54,97,51,0,0,0,0,96,12,203,2,215,180,179,45,0,0,0,0,223,38,108,6,0,0,0,0,140,225,199,194,214,179,181,37,0,0,0,0,223,39,108,6,0,0,0,0,140,97,89,216,122,246,182,4,0,
0,0,224,251,132,205,0,0,0,0,128,49,52,133,173,231,157,45,1,0,0,0,248,62,97,51,0,0,0,0,96,12,171,194,214,179,183,37,0,0,0,0,223,39,108,6,0,0,0,0,12,109,89,224,154,182,182,5,0,0,0,224,251,132,205,0,0,0,
0,128,161,45,11,92,211,214,182,0,0,0,0,124,159,176,25,0,0,0,0,48,180,101,129,107,218,219,22,0,0,0,128,239,19,54,3,0,0,0,0,134,182,44,108,61,27,91,2,0,0,0,208,77,216,12,0,0,0,0,24,218,207,133,173,103,103,
75,0,0,0,0,186,9,155,1,0,0,0,0,67,107,10,91,207,255,108,9,0,0,0,64,55,97,51,0,0,0,0,96,104,171,194,214,179,181,37,0,0,0,0,221,132,205,0,0,0,0,128,33,53,41,175,179,217,206,182,0,0,0,0,116,19,54,3,0,0,0,
0,134,180,42,112,77,91,219,2,0,0,0,208,77,216,12,0,0,0,0,24,210,178,176,245,108,109,9,0,0,0,192,237,8,155,1,0,0,0,0,67,90,22,182,158,157,45,1,0,0,0,184,29,97,51,0,0,0,0,96,72,63,23,182,158,255,218,18,
0,0,0,128,219,17,54,3,0,0,0,0,134,180,44,108,61,91,91,2,0,0,0,112,59,194,102,0,0,0,0,192,144,86,133,173,103,107,75,0,0,0,0,110,71,216,12,0,0,0,0,24,202,178,192,53,237,108,11,0,0,0,192,237,8,155,1,0,0,
0,0,67,89,22,182,158,141,45,1,0,0,0,184,61,97,51,0,0,0,0,96,40,235,194,214,179,179,37,0,0,0,0,183,39,108,6,0,0,0,0,12,229,199,194,214,243,95,91,2,0,0,0,112,123,194,102,0,0,0,0,192,80,150,133,173,103,107,
75,0,0,0,0,110,79,216,12,0,0,0,0,24,202,186,176,245,108,109,9,0,0,0,192,237,9,155,1,0,0,0,0,67,88,22,182,158,93,146,189,109,1,0,0,0,184,61,97,51,0,0,0,0,96,8,203,194,214,179,181,37,0,0,0,0,119,35,108,
6,0,0,0,0,12,97,93,216,122,254,107,75,0,0,0,0,238,70,216,12,0,0,0,0,24,194,207,133,173,103,107,75,0,0,0,0,238,70,216,12,0,0,0,0,24,194,178,176,245,108,109,9,0,0,0,192,221,8,155,1,0,0,0,0,67,88,21,180,
150,125,146,157,45,1,0,0,0,184,27,97,51,0,0,0,0,224,212,86,133,173,103,107,75,0,0,0,0,238,78,216,12,0,0,0,0,56,181,85,97,235,121,103,75,0,0,0,0,238,78,216,12,0,0,0,0,56,181,159,11,91,207,214,150,0,0,0,
0,220,157,176,25,0,0,0,0,112,106,171,194,214,179,181,37,0,0,0,0,119,39,108,6,0,0,0,0,156,218,170,160,181,236,147,236,108,9,0,0,0,192,221,9,155,1,0,0,0,0,167,180,76,210,20,180,158,173,45,1,0,0,0,184,31,
97,51,0,0,0,0,224,148,86,133,173,231,157,45,1,0,0,0,184,31,97,51,0,0,0,0,224,148,86,133,173,103,107,75,0,0,0,0,238,71,216,12,0,0,0,0,56,165,95,11,91,207,198,150,0,0,0,0,220,143,176,25,0,0,0,0,112,74,171,
130,214,178,75,178,183,37,0,0,0,0,247,35,108,6,0,0,0,0,156,202,50,73,83,208,122,182,182,4,0,0,0,224,254,132,205,0,0,0,0,128,83,89,21,182,158,119,182,4,0,0,0,224,254,132,205,0,0,0,0,128,83,89,21,182,158,
173,45,1,0,0,0,184,63,97,51,0,0,0,0,224,84,126,45,108,61,27,91,2,0,0,0,112,127,194,102,0,0,0,0,192,169,172,10,90,203,214,118,0,0,0,0,60,140,176,25,0,0,0,0,112,10,203,36,77,65,235,217,216,18,0,0,0,128,
135,17,54,3,0,0,0,0,78,97,85,216,122,222,217,18,0,0,0,128,135,17,54,3,0,0,0,0,78,225,215,194,214,179,181,37,0,0,0,0,15,35,108,6,0,0,0,0,156,194,170,160,181,236,142,31,0,0,0,0,60,128,176,25,0,0,0,0,112,
10,235,130,214,178,181,29,0,0,0,0,15,39,108,6,0,0,0,0,244,109,85,216,122,222,217,18,0,0,0,128,135,19,54,3,0,0,0,0,250,182,46,108,61,27,91,2,0,0,0,240,112,194,102,0,0,0,0,64,223,126,46,104,45,251,24,163,
9,0,0,0,208,11,97,51,0,0,0,0,160,111,235,130,214,178,181,29,0,0,0,0,253,16,54,3,0,0,0,0,250,212,36,89,22,180,158,119,182,4,0,0,0,160,31,194,102,0,0,0,0,64,159,214,133,173,103,99,75,0,0,0,0,250,33,108,
6,0,0,0,0,244,105,85,216,122,54,182,4,0,0,0,160,31,194,102,0,0,0,0,64,159,126,45,104,45,27,219,1,0,0,0,208,31,97,51,0,0,0,0,160,79,235,130,214,242,206,118,0,0,0,0,244,71,216,12,0,0,0,0,232,203,186,176,
245,108,108,9,0,0,0,64,127,132,205,0,0,0,0,128,190,172,10,91,207,198,150,0,0,0,0,244,71,216,12,0,0,0,0,232,203,175,5,173,101,99,59,0,0,0,0,250,37,108,6,0,0,0,0,244,101,93,208,90,222,217,14,0,0,0,128,126,
9,155,1,0,0,0,0,125,88,37,105,10,90,207,198,150,0,0,0,0,244,75,216,12,0,0,0,0,232,195,170,176,245,108,108,9,0,0,0,64,191,132,205,0,0,0,0,128,62,252,90,208,90,174,108,7,0,0,0,64,255,132,205,0,0,0,0,128,
62,172,11,90,203,59,219,1,0,0,0,208,63,97,51,0,0,0,0,224,161,150,199,143,82,108,108,9,0,0,0,64,255,132,205,0,0,0,0,128,135,90,23,180,150,125,146,173,45,1,0,0,0,232,159,176,25,0,0,0,0,240,80,191,22,180,
150,43,219,1,0,0,0,112,26,194,102,0,0,0,0,192,67,173,11,90,203,59,219,1,0,0,0,112,26,194,102,0,0,0,0,192,67,44,143,31,165,216,216,18,0,0,0,128,211,16,54,3,0,0,0,0,30,98,93,208,90,182,73,118,182,4,0,0,
0,224,52,132,205,0,0,0,0,128,135,248,181,160,181,108,108,7,0,0,0,192,233,8,155,1,0,0,0,0,15,177,46,104,45,239,108,7,0,0,0,192,233,8,155,1,0,0,0,0,247,181,60,126,148,226,202,150,0,0,0,0,156,142,176,25,
0,0,0,0,112,95,235,130,214,114,101,59,0,0,0,0,78,75,216,12,0,0,0,0,184,175,95,11,90,139,17,154,0,0,0,0,39,38,108,6,0,0,0,0,220,215,89,65,107,185,178,29,0,0,0,0,167,37,108,6,0,0,0,0,220,199,42,73,83,200,
90,118,199,15,0,0,0,0,78,72,216,12,0,0,0,0,184,143,117,65,107,185,178,29,0,0,0,0,167,39,108,6,0,0,0,0,220,199,175,5,173,229,157,237,0,0,0,0,56,61,97,51,0,0,0,0,224,62,206,10,90,203,149,237,0,0,0,0,56,
61,97,51,0,0,0,0,224,174,214,5,173,229,202,118,0,0,0,0,12,67,216,12,0,0,0,0,184,171,117,65,107,249,199,118,0,0,0,0,12,67,216,12,0,0,0,0,184,171,223,10,90,203,198,118,0,0,0,0,12,67,216,12,0,0,0,0,184,139,
38,201,170,144,181,108,147,236,108,9,0,0,0,192,48,132,205,0,0,0,0,128,187,88,23,180,150,141,237,0,0,0,0,24,142,176,25,0,0,0,0,112,23,37,141,208,252,219,118,0,0,0,0,12,71,216,12,0,0,0,0,184,139,117,33,
235,216,165,29,163,9,0,0,0,192,64,132,205,0,0,0,0,128,219,90,37,89,22,178,150,141,237,0,0,0,0,24,150,176,25,0,0,0,0,112,91,235,130,214,242,143,237,0,0,0,0,24,150,176,25,0,0,0,0,112,91,191,21,178,142,125,
146,43,219,1,0,0,0,48,44,97,51,0,0,0,0,224,54,154,148,211,217,236,202,118,0,0,0,0,12,79,216,12,0,0,0,0,184,141,117,65,107,121,103,59,0,0,0,0,134,39,108,6,0,0,0,0,220,198,111,5,173,229,202,118,0,0,0,0,
12,79,216,12,0,0,0,0,184,141,117,33,235,184,74,178,183,29,0,0,0,0,195,19,54,3,0,0,0,0,186,172,146,44,11,89,203,63,182,3,0,0,0,96,28,194,102,0,0,0,0,64,151,117,65,107,185,178,29,0,0,0,0,227,16,54,3,0,0,
0,0,186,252,86,200,58,174,98,132,38,0,0,0,192,104,132,205,0,0,0,0,128,239,105,82,78,103,51,35,52,1,0,0,0,70,36,108,6,0,0,0,0,124,207,89,65,107,185,178,29,0,0,0,0,227,17,54,3,0,0,0,0,190,231,215,66,214,
177,141,17,154,0,0,0,0,163,18,54,3,0,0,0,0,190,231,172,144,117,252,109,43,0,0,0,0,198,37,108,6,0,0,0,0,124,203,58,73,83,200,90,174,108,7,0,0,0,192,184,132,205,0,0,0,0,128,111,249,173,144,117,92,37,217,
217,14,0,0,0,128,113,9,155,1,0,0,0,0,223,114,86,200,58,254,177,21,0,0,0,0,227,19,54,3,0,0,0,0,190,102,121,252,40,193,149,237,0,0,0,0,24,159,176,25,0,0,0,0,240,53,103,133,172,227,42,201,222,118,0,0,0,0,
140,79,216,12,0,0,0,0,248,154,63,10,89,135,17,154,0,0,0,0,133,248,65,9,0,0,166,111,177,88,76,233,143,179,204,233,198,57,237,142,31,0,0,115,183,76,178,42,100,45,87,182,3,0,0,0,160,12,194,102,0,0,140,101,
125,252,188,204,77,120,236,255,242,249,95,106,174,146,52,5,173,121,159,100,251,149,175,111,147,252,191,127,125,109,115,139,95,7,0,80,250,93,109,108,87,49,66,19,0,0,0,160,24,194,102,0,0,156,194,42,109,
72,236,250,243,207,199,207,203,156,174,43,217,16,154,124,253,47,94,191,246,181,103,223,249,125,182,185,249,75,211,109,110,130,106,215,95,223,71,56,13,0,24,215,111,133,172,195,8,77,0,0,0,128,130,44,14,
135,131,42,0,0,76,253,210,119,154,49,154,171,220,132,175,126,204,205,168,165,70,197,123,181,77,27,62,219,37,249,95,110,130,104,215,159,25,206,243,124,63,68,88,164,195,225,176,176,117,0,220,241,222,216,
36,249,88,192,114,246,73,254,83,192,123,169,111,12,0,0,0,128,35,157,205,0,0,232,178,202,77,144,236,231,79,126,204,112,245,255,158,125,218,208,217,46,109,24,109,123,252,218,70,233,0,128,123,58,43,100,29,
87,182,2,0,0,0,160,44,194,102,0,0,124,106,157,207,67,101,107,37,41,94,243,157,125,218,167,13,159,109,115,19,68,219,230,102,132,39,0,192,215,252,90,200,58,140,208,4,0,0,0,40,140,176,25,0,192,124,173,210,
134,148,126,62,254,120,165,36,147,211,28,247,120,253,175,175,239,211,134,206,222,165,237,136,182,141,145,156,0,192,141,179,2,214,176,139,206,102,0,0,0,0,197,17,54,3,0,152,135,38,109,224,232,215,220,132,
204,240,253,240,239,239,131,77,218,208,217,127,35,128,6,0,115,117,118,188,43,140,237,202,86,0,0,0,0,148,71,216,12,0,102,104,177,88,40,194,244,45,115,19,46,91,31,255,25,186,172,243,121,0,109,159,155,14,
104,155,24,193,9,0,115,184,255,255,86,200,178,255,62,28,14,54,15,0,0,0,160,48,11,255,209,6,0,102,120,1,16,54,155,162,101,132,203,24,198,54,109,240,236,58,128,182,159,209,159,253,121,146,103,181,45,250,
112,56,56,244,1,220,255,239,242,211,63,102,252,206,102,219,36,191,248,239,150,0,0,0,0,229,209,217,12,0,160,78,203,8,151,49,142,213,241,227,226,248,207,219,180,161,179,127,142,159,1,128,122,157,165,140,
17,154,127,219,10,0,0,0,128,50,9,155,1,0,212,227,44,55,225,178,149,114,80,136,85,62,15,159,93,165,237,122,118,149,100,167,60,0,80,149,82,70,104,94,217,10,0,0,0,128,50,25,163,9,0,115,188,0,24,163,89,139,
101,110,2,102,103,202,65,133,118,105,255,178,248,239,180,29,208,106,247,60,198,104,2,48,237,251,127,9,35,52,175,146,252,126,124,15,179,121,0,0,0,0,133,209,217,12,0,160,44,235,180,29,37,206,98,52,38,245,
91,166,237,120,118,145,54,120,182,73,59,110,243,74,105,0,160,56,103,41,99,132,230,63,182,2,0,0,0,160,92,194,102,0,0,227,106,242,121,192,172,81,18,38,106,153,228,252,248,177,79,27,56,123,149,105,116,60,
3,128,41,40,97,132,230,62,201,165,173,0,0,0,0,40,151,176,25,0,192,240,154,180,193,178,235,128,25,204,241,223,129,243,227,199,46,55,193,179,157,210,0,192,104,74,184,151,94,217,6,0,0,0,128,178,61,82,2,0,
128,65,52,105,131,53,111,146,124,76,242,58,130,102,144,220,140,218,252,144,228,253,241,223,147,70,89,0,96,80,103,133,188,255,190,178,21,0,0,0,0,101,19,54,3,0,56,157,38,2,102,112,23,171,227,191,39,31,142,
159,87,74,2,0,131,40,97,132,230,46,198,107,3,0,0,0,20,79,216,12,0,160,95,77,4,204,160,175,127,143,222,39,121,123,252,49,0,112,58,37,220,87,117,53,3,0,0,0,168,128,176,25,0,64,63,206,210,6,203,4,204,160,
95,235,220,116,59,123,30,35,54,1,224,20,247,216,18,222,95,47,109,5,0,0,0,64,249,132,205,0,0,238,111,149,155,128,217,155,232,190,4,167,180,76,242,44,109,232,236,197,241,159,1,128,135,43,97,132,230,85,146,
189,173,0,0,0,0,40,159,176,25,0,192,221,44,147,92,164,13,188,188,79,27,48,107,148,5,6,211,124,242,239,224,235,8,157,1,192,67,157,21,176,134,191,109,3,0,0,0,64,29,132,205,0,0,110,231,60,109,247,50,93,149,
160,172,127,47,133,206,0,224,254,206,50,254,255,113,98,151,182,179,25,0,0,0,0,21,16,54,3,0,248,182,85,218,96,217,199,180,97,150,51,37,129,34,157,231,38,116,214,40,7,0,220,90,9,35,52,117,53,3,0,0,0,168,
136,176,25,0,192,231,154,180,193,149,247,199,143,139,8,175,64,45,206,211,134,206,158,251,247,22,0,110,117,239,61,43,96,29,151,182,2,0,0,0,160,30,194,102,0,0,173,85,218,174,72,215,221,145,86,74,2,85,106,
146,60,75,27,22,61,87,14,0,248,166,179,140,31,206,222,164,29,163,9,0,0,0,64,37,132,205,0,128,185,59,79,242,54,55,193,148,70,73,96,18,150,105,131,163,111,35,60,10,0,95,99,132,38,0,0,0,0,119,38,108,6,0,
204,209,50,237,152,189,143,105,195,40,107,37,129,201,90,167,13,147,190,136,48,41,0,92,107,50,254,8,205,125,140,208,4,0,0,0,168,142,176,25,0,48,39,235,220,140,202,124,22,193,19,152,147,139,227,191,251,
103,74,1,0,69,188,31,190,178,13,0,0,0,0,245,17,54,3,0,230,224,60,109,103,163,183,199,31,3,243,212,36,121,115,252,104,148,3,128,25,251,179,128,53,92,218,6,0,0,0,128,250,8,155,1,0,83,213,228,243,81,153,
43,37,1,142,206,162,203,25,0,243,181,44,224,110,124,149,100,103,43,0,0,0,0,234,35,108,6,0,76,205,50,109,184,236,99,140,202,4,190,173,73,219,225,236,181,115,2,128,153,57,43,96,13,127,219,6,0,0,0,128,58,
9,155,1,0,83,177,78,59,38,243,67,140,202,4,110,239,60,237,152,221,149,82,0,48,19,99,143,208,220,165,237,108,6,0,0,0,64,133,132,205,0,128,218,157,167,13,138,188,77,27,56,3,184,171,229,241,28,185,80,10,
0,38,110,117,124,223,27,147,174,102,0,0,0,0,21,19,54,3,0,106,117,158,182,139,217,235,232,72,4,244,227,69,140,213,4,96,218,254,40,96,13,47,109,3,0,0,0,64,189,132,205,0,128,154,52,73,158,39,249,152,54,16,
178,84,18,160,103,231,105,59,37,58,95,0,152,234,251,220,152,46,147,236,109,3,0,0,0,64,189,132,205,0,128,26,52,105,67,102,31,146,60,139,174,67,192,105,173,210,142,213,92,43,5,0,19,114,86,192,61,218,8,77,
0,0,0,128,202,9,155,1,0,37,107,34,100,6,140,119,254,188,205,248,29,96,0,160,47,191,141,252,250,219,36,27,219,0,0,0,0,80,183,31,148,0,0,40,80,147,228,34,201,159,17,48,3,198,117,61,178,247,185,82,0,80,249,
253,250,124,228,53,188,178,13,0,0,0,0,245,19,54,3,0,74,210,68,200,12,40,207,179,36,63,38,249,159,82,0,80,169,179,145,95,127,159,228,210,54,0,0,0,0,212,79,216,12,0,40,65,19,33,51,160,108,231,105,255,162,
28,0,106,244,231,200,175,127,105,11,0,0,0,0,166,97,113,56,28,84,1,0,230,118,1,88,44,74,89,74,19,33,51,128,147,58,28,14,11,85,0,152,213,29,251,223,150,73,62,140,188,134,159,146,236,238,241,30,230,27,11,
0,0,0,160,48,58,155,1,0,99,104,34,100,6,0,0,67,40,161,171,217,206,54,0,0,0,0,76,131,176,25,0,48,180,139,36,207,34,100,6,0,0,67,56,27,249,245,255,182,5,0,0,0,0,211,33,108,6,0,12,229,60,109,200,108,169,
20,0,0,48,136,179,145,239,223,219,36,27,219,0,0,0,0,48,29,194,102,0,192,169,173,147,188,142,144,25,0,0,12,237,143,145,95,255,149,45,0,0,0,0,152,150,197,225,112,80,5,0,152,219,5,96,177,24,226,101,214,105,
59,153,173,85,28,96,60,135,195,97,161,10,0,147,185,99,223,69,147,228,227,136,175,191,79,242,159,7,190,135,249,198,2,0,0,0,40,140,206,102,0,64,223,150,73,94,164,29,217,3,0,0,140,227,124,228,215,215,213,
12,0,0,0,96,130,116,54,3,128,57,94,0,78,211,117,161,73,219,201,236,66,133,1,202,161,179,25,64,213,119,236,135,248,144,113,71,217,255,39,109,119,179,135,188,135,249,198,2,0,0,0,40,140,206,102,0,64,31,158,
39,249,51,109,224,12,0,0,24,215,58,227,6,205,46,243,192,160,25,0,0,0,0,101,18,54,3,0,30,226,44,237,200,204,165,82,0,0,64,49,254,24,249,245,255,178,5,0,0,0,0,211,100,140,38,0,204,241,2,240,240,17,63,171,
180,33,179,181,106,2,148,205,24,77,128,106,238,216,125,105,146,124,28,241,245,175,146,252,222,211,123,152,111,44,0,0,0,128,194,60,82,2,0,224,14,154,180,33,179,247,17,52,3,0,128,18,157,143,252,250,175,
108,1,0,0,0,192,116,233,108,6,0,115,188,0,220,175,235,194,69,146,103,105,3,103,0,84,66,103,51,128,162,239,216,167,240,33,227,141,185,223,38,249,165,199,247,48,223,88,0,0,0,0,133,249,65,9,0,128,14,235,
180,221,204,86,74,1,0,0,197,223,221,151,35,190,190,174,102,0,0,0,0,19,39,108,6,0,124,75,147,54,100,118,174,20,0,0,80,133,63,70,124,237,93,146,75,91,0,0,0,0,48,109,198,104,2,192,28,47,0,221,35,126,46,98,
100,38,192,36,24,163,9,80,204,29,251,212,154,36,31,71,124,253,39,233,57,108,230,191,91,2,0,0,0,148,71,103,51,0,224,83,235,24,153,9,0,0,53,58,31,241,181,247,73,174,108,1,0,0,0,192,244,9,155,1,0,137,145,
153,0,0,80,187,63,71,124,237,87,105,3,103,0,0,0,0,76,156,49,154,0,48,199,11,192,231,35,126,206,211,6,205,26,149,1,152,30,99,52,1,70,185,99,15,109,157,228,237,72,175,189,79,242,83,78,16,54,243,223,45,1,
0,0,0,202,163,179,25,0,204,215,50,201,235,180,127,49,5,0,0,212,235,143,17,95,251,50,186,154,1,0,0,0,204,134,206,102,0,48,199,11,192,98,241,60,201,51,149,0,152,62,157,205,0,6,187,99,143,245,210,203,36,
31,70,252,163,255,148,100,119,162,247,48,223,88,0,0,0,0,133,209,217,12,96,34,70,30,217,66,61,214,105,71,102,174,148,2,0,0,38,225,124,196,215,190,204,137,130,102,0,0,0,0,148,73,103,51,128,169,28,232,194,
102,124,95,147,182,147,217,133,82,0,204,139,206,102,0,147,127,38,251,144,182,187,217,24,78,214,213,236,248,30,230,27,11,0,0,0,160,48,58,155,1,192,244,173,147,188,206,120,127,1,5,0,0,156,198,249,136,247,
252,203,232,106,6,0,0,0,48,59,194,102,0,48,93,77,218,144,217,153,82,0,0,192,36,253,49,226,107,191,82,126,0,0,0,128,249,49,70,19,96,42,7,186,49,154,124,238,44,109,208,172,81,10,128,121,51,70,19,96,178,
207,100,171,36,239,71,250,227,110,146,60,30,224,61,204,55,22,0,0,0,64,97,116,54,3,128,105,105,162,155,25,0,0,204,193,159,35,190,246,95,202,15,0,0,0,48,79,58,155,1,76,229,64,215,217,12,221,204,0,248,10,
157,205,0,38,249,76,214,36,249,56,210,31,117,147,1,186,154,29,223,195,124,99,1,0,0,0,20,70,103,51,0,168,95,19,221,204,0,0,96,78,46,70,124,109,93,205,0,0,0,0,102,76,103,51,128,169,28,232,58,155,205,213,
58,109,208,108,169,20,0,124,141,206,102,0,147,124,38,251,48,210,51,192,38,3,117,53,59,190,135,249,198,2,0,0,0,40,204,35,37,0,128,42,53,73,94,36,121,27,65,51,0,0,152,147,243,17,159,1,116,53,3,0,0,0,152,
57,157,205,0,166,114,160,235,108,54,39,171,36,111,34,100,6,192,45,232,108,6,48,185,103,178,247,199,103,130,161,109,50,96,87,179,227,123,152,111,44,0,0,0,128,194,232,108,6,0,117,121,158,246,47,151,150,
74,1,0,0,179,179,206,56,65,179,68,87,51,0,0,0,0,146,252,160,4,0,80,133,101,218,110,102,43,165,0,0,128,217,250,115,164,215,221,28,63,0,0,0,0,152,57,99,52,1,166,114,160,27,163,57,101,231,73,94,36,105,148,
2,128,187,50,70,19,96,50,207,100,203,36,31,70,250,227,61,206,8,97,51,255,221,18,0,0,0,160,60,58,155,1,64,185,154,36,175,147,156,41,5,0,0,204,222,179,145,94,119,19,93,205,0,0,0,0,56,210,217,12,96,42,7,
186,206,102,83,179,78,27,52,91,42,5,0,15,161,179,25,192,36,158,201,154,180,93,205,154,17,254,104,163,116,53,59,190,135,249,198,2,0,0,0,40,204,35,37,0,128,226,60,79,242,54,130,102,0,0,64,235,34,227,4,205,
54,209,213,12,0,0,0,128,79,232,108,6,48,149,3,93,103,179,41,104,146,188,73,219,213,12,0,122,161,179,25,192,36,158,201,62,102,102,93,205,142,239,97,190,177,0,0,0,0,10,163,179,25,0,148,225,44,237,88,156,
181,82,0,0,0,159,56,143,174,102,0,0,0,0,20,66,103,51,128,169,28,232,58,155,213,236,69,218,177,56,0,208,59,157,205,0,170,127,38,251,144,100,57,194,31,105,212,174,102,199,247,48,223,88,0,0,0,0,133,249,65,
9,0,96,52,203,180,99,51,87,74,1,0,0,124,197,121,198,9,154,109,162,171,25,0,0,0,0,95,161,179,25,192,84,14,116,157,205,106,115,150,228,117,198,25,135,3,192,140,232,108,6,80,245,51,217,251,140,243,127,78,
25,189,171,217,241,61,204,55,22,0,0,0,64,97,30,41,1,0,12,238,121,218,142,102,141,82,0,0,0,223,176,206,56,65,179,171,232,106,6,0,0,0,192,55,232,108,6,48,149,3,93,103,179,26,52,105,67,102,107,165,0,96,40,
58,155,1,84,251,76,246,118,164,103,135,159,146,236,10,121,15,243,141,5,0,0,0,80,152,31,148,0,0,6,177,74,251,151,69,141,82,0,0,0,29,214,25,39,104,118,153,66,130,102,0,0,0,0,148,73,103,51,128,169,28,232,
58,155,149,236,34,201,11,101,0,96,12,58,155,1,84,249,76,54,251,174,102,199,247,48,223,88,0,0,0,0,133,209,217,12,0,78,167,73,27,50,59,87,10,0,0,224,150,214,209,213,12,0,0,0,128,66,9,155,1,192,105,44,147,
188,73,59,62,19,0,0,224,182,254,24,225,53,247,73,158,42,61,0,0,0,0,93,30,41,1,0,244,110,157,228,125,4,205,0,0,128,187,89,102,156,206,200,175,210,6,206,0,0,0,0,224,187,132,205,0,160,95,23,73,222,166,29,
161,9,0,0,112,23,207,70,120,205,125,146,151,74,15,0,0,0,192,109,24,163,9,0,253,104,146,188,200,56,93,8,0,0,128,250,45,163,171,25,0,0,0,0,133,91,28,14,7,85,0,152,194,129,190,88,40,194,120,150,73,222,196,
216,76,0,10,116,56,28,92,18,0,234,120,38,123,157,225,195,102,187,36,63,21,252,30,230,27,11,0,0,0,160,48,194,102,0,83,57,208,133,205,198,178,78,27,52,107,148,2,128,18,9,155,1,84,241,76,182,76,242,97,132,
101,63,73,114,89,240,123,152,111,44,0,0,0,128,194,60,82,2,0,184,183,139,36,111,35,104,6,0,0,60,204,179,17,94,115,155,130,131,102,0,0,0,0,148,73,103,51,128,169,28,232,58,155,13,169,73,242,34,195,143,184,
1,128,59,211,217,12,160,248,103,178,101,198,233,106,246,56,201,166,240,247,48,223,88,0,0,0,0,133,249,65,9,0,224,78,154,180,221,204,86,74,1,0,0,244,224,245,8,175,185,73,225,65,51,0,0,0,0,202,164,179,25,
192,84,14,116,157,205,134,176,138,177,153,0,84,70,103,51,128,162,159,201,214,199,103,140,161,253,146,118,140,102,233,239,97,190,177,0,0,0,0,10,243,72,9,0,224,86,206,147,188,143,160,25,0,0,208,159,103,
35,188,230,101,42,8,154,1,0,0,0,80,38,157,205,0,166,114,160,235,108,118,74,47,146,92,40,3,0,53,210,217,12,160,216,103,178,117,134,239,106,182,79,219,213,108,87,201,123,152,111,44,0,0,0,128,194,252,160,
4,0,240,77,77,146,215,73,206,148,2,0,0,232,217,24,93,205,94,165,146,160,25,0,0,0,0,101,210,217,12,96,42,7,186,206,102,125,107,210,118,25,88,41,5,0,53,211,217,12,160,200,103,178,179,36,111,6,94,226,62,
201,79,199,207,181,188,135,249,198,2,0,0,0,40,204,35,37,0,128,47,172,146,124,136,160,25,0,0,112,26,47,70,120,205,167,169,40,104,6,0,0,0,64,153,132,205,0,224,115,103,105,59,154,53,74,1,0,0,156,192,121,
146,229,192,175,185,77,114,169,244,0,0,0,0,60,148,49,154,0,83,57,208,141,209,236,195,121,146,215,202,0,192,148,24,163,9,80,212,51,89,147,182,139,114,51,240,242,30,39,217,84,248,30,230,27,11,0,0,0,160,
48,63,40,1,0,36,105,67,102,231,202,0,0,0,156,208,69,134,15,154,109,14,135,195,70,233,1,0,0,0,232,131,206,102,0,83,57,208,117,54,187,175,38,201,139,8,154,1,48,81,58,155,1,20,243,76,182,76,242,62,195,135,
205,126,58,28,14,59,59,4,0,0,0,64,31,116,54,3,96,206,154,36,111,147,172,148,2,0,0,56,177,103,25,62,104,246,50,201,78,233,1,0,0,0,232,139,206,102,0,83,57,208,117,54,187,171,101,146,55,17,52,3,96,226,116,
54,3,40,226,153,108,149,182,171,217,144,246,73,126,74,178,247,223,255,0,0,0,0,232,139,206,102,0,204,209,42,109,71,179,70,41,0,0,128,1,188,24,225,53,255,74,27,56,3,0,0,0,128,222,232,108,6,48,149,3,93,103,
179,219,90,69,208,12,128,25,209,217,12,96,244,103,178,179,180,93,149,135,180,77,242,203,39,239,5,54,8,0,0,0,128,94,60,82,2,0,102,228,60,237,232,154,70,41,0,0,128,1,52,25,167,171,217,83,165,7,0,0,0,224,
20,132,205,0,152,139,243,36,175,149,1,0,0,24,208,69,146,229,192,175,121,149,100,163,244,0,0,0,0,156,130,49,154,0,83,57,208,141,209,252,158,139,140,211,77,0,0,70,103,140,38,192,104,207,100,203,36,31,6,
94,198,62,237,248,204,221,191,222,11,108,16,0,0,0,0,189,248,65,9,0,152,184,215,105,187,154,1,0,0,12,253,44,50,180,87,249,87,208,12,0,0,0,0,250,164,179,25,192,84,14,116,157,205,190,70,208,12,128,217,211,
217,12,96,148,103,178,179,36,111,6,94,194,46,109,87,179,253,87,222,11,108,16,0,0,0,0,189,16,54,3,152,202,129,46,108,246,111,130,102,0,16,97,51,128,17,158,201,154,36,239,211,142,209,28,210,239,73,174,190,
241,94,96,131,0,0,0,0,232,197,35,37,0,96,98,154,180,29,4,206,149,2,0,0,24,193,179,12,31,52,219,228,27,65,51,0,0,0,0,232,147,206,102,0,83,57,208,117,54,75,218,160,217,219,36,43,165,0,128,150,206,102,0,
131,62,147,173,210,118,53,27,218,79,105,199,104,126,235,189,192,6,1,0,0,0,208,11,157,205,0,152,138,38,130,102,0,0,192,184,94,143,240,154,127,229,59,65,51,0,0,0,0,232,147,176,25,0,83,208,68,208,12,0,0,
24,215,243,17,158,73,118,73,94,42,61,0,0,0,0,67,249,65,9,0,168,92,19,65,51,0,0,96,124,251,180,93,198,134,180,57,190,46,0,0,0,0,12,98,113,56,28,84,1,96,10,7,250,98,49,199,63,118,19,65,51,0,248,174,195,
225,176,80,5,0,0,0,0,0,160,15,194,102,0,83,57,208,231,23,54,107,34,104,6,0,157,132,205,0,0,0,0,0,128,190,8,155,1,76,229,64,159,87,216,172,137,160,25,0,220,138,176,25,0,0,0,0,0,208,23,97,51,128,169,28,
232,243,9,155,53,17,52,3,128,91,19,54,3,0,0,0,0,0,250,34,108,6,48,149,3,125,30,97,179,38,130,102,0,112,39,194,102,0,0,0,0,0,64,95,132,205,0,166,114,160,79,63,108,214,68,208,12,0,238,76,216,12,0,0,0,0,
0,232,139,176,25,192,84,14,244,105,135,205,154,8,154,1,192,189,8,155,1,0,0,0,0,0,125,17,54,3,152,202,129,62,221,176,89,19,65,51,0,184,55,97,51,0,0,0,0,0,160,47,194,102,0,83,57,208,167,25,54,107,34,104,
6,0,15,34,108,6,0,0,0,0,0,244,69,216,12,96,42,7,250,52,195,102,111,146,156,217,93,0,184,63,97,51,0,0,0,0,0,160,47,194,102,0,83,57,208,167,23,54,123,157,228,220,206,2,192,195,8,155,1,0,0,0,0,0,125,17,54,
3,152,202,129,62,173,176,153,160,25,0,244,68,216,12,0,0,0,0,0,232,139,176,25,192,84,14,244,233,132,205,4,205,0,160,71,194,102,0,0,0,0,0,64,95,132,205,0,166,114,160,79,35,108,118,145,228,133,221,4,128,
254,8,155,1,0,0,0,0,0,125,17,54,3,152,202,129,94,127,216,236,60,109,87,51,0,160,71,194,102,0,0,0,0,0,64,95,132,205,0,166,114,160,215,29,54,59,143,160,25,0,156,132,176,25,0,0,0,0,0,208,23,97,51,128,169,
28,232,245,134,205,86,73,222,38,105,236,34,0,244,79,216,12,0,0,0,0,0,232,139,176,25,192,84,14,244,58,195,102,171,8,154,1,192,73,9,155,1,0,0,0,0,0,125,17,54,3,152,202,129,94,95,216,172,73,242,33,130,102,
0,112,82,194,102,0,0,0,0,0,64,95,30,41,1,0,35,104,162,163,25,0,0,0,0,0,0,0,84,69,103,51,128,169,28,232,117,117,54,123,159,118,132,38,0,112,98,58,155,1,0,0,0,0,0,125,209,217,12,128,161,189,142,160,25,0,
0,0,0,0,0,0,84,71,216,12,128,33,61,79,114,174,12,0,0,0,0,0,0,0,80,31,99,52,1,166,114,160,151,63,70,243,60,109,87,51,0,96,64,198,104,2,0,0,0,0,0,125,17,54,3,152,202,129,94,118,216,108,149,228,189,93,2,
128,225,9,155,1,0,0,0,0,0,125,17,54,3,152,202,129,94,110,216,108,149,228,109,146,198,46,1,192,240,132,205,0,0,0,0,0,128,190,8,155,1,76,229,64,47,51,108,214,164,13,154,173,236,16,0,140,67,216,12,0,0,0,
0,0,232,139,176,25,192,84,14,244,50,195,102,111,147,172,237,14,0,140,71,216,12,0,0,0,0,0,232,203,35,37,0,224,68,94,71,208,12,0,0,0,0,0,0,0,38,67,103,51,128,169,28,232,101,117,54,59,79,27,54,3,0,70,166,
179,25,0,0,0,0,0,208,23,97,51,128,169,28,232,229,132,205,86,73,222,219,17,0,40,131,176,25,0,0,0,0,0,208,23,97,51,128,169,28,232,101,132,205,154,36,31,142,159,1,128,2,8,155,1,0,0,0,0,0,125,17,54,3,152,
202,129,94,70,216,236,125,218,206,102,0,64,33,132,205,0,0,0,0,0,128,190,60,82,2,0,122,242,58,130,102,0,0,0,0,0,0,0,48,89,58,155,1,76,229,64,31,183,179,217,121,218,176,25,0,80,24,157,205,0,0,0,0,0,128,
190,8,155,1,76,229,64,31,47,108,182,74,59,62,19,0,40,144,176,25,0,0,0,0,0,208,23,97,51,128,169,28,232,227,132,205,154,36,31,142,159,1,128,2,9,155,1,0,0,0,0,0,125,121,164,4,0,60,192,155,8,154,1,0,0,0,0,
0,0,192,44,8,155,1,112,95,207,147,172,149,1,0,0,0,0,0,0,0,230,193,24,77,128,169,28,232,195,142,209,92,39,121,171,234,0,80,62,99,52,1,0,0,0,0,128,190,8,155,1,76,229,64,31,46,108,214,36,249,16,227,51,1,
160,10,194,102,0,0,0,0,0,64,95,140,209,4,224,174,222,68,208,12,0,0,0,0,0,0,0,102,71,216,12,128,187,120,158,118,132,38,0,80,135,173,18,0,0,0,0,0,0,125,17,54,3,224,182,214,73,158,41,3,0,84,101,175,4,0,0,
0,0,0,64,95,132,205,0,184,141,38,237,248,76,0,0,0,0,0,0,0,96,166,132,205,0,184,141,215,105,3,103,0,0,0,0,0,0,0,192,76,9,155,1,208,229,34,201,153,50,0,0,0,0,0,0,0,192,188,9,155,1,240,61,171,36,47,148,1,
0,170,245,78,9,0,0,0,0,0,128,190,8,155,1,240,61,175,149,0,0,0,0,0,0,0,0,72,132,205,0,248,182,23,105,59,155,1,0,0,0,0,0,0,0,8,155,1,240,85,235,36,23,202,0,0,213,219,41,1,0,0,0,0,0,208,23,97,51,0,254,173,
137,241,153,0,48,21,59,37,0,0,0,0,0,0,250,34,108,6,192,191,189,72,178,84,6,0,0,0,0,0,0,0,224,83,139,195,225,160,10,0,83,56,208,23,139,62,126,155,179,36,111,84,19,0,38,227,63,135,195,97,175,12,0,0,0,0,
0,64,31,132,205,0,166,114,160,63,60,108,214,36,249,112,252,12,0,120,230,3,0,0,0,0,0,248,140,49,154,0,92,123,29,65,51,0,152,146,189,18,0,0,0,0,0,0,125,18,54,3,32,105,199,103,158,41,3,0,76,202,86,9,0,0,
0,0,0,128,62,9,155,1,208,164,237,106,6,0,0,0,0,0,0,0,240,77,194,102,0,60,139,241,153,0,48,69,239,148,0,0,0,0,0,0,232,147,176,25,192,188,173,147,92,40,3,0,0,0,0,0,0,0,208,69,216,12,96,190,154,24,159,9,
0,83,182,81,2,0,0,0,0,0,160,79,194,102,0,243,117,145,100,169,12,0,0,0,0,0,0,0,192,109,44,14,135,131,42,0,76,225,64,95,44,238,242,211,87,73,222,171,26,0,76,251,122,144,36,158,249,0,0,0,0,0,128,190,232,
108,6,48,79,47,148,0,0,38,109,175,4,0,0,0,0,0,64,223,132,205,0,230,231,34,201,90,25,0,96,210,182,74,0,0,0,0,0,0,244,77,216,12,96,94,154,36,207,148,1,0,38,111,167,4,0,0,0,0,0,64,223,132,205,0,230,229,69,
218,192,25,0,48,109,255,83,2,0,0,0,0,0,160,111,194,102,0,243,177,78,114,174,12,0,48,11,27,37,0,0,0,0,0,0,250,182,56,28,14,170,0,48,133,3,125,177,232,250,41,239,147,172,84,10,0,102,225,167,28,71,105,122,
230,3,0,0,0,0,0,250,34,108,6,48,149,3,253,251,97,179,243,36,175,85,9,0,230,115,53,184,254,129,103,62,0,0,0,0,0,160,47,194,102,0,83,57,208,191,29,54,107,146,124,56,126,6,0,166,111,147,228,241,245,63,120,
230,3,0,0,0,0,0,250,242,72,9,0,38,239,89,4,205,0,96,78,182,74,0,0,0,0,0,0,156,130,176,25,192,180,45,147,92,40,3,0,204,202,255,148,0,0,0,0,0,0,56,5,97,51,128,105,123,161,4,0,48,59,91,37,0,0,0,0,0,0,78,
97,113,56,28,84,1,96,10,7,250,98,241,239,47,173,147,188,85,25,0,152,223,181,224,211,127,240,204,7,0,0,0,0,0,244,69,103,51,128,233,210,213,12,0,230,103,171,4,0,0,0,0,0,192,169,8,155,1,76,211,121,146,149,
50,0,192,236,108,149,0,0,0,0,0,0,56,21,97,51,128,105,122,166,4,0,48,75,239,148,0,0,0,0,0,0,56,21,97,51,128,233,185,72,178,84,6,0,152,165,173,18,0,0,0,0,0,0,167,178,56,28,14,170,0,48,133,3,125,177,72,146,
38,201,135,227,103,0,96,134,87,130,127,127,193,51,31,0,0,0,0,0,208,23,157,205,0,166,229,34,130,102,0,48,87,27,37,0,0,0,0,0,0,78,73,216,12,96,58,154,36,127,42,3,0,204,214,59,37,0,0,0,0,0,0,78,73,216,12,
96,58,46,162,171,25,0,204,217,70,9,0,0,0,0,0,128,83,90,28,14,7,85,0,168,241,0,95,44,62,253,199,38,201,135,8,155,1,192,108,29,14,135,133,42,0,0,0,0,0,0,167,164,179,25,192,52,92,68,208,12,0,230,108,163,
4,0,0,0,0,0,192,169,9,155,1,212,175,73,242,167,50,0,192,172,189,83,2,0,0,0,0,0,224,212,132,205,0,234,119,17,93,205,0,96,238,54,74,0,0,0,0,0,0,156,218,226,112,56,168,2,64,141,7,248,98,145,180,33,179,15,
17,54,3,0,207,118,158,237,0,0,0,0,0,128,19,211,217,12,160,110,23,17,52,3,128,185,219,40,1,0,0,0,0,0,48,4,97,51,128,122,53,73,254,84,6,0,152,189,127,148,0,0,0,0,0,0,24,130,176,25,64,189,46,162,171,25,0,
160,179,25,0,0,0,0,0,48,144,197,225,112,80,5,128,26,15,240,197,226,99,132,205,0,96,238,246,73,254,147,36,158,237,0,0,0,0,0,128,83,251,65,9,0,134,179,88,44,250,250,173,206,35,104,6,0,36,87,74,0,0,0,0,0,
0,12,69,103,51,128,33,15,221,254,194,102,31,146,44,85,20,0,102,239,247,28,3,103,158,237,0,0,0,0,0,128,83,19,54,3,24,242,208,237,39,108,118,150,228,141,106,2,0,105,71,104,238,19,97,51,0,0,0,0,0,224,244,
30,41,1,64,117,254,84,2,0,32,201,38,199,160,25,0,0,0,0,0,192,16,132,205,0,234,178,74,178,86,6,0,32,201,63,74,0,0,0,0,0,0,12,73,216,12,160,46,186,154,1,0,215,174,148,0,0,0,0,0,0,24,210,226,112,56,168,2,
192,80,135,238,98,241,144,95,222,36,249,168,138,0,64,146,109,146,95,62,253,130,103,59,0,0,0,0,0,224,212,116,54,3,168,199,133,18,0,0,71,127,43,1,0,0,0,0,0,48,52,157,205,0,134,60,116,31,214,217,236,67,146,
165,42,2,0,73,126,74,178,251,244,11,158,237,0,0,0,0,0,128,83,211,217,12,160,14,103,17,52,3,0,90,219,252,43,104,6,0,0,0,0,0,48,4,97,51,128,58,252,161,4,0,192,145,17,154,0,0,0,0,0,192,40,140,209,4,24,242,
208,189,223,24,205,101,218,17,154,0,0,201,87,70,104,38,198,104,2,0,0,0,0,0,167,167,179,25,64,249,206,149,0,0,56,218,198,8,77,0,0,0,0,0,96,36,194,102,0,229,51,66,19,0,184,102,132,38,0,0,0,0,0,48,26,97,
51,128,178,157,165,29,163,9,0,144,36,87,74,0,0,0,0,0,0,140,69,216,12,160,108,191,41,1,0,112,116,21,35,52,1,0,0,0,0,128,17,9,155,1,148,171,73,114,174,12,0,192,209,63,74,0,0,0,0,0,0,140,73,216,12,160,92,
103,74,0,0,28,237,147,92,42,3,0,0,0,0,0,48,38,97,51,128,114,253,169,4,0,192,209,149,18,0,0,0,0,0,0,99,91,28,14,7,85,0,24,234,208,93,44,110,251,83,151,73,62,168,24,0,112,244,75,146,237,247,126,130,103,
59,0,0,0,0,0,224,212,116,54,3,40,211,153,18,0,0,71,187,116,4,205,0,0,0,0,0,0,134,32,108,6,80,166,63,148,0,0,56,122,165,4,0,0,0,0,0,64,9,140,209,4,24,242,208,189,221,24,205,101,140,208,4,0,110,252,39,201,
190,235,39,121,182,3,0,0,0,0,0,78,77,103,51,128,242,156,41,1,0,112,116,153,91,4,205,0,0,0,0,0,0,134,32,108,6,80,30,35,52,1,128,107,127,43,1,0,0,0,0,0,80,10,99,52,1,134,60,116,187,199,104,46,99,132,38,
0,208,218,38,249,229,182,63,217,179,29,0,0,0,0,0,112,106,58,155,1,148,229,76,9,0,128,163,87,74,0,0,0,0,0,0,148,68,103,51,128,33,15,221,238,206,102,239,147,172,84,10,0,102,111,159,228,63,119,249,5,158,
237,0,0,0,0,0,128,83,211,217,12,160,28,203,8,154,1,0,45,93,205,0,0,0,0,0,128,226,8,155,1,148,99,173,4,0,192,209,165,18,0,0,0,0,0,0,165,17,54,3,40,199,111,74,0,0,164,13,154,237,148,1,0,0,0,0,0,40,205,226,
112,56,168,2,192,80,135,238,98,241,189,255,249,99,146,70,149,0,96,246,30,39,217,220,245,23,121,182,3,0,0,0,0,0,78,77,103,51,128,50,172,35,104,6,0,180,33,179,141,50,0,0,0,0,0,0,37,18,54,3,40,131,17,154,
0,64,146,188,82,2,0,0,0,0,0,160,84,198,104,2,12,121,232,126,123,140,230,251,36,43,21,2,128,89,219,37,249,233,190,191,216,179,29,0,0,0,0,0,112,106,58,155,1,140,175,137,160,25,0,144,252,165,4,0,0,0,0,0,
64,201,132,205,0,198,119,166,4,0,48,123,187,36,151,202,0,0,0,0,0,0,148,76,216,12,96,124,191,42,1,0,204,158,174,102,0,0,0,0,0,64,241,22,135,195,65,21,0,134,58,116,23,139,175,125,249,67,146,165,234,0,192,
108,237,146,252,244,208,223,196,179,29,0,0,0,0,0,112,106,58,155,1,140,107,25,65,51,0,152,187,191,149,0,0,0,0,0,0,168,129,176,25,192,184,214,74,0,0,179,182,79,242,82,25,0,0,0,0,0,128,26,8,155,1,140,235,
103,37,0,128,89,123,149,54,112,6,0,0,0,0,0,80,188,197,225,112,80,5,128,161,14,221,197,226,223,95,122,159,100,165,50,0,48,75,251,36,63,165,167,176,153,103,59,0,0,0,0,0,224,212,132,205,0,134,60,116,191,
12,155,57,132,1,96,190,158,36,185,236,235,55,243,108,7,0,0,0,0,0,156,154,176,25,192,144,135,238,231,97,179,117,146,183,170,2,0,179,180,75,219,213,172,55,158,237,0,0,0,0,0,128,83,123,164,4,0,163,89,43,
1,0,204,214,95,74,0,0,0,0,0,0,212,70,216,12,96,60,63,43,1,0,204,210,46,61,142,207,4,0,0,0,0,0,24,138,176,25,192,120,86,74,0,0,179,164,171,25,0,0,0,0,0,80,165,197,225,112,80,5,128,161,14,221,197,226,250,
135,77,146,143,42,2,0,179,179,73,242,248,20,191,177,103,59,0,0,0,0,0,224,212,116,54,3,24,199,74,9,0,96,150,116,53,3,0,0,0,0,0,170,37,108,6,48,142,181,18,0,192,236,108,142,31,0,0,0,0,0,0,85,18,54,3,24,
199,143,74,0,0,179,243,68,9,0,0,0,0,0,128,154,9,155,1,140,99,169,4,0,48,43,47,147,236,148,1,0,0,0,0,0,168,217,226,112,56,168,2,192,80,135,238,98,113,253,67,135,47,0,204,199,62,201,79,199,207,39,227,217,
14,0,0,0,0,0,56,53,157,205,0,134,183,84,2,0,152,149,191,114,226,160,25,0,0,0,0,0,192,16,116,54,3,24,242,208,109,59,155,173,147,188,85,13,0,152,133,93,218,174,102,39,231,217,14,0,0,0,0,0,56,53,157,205,
0,134,183,86,2,0,152,141,39,74,0,0,0,0,0,0,76,133,176,25,192,240,254,79,9,0,96,22,174,146,108,148,1,0,0,0,0,0,152,10,97,51,128,225,173,148,0,0,38,111,159,228,169,50,0,0,0,0,0,0,83,34,108,6,48,188,70,9,
0,96,242,94,37,217,41,3,0,0,0,0,0,48,37,139,195,225,160,10,0,67,29,186,139,69,146,56,120,1,96,218,118,73,126,26,250,69,61,219,1,0,0,0,0,0,167,166,179,25,192,176,26,37,0,128,201,123,162,4,0,0,0,0,0,192,
20,9,155,1,12,107,165,4,0,48,105,87,73,54,202,0,0,0,0,0,0,76,145,176,25,0,0,64,63,246,209,213,12,0,0,0,0,0,152,48,97,51,128,97,173,149,0,0,38,235,175,180,129,51,0,0,0,0,0,128,73,250,65,9,0,134,177,88,
44,20,1,0,166,107,115,56,28,94,42,3,0,0,0,0,0,48,101,58,155,1,12,235,71,37,0,128,73,50,62,19,0,0,0,0,0,152,60,97,51,128,97,45,149,0,0,38,231,175,36,59,101,0,0,0,0,0,0,166,78,216,12,0,0,224,254,182,73,
158,43,3,0,0,0,0,0,48,7,194,102,0,195,106,148,0,0,38,197,248,76,0,0,0,0,0,96,54,132,205,0,134,181,82,2,0,152,140,191,210,118,54,3,0,0,0,0,0,152,133,197,225,112,80,5,128,33,14,220,197,34,73,28,186,0,48,
13,219,36,191,124,250,5,207,86,0,0,0,0,0,192,212,9,155,1,12,117,224,10,155,1,192,148,252,146,127,117,53,243,108,5,0,0,0,0,0,76,157,49,154,0,0,0,119,99,124,38,0,0,0,0,0,48,75,58,155,1,12,117,224,46,22,
235,36,111,85,2,0,170,182,73,242,248,107,255,131,103,43,0,0,0,0,0,96,234,116,54,3,0,0,184,157,125,146,39,202,0,0,0,0,0,0,204,149,176,25,0,0,192,237,60,77,178,83,6,0,0,0,0,0,96,174,132,205,0,0,0,186,93,
37,185,84,6,0,0,0,0,0,96,206,132,205,0,0,0,190,111,23,227,51,1,0,0,0,0,0,132,205,0,0,0,58,60,73,178,87,6,0,0,0,0,0,96,238,132,205,0,0,0,190,237,175,36,27,101,0,0,0,0,0,0,16,54,3,0,0,248,150,77,146,231,
202,0,0,0,0,0,0,208,18,54,3,0,0,248,210,62,237,248,76,0,0,0,0,0,0,142,132,205,0,0,0,190,244,36,201,78,25,0,0,0,0,0,0,110,8,155,1,0,0,124,238,101,146,43,101,0,0,0,0,0,0,248,156,176,25,0,0,192,141,109,146,
167,202,0,0,0,0,0,0,240,37,97,51,0,0,128,214,62,201,99,101,0,0,0,0,0,0,248,58,97,51,0,0,128,214,239,105,3,103,0,0,0,0,0,0,124,133,176,25,0,0,64,59,58,115,163,12,0,0,0,0,0,0,223,182,56,28,14,170,0,48,196,
129,187,88,36,137,67,23,0,202,115,149,182,171,217,131,120,182,2,0,0,0,0,0,166,78,216,12,96,168,3,87,216,12,0,74,180,77,242,56,61,140,207,244,108,5,0,0,0,0,0,76,157,176,25,192,80,7,174,176,25,0,148,102,
159,54,104,182,237,227,55,243,108,5,0,0,0,0,0,76,157,176,25,192,80,7,174,176,25,0,148,230,247,180,35,52,123,225,217,10,0,0,0,0,0,152,186,71,74,0,48,168,173,18,0,64,17,254,74,143,65,51,0,0,0,0,0,128,57,
16,54,3,24,214,94,9,0,96,116,151,73,158,43,3,0,0,0,0,0,192,221,8,155,1,0,0,115,178,77,242,84,25,0,0,0,0,0,0,238,78,216,12,96,88,91,37,0,128,209,236,147,60,142,78,163,0,0,0,0,0,0,247,34,108,6,48,172,255,
167,4,0,48,138,125,4,205,0,0,0,0,0,0,30,68,216,12,96,88,123,37,0,128,81,60,141,14,163,0,0,0,0,0,0,15,34,108,6,48,172,173,18,0,192,224,254,74,114,169,12,0,0,0,0,0,0,15,35,108,6,0,0,76,217,101,146,231,202,
0,0,0,0,0,0,240,112,139,195,225,160,10,0,67,28,184,139,197,245,15,29,188,0,48,140,109,146,95,134,122,49,207,86,0,0,0,0,0,192,212,9,155,1,12,117,224,10,155,1,192,144,182,73,30,39,217,15,245,130,158,173,
0,0,0,0,0,128,169,51,70,19,96,120,27,37,0,128,147,218,39,249,61,3,6,205,0,0,0,0,0,0,230,64,216,12,96,120,123,37,0,128,147,190,207,62,78,178,83,10,0,0,0,0,0,128,126,9,155,1,12,239,191,74,0,0,39,243,123,
218,17,154,0,0,0,0,0,0,244,76,216,12,96,120,59,37,0,128,147,120,18,227,170,1,0,0,0,0,0,78,70,216,12,96,120,59,37,0,128,222,61,73,114,169,12,0,0,0,0,0,0,167,179,56,28,14,170,0,48,196,129,187,88,124,250,
143,14,95,0,232,207,203,36,79,199,94,132,103,43,0,0,0,0,0,96,234,116,54,3,24,199,86,9,0,160,23,151,41,32,104,6,0,0,0,0,0,48,7,194,102,0,227,216,41,1,0,60,216,101,218,241,153,0,0,0,0,0,0,12,64,216,12,96,
28,255,85,2,0,120,144,171,8,154,1,0,0,0,0,0,12,74,216,12,96,28,27,37,0,128,123,219,70,208,12,0,0,0,0,0,96,112,139,195,225,160,10,0,67,28,184,139,197,167,255,216,36,249,168,42,0,112,103,219,36,143,147,
236,75,91,152,103,43,0,0,0,0,0,96,234,132,205,0,134,58,112,63,15,155,37,201,135,36,75,149,1,128,91,219,166,208,160,89,34,108,6,0,0,0,0,0,76,159,49,154,0,227,217,40,1,0,220,218,54,5,7,205,0,0,0,0,0,0,230,
64,216,12,96,60,255,85,2,0,184,149,109,4,205,0,0,0,0,0,0,70,39,108,6,48,158,141,18,0,64,167,109,4,205,0,0,0,0,0,0,138,176,56,28,14,170,0,48,196,129,187,88,124,237,203,31,147,52,170,3,0,95,181,77,69,65,
51,207,86,0,0,0,0,0,192,212,233,108,6,48,174,141,18,0,192,87,109,163,163,25,0,0,0,0,0,64,81,132,205,0,198,245,78,9,0,224,11,219,8,154,1,0,0,0,0,0,20,71,216,12,96,92,27,37,0,128,207,108,35,104,6,0,0,0,
0,0,80,164,197,225,112,80,5,128,33,14,220,197,226,91,255,211,135,36,75,21,2,128,186,131,102,158,173,0,0,0,0,0,128,169,211,217,12,96,124,27,37,0,0,29,205,0,0,0,0,0,0,74,39,108,6,48,190,127,148,0,128,153,
219,70,208,12,0,0,0,0,0,160,120,198,104,2,12,117,224,126,123,140,102,147,228,163,10,1,48,83,219,76,36,104,230,217,10,0,0,0,0,0,152,58,157,205,0,198,183,79,114,165,12,0,204,208,54,58,154,1,0,0,0,0,0,84,
67,216,12,160,12,239,148,0,128,153,185,76,242,75,4,205,0,0,0,0,0,0,170,97,140,38,192,80,7,238,183,199,104,38,201,50,201,7,85,2,96,38,46,147,60,153,218,31,202,179,21,0,0,0,0,0,48,117,194,102,0,67,29,184,
223,15,155,37,201,251,36,43,149,2,96,226,46,51,193,160,89,34,108,6,0,0,0,0,0,76,159,49,154,0,229,248,91,9,0,152,184,167,153,104,208,12,0,0,0,0,0,96,14,116,54,3,24,234,192,237,238,108,182,140,81,154,0,
76,215,147,180,93,205,38,203,179,21,0,0,0,0,0,48,117,58,155,1,148,99,151,100,163,12,0,76,204,62,51,8,154,1,0,0,0,0,0,204,129,176,25,64,89,140,210,4,96,74,246,73,30,71,208,12,0,0,0,0,0,96,18,140,209,4,
24,234,192,237,30,163,153,36,77,218,81,154,141,138,1,80,185,125,218,160,217,118,46,127,96,207,86,0,0,0,0,0,192,212,233,108,6,80,150,125,146,43,101,0,160,114,219,36,63,101,70,65,51,0,0,0,0,0,128,57,16,
54,3,40,143,81,154,0,212,108,147,182,163,217,94,41,0,0,0,0,0,0,166,197,24,77,128,161,14,220,219,141,209,188,246,33,201,82,213,0,168,204,101,146,39,115,253,195,123,182,2,0,0,0,0,0,166,78,103,51,128,50,
189,82,2,0,42,243,52,51,14,154,1,0,0,0,0,0,204,129,206,102,0,67,29,184,119,235,108,214,164,237,110,214,168,28,0,133,219,167,13,154,93,206,189,16,158,173,0,0,0,0,0,128,169,211,217,12,160,76,251,36,87,202,
0,64,5,239,87,143,35,104,6,0,0,0,0,0,48,11,58,155,1,12,117,224,222,173,179,89,146,44,211,118,55,3,128,18,109,147,252,158,100,167,20,45,207,86,0,0,0,0,0,192,212,233,108,6,80,174,93,146,141,50,0,80,160,
171,180,29,205,118,74,1,0,0,0,0,0,48,31,58,155,1,12,117,224,222,189,179,89,146,172,147,188,85,61,0,10,242,50,201,83,101,248,146,103,43,0,0,0,0,0,96,234,132,205,0,134,58,112,239,23,54,75,218,81,154,75,
21,4,96,100,251,180,33,179,75,165,248,58,207,86,0,0,0,0,0,192,212,9,155,1,12,117,224,222,63,108,118,158,228,181,10,2,48,162,125,218,177,153,91,165,248,54,207,86,0,0,0,0,0,192,212,9,155,1,12,117,224,222,
63,108,150,232,110,6,192,120,182,105,131,102,123,165,248,62,207,86,0,0,0,0,0,192,212,61,82,2,128,42,252,165,4,0,140,224,50,201,47,17,52,3,0,0,0,0,0,32,58,155,1,12,119,224,62,172,179,89,162,187,25,0,195,
122,146,54,108,198,45,121,182,2,0,0,0,0,0,166,78,103,51,128,122,232,110,6,192,16,246,105,187,153,93,42,5,0,0,0,0,0,0,159,210,217,12,96,168,3,247,225,157,205,18,221,205,0,56,173,77,146,223,99,108,230,189,
120,182,2,0,0,0,0,0,166,78,103,51,128,186,60,85,2,0,78,228,101,146,199,17,52,3,0,0,0,0,0,224,27,116,54,3,24,234,192,237,167,179,89,146,188,77,178,86,81,0,122,178,79,242,36,201,149,82,60,140,103,43,0,0,
0,0,0,96,234,132,205,0,134,58,112,251,11,155,173,211,6,206,0,224,161,182,105,131,102,91,165,120,56,207,86,0,0,0,0,0,192,212,25,163,9,80,159,77,116,159,1,224,225,46,211,142,205,220,42,5,0,0,0,0,0,0,183,
161,179,25,192,80,7,110,127,157,205,146,100,153,228,125,146,70,101,1,184,135,167,73,94,42,67,191,60,91,1,0,0,0,0,0,83,39,108,6,80,235,1,190,88,60,79,242,76,37,0,184,131,93,146,223,163,155,217,73,120,182,
2,0,0,0,0,0,166,78,216,12,160,214,3,124,177,104,210,118,55,91,170,6,0,183,112,149,228,201,225,112,216,43,5,0,0,0,0,0,0,247,241,72,9,0,170,181,79,242,68,25,0,184,133,167,105,59,154,237,149,2,0,0,0,0,0,
128,251,210,217,12,160,214,3,124,177,184,254,225,155,36,103,42,2,192,87,236,242,175,177,153,238,255,0,0,0,0,0,0,220,151,176,25,64,173,7,248,77,216,108,153,118,156,102,163,42,0,124,226,42,109,7,204,253,
167,95,116,255,7,0,0,0,0,0,224,190,140,209,4,168,223,46,201,95,202,0,192,209,62,198,102,2,0,0,0,0,0,112,2,58,155,1,212,122,128,223,116,54,187,246,54,201,90,101,0,102,109,155,182,155,217,246,91,63,193,
253,31,0,0,0,0,0,128,251,18,54,3,168,245,0,255,50,108,182,140,113,154,0,115,246,50,109,71,179,239,114,255,7,0,0,0,0,0,224,190,140,209,4,152,142,93,140,211,4,152,163,125,146,199,185,69,208,12,0,0,0,0,0,
0,30,66,103,51,128,90,15,240,47,59,155,93,123,147,228,76,133,0,102,225,42,237,216,204,253,109,127,129,251,63,0,0,0,0,0,0,247,37,108,6,80,235,1,254,237,176,89,147,228,67,140,211,4,152,178,125,218,78,102,
151,119,253,133,238,255,0,0,0,0,0,0,220,151,176,25,64,173,7,248,183,195,102,73,178,78,242,86,149,0,38,105,147,182,155,217,238,62,191,216,253,31,0,0,0,0,0,128,251,122,164,4,0,147,180,73,242,82,25,0,38,
231,105,146,199,185,103,208,12,0,0,0,0,0,0,30,66,103,51,128,90,15,240,239,119,54,187,246,62,201,74,181,0,170,183,77,219,205,108,251,208,223,200,253,31,0,0,0,0,0,128,251,18,54,3,168,245,0,191,93,216,172,
73,242,225,248,25,128,58,253,149,228,121,95,191,153,251,63,0,0,0,0,0,0,247,37,108,6,80,235,1,126,187,176,89,146,172,147,188,85,49,128,234,108,211,83,55,179,79,185,255,3,0,0,0,0,0,112,95,143,148,0,96,242,
54,73,158,42,3,64,53,246,105,187,153,253,146,158,131,102,0,0,0,0,0,0,240,16,58,155,1,212,122,128,223,190,179,217,181,215,73,206,85,14,160,104,155,180,221,204,118,167,122,1,247,127,0,0,0,0,0,0,238,75,216,
12,160,214,3,252,238,97,179,38,237,56,205,149,234,1,20,103,159,182,155,217,203,83,191,144,251,63,0,0,0,0,0,0,247,37,108,6,80,235,1,126,247,176,89,210,6,206,62,28,63,3,80,134,171,180,227,142,119,67,188,
152,251,63,0,0,0,0,0,0,247,245,72,9,0,102,101,159,228,241,241,51,0,227,218,37,249,253,248,177,83,14,0,0,0,0,0,0,74,39,108,6,48,63,219,36,79,148,1,96,84,47,147,252,146,182,171,25,0,0,0,0,0,0,84,193,24,
77,128,90,15,240,251,141,209,252,212,121,146,215,42,9,48,168,109,218,192,239,118,172,5,184,255,3,0,0,0,0,0,112,95,194,102,0,181,30,224,15,15,155,37,201,69,146,23,170,9,112,114,251,36,127,37,121,233,254,
13,0,0,0,0,0,64,173,132,205,0,106,61,192,251,9,155,37,109,119,179,115,21,5,56,153,203,36,79,211,6,206,116,22,3,0,0,0,0,0,160,90,194,102,0,181,30,224,253,133,205,18,129,51,128,83,216,166,13,153,109,62,
253,162,251,55,0,0,0,0,0,0,181,18,54,3,168,245,0,239,55,108,150,8,156,1,244,101,159,227,200,204,175,253,143,238,223,0,0,0,0,0,0,212,74,216,12,160,214,3,188,255,176,89,34,112,6,240,80,151,249,100,100,230,
215,184,127,3,0,0,0,0,0,80,43,97,51,128,90,15,240,211,132,205,18,129,51,128,251,216,164,13,153,109,187,126,162,251,55,0,0,0,0,0,0,181,18,54,3,168,245,0,63,93,216,44,17,56,3,184,173,93,218,145,153,151,
183,253,5,238,223,0,0,0,0,0,0,212,74,216,12,160,214,3,252,180,97,179,68,224,12,224,123,246,73,94,37,121,153,239,140,204,252,26,247,111,0,0,0,0,0,0,106,37,108,6,80,235,1,126,250,176,89,34,112,6,240,53,
151,105,187,153,237,238,243,139,221,191,1,0,0,0,0,0,168,149,176,25,64,173,7,248,48,97,179,36,121,145,228,66,197,1,178,73,242,52,201,246,33,191,137,251,55,0,0,0,0,0,0,181,18,54,3,168,245,0,31,46,108,150,
180,221,205,94,171,58,48,83,219,180,33,179,77,31,191,153,251,55,0,0,0,0,0,0,181,18,54,3,168,245,0,31,54,108,150,8,156,1,243,179,75,59,46,243,178,207,223,212,253,27,0,0,0,0,0,128,90,9,155,1,212,122,128,
15,31,54,75,146,85,146,183,73,26,59,0,76,216,62,201,171,36,207,79,241,155,187,127,3,0,0,0,0,0,80,43,97,51,128,90,15,240,113,194,102,73,27,56,123,125,252,12,48,37,251,180,33,179,151,199,31,159,132,251,
55,0,0,0,0,0,0,181,18,54,3,168,245,0,31,47,108,150,180,157,205,222,36,89,219,9,96,34,254,202,137,67,102,215,220,191,1,0,0,0,0,0,168,149,176,25,64,173,7,248,184,97,179,107,175,147,156,219,13,160,98,151,
105,131,102,187,161,94,208,253,27,0,0,0,0,0,128,90,9,155,1,212,122,128,151,17,54,75,218,176,217,139,180,221,206,0,106,113,153,129,67,102,215,220,191,1,0,0,0,0,0,168,149,176,25,64,173,7,120,57,97,179,36,
89,37,121,27,129,51,160,124,151,25,41,100,118,205,253,27,0,0,0,0,0,128,90,9,155,1,212,122,128,151,21,54,75,218,160,217,219,180,193,51,128,210,92,102,228,144,217,53,247,111,0,0,0,0,0,0,106,245,72,9,0,232,
201,62,201,47,105,3,29,0,165,184,76,242,83,146,39,41,32,104,6,0,0,0,0,0,0,53,211,217,12,160,214,3,188,188,206,102,159,58,79,242,34,198,106,2,227,216,39,185,74,33,157,204,254,205,253,27,0,0,0,0,0,128,90,
9,155,1,212,122,128,151,29,54,75,218,113,154,111,146,44,237,22,48,144,125,146,87,73,94,30,127,92,36,247,111,0,0,0,0,0,0,106,37,108,6,80,235,1,94,126,216,44,105,59,155,189,78,114,102,199,128,19,218,167,
130,144,217,53,247,111,0,0,0,0,0,0,106,37,108,6,80,235,1,94,71,216,236,218,121,140,213,4,250,183,75,59,42,243,178,166,69,187,127,3,0,0,0,0,0,80,43,97,51,128,90,15,240,186,194,102,73,59,78,243,77,218,241,
154,0,15,177,73,242,119,42,11,153,93,115,255,6,0,0,0,0,0,160,86,194,102,0,181,30,224,245,133,205,174,61,79,242,204,14,2,247,112,153,54,100,182,169,249,15,225,254,13,0,0,0,0,0,64,173,132,205,0,106,61,192,
235,13,155,37,109,119,179,215,209,229,12,232,182,79,27,50,123,149,118,108,102,245,220,191,1,0,0,0,0,0,168,149,176,25,64,173,7,120,221,97,179,107,207,163,203,25,240,117,187,180,1,179,203,180,129,179,201,
112,255,6,0,0,0,0,0,160,86,194,102,0,181,30,224,211,8,155,37,186,156,1,159,219,164,13,153,93,77,245,15,232,254,13,0,0,0,0,0,64,173,132,205,0,106,61,192,167,19,54,187,246,60,201,159,73,26,187,11,179,179,
79,27,46,251,43,19,25,149,249,61,238,223,0,0,0,0,0,0,212,74,216,12,160,214,3,124,122,97,179,36,89,166,237,114,182,182,195,48,11,187,180,1,179,171,76,108,84,230,247,184,127,3,0,0,0,0,0,80,43,97,51,128,
90,15,240,105,134,205,174,157,37,121,145,54,124,6,76,207,101,146,191,211,142,204,156,29,247,111,0,0,0,0,0,0,106,37,108,6,80,235,1,62,237,176,89,210,142,211,188,72,242,204,110,195,36,236,146,188,74,27,
52,219,207,185,16,238,223,0,0,0,0,0,0,212,74,216,12,160,214,3,124,250,97,179,107,203,180,93,206,206,236,58,84,233,50,51,238,98,246,53,238,223,0,0,0,0,0,0,212,74,216,12,160,214,3,124,62,97,179,107,235,
180,93,206,214,118,31,138,183,77,219,197,236,42,51,239,98,246,53,238,223,0,0,0,0,0,0,212,74,216,12,160,214,3,124,126,97,179,107,231,105,67,103,75,223,5,80,148,125,218,46,102,175,210,142,204,228,27,220,
191,1,0,0,0,0,0,168,149,176,25,64,173,7,248,124,195,102,215,206,35,116,6,37,184,76,242,79,218,46,102,220,130,251,55,0,0,0,0,0,0,181,18,54,3,168,245,0,23,54,75,146,38,201,69,146,63,143,63,6,134,177,73,
242,119,140,201,188,23,247,111,0,0,0,0,0,0,106,37,108,6,80,235,1,46,108,246,169,38,66,103,112,106,219,220,4,204,118,202,113,127,238,223,0,0,0,0,0,0,212,74,216,12,160,214,3,92,216,236,107,154,180,227,53,
255,140,241,154,208,135,93,218,112,217,171,8,152,245,198,253,27,0,0,0,0,0,128,90,9,155,1,212,122,128,11,155,117,57,79,242,44,66,103,112,87,187,180,1,179,191,211,118,51,163,103,238,223,0,0,0,0,0,0,212,
74,216,12,160,214,3,92,216,236,182,206,210,118,58,91,43,5,124,211,46,2,102,131,113,255,6,0,0,0,0,0,160,86,194,102,0,181,30,224,194,102,119,181,74,27,58,59,87,10,72,210,134,202,254,73,27,50,219,42,199,
112,220,191,1,0,0,0,0,0,168,149,176,25,64,173,7,184,176,217,125,45,211,6,206,254,136,17,155,204,207,38,55,1,179,157,114,140,195,253,27,0,0,0,0,0,128,90,9,155,1,212,122,128,11,155,245,225,60,109,232,108,
173,20,76,212,62,159,7,204,246,74,50,62,247,111,0,0,0,0,0,0,106,37,108,6,80,235,1,46,108,214,167,101,218,17,155,103,209,237,140,250,237,210,6,203,254,73,27,52,163,48,238,223,0,0,0,0,0,0,212,74,216,12,
160,214,3,92,216,236,84,206,210,118,59,59,83,10,42,177,79,27,42,123,23,227,49,171,224,254,13,0,0,0,0,0,64,173,132,205,0,106,61,192,133,205,78,173,73,27,56,251,51,201,74,57,40,204,54,55,227,49,55,202,81,
23,247,111,0,0,0,0,0,0,106,37,108,6,80,235,1,46,108,54,164,101,110,58,158,173,148,131,17,236,242,121,184,108,175,36,245,114,255,6,0,0,0,0,0,160,86,194,102,0,181,30,224,194,102,99,89,70,240,140,211,219,
229,102,52,230,38,70,99,78,138,251,55,0,0,0,0,0,0,181,18,54,3,168,245,0,23,54,43,193,50,109,240,236,215,227,103,184,175,109,218,80,217,127,35,92,54,121,238,223,0,0,0,0,0,0,212,74,216,12,160,214,3,92,216,
172,52,77,146,117,146,223,142,159,151,74,194,119,108,210,118,45,219,198,88,204,217,113,255,6,0,0,0,0,0,160,86,194,102,0,181,30,224,194,102,165,91,229,243,240,25,243,181,61,126,92,119,45,219,42,201,188,
185,127,3,0,0,0,0,0,80,43,97,51,128,90,15,112,97,179,218,172,143,31,191,70,248,108,202,118,249,50,88,182,87,22,62,229,254,13,0,0,0,0,0,64,173,132,205,0,106,61,192,133,205,106,183,62,126,252,124,252,220,
40,73,117,182,185,9,150,93,255,120,175,44,116,113,255,6,0,0,0,0,0,160,86,194,102,0,181,30,224,194,102,83,179,58,126,252,156,155,17,156,148,97,155,182,99,217,127,63,249,241,86,89,184,47,247,111,0,0,0,0,
0,0,106,37,108,6,80,235,1,46,108,54,7,171,124,30,64,91,69,7,180,83,218,164,13,146,253,47,66,101,156,144,251,55,0,0,0,0,0,0,181,18,54,3,168,245,0,23,54,155,171,38,55,193,179,31,35,132,118,23,187,79,62,
254,247,201,143,183,49,254,146,1,185,127,3,0,0,0,0,0,80,43,97,51,128,90,15,112,97,51,190,180,254,228,243,255,165,13,161,125,250,245,41,219,231,166,11,217,187,227,231,221,191,62,160,8,238,223,0,0,0,0,0,
0,212,74,216,12,160,214,3,92,216,140,187,91,165,237,128,214,228,38,136,246,99,146,229,241,199,159,126,125,108,155,79,126,188,79,242,223,111,252,111,27,219,74,109,220,191,1,0,0,0,0,0,168,149,176,25,0,204,
241,2,112,251,176,226,42,223,30,209,217,164,59,156,182,75,119,87,177,141,29,97,78,220,191,1,0,0,0,0,0,168,149,176,25,0,0,0,0,0,0,0,0,0,157,132,205,0,0,0,0,0,0,0,0,0,232,36,108,6,0,0,0,0,0,0,0,0,64,39,
97,51,0,0,0,0,0,0,0,0,0,58,9,155,1,0,0,0,0,0,0,0,0,208,73,216,12,0,0,0,0,0,0,0,0,128,78,194,102,0,0,0,0,0,0,0,0,0,116,18,54,3,0,0,0,0,0,0,0,0,160,147,176,25,0,0,0,0,0,0,0,0,0,157,132,205,0,0,0,0,0,0,0,
0,0,232,36,108,6,0,0,0,0,0,0,0,0,64,39,97,51,0,0,0,0,0,0,0,0,0,58,9,155,1,0,0,0,0,0,0,0,0,208,73,216,12,0,0,0,0,0,0,0,0,128,78,194,102,0,0,0,0,0,0,0,0,0,116,18,54,3,0,0,0,0,0,0,0,0,160,147,176,25,0,0,
0,0,0,0,0,0,0,157,132,205,0,0,0,0,0,0,0,0,0,232,36,108,6,0,0,0,0,0,0,0,0,64,39,97,51,0,0,0,0,0,0,0,0,0,58,9,155,1,0,0,0,0,0,0,0,0,208,73,216,12,0,0,0,0,0,0,0,0,128,78,194,102,0,0,0,0,0,0,0,0,0,116,18,
54,3,0,0,0,0,0,0,0,0,160,147,176,25,0,0,0,0,0,0,0,0,0,157,132,205,0,0,0,0,0,0,0,0,0,232,36,108,6,0,0,0,0,0,0,0,0,64,39,97,51,0,0,0,0,0,0,0,0,0,58,9,155,1,0,0,0,0,0,0,0,0,208,73,216,12,0,0,0,0,0,0,0,0,
128,78,194,102,0,0,0,0,0,0,0,0,0,116,18,54,3,0,0,0,0,0,0,0,0,160,147,176,25,0,0,0,0,0,0,0,0,0,157,132,205,0,0,0,0,0,0,0,0,0,232,36,108,6,0,0,0,0,0,0,0,0,64,39,97,51,0,0,0,0,0,0,0,0,0,58,9,155,1,0,0,0,
0,0,0,0,0,208,73,216,12,0,0,0,0,0,0,0,0,128,78,194,102,0,0,0,0,0,0,0,0,0,116,18,54,3,0,0,0,0,0,0,0,0,160,147,176,25,0,0,0,0,0,0,0,0,0,157,132,205,0,0,0,0,0,0,0,0,0,232,36,108,6,0,0,0,0,0,0,0,0,64,39,97,
51,0,0,0,0,0,0,0,0,0,58,9,155,1,0,0,0,0,0,0,0,0,208,73,216,12,0,0,0,0,0,0,0,0,128,78,194,102,0,0,0,0,0,0,0,0,0,116,18,54,3,0,0,0,0,0,0,0,0,160,147,176,25,0,0,0,0,0,0,0,0,0,157,132,205,0,0,0,0,0,0,0,0,
0,232,36,108,6,0,0,0,0,0,0,0,0,64,39,97,51,0,0,0,0,0,0,0,0,0,58,9,155,1,0,0,0,0,0,0,0,0,208,73,216,12,0,0,0,0,0,0,0,0,128,78,194,102,0,0,0,0,0,0,0,0,0,116,18,54,3,0,0,0,0,0,0,0,0,160,147,176,25,0,0,0,
0,0,0,0,0,0,157,132,205,0,0,0,0,0,0,0,0,0,232,36,108,6,0,0,0,0,0,0,0,0,64,39,97,51,0,0,0,0,0,0,0,0,0,58,9,155,1,0,0,0,0,0,0,0,0,208,73,216,12,0,0,0,0,0,0,0,0,128,78,194,102,0,0,0,0,0,0,0,0,0,116,18,54,
3,0,0,0,0,0,0,0,0,160,147,176,25,0,0,0,0,0,0,0,0,0,157,132,205,0,0,0,0,0,0,0,0,0,232,36,108,6,0,0,0,0,0,0,0,0,64,39,97,51,0,0,0,0,0,0,0,0,0,58,9,155,1,0,0,0,0,0,0,0,0,208,73,216,12,0,0,0,0,0,0,0,0,128,
78,194,102,0,0,0,0,0,0,0,0,0,116,18,54,3,0,0,0,0,0,0,0,0,160,147,176,25,0,0,0,0,0,0,0,0,0,157,132,205,0,0,0,0,0,0,0,0,0,232,36,108,6,0,0,0,0,0,0,0,0,64,39,97,51,0,0,0,0,0,0,0,0,0,58,9,155,1,0,0,0,0,0,
0,0,0,208,73,216,12,0,0,0,0,0,0,0,0,128,78,194,102,0,0,0,0,0,0,0,0,0,116,18,54,3,0,0,0,0,0,0,0,0,160,147,176,25,0,0,0,0,0,0,0,0,0,157,132,205,0,0,0,0,0,0,0,0,0,232,36,108,6,0,0,0,0,0,0,0,0,64,39,97,51,
0,0,0,0,0,0,0,0,0,58,9,155,1,0,0,0,0,0,0,0,0,208,73,216,12,0,0,0,0,0,0,0,0,128,78,194,102,0,0,0,0,0,0,0,0,0,116,18,54,3,0,0,0,0,0,0,0,0,160,147,176,25,0,0,0,0,0,0,0,0,0,157,132,205,0,0,0,0,0,0,0,0,0,232,
36,108,6,0,0,0,0,0,0,0,0,64,39,97,51,0,0,0,0,0,0,0,0,0,58,9,155,1,0,0,0,0,0,0,0,0,208,73,216,12,0,0,0,0,0,0,0,0,128,78,194,102,0,0,0,0,0,0,0,0,0,116,18,54,3,0,0,0,0,0,0,0,0,160,147,176,25,0,0,0,0,0,0,
0,0,0,157,132,205,0,0,0,0,0,0,0,0,0,232,36,108,6,0,0,0,0,0,0,0,0,64,39,97,51,0,0,0,0,0,0,0,0,0,58,9,155,1,0,0,0,0,0,0,0,0,208,73,216,12,0,0,0,0,0,0,0,0,128,78,194,102,0,0,0,0,0,0,0,0,0,116,18,54,3,0,0,
0,0,0,0,0,0,160,147,176,25,0,0,0,0,0,0,0,0,0,157,132,205,0,0,0,0,0,0,0,0,0,232,36,108,6,0,0,0,0,0,0,0,0,64,39,97,51,0,0,0,0,0,0,0,0,0,58,9,155,1,0,0,0,0,0,0,0,0,208,73,216,12,0,0,0,0,0,0,0,0,128,78,194,
102,0,0,0,0,0,0,0,0,0,116,18,54,3,0,0,0,0,0,0,0,0,160,147,176,25,0,0,0,0,0,0,0,0,0,157,132,205,0,0,0,0,0,0,0,0,0,232,36,108,6,0,0,0,0,0,0,252,127,118,237,64,0,0,0,0,64,144,191,245,8,11,20,71,0,0,176,100,
51,0,0,0,0,0,0,0,0,0,150,108,6,0,0,0,0,0,0,0,0,192,146,205,0,0,0,0,0,0,0,0,0,88,178,25,0,0,0,0,0,0,0,0,0,75,54,3,0,0,0,0,0,0,0,0,96,201,102,0,0,0,0,0,0,0,0,0,44,217,12,0,0,0,0,0,0,0,0,128,37,155,1,0,0,
0,0,0,0,0,0,176,100,51,0,0,0,0,0,0,0,0,0,150,108,6,0,0,0,0,0,0,0,0,192,146,205,0,0,0,0,0,0,0,0,0,88,178,25,0,0,0,0,0,0,0,0,0,75,54,3,0,0,0,0,0,0,0,0,96,201,102,0,0,0,0,0,0,0,0,0,44,217,12,0,0,0,0,0,0,
0,0,128,37,155,1,0,0,0,0,0,0,0,0,176,100,51,0,0,0,0,0,0,0,0,0,150,108,6,0,0,0,0,0,0,0,0,192,146,205,0,0,0,0,0,0,0,0,0,88,178,25,0,0,0,0,0,0,0,0,0,75,54,3,0,0,0,0,0,0,0,0,96,201,102,0,0,0,0,0,0,0,0,0,44,
217,12,0,0,0,0,0,0,0,0,128,37,155,1,0,0,0,0,0,0,0,0,176,100,51,0,0,0,0,0,0,0,0,0,150,108,6,0,0,0,0,0,0,0,0,192,146,205,0,0,0,0,0,0,0,0,0,88,178,25,0,0,0,0,0,0,0,0,0,75,54,3,0,0,0,0,0,0,0,0,96,201,102,
0,0,0,0,0,0,0,0,0,44,217,12,0,0,0,0,0,0,0,0,128,37,155,1,0,0,0,0,0,0,0,0,176,100,51,0,0,0,0,0,0,0,0,0,150,108,6,0,0,0,0,0,0,0,0,192,146,205,0,0,0,0,0,0,0,0,0,88,178,25,0,0,0,0,0,0,0,0,0,75,54,3,0,0,0,
0,0,0,0,0,96,201,102,0,0,0,0,0,0,0,0,0,44,217,12,0,0,0,0,0,0,0,0,128,37,155,1,0,0,0,0,0,0,0,0,176,100,51,0,0,0,0,0,0,0,0,0,150,108,6,0,0,0,0,0,0,0,0,192,146,205,0,0,0,0,0,0,0,0,0,88,178,25,0,0,0,0,0,0,
0,0,0,75,54,3,0,0,0,0,0,0,0,0,96,201,102,0,0,0,0,0,0,0,0,0,44,217,12,0,0,0,0,0,0,0,0,128,37,155,1,0,0,0,0,0,0,0,0,176,100,51,0,0,0,0,0,0,0,0,0,150,108,6,0,0,0,0,0,0,0,0,192,146,205,0,0,0,0,0,0,0,0,0,88,
178,25,0,0,0,0,0,0,0,0,0,75,54,3,0,0,0,0,0,0,0,0,96,201,102,0,0,0,0,0,0,0,0,0,44,217,12,0,0,0,0,0,0,0,0,128,37,155,1,0,0,0,0,0,0,0,0,176,100,51,0,0,0,0,0,0,0,0,0,150,108,6,0,0,0,0,0,0,0,0,192,146,205,
0,0,0,0,0,0,0,0,0,88,178,25,0,0,0,0,0,0,0,0,0,75,54,3,0,0,0,0,0,0,0,0,96,201,102,0,0,0,0,0,0,0,0,0,44,217,12,0,0,0,0,0,0,0,0,128,37,155,1,0,0,0,0,0,0,0,0,176,100,51,0,0,0,0,0,0,0,0,0,150,108,6,0,0,0,0,
0,0,0,0,192,146,205,0,0,0,0,0,0,0,0,0,88,178,25,0,0,0,0,0,0,0,0,0,75,54,3,0,0,0,0,0,0,0,0,96,201,102,0,0,0,0,0,0,0,0,0,44,217,12,0,0,0,0,0,0,0,0,128,37,155,1,0,0,0,0,0,0,0,0,176,100,51,0,0,0,0,0,0,0,0,
0,150,108,6,0,0,0,0,0,0,0,0,192,146,205,0,0,0,0,0,0,0,0,0,88,178,25,0,0,0,0,0,0,0,0,0,75,54,3,0,0,0,0,0,0,0,0,96,201,102,0,0,0,0,0,0,0,0,0,44,217,12,0,0,0,0,0,0,0,0,128,37,155,1,0,0,0,0,0,0,0,0,176,100,
51,0,0,0,0,0,0,0,0,0,150,108,6,0,0,0,0,0,0,0,0,192,146,205,0,0,0,0,0,0,0,0,0,88,178,25,0,0,0,0,0,0,0,0,0,75,54,3,0,0,0,0,0,0,0,0,96,201,102,0,0,0,0,0,0,0,0,0,44,217,12,0,0,0,0,0,0,0,0,128,37,155,1,0,0,
0,0,0,0,0,0,176,100,51,0,0,0,0,0,0,0,0,0,150,108,6,0,0,0,0,0,0,0,0,192,146,205,0,0,0,0,0,0,0,0,0,88,178,25,0,0,0,0,0,0,0,0,0,75,54,3,0,0,0,0,0,0,0,0,96,201,102,0,0,0,0,0,0,0,0,0,44,217,12,0,0,0,0,0,0,
0,0,128,37,155,1,0,0,0,0,0,0,0,0,176,100,51,0,0,0,0,0,0,0,0,0,150,108,6,0,0,0,0,0,0,0,0,192,146,205,0,0,0,0,0,0,0,0,0,88,178,25,0,0,0,0,0,0,0,0,0,75,54,3,0,0,0,0,0,0,0,0,96,201,102,0,0,0,0,0,0,0,0,0,44,
217,12,0,0,0,0,0,0,0,0,128,37,155,1,0,0,0,0,0,0,0,0,176,100,51,0,0,0,0,0,0,0,0,0,150,108,6,0,0,0,0,0,0,0,0,192,146,205,0,0,0,0,0,0,0,0,0,88,178,25,0,0,0,0,0,0,0,0,0,75,54,3,0,0,0,0,0,0,0,0,96,201,102,
0,0,0,0,0,0,0,0,0,44,217,12,0,0,0,0,0,0,0,0,128,37,155,1,0,0,0,0,0,0,0,0,176,100,51,0,0,0,0,0,0,0,0,0,150,108,6,0,0,0,0,0,0,0,0,192,146,205,0,0,0,0,0,0,0,0,0,88,178,25,0,0,0,0,0,0,0,0,0,75,54,3,0,0,0,
0,0,0,0,0,96,201,102,0,0,0,0,0,0,0,0,0,44,217,12,0,0,0,0,0,0,0,0,128,37,155,1,0,0,0,0,0,0,0,0,176,100,51,0,0,0,0,0,0,0,0,0,150,108,6,0,0,0,0,0,0,0,0,192,146,205,0,0,0,0,0,0,0,0,0,88,178,25,0,0,0,0,0,0,
0,0,0,75,54,3,0,0,0,0,0,0,0,0,96,201,102,0,0,0,0,0,0,0,0,0,44,217,12,0,0,0,0,0,0,0,0,128,37,155,1,0,0,0,0,0,0,0,0,176,100,51,0,0,0,0,0,0,0,0,0,150,108,6,0,0,0,0,0,0,0,0,192,146,205,0,0,0,0,0,0,0,0,0,88,
178,25,0,0,0,0,0,0,0,0,0,75,54,3,0,0,0,0,0,0,0,0,96,201,102,0,0,0,0,0,0,0,0,0,44,217,12,0,0,0,0,0,0,0,0,128,37,155,1,0,0,0,0,0,0,0,0,176,100,51,0,0,0,0,0,0,0,0,0,150,108,6,0,0,0,0,0,0,0,0,192,146,205,
0,0,0,0,0,0,0,0,0,88,178,25,0,0,0,0,0,0,0,0,0,75,54,3,0,0,0,0,0,0,0,0,96,201,102,0,0,0,0,0,0,0,0,0,44,217,12,0,0,0,0,0,0,0,0,128,37,155,1,0,0,0,0,0,0,0,0,176,100,51,0,0,0,0,0,0,0,0,0,150,108,6,0,0,0,0,
0,0,0,0,192,146,205,0,0,0,0,0,0,0,0,0,88,178,25,0,0,0,0,0,0,0,0,0,75,54,3,0,0,0,0,0,0,0,0,96,201,102,0,0,0,0,0,0,0,0,0,44,217,12,0,0,0,0,0,0,0,0,128,37,155,1,0,0,0,0,0,0,0,0,176,100,51,0,0,0,0,0,0,0,0,
0,150,108,6,0,0,0,0,0,0,0,0,192,146,205,0,0,0,0,0,0,0,0,0,88,178,25,0,0,0,0,0,0,0,0,0,75,54,3,0,0,0,0,0,0,0,0,96,201,102,0,0,0,0,0,0,0,0,0,44,217,12,0,0,0,0,0,0,0,0,128,37,155,1,0,0,0,0,0,0,0,0,176,100,
51,0,0,0,0,0,0,0,0,0,150,108,6,0,0,0,0,0,0,0,0,192,146,205,0,0,0,0,0,0,0,0,0,88,178,25,0,0,0,0,0,0,0,0,0,75,54,3,0,0,0,0,0,0,0,0,96,201,102,0,0,0,0,0,0,0,0,0,44,217,12,0,0,0,0,0,0,0,0,128,37,155,1,0,0,
0,0,0,0,0,0,176,100,51,0,0,0,0,0,0,0,0,0,150,108,6,0,0,0,0,0,0,0,0,192,146,205,0,0,0,0,0,0,0,0,0,88,178,25,0,0,0,0,0,0,0,0,0,75,54,3,0,0,0,0,0,0,0,0,96,201,102,0,0,0,0,0,0,0,0,0,44,217,12,0,0,0,0,0,0,
0,0,128,37,155,1,0,0,0,0,0,0,0,0,176,100,51,0,0,0,0,0,0,0,0,0,150,108,6,0,0,0,0,0,0,0,0,192,146,205,0,0,0,0,0,0,0,0,0,88,178,25,0,0,0,0,0,0,0,0,0,75,54,3,0,0,0,0,0,0,0,0,96,201,102,0,0,0,0,0,0,0,0,0,44,
217,12,0,0,0,0,0,0,0,0,128,37,155,1,0,0,0,0,0,0,0,0,176,100,51,0,0,0,0,0,0,0,0,0,150,108,6,0,0,0,0,0,0,0,0,192,146,205,0,0,0,0,0,0,0,0,0,88,178,25,0,0,0,0,0,0,0,0,0,75,54,3,0,0,0,0,0,0,0,0,96,201,102,
0,0,0,0,0,0,0,0,0,44,217,12,0,0,0,0,0,0,0,0,128,37,155,1,0,0,0,0,0,0,0,0,176,100,51,0,0,0,0,0,0,0,0,0,150,108,6,0,0,0,0,0,0,0,0,192,146,205,0,0,0,0,0,0,0,0,0,88,178,25,0,0,0,0,0,0,0,0,0,75,54,3,0,0,0,
0,0,0,0,0,96,201,102,0,0,0,0,0,0,0,0,0,44,217,12,0,0,0,0,0,0,0,0,128,37,155,1,0,0,0,0,0,0,0,0,176,100,51,0,0,0,0,0,0,0,0,0,150,108,6,0,0,0,0,0,0,0,0,192,146,205,0,0,0,0,0,0,0,0,0,88,178,25,0,0,0,0,0,0,
0,0,0,75,54,3,0,0,0,0,0,0,0,0,96,201,102,0,0,0,0,0,0,0,0,0,44,217,12,0,0,0,0,0,0,0,0,128,37,155,1,0,0,0,0,0,0,0,0,176,100,51,0,0,0,0,0,0,0,0,0,150,108,6,0,0,0,0,0,0,0,0,192,146,205,0,0,0,0,0,0,0,0,0,88,
178,25,0,0,0,0,0,0,0,0,0,75,54,3,0,0,0,0,0,0,0,0,96,201,102,0,0,0,0,0,0,0,0,0,44,217,12,0,0,0,0,0,0,0,0,128,37,155,1,0,0,0,0,0,0,0,0,176,100,51,0,0,0,0,0,0,0,0,0,150,108,6,0,0,0,0,0,0,0,0,192,146,205,
0,0,0,0,0,0,0,0,0,88,178,25,0,0,0,0,0,0,0,0,0,75,54,3,0,0,0,0,0,0,0,0,96,201,102,0,0,0,0,0,0,0,0,0,44,217,12,0,0,0,0,0,0,0,0,128,37,155,1,0,0,0,0,0,0,0,0,176,100,51,0,0,0,0,0,0,0,0,0,150,108,6,0,0,0,0,
0,0,0,0,192,146,205,0,0,0,0,0,0,0,0,0,88,178,25,0,0,0,0,0,0,0,0,0,75,54,3,0,0,0,0,0,0,0,0,96,201,102,0,0,0,0,0,0,0,0,0,44,217,12,0,0,0,0,0,0,0,0,128,37,155,1,0,0,0,0,0,0,0,0,176,100,51,0,0,0,0,0,0,0,0,
0,150,108,6,0,0,0,0,0,0,0,0,192,146,205,0,0,0,0,0,0,0,0,0,88,178,25,0,0,0,0,0,0,0,0,0,75,54,3,0,0,0,0,0,0,0,0,96,201,102,0,0,0,0,0,0,0,0,0,44,217,12,0,0,0,0,0,0,0,0,128,37,155,1,0,0,0,0,0,0,0,0,176,100,
51,0,0,0,0,0,0,0,0,0,150,108,6,0,0,0,0,0,0,0,0,192,146,205,0,0,0,0,0,0,0,0,0,88,178,25,0,0,0,0,0,0,0,0,0,75,54,3,0,0,0,0,0,0,0,0,96,201,102,0,0,0,0,0,0,0,0,0,44,217,12,0,0,0,0,0,0,0,0,128,37,155,1,0,0,
0,0,0,0,0,0,176,100,51,0,0,0,0,0,0,0,0,0,150,108,6,0,0,0,0,0,0,0,0,192,146,205,0,0,0,0,0,0,0,0,0,88,178,25,0,0,0,0,0,0,0,0,0,75,54,3,0,0,0,0,0,0,0,0,96,201,102,0,0,0,0,0,0,0,0,0,44,217,12,0,0,0,0,0,0,
0,0,128,37,155,1,0,0,0,0,0,0,0,0,176,100,51,0,0,0,0,0,0,0,0,0,150,108,6,0,0,0,0,0,0,0,0,192,146,205,0,0,0,0,0,0,0,0,0,88,178,25,0,0,0,0,0,0,0,0,0,75,54,3,0,0,0,0,0,0,0,0,96,201,102,0,0,0,0,0,0,0,0,0,44,
217,12,0,0,0,0,0,0,0,0,128,37,155,1,0,0,0,0,0,0,0,0,176,100,51,0,0,0,0,0,0,0,0,0,150,108,6,0,0,0,0,0,0,0,0,192,146,205,0,0,0,0,0,0,0,0,0,88,178,25,0,0,0,0,0,0,0,0,0,75,54,3,0,0,0,0,0,0,0,0,96,201,102,
0,0,0,0,0,0,0,0,0,44,217,12,0,0,0,0,0,0,0,0,128,37,155,1,0,0,0,0,0,0,0,0,176,100,51,0,0,0,0,0,0,0,0,0,150,108,6,0,0,0,0,0,0,0,0,192,146,205,0,0,0,0,0,0,0,0,0,88,178,25,0,0,0,0,0,0,0,0,0,75,54,3,0,0,0,
0,0,0,0,0,96,201,102,0,0,0,0,0,0,0,0,0,44,217,12,0,0,0,0,0,0,0,0,128,37,155,1,0,0,0,0,0,0,0,0,176,100,51,0,0,0,0,0,0,0,0,0,150,108,6,0,0,0,0,0,0,0,0,192,146,205,0,0,0,0,0,0,0,0,0,88,178,25,0,0,0,0,0,0,
0,0,0,75,54,3,0,0,0,0,0,0,0,0,96,201,102,0,0,0,0,0,0,0,0,0,44,217,12,0,0,0,0,0,0,0,0,128,37,155,1,0,0,0,0,0,0,0,0,176,100,51,0,0,0,0,0,0,0,0,0,150,108,6,0,0,0,0,0,0,0,0,192,146,205,0,0,0,0,0,0,0,0,0,88,
178,25,0,0,0,0,0,0,0,0,0,75,54,3,0,0,0,0,0,0,0,0,96,201,102,0,0,0,0,0,0,0,0,0,44,217,12,0,0,0,0,0,0,0,0,128,37,155,1,0,0,0,0,0,0,0,0,176,100,51,0,0,0,0,0,0,0,0,0,150,108,6,0,0,0,0,0,0,0,0,192,146,205,
0,0,0,0,0,0,0,0,0,88,178,25,0,0,0,0,0,0,0,0,0,75,54,3,0,0,0,0,0,0,0,0,96,201,102,0,0,0,0,0,0,0,0,0,44,217,12,0,0,0,0,0,0,0,0,128,37,155,1,0,0,0,0,0,0,0,0,176,100,51,0,0,0,0,0,0,0,0,0,150,108,6,0,0,0,0,
0,0,0,0,192,10,0,0,255,255,3,0,213,16,1,84,223,115,14,150,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* WillStereoDelayAudioProcessorEditor::semiquaver_png = (const char*) resource_WillStereoDelayAudioProcessorEditor_semiquaver_png;
const int WillStereoDelayAudioProcessorEditor::semiquaver_pngSize = 55201;


//[EndFile] You can add extra defines here...
//[/EndFile]
