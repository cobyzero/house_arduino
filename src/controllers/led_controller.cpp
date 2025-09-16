#include "led_controller.h"
#include <Arduino.h>

LedController ledController;

LedController::LedController()
{
    pinRoom = 8;
}

void LedController::Setup()
{
    pinMode(pinRoom, OUTPUT);
}

void LedController::On(int pin)
{
    digitalWrite(pin, HIGH);
}

void LedController::Off(int pin)
{
    digitalWrite(pin, LOW);
}