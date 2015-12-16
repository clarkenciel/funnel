/*
  ==============================================================================

    Hub.cpp
    Created: 13 Dec 2015 8:49:31am
    Author:  danny

  ==============================================================================
*/

#include "Hub.h"

#define PORT 57001

Hub::Hub (String address, VoiceBank& is, const Voice& os)
  : mIncoming(is),
    mOutgoing(os),
    mAddress(address)
{
  std::cout << "Hub with IP: " << mAddress.toRawUTF8() << std::endl;
  // set up listening
  addListener(this, "/funnel/hello");    // detection
  addListener(this, "/funnel/active");   // sending values
  addListener(this, "/funnel/inactive"); // not sending values
  connect(PORT);
}

Hub::~Hub ()
{}

/* Primary exposed interface */

void
Hub::send ()
{
  for (std::vector<String>::const_iterator tgt = mTargets.begin();
       tgt != mTargets.end(); tgt++)
  {
    output.connect(*tgt, PORT);
    if (! output.send("/funnel/active",
                      mAddress,
                      (float) mOutgoing.getCurrentValue()) )
      std::cout << "Unable to send to: " << *tgt << std::endl;
  }
}

/*
 * Add a new target to the targets vector.
 */
void
Hub::addTarget (String ip)
{
  std::cout << "Adding Target: " << ip << std::endl;
  mTargets.push_back(ip);
}

/*
 * Remove a target from the targets vector
 */
void
Hub::removeTarget (String ip)
{
  std::vector<String>::iterator it = mTargets.begin();

  // iterate through, only stopping at match or end
  for (; it != mTargets.end() || *it != ip; it++)

  // only erase if iterator did not hit the end of the vector
  if (it != mTargets.end())
  {
    mTargets.erase(it);
    greeter.connect(*it, PORT);
    greeter.send("/funnel/inactive",mAddress);
  }
}

std::vector<String>
Hub::getCurrentIncoming () const
{
  return mIncoming.getStreamNames();
}

std::vector<String>
Hub::getCurrentTargets () const
{
  return mTargets;
}

std::vector<String>
Hub::getPotentialTargets () const
{
  return mPotentialTargets;
}

/*
 * Ping network for peers
 */
void
Hub::seekPeers ()
{
  std::cout << "broadcasting: " << mAddress << std::endl;
  greeter.connect("255.255.255.255", PORT);
  greeter.send("/funnel/hello", mAddress);
}

/* Dispatchees for received messages */

void
Hub::oscMessageReceived (const OSCMessage& msg)
{
  String address = msg.getAddressPattern().toString();

  // msg[0] will always be IP
  if (address == "/funnel/hello")
    greet(msg[0]);
  else if (address == "/funnel/active")
    capture(msg[0], msg[1]);  // msg[1] will be a new value
  else if (address == "/funnel/inactive")
    detach(msg[0]);
  else
    std::cerr << "OSC Adress \"" << mAddress << "\" not handled." << std::endl;
}

void
Hub::removeIncoming (String ip)
{
  mIncoming.removeVoice(ip);
}

void
Hub::addIncoming (String ip)
{
  mIncoming.addVoice(ip);
}

void
Hub::addPotentialTarget (String ip)
{
  if (ip != "" || ip != "funnel" || ip != "hello" 
      || ip != "/funnel/hello" || !hasPotentialTarget(ip))
  {
    //std::cout << mAddress << " adding: " << ip << std::endl;
    mPotentialTargets.push_back(ip);
  }
}

void
Hub::greet (OSCArgument& arg)
{
  String ip = arg.getString();

  // seems strane that this isn't !mAddress.compare ...
  if (!(mAddress == ip))
  {
    // if we have not seen the address before,
    // take note 
    if (!hasPotentialTarget(ip)) 
    {
      addPotentialTarget(ip); // toRawUTF8 returns String

      // and respond with our IP
      std::cout << "Greeting: " << ip << std::endl;
      greeter.connect("255.255.255.255", PORT);
      greeter.send("/funnel/hello", mAddress);
    }
  }
}

/*
 * Capture an incoming connection as a stream
 */
void
Hub::capture (OSCArgument& name, OSCArgument& val)
{
  String ip = name.getString();

  // if we have not seen the address before,
  // create a new voice
  std::cout << "Capturing/updating: " << ip << std::endl;
  if (!mIncoming.hasVoice(ip)) 
  {
    mIncoming.addVoice(ip);
    mIncoming.addValueToVoice(ip, val.getFloat32());
  }
  else
    mIncoming.addValueToVoice(ip, val.getFloat32());
}

void
Hub::detach (OSCArgument& name)
{
  String ip = name.getString();

  // if we are currently working with the voice, remove it
  std::cout << "Detaching: " << ip << std::endl;
  if (!mIncoming.hasVoice(ip))
    mIncoming.removeVoice(ip);
}

bool
Hub::hasPotentialTarget (String name) const
{
  // see if we have the ip as a potential target already
  for (std::vector<String>::const_iterator it = mPotentialTargets.begin();
       it != mPotentialTargets.end(); it++)
  {
    if (name == *it)
      return true;
  }

  return false;
}

bool
Hub::hasCurrentTarget (String name) const
{
  // see if we have the ip as a potential target already
  for (std::vector<String>::const_iterator it = mTargets.begin();
       it != mTargets.end(); it++)
  {
    if (name == *it)
      return true;
  }

  return false;
}
