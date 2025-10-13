






#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "Helpers.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p), 
    titleBar(p.getName()),
    dryWetSlider("dry/wet"),
    pitchSlider("pitch"),
    stretchSlider("stretch"),
    lengthSlider("length"),
    startFade("fade in"),
    endFade("fade out"),
    startTrim("start trim"),
    endTrim("end trim"),
    waveForm(p.getIR()),
    sliderGroup("sliderGroup")
{
    for (auto& component : components) 
    {
        component->setLookAndFeel(&lookAndFeel);
        addAndMakeVisible(component);
    }

    for (auto& slider : sliders)
    {
        Label& valueLabel = slider->getSliderValueLabel();
        valueLabel.setColour(Label::ColourIds::backgroundColourId, colour_constants::transparent);
        valueLabel.setColour(Label::ColourIds::textColourId, colour_constants::main);

        Label& nameLabel = slider->getSliderNameLabel();
        nameLabel.setColour(Label::ColourIds::backgroundColourId, colour_constants::main);
        nameLabel.setColour(Label::ColourIds::textColourId, colour_constants::backGround);
    }
    setSize (1000, 500);
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
    g.fillAll (Colours::white);
}

void AudioPluginAudioProcessorEditor::resized()
{
    auto bounds = getLocalBounds();
    titleBar.setBounds(bounds.removeFromTop(50));
    auto waveformBounds = bounds.removeFromTop(350);
    waveForm.setBounds(waveformBounds);
    sliderGroup.setBounds(bounds);
    LayoutHelpers::distributeHorizontally(sliders, bounds, 10);
}
