#ifndef NEXTIONCOMLIB_H
#define NEXTIONCOMLIB_H

#include "Arduino.h"

extern HardwareSerial *nextionSerial; // Seri port değişkeni tanımla

void NextionComLib_begin(HardwareSerial &serial, long baudrate);
void NextionComLib_sendCommand(const char *cmd);
String NextionComLib_receiveResponse();

#endif
