/*
 ==============================================================================
 
 ACEqualizer.h
 Created: 16 Nov 2019 10:24:17pm
 Author:  Spencer Ward
 
 ==============================================================================
 */

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class ACEqualizer
{
public:
    ACEqualizer();
    ~ACEqualizer();
    
    void setSampleRate(double inSampleRate);
    
    void reset();
    
    void calculateLPFCoeffs(float fCuttoffFreq, float fQ, float Gain,
                            float &m_F_b1,
                            float &m_F_b2,
                            float &m_F_a0,
                            float &m_F_a1,
                            float &m_F_a2,
                            float &m_F_c0,
                            float &m_F_d0
                            );
    
    //try putting m_fCutoffFreqMapped in getMa frequency space
    static const float getMagnitudeForFrequency(double frequency,
                         double mSampleRate,
                        const float m_F_b1,
                        const float m_F_b2,
                        const float m_F_a0,
                        const float m_F_a1,
                        const float m_F_a2);
    
    void process (float* inAudio,
                  int channelNumber,
                  float* outAudio,
                  int inNumSamplestoRender);
    
    float m_F_b1 {0};
    float m_F_b2 {0};
    float m_F_a0 {0};
    float m_F_a1 {0};
    float m_F_a2 {0};
    float m_F_c0 {0};
    float m_F_d0 {0};
    
    float m_fCutoffFreqMapped {0};
    float m_fQMapped {0};
    float m_GainMapped {0};
    
    double mSampleRate {48000.0};
    
private:
    
    float m_F_Xz_1 {0};
    float m_F_Xz_2 {0};
    float m_F_Yz_1 {0};
    float m_F_Yz_2 {0};
    
    struct FilterState
    {
        float v1;
    };

    FilterState Biquad[1];
    
};

//    const static filterCoefficientCalculations();
    

