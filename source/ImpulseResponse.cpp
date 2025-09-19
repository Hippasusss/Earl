





#include "ImpulseResponse.h"
#include "juce_audio_formats/juce_audio_formats.h"

ImpulseResponse::ImpulseResponse() :
    IR(), IRblock(IR)
{
}

ImpulseResponse::~ImpulseResponse()
{
}

void ImpulseResponse::loadIR(juce::File file)
{
    juce::AudioFormatManager formatManager;
    auto formatReader = formatManager.createReaderFor(file);
    formatReader->read(&IR,0,formatReader->lengthInSamples,0,true,true);
}

void ImpulseResponse::pitchCurrentIR(float semitones)
{
}
