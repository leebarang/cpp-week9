#include "link.h"
#include "node.h"
#include <iostream>

void Link::sendPacket(Node* sender, Packet* packet){
    Node* receiver = other(sender);
    //std::cout << "Link: forwarding packet from node #" << sender->id() << ", to node #" << receiver->id() << std::endl;
    log("forwarding packet");
    receiver->onReceive(packet);
}