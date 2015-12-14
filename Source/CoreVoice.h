/*
  ==============================================================================

    CoreVoice.h
    Created: 14 Dec 2015 11:13:59am
    Author:  danny

  ==============================================================================
*/

#ifndef COREVOICE_H_INCLUDED
#define COREVOICE_H_INCLUDED

#include "Voice.h"

/*
 * Initializes with a sine wave, rather than 0s
 */
class CoreVoice : public Voice
{
  public:
    CoreVoice ();
};




#endif  // COREVOICE_H_INCLUDED
