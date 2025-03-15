#include "NextionComLib.h"

HardwareSerial *nextionSerial = nullptr; // Seri port başlangıçta boş olacak

void NextionComLib_begin(HardwareSerial &serial, long baudrate) {
    nextionSerial = &serial;
    nextionSerial->begin(baudrate);
}

void NextionComLib_sendCommand(const char *cmd) {
    if (nextionSerial) {
        nextionSerial->print(cmd);
        nextionSerial->write(0xFF);
        nextionSerial->write(0xFF);
        nextionSerial->write(0xFF); // Nextion komut sonlandırıcı
    }
}

String NextionComLib_receiveResponse() {
    String response = "";
    if (nextionSerial) {
        while (nextionSerial->available()) {
            response += (char)nextionSerial->read();
        }
    }
    return response;
}
