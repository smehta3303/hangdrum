#ifndef INCLUDE_HANGDRUM_H_
#define INCLUDE_HANGDRUM_H_

constexpr uint32_t FSR1_PIN = A0;
constexpr uint32_t FSR2_PIN = A1;
constexpr uint32_t POWER_PIN = 12;

void read_pads();
void update_notes();
void turn_note_on(uint32_t note, uint32_t velocity, uint32_t channel);
void turn_note_off(uint32_t note, uint32_t velocity, uint32_t channel);

#endif