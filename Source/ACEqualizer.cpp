/*
 ==============================================================================
 
 ACEqualizer.cpp
 Created: 16 Nov 2019 10:24:17pm
 Author:  Spencer Ward
 
 ==============================================================================
 */

#include "ACEqualizer.h"

#include <array>
#include <complex>


ACEqualizer::ACEqualizer()
: mSampleRate(-1.0)
{
    
}

ACEqualizer::~ACEqualizer()
{
    
}

void ACEqualizer::setSampleRate(double inSampleRate)
{
    mSampleRate = inSampleRate;
}

void ACEqualizer::reset()
{
    for (auto channel = 0; channel < 2; )
    {
        Biquad[channel].v1 = 0;
//        theFilters[channel].v2 = 0;
    }
}

void ACEqualizer::calculateLPFCoeffs(float fCutoffFreq, float fQ, float Gain,
                                     float &m_F_b1,
                                     float &m_F_b2,
                                     float &m_F_a0,
                                     float &m_F_a1,
                                     float &m_F_a2,
                                     float &m_F_c0,
                                     float &m_F_d0)
{
    
    const float fCutoffFreqMapped = jmap(fCutoffFreq, 0.0f, 1.0f, 20.0f, 20000.0f);
    const float fQMapped = jmap(fQ, 0.0f, 1.0f, 0.33f, 12.0f);
    const float GainMapped = jmap(Gain, 0.0f, 1.0f, -12.0f, 12.0f);
    
    m_fCutoffFreqMapped = fCutoffFreqMapped;
    m_fQMapped = fQMapped;
    m_GainMapped = GainMapped;

    float theta_c = 2.0*double_Pi*fCutoffFreqMapped/(float)mSampleRate;
    
    // Clamp to 0.95 pi/2 experiment)
    float tanArg = theta_c/(2.0/fQMapped);
    
    if (tanArg >= double_Pi/2.0)
    {
        tanArg = 0.95*double_Pi/2.0;
    }
    
    float fMu = pow(10.0, GainMapped/20.0f);
    float fDelta = 4.0/(1.0+fMu);

    float fBetaNumerator = 1.0 - fDelta*(tan(tanArg));
    float fBetaDenominator = 1.0 + fDelta*(tan(tanArg));

    float fBeta = 0.5*(fBetaNumerator/fBetaDenominator);

    float fGamma = (0.5*fBeta)*(cos(theta_c));

    float fAlpha = (0.5 - fBeta);
    
    m_F_a0 = fAlpha;
    m_F_a1 = 0.0;
    m_F_a2 = -fAlpha;
    m_F_b1 = -2.0*fGamma;
    m_F_b2 = 2.0*fBeta;
    
    m_F_c0 = fMu - 1.0;
    m_F_d0 = 1.0;
    
}

const float ACEqualizer::getMagnitudeForFrequency(double frequency,
                                                   double mSampleRate,
                              const float m_F_b1,
                              const float m_F_b2,
                              const float m_F_a0,
                              const float m_F_a1,
                              const float m_F_a2)
{

    constexpr std::complex<double> j (0,1);
    
//    jassert (frequency >= 0 && frequency <= mSampleRate * 0.5);
    
    std::complex<double> numerator = 0.0, denominator = 0.0,  factor = 1.0;
    std::complex<double> expjwT = std::exp(-(double_Pi*2.0) * frequency * j / mSampleRate);

    numerator += ((double)m_F_a0) * factor; factor *= expjwT;
    numerator += ((double)m_F_a1) * factor; factor *= expjwT;
    numerator += ((double)m_F_a2) * factor;

    denominator = 1.0;
    factor = expjwT;

    denominator += ((double)m_F_b1) * factor; factor *= expjwT;
    denominator += ((double)m_F_b2) * factor;
    
    return std::abs(numerator / denominator);

}

void ACEqualizer::process(float* inAudio,
                          int channelNumber,
                          float* outAudio,
                          int inNumSamplestoRender)
{
    for(int i = 0; i < inNumSamplestoRender; i++)
    {
        auto xn = inAudio[i];
        
        auto yn_2 = m_F_Yz_2;
        auto yn_1 = m_F_Yz_1;

        auto xn_2 = m_F_Xz_2;
        auto xn_1 = m_F_Xz_1;

        //auto yn = (m_F_a0*xn + m_F_a1*xn_1 + m_F_a2*xn_2 - m_F_b1*yn_1 - m_F_b2*yn_2);
        const float wet = m_F_c0 * (m_F_a0*xn + m_F_a1*xn_1 + m_F_a2*xn_2 - m_F_b1*yn_1 - m_F_b2*yn_2);
        const float dry = m_F_d0 * xn;
        auto yn = wet + dry;

        m_F_Xz_2 = m_F_Xz_1;
        m_F_Xz_1 = xn;

        m_F_Yz_2 = m_F_Yz_1;
        m_F_Yz_1 = yn;
        
        outAudio[i] = yn;
    }
    
        float v1 = Biquad[channelNumber].v1;
    Biquad[channelNumber].v1 = v1;
}
    


