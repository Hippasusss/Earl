





#pragma once

#include "juce_dsp/juce_dsp.h"

class Convolution : juce::dsp::ProcessorBase
{
public:
    Convolution();
    ~Convolution();

    void prepare(const juce::dsp::ProcessSpec &) override;
    void process(const juce::dsp::ProcessContextReplacing<float> &) override;
    void reset() override;

private:
    juce::dsp::FFT FFT;
};
