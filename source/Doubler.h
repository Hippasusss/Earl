#pragma once
#include "juce_dsp/juce_dsp.h"

using namespace juce;

class Doubler : dsp::ProcessorBase
{
    public:
        Doubler() = default;
        ~Doubler() = default;

        void prepare(const dsp::ProcessSpec&) override;
        void process(const dsp::ProcessContextReplacing<float>&) override;
        void reset() override;
    private:

};

