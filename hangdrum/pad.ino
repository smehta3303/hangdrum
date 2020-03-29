#include "pad.h"

const bool Pad::get_current_state() const
{
    return current_state_;
}

const bool Pad::get_previous_state() const
{
    return previous_state_;
}

const uint32_t Pad::get_value() const
{
    return (pad_value_);
}

void Pad::read() const
{
    previous_state_ = current_state_;
    pad_value_ = fsr_.scale_to_midi(fsr_.read_value());
    
    if (pad_value_ > 0)
    {
        current_state_ = true;
    }
    else
    {
       current_state_ = false;
    }
}