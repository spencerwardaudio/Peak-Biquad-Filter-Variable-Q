/*
  ==============================================================================

    ACAudioHelpers.h
    Created: 16 Nov 2019 10:39:21pm
    Author:  Spencer Ward

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

#define aParameterSmoothingCoeff 0.2

inline float kap_linear_interp(float v0, float v1, float t)
{
    return (1 - t) * v0 + t * v1;
}
