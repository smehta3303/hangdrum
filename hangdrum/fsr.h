/*
 * Creates an FSR object for handling FSR sensors.
 * Includes functionality for mapping FSR input to 
 * MIDI note velocities.
 * 
 * Has a simple averaging filter for filtered output.
 */

#ifndef INCLUDE_FSR_H_
#define INCLUDE_FSR_H_

class FSR
{
public:
    FSR(uint32_t input_pin, uint32_t power_pin);

    /// @brief - Reads value from the ADC 
    /// @returns - measured FSR resistance
    uint32_t readValue() const;

    /// @brief - Filters value using an averaging filter
    /// @returns - measured and filtered FSR resistance
    uint32_t readFilteredValue() const;

    /// @brief - Scales value to MIDI velocity
    /// @returns - Midi velocity (0-127)
    uint32_t scaleToMidi(uint32_t value) const;
    
private:
    uint32_t input_pin_;    // ADC pin
    uint32_t power_pin_;    // pin to use for 5V
    
    static constexpr size_t FILTER_SIZE = 3;    // Sample size of filter. Increaseing this would increase latency  
    static constexpr uint32_t ADC_SCALE = 90;   // in percent
};

#endif
