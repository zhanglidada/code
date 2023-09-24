#ifndef TIMER_H
#define TIMER_H

#include <time.h>

/// @brief 对当前时间获取的封装
/// @returns The current time.
struct timespec snap_time()
{
    struct timespec t;  // 时间规格
    clock_gettime(CLOCK_REALTIME, &t);
    return t;
}

/// @brief Calculates the time difference between two struct timespecs
/// @param t1 The first time.
/// @param t2 The second time.
/// @returns The difference between the two times.
double get_elapsed(struct timespec t1, struct timespec t2)
{
    // 计算时间差（tv_nsec为纳秒数）
    double ft1 = t1.tv_sec + ((double)t1.tv_nsec / 1000000000.0);
    double ft2 = t2.tv_sec + ((double)t2.tv_nsec / 1000000000.0);
    return ft2 - ft1;
}


#endif