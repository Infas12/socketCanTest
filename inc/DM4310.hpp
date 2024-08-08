#ifndef DM4310_HPP
#define DM4310_HPP

#include "CanManager.hpp"
#include "Motor.hpp"

class DM4310 : public CanMsgHandler, public Motor
{
private:
        
        //Can manager
        CanManager* m_Manager;

        //attribute
        uint32_t cmdId;
        uint32_t fdbId;

        const static float P_MIN;
        const static float P_MAX;
        const static float V_MIN;
        const static float V_MAX;
        const static float T_MIN;
        const static float T_MAX;
        const static float KP_MIN;
        const static float KP_MAX;
        const static float KD_MIN;
        const static float KD_MAX;

public:

        // additional attribute
        float tauff;
        float torqueFdb;
        float kp;
        float kd;
        

        MotorControlModeType controlMode = Motor::RELAX_MODE;

        DM4310(CanManager* manager_) : CanMsgHandler(manager_) , Motor(), cmdId(0), fdbId(0), kp(KP_MIN), kd(KD_MIN), tauff(0.0), m_Manager(manager_)
        {};

        void Registration(int cmdId, int fdbId){
            this->CanMsgHandler::Registration(fdbId);
            this->cmdId = cmdId;
            this->fdbId = fdbId;
        };
        
        virtual void HandleNewMsg(can_frame msg);
        virtual void Update();
        void Enable();
        void Disable();
        void SetZero();

};


#endif // DM4310_HPP