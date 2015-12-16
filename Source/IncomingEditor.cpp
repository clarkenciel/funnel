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
{
  // SO BAD!!!!
  if (hasSlider(slider))
    mHub.mIncoming.setVoiceAmp(slider->getName(), slider->getValue());
}

void
IncomingEditor::paint (Graphics& g)
{
  g.fillAll (Colours::white);
  updateIncoming();
}

/*
 * Get all potential targets
 * If we do not have a button, create one
 * on the current targets list or not
 */
void
IncomingEditor::updateIncoming ()
{
  std::vector<String> incoming = mHub.getCurrentIncoming();
  for (std::vector<String>::iterator tgt = incoming.begin();
       tgt != incoming.end(); tgt++)
  {
    if (!hasSlider(*tgt))
    {
      mConnections.emplace(*tgt,
          std::unique_ptr<Slider>(new Slider(*tgt)));
      (*mConnections.end()->second).setSliderStyle(Slider::LinearHorizontal);
      (*mConnections.end()->second).setRange(0.0,1.0,0.01);
      addAndMakeVisible(mConnections.at(*tgt).get());
    }
  }
  std::cout << "Num Incoming: " << mConnections.size() << std::endl;
}

bool
IncomingEditor::hasSlider(String name)
{
  std::map<String, std::unique_ptr<Slider>>::iterator sld;
  for (sld = mConnections.begin(); sld != mConnections.end(); sld++)
  {
    if (sld->first == name)
      return true;
  }
  return false;
}

bool
IncomingEditor::hasSlider(Slider* slider)
{
  std::map<String, std::unique_ptr<Slider>>::iterator sld;
  for (sld = mConnections.begin(); sld != mConnections.end(); sld++)
  {
    if (sld->second.get() == slider)
      return true;
  }
  return false;
}
