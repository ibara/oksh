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
* HardenedBSD
* SoloBSD (as the default shell)
* Mac OS X
* Linux (glibc and musl)
* Cygwin
* Android (via Termux)
* AIX (with major thanks to @tssva and @NattyNarwhal)
* IBM i PASE
* Solaris
* Illumos

Running on a system not listed here? Add it and send a pull request!

Believed working
----------------
We believe that `oksh` will work on the following platforms, but testing is needed.
Help is greatly appreciated and encouraged!
* HPUX
* Irix

Supported compilers
-------------------
`oksh` is known to build with the following C compilers:
* clang (https://llvm.org/)
* gcc (https://gcc.gnu.org/)
* pcc (http://pcc.ludd.ltu.se/)
* cparser (https://pp.ipd.kit.edu/firm/)
* xlc (https://www.ibm.com/us-en/marketplace/ibm-c-and-c-plus-plus-compiler-family)
* Sun Studio compiler (https://www.oracle.com/technetwork/server-storage/developerstudio/overview/index.html)
* lacc (https://github.com/larmel/lacc)

Building with a compiler not listed here? Add it and send a pull request!

Packages
--------
`oksh` is included in some package systems.
* [FreeBSD ports](https://www.freshports.org/shells/oksh/)
* [pkgsrc](http://pkgsrc.se/shells/oksh)
* [Ravenports](http://www.ravenports.com/catalog/bucket_9E/ksh/standard/)
* [Ubuntu PPA](https://launchpad.net/~dysfunctionalprogramming/+archive/ubuntu/oksh)
* [MacPorts](https://www.macports.org/ports.php?by=name&substr=oksh)
* [Homebrew](https://github.com/sirn/homebrew-oksh/)

Using a package not listed here? Add it and send a pull request!

Dependencies
------------
A C99 compiler is the easiest way to ensure that `oksh` will build correctly.
Please see the list of C compilers above for a list of known working compilers.

Though not required, the `ncurses` library will be used for screen clearing
routines if the library is found during the `configure` stage. This can be
turned off by the user by passing the `--disable-curses` flag to `configure`.

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
See releases tab. The latest release is oksh-6.6, which matches the ksh(1)
from OpenBSD 6.6.
