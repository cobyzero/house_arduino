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
    else if (command == "alarm.on")
    {
        return ALARM_ON;
    }
    else if (command == "alarm.off")
    {
        return ALARM_OFF;
    }
    else if (command == "door.open")
    {
        return DOOR_OPEN;
    }
    else if (command == "door.close")
    {
        return DOOR_CLOSE;
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