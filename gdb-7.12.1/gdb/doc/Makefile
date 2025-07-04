##Copyright (C) 1991-2017 Free Software Foundation, Inc.

# Makefile for GDB documentation.
# This file is part of GDB.

# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

srcdir = .


prefix = /workspace/gdb-mipsel-static

infodir = ${datarootdir}/info
datarootdir = ${prefix}/share
docdir = ${datarootdir}/doc/${PACKAGE}
pdfdir = ${docdir}
htmldir = ${docdir}
mandir = ${datarootdir}/man
man1dir = $(mandir)/man1
man5dir = $(mandir)/man5

transform = s,y,y,

SHELL = /bin/bash

LN_S = ln -s

INSTALL = /usr/bin/install -c
INSTALL_PROGRAM = /usr/bin/install -c
INSTALL_DATA = /usr/bin/install -c -m 644

SYSTEM_GDBINIT = 

mkinstalldirs = $(SHELL) $(srcdir)/../../mkinstalldirs

# main GDB source directory
gdbdir = $(srcdir)/..

# where to find texinfo; GDB dist should include a recent one
TEXIDIR=${gdbdir}/../texinfo

# where to find makeinfo, preferably one designed for texinfo-2
MAKEINFO = makeinfo --split-size=5000000
MAKEINFOFLAGS = 
MAKEINFO_EXTRA_FLAGS =  -DHAVE_MAKEINFO_CLICK
MAKEINFO_CMD = $(MAKEINFO) $(MAKEINFOFLAGS) $(MAKEINFO_EXTRA_FLAGS)

MAKEHTML = $(MAKEINFO_CMD) --html
MAKEHTMLFLAGS =

# where to find texi2roff, ditto
TEXI2ROFF=texi2roff

# where to find texi2dvi, ditto
TEXI2DVI=texi2dvi

# Package to install the docs under
PACKAGE = gdb

# Package version and bug-reporting URL.
PKGVERSION = (GDB) 
BUGURL_TEXI = @uref{http://www.gnu.org/software/gdb/bugs/}

# Where is the source dir for the READLINE library doc?  
# Traditionally readline is in .. or .
READLINE_DIR = ${gdbdir}/../readline/doc
READLINE_TEXI_INCFLAG = -I $(READLINE_DIR)

# The GDB/MI docs come from a sibling directory ../mi
GDBMI_DIR = ${gdbdir}/mi

SET_TEXINPUTS = \
   TEXINPUTS=${TEXIDIR}:.:$(srcdir):$(READLINE_DIR):$(GDBMI_DIR):$$TEXINPUTS

# Files which should be generated via 'info' and installed by 'install-info'
INFO_DEPS = gdb.info stabs.info annotate.info

# Files which should be generated via 'pdf' and installed by 'install-pdf'
PDFFILES = gdb.pdf stabs.pdf refcard.pdf annotate.pdf
# Files which should be generated via 'html' and installed by 'install-html'
HTMLFILES =  gdb/index.html stabs/index.html annotate/index.html
HTMLFILES_INSTALL = gdb stabs annotate

# There may be alternate predefined collections of switches to configure
# the GDB manual.  Normally this is not done in synch with the software
# config system, since this choice tends to be independent; most people
# want a doc config of `all' for a generic manual, regardless of sw config.
DOC_CONFIG = all

# This list of sed edits will edit the GDB reference card
# for what fonts and what papersize to use.
# By default (NO edits applied), the refcard uses:
#    - Computer Modern (CM) fonts
#    - US letter paper (8.5x11in)
# List some of the following files for alternative fonts and paper:
#  a4rc.sed     use A4 paper (297 x 210 mm)
#  psrc.sed     use PostScript fonts (Karl Berry short TeX names)
# lpsrc.sed     use PostScript fonts (full PostScript names in TeX)
# e.g. for A4, Postscript:  REFEDITS = a4rc.sed psrc.sed
#      for A4, CM fonts:    REFEDITS = a4rc.sed
#      for US, PS fonts:    REFEDITS = psrc.sed
#      for default:
REFEDITS =

# Don Knuth's TeX formatter
TEX = tex
PDFTEX = pdftex

# Program to generate Postscript files from DVI files.
DVIPS = dvips

# Main GDB manual
# Note that this unconditionally includes the readline texi files,
# even when --with-system-readline is used.  This is harmless because
# these are only used as dependencies.
GDB_DOC_SOURCE_INCLUDES = \
	$(srcdir)/fdl.texi \
	$(srcdir)/gpl.texi \
	$(srcdir)/agentexpr.texi \
	$(READLINE_DIR)/rluser.texi \
	$(READLINE_DIR)/hsuser.texi
GDB_DOC_BUILD_INCLUDES = \
	gdb-cfg.texi \
	GDBvn.texi
GDB_DOC_FILES = \
	$(srcdir)/gdb.texinfo \
	$(srcdir)/guile.texi \
	$(srcdir)/python.texi \
	$(GDB_DOC_SOURCE_INCLUDES) \
	$(GDB_DOC_BUILD_INCLUDES)

# Stabs manual: All files
STABS_DOC_SOURCE_INCLUDES = \
	$(srcdir)/fdl.texi
STABS_DOC_BUILD_INCLUDES = \
	gdb-cfg.texi \
	GDBvn.texi
STABS_DOC_FILES = \
	$(srcdir)/stabs.texinfo \
	$(STABS_DOC_SOURCE_INCLUDES) \
	$(STABS_DOC_BUILD_INCLUDES)

# Annotate migration document
ANNOTATE_DOC_SOURCE_INCLUDES = \
	$(srcdir)/fdl.texi
ANNOTATE_DOC_BUILD_INCLUDES = \
	gdb-cfg.texi \
	GDBvn.texi
ANNOTATE_DOC_FILES = \
	$(srcdir)/annotate.texinfo \
	$(ANNOTATE_DOC_SOURCE_INCLUDES) \
	$(ANNOTATE_DOC_BUILD_INCLUDES)

# Options to extract the man page from gdb.texinfo
MANCONF = -Dman

TEXI2POD = perl $(srcdir)/../../etc/texi2pod.pl \
		$(MAKEINFOFLAGS) $(MAKEINFO_EXTRA_FLAGS)

POD2MAN1 = pod2man --center="GNU Development Tools" \
		   --release="gdb-`sed q version.subst`" --section=1
POD2MAN5 = pod2man --center="GNU Development Tools" \
		   --release="gdb-`sed q version.subst`" --section=5

# List of man pages generated from gdb.texi
MAN1S = gdb.1 gdbserver.1 gcore.1
MAN5S = gdbinit.5
MANS = $(MAN1S) $(MAN5S)

# Host-dependent makefile fragment comes in here.
# Host: Linux/MIPS
NAT_FILE= config/nm-linux.h
NATDEPFILES= inf-ptrace.o fork-child.o mips-linux-nat.o \
	linux-thread-db.o proc-service.o \
	linux-nat.o linux-osdata.o linux-fork.o \
	linux-procfs.o linux-ptrace.o linux-waitpid.o \
	linux-personality.o \
	mips-linux-watch.o linux-namespaces.o
NAT_CDEPS = $(srcdir)/proc-service.list

LOADLIBES = -ldl $(RDYNAMIC)
# End of host-dependent makefile fragment
HAVE_NATIVE_GCORE_TARGET = 1

###

all:

info: $(INFO_DEPS)
dvi: gdb.dvi stabs.dvi refcard.dvi annotate.dvi
ps: gdb.ps stabs.ps refcard.ps annotate.ps
html: $(HTMLFILES)
pdf: $(PDFFILES)
man: $(MANS)

DOXYGEN = doxygen
doxyedit = sed -e 's,@srcdir\@,$(srcdir),g'

doxy:	doxy/index.html \
	doxy/gdb-api/index.html \
	doxy/gdb-xref/index.html \
	doxy/gdbserver/index.html

doxy/index.html: $(srcdir)/doxy-index.in
	-mkdir -p doxy
	cp $(srcdir)/doxy-index.in doxy/index.html

doxy/gdb-api/index.html: Doxyfile-gdb-api Doxyfile-base
	-mkdir -p doxy
	$(DOXYGEN) Doxyfile-gdb-api

doxy/gdb-xref/index.html: Doxyfile-gdb-xref Doxyfile-base
	-mkdir -p doxy
	$(DOXYGEN) Doxyfile-gdb-xref

doxy/gdbserver/index.html: Doxyfile-gdbserver Doxyfile-base
	-mkdir -p doxy
	$(DOXYGEN) Doxyfile-gdbserver

Doxyfile-base:	$(srcdir)/Doxyfile-base.in 
	$(doxyedit) $(srcdir)/Doxyfile-base.in >Doxyfile-base

Doxyfile-gdb-api:	$(srcdir)/Doxyfile-gdb-api.in 
	$(doxyedit) $(srcdir)/Doxyfile-gdb-api.in >Doxyfile-gdb-api

Doxyfile-gdb-xref:	$(srcdir)/Doxyfile-gdb-xref.in
	$(doxyedit) $(srcdir)/Doxyfile-gdb-xref.in >Doxyfile-gdb-xref

Doxyfile-gdbserver:	$(srcdir)/Doxyfile-gdbserver.in
	$(doxyedit) $(srcdir)/Doxyfile-gdbserver.in >Doxyfile-gdbserver

all-doc: info dvi ps # pdf
diststuff: info man
	rm -f gdb-cfg.texi GDBvn.texi

install-info: $(INFO_DEPS)
	$(SHELL) $(srcdir)/../../mkinstalldirs $(DESTDIR)$(infodir)
	@list='$(INFO_DEPS)'; \
	for file in $$list; do \
	  if test -f $$file; then d=.; else d=$(srcdir); fi; \
	  for ifile in `cd $$d && echo $$file $$file-[0-9] $$file-[0-9][0-9]`; do \
	    if test -f $$d/$$ifile; then \
	      echo " $(INSTALL_DATA) $$d/$$ifile $(DESTDIR)$(infodir)/$$ifile"; \
	      $(INSTALL_DATA) $$d/$$ifile $(DESTDIR)$(infodir)/$$ifile; \
	    else : ; fi; \
	  done; \
	done
	$(POST_INSTALL)
	@if $(SHELL) -c 'install-info --version | sed 1q | fgrep -s -v -i debian' >/dev/null 2>&1; then \
	  list='$(INFO_DEPS)'; \
	  for file in $$list; do \
	    echo " install-info --info-dir=$(DESTDIR)$(infodir) $(DESTDIR)$(infodir)/$$file";\
	    install-info --info-dir=$(DESTDIR)$(infodir) $(DESTDIR)$(infodir)/$$file || :;\
	  done; \
	else : ; fi

uninstall-info:
	$(PRE_UNINSTALL)
	@if $(SHELL) -c 'install-info --version | sed 1q | fgrep -s -v -i debian' >/dev/null 2>&1; then \
	  ii=yes; \
	else ii=; fi; \
	list='$(INFO_DEPS)'; \
	for file in $$list; do \
	  test -z "$$ii" \
	    || install-info --info-dir=$(DESTDIR)$(infodir) --remove $$file; \
	done
	$(NORMAL_UNINSTALL)
	list='$(INFO_DEPS)'; \
	for file in $$list; do \
	  (cd $(DESTDIR)$(infodir) && rm -f $$file $$file-[0-9] $$file-[0-9][0-9]); \
	done

html__strip_dir = `echo $$p | sed -e 's|^.*/||'`;

install-html: $(HTMLFILES)
	@$(NORMAL_INSTALL)
	test -z "$(htmldir)" || $(mkinstalldirs) "$(DESTDIR)$(htmldir)"
	@list='$(HTMLFILES_INSTALL)'; for p in $$list; do \
	  if test -f "$$p" || test -d "$$p"; then d=""; else d="$(srcdir)/"; fi; \
	  f=$(html__strip_dir) \
	  if test -d "$$d$$p"; then \
	    echo " $(mkinstalldirs) '$(DESTDIR)$(htmldir)/$$f'"; \
	    $(mkinstalldirs) "$(DESTDIR)$(htmldir)/$$f" || exit 1; \
	    echo " $(INSTALL_DATA) '$$d$$p'/* '$(DESTDIR)$(htmldir)/$$f'"; \
	    $(INSTALL_DATA) "$$d$$p"/* "$(DESTDIR)$(htmldir)/$$f"; \
	  else \
	    echo " $(INSTALL_DATA) '$$d$$p' '$(DESTDIR)$(htmldir)/$$f'"; \
	    $(INSTALL_DATA) "$$d$$p" "$(DESTDIR)$(htmldir)/$$f"; \
	  fi; \
	done

pdf__strip_dir = `echo $$p | sed -e 's|^.*/||'`;

install-pdf: $(PDFFILES)
	@$(NORMAL_INSTALL)
	test -z "$(pdfdir)" || $(mkinstalldirs) "$(DESTDIR)$(pdfdir)"
	@list='$(PDFFILES)'; for p in $$list; do \
	  if test -f "$$p"; then d=; else d="$(srcdir)/"; fi; \
	  f=$(pdf__strip_dir) \
	  echo " $(INSTALL_DATA) '$$d$$p' '$(DESTDIR)$(pdfdir)/$$f'"; \
	  $(INSTALL_DATA) "$$d$$p" "$(DESTDIR)$(pdfdir)/$$f"; \
	done

install-man: install-man1 install-man5

install-man1: $(MAN1S)
	test -z "$(man1dir)" || $(mkinstalldirs) "$(DESTDIR)$(man1dir)"
	@list='$(MAN1S)'; for p in $$list; do \
	  if test "x$(HAVE_NATIVE_GCORE_TARGET)$(HAVE_NATIVE_GCORE_HOST)" = x \
		  -a "$$p" = gcore.1; then \
	    continue; \
	  fi; \
	  if test -f "$$p"; then d=; else d="$(srcdir)/"; fi; \
	  f=`echo $$p | sed -e 's|^.*/||' -e '$(transform)'`; \
	  echo " $(INSTALL_DATA) '$$d$$p' '$(DESTDIR)$(man1dir)/$$f'"; \
	  $(INSTALL_DATA) "$$d$$p" "$(DESTDIR)$(man1dir)/$$f"; \
	done

install-man5: $(MAN5S)
	test -z "$(man5dir)" || $(mkinstalldirs) "$(DESTDIR)$(man5dir)"
	@list='$(MAN5S)'; for p in $$list; do \
	  if test -f "$$p"; then d=; else d="$(srcdir)/"; fi; \
	  f=`echo $$p | sed -e 's|^.*/||' -e '$(transform)'`; \
	  echo " $(INSTALL_DATA) '$$d$$p' '$(DESTDIR)$(man5dir)/$$f'"; \
	  $(INSTALL_DATA) "$$d$$p" "$(DESTDIR)$(man5dir)/$$f"; \
	done

uninstall-man: uninstall-man1 uninstall-man5

uninstall-man1:
	@test -n "$(man1dir)" || exit 0; \
	files=`{ l2='$(MAN1S)'; for i in $$l2; do \
	  if test "x$(HAVE_NATIVE_GCORE_TARGET)$(HAVE_NATIVE_GCORE_HOST)" = x \
		  -a "$$i" = gcore.1; then \
	    continue; \
	  fi; \
	  echo "$$i"; \
	done | \
	  sed -n '/\.1[a-z]*$$/p'; \
	} | sed -e 's,.*/,,;h;s,.*\.,,;s,^[^1][0-9a-z]*$$,1,;x' \
	      -e 's,\.[0-9a-z]*$$,,;$(transform);G;s,\n,.,'`; \
	test -z "$$files" || { \
	  echo " ( cd '$(DESTDIR)$(man1dir)' && rm -f" $$files ")"; \
	  cd "$(DESTDIR)$(man1dir)" && rm -f $$files; }

uninstall-man5:
	@test -n "$(man5dir)" || exit 0; \
	files=`{ l2='$(MAN5S)'; for i in $$l2; do echo "$$i"; done | \
	  sed -n '/\.5[a-z]*$$/p'; \
	} | sed -e 's,.*/,,;h;s,.*\.,,;s,^[^5][0-9a-z]*$$,5,;x' \
	      -e 's,\.[0-9a-z]*$$,,;$(transform);G;s,\n,.,'`; \
	test -z "$$files" || { \
	  echo " ( cd '$(DESTDIR)$(man5dir)' && rm -f" $$files ")"; \
	  cd "$(DESTDIR)$(man5dir)" && rm -f $$files; }

STAGESTUFF = *.info* gdb-all.texi GDBvn.texi *.ps *.dvi *.pdf *.1 *.5

# Copy the object files from a particular stage into a subdirectory.
stage1: force
	-mkdir stage1
	-mv $(STAGESTUFF) stage1

stage2: force
	-mkdir stage2
	-mv $(STAGESTUFF) stage2

stage3: force
	-mkdir stage3
	-mv $(STAGESTUFF) stage3

against=stage2

comparison: force
	for i in $(STAGESTUFF) ; do cmp $$i $(against)/$$i ; done

de-stage1: force
	-(cd stage1 ; mv -f * ..)
	-rmdir stage1

de-stage2: force
	-(cd stage2 ; mv -f * ..)
	-rmdir stage2

de-stage3: force
	-(cd stage3 ; mv -f * ..)
	-rmdir stage3

# GDB QUICK REFERENCE (dvi output)
refcard.dvi : refcard.tex $(REFEDITS)
	echo > tmp.sed
	for f in x $(REFEDITS) ; do \
		test x$$f = xx && continue ; \
		cat $(srcdir)/$$f >>tmp.sed ; \
	done
	sed -f tmp.sed $(srcdir)/refcard.tex >sedref.tex
	$(SET_TEXINPUTS) $(TEX) sedref.tex
	mv sedref.dvi refcard.dvi
	rm -f sedref.log sedref.tex tmp.sed

refcard.ps : refcard.dvi
	$(DVIPS) -t landscape -o $@ $?

refcard.pdf : refcard.tex $(REFEDITS)
	echo > tmp.sed
	for f in x $(REFEDITS) ; do \
		test x$$f = xx && continue ; \
		cat $(srcdir)/$$f >>tmp.sed ; \
	done
	sed -f tmp.sed $(srcdir)/refcard.tex >sedref.tex
	$(SET_TEXINPUTS) $(PDFTEX) sedref.tex
	mv sedref.pdf refcard.pdf
	rm -f sedref.log sedref.tex tmp.sed

# File to record current GDB version number.
GDBvn.texi : version.subst
	echo "@set GDBVN `sed q version.subst`" > ./GDBvn.new
	if [ -n "$(PKGVERSION)" ]; then \
	  echo "@set VERSION_PACKAGE $(PKGVERSION)" >> ./GDBvn.new; \
	fi
	echo "@set BUGURL $(BUGURL_TEXI)" >> ./GDBvn.new
	if [ "$(BUGURL_TEXI)" = "@uref{http://www.gnu.org/software/gdb/bugs/}" ]; then \
	  echo "@set BUGURL_DEFAULT" >> ./GDBvn.new; \
	fi
	if test -z "$(READLINE_TEXI_INCFLAG)"; then \
	  echo "@set SYSTEM_READLINE" >> ./GDBvn.new; \
	fi
	if [ -n "$(SYSTEM_GDBINIT)" ]; then \
	  echo "@set SYSTEM_GDBINIT $(SYSTEM_GDBINIT)" >> ./GDBvn.new; \
	fi
	mv GDBvn.new GDBvn.texi

version.subst: $(gdbdir)/version.in $(gdbdir)/../bfd/version.h
	date=`sed -n -e 's/^.* BFD_VERSION_DATE \(.*\)$$/\1/p' $(gdbdir)/../bfd/version.h`; \
	sed -e "s/DATE/$$date/" < $(gdbdir)/version.in > version.subst

# Updated atomically
.PRECIOUS: GDBvn.texi

# Choose configuration for GDB manual (normally `all'; normally not tied into
# `configure' script because most users prefer generic version of manual,
# not one for their binary config---which may not be specifically
# defined anyways).
gdb-cfg.texi: ${srcdir}/${DOC_CONFIG}-cfg.texi
	(test "$(LN_S)" = "ln -s" && \
	  ln -s ${srcdir}/${DOC_CONFIG}-cfg.texi gdb-cfg.texi) || \
	ln ${srcdir}/${DOC_CONFIG}-cfg.texi gdb-cfg.texi || \
	cp ${srcdir}/${DOC_CONFIG}-cfg.texi gdb-cfg.texi

# GDB MANUAL: texinfo source, using @set/@clear/@value/@ifset/@ifclear
# If your texinfo or makeinfo don't support these, get a new texinfo release
#
# The nonsense with GDBvn.texi gets this to run with both Sun and GNU make.
#   Note that we can *generate* GDBvn.texi, but since we distribute one in the
#   source directory for the benefit of people who *don't* use this makefile,
#   VPATH will often tell make not to bother building it, because the one
#   in the srcdir is up to date.  (if not, then make should build one here).

# Clean these up before each run.  Avoids a catch 22 with not being
# able to re-generate these files (to fix a corruption) because these
# files contain a corruption.
GDB_TEX_TMPS = gdb.aux gdb.cp* gdb.fn* gdb.ky* gdb.log gdb.pg* gdb.toc \
	gdb.tp* gdb.vr*

# GDB MANUAL: TeX dvi file
gdb.dvi: ${GDB_DOC_FILES}
	if [ ! -f ./GDBvn.texi ]; then \
		(test "$(LN_S)" = "ln -s" && ln -s $(srcdir)/GDBvn.texi .) || \
		ln $(srcdir)/GDBvn.texi . || \
		cp $(srcdir)/GDBvn.texi . ; else true; fi
	rm -f $(GDB_TEX_TMPS)
	$(TEXI2DVI) $(READLINE_TEXI_INCFLAG) -I ${GDBMI_DIR} -I $(srcdir) \
		$(srcdir)/gdb.texinfo

gdb.ps: gdb.dvi
	$(DVIPS) -o $@ $?

gdb.pdf: ${GDB_DOC_FILES}
	if [ ! -f ./GDBvn.texi ]; then \
		(test "$(LN_S)" = "ln -s" && ln -s $(srcdir)/GDBvn.texi .) || \
		ln $(srcdir)/GDBvn.texi . || \
		cp $(srcdir)/GDBvn.texi . ; else true; fi
	rm -f $(GDB_TEX_TMPS)
	$(TEXI2DVI) --pdf $(READLINE_TEXI_INCFLAG) -I ${GDBMI_DIR} -I $(srcdir) \
		$(srcdir)/gdb.texinfo

# GDB MANUAL: info file
gdb.info: ${GDB_DOC_FILES}
	$(MAKEINFO_CMD) $(READLINE_TEXI_INCFLAG) -I ${GDBMI_DIR} -I $(srcdir) \
		-o gdb.info $(srcdir)/gdb.texinfo

# GDB MANUAL: roff translations
# Try to use a recent texi2roff.  v2 was put on prep in jan91.
# If you want an index, see texi2roff doc for postprocessing 
# and add -i to texi2roff invocations below.
# Workarounds for texi2roff-2 (probably fixed in later texi2roff's, delete
#    corresponding -e lines when later texi2roff's are current)
# + @ifinfo's deleted explicitly due to texi2roff-2 bug w nested constructs.
# + @c's deleted explicitly because texi2roff sees texinfo commands in them
# + @   (that's at-BLANK) not recognized by texi2roff, turned into blank
# + @alphaenumerate is ridiculously new, turned into @enumerate

# texi2roff doesn't have a notion of include dirs, so we have to fake 
# it out for gdb manual's include files---but only if not configured
# in main sourcedir.
links2roff: $(GDB_DOC_SOURCE_INCLUDES)
	if [ ! -f gdb.texinfo ]; then \
		(test "$(LN_S)" = "ln -s" && ln -s $(GDB_DOC_SOURCE_INCLUDES) .) || \
		ln $(GDB_DOC_SOURCE_INCLUDES)    . || \
		cp $(GDB_DOC_SOURCE_INCLUDES)    . ; \
	fi
	touch links2roff

# gdb manual suitable for [gtn]roff -me
gdb.me: $(GDB_DOC_FILES) links2roff
	sed -e '/\\input texinfo/d' \
		-e '/@c TEXI2ROFF-KILL/,/@c END TEXI2ROFF-KILL/d' \
		-e '/^@ifinfo/,/^@end ifinfo/d' \
		-e '/^@c /d' \
		-e 's/{.*,,/{/' \
		-e 's/@ / /g' \
		-e 's/^@alphaenumerate/@enumerate/g' \
		-e 's/^@end alphaenumerate/@end enumerate/g' \
		$(srcdir)/gdb.texinfo | \
	$(TEXI2ROFF) -me | \
	sed -e 's/---/\\(em/g' \
	>gdb.me 

# gdb manual suitable for [gtn]roff -ms
gdb.ms: $(GDB_DOC_FILES) links2roff
	sed -e '/\\input texinfo/d' \
		-e '/@c TEXI2ROFF-KILL/,/@c END TEXI2ROFF-KILL/d' \
		-e '/^@ifinfo/,/^@end ifinfo/d' \
		-e '/^@c /d' \
		-e 's/{.*,,/{/' \
		-e 's/@ / /g' \
		-e 's/^@alphaenumerate/@enumerate/g' \
		-e 's/^@end alphaenumerate/@end enumerate/g' \
		$(srcdir)/gdb.texinfo | \
	$(TEXI2ROFF) -ms | \
	sed -e 's/---/\\(em/g' \
	>gdb.ms 

# gdb manual suitable for [tn]roff -mm
# '@noindent's removed due to texi2roff-2 mm bug; if yours is newer, 
#   try leaving them in
gdb.mm: $(GDB_DOC_FILES) links2roff
	sed -e '/\\input texinfo/d' \
		-e '/@c TEXI2ROFF-KILL/,/@c END TEXI2ROFF-KILL/d' \
		-e '/^@ifinfo/,/^@end ifinfo/d' \
		-e '/^@c /d' \
		-e 's/{.*,,/{/' \
		-e '/@noindent/d' \
		-e 's/@ / /g' \
		-e 's/^@alphaenumerate/@enumerate/g' \
		-e 's/^@end alphaenumerate/@end enumerate/g' \
		$(srcdir)/gdb.texinfo | \
	$(TEXI2ROFF) -mm | \
	sed -e 's/---/\\(em/g' \
	>gdb.mm 

# GDB MANUAL: HTML file

gdb/index.html: ${GDB_DOC_FILES}
	$(MAKEHTML) $(MAKEHTMLFLAGS) $(READLINE_TEXI_INCFLAG) -I ${GDBMI_DIR} -I $(srcdir) $(srcdir)/gdb.texinfo

stabs.info: $(STABS_DOC_FILES)
	$(MAKEINFO_CMD) -I $(srcdir) -o stabs.info $(srcdir)/stabs.texinfo

# STABS DOCUMENTATION: HTML file

stabs/index.html: $(STABS_DOC_FILES)
	$(MAKEHTML) $(MAKEHTMLFLAGS) -I $(srcdir) $(srcdir)/stabs.texinfo

# Clean these up before each run.  Avoids a catch 22 with not being
# able to re-generate these files (to fix a corruption) because these
# files contain a corruption.
STABS_TEX_TMPS = stabs.aux stabs.cp* stabs.fn* stabs.ky* \
	stabs.log stabs.pg* stabs.toc stabs.tp* stabs.vr*

# STABS DOCUMENTATION: TeX dvi file
stabs.dvi : $(STABS_DOC_FILES)
	rm -f $(STABS_TEX_TMPS)
	$(TEXI2DVI) -I $(srcdir) $(srcdir)/stabs.texinfo

stabs.ps: stabs.dvi
	$(DVIPS) -o $@ $?

stabs.pdf: $(STABS_DOC_FILES)
	rm -f $(STABS_TEX_TMPS)
	$(TEXI2DVI) --pdf -I $(srcdir) $(srcdir)/stabs.texinfo

# Clean these up before each run.  Avoids a catch 22 with not being
# able to re-generate these files (to fix a corruption) because these
# files contain a corruption.
ANNOTATE_TEX_TMPS = annotate.aux annotate.cp* annotate.fn* annotate.ky* \
	annotate.log annotate.pg* annotate.toc annotate.tp* annotate.vr*

# ANNOTATE DOCUMENTATION: TeX dvi file
annotate.dvi : $(ANNOTATE_DOC_FILES)
	rm -f $(ANNOTATE_TEX_TMPS)
	$(TEXI2DVI) -I $(srcdir) $(srcdir)/annotate.texinfo

annotate.ps: annotate.dvi
	$(DVIPS) -o $@ $?

annotate.pdf: $(ANNOTATE_DOC_FILES)
	rm -f $(ANNOTATE_TEX_TMPS)
	$(TEXI2DVI) --pdf -I $(srcdir) $(srcdir)/annotate.texinfo

annotate.info: $(ANNOTATE_DOC_FILES)
	$(MAKEINFO_CMD) -I $(srcdir) -o annotate.info $(srcdir)/annotate.texinfo

annotate/index.html: $(ANNOTATE_DOC_FILES)
	$(MAKEHTML) $(MAKEHTMLFLAGS) -I $(srcdir) $(srcdir)/annotate.texinfo

# Man pages
gdb.1: $(GDB_DOC_FILES)
	touch $@
	-$(TEXI2POD) $(MANCONF) -Dgdb < $(srcdir)/gdb.texinfo > gdb.pod
	-($(POD2MAN1) gdb.pod | sed -e '/^.if n .na/d' > $@.T$$$$ && \
		mv -f $@.T$$$$ $@) || (rm -f $@.T$$$$ && exit 1)
	rm -f gdb.pod

gdbserver.1: $(GDB_DOC_FILES)
	touch $@
	-$(TEXI2POD) $(MANCONF) -Dgdbserver < $(srcdir)/gdb.texinfo > gdbserver.pod
	-($(POD2MAN1) gdbserver.pod | sed -e '/^.if n .na/d' > $@.T$$$$ && \
		mv -f $@.T$$$$ $@) || (rm -f $@.T$$$$ && exit 1)
	rm -f gdbserver.pod

gcore.1: $(GDB_DOC_FILES)
	touch $@
	-$(TEXI2POD) $(MANCONF) -Dgcore < $(srcdir)/gdb.texinfo > gcore.pod
	-($(POD2MAN1) gcore.pod | sed -e '/^.if n .na/d' > $@.T$$$$ && \
		mv -f $@.T$$$$ $@) || (rm -f $@.T$$$$ && exit 1)
	rm -f gcore.pod

gdbinit.5: $(GDB_DOC_FILES)
	touch $@
	-$(TEXI2POD) $(MANCONF) -Dgdbinit < $(srcdir)/gdb.texinfo > gdbinit.pod
	-($(POD2MAN5) gdbinit.pod | sed -e '/^.if n .na/d' > $@.T$$$$ && \
		mv -f $@.T$$$$ $@) || (rm -f $@.T$$$$ && exit 1)
	rm -f gdbinit.pod

force:

Makefile: Makefile.in $(host_makefile_frag) ../config.status
	cd .. && $(SHELL) ./config.status doc/Makefile


# The "least clean" level of cleaning.  Get rid of files which are
# automatically generated files that are just intermediate files,

mostlyclean:
	rm -f gdb.mm gdb.ms gdb.me links2roff
	rm -f $(GDB_TEX_TMPS)
	rm -f $(STABS_TEX_TMPS)
	rm -f $(ANNOTATE_TEX_TMPS)
	rm -f sedref.dvi sedref.tex tmp.sed
	rm -f version.subst

clean: mostlyclean
	rm -f gdb-cfg.texi GDBvn.texi

distclean: clean
	rm -f Makefile

# GDBvn.texi, the dvi files, the info files, and the postscript files, 
# are all part of the distribution, so it should not be removed by
# "clean" or "distclean".  Use maintainer-clean to remove them.

maintainer-clean realclean: distclean
	rm -f GDBvn.texi *.info* *.dvi *.ps *.html *.pdf $(MANS)

install: install-info install-man

uninstall: uninstall-info uninstall-man
