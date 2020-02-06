/*
  ==============================================================================

    ACFilterGraph.cpp
    Created: 19 Jan 2020 6:34:28pm
    Author:  Spencer Ward

  ==============================================================================
*/

#include "ACFilterGraph.h"
#include "ACInterfaceDefines.h"

ACFilterGraph::ACFilterGraph(AcparametricEq111619AudioProcessor* inProcessor)
: ACPanelBase(inProcessor)
{
    setSize(FILTER_GRAPH_WIDTH, FILTER_GRAPH_HEIGHT);

    mMagnitudeResponse = std::make_unique<ACMagnitudeResponse>(mProcessor);
    mMagnitudeResponse->setBounds(0, 0, getWidth(), getHeight());
    addAndMakeVisible(mMagnitudeResponse.get());
}

ACFilterGraph::~ACFilterGraph()
{

}
    
void ACFilterGraph::paint(Graphics& g)
{
    ACPanelBase::paint(g);
    
    

}

void ACFilterGraph::setParameterID(int inParameterID)
{
    mMagnitudeResponse->setParameterID(inParameterID);
}


