#include <Arduino.h>

enum Command
{
    NONE,
    LED_ON,
    LED_OFF
};

Command parseCommand(const String &command)
{
    if (command == "room.light.on")
        return LED_ON;
    else if (command == "room.light.off")
        return LED_OFF;
    return NONE;
}