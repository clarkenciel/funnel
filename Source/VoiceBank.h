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
#include "Voice.h"

class VoiceBank
{
public:
  VoiceBank ();
  ~VoiceBank ();

  int addVoice (const char* key); // returns index of new voice
  int removeVoice (const char* key); // returns new size of voices vector
  int getNumVoices () const; // return size of voices vector

  bool addValueToVoice (const char* key, double value);
  std::vector<double> getNextValues ();
  std::vector<double> getCurrentValues () const; // only reads so const
  std::vector<const char*> getStreamNames () const;


private:
  int mNumVoices;
  std::map<const char*, std::unique_ptr<Voice>> mVoices;
};

#endif  // VOICEBANK_H_INCLUDED
