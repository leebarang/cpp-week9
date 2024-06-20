#ifndef ROUTER_H
#define ROUTER_H

#include "node.h"
#include <vector>
#include <iostream>

struct RoutingEntry {
public:
  Address destination;
  Link *nextLink;
};

class Router : public Node {
protected:
  std::vector<RoutingEntry> routingTable_;

  // 패킷을 받아 재전송한다.
  void onReceive(Packet* packet) override;
  
public:
  ~Router() override {}
};

#endif