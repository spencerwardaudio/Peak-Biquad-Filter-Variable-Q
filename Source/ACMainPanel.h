/*
  ==============================================================================

    ACMainPanel.h
    Created: 4 Jan 2020 3:03:12pm
    Author:  Spencer Ward

  ==============================================================================
*/

#pragma once

#include "ACPanelBase.h"

#include "ACTopPanel.h"
#include "ACFilterGraph.h"
#include "ACEQDialPanel.h"


class ACMainPanel
:   public ACPanelBase
{
public:
    
    ACMainPanel(AcparametricEq111619AudioProcessor* inProcessor);
    ~ACMainPanel();
    
private:
    
    std::unique_ptr<ACTopPanel> mTopPanel;
    std::unique_ptr<ACFilterGraph> mFilterGraph;
    std::unique_ptr<ACEQDialPanel> mEQDialPanel;
    
};
