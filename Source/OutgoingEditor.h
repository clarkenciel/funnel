/*
  ==============================================================================

    OutgoingEditor.h
    Created: 14 Dec 2015 7:04:21pm
    Author:  danny

  ==============================================================================
*/

#ifndef OUTGOINGEDITOR_H_INCLUDED
#define OUTGOINGEDITOR_H_INCLUDED

#include <vector>
#include <memory>
#include "../JuceLibraryCode/JuceHeader.h"
#include "Hub.h"

class OutgoingEditor : public Component,
                       public Button::Listener
{
  public:
    OutgoingEditor (Hub& hub, String name = "OutgoingEditor");
    ~OutgoingEditor () {};

    void paint (Graphics& g);
    void updateTargets();
    void buttonClicked (Button* button) override;

  private:
    Hub& mHub;

    std::vector<std::unique_ptr<ToggleButton>> mTargets;

    bool hasButton (String name);
};

#endif  // OUTGOINGEDITOR_H_INCLUDED
