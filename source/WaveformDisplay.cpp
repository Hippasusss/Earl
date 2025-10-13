








#include "WaveformDisplay.h"

WaveformDisplay::WaveformDisplay(juce::AudioFormatManager& manager)
: cache(10), thumbnail(reductionFactor, manager, cache) 
{
}

void WaveformDisplay::paint(juce::Graphics &g) 
{
    g.fillAll(juce::Colours::white);

    if (thumbnail.getTotalLength() > 0.0) 
    {
        g.setColour(juce::Colours::aliceblue);
        thumbnail.drawChannels(g, getLocalBounds(), 0.0, thumbnail.getTotalLength(), 1.0f);
    } 
    else 
    {
        g.setColour(juce::Colours::red);
        g.drawText("No file loaded", getLocalBounds(), juce::Justification::centred);
    }
}

