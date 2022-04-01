/*
 * Copyright 2022 Casey Sanchez
 */

#pragma once

#include <Arduino.h>

class StepperMotor
{  
    uint8_t m_dir_pin;
    uint8_t m_pul_pin;
  
    float m_period;  
    float m_duty_cycle;
    
    uint8_t m_state;
    
    float m_elapsed;    
    float m_then;

    uint32_t m_steps_per_revolution;
  
    float m_max_velocity;
  
public:
    StepperMotor(uint8_t const &dir_pin, uint8_t const &pul_pin, uint32_t const &steps_per_revolution, float const &max_velocity);
  
    void setVelocity(float const &velocity);
  
    void update();

private:
    void pulse(float const &elapsed);
};
