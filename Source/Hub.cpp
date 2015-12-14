/*
  ==============================================================================

    Hub.cpp
    Created: 13 Dec 2015 8:49:31am
    Author:  danny

  ==============================================================================
*/

#include "Hub.h"

#define PORT 57001

Hub::Hub (const char* address, VoiceBank& is, const Voice& os)
  : mAddress(address),
    mIncoming(is),
    mOutgoing(os),
    mTargets(0),
    mPotentialTargets(0)
{
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
  for (std::vector<const char*>::iterator tgt = mTargets.begin();
       tgt != mTargets.end(); tgt++)
  {
    output.connect(*tgt, PORT);
    if (! output.send("/funnel/active", (float) mOutgoing.getCurrentValue()) )
      std::cerr << "Unable to send to: " << *tgt << std::endl;
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
  if (it != mTargets.end()) mTargets.erase(it);
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

/* Dispatchees for received messages */

void
Hub::oscMessageReceived (const OSCMessage& msg)
{
  String address = msg.getAddressPattern().toString();

  if (address == String("/funnel/hello"))
    greet(msg[0]); // msg[0] will be the ip in this case
  else if (address == String("/funnel/active"))
    std::cout << "implement active!" << std::endl;
  else if (address == String("/funnel/inactive"))
    std::cout << "implement active!" << std::endl;
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
  String ip = arg.getString();
  bool found = false;

  // see if we have the ip as a potential target already
  for (std::vector<const char*>::const_iterator it = mPotentialTargets.begin();
       it != mPotentialTargets.end(); it++)
  {
    if (ip.compare(*it))
    {
      found = true;
      break;
    }
  }

  // if we have not seen the address before,
  // take note and respond with our IP
  if (!found) 
  {
    addPotentialTarget(ip.toRawUTF8()); // toRawUTF8 returns const char*
    greeter.connect(ip, PORT);
    greeter.send("/funnel/hello", String(mAddress));
  }
}
