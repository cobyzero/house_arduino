#include <Arduino.h>

enum Command
{
    NONE,
    LED_ON,
    LED_OFF,
    VENTILATOR_ON,
    VENTILATOR_OFF,
    ALARM_ON,
    ALARM_OFF,
    DOOR_OPEN,
    DOOR_CLOSE,
    SETUP_PINS
};

Command parseCommand(const String &command);