/*
   ==============================================================================

   Voice.h
Created: 7 Dec 2015 1:37:52pm
Author:  root

==============================================================================
*/

#ifndef VOICE_H_INCLUDED
#define VOICE_H_INCLUDED


#define SAMPLERATE 44100.0

class Voice
{
  public:
    Voice ();
    Voice (double amp);
    ~Voice ();

    void addValue (double value); // does not append, overwrites with wraparound
    double getNextValue ();
    double getCurrentValue () const; // this doesn't mutate
    void setFreq (double nufreq);
    void setAmp (double nuAmp);

  protected: // want these accessible to children
    double* mValues;
    int mNumValues, mWriteIdx, mReadIdx;
    double mPhase, mFreq, mAmp, mPhaseInc;

    int calcReadIdx ();

};


#endif  // VOICE_H_INCLUDED
