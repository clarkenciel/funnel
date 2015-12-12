/*
  ==============================================================================

    VoiceBank.cpp
    Created: 7 Dec 2015 1:38:01pm
    Author:  root

  ==============================================================================
*/

#include "VoiceBank.h"

VoiceBank::VoiceBank ()
{
}

VoiceBank::~VoiceBank ()
{
  // Since I'm using vectors and smart pointers, I shouldn't
  // need to worry about deallocating memory manually here
  
  //for (auto v = voices.begin(); v != voices.end(); v++)
  //  delete v;
  //delete voices;
}

/*
 * Add a voice to the tail of the voices vector and return its index
 */
int
VoiceBank::addVoice ()
{
  // with 0-index, the current size will be the index of the 
  // item push_back'd onto the vector
  int idx = voices.size(); 
  voices.push_back( std::unique_ptr<Voice>(new Voice()) );
  return idx;
}

/*
 * Remove a voice from the bank and return the new number of voices
 */
int
VoiceBank::removeVoice (int idx)
{
  if (idx < voices.size() && idx >= 0)
    voices.erase(voices.begin() + idx);
  return voices.size();
}

/*
 * Get the current number of voices
 */
int
VoiceBank::getNumVoices ()
{
  return voices.size();
}

/*
 * Add a value to a specific voice. 
 * Remember that adding to a voice is an overwriting-with-wraparound operation
 */
void
VoiceBank::addValueToVoice (int _vi, double _v)
{
  voices[_vi]->addValue(_v);
}

/*
 * Return a vector containing the current values for each of the voices
 */
std::vector<double>
VoiceBank::getValues ()
{
  std::vector<double> out(voices.size(), 0);
  for (auto v = voices.begin(); v != voices.end(); v++)
    out.push_back((*v)->getNextValue());
  return out;
}

