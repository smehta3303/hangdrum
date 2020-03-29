/*
 * Creates an FSR object for handling FSR sensors.
 * Includes functionality for mapping FSR input to 
 * MIDI note velocities.
 * 
 * Has a simple averaging filter for filtered output.
 */

#ifndef INCLUDE_FSR_H_
#define INCLUDE_FSR_H_

class Fsr
{
public:
    Fsr(uint32_t input_pin, uint32_t power_pin);
    virtual ~Fsr() = default;

    /// @brief - Reads value from the ADC 
    /// @returns - measured FSR resistance
    uint32_t read_value() const;

    /// @brief - Filters value using an averaging filter
    /// @returns - measured and filtered FSR resistance
    uint32_t read_filtered_value() const;

    /// @brief - Scales value to MIDI velocity
    /// @returns - Midi velocity (0-127)
    uint32_t scale_to_midi(uint32_t value) const;
    
private:
    uint32_t input_pin_;    // ADC pin
    uint32_t power_pin_;    // pin to use for 5V
    
    static constexpr size_t FILTER_SIZE = 3;    // Sample size of filter. Increaseing this would increase latency  
};

#endif
