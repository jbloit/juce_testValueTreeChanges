#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{

    ValueTree slaveTree = ValueTree{"slave"};
    slaveTree.setProperty("id", 0, nullptr);
    slaveTree.setProperty("state", 1, nullptr);
    
    tree.appendChild(slaveTree, nullptr);
    
    tree.addListener(this);
    
    addAndMakeVisible(button);
    button.addListener(this);
    button.setButtonText("update value tree");
    
    setSize (600, 400);
    
    
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
}

void MainComponent::resized()
{
    button.setBounds(getLocalBounds().reduced(getHeight()/10));
}


void MainComponent::valueTreePropertyChanged (ValueTree& tree,
                               const Identifier& property)
{
    DBG("Property that changed " << property.toString() + " " + tree[property].toString());
    
}


void MainComponent::buttonClicked(Button * button)
{
    ValueTree slaveTree = tree.getChildWithName("slave");
    
    ValueTree newSlaveTree = ValueTree{"slave"};
    newSlaveTree.setProperty("id", 0, nullptr);
    newSlaveTree.setProperty("state", count++, nullptr);
        
    slaveTree.copyPropertiesAndChildrenFrom(newSlaveTree, nullptr);
    
    DBG("main tree " << tree.toXmlString());

}
