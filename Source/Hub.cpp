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
  : mAddress(address),
    mIncoming(is),
    mOutgoing(os),
    mTargets(0),
    mPotentialTargets(0)
{
  std::cout << "Hub with IP: " << mAddress.toRawUTF8() << std::endl;
  // set up listening
  addListener(this, "/funnel/hello");    // detection
  addListener(this, "/funnel/active");   // sending values
  addListener(this, "/funnel/inactive"); // not sending values
}

Hub::~Hub ()
{}

/* Primary exposed interface */

void
Hub::send ()
{
  for (std::vector<const char*>::const_iterator tgt = mTargets.begin();
       tgt != mTargets.end(); tgt++)
  {
    output.connect(*tgt, PORT);
    std::cout << "sending to: " << *tgt << std::endl;
    if (! output.send("/funnel/active",
                      mAddress,
                      (float) mOutgoing.getCurrentValue()) )
      std::cout << "Unable to send to: " << *tgt << std::endl;
  }
}


/*
 * Add a new target to the targets map.
 *
 * Keys are IPs, targets are OSCSenders
 */
void
Hub::addTarget (const char* ip)
{
  mTargets.push_back(ip);
}

void
Hub::removeTarget (const char* ip)
{
  std::vector<const char*>::iterator it = mTargets.begin();

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

std::vector<const char*>
Hub::getCurrentIncoming () const
{
  return mIncoming.getStreamNames();
}

std::vector<const char*>
Hub::getCurrentTargets () const
{
  return mTargets;
}

std::vector<const char*>
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
  greeter.send("/funnel/hello", String(mAddress));
}

/* Dispatchees for received messages */

void
Hub::oscMessageReceived (const OSCMessage& msg)
{
  String address = msg.getAddressPattern().toString();

  // msg[0] will always be IP
  if (address == String("/funnel/hello"))
    greet(msg[0]);
  else if (address == String("/funnel/active"))
    capture(msg[0], msg[1]);  // msg[1] will be a new value
  else if (address == String("/funnel/inactive"))
    detach(msg[0]);
  else
    std::cerr << "OSC Adress \"" << mAddress << "\" not handled." << std::endl;
}

void
Hub::removeIncoming (const char* ip)
{
  mIncoming.removeVoice(ip);
}

void
Hub::addIncoming (const char* ip)
{
  mIncoming.addVoice(ip);
}

void
Hub::addPotentialTarget (const char* ip)
{
  mPotentialTargets.push_back(ip);
}

void
Hub::greet (OSCArgument& arg)
{
  const char* ip = arg.getString().toRawUTF8();
  bool found = hasPotentialTarget(ip);

  // if we have not seen the address before,
  // take note and respond with our IP
  if (!found) 
  {
    addPotentialTarget(ip); // toRawUTF8 returns const char*
    greeter.connect("255.255.255.255", PORT);
    greeter.send("/funnel/hello", String(mAddress));
  }
}

/*
 * Capture an incoming connection as a stream
 */
void
Hub::capture (OSCArgument& name, OSCArgument& val)
{
  const char* ip = name.getString().toRawUTF8();
  bool found = mIncoming.hasVoice(ip);

  // if we have not seen the address before,
  // create a new voice
  if (!found) 
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
  const char* ip = name.getString().toRawUTF8();
  bool found = mIncoming.hasVoice(ip);

  // if we are currently working with the voice, remove it
  if (found) 
    mIncoming.removeVoice(ip);
}

bool
Hub::hasPotentialTarget (const char* name) const
{
  bool found = false;

  // see if we have the ip as a potential target already
  for (std::vector<const char*>::const_iterator it = mPotentialTargets.begin();
       it != mPotentialTargets.end(); it++)
  {
    if (name == *it)
    {
      found = true;
      break;
    }
  }

  return found;
}
