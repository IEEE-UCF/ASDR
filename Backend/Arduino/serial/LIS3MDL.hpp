#pragma once

uint8_t constexpr LIS3MDL_ADDRESS = 0x1C;

uint8_t constexpr LIS3MDL_WHO_AM_I = 0x0F;

uint8_t constexpr LIS3MDL_CTRL_REG1 = 0x20;

uint8_t constexpr LIS3MDL_CTRL_REG2 = 0x21;
uint8_t constexpr LIS3MDL_CTRL_REG3 = 0x22;
uint8_t constexpr LIS3MDL_CTRL_REG4 = 0x23;
uint8_t constexpr LIS3MDL_CTRL_REG5 = 0x24;

uint8_t constexpr LIS3MDL_STATUS_REG = 0x27;

uint8_t constexpr LIS3MDL_OUT_X_L = 0x28;
uint8_t constexpr LIS3MDL_OUT_X_H = 0x29;
uint8_t constexpr LIS3MDL_OUT_Y_L = 0x2A;
uint8_t constexpr LIS3MDL_OUT_Y_H = 0x2B;
uint8_t constexpr LIS3MDL_OUT_Z_L = 0x2C;
uint8_t constexpr LIS3MDL_OUT_Z_H = 0x2D;

uint8_t constexpr LIS3MDL_TEMP_OUT_L = 0x2E;
uint8_t constexpr LIS3MDL_TEMP_OUT_H = 0x2F;

uint8_t constexpr LIS3MDL_INT_CFG = 0x30;
uint8_t constexpr LIS3MDL_INT_SRC = 0x31;
uint8_t constexpr LIS3MDL_INT_THS_L = 0x32;
uint8_t constexpr LIS3MDL_INT_THS_H = 0x33;
 