
/* Workarounds for missing clock_gettime() on MacOS prior to v10.12 */
#if defined(__APPLE__) && defined(__MACH__) && __MAC_OS_X_VERSION_MIN_REQUIRED < 101200
#include <time.h>
/* not compiling with CC="xcrun --sdk macosx cc" nor SDKROOT="..." */
#if !defined(CLOCK_REALTIME) && !defined(CLOCK_MONOTONIC)
#define _OKSH_PORTABLE_MACOS_CLOCK_GETTIME_
#include <errno.h>
#include <mach/clock.h>
#include <mach/mach_time.h>
#include <sys/time.h>
#define CLOCK_REALTIME 0
#define CLOCK_MONOTONIC 6
int clock_gettime(clock_id_t clk_id, struct timespec *ts);
#endif
#endif /* __APPLE__ */

