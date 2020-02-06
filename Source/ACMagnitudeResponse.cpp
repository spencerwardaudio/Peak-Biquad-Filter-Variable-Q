/*
  ==============================================================================

    ACMagnitudeResponse.cpp
    Created: 19 Jan 2020 7:04:02pm
    Author:  Spencer Ward

  ==============================================================================
*/

#include "ACMagnitudeResponse.h"
#include "ACInterfaceDefines.h"

ACMagnitudeResponse::ACMagnitudeResponse(AcparametricEq111619AudioProcessor* inProcessor)
: mProcessor(inProcessor)

/*mParameterID(-1),*/
//mCoefficients(mCoefficients)
{
    
}
ACMagnitudeResponse::~ACMagnitudeResponse()
{
    
}
   

//void ACMagnitudeResponse::pushData (const AudioBuffer<float> &dataXY, int numPoints, int numEntries)
//{
//    dataStructure.dataX.clear();
//    dataStructure.dataX.addArray (dataXY.getReadPointer (0), numPoints);
//
//    dataStructure.dataY.clear();
//    for (auto i = 0; i < numEntries; i++)
//        dataStructure.dataY.add (Array<float> (dataXY.getReadPointer (1 + i), numPoints));
//
//    dataStructure.numPoints.store (numPoints);
//    dataStructure.numEntries.store (numEntries);
//}

void ACMagnitudeResponse::paint(Graphics& g)
{

//    bufferData.setSize (2, N, false, false, true);
//
//    g.setColour(Colours::blueviolet);
//    g.drawLine(0, FILTER_GRAPH_HEIGHT, FILTER_GRAPH_WIDTH, FILTER_GRAPH_HEIGHT/2, 5);

    
//        std::cout << " Frequency " << frequency << std::endl;
//        std::cout << " Magnitude " << magnitude << std::endl;


//        Array<double> dataX[i] = frequency;
//        auto dataY[i] = (float)Decibels::gainToDecibels (magnitude);
    
    
    
    auto N = 1001;

    for (auto i = 0; i < N; i++)
    {
        auto frequency = jmap(i / (1001 - 1.0), 10.0, 22000.0);
        auto magnitude = mProcessor->getMagnitudeResponse(frequency);

//        std::cout << " magnitude in magnitude response loop " << magnitude << std::endl;


        auto scaledFreq = ((450.0 / 22000.0) * frequency);
        auto scaledMag = FILTER_GRAPH_HEIGHT * magnitude;

        g.setColour(Colours::blueviolet);
        g.drawLine(scaledFreq, scaledMag, scaledFreq, scaledMag -3, 5);

        }
    
    g.setColour(Colours::blueviolet);
    g.drawLine(0, 0, getWidth(), getHeight(), 5);
    
    
    
    
//
//        information.minimumXValue = 10.0;
//        information.maximumXValue = 22000.0;
//
////        auto numPoints = dataStructure.numPoints.load();
////        auto numEntries = dataStructure.numEntries.load();
//
//        auto *dataX = bufferData.getWritePointer (0);
//        auto *dataY = bufferData.getWritePointer (1);
//
//            for (auto n = 0; n < numEntries; n++)
//            {
//
//                for (auto i = 0; i < numPoints; i++)
//                {
//                    auto valueX = dataStructure.dataX[i];
//                    auto valueY = dataStructure.dataY[n][i];
//                    }
//                }
//        }
    

    
    /*
     
     #include <stdo.h>
     #include <math.h>
     
     #define SAMPLING_RATE 44100
     #define NUM_SECONDS 3
     #define NUM_SAMPLES (NUM_SECONDS * SAMPLING_RATE)
     #define PI 3.14
     #define FREQUENCY 440
     
     main()
     {
        int j;
     for(j = 0; j < NUM_SAMPLES; j++){
     float sample;
        sample = sin(2 * PI * FREQUENCY * j / SAMPLING_RATE);
        printf("%f\n", sample);
     }
     }
     */
    
    
    }

void ACMagnitudeResponse::timerCallback()
{

    float tempfCutoffFreqMapped = 0.0;

    float tempfQMapped = 0.0;

    float tempGainMapped = 0.0;

    if(m_fCutoffFreqMapped != tempfCutoffFreqMapped){
        tempfCutoffFreqMapped = m_fCutoffFreqMapped;
        repaint();
    }

    if(m_fQMapped != tempfQMapped){
        tempfQMapped = m_fQMapped;
        repaint();
    }

    if(m_GainMapped != tempGainMapped){
        tempGainMapped = m_GainMapped;
        repaint();
    }
}


void ACMagnitudeResponse::setParameterID(int inParameterID)
{
    mParameterID = inParameterID;
    
    startTimerHz(15);
}




