#include "service_installer.h"
#include <iostream>

// 서비스를 설치하는 역할
void ServiceInstaller::install(Host *host, Service *service) {
  host->services_.push_back(service);
}