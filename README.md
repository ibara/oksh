oksh
====
Portable OpenBSD `ksh(1)`. Not an official OpenBSD project.

Why?
----
Because all operating systems deserve a good shell.

Unlike other ports of OpenBSD ksh, this port is entirely self-contained and aims to be maximally portable across operating systems and C compilers.
We are always looking for new combinations to add support for.

Supported systems
-----------------
`oksh` is known to run on the following Operating Systems:
* OpenBSD
* FreeBSD
* DragonFly BSD
* NetBSD
* HardenedBSD
* SoloBSD (as the default shell)
* Mac OS X (port originally by @geoff-nixon)
* Linux (glibc and musl)
* Cygwin
* Android (via Termux)
* AIX (with major thanks to @tssva and @NattyNarwhal)
* IBM i PASE
* Solaris
* Illumos
* midipix
* WSL
* WSL2
* Unixware 7
* Haiku
* HP-UX (gcc only)
* SerenityOS
* MSYS2

Running on a system not listed here? Add it and send a pull request!

Believed working
----------------
We believe that `oksh` will work on the following platforms, but testing is needed.
Help is greatly appreciated and encouraged!
* Irix

Supported compilers
-------------------
`oksh` is known to build with the following C compilers:
* [clang](https://llvm.org/)
* [gcc](https://gcc.gnu.org/)
* [pcc](http://pcc.ludd.ltu.se/)
* [cparser](https://pp.ipd.kit.edu/firm/)
* [xlc](https://www.ibm.com/us-en/marketplace/ibm-c-and-c-plus-plus-compiler-family)
* [Sun Studio compiler](https://www.oracle.com/technetwork/server-storage/developerstudio/overview/index.html)
* [lacc](https://github.com/larmel/lacc)
* Optimizing C Compilation System  (CCS) 4.2  03/27/14 (uw714mp5.bl4s)
* [Tiny C Compiler](https://bellard.org/tcc/)
* [CompCert](https://compcert.org/)
* [Nils Weller's C compiler](http://nwcc.sourceforge.net/)
* [cproc](https://sr.ht/~mcf/cproc/) (Currently requires a small tweak to ignore a volatile store error)
* [vbcc](http://www.compilers.de/vbcc.html) (Only tested on OpenBSD/i386)
* [chibicc](https://github.com/rui314/chibicc)
* [kefir](https://git.sr.ht/~jprotopopov/kefir)

Building with a compiler not listed here? Add it and send a pull request!

Packages
--------
`oksh` is included in some package systems.

[![Packaging status](https://repology.org/badge/vertical-allrepos/oksh.svg)](https://repology.org/project/oksh/versions)

In addition, there are some unofficial packages:
* [Ubuntu PPA](https://launchpad.net/~dysfunctionalprogramming/+archive/ubuntu/oksh)
* [Debian](https://software.opensuse.org//download.html?project=home%3AHead_on_a_Stick%3Aoksh&package=oksh)

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

Out-of-tree builds
------------------
The `configure` script will detect out-of-tree builds if you prefer to
build out-of-tree. In order for this to work, the `VPATH` make extension
is used. While not POSIX, `VPATH` is known to work with BSD make and GNU
make. In-tree builds create a fully POSIX `Makefile`.

Cross compiling
---------------
Cross compiling can be achieved by running `configure` as follows:
```
CC=/path/to/cross/cc CFLAGS="any needed cflags" LDFLAGS="any needed ldflags" ./configure --no-thanks
```

This will skip all `configure` checks and write out a generic `Makefile`
and `pconfig.h` with nearly no options turned on. If using a cross gcc
or clang, this very well may just work (with all compat compiled in).
You can edit these files to reflect your system before running `make`.

All environment variables and configure flags are respected when using
`--no-thanks`. Further specifying `--no-link` after `--no-thanks` will
only compile the source files into object files, to be transfered onto
the target machine and linked there.

The `--no-thanks` flag can also be used to compile a native `oksh` with
all the compatibility functions compiled in, rather than relying on the
system's version of those functions.

Submitting patches
------------------
Patches that add new platforms and improve support for existing platforms
are always welcome.

Patches that cause `oksh` to deviate from upstream OpenBSD ksh behavior
are better suited to be sent to the
[OpenBSD tech@](https://www.openbsd.org/mail.html)
mailing list. Please make sure to test your patch on an OpenBSD machine
first before submitting it to tech@. I will sync with the upstream 
OpenBSD code once your patch is accepted. If you'd like to open an issue
here to track progress of your patch on tech@, that's fine.

License
-------
The main Korn shell files are public domain (see `LEGAL`).
Portability files are BSD or ISC licensed; see individual file headers
for details.

Get a tarball
-------------
See releases tab. The latest release is oksh-7.3, which matches the ksh(1)
from OpenBSD 7.3, released April 10, 2023.
