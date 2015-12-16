/*
   ==============================================================================

   VoiceBank.h
Created: 7 Dec 2015 1:38:01pm
Author:  Danny Clarke

==============================================================================
*/

#ifndef VOICEBANK_H_INCLUDED
#define VOICEBANK_H_INCLUDED

#include <map>
#include <memory>
#include <vector>
#include <utility>
#include "../JuceLibraryCode/JuceHeader.h"
#include "Voice.h"

class VoiceBank
{
  public:
    VoiceBank ();
    ~VoiceBank ();

    int addVoice (String key); // returns index of new voice
    int removeVoice (String key); // returns new size of voices vector
    int getNumVoices () const; // return size of voices vector

    bool addValueToVoice (String key, double value);
    bool setVoiceAmp (String key, double value);
    bool hasVoice (String key) const;

    std::vector<double> getNextValues ();
    std::vector<double> getCurrentValues () const; // only reads so const
    std::vector<String> getStreamNames () const;
    std::map<String, double> getAmplitudes () const;

  private:
    int mNumVoices;
    std::map<String, std::unique_ptr<Voice>> mVoices;

};

#endif  // VOICEBANK_H_INCLUDED
