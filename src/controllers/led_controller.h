

class LedController
{
public:
    LedController();
    void Setup();
    void On(int pin);
    void Off(int pin);
    int GetPinRoom() const { return pinRoom; }

private:
    int pinRoom;
};
extern LedController ledController;