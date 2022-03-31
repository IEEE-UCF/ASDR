#include "serial_command_server.hpp"

bool SerialCommandServer::registerCommand(uint8_t const &command, uint8_t (*callback)(uint8_t const &, uint8_t const *, uint8_t &, uint8_t *))
{
    if (m_num_commands >= MAX_COMMANDS) {
        return false;
    }
  
    size_t const index = m_num_commands;
  
    m_serial_commands[index].command = command;
    m_serial_commands[index].callback = callback;
  
    m_num_commands++;
  
    return true;
}

void SerialCommandServer::enable()
{  
    Serial.begin(115200);
  
    while (!Serial);
}

void SerialCommandServer::listen()
{
    if (Serial.available()) {
        SerialCommandRequest request;
    
        Serial.readBytes(&request.command, sizeof(uint8_t));  
        Serial.readBytes(&request.size, sizeof(uint8_t));
    
        if (request.size > 0) {
            Serial.readBytes(&request.buffer[0], request.size);
        }
    
        SerialCommandResponse response;
    
        response.status = SerialCommandStatus::FAILURE;
        response.size = 0;
        
        for (size_t index = 0; index < m_num_commands; ++index) {
            if (m_serial_commands[index].command == request.command) {
                response.status = m_serial_commands[index].callback(request.size, request.buffer, response.size, response.buffer);
        
                break;
            }
        }
    
        Serial.write(&response.status, sizeof(uint8_t));
        Serial.write(&response.size, sizeof(uint8_t));
    
        if (response.size > 0) {
            Serial.write(&response.buffer[0], response.size);
        }
    }
}
