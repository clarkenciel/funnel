/*
  ==============================================================================

    VoiceBank.h
    Created: 7 Dec 2015 1:38:01pm
    Author:  root

  ==============================================================================
*/

#ifndef VOICEBANK_H_INCLUDED
#define VOICEBANK_H_INCLUDED

#include <memory>
#include "Voice.h"
#include "../JuceLibraryCode/JuceHeader.h"

class VoiceBank
{
public:
  VoiceBank ();
  ~VoiceBank ();

  int addVoice (); // returns index of new voice
  int removeVoice (int idx); // returns new size of voices vector
  int getNumVoices (); // return size of voices vector

  void addValueToVoice (int voiceIdx, double value);
  std::vector<double> getValues ();


private:
  std::vector<std::unique_ptr<Voice>> voices;
};

#endif  // VOICEBANK_H_INCLUDED
