#include "auto_router.h"

/*
// 전체 노드와 링크 정보를 통해
// 모든 호스트로 전달될 수 있는 라우팅 테이블을 구성한다
void AutoRouter::calculate(const std::vector<Node *> &nodes,
                           const std::vector<Link *> &links) {

// node a, node b, node c, node d
// a <- link a (1.0) -> b
// b <- link b (2.0) -> c

    double matrix[10000][10000];

    for(int i = 0; i < (int)nodes.size(); i++) {
      for(int j = 0; j < (int)nodes.size(); j++) {
        Node* a = nodes[i];
        Node* b = nodes[j];

        matrix[i][j] = 99999999;
        for(Link * l : links) {
          if(l->a() == a && l->b() == b) {
            matrix[i][j] = l->delay();
          }
        }
      }
    }

    // 다익스트라를 돌리면서 호스트에 대한 최소경로로 갈수잇는 다음 홉을 기록
    for(Node* n : nodes) {
      Host* host = dynamic_cast<Host*>(n);
      if(host == nullptr) {
        continue;
      }
    }
}
*/