#ifndef LINK_H
#define LINK_H

#include "packet.h"
#include "object.h"
#include <cstdlib>

class Node;

class Link : public Object {
  friend class LinkInstaller;

private:
  Link(Node *nodeA, Node *nodeB) : nodeA_(nodeA), nodeB_(nodeB) {}

  Node *nodeA_;
  Node *nodeB_;
  
  double delay_ = 0.0;
  
  // 매개변수로 주어진 노드가 아닌 반대편 노드를 구한다.
  Node *other(const Node *node) const {
    return node == nodeA_ ? nodeB_ : nodeA_;
  }

public:
  // 해당 오브젝트의 이름을 반환한다.
  virtual std::string name() override { return "Link";}

  double delay() const { return delay_; }
  Node *a() const { return nodeA_; }
  Node *b() const { return nodeB_; }
  void sendPacket(Node* sender, Packet* packet);
};

#endif