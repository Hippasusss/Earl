






#pragma once

#include "juce_dsp/juce_dsp.h"

class ImpulseResponse
{
public:
    ImpulseResponse();
    ~ImpulseResponse();
    void loadIR(juce::File file);
    void pitchCurrentIR(float semitones);
    juce::dsp::AudioBlock<float> getIRAudioBlock() {return IRblock;};
private:
    juce::AudioBuffer<float> IR;
    juce::dsp::AudioBlock<float> IRblock;
};
