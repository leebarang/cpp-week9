#include "echo_service.h"

void EchoService::receivePacket(Packet* packet) {
    //std::cout << "EchoService: received \""<< packet->dataString() <<"\" from "<< packet->srcAddress().toString() << ":" << packet->srcPort() << ", send reply with same data" << std::endl;
    std::string message = "received \"" + packet->dataString() + "\" from " + packet->srcAddress().toString() + ":" + std::to_string(packet->srcPort()) + ", send reply with same data";
    log(message);
    Packet *newPacket = new Packet(packet->destAddress(),packet->srcAddress(),packet->destPort(),packet->srcPort(),packet->data());
    delete packet;
    host_->send(newPacket);
}