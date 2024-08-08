#include "CanManager.hpp"

void CanMsgHandler::Registration(int id)
{
    m_Manager->HandlerMap.insert(std::make_pair(id,this));
}

void CanMsgHandler::HandleNewMsg(can_frame msg)
{
    std::cout << msg.can_id << std::endl;
}

void CanManager::Init()
{
    //setting up port and bitrate
    (void)system(("sudo ip link set " + m_PortName + " type can bitrate 1000000").c_str());
    (void)system(("sudo ifconfig " + m_PortName + " up").c_str());
    (void)system(("sudo ip -details link show " + m_PortName).c_str());

    //setup socketcan
    struct sockaddr_can addr;
    struct ifreq ifr;
    SocketFD = socket(PF_CAN, SOCK_RAW, CAN_RAW);

    strcpy(ifr.ifr_name, m_PortName.c_str());
    ioctl(SocketFD, SIOCGIFINDEX, &ifr);

    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;
    bind(SocketFD, (struct sockaddr *)&addr, sizeof(addr));

    //Start Receiving
    StartRxThread();
}

void CanManager::SendMsg(can_frame msg)
{
    int nbytes = write(SocketFD, &msg, sizeof(struct can_frame));
    if(nbytes == -1)
    {
        std::cerr << "send error" << std::endl;
        exit(1);
    }
}

void CanManager::StartRxThread()
{
    m_IsRunning = true;
    auto lambda = [](void* arg) -> void* {
        CanManager* self = static_cast<CanManager*>(arg);
        self->RxThread();
        return nullptr;
    };
    pthread_create(&RxThreadID, nullptr, lambda, this);

}

void CanManager::EndRxThread()
{
    m_IsRunning = false;
}

void CanManager::RxThread()
{

    while(this->IsRunning())
    {
        
        //TODO: Use `select()` instead, non-block reading required here.
        while(TxRequestFlag){;}
        
        //Read Frame
        struct can_frame frame;
        SocketMtx.lock();
        int nbytes = read(SocketFD, &frame, sizeof(struct can_frame));
        SocketMtx.unlock();
        
        //Distribute Msgs
        if (nbytes < 0) {
            std::cout << "read error" << std::endl;
            exit(1);
		}else{
            //Written like shit; Gonna Fix this
            auto iter = HandlerMap.find(frame.can_id);
            if(iter == HandlerMap.end()) //Handler not found
            {
                std::cerr << "Handler for Can ID " << frame.can_id  << " does not exist" << std::endl;
                exit(1);
            }

            ((CanMsgHandler *)(iter->second))->HandleNewMsg(frame);
        
        }
        
        //read loop frequency
        std::this_thread::sleep_for(std::chrono::microseconds(10));
    }

}