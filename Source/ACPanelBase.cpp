/*
  ==============================================================================

    ACPanelBase.cpp
    Created: 3 Jan 2020 11:39:29pm
    Author:  Spencer Ward

  ==============================================================================
*/

#include "ACPanelBase.h"

ACPanelBase::ACPanelBase(AcparametricEq111619AudioProcessor* inProcessor)
:   mProcessor(inProcessor)
{
    
}

ACPanelBase::~ACPanelBase()
{
    
}

void ACPanelBase::mouseEnter (const MouseEvent& event)
{
    repaint();
}

void ACPanelBase::mouseExit (const MouseEvent& event)
{
    repaint();
}

void ACPanelBase::paint (Graphics& g)
{
//    if(isMouseOver()){
//        g.setColour(KAPColour_4);
//        g.fillAll();
//    }
    
    g.setColour(Colours::whitesmoke);
    g.fillAll();
    
    g.setColour(Colours::black);
    g.drawRect(0, 0, getWidth(), getHeight());
}
