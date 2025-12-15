#include "network_controller.h"
#include "pin_controller.h"
#include <Arduino.h>
#include "../utils/commands.h"
#include "../utils/utils.h"

NetworkController networkController;

NetworkController::NetworkController()
{
    serialPort = 9600;
}

void NetworkController::Setup()
{
    Serial.begin(serialPort);
    Serial.println("NetworkController initialized.");
}

void alarmOn(int pin, int seconds)
{
    if(seconds == 0){
        return;
    }
    pinController.On(pin);
    delay(500);
    pinController.Off(pin);
    delay(500);
    alarmOn(pin, seconds - 1);
}

void NetworkController::Loop()
{
    if (Serial.available())
    {
        String command = Serial.readStringUntil('\n'); // room.light.on.1
        command.trim();
        String partes[10];
        int count = 0;
        splitString(command, partes, count);

        Command cmd = parseCommand(partes[1] + "." + partes[2]);
        int pin = partes[3].toInt();
        switch (cmd)
        {
        case ALARM_ON:
            alarmOn(pin, 5);
            Serial.println("Alarm turned ON");
            break;
        case LED_ON:
        case VENTILATOR_ON:
        case DOOR_OPEN:
            pinController.On(pin);
            Serial.println("Device turned ON");
            break;
        case LED_OFF:
        case VENTILATOR_OFF:
        case ALARM_OFF:
        case DOOR_CLOSE:
            pinController.Off(pin);
            Serial.println("Device turned OFF");
            break;
        case SETUP_PINS:
            pinController.Setup(pin);
            Serial.println("Pins setup completed");
            break;
        case NONE:
            Serial.println("Unknown command");
            break;
        default:
            break;
        }
    }
}