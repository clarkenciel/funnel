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
{
}

void
OutgoingEditor::buttonClicked (Button* button)
{
  for (std::vector<std::unique_ptr<ToggleButton>>::iterator it = mTargets.begin();
       it != mTargets.end(); it++)
  {
    if (button == (*it).get())
      (*it)->setToggleState(!(*it)->getToggleState(), dontSendNotification);
  }
}

void
OutgoingEditor::paint (Graphics& g)
{
  g.fillAll (Colours::white);
  updateTargets();
}

/*
 * Get all potential targets
 * If we do not have a button, create one
 * on the current targets list or not
 */
void
OutgoingEditor::updateTargets ()
{
  std::vector<const char*> potential = mHub.getPotentialTargets();
  for (std::vector<const char*>::iterator tgt = potential.begin();
       tgt != potential.end(); tgt++)
  {
    if (!hasButton(*tgt))
    {
      mTargets.push_back(
          std::unique_ptr<ToggleButton>(new ToggleButton(String(*tgt))));
      addAndMakeVisible(**(mTargets.end() - 1));
    }
  }
}

bool
OutgoingEditor::hasButton(const char* name)
{
  std::vector<std::unique_ptr<ToggleButton>>::iterator btn;

  for (btn = mTargets.begin(); btn != mTargets.end(); btn++)
  {
    if ((*btn)->getButtonText().compare(name))
      return true;
  }
  return false;
}
