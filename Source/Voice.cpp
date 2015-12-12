/*
  ==============================================================================

    Voice.cpp
    Created: 7 Dec 2015 1:37:52pm
    Author:  Danny Clarke

  ==============================================================================
*/

#include "Voice.h"
#include "math.h"

Voice::Voice ()
  : numValues(1024),
    writeIdx(0),
    phase(0.0),
    freq(220.0)
{
  phaseInc = numValues * freq / SAMPLERATE;
  values = new double[numValues];
}

Voice::~Voice ()
{
  delete[] values;
}

/*
 * Adds a new value, starting from index 0, to the table of values.
 * It does not append; it overrides existing values.
 */
void
Voice::addValue (double _v)
{
  values[writeIdx] = _v;
  writeIdx = (writeIdx + 1)% numValues;
}

/*
 * Returns the next value from the table, with wrap around.
 * Uses phase to do so
 */
double
Voice::getNextValue ()
{
  int readIdx = (int) floor(phase + 0.5);
  phase = fmod(phase + phaseInc, numValues);

  return values[readIdx] * amp;
}

void
Voice::setFreq (double _nf)
{
  freq = _nf;
  phaseInc = numValues * freq / SAMPLERATE;
}

void
Voice::setAmp (double _na)
{
  amp = _na;
}

