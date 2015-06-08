/*
 * Linux support.
 */

/* Includes */
#include <sys/file.h>
#include <sys/param.h>
#include <time.h>

/* Defines */
#define _PW_NAME_LEN	LOGIN_NAME_MAX
#define CHILD_MAX	80
#define srand_deterministic(x)	srand(x)

/* Functions */
const char *const sys_signame;
mode_t	getmode(const void *, mode_t);
void   *setmode(const char *);
size_t	strlcat(char *, const char *, size_t);
size_t	strlcpy(char *, const char *, size_t);
