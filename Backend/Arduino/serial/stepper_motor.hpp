/*
 * Copyright 2022 Casey Sanchez
 */

#pragma once

#include <Arduino.h>

class StepperMotor
{  
    uint8_t m_pin_dir;
    uint8_t m_pin_pul;
  
    float m_period;  
    float m_duty_cycle;
    
    uint8_t m_state;
    
    float m_elapsed;
        
    uint32_t m_then;

    uint32_t m_steps_per_revolution;
  
    float m_max_velocity;
  
public:
    StepperMotor(uint8_t const &pin_dir, uint8_t const &pin_pul, uint32_t const &steps_per_revolution, float const &max_velocity);
  
    void setVelocity(float const &velocity);
  
    void update();

private:
    void pulse(float const &elapsed);
};
