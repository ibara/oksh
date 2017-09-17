/*
 * Linux support.
 */

/* Includes */
#include <sys/file.h>
#include <sys/param.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

/* Defines */
#define _PW_NAME_LEN	LOGIN_NAME_MAX
#define O_EXLOCK	0
#define srand_deterministic(x)	srand(x)
#define sys_signame	esys_signame

#ifndef __CYGWIN__
#define CHILD_MAX	80
#endif

#ifdef __CYGWIN__
#define setresgid(x, y, z)	setgid(x); setegid(x)
#define setresuid(x, y, z)	setuid(x); seteuid(x)
#endif

/* From OpenBSD sys/time.h */
#define	timespeccmp(tsp, usp, cmp)					\
	(((tsp)->tv_sec == (usp)->tv_sec) ?				\
	    ((tsp)->tv_nsec cmp (usp)->tv_nsec) :			\
	    ((tsp)->tv_sec cmp (usp)->tv_sec))

#define	timespecsub(tsp, usp, vsp)					\
	do {								\
		(vsp)->tv_sec = (tsp)->tv_sec - (usp)->tv_sec;		\
		(vsp)->tv_nsec = (tsp)->tv_nsec - (usp)->tv_nsec;	\
		if ((vsp)->tv_nsec < 0) {				\
			(vsp)->tv_sec--;				\
			(vsp)->tv_nsec += 1000000000L;			\
		}							\
	} while (0)

/* Resource limits for Cygwin, from OpenBSD sys/resource.h */
#ifdef __CYGWIN__
#define	RLIMIT_RSS	5		/* resident set size */
#define	RLIMIT_MEMLOCK	6		/* locked-in-memory address space */
#define	RLIMIT_NPROC	7		/* number of processes */
#endif

/* Functions */
mode_t	getmode(const void *, mode_t);
void   *reallocarray(void *, size_t, size_t);
void   *setmode(const char *);
size_t	strlcat(char *, const char *, size_t);
size_t	strlcpy(char *, const char *, size_t);
long long strtonum(const char *numstr, long long minval, long long maxval,
		   const char **errstrp);

/* Externs */
extern const char *const sys_signame[NSIG];
