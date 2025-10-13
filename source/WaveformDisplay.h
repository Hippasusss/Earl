






#pragma once

#include <juce_gui_extra/juce_gui_extra.h>
#include <juce_audio_utils/juce_audio_utils.h>

class WaveformDisplay  : public juce::Component, juce::ChangeListener
{
public:
    juce::AudioThumbnailCache cache;
    const size_t reductionFactor = 20;

    WaveformDisplay(juce::AudioFormatManager& manager);
    void paint(juce::Graphics &g) override;
    void changeListenerCallback (juce::ChangeBroadcaster* source) override
    {
        repaint();
    }

private:
    juce::AudioThumbnail thumbnail;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaveformDisplay);
};
