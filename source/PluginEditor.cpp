#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p), 
    titleBar(p.getName()),
    mainSlider("main")
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
    mainSlider.setBounds(bounds);
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
