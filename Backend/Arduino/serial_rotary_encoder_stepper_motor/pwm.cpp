#include "pwm.hpp"

PWM::PWM(uint8_t const &pin, float const &period) : 
    m_pin { pin }, 
    m_period { period },
    m_duty_cycle { 0.0f },
    m_state { LOW },
    m_elapsed { 0.0f }
{
    pinMode(m_pin, OUTPUT);
  
    m_then = static_cast<float>(micros()) * 1e-6;
}

void PWM::setDutyCycle(float const &duty_cycle)
{
    m_duty_cycle = min(max(duty_cycle, 0.0f), 1.0f);
}

void PWM::update()
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

void PWM::pulse(float const &elapsed)
{
    m_elapsed += elapsed;
  
    if (m_state == LOW) {
        if (m_elapsed >= m_period * (1.0f - m_duty_cycle)) {
            m_elapsed = 0.0f;
            
            m_state = HIGH;
            
            digitalWrite(m_pin, m_state);
        }
    }
    else if (m_state == HIGH) {
        if (m_elapsed >= m_period * m_duty_cycle) {
            m_elapsed = 0.0f;
            
            m_state = LOW;
            
            digitalWrite(m_pin, m_state);
        }
    }
}
