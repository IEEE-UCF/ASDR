#include "serial_command_client.hpp"

SerialCommandClient::~SerialCommandClient()
{
    close();
}

void SerialCommandClient::open(std::string const &path_name)
{
    close();

    m_serial = std::unique_ptr<serial::Serial>(new serial::Serial(path_name, 115200, serial::Timeout::simpleTimeout(1000)));   
}

void SerialCommandClient::close()
{
    if (m_serial) {
        if (m_serial->isOpen()) {
            m_serial->close();
        }

        m_serial.reset();
    }
}

bool SerialCommandClient::sendCommand(SerialCommandRequest const &request, SerialCommandResponse &response)
{
    if (m_serial->isOpen()) {
        m_serial->write(&request.command, sizeof(uint8_t));
        m_serial->write(&request.size, sizeof(uint8_t));

        if (request.size > 0) {
            m_serial->write(&request.buffer[0], request.size);
        }

        m_serial->read(&response.status, sizeof(uint8_t));
        m_serial->read(&response.size, sizeof(uint8_t));

        if (response.size > 0) {
            m_serial->read(&response.buffer[0], response.size);
        }

        return true;
    }

    return false;
}