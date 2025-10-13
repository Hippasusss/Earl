






#pragma once

#include "juce_audio_formats/juce_audio_formats.h"
#include "juce_dsp/juce_dsp.h"
#include "juce_events/juce_events.h"

class ImpulseResponse : juce::ChangeBroadcaster
{
public:
    ImpulseResponse();
    ~ImpulseResponse();
    void loadIR(juce::File file);
    void pitchCurrentIR(float semitones);

    juce::AudioFormatManager& getAudioFormatManager() {return formatManager;};
    juce::dsp::AudioBlock<float> getIRAudioBlock() {return IRblock;};
private:
    juce::AudioBuffer<float> IR;
    juce::dsp::AudioBlock<float> IRblock;
    juce::AudioFormatManager formatManager;
};
