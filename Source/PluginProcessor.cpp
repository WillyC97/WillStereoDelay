/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

double SampleRate;

//==============================================================================
WillStereoDelayAudioProcessor::WillStereoDelayAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
    addParameter(leftMix_param = new AudioParameterInt("LeftMix", "Left Mix", 0, 100, 30));
    addParameter(rightMix_param = new AudioParameterInt("RightMix", "Left Mix", 0, 100, 30));
    addParameter(leftDelayTime_param = new AudioParameterFloat("LeftDelayTime", "Left Delay Time", 0, 2000, 0));
    addParameter(rightDelayTime_param = new AudioParameterFloat("RightDelayTime", "Right Delay Time", 0, 2000, 0));
    addParameter(leftFeedback_param = new AudioParameterInt("LeftFeedback", "Left Feedback", -100, 100, 0));
    addParameter(rightFeedback_param = new AudioParameterInt("RightFeedback", "Right Feedback", -100, 100, 0));
    addParameter(leftLPF_param = new AudioParameterInt("LeftLPF", "Left LPF", 20, 20000, 20000));
    addParameter(rightLPF_param = new AudioParameterInt("RightLPF", "Right LPF", 20, 20000, 20000));
    addParameter(leftHPF_param = new AudioParameterInt("LeftHPF", "Left HPF", 20, 20000, 20));
    addParameter(rightHPF_param = new AudioParameterInt("RightHPF", "Right HPF", 20, 20000, 20));
    addParameter(leftCrossLevel_param = new AudioParameterInt("LeftCross", "Left Cross", 0, 100, 0));
    addParameter(rightCrossLevel_param = new AudioParameterInt("RightCross", "Right Feedback", 0, 100, 0));
    addParameter(tremoloAmount_param = new AudioParameterFloat("TremoloAmount", "Tremolo Amount", 0, 1, 0));
    addParameter(tremoloRate_param = new AudioParameterFloat("TremoloRate", "Tremolo Rate", 0, 20, 0));
    addParameter(bitDepth_param = new AudioParameterInt("bitDepth", "Bit Depth", 4, 32, 24));
    addParameter(bitRate_param = new AudioParameterInt("bitRate", "Bit Rate", 1, 50, 1));


}

WillStereoDelayAudioProcessor::~WillStereoDelayAudioProcessor()
{
}

//==============================================================================
const String WillStereoDelayAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool WillStereoDelayAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool WillStereoDelayAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool WillStereoDelayAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double WillStereoDelayAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int WillStereoDelayAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int WillStereoDelayAudioProcessor::getCurrentProgram()
{
    return 0;
}

void WillStereoDelayAudioProcessor::setCurrentProgram (int index)
{
}

const String WillStereoDelayAudioProcessor::getProgramName (int index)
{
    return {};
}

void WillStereoDelayAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void WillStereoDelayAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    
    
    delay_left.createBuffer();
    delay_right.createBuffer();
    
    delay_left.setSampleRate(sampleRate);
    delay_right.setSampleRate(sampleRate);
    
    delay_left.updateAngleDelta();
    delay_right.updateAngleDelta();
    
    SampleRate = sampleRate;
   
}



void WillStereoDelayAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool WillStereoDelayAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void WillStereoDelayAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    
   
    
//ScopedNoDenormals noDenormals;
//    auto totalNumInputChannels  = getTotalNumInputChannels();
//    auto totalNumOutputChannels = getTotalNumOutputChannels();

    //THIS IS NUM SAMPLES PER CHANNEL
    
    const int totalNumInputChannels  = getTotalNumInputChannels();
    const int totalNumOutputChannels = getTotalNumOutputChannels();
    const int numSamples = buffer.getNumSamples();
    
    for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    
    
    
    
    for(int i = 0; i < numSamples; i++){
        
        delay_left.calcFilterLPF(SampleRate, *leftLPF_param);
        delay_right.calcFilterLPF(SampleRate, *rightLPF_param);
        
        delay_left.calcFilterHPF(SampleRate, *leftHPF_param);
        delay_right.calcFilterHPF(SampleRate, *rightHPF_param);
        
        //delay_left.setCrossFeeedbackLevel(*leftCrossLevel_param);

        
        playHead = this->getPlayHead();
        playHead->getCurrentPosition (currentPositionInfo);
        
        BPM = currentPositionInfo.bpm;
        
                
        noteValDelayL = delay_left.calculateDelay(*leftDelayTime_param, BPM);
        noteValDelayR = delay_right.calculateDelay(*rightDelayTime_param, BPM);
        

        
        
        delay_left.setDelayTime(noteValDelayL);
        delay_right.setDelayTime(noteValDelayR);
        
        delay_left.setFeedback(*leftFeedback_param);
        delay_right.setFeedback(*rightFeedback_param);
        delay_left.setMixlevel(*leftMix_param);
        delay_right.setMixlevel(*rightMix_param);
        
        delay_left.setCrossFeedVal(*leftCrossLevel_param);
        delay_right.setCrossFeedVal(*rightCrossLevel_param);
        
        delay_left.setCurrentFeedbackInput(delay_right.getCurrentFeedbackOutput());
        delay_right.setCurrentFeedbackInput(delay_left.getCurrentFeedbackOutput());
        
        delay_left.setTremoloAmount(*tremoloAmount_param);
        delay_right.setTremoloAmount(*tremoloAmount_param);

        delay_left.setTremoloRate(*tremoloRate_param);
        delay_right.setTremoloRate(*tremoloRate_param);
        
        delay_left.setPostPreMixToggle(postPreMix);
        delay_right.setPostPreMixToggle(postPreMix);
        
        delay_left.setBitdepth(*bitDepth_param);
        delay_right.setBitdepth(*bitDepth_param);
        
        delay_left.setBitRate(*bitRate_param);
        delay_right.setBitRate(*bitRate_param);
        
            
            float* channelDataLeft = buffer.getWritePointer(0);
            float* channelDataRight = buffer.getWritePointer(1);
            //float* channelData = buffer.getWritePointer (channel);
        
        float leftChannelInput = channelDataLeft[i];
        float rightChannelInput = channelDataRight[i];
        
        switch (leftInputSelection) {
            case 1: leftChannelInput = channelDataLeft[i];break;
            case 2: leftChannelInput = channelDataRight[i];break;
            case 3: leftChannelInput = channelDataLeft[i] + channelDataRight[i];break;
            case 4: leftChannelInput = 0;break;
            default:
                break;
        }
        
        switch (rightInputSelection) {
            case 1: rightChannelInput = channelDataRight[i];break;
            case 2: rightChannelInput = channelDataLeft[i];break;
            case 3: leftChannelInput = channelDataLeft[i] + channelDataRight[i];break;
            case 4: rightChannelInput = 0;break;

            default:
                break;
        }
        
        
        
        channelDataLeft[i] = delay_left.next(leftChannelInput, 0, i);
        
        
            
            if(getTotalNumInputChannels() == 1 && getTotalNumOutputChannels() == 2){
                channelDataRight[i] = channelDataLeft[i];

            }
            
            //Stereo In , Stereo Out
            if(getTotalNumInputChannels() == 2 && getTotalNumOutputChannels() == 2){
                channelDataRight[i] = delay_right.next(rightChannelInput, 1, i);
                
            }
            
        
       
        
    }
}

//==============================================================================
bool WillStereoDelayAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* WillStereoDelayAudioProcessor::createEditor()
{
    return new WillStereoDelayAudioProcessorEditor (*this);
}

//==============================================================================
void WillStereoDelayAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    ScopedPointer<XmlElement> xml (new XmlElement ("WillStereoDelay"));
    
    xml->setAttribute ("LeftMix",        (double) *leftMix_param);
    xml->setAttribute ("RightMix",       (double) *rightMix_param);
    //xml->setAttribute ("LeftDelayTime",  (double) *leftDelayTime_param);
    //xml->setAttribute ("RightDelayTime", (double) *rightDelayTime_param);
    xml->setAttribute ("LeftFeedback",   (double) *leftFeedback_param);
    xml->setAttribute ("RightFeedback",  (double) *rightFeedback_param);
    xml->setAttribute ("LeftLPF",        (double) *leftLPF_param);
    xml->setAttribute ("RightLPF",       (double) *rightLPF_param);
    xml->setAttribute ("LeftHPF",        (double) *leftHPF_param);
    xml->setAttribute ("RightHPF",        (double) *rightHPF_param);
    
    copyXmlToBinary (*xml, destData);
}

void WillStereoDelayAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    ScopedPointer<XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));
    if (xmlState != nullptr)
    {
        if (xmlState->hasTagName ("WillStereoDelay"))
        {
            *leftMix_param           = xmlState->getDoubleAttribute ("LeftMix",        30.0);
            *rightMix_param          = xmlState->getDoubleAttribute ("RightMix",       30.0);
            //*leftDelayTime_param     = xmlState->getDoubleAttribute ("LeftDelayTime",  0.0);
            //*rightDelayTime_param    = xmlState->getDoubleAttribute ("RightDelayTime", 0.0);
            *leftFeedback_param      = xmlState->getDoubleAttribute ("LeftFeedback",   0.0);
            *rightFeedback_param     = xmlState->getDoubleAttribute ("RightFeedback",  0.0);
            *leftLPF_param           = xmlState->getDoubleAttribute ("LeftLPF",        0.0);
            *rightLPF_param          = xmlState->getDoubleAttribute ("RightLPF",       0.0);
            *leftHPF_param           = xmlState->getDoubleAttribute ("LeftHPF",        0.0);
            *rightHPF_param          = xmlState->getDoubleAttribute ("RightHPF",       0.0);
            
        }
    }
    
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new WillStereoDelayAudioProcessor();
}
