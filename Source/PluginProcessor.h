/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "DigitalDelayLine.h"


//==============================================================================
/**
*/
class WillStereoDelayAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    WillStereoDelayAudioProcessor();
    ~WillStereoDelayAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    AudioParameterInt* leftMix_param;
    AudioParameterInt* rightMix_param;
    AudioParameterFloat* leftDelayTime_param;
    AudioParameterFloat* rightDelayTime_param;
    AudioParameterInt* leftFeedback_param;
    AudioParameterInt* rightFeedback_param;
    AudioParameterInt* leftLPF_param;
    AudioParameterInt* rightLPF_param;
    AudioParameterInt* leftHPF_param;
    AudioParameterInt* rightHPF_param;
    AudioParameterInt* leftCrossLevel_param;
    AudioParameterInt* rightCrossLevel_param;
    
    float ChannelLeftBuffer;
    float ChannelRightBuffer;

    double mins_in_msL;
    double mins_in_msR;
    float noteValDelayL;
    float noteValDelayR;
    double BPM;
    int leftInputSelection;
    int rightInputSelection;



private:
    
    DigitalDelayLine delay_left;
    DigitalDelayLine delay_right;
    
    AudioPlayHead* playHead;
    AudioPlayHead::CurrentPositionInfo currentPositionInfo;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WillStereoDelayAudioProcessor)
};

#endif  // PLUGINPROCESSOR_H_INCLUDED

