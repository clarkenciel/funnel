/*
  ==============================================================================

    IncomingEditor.h
    Created: 14 Dec 2015 7:04:13pm
    Author:  danny

  ==============================================================================
*/

#ifndef INCOMINGEDITOR_H_INCLUDED
#define INCOMINGEDITOR_H_INCLUDED

#include <memory>
#include <map>
#include "../JuceLibraryCode/JuceHeader.h"
#include "Hub.h"

class IncomingEditor : public Component,
                       public Slider::Listener
{
  public:
    IncomingEditor (Hub& hub, String name = "incomingEditor");
    ~IncomingEditor () {};
    

    void paint (Graphics& g);
    void updateIncoming ();

  private:
    Hub& mHub;

    std::map<String, std::unique_ptr<Slider>> mConnections;

    void sliderValueChanged (Slider* sliderThatHasChanged) override;
    bool hasSlider(String name);
    bool hasSlider(Slider* slider);
};

#endif  // INCOMINGEDITOR_H_INCLUDED
