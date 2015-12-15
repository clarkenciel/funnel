/*
  ==============================================================================

    IncomingEditor.h
    Created: 14 Dec 2015 7:04:13pm
    Author:  danny

  ==============================================================================
*/

#ifndef INCOMINGEDITOR_H_INCLUDED
#define INCOMINGEDITOR_H_INCLUDED

#include <vector>
#include "../JuceLibraryCode/JuceHeader.h"
#include "Hub.h"

class IncomingEditor : public Component,
                       public Slider::Listener
{
  public:
    IncomingEditor (Hub& hub, String name = "incomingEditor");
    ~IncomingEditor () {};
    

    void paint (Graphics& g);

  private:
    Hub& mHub;

    std::vector<Slider> mConnections;

    void sliderValueChanged (Slider* sliderThatHasChanged) override;

};

#endif  // INCOMINGEDITOR_H_INCLUDED
