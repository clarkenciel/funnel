/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Voice.h"
#include "CoreVoice.h"
#include "VoiceBank.h"
#include "Hub.h"
#include "Mixer.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent   : public AudioAppComponent
{
  public:
    //==============================================================================
    MainContentComponent()
    {
      setSize (800, 600);

      // specify the number of input and output channels that we want to open
      setAudioChannels (2, 2);

      // Fetch our current public IP
      Array<IPAddress>* ips;
      ips = new Array<IPAddress>();
      IPAddress::findAllAddresses(*ips);

      if (ips->size() > 1)
        IP = ips->getReference(1).toString().toRawUTF8();
      else if (ips->size() == 1)
        IP = ips->getReference(0).toString().toRawUTF8();
      else
        IP = "127.0.0.1";

      std::cout << IP << std::endl;
      
    }

    ~MainContentComponent()
    {
      shutdownAudio();
    }

    //=======================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override
    {
      // This function will be called when the audio device is started, or when
      // its settings (i.e. sample rate, block size, etc) are changed.

      // You can use this function to initialise any resources you might need,
      // but be careful - it will be called on the audio thread, not the GUI thread.

      // For more details, see the help for AudioProcessor::prepareToPlay()
      
      // do final bits of set up
      mCore = new CoreVoice();
      mModifiers = new VoiceBank();
      mHub = new Hub(IP, *mModifiers, *mCore);
      mMixer = new Mixer(*mModifiers, *mCore);

    }

    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override
    {
      bufferToFill.clearActiveBufferRegion(); // clear buffer of noise
      AudioSampleBuffer& buffer         = *bufferToFill.buffer;
      int start                         = bufferToFill.startSample;
      int numSamples                    = bufferToFill.numSamples;
      for (int chan = 0; chan < buffer.getNumChannels(); ++chan)
      {
        float* const channelData = buffer.getWritePointer(chan, start);

        for (int i = 0; i < numSamples; ++i)
        {
          channelData[i] = (float) mMixer->mix();
        }
      }
    }

    void releaseResources() override
    {
      // This will be called when the audio device stops, or when it is being
      // restarted due to a setting change.

      // For more details, see the help for AudioProcessor::releaseResources()
    }

    //=======================================================================
    void paint (Graphics& g) override
    {
      // (Our component is opaque, so we must completely fill the background with a solid colour)
      g.fillAll (Colours::black);


      // You can add your drawing code here!

    }

    void resized() override
    {
      // This is called when the MainContentComponent is resized.
      // If you add any child components, this is where you should
      // update their positions.
    }


  private:
    //==============================================================================

    // Your private member variables go here...
    const char* IP;
    CoreVoice* mCore;
    VoiceBank* mModifiers;
    Hub* mHub;
    Mixer* mMixer;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent()     { return new MainContentComponent(); }


#endif  // MAINCOMPONENT_H_INCLUDED
