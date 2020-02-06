/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

#include "ACGain.h"
#include "ACEqualizer.h"

//==============================================================================
/**
*/
class AcparametricEq111619AudioProcessor  : public AudioProcessor, public ACEqualizer
{
public:
    //==============================================================================
    AcparametricEq111619AudioProcessor();
    ~AcparametricEq111619AudioProcessor();

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
    
    float getMagnitudeResponse(double frequency);
    
    AudioProcessorValueTreeState parameters;

private:
    
    /** internal */
    void initializeParameters();
    
    /** internal */
    void initializeDSP();
    
    std::unique_ptr<ACGain> mGain[2];
    std::unique_ptr<ACEqualizer> mHPFilter[2];
//    std::unique_ptr<ACEqualizer> mCoefficientsMagnitude;
    
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AcparametricEq111619AudioProcessor)
};
