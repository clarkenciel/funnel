/*
  ==============================================================================

    Voice.h
    Created: 7 Dec 2015 1:37:52pm
    Author:  root

  ==============================================================================
*/

#ifndef VOICE_H_INCLUDED
#define VOICE_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

#define SAMPLERATE 44100.0

class Voice
{
public:
  Voice ();
  ~Voice ();

  void addValue (double value); // does not append, overwrites with wraparound
  double getNextValue ();
  void setFreq (double nufreq);
  void setAmp (double nuAmp);

private:
  double* values;
  int numValues, writeIdx;
  
  double phase, freq, amp, phaseInc;

  int calcReadIdx ();
};


#endif  // VOICE_H_INCLUDED
