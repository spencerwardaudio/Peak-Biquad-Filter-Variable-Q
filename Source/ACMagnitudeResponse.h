/*
  ==============================================================================

    ACMagnitudeResponse.h
    Created: 19 Jan 2020 7:04:02pm
    Author:  Spencer Ward

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "ACEqualizer.h"

class ACMagnitudeResponse
:   public Component, public ACEqualizer , public Timer
{


public:
    ACMagnitudeResponse(AcparametricEq111619AudioProcessor* inProcessor);
    ~ACMagnitudeResponse();

//    /** Pushes the data to display (several outputs). */
//    void pushData (const AudioBuffer<float> &dataXY, int numPoints, int numEntries);
    
    
    /** @internal */
    void paint (Graphics& g) override;

    void timerCallback() override;

    void setParameterID(int inParameterID);

private:

//    const static int N = 1001;
//
//    struct DataStructure
//    {
//        DataStructure()
//        {
//            numPoints.store (0);
//            numEntries.store (0);
//        }
//
//        Array<float> dataX;
//        Array<Array<float>> dataY;
//
//        std::atomic<int> numPoints;
//        std::atomic<int> numEntries;
//    };
//
//
    int mParameterID;
//
//    DataStructure dataStructure;
//
//    AudioBuffer<float> bufferData;
    
//    std::unique_ptr<ACEqualizer> mCoefficients;
    
//    ACEqualizer* mCoefficients;

    AcparametricEq111619AudioProcessor* mProcessor;

//    ACEqualizer* mCoefficients;
};
