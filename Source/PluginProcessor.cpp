/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "ACParameters.h"

//==============================================================================
AcparametricEq111619AudioProcessor::AcparametricEq111619AudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ),
        parameters(*this, nullptr)
#endif
{
    initializeParameters();
    
    initializeDSP();
}

AcparametricEq111619AudioProcessor::~AcparametricEq111619AudioProcessor()
{
}

//==============================================================================
const String AcparametricEq111619AudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool AcparametricEq111619AudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool AcparametricEq111619AudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool AcparametricEq111619AudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double AcparametricEq111619AudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int AcparametricEq111619AudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int AcparametricEq111619AudioProcessor::getCurrentProgram()
{
    return 0;
}

void AcparametricEq111619AudioProcessor::setCurrentProgram (int index)
{
}

const String AcparametricEq111619AudioProcessor::getProgramName (int index)
{
    return {};
}

void AcparametricEq111619AudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void AcparametricEq111619AudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    
    for(int i = 0; i < 2; i++){
        mHPFilter[i]->setSampleRate(sampleRate);
    }

//    ACEqualizer::reset();
    
}

void AcparametricEq111619AudioProcessor::releaseResources()
{

    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool AcparametricEq111619AudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
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

void AcparametricEq111619AudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();


    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    
        mHPFilter[0]->calculateLPFCoeffs(getParameter(aParameter_CutoffFrequency), getParameter(aParameter_Q), getParameter(aParameter_CutBoost), m_F_b1, m_F_b2, m_F_a0, m_F_a1, m_F_a2, m_F_c0, m_F_d0);

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
        
        mGain[channel]->process(channelData,
                       1.0f,
                       channelData,
                       buffer.getNumSamples());
        
        mHPFilter[channel]->process(channelData,
                                    channel,
                                    channelData,
                                    buffer.getNumSamples());


        // ..do something to the data...
    }
}

//==============================================================================
bool AcparametricEq111619AudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* AcparametricEq111619AudioProcessor::createEditor()
{
    return new AcparametricEq111619AudioProcessorEditor (*this);
}

//==============================================================================
void AcparametricEq111619AudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void AcparametricEq111619AudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

float AcparametricEq111619AudioProcessor::getMagnitudeResponse(double frequency)
{
    
    auto magnitude = mHPFilter[0]->getMagnitudeForFrequency(frequency,
    mSampleRate,
    m_F_b1,
    m_F_b2,
    m_F_a0,
    m_F_a1,
    m_F_a2);
    
//            std::cout << " Frequency " << frequency << std::endl;
//            std::cout << " Magnitude in getMagnitudeResponse function " << magnitude << std::endl;
//
//            std::cout << " m_F_b1 " << m_F_b1 << std::endl;
//            std::cout << " m_F_b2 " << m_F_b2 << std::endl;
//            std::cout << " m_F_a0 " << m_F_a0 << std::endl;
//            std::cout << " m_F_a1 " << m_F_a1 << std::endl;
//            std::cout << " m_F_a2 " << m_F_a2 << std::endl;
    
    return magnitude;
}

void AcparametricEq111619AudioProcessor::initializeParameters()
{
    for(int i = 0; i < aParameter_TotalNumParameters; i++)
    {
        parameters.createAndAddParameter(ACParameterID[i],
        ACParameterID[i],
        ACParameterID[i],
        NormalisableRange<float>(0.0f, 1.0f),
                                         0.5f, nullptr, nullptr);

    }
    
    
}

void AcparametricEq111619AudioProcessor::initializeDSP()
{
    for(int i = 0; i < 2; i++)
    {
        mGain[i] = std::make_unique<ACGain>();
        mHPFilter[i] = std::make_unique<ACEqualizer>();
    }
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new AcparametricEq111619AudioProcessor();
}


