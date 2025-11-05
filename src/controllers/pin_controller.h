

class PinController
{
public:
    PinController();
    void Setup(int pinRoom);
    void On(int pin);
    void Off(int pin);
};
extern PinController pinController;