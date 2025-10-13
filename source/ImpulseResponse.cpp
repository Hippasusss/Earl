





#include "ImpulseResponse.h"

ImpulseResponse::ImpulseResponse() :
    IR(), IRblock(IR), formatManager()
{
    formatManager.registerBasicFormats();
}

ImpulseResponse::~ImpulseResponse()
{
}

void ImpulseResponse::loadIR(juce::File file)
{
    auto formatReader = std::unique_ptr<juce::AudioFormatReader>(formatManager.createReaderFor(file));
    IR.clear();
    IR.setSize(formatReader->numChannels, formatReader->lengthInSamples);
    formatReader->read(&IR,0,formatReader->lengthInSamples,0,true,true);
    sendChangeMessage();
}

void ImpulseResponse::pitchCurrentIR(float semitones)
{
}
