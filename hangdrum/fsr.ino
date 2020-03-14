#include "fsr.h"

FSR::FSR(uint32_t input_pin, uint32_t power_pin) :
    input_pin_(input_pin),
    power_pin_(power_pin)
{
    pinMode(power_pin_, OUTPUT);
    digitalWrite(power_pin_, HIGH);
}

uint32_t FSR::readValue() const
{
    return analogRead(input_pin_);
}

uint32_t FSR::readFilteredValue() const
{
    uint32_t input_value_sum = 0;
    for(uint32_t i = 0; i < FILTER_SIZE; i++)
    {
        input_value_sum += readValue();
    }

    return (input_value_sum / FILTER_SIZE);
}

uint32_t FSR::scaleToMidi(uint32_t value) const
{
    // For the 10 bit ADC on the Teensy 4, value can never exceed ‭1023 (1024 - 1)‬
    // but to map it properly to MIDI velocity, we want to be able to 
    // hit the max velocity without breaking a finger. 
    // So scaling it to 90% allows us to hit the 127 mark 
    // AND still be able to play the next day!
    uint32_t note_value = (value * 127) / ((1023 * ADC_SCALE) / 100);
    
    if(note_value > 127)
        note_value = 127;

    return note_value;
}