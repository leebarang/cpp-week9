#include "message_service.h"

// 메시지 패킷를 전송한다
void MessageService::send(std::string message) {
    Packet *newPacket = new Packet(host_->address(),destAddress_,port_,destPort_,message);
    host_->send(newPacket);
}

// 패킷을 받고, 서비스를 실행한다.
void MessageService::receivePacket(Packet* packet) {
    //std::cout << "MessageService: received \""<< packet->dataString() <<"\" from "<< packet->srcAddress().toString() << ":" << packet->srcPort() << std::endl;
    log("received");
}