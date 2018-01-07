oksh
====
Portable OpenBSD `ksh(1)`.

Why?
----
Because other operating systems deserve a good shell to use.
Originally a port of `ksh` to FreeBSD. The default FreeBSD shell is `tcsh`.
DragonFly BSD should also just work.
Later, NetBSD support was added. NetBSD also has a `ksh` variant so it might
be less useful there.
Linux support, tested on Slackware and Ubuntu, exists. This includes Cygwin.
Darwin (Mac OS X) supported as well.
Other operating system support welcome and appreciated.

Dependencies
------------
A C compiler that understands the `long long` type. A C99 compiler is the
easiest way to ensure that oksh will build correctly.

A `configure` script that produces a POSIX `Makefile` is available to ease
building and installation and can be run by:
```
$ ./configure
$ make && sudo make install
```

In case of emergency
--------------------
If you cannot execute make for whatever reason, a rescue script,
`rescue.sh`, is available. This script contains nothing more than a
hand-written list of compiler invocations which will build `oksh` in the
most basic and portable way possible. This rescue shell is perfectly
usable (as it is just an unoptimized build).

License
-------
Most files are public domain (see LEGAL).
The rest are BSD or ISC licensed.

Get a tarball
-------------
http://devio.us/~bcallah/oksh/oksh-20180107.tar.gz
