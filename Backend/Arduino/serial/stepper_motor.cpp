#include "stepper_motor.hpp"

StepperMotor::StepperMotor(uint8_t const &pwm_pin, uint8_t const &dir_pin, uint32_t const &steps_per_revolution, float const &max_velocity) : 
    m_dir_pin { dir_pin }, 
    m_steps_per_revolution { steps_per_revolution }, 
    m_max_velocity { max_velocity },
    m_pwm { pwm_pin, 2.0f * 3.141592f / (static_cast<float>(steps_per_revolution) * max_velocity) }
{
    pinMode(m_dir_pin, OUTPUT);
}

void StepperMotor::setVelocity(float const &velocity)
{
    if (velocity > 0.0f) {
        digitalWrite(m_dir_pin, HIGH);
    
        if (velocity > m_max_velocity) {
            m_pwm.setDutyCycle(1.0f);
        }
        else {
            m_pwm.setDutyCycle(velocity / m_max_velocity);
        }
    }
    else if (velocity < 0.0f) {
        digitalWrite(m_dir_pin, LOW);
        
        if (velocity * -1.0f > m_max_velocity) {
            m_pwm.setDutyCycle(1.0f);
        }
        else {
            m_pwm.setDutyCycle(velocity * -1.0f / m_max_velocity);
        }
    }
    else {
        digitalWrite(m_dir_pin, LOW);
    
        m_pwm.setDutyCycle(0.0f);
    }
}

void StepperMotor::update()
{
    m_pwm.update();
}
