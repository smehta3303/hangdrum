#ifndef INLUCDE_MIDI_SETTINGS_H_
#define INLUCDE_MIDI_SETTINGS_H_
#include <MIDI.h>

// the MIDI channel number to send messages
const int channel = 1;

// remember when a note-on message has been sent
int note = 60;
int velocity = 127;

void midi_sanity_check();

#endif