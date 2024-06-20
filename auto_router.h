#ifndef AUTO_ROUTER_H
#define AUTO_ROUTER_H

#include "host.h"
#include "link.h"
#include "router.h"
#include "service.h"
#include <algorithm>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <vector>

class AutoRouter : public Router {
public:
  void calculate(const std::vector<Node *> &nodes,
                 const std::vector<Link *> &links);
};

#endif