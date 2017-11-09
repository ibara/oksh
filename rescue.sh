#!/bin/sh

# This rescue script should work literally everywhere.
# If your kit is so broken you need this, I'm going to
#   assume that you need all the help you can get.
#
# Written by Brian Callahan <bcallah@openbsd.org>
# Released into the Public Domain

echo "cc -DEMACS -DVI -Iportable/common -o alloc.o -c alloc.c"
cc -DEMACS -DVI -Iportable/common -o alloc.o -c alloc.c

echo "cc -DEMACS -DVI -Iportable/common -o c_ksh.o -c c_ksh.c"
cc -DEMACS -DVI -Iportable/common -o c_ksh.o -c c_ksh.c

echo "cc -DEMACS -DVI -Iportable/common -o c_sh.o -c c_sh.c"
cc -DEMACS -DVI -Iportable/common -o c_sh.o -c c_sh.c

echo "cc -DEMACS -DVI -Iportable/common -o c_test.o -c c_test.c"
cc -DEMACS -DVI -Iportable/common -o c_test.o -c c_test.c

echo "cc -DEMACS -DVI -Iportable/common -o c_ulimit.o -c c_ulimit.c"
cc -DEMACS -DVI -Iportable/common -o c_ulimit.o -c c_ulimit.c

echo "cc -DEMACS -DVI -Iportable/common -o edit.o -c edit.c"
cc -DEMACS -DVI -Iportable/common -o edit.o -c edit.c

echo "cc -DEMACS -DVI -Iportable/common -o emacs.o -c emacs.c"
cc -DEMACS -DVI -Iportable/common -o emacs.o -c emacs.c

echo "cc -DEMACS -DVI -Iportable/common -o eval.o -c eval.c"
cc -DEMACS -DVI -Iportable/common -o eval.o -c eval.c

echo "cc -DEMACS -DVI -Iportable/common -o exec.o -c exec.c"
cc -DEMACS -DVI -Iportable/common -o exec.o -c exec.c

echo "cc -DEMACS -DVI -Iportable/common -o expr.o -c expr.c"
cc -DEMACS -DVI -Iportable/common -o expr.o -c expr.c

echo "cc -DEMACS -DVI -Iportable/common -o history.o -c history.c"
cc -DEMACS -DVI -Iportable/common -o history.o -c history.c

echo "cc -DEMACS -DVI -Iportable/common -o io.o -c io.c"
cc -DEMACS -DVI -Iportable/common -o io.o -c io.c

echo "cc -DEMACS -DVI -Iportable/common -o jobs.o -c jobs.c"
cc -DEMACS -DVI -Iportable/common -o jobs.o -c jobs.c

echo "cc -DEMACS -DVI -Iportable/common -o lex.o -c lex.c"
cc -DEMACS -DVI -Iportable/common -o lex.o -c lex.c

echo "cc -DEMACS -DVI -Iportable/common -o mail.o -c mail.c"
cc -DEMACS -DVI -Iportable/common -o mail.o -c mail.c

echo "cc -DEMACS -DVI -Iportable/common -o main.o -c main.c"
cc -DEMACS -DVI -Iportable/common -o main.o -c main.c

echo "cc -DEMACS -DVI -Iportable/common -o misc.o -c misc.c"
cc -DEMACS -DVI -Iportable/common -o misc.o -c misc.c

echo "cc -DEMACS -DVI -Iportable/common -o path.o -c path.c"
cc -DEMACS -DVI -Iportable/common -o path.o -c path.c

echo "cc -DEMACS -DVI -Iportable/common -o shf.o -c shf.c"
cc -DEMACS -DVI -Iportable/common -o shf.o -c shf.c

echo "cc -DEMACS -DVI -Iportable/common -o syn.o -c syn.c"
cc -DEMACS -DVI -Iportable/common -o syn.o -c syn.c

echo "cc -DEMACS -DVI -Iportable/common -o table.o -c table.c"
cc -DEMACS -DVI -Iportable/common -o table.o -c table.c

echo "cc -DEMACS -DVI -Iportable/common -o trap.o -c trap.c"
cc -DEMACS -DVI -Iportable/common -o trap.o -c trap.c

echo "cc -DEMACS -DVI -Iportable/common -o tree.o -c tree.c"
cc -DEMACS -DVI -Iportable/common -o tree.o -c tree.c

echo "cc -DEMACS -DVI -Iportable/common -o tty.o -c tty.c"
cc -DEMACS -DVI -Iportable/common -o tty.o -c tty.c

echo "cc -DEMACS -DVI -Iportable/common -o var.o -c var.c"
cc -DEMACS -DVI -Iportable/common -o var.o -c var.c

echo "cc -DEMACS -DVI -Iportable/common -o version.o -c version.c"
cc -DEMACS -DVI -Iportable/common -o version.o -c version.c

echo "cc -DEMACS -DVI -Iportable/common -o vi.o -c vi.c"
cc -DEMACS -DVI -Iportable/common -o vi.o -c vi.c

echo "cc -DEMACS -DVI -Iportable/common -o reallocarray.o -c portable/common/reallocarray.c"
cc -DEMACS -DVI -Iportable/common -o reallocarray.o -c portable/common/reallocarray.c

echo "cc -DEMACS -DVI -Iportable/common -o strtonum.o -c portable/common/strtonum.c"
cc -DEMACS -DVI -Iportable/common -o strtonum.o -c portable/common/strtonum.c

echo "cc -DEMACS -DVI -Iportable/common -o setmode.o -c portable/linux/setmode.c"
cc -DEMACS -DVI -Iportable/common -o setmode.o -c portable/linux/setmode.c

echo "cc -DEMACS -DVI -Iportable/common -o signame.o -c portable/linux/signame.c"
cc -DEMACS -DVI -Iportable/common -o signame.o -c portable/linux/signame.c

echo "cc -DEMACS -DVI -Iportable/common -o strlcat.o -c portable/linux/strlcat.c"
cc -DEMACS -DVI -Iportable/common -o strlcat.o -c portable/linux/strlcat.c

echo "cc -DEMACS -DVI -Iportable/common -o strlcpy.o -c portable/linux/strlcpy.c"
cc -DEMACS -DVI -Iportable/common -o strlcpy.o -c portable/linux/strlcpy.c

echo "cc -DEMACS -DVI -Iportable/common -o unvis.o -c portable/linux/unvis.c"
cc -DEMACS -DVI -Iportable/common -o unvis.o -c portable/linux/unvis.c

echo "cc -DEMACS -DVI -Iportable/common -o vis.o -c portable/linux/vis.c"
cc -DEMACS -DVI -Iportable/common -o vis.o -c portable/linux/vis.c

echo "cc -o oksh alloc.o c_ksh.o c_sh.o c_test.o c_ulimit.o edit.o emacs.o eval.o exec.o expr.o history.o io.o jobs.o lex.o mail.o main.o misc.o path.o shf.o syn.o table.o trap.o tree.o tty.o var.o version.o vi.o reallocarray.o strtonum.o setmode.o signame.o strlcat.o strlcpy.o unvis.o vis.o -lc"
cc -o oksh alloc.o c_ksh.o c_sh.o c_test.o c_ulimit.o edit.o emacs.o eval.o exec.o expr.o history.o io.o jobs.o lex.o mail.o main.o misc.o path.o shf.o syn.o table.o trap.o tree.o tty.o var.o version.o vi.o reallocarray.o strtonum.o setmode.o signame.o strlcat.o strlcpy.o unvis.o vis.o -lc
