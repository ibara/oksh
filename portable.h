/*
 * Multi-platform support.
 */

#ifndef _OKSH_PORTABLE_H_
#define _OKSH_PORTABLE_H_

/*
 * Includes
 */

#if defined(__linux__) || defined(__CYGWIN__) || defined(__midipix__)
#include <sys/file.h>
#include <sys/types.h>

#include <grp.h>
#include <stdint.h>
#include <stdlib.h>
#endif /* __linux__ || __CYGWIN__ || __midipix__ */

#include <sys/param.h>
#include <sys/time.h>
#include <stdint.h>

#ifdef __APPLE__
#include <mach/clock.h>
#include <mach/mach.h>
#endif /* __APPLE__ */

#if defined(_AIX) || defined(__sun)
#include <sys/file.h>
#endif /* _AIX || __sun */

#if defined(__HAIKU__)
#include <stdint.h>
#endif

#include <time.h>

#include "pconfig.h"

/*
 * Defines
 */

#ifndef CHILD_MAX
#define CHILD_MAX	80
#endif /* !CHILD_MAX */

#ifndef O_EXLOCK
#define O_EXLOCK	0
#endif /* !O_EXLOCK */

#ifndef _PATH_BSHELL
#define _PATH_BSHELL	"/bin/sh"
#endif /* !_PATH_BSHELL */

#ifndef _PATH_DEFPATH
#define _PATH_DEFPATH	"/usr/bin:/bin"
#endif /* !_PATH_DEFPATH */

#ifndef _PATH_STDPATH
#define _PATH_STDPATH	"/usr/bin:/bin:/usr/sbin:/sbin"
#endif /* !_PATH_STDPATH */

#ifndef _PW_NAME_LEN
#if defined(__linux__) || defined(__CYGWIN__) || defined(_AIX) || defined(__midipix__) || defined(__HAIKU__) || defined(__QNXNTO__)
#define _PW_NAME_LEN	LOGIN_NAME_MAX
#elif defined(__NetBSD__)
#define _PW_NAME_LEN	MAXLOGNAME
#elif defined(__sun)
#define _PW_NAME_LEN	LOGNAME_MAX
#elif defined(__hpux)
#define _PW_NAME_LEN	8
#else
#define _PW_NAME_LEN	MAXLOGNAME - 1
#endif /* __linux__ || __CYGWIN__ || _AIX || __NetBSD__ || __sun || __midipix__ || __HAIKU__ || __QNXNTO__ */
#endif /* !_PW_NAME_LEN */

#ifndef LOCK_EX
#define LOCK_EX	0x02
#endif /* !LOCK_EX */

#ifndef LOCK_UN
#define LOCK_UN	0x08
#endif /* !LOCK_UN */

#ifndef RLIMIT_RSS
#define	RLIMIT_RSS	5		/* resident set size */
#endif /* !RLIMIT_RSS */

#ifndef RLIMIT_MEMLOCK
#define	RLIMIT_MEMLOCK	6		/* locked-in-memory address space */
#endif /* !RLIMIT_MEMLOCK */

#ifndef RLIMIT_NPROC
#define	RLIMIT_NPROC	7		/* number of processes */
#endif /* !RLIMIT_NPROC */

/* Convert clock_gettime() to clock_get_time() on Max OS X < 10.12 */
#if defined(__APPLE__) && defined(__MACH__) && __MAC_OS_X_VERSION_MIN_REQUIRED < 101200
#define clock_gettime(x, y)						\
	clock_serv_t cclock;						\
	mach_timespec_t mts;						\
	host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock); \
	clock_get_time(cclock, &mts);					\
	mach_port_deallocate(mach_task_self(), cclock);			\
	(y)->tv_sec = mts.tv_sec;					\
	(y)->tv_nsec = mts.tv_nsec;
#endif /* __APPLE__ && __MACH__ && < 10.12 */

#ifdef _AIX
#define VWERASE VWERSE
#define VDISCARD VDISCRD
#define _PATH_DEFPATH "/usr/bin:/etc:/usr/sbin:/usr/ucb:/usr/bin/X11:/sbin"
#define WCOREFLAG 0200
#define WCOREDUMP(x) ((x) & WCOREFLAG)
#undef BAD
#endif /* _AIX */

#ifdef __HAIKU__
#define _PATH_DEFPATH ".:/boot/home/config/non-packaged/bin:/boot/home/config/bin:/boot/system/non-packaged/bin:/bin:/boot/system/apps:/boot/system/preferences"
#define WCOREFLAG 0200
#define WCOREDUMP(x) ((x) & WCOREFLAG)
#endif /* __HAIKU__ */

#ifndef HAVE_SETRESGID
#define setresgid(x, y, z)	setgid(x); setegid(y); setgid(z)
#endif /* !HAVE_SETRESGID */

#ifndef HAVE_SETRESUID
#define setresuid(x, y, z)	setuid(x); seteuid(y); setuid(z)
#endif /* !HAVE_SETRESUID */

#ifndef HAVE_SRAND_DETERMINISTIC
#define srand_deterministic(x)	srand(x)
#endif /* !HAVE_SRAND_DETERMINISTIC */

#ifndef HAVE_TIMERADD
#define timeradd(tvp, uvp, vvp)                                         \
        do {                                                            \
                (vvp)->tv_sec = (tvp)->tv_sec + (uvp)->tv_sec;          \
                (vvp)->tv_usec = (tvp)->tv_usec + (uvp)->tv_usec;       \
                if ((vvp)->tv_usec >= 1000000) {                        \
                        (vvp)->tv_sec++;                                \
                        (vvp)->tv_usec -= 1000000;                      \
                }                                                       \
        } while (0)
#endif /* !HAVE_TIMERADD */

#ifndef HAVE_TIMERCLEAR
#define timerclear(tvp) ((tvp)->tv_sec = (tvp)->tv_usec = 0)
#endif /* !HAVE_TIMERCLEAR */

#ifndef HAVE_TIMERSUB
#define timersub(tvp, uvp, vvp)                                         \
        do {                                                            \
                (vvp)->tv_sec = (tvp)->tv_sec - (uvp)->tv_sec;          \
                (vvp)->tv_usec = (tvp)->tv_usec - (uvp)->tv_usec;       \
                if ((vvp)->tv_usec < 0) {                               \
                        (vvp)->tv_sec--;                                \
                        (vvp)->tv_usec += 1000000;                      \
                }                                                       \
        } while (0)
#endif /* !HAVE_TIMERSUB */

/* struct stat compatibility */
#ifndef HAVE_ST_MTIM
#ifndef HAVE_ST_MTIMESPEC
#define st_mtim st_mtime
#define timespeccmp(tsp, usp, cmp) (tsp) cmp (usp)
#else
#define st_mtim	st_mtimespec
#endif /* !HAVE_ST_TIMESPEC */
#endif /* !HAVE_ST_MTIM */

/* Cygwin already has a sys_signame but we want to use our own */
#ifdef __CYGWIN__
#undef sys_signame
#endif /* __CYGWIN__ */

/* Android is missing _CS_PATH */
#if defined(__linux__) && defined(__ANDROID__)
#ifndef _CS_PATH
#define _CS_PATH 1
#endif
#endif

/* From OpenBSD sys/time.h */
#ifndef timespeccmp
#define timespeccmp(tsp, usp, cmp)                                      \
        (((tsp)->tv_sec == (usp)->tv_sec) ?                             \
            ((tsp)->tv_nsec cmp (usp)->tv_nsec) :                       \
            ((tsp)->tv_sec cmp (usp)->tv_sec))
#endif

#ifndef timespecsub
#define timespecsub(tsp, usp, vsp)                                      \
        do {                                                            \
                (vsp)->tv_sec = (tsp)->tv_sec - (usp)->tv_sec;          \
                (vsp)->tv_nsec = (tsp)->tv_nsec - (usp)->tv_nsec;       \
                if ((vsp)->tv_nsec < 0) {                               \
                        (vsp)->tv_sec--;                                \
                        (vsp)->tv_nsec += 1000000000L;                  \
                }                                                       \
        } while (0)
#endif

/*
 * Prototypes
 */

#ifndef HAVE_ASPRINTF
int asprintf(char **str, const char *fmt, ...);
#endif /* !HAVE_ASPRINTF */

#ifndef HAVE_CONFSTR
size_t	confstr(int, char *, size_t);
#endif /* !HAVE_CONFSTR */

#ifndef HAVE_REALLOCARRAY
void	 *reallocarray(void *, size_t, size_t);
#endif /* !HAVE_REALLOCARRAY */

#ifndef HAVE_STRAVIS
int	  stravis(char **, const char *, int);
#endif /* !HAVE_STRAVIS */

#ifndef HAVE_STRLCAT
size_t	strlcat(char *, const char *, size_t);
#endif /* !HAVE_STRLCAT */

#ifndef HAVE_STRLCPY
size_t	strlcpy(char *, const char *, size_t);
#endif /* !HAVE_STRLCPY */

#ifndef HAVE_STRTONUM
long long strtonum(const char *numstr, long long minval, long long maxval,
		   const char **errstrp);
#endif /* !HAVE_STRTONUM */

#ifndef HAVE_STRUNVIS
int	  strunvis(char *, const char *);
#endif /* !HAVE_STRUNVIS */

int	oksh_issetugid(void);

/*
 * Externs
 */

#if !defined(HAVE_SIGLIST) || !defined(HAVE_SIGNAME)
#ifdef NSIG
#undef NSIG
#endif /* NSIG */
#define NSIG 33
#ifndef HAVE_SIGLIST
extern const char *const sys_siglist[NSIG];
#endif /* !HAVE_SIGLIST */
#ifndef HAVE_SIGNAME
extern const char *const sys_signame[NSIG];
#endif /* !HAVE_SIGNAME */
#endif /* !HAVE_SIGLIST || !HAVE_SIGNAME */

/*
 * Types
 */

#ifndef HAVE_SIG_T
typedef void (*sig_t) (int);
#endif /* !HAVE_SIG_T */

#endif /* !_OKSH_PORTABLE_H_ */
