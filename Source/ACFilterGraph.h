/*
  ==============================================================================

    ACFilterGraph.h
    Created: 19 Jan 2020 6:34:28pm
    Author:  Spencer Ward

  ==============================================================================
*/

#pragma once

#include "ACPanelBase.h"
#include "ACMagnitudeResponse.h"

class ACFilterGraph
:   public ACPanelBase
{
    public:
    
    ACFilterGraph(AcparametricEq111619AudioProcessor* inProcessor);
    ~ACFilterGraph();
    
    void paint(Graphics& g) override;
    
    void setParameterID(int inParameterID);

private:
    
    std::unique_ptr<ACMagnitudeResponse> mMagnitudeResponse;
    
};
