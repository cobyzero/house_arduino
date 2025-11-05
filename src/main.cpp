#include <Arduino.h>
#include "controllers/network_controller.h"

void setup()
{
  networkController.Setup();
}

void loop()
{
  networkController.Loop();
}
