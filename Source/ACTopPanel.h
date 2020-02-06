/*
  ==============================================================================

    ACTopPanel.h
    Created: 17 Jan 2020 1:33:48pm
    Author:  Spencer Ward

  ==============================================================================
*/

#pragma once

#include "ACPanelBase.h"

class ACTopPanel
: public ACPanelBase
{
public:
    
    ACTopPanel(AcparametricEq111619AudioProcessor* inProcessor);
    ~ACTopPanel();
    
    void paint(Graphics& g) override;
    
private:
    
};
