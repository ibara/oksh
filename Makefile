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
	var.o version.o vi.o

all:	${OBJS}
	${CC} ${LDFLAGS} -o ${PROG} ${OBJS}

install: all
	install -c -s -o root -g wheel -m 555 oksh ${PREFIX}/bin
	install -c -o root -g wheel -m 444 oksh.1 ${PREFIX}/man/man1
	echo "${PREFIX}/bin/oksh" >> /etc/shells

clean:
	rm -f ${PROG} *.o *~
