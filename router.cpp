#include "router.h"

// 패킷을 받아 재전송한다.
void Router::onReceive(Packet* packet) {
  bool existDestination = false;
  for(RoutingEntry r : routingTable_) {
    if(r.destination == packet->destAddress()) {
      existDestination = true;
      //std::cout << "Router #" << id() << ": forwarding packet (from: " << packet->srcAddress().toString() << ", to: " << packet->destAddress().toString() << ", " << packet->dataSize() << " bytes)" << std::endl;
      std::string message = "forwarding packet: " + packet->toString() + " to " + r.nextLink->toString();
      log(message);
      r.nextLink->sendPacket(this, packet);
      break;
    }
  }
  if (existDestination == false) {
    //std::cout << "Router #" << id() << ":no route for packet (from: " << packet->srcAddress().toString() << ", to: " << packet->destAddress().toString() << ", " << packet->dataSize() << " bytes)" << std::endl;
    log("no route for packet");
  }
}