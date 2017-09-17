/*
 * NetBSD support.
 */

/* Defines */
#define setresgid(x, y, z)	setgid(x); setegid(x)
#define setresuid(x, y, z)	setuid(x); seteuid(x)
#define srand_deterministic(x)	srand(x)
