#pragma once

#include <memory>
#include <string>

#include "serial/serial.h"

enum SerialCommandStatus : uint8_t
{
    SUCCESS = 0,
    FAILURE = 1
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

class SerialCommandClient
{
    std::unique_ptr<serial::Serial> m_serial;
    
public:
    ~SerialCommandClient();

    void open(std::string const &path_name);
    void close();

    bool sendCommand(SerialCommandRequest const &request, SerialCommandResponse &response);
};