/*
  ==============================================================================

    Mixer.h
    Created: 13 Dec 2015 8:49:38am
    Author:  Danny Clarke

  ==============================================================================
*/

#ifndef MIXER_H_INCLUDED
#define MIXER_H_INCLUDED

#include <map>
#include "../JuceLibraryCode/JuceHeader.h"
#include "Voice.h"
#include "VoiceBank.h"
#include "Hub.h"

class Mixer
{
  public:
    Mixer (Hub& sender, const VoiceBank& modifiers, Voice& core);
    ~Mixer ();

    double mix();

    bool setBoardVal (String key, double val);
    std::map<String,double> getBoardData () const; // does not modify board

  private:
    std::map<String, double> mBoard;

    const VoiceBank& mModifiers; // read only
    Voice& mCore; // will be modified when mixing happens
    Hub& mSender; // only used for its send function
};

#endif  // MIXER_H_INCLUDED
