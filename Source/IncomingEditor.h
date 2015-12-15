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

class IncomingEditor : public Component,
                       public Button::Listener
{
  public:
    IncomingEditor (String name = "incomingEditor");
    ~IncomingEditor () {};

  private:

    void  buttonClicked (Button* button) override;

};

#endif  // INCOMINGEDITOR_H_INCLUDED
