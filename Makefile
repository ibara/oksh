# oksh Makefile

# OpenBSD defaults
CC ?= cc
CFLAGS ?= -O2 -pipe
PREFIX ?= /usr/local

CFLAGS += -Wall
LDFLAGS += -static

PROG =	oksh
OBJS =	alloc.o c_ksh.o c_sh.o c_test.o c_ulimit.o edit.o emacs.o \
	eval.o exec.o expr.o history.o io.o jobs.o lex.o mail.o main.o \
	mknod.o misc.o path.o shf.o syn.o table.o trap.o tree.o tty.o \
	var.o version.o vi.o setmode.o signame.o strlcat.o strlcpy.o \
	reallocarray.o

# On Linux group is root, on FreeBSD it's wheel.
GROUP := `uname -s|sed 's/Linux/root/;s/^[^r].*[^t]$\/wheel/'`

# Update /etc/shells once: at install time only, not after an upgrade.
FOUND := `grep -w oksh /etc/shells >/dev/null; [ $$$? -eq 0 ] && echo \'`
ETC = "${PREFIX}/bin/oksh" >> /etc/shells

all:	${OBJS}
	${CC} ${LDFLAGS} -o ${PROG} ${OBJS}

install: all
	install -c -s -o root -g ${GROUP} -m 555 oksh ${PREFIX}/bin
	install -c -o root -g ${GROUP} -m 444 oksh.1 ${PREFIX}/man/man1
	echo ${FOUND}${ETC}${FOUND}

clean:
	rm -f ${PROG} *.o *~
