






#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p), 
    titleBar(p.getName()),
    dryWetSlider("main"),
    pitchSlider("pitch"),
    stretchSlider("stretch"),
    lengthSlider("length"),
    startFade("startFade"),
    endFade("endFade"),
    startTrim("startTrim"),
    endTrim("endTrim"),
    sliderGroup("sliderGroup")
{
    for (auto& component : components) 
    {
        component->setLookAndFeel(&lookAndFeel);
        addAndMakeVisible(component);
    }
    setSize (400, 300);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
{
    for (auto& component : components) 
    {
        component->setLookAndFeel(nullptr);
    }
}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void AudioPluginAudioProcessorEditor::resized()
{
    auto bounds = getLocalBounds();
    titleBar.setBounds(bounds.removeFromTop(100));
    dryWetSlider.setBounds(bounds);
}
