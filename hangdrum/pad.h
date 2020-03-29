#ifndef INCLUDE_PAD_H_
#define INCLUDE_PAD_H_

#include "fsr.h"

class Pad
{
public:
    Pad(const Fsr& fsr) :
    fsr_(fsr),
    current_state_(false),
    previous_state_(false),
    pad_value_(0)
    {}

    virtual ~Pad() = default;

    const bool get_current_state() const;
    const bool get_previous_state() const;
    const uint32_t get_value() const;
    void read() const;

private:
    const Fsr& fsr_;
    mutable bool current_state_;
    mutable bool previous_state_;
    mutable uint32_t pad_value_;
};

#endif