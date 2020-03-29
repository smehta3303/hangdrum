#include "midi_settings.h"
#include "hangdrum_helpers.h"

void midi_sanity_check()
{
    usbMIDI.sendNoteOn(note, velocity, channel);
  	delay(1000);
  	usbMIDI.sendNoteOff(note, velocity, channel);
  	delay(1000);
}

void turn_note_on(uint32_t note, uint32_t velocity, uint32_t channel)
{
	usbMIDI.sendNoteOn(note, velocity, channel);
}

void turn_note_off(uint32_t note, uint32_t velocity, uint32_t channel)
{
	usbMIDI.sendNoteOff(note, velocity, channel);
}