#include "pid.hpp"

PID::PID(double const &proportional_gain, double const &integral_gain, double const &derivative_gain) : 
    m_proportional_gain { proportional_gain }, 
    m_integral_gain { integral_gain }, 
    m_derivative_gain { derivative_gain }, 
    m_previous_error { 0.0 }, 
    m_integral { 0.0 }
{
}

double PID::compute(double const &error, double const &delta_time)
{
    m_integral += error * delta_time;

    double const proportional_term = m_proportional_gain * error;

    double const integral_term = m_integral_gain * m_integral;

    double const derivative_term = m_derivative_gain * (error - m_previous_error) / delta_time;

    m_previous_error = error;

    return proportional_term + integral_term + derivative_term;
}
