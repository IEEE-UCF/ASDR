/*
 * Copyright 2022 Casey Sanchez
 */

#include "rotary_encoder.hpp"

RotaryEncoder::RotaryEncoder(uint8_t const &pin_1, uint8_t const &pin_2, uint32_t const &steps_per_revolution) :
    m_pin_1 { pin_1 },
    m_pin_2 { pin_2 },
    m_steps_per_revolution { steps_per_revolution },
    m_count { 0 },
    m_position { 0.0f },
    m_velocity { 0.0f },
    m_elapsed { 0.0f }
{
    pinMode(m_pin_1, INPUT_PULLUP);
    pinMode(m_pin_2, INPUT_PULLUP);
  
    m_state = digitalRead(m_pin_1) | (digitalRead(m_pin_2) << 1);
  
    m_then = micros();
}

float RotaryEncoder::getPosition() const
{
    return m_position;
}

float RotaryEncoder::getVelocity() const
{
    return m_velocity;
}

void RotaryEncoder::update()
{
    uint32_t const now = micros();
  
    if (now > m_then) {
        float const elapsed = static_cast<float>(now - m_then) * 1e-6;
    
        step(elapsed);
    }
    else {        
        float const elapsed = static_cast<float>(~0U - m_then + now) * 1e-6;
    
        step(elapsed);
    }
  
    m_then = now;
}

void RotaryEncoder::step(float const &elapsed)
{
    m_elapsed += elapsed;
    
    uint8_t const state = digitalRead(m_pin_1) | (digitalRead(m_pin_2) << 1);
  
    if (state != m_state) {  
        m_count += m_direction[state | (m_state << 2)];
    
        if (m_count < 0) {
            m_count = m_steps_per_revolution;
        }
        else if (m_count > m_steps_per_revolution) {
            m_count = 0;
        }
    
        float const previous_position = m_position;
        
        m_position = static_cast<float>(m_count) / static_cast<float>(m_steps_per_revolution) * 2.0f * 3.141592f;
    
        m_velocity = (m_position - previous_position) / m_elapsed;
        
        m_state = state;
    
        m_elapsed = 0.0f;
    } 
}
