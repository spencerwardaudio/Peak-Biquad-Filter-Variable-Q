/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

#include "ACMainPanel.h"
#include "ACFilterGraph.h"

//==============================================================================
/**
*/
class AcparametricEq111619AudioProcessorEditor  : public AudioProcessorEditor
{
public:
    AcparametricEq111619AudioProcessorEditor (AcparametricEq111619AudioProcessor&);
    ~AcparametricEq111619AudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:

    AcparametricEq111619AudioProcessor& processor;
    
    std::unique_ptr<ACMainPanel> mMainPanel;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AcparametricEq111619AudioProcessorEditor)
};
