#include "midi_settings.h"
#include "pad.h"
#include "hangdrum_helpers.h"

int note = 60;
int velocity = 127;

static const Fsr fsr1(FSR1_PIN, POWER_PIN);
static const Fsr fsr2(FSR2_PIN, POWER_PIN);
static const Pad pad1(fsr1);
static const Pad pad2(fsr2);

static constexpr uint8_t NUMBER_OF_PADS = 2;
static const Pad* pads[NUMBER_OF_PADS] = {
	&pad1,
	&pad2
};

void setup() 
{
	// start the debug port
	Serial.begin(115200);
}

void loop()
{
	//read all the pads
	read_pads();
	update_notes();

	// MIDI Controllers should discard incoming MIDI messages.
  	// http://forum.pjrc.com/threads/24179-Teensy-3-Ableton-Analog-CC-causes-midi-crash
  	while (usbMIDI.read())
  	{
    	// ignore incoming messages
  	}
}

void read_pads()
{
	for(uint8_t i = 0; i < NUMBER_OF_PADS; i++)
	{
		pads[i]->read();
	}
}

void update_notes()
{
	for(uint8_t i = 0; i < NUMBER_OF_PADS; i++)
	{
		if(pads[i]->get_previous_state() != pads[i]->get_current_state())
		{
			if(pads[i]->get_current_state())
			{
				turn_note_on(note, pads[i]->get_value(), channel);
				Serial.print("Pad ");
				Serial.print(i);
				Serial.print("| Note on | ");
				Serial.println(pads[i]->get_value());
				Serial.println("--------------------");
			}
			else		
			{
				turn_note_off(note, pads[i]->get_value(), channel);
				Serial.print("Pad ");
				Serial.print(i);
				Serial.println("| Note off | ");
				Serial.println("--------------------");
			}
		}
	}
}
