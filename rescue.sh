#!/bin/sh

# This rescue script should work literally everywhere.
# If your kit is so broken you need this, I'm going to
#   assume that you need all the help you can get.
#
# Written by Brian Callahan <bcallah@openbsd.org>
# Released into the Public Domain

cp prescue.h pconfig.h

echo cc -DEMACS -DVI -o alloc.o -c alloc.c
cc -DEMACS -DVI -o alloc.o -c alloc.c

echo cc -DEMACS -DVI -o c_ksh.o -c c_ksh.c
cc -DEMACS -DVI -o c_ksh.o -c c_ksh.c

echo cc -DEMACS -DVI -o c_sh.o -c c_sh.c
cc -DEMACS -DVI -o c_sh.o -c c_sh.c

echo cc -DEMACS -DVI -o c_test.o -c c_test.c
cc -DEMACS -DVI -o c_test.o -c c_test.c

echo cc -DEMACS -DVI -o c_ulimit.o -c c_ulimit.c
cc -DEMACS -DVI -o c_ulimit.o -c c_ulimit.c

echo cc -DEMACS -DVI -o edit.o -c edit.c
cc -DEMACS -DVI -o edit.o -c edit.c

echo cc -DEMACS -DVI -o emacs.o -c emacs.c
cc -DEMACS -DVI -o emacs.o -c emacs.c

echo cc -DEMACS -DVI -o eval.o -c eval.c
cc -DEMACS -DVI -o eval.o -c eval.c

echo cc -DEMACS -DVI -o exec.o -c exec.c
cc -DEMACS -DVI -o exec.o -c exec.c

echo cc -DEMACS -DVI -o expr.o -c expr.c
cc -DEMACS -DVI -o expr.o -c expr.c

echo cc -DEMACS -DVI -o history.o -c history.c
cc -DEMACS -DVI -o history.o -c history.c

echo cc -DEMACS -DVI -o io.o -c io.c
cc -DEMACS -DVI -o io.o -c io.c

echo cc -DEMACS -DVI -o jobs.o -c jobs.c
cc -DEMACS -DVI -o jobs.o -c jobs.c

echo cc -DEMACS -DVI -o lex.o -c lex.c
cc -DEMACS -DVI -o lex.o -c lex.c

echo cc -DEMACS -DVI -o mail.o -c mail.c
cc -DEMACS -DVI -o mail.o -c mail.c

echo cc -DEMACS -DVI -o main.o -c main.c
cc -DEMACS -DVI -o main.o -c main.c

echo cc -DEMACS -DVI -o misc.o -c misc.c
cc -DEMACS -DVI -o misc.o -c misc.c

echo cc -DEMACS -DVI -o path.o -c path.c
cc -DEMACS -DVI -o path.o -c path.c

echo cc -DEMACS -DVI -o shf.o -c shf.c
cc -DEMACS -DVI -o shf.o -c shf.c

echo cc -DEMACS -DVI -o syn.o -c syn.c
cc -DEMACS -DVI -o syn.o -c syn.c

echo cc -DEMACS -DVI -o table.o -c table.c
cc -DEMACS -DVI -o table.o -c table.c

echo cc -DEMACS -DVI -o trap.o -c trap.c
cc -DEMACS -DVI -o trap.o -c trap.c

echo cc -DEMACS -DVI -o tree.o -c tree.c
cc -DEMACS -DVI -o tree.o -c tree.c

echo cc -DEMACS -DVI -o tty.o -c tty.c
cc -DEMACS -DVI -o tty.o -c tty.c

echo cc -DEMACS -DVI -o var.o -c var.c
cc -DEMACS -DVI -o var.o -c var.c

echo cc -DEMACS -DVI -o version.o -c version.c
cc -DEMACS -DVI -o version.o -c version.c

echo cc -DEMACS -DVI -o vi.o -c vi.c
cc -DEMACS -DVI -o vi.o -c vi.c

echo cc -DEMACS -DVI -o confstr.o -c confstr.c
cc -DEMACS -DVI -o confstr.o -c confstr.c

echo cc -DEMACS -DVI -o reallocarray.o -c reallocarray.c
cc -DEMACS -DVI -o reallocarray.o -c reallocarray.c

echo cc -DEMACS -DVI -o strtonum.o -c strtonum.c
cc -DEMACS -DVI -o strtonum.o -c strtonum.c

echo cc -DEMACS -DVI -o signame.o -c signame.c
cc -DEMACS -DVI -o signame.o -c signame.c

echo cc -DEMACS -DVI -o strlcat.o -c strlcat.c
cc -DEMACS -DVI -o strlcat.o -c strlcat.c

echo cc -DEMACS -DVI -o strlcpy.o -c strlcpy.c
cc -DEMACS -DVI -o strlcpy.o -c strlcpy.c

echo cc -DEMACS -DVI -o unvis.o -c unvis.c
cc -DEMACS -DVI -o unvis.o -c unvis.c

echo cc -DEMACS -DVI -o vis.o -c vis.c
cc -DEMACS -DVI -o vis.o -c vis.c

echo cc -o oksh alloc.o c_ksh.o c_sh.o c_test.o c_ulimit.o edit.o emacs.o eval.o exec.o expr.o history.o io.o jobs.o lex.o mail.o main.o misc.o path.o shf.o syn.o table.o trap.o tree.o tty.o var.o version.o vi.o confstr.o reallocarray.o strtonum.o signame.o strlcat.o strlcpy.o unvis.o vis.o -lc
cc -o oksh alloc.o c_ksh.o c_sh.o c_test.o c_ulimit.o edit.o emacs.o eval.o exec.o expr.o history.o io.o jobs.o lex.o mail.o main.o misc.o path.o shf.o syn.o table.o trap.o tree.o tty.o var.o version.o vi.o confstr.o reallocarray.o strtonum.o signame.o strlcat.o strlcpy.o unvis.o vis.o -lc
