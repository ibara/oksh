oksh
====
Portable OpenBSD `ksh(1)`.

Why?
----
Because all operating systems deserve a good shell.

Supported systems
-----------------
`oksh` is known to run on the following Operating Systems:
* OpenBSD
* FreeBSD
* DragonFly BSD
* NetBSD
* Mac OS X
* Linux (glibc and musl)
* Cygwin
* Android (via Termux)
* AIX (with major thanks to @tssva and @NattyNarwhal)
* IBM i PASE

Running on a system not listed here? Add it and send a pull request!

Believed working
----------------
We believe that `oksh` will work on the following platforms, but testing is needed.
Help is greatly appreciated and encouraged!
* HPUX
* Solaris

Supported compilers
-------------------
`oksh` is known to build with the following C compilers:
* clang (https://llvm.org/)
* gcc (https://gcc.gnu.org/)
* pcc (http://pcc.ludd.ltu.se/)
* cparser (https://pp.ipd.kit.edu/firm/)
* xlc (https://www.ibm.com/us-en/marketplace/ibm-c-and-c-plus-plus-compiler-family)

Building with a compiler not listed here? Add it and send a pull request!

Packages
--------
`oksh` is included in some package systems.
* [FreeBSD ports](https://www.freshports.org/shells/oksh/)
* [pkgsrc-wip](http://pkgsrc.se/wip/oksh)

Using a package not listed here? Add it and send a pull request!

Dependencies
------------
A C99 compiler is the easiest way to ensure that `oksh` will build correctly.
Please see the list of C compilers above for a list of known working compilers.

A `configure` script that produces a `POSIX` `Makefile` is provided to
ease building and installation and can be run by:
```
$ ./configure
$ make && sudo make install
```

In case of emergency
--------------------
If you cannot execute `make` for whatever reason, a rescue script,
`rescue.sh`, is available. This script contains nothing more than a
hand-written list of compiler invocations which will build `oksh` in the
most basic and portable way possible. This rescue shell is perfectly
usable (as it is just an unoptimized build).

License
-------
The main Korn shell files are public domain (see `LEGAL`).
Portability files are BSD or ISC licensed; see individual file headers
for details.

Get a tarball
-------------
http://devio.us/~bcallah/oksh/oksh-20180502.tar.gz
