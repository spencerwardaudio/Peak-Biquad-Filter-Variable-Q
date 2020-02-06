/*
  ==============================================================================

    ACGain.cpp
    Created: 18 Nov 2019 5:40:49pm
    Author:  Spencer Ward

  ==============================================================================
*/

#include "ACGain.h"
#include "ACAudioHelpers.h"

ACGain::ACGain()
{
    
}

ACGain::~ACGain()
{
    
}

void ACGain::process(float* inAudio,
             float inGain,
             float* outAudio,
             int inNumSamplesToRender)
    {
//        float gainMapped = jmap(inGain, 0.0f, 1.0f, -24.0f, 24.0f);
//        gainMapped = Decibels::decibelsToGain(gainMapped, -24.0f);
        
        for(int i = 0; i <inNumSamplesToRender; i++){
            outAudio[i] = inAudio[i] * inGain;
        };
    
        
    }
