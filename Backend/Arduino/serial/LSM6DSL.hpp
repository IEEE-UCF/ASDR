#pragma once

uint8_t constexpr LSM6DSL_ADDRESS = 0x6A;

uint8_t constexpr LSM6DSL_WHO_AM_I = 0x0F;
uint8_t constexpr LSM6DSL_RAM_ACCESS = 0x01;
uint8_t constexpr LSM6DSL_CTRL1_XL = 0x10;
uint8_t constexpr LSM6DSL_CTRL8_XL = 0x17;
uint8_t constexpr LSM6DSL_CTRL2_G = 0x11;
uint8_t constexpr LSM6DSL_CTRL10_C = 0x19;
uint8_t constexpr LSM6DSL_TAP_CFG1 = 0x58;
uint8_t constexpr LSM6DSL_INT1_CTRL = 0x0D;
uint8_t constexpr LSM6DSL_CTRL3_C = 0x12;
uint8_t constexpr LSM6DSL_CTRL4_C = 0x13;

uint8_t constexpr LSM6DSL_STEP_COUNTER_L = 0x4B;
uint8_t constexpr LSM6DSL_STEP_COUNTER_H = 0x4C;

uint8_t constexpr LSM6DSL_OUT_X_L_XL = 0x28;
uint8_t constexpr LSM6DSL_OUT_X_H_XL = 0x29;
uint8_t constexpr LSM6DSL_OUT_Y_L_XL = 0x2A;
uint8_t constexpr LSM6DSL_OUT_Y_H_XL = 0x2B;
uint8_t constexpr LSM6DSL_OUT_Z_L_XL = 0x2C;
uint8_t constexpr LSM6DSL_OUT_Z_H_XL = 0x2D;

uint8_t constexpr LSM6DSL_OUT_L_TEMP = 0x20;
uint8_t constexpr LSM6DSL_OUT_H_TEMP = 0x21;

uint8_t constexpr LSM6DSL_OUT_X_L_G = 0x22;
uint8_t constexpr LSM6DSL_OUT_X_H_G = 0x23;
uint8_t constexpr LSM6DSL_OUT_Y_L_G = 0x24;
uint8_t constexpr LSM6DSL_OUT_Y_H_G = 0x25;
uint8_t constexpr LSM6DSL_OUT_Z_L_G = 0x26;
uint8_t constexpr LSM6DSL_OUT_Z_H_G = 0x27;

uint8_t constexpr LSM6DSL_TAP_CFG = 0x58;
uint8_t constexpr LSM6DSL_WAKE_UP_SRC = 0x1B;
uint8_t constexpr LSM6DSL_WAKE_UP_DUR = 0x5C;
uint8_t constexpr LSM6DSL_FREE_FALL = 0x5D;
uint8_t constexpr LSM6DSL_MD1_CFG = 0x5E;
uint8_t constexpr LSM6DSL_MD2_CFG = 0x5F;
uint8_t constexpr LSM6DSL_TAP_THS_6D = 0x59;
uint8_t constexpr LSM6DSL_INT_DUR2 = 0x5A;
uint8_t constexpr LSM6DSL_WAKE_UP_THS = 0x5B;
uint8_t constexpr LSM6DSL_FUNC_SRC1 = 0x53;
