#pragma once

#include <Arduino.h>

#include "pwm.hpp"

class StepperMotor
{  
    PWM m_pwm;
  
    uint8_t m_dir_pin;
    
    uint32_t m_steps_per_revolution;
  
    float m_max_velocity;
  
public:
    StepperMotor(uint8_t const &pwm_pin, uint8_t const &dir_pin, uint32_t const &steps_per_revolution, float const &max_velocity);
  
    void setVelocity(float const &velocity);
  
    void update();
};
