/*
  ==============================================================================

    Hub.h
    Created: 13 Dec 2015 8:49:31am
    Author:  Danny Clarke

  ==============================================================================
*/

// TODO: Potential target stuff should be broken out

#ifndef HUB_H_INCLUDED
#define HUB_H_INCLUDED

#include <memory>
#include <map>
#include <vector>
#include "../JuceLibraryCode/JuceHeader.h"
#include "VoiceBank.h"
#include "Voice.h"

// To use the OSCReceiver, you subclass it.
// ListenerWithOSCAddress provides extra functionality around routing messages
// and RealtimeCallback allows for faster callback execution.
class Hub : public OSCReceiver,
            public OSCReceiver::ListenerWithOSCAddress<OSCReceiver::RealtimeCallback>
{
  public:
    Hub (const char* address, VoiceBank& inStreams, const Voice& outStream);
    ~Hub ();

    void oscMessageReceived (const OSCMessage& message) override;
    void send (); // only reads
    void addTarget (const char* ip);
    void removeTarget (const char* ip);
    void seekPeers ();
    bool hasPotentialTarget (const char* ip) const;

    std::vector<const char*> getCurrentIncoming () const;
    std::vector<const char*> getCurrentTargets () const;
    std::vector<const char*> getPotentialTargets () const;

  private:
    const char* mAddress;

    // avoid greet messages locking the output
    OSCSender output, greeter;

    // store IPs
    std::vector<const char*> mTargets; 
    std::vector<const char*> mPotentialTargets; 

    VoiceBank& mIncoming; // we mutate these
    const Voice& mOutgoing; // we only read these

    void addIncoming (const char* ip);
    void removeIncoming (const char* ip);
    void greet (OSCArgument& name); // add new potential target and respond
    void capture (OSCArgument& name, OSCArgument& val);
    void detach (OSCArgument& name);
    void addPotentialTarget (const char* ip);
};


#endif  // HUB_H_INCLUDED
