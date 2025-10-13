





#pragma once

#include "PluginProcessor.h"
#include "LabeledSlider.h"
#include "WaveformDisplay.h"
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
    LabeledSlider dryWetSlider;
    LabeledSlider pitchSlider;
    LabeledSlider stretchSlider;
    LabeledSlider lengthSlider;
    LabeledSlider startFade;
    LabeledSlider endFade;
    LabeledSlider startTrim;
    LabeledSlider endTrim;
    WaveformDisplay waveForm;
    GroupComponent sliderGroup;

    CustomLookAndFeel lookAndFeel;

    std::array<LabeledSlider*, 8> sliders
    {
        &dryWetSlider, 
        &pitchSlider,
        &stretchSlider,
        &lengthSlider,
        &startFade,
        &endFade,
        &startTrim,
        &endTrim,
    };


    std::array<Component*, 11> components 
    {
        &titleBar,
        &dryWetSlider, 
        &pitchSlider,
        &stretchSlider,
        &lengthSlider,
        &startFade,
        &endFade,
        &startTrim,
        &endTrim,
        &sliderGroup,
        &waveForm
    };


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioPluginAudioProcessorEditor)
};
