






#pragma once

#include <juce_gui_extra/juce_gui_extra.h>
#include <juce_audio_utils/juce_audio_utils.h>

class WaveformDisplay  : public juce::Component
{
public:
    const size_t reductionFactor = 20;

    WaveformDisplay();
    void paint(juce::Graphics &g) override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaveformDisplay);
};
