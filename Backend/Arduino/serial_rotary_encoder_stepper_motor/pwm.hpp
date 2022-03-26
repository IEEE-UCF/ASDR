#pragma once

#include <Arduino.h>

class PWM
{  
    uint8_t m_pin;
  
    float m_period;
  
    float m_duty_cycle;
    
    uint8_t m_state;
    
    float m_elapsed;
    
    float m_then;
  
public:
    PWM(uint8_t const &pin, float const &period);
  
    void setDutyCycle(float const &duty_cycle);
  
    void update();

private:
    void pulse(float const &elapsed);
};
