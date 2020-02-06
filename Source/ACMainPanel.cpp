/*
  ==============================================================================

    ACMainPanel.cpp
    Created: 4 Jan 2020 3:03:12pm
    Author:  Spencer Ward

  ==============================================================================
*/

#include "ACMainPanel.h"
#include "ACParameters.h"

ACMainPanel::ACMainPanel(AcparametricEq111619AudioProcessor* inProcessor)
:   ACPanelBase(inProcessor)
{
    setSize(MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);
    
    mTopPanel = std::make_unique<ACTopPanel>(inProcessor);
    mTopPanel->setTopLeftPosition(0, 0);
    addAndMakeVisible(mTopPanel.get());
    
    mFilterGraph = std::make_unique<ACFilterGraph>(inProcessor);
    mFilterGraph->setTopLeftPosition(0, TOP_PANEL_HEIGHT);
    addAndMakeVisible(mFilterGraph.get());
    
    
    mEQDialPanel = std::make_unique<ACEQDialPanel>(inProcessor);
    mEQDialPanel->setTopLeftPosition(0, TOP_PANEL_HEIGHT + FILTER_GRAPH_HEIGHT);
    mEQDialPanel->setParameterID(aParameter_InputGain);
    mEQDialPanel->setParameterID(aParameter_CutoffFrequency);
    mEQDialPanel->setParameterID(aParameter_CutBoost);
    mEQDialPanel->setParameterID(aParameter_Q);
    addAndMakeVisible(mEQDialPanel.get());
}

ACMainPanel::~ACMainPanel()
{
    
}
