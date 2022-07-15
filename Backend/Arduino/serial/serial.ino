/*
 * Copyright 2022 Casey Sanchez
 */

#include "serial_command_server.hpp"
#include "berry_imu.hpp"
#include "rotary_encoder.hpp"
#include "stepper_motor.hpp"

enum : uint8_t
{
    BERRY_IMU_READ_COMMAND = 0,
    UVC_LIGHT_WRITE_COMMAND = 1,
    ROTARY_ENCODER_READ_COMMAND = 2,
    STEPPER_MOTOR_WRITE_COMMAND = 3
};

SerialCommandServer<4> serial_command_server;

BerryIMU berry_imu;

RotaryEncoder rotary_encoder[4] = {
    RotaryEncoder(2, 3, 300),
    RotaryEncoder(4, 5, 300),
    RotaryEncoder(6, 7, 300),
    RotaryEncoder(8, 9, 300)
};

StepperMotor stepper_motor[4] = {
    StepperMotor(22, 23, 3000, 3.141592f * 5.0f / 3.0f),
    StepperMotor(24, 25, 3000, 3.141592f * 5.0f / 3.0f),
    StepperMotor(26, 27, 3000, 3.141592f * 5.0f / 3.0f),
    StepperMotor(28, 29, 3000, 3.141592f * 5.0f / 3.0f)
};

uint8_t berry_imu_read(uint8_t const &request_size, uint8_t const *request_buffer, uint8_t &response_size, uint8_t *response_buffer)
{
    float gyr[3];
    float acc[3];
    float mag[3];
  
    berry_imu.readGyr(&gyr[0]);
    berry_imu.readAcc(&acc[0]);
    berry_imu.readMag(&mag[0]);
  
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

uint8_t rotary_encoder_read(uint8_t const &request_size, uint8_t const *request_buffer, uint8_t &response_size, uint8_t *response_buffer)
{
    if (request_size == sizeof(uint32_t)) {
        uint32_t rotary_encoder_id;
      
        memcpy(&rotary_encoder_id, &request_buffer[0], sizeof(uint32_t));
        
        if (rotary_encoder_id >= 0 && rotary_encoder_id < 4) {
            float const position = rotary_encoder[rotary_encoder_id].getPosition();
            float const velocity = rotary_encoder[rotary_encoder_id].getVelocity();
      
            response_size = sizeof(float) + sizeof(float);
      
            memcpy(&response_buffer[0], &position, sizeof(float));
            memcpy(&response_buffer[sizeof(float)], &velocity, sizeof(float));
        
            return SerialCommandStatus::SUCCESS;
        }
    }
    
    return SerialCommandStatus::FAILURE;
}

uint8_t stepper_motor_write(uint8_t const &request_size, uint8_t const *request_buffer, uint8_t &response_size, uint8_t *response_buffer) 
{
    if (request_size == sizeof(uint32_t) + sizeof(float)) {
        uint32_t stepper_motor_id;
        float velocity;
    
        memcpy(&stepper_motor_id, &request_buffer[0], sizeof(uint32_t));
        memcpy(&velocity, &request_buffer[sizeof(uint32_t)], sizeof(float));
        
        if (stepper_motor_id >= 0 && stepper_motor_id < 4) {
            stepper_motor[stepper_motor_id].setVelocity(velocity);
            
            return SerialCommandStatus::SUCCESS;
        }
    }
  
    return SerialCommandStatus::FAILURE;
}

void setup()
{
    //berry_imu.setup();
  
    serial_command_server.setup();
  
    serial_command_server.registerCommand(BERRY_IMU_READ_COMMAND, &berry_imu_read);
    serial_command_server.registerCommand(UVC_LIGHT_WRITE_COMMAND, &uvc_light_write);
    serial_command_server.registerCommand(ROTARY_ENCODER_READ_COMMAND, &rotary_encoder_read); 
    serial_command_server.registerCommand(STEPPER_MOTOR_WRITE_COMMAND, &stepper_motor_write); 
}

void loop() 
{    
    serial_command_server.listen();

    for (uint32_t rotary_encoder_id = 0; rotary_encoder_id < 4; ++rotary_encoder_id) {
        rotary_encoder[rotary_encoder_id].update();
    }
  
    for (uint32_t stepper_motor_id = 0; stepper_motor_id < 4; ++stepper_motor_id) {
        stepper_motor[stepper_motor_id].update();
    }
}
