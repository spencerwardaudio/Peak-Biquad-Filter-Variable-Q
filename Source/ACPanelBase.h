/*
  ==============================================================================

    ACPanelBase.h
    Created: 3 Jan 2020 11:39:29pm
    Author:  Spencer Ward

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "ACInterfaceDefines.h"

class ACPanelBase
:   public Component
{
public:
    
    ACPanelBase(AcparametricEq111619AudioProcessor* inProcessor);
    ~ACPanelBase();
    
    void mouseEnter (const MouseEvent& event) override;

    void mouseExit (const MouseEvent& event) override;
    
    void paint (Graphics& g) override;
    
protected:
    
    AcparametricEq111619AudioProcessor* mProcessor;
    
};
