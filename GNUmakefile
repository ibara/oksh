# oksh portable GNUmakefile
# This file written by Brian Callahan <bcallah@openbsd.org>
# and released into the Public Domain.

PROG = oksh

PREFIX ?= /usr/local
MANDIR ?= ${PREFIX}/man
DOCDIR ?= ${PREFIX}/share/doc/oksh
INSTALL = /usr/bin/install

CFLAGS ?= -O2 -pipe
CFLAGS += -Wall

OBJS =	alloc.o c_ksh.o c_sh.o c_test.o c_ulimit.o edit.o emacs.o eval.o \
	exec.o expr.o history.o io.o jobs.o lex.o mail.o main.o mknod.o \
	misc.o path.o shf.o syn.o table.o trap.o tree.o tty.o var.o \
	version.o vi.o

#
# Portability stuff.
#
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
GROUP =	root
OBJS +=	portable/common/reallocarray.o portable/linux/setmode.o \
	portable/linux/signame.o portable/linux/strlcat.o \
	portable/linux/strlcpy.o portable/linux/strtonum.o
else ifeq ($(UNAME_S),FreeBSD)
GROUP =	bin
OBJS +=	portable/common/reallocarray.o
else ifeq ($(UNAME_S),DragonFly)
GROUP =	bin
OBJS += portable/common/reallocarray.o
else ifeq ($(UNAME_S),NetBSD)
GROUP =	bin
OBJS += portable/common/reallocarray.o
endif

#
# Only update /etc/shells at install time, not during update
#
UPDATE := `grep -w ${PREFIX}/bin/${PROG} /etc/shells > /dev/null;\
	[ $$? -ne 0] && echo "${PREFIX}/bin/${PROG}" >> /etc/shells`

all: ${OBJS}
	${CC} -o ${PROG} ${OBJS}

install: all
	${INSTALL} -c -s -o root -g ${GROUP} -m 555 ${PROG} ${PREFIX}/bin
	${INSTALL} -c -s -o root -g ${GROUP} -m 444 oksh.1 ${MANDIR}/man1/${PROG}.1
	echo ${UPDATE}

clean:
	rm -f ${PROG} ${OBJS}
