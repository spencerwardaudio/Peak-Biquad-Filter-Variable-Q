/*
  ==============================================================================

    ACEQDialPanel.cpp
    Created: 4 Jan 2020 4:09:23pm
    Author:  Spencer Ward

  ==============================================================================
*/

#include "ACEQDialPanel.h"
#include "ACParameters.h"
#include "ACHelperFunctions.h"

ACEQDialPanel::ACEQDialPanel(AcparametricEq111619AudioProcessor* inProcessor)
:   ACPanelBase(inProcessor)
{
    setSize(EQDial_PANEL_WIDTH, EQDial_PANEL_HEIGHT);
}

ACEQDialPanel::~ACEQDialPanel()
{
    
}

void ACEQDialPanel::paint(Graphics& g)
{
    ACPanelBase::paint(g);
    
    String label;
    
    label = "Parametric";

    g.setColour(ACColour_5);
    g.setFont(font_3);

    g.drawText(label, 0, 0, getWidth(), 60, Justification::centred);
    
//    if(mSliders){
//        paintComponentLabel(g, mSliders.get());
//    }
    
    // paint labels
    for(int i = 0; i < mSliders.size(); i++){
        paintComponentLabel(g, mSliders[i]);
    }
}

void ACEQDialPanel::setParameterID(int inParameterID)
{
    mSliders.clear();
    
    const int slider_size = 56;
    
    int x = 20;
    int y = (getHeight() * 0.15);

    
    ACParameterSlider* inputGain =
    new ACParameterSlider(mProcessor->parameters,
        ACParameterID[aParameter_InputGain]);
    inputGain->setBounds(x, y, slider_size, slider_size);
    addAndMakeVisible(inputGain);
    mSliders.add(inputGain);
    x = x + (slider_size*2);

    ACParameterSlider* cutoff =
    new ACParameterSlider(mProcessor->parameters,
                          ACParameterID[aParameter_CutoffFrequency]);
    cutoff->setBounds(x, y, slider_size, slider_size);
//    cutoff->juce::Slider::setRange(20.0, 22000.0, 0.01);
//    cutoff->setSkewFactor(0.2);
//    cutoff->setValue(1000.0, dontSendNotification);
    addAndMakeVisible(cutoff);
    mSliders.add(cutoff);
    x = x + (slider_size*2);
    
    ACParameterSlider* cutBoost = new ACParameterSlider(mProcessor->parameters,
                                                  ACParameterID[aParameter_CutBoost]);
    cutBoost->setBounds(x, y, slider_size, slider_size);
//    cutBoost->juce::Slider::setRange(-12.0, 12.0);
    addAndMakeVisible(cutBoost);
    mSliders.add(cutBoost);
    x = x + (slider_size*2);
    
    ACParameterSlider* Q =
    new ACParameterSlider(mProcessor->parameters,
                          ACParameterID[aParameter_Q]);
    Q->setBounds(x, y, slider_size, slider_size);
//    Q->juce::Slider::setRange(0.33, 12.0);
//    Q->setSkewFactor(0.1);
//    Q->setValue(1.0 / std::sqrt (2.0), dontSendNotification);
    addAndMakeVisible(Q);
    mSliders.add(Q);
    



//    ACParameterSlider* cutBoost
//
//    ACParameterSlider* Q
    
    
//    mSliders = std::make_unique<ACParameterSlider>(mProcessor->parameters, ACParameterID[inParameterID]);
//    const int slider_size = 54;
//
//    mSliders->setBounds((getWidth() * 0.5) - (slider_size * 0.5),
//                       (getHeight() * 0.2) - (slider_size * 0.5) - 10,
//                       slider_size,
//                       slider_size);
//
//    addAndMakeVisible(mSliders.get());
}
