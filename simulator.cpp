#include "simulator.h"

double Simulator::time_ = 0.0;
std::priority_queue<Schedule> Simulator::schedules_;

// 스케줄 큐에 스케줄을 추가한다.
void Simulator::schedule(double time, std::function<void()> function) {
    schedules_.push(Schedule (time, function));
}

// 모든 스케줄을 실행한다.
void Simulator::run() {
    while(!schedules_.empty()) {
      Schedule schedule = schedules_.top();
      schedules_.pop();

      time_ = schedule.time();
      schedule.call();
    }
}