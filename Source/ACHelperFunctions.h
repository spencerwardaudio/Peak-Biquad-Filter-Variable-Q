/*
  ==============================================================================

    ACHelperFunctions.h
    Created: 4 Jan 2020 4:23:16pm
    Author:  Spencer Ward

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "ACInterfaceDefines.h"

inline void paintComponentLabel(Graphics& g, Component* inComponent)
{
    const int x = inComponent->getX() - (inComponent->getWidth() * 0.25f);
    const int y = inComponent->getY() + inComponent->getHeight();
    const int w = inComponent->getWidth() * 1.5f;
    const int h = 20;
    
    const float cornerSize = 3.0f;
    
    const String label = inComponent->getName();
    
    g.setColour(ACColour_1);
    g.fillRoundedRectangle(x, y, w, h, cornerSize);
    
    g.setColour(ACColour_1);
    g.setFont(font_1);
    
    g.drawFittedText(label, x, y, w, h, Justification::centred, 1);
}
