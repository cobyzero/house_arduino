#include <Arduino.h>

enum Command
{
    NONE,
    LED_ON,
    LED_OFF,
    VENTILATOR_ON,
    VENTILATOR_OFF,
    SETUP_PINS
};

Command parseCommand(const String &command);