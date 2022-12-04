#include <iostream>

class Switch1
{
public:
    void turnOnSwitch1()
    {
        std::cout << "Switch1 is on" << std::endl;
    }

    void turnOffSwitch1()
    {
        std::cout << "Switch 1 is off" << std::endl;
    }
};

class Switch2
{
public:
    void turnOnSwitch2()
    {
        std::cout << "Switch2 is on" << std::endl;
    }

    void turnOffSwitch2()
    {
        std::cout << "Switch 2 is off" << std::endl;
    }
};

class Switch3
{
public:
    void turnOnSwitch3()
    {
        std::cout << "Switch3 is on" << std::endl;
    }

    void turnOffSwitch3()
    {
        std::cout << "Switch 3 is off" << std::endl;
    }
};

class Radio
{
public:
    void turnOnRadio()
    {
        switch1.turnOnSwitch1();
        switch2.turnOnSwitch2();
        switch3.turnOnSwitch3();
    }
    
    void turnOffRadio()
    {
        switch1.turnOffSwitch1();
        switch2.turnOffSwitch2();
        switch3.turnOffSwitch3();
    }

private:
    Switch1 switch1;
    Switch2 switch2;
    Switch3 switch3;
};

int main()
{
    Radio radio;

    radio.turnOnRadio();
    radio.turnOffRadio();

    return 0;
}
