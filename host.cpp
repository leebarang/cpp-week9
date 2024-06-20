#include "host.h"
#include <iostream>

// 소멸자 : 설치된 모든 서비스 객체들을 삭제
Host::~Host() {
    for (auto service : services_) {
        delete service;
    }
    // 벡터를 비워줌으로써 더 이상 필요하지 않은 포인터들을 관리
    services_.clear();
}

// 호스트와 설치된 서비스를 전부 초기화한다.
void Host::initialize() {}

// 랜덤한 링크를 하나 반환한다. 
Link* Host::getRandomLink() {
    srand(unsigned(time(NULL)));
    int randomNumber = rand()%int(myLink_.size());
    return myLink_[randomNumber];
}

// 고유한 포트를 각 서비스에 부여하기 위해, 사용가능한 포트를 반환한다.
short Host::assignSrcPort() {
    short srcPort = 1000;
    bool unique = false;
    while (!unique) {
        unique = true;
        for (Service* s : services_) {
            if (s->port() == srcPort) {
                srcPort++;
                unique = false;
                break;
            }
        }
    }
    return srcPort;
}

// 패킷을 전달 받는다.
void Host::onReceive(Packet* packet) {
    Service *service = nullptr;
    for(Service *s: services_) {
        if(s->port() == packet->destPort()) {
            service = s;
            //std::cout << "Host #" << id() << ": received packet, destination port: " << service->port() << std::endl;
            std::string message = "received packet: " + packet->toString() + ", forwarding to " + service->toString();
            log(message);
            break;
        }
    }

    if(service != nullptr) {
        service->receivePacket(packet);
    }

    else {
        //std::cout << "Host #" << id() << ": no service for packet (from: "<< packet->srcAddress().toString() << ", to: " << packet->destAddress().toString() << ", " << packet->dataSize() << " bytes)" << std::endl;
        std::string message = "no service for packet: " + packet->toString();
        log(message);
    }
}

// 링크를 랜덤으로 하나 선택하여 패킷을 전송한다.
void Host::send(Packet *packet) {
    //std::cout << "Host #" << id() << ": sending packet (from: " << packet->srcAddress().toString() << ", to: " << packet->destAddress().toString() << ", " << packet->dataSize() << " bytes)" << std::endl;
    std::string message = "sending packet: " + packet->toString();
    log(message);
    getRandomLink()->sendPacket(this, packet);
}

