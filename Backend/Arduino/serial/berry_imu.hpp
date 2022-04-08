/*
* Copyright 2022 Casey Sanchez
*/

#pragma once

#include <Arduino.h>
#include <Wire.h>

#include "LSM6DSL.hpp"
#include "LIS3MDL.hpp"

enum : uint8_t
{
    FS_G_250 = 0,
    FS_G_500,
    FS_G_1000,
    FS_G_2000
};

enum : uint8_t
{
    FS_XL_2 = 0,
    FS_XL_4,
    FS_XL_8,
    FS_XL_16
};

enum : uint8_t
{
    FS_M_4 = 0,
    FS_M_8,
    FS_M_12,
    FS_M_16
};

uint8_t const FS_G_bits[4] = {
    0b00, // FS_G_250
    0b01, // FS_G_500
    0b10, // FS_G_1000
    0b11  // FS_G_2000
};

float const FS_G_sensitivity[4] = {
    8.75f, // FS_G_250
    17.5f, // FS_G_500
    35.0f, // FS_G_1000
    70.0f  // FS_G_2000
};

uint8_t const FS_XL_bits[4] = {
    0b00, // FS_XL_2
    0b10, // FS_XL_4
    0b11, // FS_XL_8
    0b01  // FS_XL_16
};

float const FS_XL_sensitivity[4] = {
    0.061f, // FS_XL_2
    0.122f, // FS_XL_4
    0.244f, // FS_XL_8
    0.488f  // FS_XL_16
};

uint8_t const FS_M_bits[4] = {
    0b00, // FS_M_4
    0b01, // FS_M_8
    0b10, // FS_M_12
    0b11  // FS_M_16
};

float const FS_M_sensitivity[4] = {
    6842.0f, // FS_M_4
    3421.0f, // FS_M_8
    2281.0f, // FS_M_12
    1711.0f  // FS_M_16
};

class BerryIMU
{
    uint8_t m_FS_G;
    uint8_t m_FS_XL;
    uint8_t m_FS_M;

public:
    BerryIMU(uint8_t const &FS_G = FS_G_2000, uint8_t const &FS_XL = FS_XL_16, uint8_t const &FS_M = FS_M_16);

    // Convert to SI units [mdeg/sec]->[rad/sec]
    void readGyr(float gyr[3]);
    // Convert to SI units [mG]->[m/s^2]
    void readAcc(float acc[3]);
    // Convert to SI units [Gauss]->[Tesla]
    void readMag(float mag[3]);

private:
    void write(uint8_t const &device, uint8_t const &address, uint8_t const &value);
    void read(uint8_t const &device, uint8_t const &address, uint8_t const &size, uint8_t *buffer);
};
