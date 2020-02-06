/*
  ==============================================================================

    ACEQDialPanel.h
    Created: 4 Jan 2020 4:09:23pm
    Author:  Spencer Ward

  ==============================================================================
*/

#pragma once

#include "ACPanelBase.h"
#include "ACParameterSlider.h"

class ACEQDialPanel
:   public ACPanelBase
{
public:

    ACEQDialPanel(AcparametricEq111619AudioProcessor* inProcessor);
    ~ACEQDialPanel();

    void paint(Graphics& g) override;

    void setParameterID(int inParameterID);

private:

    OwnedArray<ACParameterSlider> mSliders;
    
};
