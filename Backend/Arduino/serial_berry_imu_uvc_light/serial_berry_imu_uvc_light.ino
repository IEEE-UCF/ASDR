#include "serial_command_server.hpp"
#include "berry_imu.hpp"

SerialCommandServer serial_command_server;

BerryIMU berry_imu;

uint8_t berry_imu_read(uint8_t const &request_size, uint8_t const *request_buffer, uint8_t &response_size, uint8_t *response_buffer)
{
    float gyr[3];
    float acc[3];
    float mag[3];
  
    berry_imu.readGyr(gyr);
    berry_imu.readAcc(acc);
    berry_imu.readMag(mag);
  
    response_size = sizeof(float) * 3 * 3;
  
    memcpy(&response_buffer[sizeof(float) * 3 * 0], &gyr[0], sizeof(float) * 3);
    memcpy(&response_buffer[sizeof(float) * 3 * 1], &acc[0], sizeof(float) * 3);
    memcpy(&response_buffer[sizeof(float) * 3 * 2], &mag[0], sizeof(float) * 3);
  
    return SerialCommandStatus::SUCCESS;
}

uint8_t uvc_light_write(uint8_t const &request_size, uint8_t const *request_buffer, uint8_t &response_size, uint8_t *response_buffer)
{
    return SerialCommandStatus::SUCCESS;
}

void setup() 
{
    serial_command_server.registerCommand(0, &berry_imu_read);
    serial_command_server.registerCommand(1, &uvc_light_write);
    
    serial_command_server.enable();
    
    berry_imu.enable();
}

void loop() 
{
    serial_command_server.listen();
}
