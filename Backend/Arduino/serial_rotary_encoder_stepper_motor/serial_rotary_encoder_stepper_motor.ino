#include "rotary_encoder.hpp"
#include "stepper_motor.hpp"

#include "serial_command_server.hpp"

SerialCommandServer serial_command_server;

uint32_t const ROTARY_ENCODER_COUNT = 2;

RotaryEncoder rotary_encoder[ROTARY_ENCODER_COUNT] = {
    RotaryEncoder(5, 6, 300),
    RotaryEncoder(7, 8, 300)
};

uint32_t const STEPPER_MOTOR_COUNT = 2;

StepperMotor stepper_motor[STEPPER_MOTOR_COUNT] = {
    StepperMotor(9, 10, 15652, 3.141592f / 3.0f),
    StepperMotor(11, 12, 15652, 3.141592f / 3.0f)
};

uint8_t rotary_encoder_read(uint8_t const &request_size, uint8_t const *request_buffer, uint8_t &response_size, uint8_t *response_buffer)
{
    if (request_size == sizeof(uint32_t)) {
        uint32_t rotary_encoder_id;
      
        memcpy(&rotary_encoder_id, &request_buffer[0], sizeof(uint32_t));
        
        if (rotary_encoder_id >= 0 && rotary_encoder_id < ROTARY_ENCODER_COUNT) {
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
        
        if (stepper_motor_id >= 0 && stepper_motor_id < STEPPER_MOTOR_COUNT) {
            stepper_motor[stepper_motor_id].setVelocity(velocity);
            
            return SerialCommandStatus::SUCCESS;
        }
    }
  
    return SerialCommandStatus::FAILURE;
}

void setup() 
{
    serial_command_server.registerCommand(0, &rotary_encoder_read); 
    serial_command_server.registerCommand(1, &stepper_motor_write); 
    
    serial_command_server.enable();
}

void loop() 
{
    serial_command_server.listen();
  
    for (uint32_t rotary_encoder_id = 0; rotary_encoder_id < ROTARY_ENCODER_COUNT; ++rotary_encoder_id) {
        rotary_encoder[rotary_encoder_id].update();
    }
  
    for (uint32_t stepper_motor_id = 0; stepper_motor_id < STEPPER_MOTOR_COUNT; ++stepper_motor_id) {
        stepper_motor[stepper_motor_id].update();
    }
}
