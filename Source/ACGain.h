/*
  ==============================================================================

    ACGain.h
    Created: 18 Nov 2019 5:40:49pm
    Author:  Spencer Ward

  ==============================================================================
*/

#pragma once

class ACGain
{
    
public:
    ACGain();
    ~ACGain();
    
void process(float* inAudio,
             float inGain,
             float* outAudio,
             int inNumSamplesToRender);
    
private:
    
};
