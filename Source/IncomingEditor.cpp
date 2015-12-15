/*
  ==============================================================================

    IncomingEditor.cpp
    Created: 14 Dec 2015 7:04:13pm
    Author:  Danny Clarke

  ==============================================================================
*/

#include "IncomingEditor.h"

IncomingEditor::IncomingEditor (Hub& hub, String name)
  : Component(name),
    mHub(hub)
{}

void
IncomingEditor::sliderValueChanged (Slider* slider)
{}

void
IncomingEditor::paint (Graphics& g)
{
  g.fillAll (Colours::white);
}
