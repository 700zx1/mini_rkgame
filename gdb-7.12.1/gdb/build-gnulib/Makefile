# Copyright (C) 1989-2017 Free Software Foundation, Inc.

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

prefix = /workspace/gdb-mipsel-static
exec_prefix = ${prefix}

host_alias = mipsel-linux
target_alias = mipsel-linux
program_transform_name = s,y,y,
bindir = ${exec_prefix}/bin
libdir = ${exec_prefix}/lib
tooldir = $(libdir)/$(target_alias)

datadir = ${datarootdir}
localedir = ${datarootdir}/locale
mandir = ${datarootdir}/man
man1dir = $(mandir)/man1
man2dir = $(mandir)/man2
man3dir = $(mandir)/man3
man4dir = $(mandir)/man4
man5dir = $(mandir)/man5
man6dir = $(mandir)/man6
man7dir = $(mandir)/man7
man8dir = $(mandir)/man8
man9dir = $(mandir)/man9
infodir = ${datarootdir}/info
datarootdir = ${prefix}/share
docdir = ${datarootdir}/doc/${PACKAGE}
htmldir = ${docdir}
pdfdir = ${docdir}
includedir = ${prefix}/include

SHELL = /bin/bash
EXEEXT = 

INSTALL = /usr/bin/install -c
INSTALL_PROGRAM = /usr/bin/install -c
INSTALL_DATA = /usr/bin/install -c -m 644

DESTDIR =

AR = /opt/mipsel-buildroot-linux-gnu_sdk-buildroot/bin/mips-mti-linux-gnu-ar
AR_FLAGS = qv
RANLIB = /opt/mipsel-buildroot-linux-gnu_sdk-buildroot/bin/mips-mti-linux-gnu-ranlib
DLLTOOL = @DLLTOOL@

SUBDIRS = import
CLEANDIRS = $(SUBDIRS)
REQUIRED_SUBDIRS = $(SUBDIRS)

# If you are compiling with GCC, make sure that either 1) You have the
# fixed include files where GCC can reach them, or 2) You use the
# -traditional flag.  Otherwise the ioctl calls in inflow.c
# will be incorrectly compiled.  The "fixincludes" script in the gcc
# distribution will fix your include files up.
CC=/opt/mipsel-buildroot-linux-gnu_sdk-buildroot/bin/mips-mti-linux-gnu-gcc

# Directory containing source files.
srcdir = .././gnulib
VPATH = .././gnulib

CC_LD=$(CC)

# CFLAGS is specifically reserved for setting from the command line
# when running make.  I.E.  "make CFLAGS=-Wmissing-prototypes".
CFLAGS = -O2 -march=mips32r2

# LDFLAGS is specifically reserved for setting from the command line
# when running make.
LDFLAGS = -static-libstdc++ -static-libgcc 

FLAGS_TO_PASS = \
	"prefix=$(prefix)" \
	"exec_prefix=$(exec_prefix)" \
	"infodir=$(infodir)" \
	"datarootdir=$(datarootdir)" \
	"docdir=$(docdir)" \
	"htmldir=$(htmldir)" \
	"pdfdir=$(pdfdir)" \
	"libdir=$(libdir)" \
	"mandir=$(mandir)" \
	"datadir=$(datadir)" \
	"includedir=$(includedir)" \
	"against=$(against)" \
	"DESTDIR=$(DESTDIR)" \
	"AR=$(AR)" \
	"AR_FLAGS=$(AR_FLAGS)" \
	"CC=$(CC)" \
	"CFLAGS=$(CFLAGS)" \
	"CXX=$(CXX)" \
	"CXXFLAGS=$(CXXFLAGS)" \
	"DLLTOOL=$(DLLTOOL)" \
	"LDFLAGS=$(LDFLAGS)" \
	"RANLIB=$(RANLIB)" \
	"MAKEINFO=$(MAKEINFO)" \
	"MAKEINFOFLAGS=$(MAKEINFOFLAGS)" \
	"MAKEINFO_EXTRA_FLAGS=$(MAKEINFO_EXTRA_FLAGS)" \
	"MAKEHTML=$(MAKEHTML)" \
	"MAKEHTMLFLAGS=$(MAKEHTMLFLAGS)" \
	"INSTALL=$(INSTALL)" \
	"INSTALL_PROGRAM=$(INSTALL_PROGRAM)" \
	"INSTALL_DATA=$(INSTALL_DATA)" \
	"RUNTEST=$(RUNTEST)" \
	"RUNTESTFLAGS=$(RUNTESTFLAGS)"

all installcheck check info install-info clean-info dvi pdf install-pdf html install-html: force
	@$(MAKE) $(FLAGS_TO_PASS) DO=$@ "DODIRS=$(SUBDIRS)" subdir_do

# Traditionally "install" depends on "all".  But it may be useful
# not to; for example, if the user has made some trivial change to a
# source file and doesn't care about rebuilding or just wants to save the
# time it takes for make to check that all is up to date.
# install-only is intended to address that need.
install: all
	@$(MAKE) $(FLAGS_TO_PASS) install-only

install-only: $(CONFIG_INSTALL)
	@$(MAKE) DO=install "DODIRS=$(SUBDIRS)" $(FLAGS_TO_PASS) subdir_do

uninstall: force $(CONFIG_UNINSTALL)
	@$(MAKE) DO=uninstall "DODIRS=$(SUBDIRS)" $(FLAGS_TO_PASS) subdir_do

# Convenience rule to handle recursion.
$(LIBGNU) $(GNULIB_H): all-lib
all-lib: import/Makefile
	@$(MAKE) $(FLAGS_TO_PASS) DO=all DODIRS=import subdir_do
.PHONY: all-lib

clean mostlyclean: $(CONFIG_CLEAN)
	@$(MAKE) $(FLAGS_TO_PASS) DO=clean "DODIRS=$(CLEANDIRS)" subdir_do

distclean: clean
	@$(MAKE) $(FLAGS_TO_PASS) DO=distclean "DODIRS=$(CLEANDIRS)" subdir_do
	rm -f config.status config.h stamp-h
	rm -f config.log config.cache
	rm -f Makefile
	rm -rf $(DEPDIR)

maintainer-clean: local-maintainer-clean do-maintainer-clean distclean
realclean: maintainer-clean

local-maintainer-clean:
	@echo "This command is intended for maintainers to use;"
	@echo "it deletes files that may require special tools to rebuild."
	rm -f config.status

do-maintainer-clean:
	@$(MAKE) $(FLAGS_TO_PASS) DO=maintainer-clean "DODIRS=$(CLEANDIRS)" \
		subdir_do

subdir_do: force
	@for i in $(DODIRS); do \
		case $$i in \
		$(REQUIRED_SUBDIRS)) \
			if [ ! -f ./$$i/Makefile ] ; then \
				echo "Missing $$i/Makefile" >&2 ; \
				exit 1 ; \
			fi ;; \
		esac ; \
		if [ -f ./$$i/Makefile ] ; then \
			if (cd ./$$i; \
				$(MAKE) $(FLAGS_TO_PASS) $(DO)) ; then true ; \
			else exit 1 ; fi ; \
		else true ; fi ; \
	done

Makefile: Makefile.in config.status
	# Regenerate the Makefile.
	CONFIG_FILES="Makefile" \
	  CONFIG_COMMANDS= \
	  CONFIG_HEADERS= \
	  $(SHELL) config.status

gnulib/Makefile: gnulib/Makefile.in config.status
	CONFIG_FILES="gnulib/Makefile" \
	  CONFIG_COMMANDS="depfiles" \
	  CONFIG_HEADERS= \
	  CONFIG_LINKS= \
	  $(SHELL) config.status

config.h: stamp-h ; @true
stamp-h: $(srcdir)/config.in config.status
	CONFIG_HEADERS=config.h:config.in \
	  CONFIG_COMMANDS="default depdir" \
	  CONFIG_FILES= \
	  CONFIG_LINKS= \
	  $(SHELL) config.status

config.status: $(srcdir)/configure
	$(SHELL) config.status --recheck

ACLOCAL = aclocal
ACLOCAL_AMFLAGS = -I import/m4 -I ../../config
aclocal_m4_deps = \
	configure.ac \
	import/m4/00gnulib.m4 \
	import/m4/alloca.m4 \
	import/m4/codeset.m4 \
	import/m4/configmake.m4 \
	import/m4/extensions.m4 \
	import/m4/fcntl-o.m4 \
	import/m4/fnmatch.m4 \
	import/m4/glibc21.m4 \
	import/m4/gnulib-cache.m4 \
	import/m4/gnulib-common.m4 \
	import/m4/gnulib-comp.m4 \
	import/m4/gnulib-tool.m4 \
	import/m4/include_next.m4 \
	import/m4/inttypes-pri.m4 \
	import/m4/inttypes.m4 \
	import/m4/localcharset.m4 \
	import/m4/locale-fr.m4 \
	import/m4/locale-ja.m4 \
	import/m4/locale-zh.m4 \
	import/m4/longlong.m4 \
	import/m4/mbrtowc.m4 \
	import/m4/mbsinit.m4 \
	import/m4/mbsrtowcs.m4 \
	import/m4/mbstate_t.m4 \
	import/m4/memchr.m4 \
	import/m4/memmem.m4 \
	import/m4/mmap-anon.m4 \
	import/m4/multiarch.m4 \
	import/m4/off_t.m4 \
	import/m4/pathmax.m4 \
	import/m4/ssize_t.m4 \
	import/m4/stdbool.m4 \
	import/m4/stddef_h.m4 \
	import/m4/stdint.m4 \
	import/m4/string_h.m4 \
	import/m4/strtok_r.m4 \
	import/m4/sys_types_h.m4 \
	import/m4/unistd_h.m4 \
	import/m4/warn-on-use.m4 \
	import/m4/wchar_h.m4 \
	import/m4/wchar_t.m4 \
	import/m4/wctype_h.m4 \
	import/m4/wint_t.m4

$(srcdir)/aclocal.m4: # $(aclocal_m4_deps)
	cd $(srcdir) && $(ACLOCAL) $(ACLOCAL_AMFLAGS)

AUTOCONF = autoconf
configure_deps = $(srcdir)/configure.ac $(srcdir)/aclocal.m4
$(srcdir)/configure: # $(configure_deps)
	cd $(srcdir) && $(AUTOCONF)

AUTOHEADER = autoheader
$(srcdir)/config.in: # $(configure_deps)
	cd $(srcdir) && $(AUTOHEADER)
	rm -f stamp-h
	touch $@

# automatic rebuilding in automake-generated Makefiles requires
# this rule in the toplevel Makefile, which, with GNU make, causes
# the desired updates through the implicit regeneration of the Makefile
# and all of its prerequisites.
am--refresh:
	@:

force:

force_update:

# GNU Make has an annoying habit of putting *all* the Makefile variables
# into the environment, unless you include this target as a circumvention.
# Rumor is that this will be fixed (and this target can be removed)
# in GNU Make 4.0.
.NOEXPORT:

# GNU Make 3.63 has a different problem: it keeps tacking command line
# overrides onto the definition of $(MAKE).  This variable setting
# will remove them.
MAKEOVERRIDES=

### end of the libgnu Makefile.in.
