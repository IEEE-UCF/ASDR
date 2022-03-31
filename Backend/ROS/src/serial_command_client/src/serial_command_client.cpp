/*
 * Copyright 2022 Casey Sanchez
 */

#include "serial_command_client.hpp"

SerialCommandClient::SerialCommandClient(std::string const &serial_port) :
    m_serial { serial_port, 115200, serial::Timeout::simpleTimeout(1000) }
{
}

SerialCommandClient::~SerialCommandClient()
{
    if (m_serial.isOpen()) {
        m_serial.close();
    }
}

bool SerialCommandClient::sendCommand(SerialCommandRequest const &request, SerialCommandResponse &response)
{
    if (m_serial.isOpen()) {
        m_serial.write(&request.command, sizeof(uint8_t));
        m_serial.write(&request.size, sizeof(uint8_t));

        if (request.size > 0) {
            m_serial.write(&request.buffer[0], request.size);
        }

        m_serial.read(&response.status, sizeof(uint8_t));
        m_serial.read(&response.size, sizeof(uint8_t));

        if (response.size > 0) {
            m_serial.read(&response.buffer[0], response.size);
        }

        return true;
    }

    return false;
}