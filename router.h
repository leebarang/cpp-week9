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
  virtual void onReceive(Packet* packet) override;
  
public:
  // 해당 오브젝트의 이름을 반환한다.
  virtual std::string name() override { return "Router";}

  virtual ~Router() override {}
};

#endif