





#include "Convolution.h"

void Convolution::prepare(const juce::dsp::ProcessSpec &)
{
}

void Convolution::process(const juce::dsp::ProcessContextReplacing<float> &context)
{
    auto inputBlock = context.getInputBlock();
}

void Convolution::reset()
{
}
