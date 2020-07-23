#pragma once

#include <JuceHeader.h>

using namespace juce;
class MainComponent  : public juce::Component, public ValueTree::Listener, public Button::Listener
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    //==============================================================================
    // Your private member variables go here...

    ValueTree tree{"main"};
    
    
     void valueTreePropertyChanged (ValueTree& tree,
                                    const Identifier& property) override;
    
    TextButton button;
    
    void buttonClicked(Button *) override;
    
    int count = 0;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
