/*
  ==============================================================================

    ACParameters.h
    Created: 3 Jan 2020 11:25:16pm
    Author:  Spencer Ward

  ==============================================================================
*/

#pragma once

enum ACParameter
{
    aParameter_InputGain = 0,
    aParameter_CutoffFrequency,
    aParameter_Q,
    aParameter_CutBoost,
    aParameter_TotalNumParameters,
};

static String ACParameterID [aParameter_TotalNumParameters] =
{
    "InputGain",
    "CutoffFrequency",
    "Q",
    "Cut/Boost",
};
