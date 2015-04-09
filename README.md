oksh
====
ksh(1) from OpenBSD ported to FreeBSD, DragonFly BSD, and NetBSD.
Might work on other operating systems too but not tested.

Why?
----
Sometimes I have to use FreeBSD. I don't like tcsh.
ksh from OpenBSD is much better. Now FreeBSD users can use it too.
Later ported to NetBSD. Hopefully a Linux port will come soon.
Designed to be as minimally invasive as possible.

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

License
-------
Most files are public domain (see LEGAL).
A couple are BSD licensed (alloc.c and mknod.c).

Get a tarball
-------------
http://homepages.rpi.edu/~callab3/oksh-3.tar.gz
