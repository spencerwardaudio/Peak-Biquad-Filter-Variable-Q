/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AcparametricEq111619AudioProcessorEditor::AcparametricEq111619AudioProcessorEditor (AcparametricEq111619AudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{

    setSize(MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);
    
    mMainPanel = std::make_unique<ACMainPanel>(&processor);
    addAndMakeVisible(mMainPanel.get());
}

AcparametricEq111619AudioProcessorEditor::~AcparametricEq111619AudioProcessorEditor()
{
}

//==============================================================================
void AcparametricEq111619AudioProcessorEditor::paint (Graphics& g)
{
   
}

void AcparametricEq111619AudioProcessorEditor::resized()
{

}
