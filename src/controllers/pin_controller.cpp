#include "pin_controller.h"
#include <Arduino.h>

PinController pinController;

PinController::PinController()
{
}

void PinController::Setup(int pinRoom)
{
    pinMode(pinRoom, OUTPUT);
}

void PinController::On(int pin)
{
    digitalWrite(pin, HIGH);
}

void PinController::Off(int pin)
{
    digitalWrite(pin, LOW);
}