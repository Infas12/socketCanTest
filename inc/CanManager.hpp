#ifndef CAN_MANAGER_HPP
#define CAN_MANAGER_HPP

#include <net/if.h>
#include <sys/ioctl.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <iostream>
#include <signal.h>
#include <cstring>
#include <string>
#include <chrono>
#include <unistd.h>
#include <thread>
#include <mutex>
#include <pthread.h>
#include <map>

//forward declaration
class CanMsgHandler; 

class CanManager
{

private:

    std::string m_PortName;
    bool m_IsRunning;

public:
    CanManager(){};
    ~CanManager(){};
    
    int SocketFD;
    std::mutex SocketMtx;
    bool TxRequestFlag;
    pthread_t RxThreadID{};
    std::map<int,CanMsgHandler*> HandlerMap;
    
    void SetPortName(const std::string PortName){m_PortName = PortName;};
    void Init();
    bool IsRunning(){return m_IsRunning;}
    
    //Transmit
    void SendMsg(can_frame msg);

    //Receive, with a single thread.
    void StartRxThread();
    void EndRxThread();
    void RxThread();

};
//written like sh*t
class CanMsgHandler
{
    private:
        int m_id;
        CanManager* m_Manager;
    public:
        CanMsgHandler(CanManager* manager_) : m_Manager(manager_) {};
        void Registration(int id); 
        virtual void HandleNewMsg(can_frame msg) = 0 ;
};




#endif