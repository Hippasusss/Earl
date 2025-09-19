





#pragma once
#include <vector> 
#include "juce_core/juce_core.h"

class FileBrowser
{
public:
    FileBrowser();
    FileBrowser(juce::File root);
    ~FileBrowser();

    std::vector<juce::File> getAvailableFilesInRoot();
    void setRoot(juce::File file) { root = file;};
private:
    juce::File root;
};
