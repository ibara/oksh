/*
 * NetBSD support.
 */

/* Defines */
#define setresgid(x, x, x)	setgid(x); setegid(x)
#define setresuid(x, x, x)	setuid(x); seteuid(x)
#define srand_deterministic(x)	srand(x)
