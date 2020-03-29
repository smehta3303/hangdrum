#include "fsr.h"

Fsr::Fsr(uint32_t input_pin, uint32_t power_pin) :
    input_pin_(input_pin),
    power_pin_(power_pin)
{
    pinMode(power_pin_, OUTPUT);
    digitalWrite(power_pin_, HIGH);
}

uint32_t Fsr::read_value() const
{
    uint32_t value = 0;
    for(uint16_t i = 0; i < 512; i++)
    {
        uint32_t inst_val = analogRead(input_pin_);
        if(inst_val > value)
            value = inst_val;
    }

    return value;
}

uint32_t Fsr::read_filtered_value() const
{
    uint32_t input_value_sum = 0;
    for(uint32_t i = 0; i < FILTER_SIZE; i++)
    {
        input_value_sum += read_value();
    }

    return (input_value_sum / FILTER_SIZE);
}

uint32_t Fsr::scale_to_midi(uint32_t value) const
{
    // For the 10 bit ADC on the Teensy 4, value can never exceed ‭1023 (1024 - 1)‬
    // but to map it properly to MIDI velocity, we want to be able to 
    // hit the max velocity without breaking a finger. 
    // So scaling it to 90% allows us to hit the 127 mark 
    // AND still be able to play the next day!
    uint32_t note_value = (value * 127) / 900;
    
    if(note_value > 127)
        note_value = 127;

    return note_value;
}