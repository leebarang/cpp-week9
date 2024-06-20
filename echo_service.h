#ifndef ECHO_SERVICE_H
#define ECHO_SERVICE_H

#include "host.h"
#include "service.h"
#include <iostream>
#include <string>

// 수신한 패킷을 전송자에게 다시 전송하는 서비스
class EchoService : public Service {
  friend class EchoServiceInstaller;

private:
  EchoService(Host *host, short port) : Service(host, port) {}

public:
  virtual ~EchoService() override = default;
  // 해당 오브젝트의 이름을 반환한다.
  virtual std::string name() override { return "EchoService";}
  virtual void receivePacket(Packet* packet) override;
};

#endif