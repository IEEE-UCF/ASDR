#pragma once

#include <Arduino.h>

class RotaryEncoder
{
    int8_t const m_direction[16] = {
        0, -1, 1, 0,
        1, 0, 0, -1,
        -1, 0, 0, 1,
        0, 1, -1, 0 };
  
    uint8_t m_pin_1;
    uint8_t m_pin_2;
  
    uint32_t m_steps_per_revolution;
  
    uint8_t m_state;
  
    int32_t m_count;
  
    float m_position;
    float m_velocity;
  
    float m_elapsed;
    
    float m_then;

public:
    RotaryEncoder(uint8_t const &pin_1, uint8_t const &pin_2, uint32_t const &steps_per_revolution);
    
    float getPosition() const;
    float getVelocity() const;
    
    void update();

private:
    void step(float const &elapsed);
};
