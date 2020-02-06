/*
  ==============================================================================

    ACParameterSlider.cpp
    Created: 4 Jan 2020 3:59:23pm
    Author:  Spencer Ward

  ==============================================================================
*/

#include "ACParameterSlider.h"

ACParameterSlider::ACParameterSlider(AudioProcessorValueTreeState& stateToControl,
                                     const String& parameterID)
:   juce::Slider(parameterID)
{
    setSliderStyle(SliderStyle::RotaryHorizontalVerticalDrag);
    setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, false, 0, 0);
    
    mAttachment =
    std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(stateToControl, parameterID, *this);
}

ACParameterSlider::~ACParameterSlider()
{
    
}

