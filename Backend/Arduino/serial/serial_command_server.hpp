/*
 * Copyright 2022 Casey Sanchez
 */

#pragma once

#include <Arduino.h>

enum SerialCommandStatus : uint8_t
{
    FAILURE = 0,
    SUCCESS = 1
};

struct SerialCommandRequest
{
    uint8_t command;
    uint8_t size;
    uint8_t buffer[255];
};

struct SerialCommandResponse
{
    uint8_t status;
    uint8_t size;
    uint8_t buffer[255];
};

template <size_t MAX_COMMANDS>
class SerialCommandServer
{
    struct SerialCommand
    {
        uint8_t command;
        uint8_t (*callback)(uint8_t const &, uint8_t const *, uint8_t &, uint8_t *);

        SerialCommand() :
            command { ~0 },
            callback { nullptr }
        {            
        }
    };
  
    SerialCommand m_serial_commands[MAX_COMMANDS];
  
    size_t m_num_commands;
  
public:
    SerialCommandServer() :
        m_num_commands { 0 }
    {
        Serial.begin(115200);
      
        while (!Serial);
    }

    bool registerCommand(uint8_t const &command, uint8_t (*callback)(uint8_t const &, uint8_t const *, uint8_t &, uint8_t *))
    {
        if (m_num_commands >= MAX_COMMANDS || command == ~0 || callback == nullptr) {
            return false;
        }
        else {
            size_t const index = m_num_commands++;
          
            m_serial_commands[index].command = command;
            m_serial_commands[index].callback = callback;
          
            return true;
        }
    }
    
    void listen()
    {
        if (Serial.available()) {
            SerialCommandRequest request;
            SerialCommandResponse response;
        
            Serial.readBytes(&request.command, sizeof(uint8_t));  
            Serial.readBytes(&request.size, sizeof(uint8_t));
        
            if (request.size > 0) {
                Serial.readBytes(&request.buffer[0], request.size);
            }

            response.status = SerialCommandStatus::FAILURE;
            
            for (size_t index = 0; index < m_num_commands; ++index) {
                if (m_serial_commands[index].command == request.command) {
                    response.status = m_serial_commands[index].callback(request.size, request.buffer, response.size, response.buffer);
            
                    break;
                }
            }

            if (response.status == SerialCommandStatus::FAILURE) {
                response.size = 0;
            }
        
            Serial.write(&response.status, sizeof(uint8_t));
            Serial.write(&response.size, sizeof(uint8_t));
        
            if (response.size > 0) {
                Serial.write(&response.buffer[0], response.size);
            }
        }
    }
};
