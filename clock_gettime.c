#include "clock_gettime.h"

#ifdef _OKSH_PORTABLE_MACOS_CLOCK_GETTIME_
int clock_gettime(clock_id_t clk_id, struct timespec *ts)
{
        int ret = -1;

        if (ts == NULL) {
                errno = EFAULT;
        } else if (clk_id == CLOCK_REALTIME) {
                /* according to clock_gettime(3) */
                struct timeval tv;
                if (gettimeofday(&tv, NULL) == 0) {
                        ts->tv_sec = tv.tv_sec;
                        ts->tv_nsec = tv.tv_usec * 1000;
                        ret = 0;
                } /* else: unknown errno */
        } else if (clk_id == CLOCK_MONOTONIC) {
                static mach_timebase_info_data_t tb = {0, 0};
                if (tb.denom != 0 || mach_timebase_info(&tb) == KERN_SUCCESS) {
                        uint64_t t = mach_absolute_time();
                        /* t = t * tb.numer / tb.denom */
                        if (tb.numer != tb.denom) {
                                uint32_t n = tb.numer, d = tb.denom;
                                uint64_t hi = (t >> 32), lo = (t & 0xFFFFFFFF);
                                t = hi * n;
                                t = (t/d << 32) + ((t%d << 32) + lo*n)/d;
                        }
                        ts->tv_sec = t / 1000000000;
                        ts->tv_nsec = t % 1000000000;
                        ret = 0;
                } else {
                        tb.denom = 0;
                        /* unknown errno */
                }
        } else {
                errno = EINVAL;
        }
        return ret;
}
#endif /* _OKSH_PORTABLE_MACOS_CLOCK_GETTIME_ */

