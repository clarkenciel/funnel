/*
  ==============================================================================

    OutgoingEditor.cpp
    Created: 14 Dec 2015 7:04:21pm
    Author:  danny

  ==============================================================================
*/

#include "OutgoingEditor.h"

OutgoingEditor::OutgoingEditor (Hub& hub, String name)
  : Component(name),
    mHub(hub)
{}

void
OutgoingEditor::buttonClicked (Button* button)
{}

void
OutgoingEditor::paint (Graphics& g)
{
  g.fillAll (Colours::white);
}
