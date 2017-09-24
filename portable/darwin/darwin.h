/*
 * Mac OS X support.
 */

 /* Includes */
#include <sys/param.h>
#include <sys/time.h>
#include <mach/clock.h>
#include <mach/mach.h>

/* Defines */
#define _PW_NAME_LEN	MAXLOGNAME - 1
#define srand_deterministic(x)	srand(x)

/* Not really sure on these two, but it seems to work ok. */
#define setresgid(x, y, z)	setgid(x); setegid(y); setgid(z)
#define setresuid(x, y, z)	setuid(x); seteuid(y); setuid(z)

/* Convert clock_gettime() to clock_get_time() */
#define clock_gettime(x, y)						\
	clock_serv_t cclock;						\
	mach_timespec_t mts;						\
	host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock); \
	clock_get_time(cclock, &mts);					\
	mach_port_deallocate(mach_task_self(), cclock);			\
	(y)->tv_sec = mts.tv_sec;					\
	(y)->tv_nsec = mts.tv_nsec;

/* struct stat compatibility */
#define st_mtim	st_mtimespec

/* From OpenBSD sys/time.h */
#define timespeccmp(tsp, usp, cmp)                                      \
        (((tsp)->tv_sec == (usp)->tv_sec) ?                             \
            ((tsp)->tv_nsec cmp (usp)->tv_nsec) :                       \
            ((tsp)->tv_sec cmp (usp)->tv_sec))

#define timespecsub(tsp, usp, vsp)                                      \
        do {                                                            \
                (vsp)->tv_sec = (tsp)->tv_sec - (usp)->tv_sec;          \
                (vsp)->tv_nsec = (tsp)->tv_nsec - (usp)->tv_nsec;       \
                if ((vsp)->tv_nsec < 0) {                               \
                        (vsp)->tv_sec--;                                \
                        (vsp)->tv_nsec += 1000000000L;                  \
                }                                                       \
        } while (0)

/* Functions */
void	 *reallocarray(void *, size_t, size_t);
int	  stravis(char **, const char *, int);
long long strtonum(const char *numstr, long long minval, long long maxval,
		   const char **errstrp);
