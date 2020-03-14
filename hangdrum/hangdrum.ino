#include "midi_settings.h"
#include "fsr.h"

const FSR fsr1(A0, 12);

void setup() 
{
	Serial.begin(115200);
}

void loop()
{
	uint32_t val = fsr1.readFilteredValue();

	Serial.println(val);
	Serial.println(fsr1.scaleToMidi(val));
	Serial.println("------------");

	delay(20);
}
