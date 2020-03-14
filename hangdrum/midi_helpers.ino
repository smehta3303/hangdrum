#include "midi_settings.h"

void midi_sanity_check()
{
    usbMIDI.sendNoteOn(note, velocity, channel);
  	delay(1000);
  	usbMIDI.sendNoteOff(note, velocity, channel);
  	delay(1000);

  	// MIDI Controllers should discard incoming MIDI messages.
  	// http://forum.pjrc.com/threads/24179-Teensy-3-Ableton-Analog-CC-causes-midi-crash
  	while (usbMIDI.read())
  	{
    	// ignore incoming messages
  	}
}