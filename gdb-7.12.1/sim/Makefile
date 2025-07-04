#    Makefile template for Configure for the sim library.
#    Copyright (C) 1993-2017 Free Software Foundation, Inc.
#    Written by Cygnus Support.
# 
# This file is part of BFD, the Binary File Descriptor library.
# 
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
exec_prefix = ${prefix}

host_alias = mipsel-linux
target_alias = mipsel-linux
program_transform_name = s,y,y,
bindir = ${exec_prefix}/bin
libdir = ${exec_prefix}/lib
tooldir = $(libdir)/$(target_alias)

datarootdir = ${prefix}/share
datadir = ${datarootdir}
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
includedir = ${prefix}/include

SHELL = /bin/bash

INSTALL = /usr/bin/install -c
INSTALL_PROGRAM = /usr/bin/install -c
INSTALL_DATA = /usr/bin/install -c -m 644

AR = /opt/mipsel-buildroot-linux-gnu_sdk-buildroot/bin/mips-mti-linux-gnu-ar
AR_FLAGS = rc
CC = /opt/mipsel-buildroot-linux-gnu_sdk-buildroot/bin/mips-mti-linux-gnu-gcc
CFLAGS = -O2 -march=mips32r2
CC_FOR_BUILD = gcc
CFLAGS_FOR_BUILD = 
MAKEINFO = makeinfo
RANLIB = /opt/mipsel-buildroot-linux-gnu_sdk-buildroot/bin/mips-mti-linux-gnu-ranlib

SUBDIRS =  mips testsuite igen

INCDIR = $(srcdir)/../include
CSEARCH = -I. -I$(srcdir) -I$(INCDIR)
DEP = mkdep

#### Makefile fragments come in here.
# @target_makefile_frag@
###

# Name of the ChangeLog file.
ChangeLog = ChangeLog


RUNTEST = `if [ -f $${srcdir}/../dejagnu/runtest ] ; then \
		echo $${srcdir}/../dejagnu/runtest ; else echo runtest; \
	   fi`
RUNTESTFLAGS=

FLAGS_TO_PASS = \
	"prefix=$(prefix)" \
	"exec_prefix=$(exec_prefix)" \
	"bindir=$(bindir)" \
	"mandir=$(mandir)" \
	"libdir=$(libdir)" \
	"against=$(against)" \
	"AR=$(AR)" \
	"AR_FLAGS=$(AR_FLAGS)" \
	"CC=$(CC)" \
	"CC_FOR_BUILD=$(CC_FOR_BUILD)" \
	"CFLAGS=$(CFLAGS)" \
	"CFLAGS_FOR_BUILD=$(CFLAGS_FOR_BUILD)" \
	"RANLIB=$(RANLIB)" \
	"MAKEINFO=$(MAKEINFO)" \
	"INSTALL=$(INSTALL)" \
	"INSTALL_DATA=$(INSTALL_DATA)" \
	"INSTALL_PROGRAM=$(INSTALL_PROGRAM)" \
	"RUNTEST=$(RUNTEST)" \
	"RUNTESTFLAGS=$(RUNTESTFLAGS)" \
	"SHELL=$(SHELL)"

# The use of $$(x_FOR_TARGET) reduces the command line length by not
# duplicating the lengthy definition.
TARGET_FLAGS_TO_PASS = \
	"prefix=$(prefix)" \
	"exec_prefix=$(exec_prefix)" \
	"against=$(against)" \
	'CC=$$(CC_FOR_TARGET)' \
	"CC_FOR_TARGET=$(CC_FOR_TARGET)" \
	"CFLAGS=$(CFLAGS)" \
	"CHILLFLAGS=$(CHILLFLAGS)" \
	'CHILL=$$(CHILL_FOR_TARGET)' \
	"CHILL_FOR_TARGET=$(CHILL_FOR_TARGET)" \
	"CHILL_LIB=$(CHILL_LIB)" \
	'CXX=$$(CXX_FOR_TARGET)' \
	"CXX_FOR_TARGET=$(CXX_FOR_TARGET)" \
	"CXXFLAGS=$(CXXFLAGS)" \
	"INSTALL=$(INSTALL)" \
	"INSTALL_PROGRAM=$(INSTALL_PROGRAM)" \
	"INSTALL_DATA=$(INSTALL_DATA)" \
	"MAKEINFO=$(MAKEINFO)" \
	"RUNTEST=$(RUNTEST)" \
	"RUNTESTFLAGS=$(RUNTESTFLAGS)"


all:
	@rootme=`pwd` ; export rootme ; \
	for dir in . `echo ${SUBDIRS} | sed 's/testsuite//'` ; do \
		if [ "$$dir" = "." ]; then \
			true; \
		elif [ -d $$dir ]; then \
			(cd $$dir; $(MAKE) $(FLAGS_TO_PASS)) || exit 1; \
		else true; fi; \
	done

clean mostlyclean:
	@rootme=`pwd` ; export rootme ; \
	for dir in . ${SUBDIRS}; do \
		if [ "$$dir" = "." ]; then \
			true; \
		elif [ -d $$dir ]; then \
			(cd $$dir; $(MAKE) $(FLAGS_TO_PASS) $@) || exit 1; \
		else true; fi; \
	done

distclean maintainer-clean realclean:
	@rootme=`pwd` ; export rootme ; \
	for dir in . ${SUBDIRS}; do \
		if [ "$$dir" = "." ]; then \
			true; \
		elif [ -d $$dir ]; then \
			(cd $$dir; $(MAKE) $(FLAGS_TO_PASS) $@) || exit 1; \
		else true; fi; \
	done
	rm -f Makefile config.cache config.log config.status

install:
	@rootme=`pwd` ; export rootme ; \
	for dir in . ${SUBDIRS}; do \
		if [ "$$dir" = "." ]; then \
			true; \
		elif [ -d $$dir ]; then \
			(cd $$dir; $(MAKE) $(FLAGS_TO_PASS) install) || exit 1; \
		else true; fi; \
	done

installcheck:
	@echo No installcheck target is available yet for the GNU simulators.

installcheck:

# The check target can not use subdir_do, because subdir_do does not
# use TARGET_FLAGS_TO_PASS.
check: force
	@if [ -f testsuite/Makefile ]; then \
	  rootme=`pwd`; export rootme; \
	  rootsrc=`cd $(srcdir); pwd`; export rootsrc; \
	  cd testsuite; \
	  $(MAKE) $(TARGET_FLAGS_TO_PASS) check; \
	else true; fi



info:
install-info:
dvi:
pdf:
install-pdf:
html:
install-html:

### 
### 

.NOEXPORT:
MAKEOVERRIDES=

.PHONY: check installcheck
check:
installcheck:

TAGS:

force:

Makefile: Makefile.in config.status
	$(SHELL) ./config.status

config.status: configure
	$(SHELL) ./config.status --recheck

# Utility to run autoconf in each directory that uses the common framework.
# This is intended to be invoked in $srcdir as
# "make -f Makefile.in autoconf-common SHELL=/bin/sh".
.PHONY: autoconf-common autoheader-common
autoconf-common autoheader-common:
	for d in * ; \
	do \
	    if [ -d $$d -a -f $$d/configure.ac ] ; \
	    then \
		 echo "Running autoconf in $$d ..." ; \
		 (cd $$d && autoconf --force) ; \
		 if [ $@ = autoheader-common ] && [ -f $$d/config.in ] ; \
		 then \
		   echo "Running autoheader in $$d ..." ; \
		   (cd $$d && autoheader --force) ; \
		 fi ; \
	    fi ; \
	done

autoconf-changelog autoheader-changelog:
	id=$(ID) ; \
	test x$$id = x && id="`id | sed -e 's/^[^(]*(\([^)]*\).*$$/\1/'`" ; \
	name=$(NAME) ; \
	test x$$name = x && name=`grep "^$$id:" /etc/passwd | cut -f 5 -d ':'` ; \
	host=$(HOST) ; \
	test x$$host = x && host="`hostname`" ; \
	date=$(DATE) ; \
	test x$$date = x && date="`date +%Y-%m-%d`" ; \
	echo "$$date $$name $$id@$$host" ; \
	for d in * ; \
	do \
	    if [ -d $$d -a -f $$d/configure.ac ] ; \
	    then \
		 echo "Creating new-$(ChangeLog) in $$d ..." ; \
		 ( echo "$$date  $$name  <$$id@$$host>" ; \
		   echo "" ; \
		   echo "	* configure: Regenerated to track ../common/aclocal.m4 changes." ; \
		   if [ $@ = autoheader-changelog ] ; \
		   then \
		     echo "	* config.in: Ditto." ; \
		   fi ; \
		   echo "" ; \
		   cat $$d/$(ChangeLog) \
		 ) > $$d/new-$(ChangeLog) ; \
	    fi ; \
	done

autoconf-install autoheader-install:
	for d in * ; \
	do \
	    if [ -d $$d -a -f $$d/configure.ac ] ; \
	    then \
		 echo "Moving $$d/new-$(ChangeLog) to $$d/$(ChangeLog) ..." ; \
		 mv $$d/new-$(ChangeLog) $$d/$(ChangeLog) ; \
	    fi ; \
	done
