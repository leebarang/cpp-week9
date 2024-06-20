#ifndef MESSAGE_SERVICE_H
#define MESSAGE_SERVICE_H

#include "address.h"
#include "host.h"
#include "service.h"
#include <iostream>

// send 함수를 호출하여 메시지를 전송할 수 있는 서비스
class MessageService : public Service {
  friend class MessageServiceInstaller;

private:
  // 목적지 주소
  Address destAddress_;
  // 목적지 포트
  short destPort_;
  MessageService(Host *host, short port, Address destAddress, short destPort)
      : Service(host, port), destAddress_(destAddress), destPort_(destPort) {}

public:

  virtual ~MessageService() override = default;

  // 해당 오브젝트의 이름을 반환한다.
  virtual std::string name() override { return "MessageService";}

  // 메시지 패킷를 전송한다
  void send(std::string message);

  // 패킷을 받고, 서비스를 실행한다.
  virtual void receivePacket(Packet* packet) override;

};

#endif