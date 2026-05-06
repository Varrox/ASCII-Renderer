#include "time_manager.h"

#include <chrono>

const auto START_TIME = std::chrono::steady_clock::now();

double Time::get_time() {
    update_time();
    return time;
}

void Time::update_time() {
    auto now = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed = now - START_TIME;
    time = elapsed.count();
}