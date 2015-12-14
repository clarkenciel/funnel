/*
  ==============================================================================

    Mixer.cpp
    Created: 13 Dec 2015 8:49:38am
    Author:  Danny Clarke

  ==============================================================================
*/

#include <iostream>
#include <vector>
#include <map>
#include "Mixer.h"
#include "VoiceBank.h"
#include "Voice.h"

Mixer::Mixer (const VoiceBank& mods, Voice& co)
  : mModifiers(mods),
    mCore(co)
{}

Mixer::~Mixer ()
{}

/* Primary external interface */

/*
 * Return result of mutating single sample of core using modifiers.
 * Will also broadcast the sample to targets
 */
double
Mixer::mix ()
{}

bool
Mixer::setBoardVal (const char* key, double val)
{
  try
  {
    mBoard.at(key) = val;
    return true;
  }
  catch (const std::out_of_range& oor)
  {
    std::cerr << "Out of Range error @ Mixer::setBoardVal: ";
    std::cerr << '\t' << oor.what() << std::endl;
    std::cerr << '\t' << key << ": " << val << std::endl;
    return false;
  }
}

/*
 * Return the mixing board data
 */
std::map<const char*, double> 
Mixer::getBoardData () const
{ return mBoard; }


