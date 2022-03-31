#include "berry_imu.hpp"

BerryIMU::BerryIMU(int32_t const &FS_G, int32_t const &FS_XL, int32_t const &FS_M) : m_FS_G(FS_G), m_FS_XL(FS_XL), m_FS_M(FS_M)
{
    Wire.begin();
}

void BerryIMU::enable()
{
    //Enable  gyroscope
    write(LSM6DSL_ADDRESS, LSM6DSL_CTRL2_G, 0b10010000 | (FS_G_bits[m_FS_G] << 2));

    // Enable the accelerometer
    write(LSM6DSL_ADDRESS, LSM6DSL_CTRL1_XL, 0b10010011 | (FS_XL_bits[m_FS_XL] << 2));
    write(LSM6DSL_ADDRESS, LSM6DSL_CTRL8_XL, 0b11001000);
    write(LSM6DSL_ADDRESS, LSM6DSL_CTRL3_C, 0b01000100);

    //Enable  magnetometer
    write(LIS3MDL_ADDRESS, LIS3MDL_CTRL_REG1, 0b11011100);
    write(LIS3MDL_ADDRESS, LIS3MDL_CTRL_REG2, 0b00000000 | (FS_M_bits[m_FS_M] << 5));
    write(LIS3MDL_ADDRESS, LIS3MDL_CTRL_REG3, 0b00000000);
}

// Convert to SI units [mdeg/sec]->[rad/sec]
void BerryIMU::readGyr(float gyr[3])
{
    float const conversion { 3.14159265358979323846f / 180.0f / 1000.0f }; 
    
    int16_t raw[3];
    
    read(LSM6DSL_ADDRESS, LSM6DSL_OUT_X_L_G, 6, reinterpret_cast<uint8_t *>(&raw[0]));
    
    gyr[0] = static_cast<float>(raw[0]) * FS_G_sensitivity[m_FS_G] * conversion;
    gyr[1] = static_cast<float>(raw[1]) * FS_G_sensitivity[m_FS_G] * conversion;
    gyr[2] = static_cast<float>(raw[2]) * FS_G_sensitivity[m_FS_G] * conversion;
}

// Convert to SI units [mG]->[m/s^2]
void BerryIMU::readAcc(float acc[3])
{
    float const conversion { 9.8f / 1000.0f };
    
    int16_t raw[3];
    
    read(LSM6DSL_ADDRESS, LSM6DSL_OUT_X_L_XL, 6, reinterpret_cast<uint8_t *>(&raw[0]));
    
    acc[0] = static_cast<float>(raw[0]) * FS_XL_sensitivity[m_FS_XL] * conversion;
    acc[1] = static_cast<float>(raw[1]) * FS_XL_sensitivity[m_FS_XL] * conversion;
    acc[2] = static_cast<float>(raw[2]) * FS_XL_sensitivity[m_FS_XL] * conversion;
}

// Convert to SI units [Gauss]->[Tesla]
void BerryIMU::readMag(float mag[3])
{
    float const conversion { 1.0f / 10000.0f };
    
    int16_t raw[3];
    
    read(LIS3MDL_ADDRESS, LIS3MDL_OUT_X_L, 6, reinterpret_cast<uint8_t *>(&raw[0]));
    
    mag[0] = static_cast<float>(raw[0]) * FS_M_sensitivity[m_FS_M] * conversion;
    mag[1] = static_cast<float>(raw[1]) * FS_M_sensitivity[m_FS_M] * conversion;
    mag[2] = static_cast<float>(raw[2]) * FS_M_sensitivity[m_FS_M] * conversion;
}

void BerryIMU::write(uint8_t const &device, uint8_t const &address, uint8_t const &value) 
{
    Wire.beginTransmission(device); 

    Wire.write(address); 
    Wire.write(value); 

    Wire.endTransmission(); 
}

void BerryIMU::read(uint8_t const &device, uint8_t const &address, size_t const &size, uint8_t *buffer) 
{
    Wire.beginTransmission(device); 

    Wire.write(address); 

    Wire.endTransmission(); 

    Wire.beginTransmission(device); 

    Wire.requestFrom(device, size); 

    uint32_t index = 0;

    while (Wire.available()) { 
        buffer[index++] = Wire.read(); 
    }

    Wire.endTransmission(); 
}
