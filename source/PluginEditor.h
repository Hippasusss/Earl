#pragma once

#include "PluginProcessor.h"
#include "LabeledSlider.h"
#include "TitleBar.h"
// #include "melatonin_inspector/melatonin_inspector.h"

//==============================================================================
class AudioPluginAudioProcessorEditor final : public juce::AudioProcessorEditor
{
public:
    explicit AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor&);
    ~AudioPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    AudioPluginAudioProcessor& processorRef;

    TitleBar titleBar;
    LabeledSlider mainSlider;
    CustomLookAndFeel lookAndFeel;

    std::array<Component*, 2> components 
       {
        &titleBar,
        &mainSlider, 
    };


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioPluginAudioProcessorEditor)
};
