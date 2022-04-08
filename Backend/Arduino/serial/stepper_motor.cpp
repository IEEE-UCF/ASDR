/*
 * Copyright 2022 Casey Sanchez
 */

#pragma once

#include "stepper_motor.hpp"

StepperMotor::StepperMotor(uint8_t const &pin_dir, uint8_t const &pin_pul, uint32_t const &steps_per_revolution, float const &max_velocity) : 
    m_pin_dir { pin_dir }, 
    m_pin_pul { pin_pul }, 
    m_period { 2.0f * 3.141592f / (static_cast<float>(steps_per_revolution) * max_velocity) },
    m_duty_cycle { 0.0f },
    m_state { LOW },
    m_elapsed { 0.0f },
    m_steps_per_revolution { steps_per_revolution }, 
    m_max_velocity { max_velocity }
{
    pinMode(m_pin_dir, OUTPUT);
    pinMode(m_pin_pul, OUTPUT);
  
    m_then = micros();
}

void StepperMotor::setVelocity(float const &velocity)
{
    if (velocity > 0.0f) {
        digitalWrite(m_pin_dir, HIGH);
    
        if (velocity > m_max_velocity) {
            m_duty_cycle = 1.0f;
        }
        else {
            m_duty_cycle = min(max(velocity / m_max_velocity, 0.0f), 1.0f);
        }
    }
    else if (velocity < 0.0f) {
        digitalWrite(m_pin_dir, LOW);
        
        if (velocity * -1.0f > m_max_velocity) {
            m_duty_cycle = 1.0f;
        }
        else {
            m_duty_cycle = min(max(velocity * -1.0f / m_max_velocity, 0.0f), 1.0f);
        }
    }
    else {
        digitalWrite(m_pin_dir, LOW);
    
        m_duty_cycle = 0.0f;
    }
}

void StepperMotor::update()
{
    uint32_t const now = micros();
  
    if (now > m_then) {
        float const elapsed = static_cast<float>(now - m_then) * 1e-6;
    
        pulse(elapsed);
    }
    else {
        float const elapsed = static_cast<float>(~0U - m_then + now) * 1e-6;
    
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
            
            digitalWrite(m_pin_pul, m_state);
        }
    }
    else if (m_state == HIGH) {
        if (m_elapsed >= m_period * m_duty_cycle) {
            m_elapsed = 0.0f;
            
            m_state = LOW;
            
            digitalWrite(m_pin_pul, m_state);
        }
    }
}
