/*
  ==============================================================================

    CoreVoice.cpp
    Created: 14 Dec 2015 11:13:59am
    Author:  danny

  ==============================================================================
*/

#include "math.h"
#include "../JuceLibraryCode/JuceHeader.h"
#include "CoreVoice.h"

// initialize as a sine wave
CoreVoice::CoreVoice ()
  : Voice ()
{
  for (int i = 0; i < mNumValues; i++)
    mValues[i] = sin((2 * double_Pi * i) / (double) mNumValues);
}
