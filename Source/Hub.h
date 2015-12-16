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
    Hub (String address, VoiceBank& inStreams, const Voice& outStream);
    ~Hub ();

    void oscMessageReceived (const OSCMessage& message) override;
    void send (); // only reads
    void addTarget (String ip);
    void removeTarget (String ip);
    void seekPeers ();
    bool hasPotentialTarget (String ip) const;
    bool hasCurrentTarget (String ip) const;

    std::vector<String> getCurrentIncoming () const;
    std::vector<String> getCurrentTargets () const;
    std::vector<String> getPotentialTargets () const;

    // SO BAD!!!!
    VoiceBank& mIncoming; // we mutate these
    const Voice& mOutgoing; // we only read these

  private:
    String mAddress;

    // avoid greet messages locking the output
    OSCSender output, greeter;

    // store IPs
    std::vector<String> mTargets; 
    std::vector<String> mPotentialTargets; 


    void addIncoming (String ip);
    void removeIncoming (String ip);
    void greet (OSCArgument& name); // add new potential target and respond
    void capture (OSCArgument& name, OSCArgument& val);
    void detach (OSCArgument& name);
    void addPotentialTarget (String ip);

};

#endif  // HUB_H_INCLUDED
