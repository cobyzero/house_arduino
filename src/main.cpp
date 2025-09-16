#include <Arduino.h>
#include "controllers/led_controller.h"
#include "controllers/network_controller.h"
void setup()
{
  networkController.Setup();
  ledController.Setup();
}

void loop()
{
  networkController.Loop();
}
