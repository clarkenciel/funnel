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
  updateTargets();
  bool togState;

  for (std::vector<std::unique_ptr<ToggleButton>>::iterator it = mTargets.begin();
       it != mTargets.end(); it++)
  {
    if (button == (*it).get())
    {
      togState = (*it)->getToggleState();
      (*it)->setToggleState(!togState, dontSendNotification);
      if (togState)
        mHub.addTarget((*it)->getName());
      else
        mHub.removeTarget((*it)->getName());
    }
  }
}

void
OutgoingEditor::paint (Graphics& g)
{
  g.fillAll (Colours::red);
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
  std::vector<String> potential = mHub.getPotentialTargets();
  int cnt = 0, w = getWidth(), h = getHeight();
  float num = (float) potential.size();

  for (std::vector<String>::iterator tgt = potential.begin();
       tgt != potential.end(); tgt++)
  {
    // set up a new button
    if (!hasButton(*tgt))
    {
      mTargets.push_back(
          std::unique_ptr<ToggleButton>(new ToggleButton(String(*tgt))));
      std::cout << "Target: " << *tgt << " Count: " << cnt << std::endl;
      ToggleButton& btn = **(mTargets.end() - 1);
      btn.setBounds(0, cnt * (h / num), w, cnt * (h / num) + (h / num));
      btn.addListener(this);
      addAndMakeVisible(btn);
      cnt++;
    }
  }
  std::cout << "Num Outgoing: " << mHub.getPotentialTargets().size() << std::endl;
}

bool
OutgoingEditor::hasButton(String name)
{
  std::vector<std::unique_ptr<ToggleButton>>::iterator btn;

  for (btn = mTargets.begin(); btn != mTargets.end(); btn++)
  {
    if ((*btn)->getButtonText() == name)
      return true;
  }
  return false;
}
