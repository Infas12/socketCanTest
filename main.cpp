#include "CanManager.hpp"
#include "DM4310.hpp"

int main()
{

    CanManager::Instance()->SetPortName("can0");
    CanManager::Instance()->Init();

    DM4310 testMotor;
    testMotor.Registration(0x01,0x00);
    testMotor.Enable();
    testMotor.controlMode = Motor::POS_MODE;


    while(true)
    {
        testMotor.positionSet = 0.0;
        testMotor.speedSet = 0.0;
        testMotor.kp = 2.0;
        testMotor.kd = 1.0;
        //std::cout << "Position: " << testMotor.positionFdb << "Vel:" << testMotor.speedFdb << std::endl;
        
        testMotor.Update();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

}
