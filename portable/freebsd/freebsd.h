/*
 * FreeBSD and DragonFly BSD support.
 */

/* Includes */
#include <sys/param.h>
#include <time.h>

/* Defines */
#define _PW_NAME_LEN	MAXLOGNAME - 1
#define srand_deterministic(x)	srand(x)
