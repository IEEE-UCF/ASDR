/*
 * Copyright 2022 Casey Sanchez
 */

#pragma once

#include "stepper_motor.hpp"

StepperMotor::StepperMotor(uint8_t const &dir_pin, uint8_t const &pul_pin, uint32_t const &steps_per_revolution, float const &max_velocity) : 
    m_dir_pin { dir_pin }, 
    m_pul_pin { pul_pin }, 
    m_period { 2.0f * 3.141592f / (static_cast<float>(steps_per_revolution) * max_velocity) },
    m_duty_cycle { 0.0f },
    m_state { LOW },
    m_elapsed { 0.0f },
    m_steps_per_revolution { steps_per_revolution }, 
    m_max_velocity { max_velocity }
{
    pinMode(m_dir_pin, OUTPUT);
    pinMode(m_pul_pin, OUTPUT);
  
    m_then = static_cast<float>(micros()) * 1e-6;
}

void StepperMotor::setVelocity(float const &velocity)
{
    if (velocity > 0.0f) {
        digitalWrite(m_dir_pin, HIGH);
    
        if (velocity > m_max_velocity) {
            m_duty_cycle = 1.0f;
        }
        else {
            m_duty_cycle = min(max(velocity / m_max_velocity, 0.0f), 1.0f);
        }
    }
    else if (velocity < 0.0f) {
        digitalWrite(m_dir_pin, LOW);
        
        if (velocity * -1.0f > m_max_velocity) {
            m_duty_cycle = 1.0f;
        }
        else {
            m_duty_cycle = min(max(velocity * -1.0f / m_max_velocity, 0.0f), 1.0f);
        }
    }
    else {
        digitalWrite(m_dir_pin, LOW);
    
        m_duty_cycle = 0.0f;
    }
}

void StepperMotor::update()
{
    float const now = static_cast<float>(micros()) * 1e-6;
  
    if (now > m_then) {
        float const elapsed = now - m_then;
    
        pulse(elapsed);
    }
    else {
        static float const max_time = static_cast<float>(uint32_t(~0)) * 1e-6;
        
        float const elapsed = max_time - m_then + now;
    
        pulse(elapsed);
    }
  
    m_then = now;
}

void StepperMotor::pulse(float const &elapsed)
{
    m_elapsed += elapsed;
  
    if (m_state == LOW) {
        if (m_elapsed >= m_period * (1.0f - m_duty_cycle)) {
            m_elapsed = 0.0f;
            
            m_state = HIGH;
            
            digitalWrite(m_pul_pin, m_state);
        }
    }
    else if (m_state == HIGH) {
        if (m_elapsed >= m_period * m_duty_cycle) {
            m_elapsed = 0.0f;
            
            m_state = LOW;
            
            digitalWrite(m_pul_pin, m_state);
        }
    }
}
