/*
  ==============================================================================

    VoiceBank.cpp
    Created: 7 Dec 2015 1:38:01pm
    Author:  root

  ==============================================================================
*/

#include <utility>
#include <map>
#include <memory>
#include <vector>
#include <iostream>
#include "VoiceBank.h"

VoiceBank::VoiceBank ()
{}

/* Since I'm using maps and smart pointers, I shouldn't
 * need to worry about deallocating memory manually here
 */
VoiceBank::~VoiceBank ()
{}

/*
 * Add a blank voice to the voice map
 */
int
VoiceBank::addVoice (const char* key)
{
  mVoices.emplace(key, std::unique_ptr<Voice>(new Voice()));
  mNumVoices = mVoices.size();
  return mNumVoices;
}

/*
 * Remove a voice from the bank and return the new number of voices
 */
int
VoiceBank::removeVoice (const char* key)
{
  mVoices.erase(key);
  mNumVoices = mVoices.size();
  return mNumVoices;
}

/*
 * Get the current number of voices
 */
int
VoiceBank::getNumVoices () const
{
  return mNumVoices;
}

/*
 * Add a value to a specific voice. Return true on success, false on failure
 * Remember that adding to a voice is an overwriting-with-wraparound operation
 */
bool
VoiceBank::addValueToVoice (const char* key, double value)
{
  try 
  {
    mVoices.at(key)->addValue(value);
    return true;
  }
  catch (const std::out_of_range& oor)
  {
    std::cerr << "Out of Range error @ VoiceBank::addValueToVoice: ";
    std::cerr << '\t' << oor.what() << std::endl;
    std::cerr << '\t' << key << ": " << value << std::endl;
    return false;
  }
}

bool
VoiceBank::setVoiceAmp (const char* key, double value)
{
  try 
  {
    mVoices.at(key)->setAmp(value);
    return true;
  }
  catch (const std::out_of_range& oor)
  {
    std::cerr << "Out of Range error @ VoiceBank::setVoiceAmp: ";
    std::cerr << '\t' << oor.what() << std::endl;
    std::cerr << '\t' << key << ": " << value << std::endl;
    return false;
  }

}

bool
VoiceBank::hasVoice (const char* key) const
{
  if (mVoices.find(key) != mVoices.end())
    return true;
  else
    return false;
}

/*
 * Return a vector containing the current values for each of the voices
 */
std::vector<double>
VoiceBank::getNextValues ()
{
  std::vector<double> out(mVoices.size(), 0);

  for (std::map<const char*, std::unique_ptr<Voice>>::iterator v = mVoices.begin(); 
       v != mVoices.end(); v++)
    out.push_back(v->second->getNextValue());

  return out;
}

/*
 * Return a vector containing the current values for each of the voices
 */
std::vector<double>
VoiceBank::getCurrentValues () const
{
  std::vector<double> out(mVoices.size(), 0);

  for (std::map<const char*, std::unique_ptr<Voice>>::const_iterator v = mVoices.begin(); 
       v != mVoices.end(); v++)
    out.push_back(v->second->getCurrentValue());

  return out;
}

/*
 * Return a vector of the names of the streams (ips here).
 */
std::vector<const char*>
VoiceBank::getStreamNames () const
{
  std::vector<const char*> out;

  for(std::map<const char*,std::unique_ptr<Voice>>::const_iterator it = mVoices.begin();
      it != mVoices.end(); it++)
    out.push_back(it->first);
  
  return out;
}
