#include "CanManager.hpp"
#include "DM4310.hpp"

int main()
{

    CanManager testCan;
    testCan.SetPortName("can0");
    testCan.Init();

    // DM4310 testMotor1(&testCan);
    // testMotor1.Registration(0x07,0x06);
    // testMotor1.Enable();
    // testMotor1.controlMode = Motor::MIT_MODE;
    // // testMotor1.SetZero();

    // DM4310 testMotor2(&testCan);
    // testMotor2.Registration(0x09,0x08);
    // testMotor2.Enable();
    // testMotor2.controlMode = Motor::MIT_MODE;
    // // testMotor2.SetZero();

    // DM4310 testMotor3(&testCan);
    // testMotor3.Registration(0x0B,0x0A);
    // testMotor3.Enable();
    // testMotor3.controlMode = Motor::MIT_MODE;
    // testMotor3.SetZero();


    CanManager testCan2;
    testCan2.SetPortName("can1");
    testCan2.Init();
    DM4310 testMotor4(&testCan2);
    testMotor4.Registration(0x00,0x01);
    testMotor4.Enable();
    testMotor4.controlMode = Motor::MIT_MODE;
    // testMotor4.SetZero();

    DM4310 testMotor5(&testCan2);
    testMotor5.Registration(0x02,0x03);
    testMotor5.Enable();
    testMotor5.controlMode = Motor::MIT_MODE;
    // testMotor5.SetZero();

    DM4310 testMotor6(&testCan2);
    testMotor6.Registration(0x04,0x05);
    testMotor6.Enable();
    testMotor6.controlMode = Motor::MIT_MODE;
    // testMotor6.SetZero();




    while(true)
    {
        // testMotor1.positionSet = 0;
        // testMotor1.speedSet = 0.0;
        // testMotor1.kp = 7.0;
        // testMotor1.kd = 2.0;

        // testMotor2.positionSet = 0;
        // testMotor2.speedSet = 0.0;
        // testMotor2.kp = 7.0;
        // testMotor2.kd = 2.0;

        // testMotor3.positionSet = 0;
        // testMotor3.speedSet = 0.0;
        // testMotor3.kp = 7.0;
        // testMotor3.kd = 2.0;

        // std::cout << "Motor1: " << testMotor1.positionFdb << std::endl;
        // std::cout << "Motor2: " << testMotor2.positionFdb << std::endl;
        // std::cout << "Motor3: " << testMotor3.positionFdb << std::endl;

        // testMotor1.Update();
        // testMotor2.Update();
        // testMotor3.Update();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

}
