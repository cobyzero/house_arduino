#pragma once

#include <Arduino.h>

class NetworkController
{
public:
    NetworkController();
    void Setup();
    void Loop();

private:
    int serialPort;
};
extern NetworkController networkController;