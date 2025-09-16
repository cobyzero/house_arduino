#include "network_controller.h"
#include "led_controller.h"
#include <Arduino.h>
#include "../utils/commands.h"

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

void NetworkController::Loop()
{
    if (Serial.available())
    {
        String command = Serial.readStringUntil('\n');
        command.trim();
        Command cmd = parseCommand(command);
        switch (cmd)
        {
        case LED_ON:
            ledController.On(ledController.GetPinRoom());
            Serial.println("Room light turned ON");
            break;
        case LED_OFF:
            ledController.Off(ledController.GetPinRoom());
            Serial.println("Room light turned OFF");
            break;
        case NONE:
            Serial.println("Unknown command");
            break;
        default:
            break;
        }
    }
}