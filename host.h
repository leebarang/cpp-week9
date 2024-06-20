#ifndef HOST_H
#define HOST_H

#include "address.h"
#include "packet.h"
#include "service.h"
#include <ctime>
#include <vector>

class Service;

// 서비스와 (패킷 내부)포트를 가지고 있고, 패킷을 노드를 통해 전송하는 역할
class Host : public Node {
  friend class ServiceInstaller;

private:
  // 호스트의 주소
  Address address_;

  // 설치된 서비스 목록
  std::vector<Service *> services_;

public:
  Address address() { return address_; }
  Host(Address address) : address_(address) {}
  virtual ~Host() override;

  // 해당 오브젝트의 이름을 반환한다.
  virtual std::string name() override { return "Host";}

  // 호스트와 설치된 서비스를 전부 초기화한다.
  void initialize();

  // 랜덤한 링크를 하나 반환한다.
  Link* getRandomLink();

  // 고유한 포트를 각 서비스에 부여하기 위해, 사용가능한 포트를 반환한다.
  short assignSrcPort();

  // 패킷을 전달 받는다.
  virtual void onReceive(Packet* packet) override;

  // 링크를 랜덤으로 하나 선택하여 패킷을 전송한다.
  void send(Packet *packet);
};

#endif