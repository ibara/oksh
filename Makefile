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

# set OS platform (HACKITY HACK for gmake/bsd make compat)
OS != echo `uname -o` | tr 'A-Z' 'a-z' | sed -E 's/.*(bsd|linux)/\1/'
OS ?= linux

all:	${OBJS}
	${CC} ${LDFLAGS} -o ${PROG} ${OBJS}

install: os
include Makefile.${OS}

clean:
	rm -f ${PROG} *.o *~
