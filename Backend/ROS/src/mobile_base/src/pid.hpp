#pragma once

class PID
{
    double m_proportional_gain;
    double m_integral_gain;
    double m_derivative_gain;

    double m_integral;

    double m_previous_error;

public:
    PID(double const &proportional_gain, double const &integral_gain, double const &derivative_gain);

    double compute(double const &error, double const &delta_time);
};