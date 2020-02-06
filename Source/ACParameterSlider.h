/*
  ==============================================================================

    ACParameterSlider.h
    Created: 4 Jan 2020 3:59:23pm
    Author:  Spencer Ward

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class ACParameterSlider
: public Slider
{
public:
    
    ACParameterSlider(AudioProcessorValueTreeState& stateToControl,
                      const String& parameterID);
    ~ACParameterSlider();
    

private:
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> mAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ACParameterSlider);
};
