#ifndef SERVICE_H
#define SERVICE_H

#include "node.h"
#include "host.h"

class Host;

class Service {
  friend class ServiceInstaller;

protected:
  // 서비스가 설치된 호스트
  Host *host_;

  // 서비스가 사용하는 포트
  short port_;

  Service(Host *host, int port) : host_(host), port_(port) {}

public:
  virtual void receivePacket(Packet* packet) = 0;
  short port() {return port_;}
};

#endif