# Makefile for regression testing the GNU debugger.
# Copyright 1992-2017 Free Software Foundation, Inc.

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
exec_prefix = ${prefix}
abs_builddir = /workspace/gdb-7.12.1/gdb/testsuite
abs_srcdir = /workspace/gdb-7.12.1/gdb/testsuite

target_alias = mipsel-linux
program_transform_name = s,y,y,
build_canonical = x86_64-pc-linux-gnu
host_canonical = mipsel-unknown-linux-gnu
target_canonical = mipsel-unknown-linux-gnu

SHELL = /bin/bash
EXEEXT = 
SUBDIRS = 
RPATH_ENVVAR = RPATH_ENVVAR

EXTRA_RULES = 

CC=/opt/mipsel-buildroot-linux-gnu_sdk-buildroot/bin/mips-mti-linux-gnu-gcc

EXPECT = `if [ "$${READ1}" != "" ] ; then \
            echo $${rootme}/expect-read1; \
          elif [ -f $${rootme}/../../expect/expect ] ; then \
            echo $${rootme}/../../expect/expect ; \
          else \
            echo expect ; \
          fi`

RUNTEST = $(RUNTEST_FOR_TARGET)

RUNTESTFLAGS =

FORCE_PARALLEL =

# Default number of iterations that we will use to run the testsuite
# if the user does not specify the RACY_ITER environment variable
# (e.g., when the user calls the make rule directly from the command
# line).
DEFAULT_RACY_ITER = 3

RUNTEST_FOR_TARGET = `\
  if [ -f $${srcdir}/../../dejagnu/runtest ]; then \
    echo $${srcdir}/../../dejagnu/runtest; \
  else \
    if [ "$(host_canonical)" = "$(target_canonical)" ]; then \
      echo runtest; \
    else \
      t='$(program_transform_name)'; echo runtest | sed -e $$t; \
    fi; \
  fi`

#### host, target, and site specific Makefile frags come in here.

# The use of $$(x_FOR_TARGET) reduces the command line length by not
# duplicating the lengthy definition.

TARGET_FLAGS_TO_PASS = \
        "prefix=$(prefix)" \
        "exec_prefix=$(exec_prefix)" \
        "against=$(against)" \
        'CC=$$(CC_FOR_TARGET)' \
        "CC_FOR_TARGET=$(CC_FOR_TARGET)" \
        "CFLAGS=$(TESTSUITE_CFLAGS)" \
        'CXX=$$(CXX_FOR_TARGET)' \
        "CXX_FOR_TARGET=$(CXX_FOR_TARGET)" \
        "CXXFLAGS=$(CXXFLAGS)" \
        "MAKEINFO=$(MAKEINFO)" \
        "INSTALL=$(INSTALL)" \
        "INSTALL_PROGRAM=$(INSTALL_PROGRAM)" \
        "INSTALL_DATA=$(INSTALL_DATA)" \
        "LDFLAGS=$(LDFLAGS)" \
        "LIBS=$(LIBS)" \
        "RUNTEST=$(RUNTEST)" \
        "RUNTESTFLAGS=$(RUNTESTFLAGS)"

all: $(EXTRA_RULES)
	@echo "Nothing to be done for all..."

.NOEXPORT:
INFODIRS=doc
info:
install-info:
dvi:
pdf:
install-pdf:
html:
install-html:

install:

uninstall: force

# Use absolute `site.exp' path everywhere to suppress VPATH lookups for it.
# Bare `site.exp' is used as a target here if user requests it explicitly.
# $(RUNTEST) is looking up `site.exp' only in the current directory.

$(abs_builddir)/site.exp site.exp: ./config.status Makefile
	@echo "Making a new config file..."
	-@rm -f ./tmp?
	@touch site.exp
	-@mv site.exp site.bak
	@echo "## these variables are automatically generated by make ##" > ./tmp0
	@echo "# Do not edit here. If you wish to override these values" >> ./tmp0
	@echo "# add them to the last section" >> ./tmp0
	@echo "set host_triplet ${host_canonical}" >> ./tmp0
	@echo "set target_alias $(target_alias)" >> ./tmp0
	@echo "set target_triplet ${target_canonical}" >> ./tmp0
	@echo "set build_triplet ${build_canonical}" >> ./tmp0
	@echo "set srcdir ${abs_srcdir}" >> ./tmp0
	@echo "set tool gdb" >> ./tmp0
	@echo 'source $${srcdir}/lib/append_gdb_boards_dir.exp' >> ./tmp0
	@echo "## All variables above are generated by configure. Do Not Edit ##" >> ./tmp0
		@cat ./tmp0 > site.exp
	@cat site.bak | sed \
			-e '1,/^## All variables above are.*##/ d' >> site.exp
	-@rm -f ./tmp?

installcheck:

# See whether -j was given to make.  Either it was given with no
# arguments, and appears as "j" in the first word, or it was given an
# argument and appears as "-j" in a separate word.
saw_dash_j = $(or $(findstring j,$(firstword $(MAKEFLAGS))),$(filter -j,$(MAKEFLAGS)))

# For GNU make, try to run the tests in parallel if any -j option is
# given.  If RUNTESTFLAGS is not empty, then by default the tests will
# be serialized.  This can be overridden by setting FORCE_PARALLEL to
# any non-empty value.  For a non-GNU make, do not parallelize.
CHECK_TARGET_TMP = $(if $(FORCE_PARALLEL),check-parallel,$(if $(RUNTESTFLAGS),check-single,$(if $(saw_dash_j),check-parallel,check-single)))
CHECK_TARGET = $(if $(RACY_ITER),$(addsuffix -racy,$(CHECK_TARGET_TMP)),$(CHECK_TARGET_TMP))
#CHECK_TARGET = check-single

# Note that we must resort to a recursive make invocation here,
# because GNU make 3.82 has a bug preventing MAKEFLAGS from being used
# in conditions.
check: all $(abs_builddir)/site.exp
	$(MAKE) $(CHECK_TARGET)

check-read1:
	$(MAKE) READ1="1" check

# All the hair to invoke dejagnu.  A given invocation can just append
# $(RUNTESTFLAGS)
DO_RUNTEST = \
	rootme=`pwd`; export rootme; \
	srcdir=${srcdir} ; export srcdir ; \
	EXPECT=${EXPECT} ; export EXPECT ; \
	EXEEXT=${EXEEXT} ; export EXEEXT ; \
        $(RPATH_ENVVAR)=$$rootme/../../expect:$$rootme/../../libstdc++:$$rootme/../../tk/unix:$$rootme/../../tcl/unix:$$rootme/../../bfd:$$rootme/../../opcodes:$$$(RPATH_ENVVAR); \
	export $(RPATH_ENVVAR); \
	if [ -f $${rootme}/../../expect/expect ] ; then  \
	  TCL_LIBRARY=$${srcdir}/../../tcl/library ; \
	  export TCL_LIBRARY ; fi ; \
	$(RUNTEST) --status

# TESTS exists for the user to pass on the command line to easily
# say "Only run these tests."  With check-single it's not necessary, but
# with check-parallel there's no other way to (easily) specify a subset
# of tests.  For consistency we support it for check-single as well.
# To specify all tests in a subdirectory, use TESTS=gdb.subdir/*.exp.
# E.g., make check TESTS="gdb.server/*.exp gdb.threads/*.exp".
TESTS :=
#TESTS =

ifeq ($(strip $(TESTS)),)
expanded_tests_or_none :=
else
expanded_tests := $(patsubst $(srcdir)/%,%,$(wildcard $(addprefix $(srcdir)/,$(TESTS))))
expanded_tests_or_none := $(or $(expanded_tests),no-matching-tests-found)
endif
#expanded_tests_or_none = $(TESTS)

# Shorthand for running all the tests in a single directory.
check-gdb.%:
	$(MAKE) check TESTS="gdb.$*/*.exp"

check-single:
	$(DO_RUNTEST) $(RUNTESTFLAGS) $(expanded_tests_or_none)

check-single-racy:
	-rm -rf cache racy_outputs temp
	mkdir -p racy_outputs; \
	racyiter="$(RACY_ITER)"; \
	test "x$$racyiter" == "x" && \
	  racyiter=$(DEFAULT_RACY_ITER); \
	if test $$racyiter -lt 2 ; then \
	  echo "RACY_ITER must be at least 2."; \
	  exit 1; \
	fi; \
	trap "exit" INT; \
	for n in `seq $$racyiter` ; do \
	  mkdir -p racy_outputs/$$n; \
	  $(DO_RUNTEST) --outdir=racy_outputs/$$n $(RUNTESTFLAGS) \
	    $(expanded_tests_or_none); \
	done; \
	$(srcdir)/analyze-racy-logs.py \
	  `ls racy_outputs/*/gdb.sum` > racy.sum; \
	sed -n '/=== gdb Summary ===/,$$ p' racy.sum

check-parallel:
	-rm -rf cache outputs temp
	$(MAKE) -k do-check-parallel; \
	result=$$?; \
	$(SHELL) $(srcdir)/dg-extract-results.sh \
	  `find outputs -name gdb.sum -print` > gdb.sum; \
	$(SHELL) $(srcdir)/dg-extract-results.sh -L \
	  `find outputs -name gdb.log -print` > gdb.log; \
	sed -n '/=== gdb Summary ===/,$$ p' gdb.sum; \
	exit $$result

check-parallel-racy:
	-rm -rf cache racy_outputs temp
	racyiter="$(RACY_ITER)"; \
	test "x$$racyiter" == "x" && \
	  racyiter=$(DEFAULT_RACY_ITER); \
	if test $$racyiter -lt 2 ; then \
	  echo "RACY_ITER must be at least 2."; \
	  exit 1; \
	fi; \
	trap "exit" INT; \
	for n in `seq $$racyiter` ; do \
	  $(MAKE) -k do-check-parallel-racy \
	    RACY_OUTPUT_N=$$n; \
	  $(SHELL) $(srcdir)/dg-extract-results.sh \
	    `find racy_outputs/$$n -name gdb.sum -print` > \
	    racy_outputs/$$n/gdb.sum; \
	  $(SHELL) $(srcdir)/dg-extract-results.sh -L \
	    `find racy_outputs/$$n -name gdb.log -print` > \
	    racy_outputs/$$n/gdb.log; \
	  sed -n '/=== gdb Summary ===/,$$ p' racy_outputs/$$n/gdb.sum; \
	done; \
	$(srcdir)/analyze-racy-logs.py \
	  `ls racy_outputs/*/gdb.sum` > racy.sum; \
	sed -n '/=== gdb Summary ===/,$$ p' racy.sum

# Turn a list of .exp files into "check/" targets.  Only examine .exp
# files appearing in a gdb.* directory -- we don't want to pick up
# lib/ by mistake.  For example, gdb.linespec/linespec.exp becomes
# check/gdb.linespec/linespec.exp.  The list is generally sorted
# alphabetically, but we take a few tests known to be slow and push
# them to the front of the list to try to lessen the overall time
# taken by the test suite -- if one of these tests happens to be run
# late, it will cause the overall time to increase.
ifeq ($(strip $(TESTS)),)
slow_tests = gdb.base/break-interp.exp gdb.base/interp.exp \
	gdb.base/multi-forks.exp
all_tests := $(shell cd $(srcdir) && find gdb.* -name '*.exp' -print)
reordered_tests := $(slow_tests) $(filter-out $(slow_tests),$(all_tests))
TEST_TARGETS := $(addprefix $(if $(RACY_ITER),check-racy,check)/,$(reordered_tests))
else
TEST_TARGETS := $(addprefix $(if $(RACY_ITER),check-racy,check)/,$(expanded_tests_or_none))
endif

do-check-parallel: $(TEST_TARGETS)
	@:

check/%.exp:
	-mkdir -p outputs/$*
	@$(DO_RUNTEST) GDB_PARALLEL=yes --outdir=outputs/$* $*.exp $(RUNTESTFLAGS)

do-check-parallel-racy: $(TEST_TARGETS)
	@:

check-racy/%.exp:
	-mkdir -p racy_outputs/$(RACY_OUTPUT_N)/$*
	$(DO_RUNTEST) GDB_PARALLEL=yes \
	  --outdir=racy_outputs/$(RACY_OUTPUT_N)/$* $*.exp \
	  $(RUNTESTFLAGS)

check/no-matching-tests-found:
	@echo ""
	@echo "No matching tests found."
	@echo ""

# Utility rule invoked by step 2 of the build-perf rule.
workers/%.worker:
	mkdir -p gdb.perf/outputs/$*
	$(DO_RUNTEST) --outdir=gdb.perf/outputs/$* lib/build-piece.exp WORKER=$* GDB_PARALLEL=gdb.perf $(RUNTESTFLAGS) GDB_PERFTEST_MODE=compile GDB_PERFTEST_SUBMODE=build-pieces

# Utility rule to build tests that support it in parallel.
# The build is broken into 3 steps distinguished by GDB_PERFTEST_SUBMODE:
# gen-workers, build-pieces, final.
#
# GDB_PERFTEST_MODE appears *after* RUNTESTFLAGS here because we don't want
# anything in RUNTESTFLAGS to override it.
#
# We don't delete the outputs directory here as these programs can take
# awhile to build, and perftest.exp has support for deciding whether to
# recompile them.  If you want to remove these directories, make clean.
#
# The point of step 1 is to construct the set of worker tasks for step 2.
# All of the information needed by build-piece.exp is contained in the name
# of the generated .worker file.
build-perf: $(abs_builddir)/site.exp
	rm -rf gdb.perf/workers
	mkdir -p gdb.perf/workers
	@: Step 1: Generate the build .worker files.
	$(DO_RUNTEST) --directory=gdb.perf --outdir gdb.perf/workers GDB_PARALLEL=gdb.perf $(RUNTESTFLAGS) GDB_PERFTEST_MODE=compile GDB_PERFTEST_SUBMODE=gen-workers
	@: Step 2: Compile the pieces.  Here is the build parallelism.
	$(MAKE) $$(cd gdb.perf && echo workers/*/*.worker)
	@: Step 3: Do the final link.
	$(DO_RUNTEST) --directory=gdb.perf --outdir gdb.perf GDB_PARALLEL=gdb.perf $(RUNTESTFLAGS) GDB_PERFTEST_MODE=compile GDB_PERFTEST_SUBMODE=final

# The default is to both compile and run the tests.
GDB_PERFTEST_MODE = both

check-perf: all $(abs_builddir)/site.exp
	@if test ! -d gdb.perf; then mkdir gdb.perf; fi
	$(DO_RUNTEST) --directory=gdb.perf --outdir gdb.perf GDB_PERFTEST_MODE=$(GDB_PERFTEST_MODE) $(RUNTESTFLAGS)

force:;

clean mostlyclean:
	-rm -f *~ core *.o a.out xgdb *.x *.grt bigcore.corefile .gdb_history
	-rm -f core.* *.tf *.cl tracecommandsscript copy1.txt zzz-gdbscript
	-rm -f *.dwo *.dwp
	-rm -rf outputs temp cache
	-rm -rf gdb.perf/workers gdb.perf/outputs gdb.perf/temp gdb.perf/cache
	-rm -f read1.so expect-read1

distclean maintainer-clean realclean: clean
	-rm -f *~ core
	-rm -f Makefile config.status *-init.exp
	-rm -fr *.log summary detail *.plog *.sum *.psum site.*

Makefile : Makefile.in config.status $(host_makefile_frag)
	$(SHELL) config.status

config.status: configure
	$(SHELL) config.status --recheck

TAGS: force
	find $(srcdir) -name '*.exp' -print | \
	    etags --regex='/proc[ \t]+\([^ \t]+\)/\1/' -

# Build the expect wrapper script that preloads the read1.so library.
expect-read1:
	@echo Making expect-read1
	@rm -f expect-read1-tmp
	@touch expect-read1-tmp
	@echo "# THIS FILE IS GENERATED -*- buffer-read-only: t -*- \n" >>expect-read1-tmp
	@echo "# vi:set ro: */\n\n" >>expect-read1-tmp
	@echo "# To regenerate this file, run:\n" >>expect-read1-tmp
	@echo "#      make clean; make/\n" >>expect-read1-tmp
	@echo "export LD_PRELOAD=`pwd`/read1.so" >>expect-read1-tmp
	@echo 'exec expect "$$@"' >>expect-read1-tmp
	@chmod +x expect-read1-tmp
	@mv expect-read1-tmp expect-read1

# Build the read1.so preload library.  This overrides the `read'
# function, making it read one byte at a time.  Running the testsuite
# with this catches racy tests.
read1.so: lib/read1.c
	$(CC) -o $@ ${srcdir}/lib/read1.c -Wall -g -shared -fPIC $(CFLAGS)

# Build the read1 machinery.
.PHONY: read1
read1: read1.so expect-read1
