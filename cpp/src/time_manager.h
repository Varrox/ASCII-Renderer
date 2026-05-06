#pragma once

struct Time {
    static double get_time();
    static void update_time();
    static inline double time = 0.0f;
};