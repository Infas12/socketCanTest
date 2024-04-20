#include "CanManager.hpp"
#include "DM4310.hpp"

int main()
{

    CanManager::Instance()->SetPortName("can0");
    CanManager::Instance()->Init();

    DM4310 testMotor1;
    testMotor1.Registration(0x01,0x00);
    testMotor1.Enable();
    testMotor1.controlMode = Motor::POS_MODE;

    DM4310 testMotor2;
    testMotor2.Registration(0x03,0x02);
    testMotor2.Enable();
    testMotor2.controlMode = Motor::POS_MODE;

    DM4310 testMotor3;
    testMotor3.Registration(0x05,0x04);
    testMotor3.Enable();
    testMotor3.controlMode = Motor::POS_MODE;


    while(true)
    {
        testMotor1.positionSet = 0;
        testMotor1.speedSet = 0.0;
        testMotor1.kp = 2.0;
        testMotor1.kd = 1.0;

        testMotor2.positionSet = 0;
        testMotor2.speedSet = 0.0;
        testMotor2.kp = 2.0;
        testMotor2.kd = 1.0;

        testMotor3.positionSet = 0;
        testMotor3.speedSet = 0.0;
        testMotor3.kp = 2.0;
        testMotor3.kd = 1.0;

        
        testMotor1.Update();
        testMotor2.Update();
        testMotor3.Update();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

}
