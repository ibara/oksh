oksh
====
Portable OpenBSD ksh(1).

Why?
----
Because other operating systems deserve a good shell to use.
Originally a port of ksh to FreeBSD. The default FreeBSD shell is tcsh.
No one likes tcsh. DragonFly BSD should also just work.
Later NetBSD support was added. NetBSD also has a ksh variant so it might be less useful there.
Linux support, tested on Slackware, exists.
Other operating system support welcome and appreciated.

Changes
-------
* Added #include &lt;time.h&gt; in lex.c
* Added #include &lt;sys/param.h&gt; and changed _PW_NAME_LEN to MAXLOGNAME in main.c
* Added #define srand_deterministic block in var.c
* Added charclass.h from OpenBSD libc
* NetBSD does not have setresgid and setresuid so provide compatability calls in misc.c
* Added LDFLAGS+=-static line in Makefile
* Renamed README to README.pdksh
* Added README.md (this file)

Linux-specific changes
----------------------
Adding Linux support was invasive.
* Added OpenBSD vesions of reallocarray.c, setmode.c, signame.c, strlcat.c, and strlcpy.c, all under #ifdef __linux__
* Added defines, externs, and includes where needed, under #ifdef __linux__
* Added OpenBSD <sys/queue.h> header as "queue.h" under #ifdef __linux__ and force Linux to use it

License
-------
Most files are public domain (see LEGAL).
The rest are BSD or ISC licensed.

Get a tarball
-------------
http://homepages.rpi.edu/~callab3/oksh-4.tar.gz
