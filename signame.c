/*	$OpenBSD: signame.c,v 1.5 2009/11/27 19:47:45 guenther Exp $ */
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include "pconfig.h"

#ifndef HAVE_SIGNAME

#include <signal.h>
#include <unistd.h>

static const struct { int sig; const char *name; } signame[] = {
	{ 0, "Signal 0" },
#ifdef SIGHUP
	{ SIGHUP, "HUP" },
#endif
#ifdef SIGINT
	{ SIGINT, "INT" },
#endif
#ifdef SIGQUIT
	{ SIGQUIT, "QUIT" },
#endif
#ifdef SIGILL
	{ SIGILL, "ILL" },
#endif
#ifdef SIGTRAP
	{ SIGTRAP, "TRAP" },
#endif
#ifdef SIGABRT
	{ SIGABRT, "ABRT" },
#endif
#ifdef SIGEMT
	{ SIGEMT, "EMT" },
#endif
#ifdef SIGFPE
	{ SIGFPE, "FPE" },
#endif
#ifdef SIGKILL
	{ SIGKILL, "KILL" },
#endif
#ifdef SIGBUS
	{ SIGBUS, "BUS" },
#endif
#ifdef SIGSEGV
	{ SIGSEGV, "SEGV" },
#endif
#ifdef SIGSYS
	{ SIGSYS, "SYS" },
#endif
#ifdef SIGPIPE
	{ SIGPIPE, "PIPE" },
#endif
#ifdef SIGALRM
	{ SIGALRM, "ALRM" },
#endif
#ifdef SIGTERM
	{ SIGTERM, "TERM" },
#endif
#ifdef SIGURG
	{ SIGURG, "URG" },
#endif
#ifdef SIGSTOP
	{ SIGSTOP, "STOP" },
#endif
#ifdef SIGTSTP
	{ SIGTSTP, "TSTP" },
#endif
#ifdef SIGCONT
	{ SIGCONT, "CONT" },
#endif
#ifdef SIGCHLD
	{ SIGCHLD, "CHLD" },
#endif
#ifdef SIGTTIN
	{ SIGTTIN, "TTIN" },
#endif
#ifdef SIGTTOU
	{ SIGTTOU, "TTOU" },
#endif
#ifdef SIGIO
	{ SIGIO, "IO" },
#endif
#ifdef SIGXCPU
	{ SIGXCPU, "XCPU" },
#endif
#ifdef SIGXFSZ
	{ SIGXFSZ, "XFSZ" },
#endif
#ifdef SIGVTALRM
	{ SIGVTALRM, "VTALRM" },
#endif
#ifdef SIGPROF
	{ SIGPROF, "PROF" },
#endif
#ifdef SIGWINCH
	{ SIGWINCH, "WINCH" },
#endif
#ifdef SIGINFO
	{ SIGINFO, "INFO" },
#endif
#ifdef SIGUSR1
	{ SIGUSR1, "USR1" },
#endif
#ifdef SIGUSR2
	{ SIGUSR2, "USR2" },
#endif
#ifdef SIGPWR
	{ SIGPWR, "PWR" },
#endif
#ifdef SIGSTKFLT
	{ SIGSTKFLT, "STKFLT" },
#endif
};

const char *sig2str(int sig) {
	for (int i = 0; i < sizeof(signame)/sizeof(*signame); i++)
		if (signame[i].sig == sig)
			return signame[i].name;
	return "UNKNOWN";
}

#endif /* !HAVE_SIGNAME */
