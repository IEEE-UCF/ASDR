/*
 * Copyright 2022 Casey Sanchez
 */

#pragma once

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
    serial::Serial m_serial;
    
public:
    SerialCommandClient(std::string const &serial_port);
    ~SerialCommandClient();

    bool sendCommand(SerialCommandRequest const &request, SerialCommandResponse &response);
};