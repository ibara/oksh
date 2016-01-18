/*
 * Mac OS X support.
 */

 /* Includes */
#include <sys/param.h>

/* Defines */
#define _PW_NAME_LEN	MAXLOGNAME - 1
#define srand_deterministic(x)	srand(x)

/* Not really sure on these two, but it seems to work ok. */
#define setresgid(x, y, z)	setgid(x); setegid(y); setgid(z)
#define setresuid(x, y, z)	setuid(x); seteuid(y); setuid(z)
