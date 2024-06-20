#ifndef SIMULATOR_H
#define SIMULATOR_H

#define RANDOM_SEED 369369

#include <cstdlib>
#include <functional>
#include <queue>
#include <vector>

class Simulator;

class Schedule {
private:
  double time_; // 이벤트 발생 시간
  std::function<void()> function_; // 동작

public:
  double time() const { return time_; }
  void call() const { function_(); }

  Schedule(double time, std::function<void()> function)
      : time_(time), function_(function) {}

  // 비교 연산에 필요한 조건을 구현한다.
  bool operator<(const Schedule& rhs) const {
    return time_ > rhs.time_; // time_을 기준으로 작다고 판단하는 비교 연산
  }
};

class Simulator {
private:
  static double time_;
  // 우선순위 큐
  static std::priority_queue<Schedule> schedules_;

public:
  static double now() { return time_; }

  static void prepare() { srand(RANDOM_SEED); }

  // 스케줄 큐에 스케줄을 추가한다.
  static void schedule(double time, std::function<void()> function);

  // 모든 스케줄을 실행한다.
  static void run();
};

#endif