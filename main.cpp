#include "CanManager.hpp"
#include "DM4310.hpp"

int main()
{

    CanManager testCan;
    testCan.SetPortName("can0");
    testCan.Init();

    DM4310 testMotor1(&testCan);
    testMotor1.Registration(0x07,0x06);
    testMotor1.Enable();
    testMotor1.controlMode = Motor::MIT_MODE;
    testMotor1.SetZero();

    DM4310 testMotor2(&testCan);
    testMotor2.Registration(0x09,0x08);
    testMotor2.Enable();
    testMotor2.controlMode = Motor::MIT_MODE;
    testMotor2.SetZero();

    DM4310 testMotor3(&testCan);
    testMotor3.Registration(0x0B,0x0A);
    testMotor3.Enable();
    testMotor3.controlMode = Motor::MIT_MODE;
    testMotor3.SetZero();


    while(true)
    {
        testMotor1.positionSet = 0;
        testMotor1.speedSet = 0.0;
        testMotor1.kp = 7.0;
        testMotor1.kd = 2.0;

        testMotor2.positionSet = 0;
        testMotor2.speedSet = 0.0;
        testMotor2.kp = 7.0;
        testMotor2.kd = 2.0;

        testMotor3.positionSet = 0;
        testMotor3.speedSet = 0.0;
        testMotor3.kp = 7.0;
        testMotor3.kd = 2.0;

        std::cout << "Motor1: " << testMotor1.positionFdb << std::endl;
        std::cout << "Motor2: " << testMotor2.positionFdb << std::endl;
        std::cout << "Motor3: " << testMotor3.positionFdb << std::endl;

        testMotor1.Update();
        testMotor2.Update();
        testMotor3.Update();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

}
