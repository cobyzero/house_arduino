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
        switch (cmd)
        {
        case LED_ON:
            pinController.On(partes[3].toInt());
            Serial.println("Room light turned ON");
            break;
        case LED_OFF:
            pinController.Off(partes[3].toInt());
            Serial.println("Room light turned OFF");
            break;
        case SETUP_PINS:
            pinController.Setup(partes[3].toInt());
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