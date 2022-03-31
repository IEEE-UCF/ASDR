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

class SerialCommandServer
{
    static size_t const MAX_COMMANDS = 16;
    
    struct SerialCommand
    {
        uint8_t command;
        uint8_t (*callback)(uint8_t const &, uint8_t const *, uint8_t &, uint8_t *);
    };
  
    SerialCommand m_serial_commands[MAX_COMMANDS];
  
    size_t m_num_commands = 0;
  
public:
    bool registerCommand(uint8_t const &command, uint8_t (*callback)(uint8_t const &, uint8_t const *, uint8_t &, uint8_t *));
    
    void enable();
  
    void listen();
};
