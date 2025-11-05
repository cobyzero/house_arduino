#include "commands.h"

Command parseCommand(const String &command)
{
    if (command == "light.on")
    {
        return LED_ON;
    }
    else if (command == "light.off")
    {
        return LED_OFF;
    }
    else if (command == "ventilator.on")
    {
        return VENTILATOR_ON;
    }
    else if (command == "ventilator.off")
    {
        return VENTILATOR_OFF;
    }
    else if (command == "setup.pins")
    {
        return SETUP_PINS;
    }
    else
    {
        return NONE;
    }
}