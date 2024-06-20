#ifndef NODE_H
#define NODE_H

#include "link.h"
#include "packet.h"
#include "object.h"
#include <vector>

class Node : public Object {

private:
  friend class LinkInstaller;
  int id_;
  static int nextId_;

protected:
  // 이 노드와 연결되어있는 링크 목록
  std::vector<Link*> myLink_;

public:
  Node() : id_(nextId_++) {}
  virtual ~Node() {}
  int id() const { return id_; }
  virtual void onReceive(Packet *packet) = 0;
};

#endif