/*
  ==============================================================================

    Voice.cpp
    Created: 7 Dec 2015 1:37:52pm
    Author:  Danny Clarke

  ==============================================================================
*/

#include <iostream>
#include "math.h"
#include "Voice.h"

Voice::Voice ()
  : mNumValues(1024),
    mWriteIdx(0),
    mPhase(0.0),
    mAmp(0.5),
    mFreq(220.0)
{
  mPhaseInc = (mNumValues * mFreq) / SAMPLERATE;
  mValues = new double[mNumValues];
  for (int i = 0; i < mNumValues; i++)
    mValues[i] = 0;
}

Voice::Voice (double a)
  : Voice ()
{
  mAmp = a;
}

Voice::~Voice ()
{
  delete[] mValues;
}

/*
 * Adds a new value, starting from index 0, to the table of values.
 * It does not append; it overrides existing values.
 */
void
Voice::addValue (double val)
{
  mValues[mWriteIdx] += val;
  mWriteIdx = (mWriteIdx + 1)% mNumValues;
}

/*
 * Returns the next value from the table, with wrap around.
 * Uses phase to do so
 */
double
Voice::getNextValue ()
{
  mPhase = fmod(mPhase + mPhaseInc, mNumValues);
  mReadIdx = (int) floor(mPhase);

  return mValues[mReadIdx] * mAmp;
}

/*
 * Returns the current value from the table.
 */
double
Voice::getCurrentValue () const
{
  return mValues[mReadIdx] * mAmp;
}


void
Voice::setFreq (double freq)
{
  mFreq = freq;
  mPhaseInc = (mNumValues * mFreq) / SAMPLERATE;
}

void
Voice::setAmp (double amp)
{
  mAmp = amp;
}

