/*
  ==============================================================================

    ACTopPanel.cpp
    Created: 17 Jan 2020 1:33:48pm
    Author:  Spencer Ward

  ==============================================================================
*/

#include "ACTopPanel.h"

ACTopPanel::ACTopPanel(AcparametricEq111619AudioProcessor* inProcessor)
: ACPanelBase(inProcessor)
{
    setSize(TOP_PANEL_WIDTH, TOP_PANEL_HEIGHT);
}

ACTopPanel::~ACTopPanel()
{
    
}

void ACTopPanel::paint(Graphics& g)
{
    ACPanelBase::paint(g);
    
    g.drawFittedText("Audio Crossover Parameteric Equalizer", 0, 0, getWidth(), getHeight(), Justification::centred, 1);

}
