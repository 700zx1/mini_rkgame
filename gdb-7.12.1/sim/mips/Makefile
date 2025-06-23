#    Makefile template for Configure for the MIPS simulator.
#    Written by Cygnus Support.

SHELL = /bin/bash

## COMMON_PRE_CONFIG_FRAG
## COMMON_PRE_CONFIG_FRAG

VPATH = $(srccom)
srcdir = .
srccom = $(srcdir)/../common
srcroot = $(srcdir)/../..
srcsim = $(srcdir)/..

prefix = /workspace/gdb-mipsel-static
exec_prefix = ${prefix}

host_alias = mipsel-linux
target_alias = mipsel-linux
program_transform_name = s,y,y,
bindir = ${exec_prefix}/bin

libdir = ${exec_prefix}/lib
tooldir = $(libdir)/$(target_alias)

datadir = ${datarootdir}
datarootdir = ${prefix}/share
mandir = ${datarootdir}/man
man1dir = $(mandir)/man1
infodir = ${datarootdir}/info
includedir = ${prefix}/include

lt_cv_dlopen_libs = 
# This can be referenced by the gettext configuration code.
top_builddir = ..

EXEEXT = 
SHELL = /bin/bash

INSTALL = /usr/bin/install -c
INSTALL_PROGRAM = /usr/bin/install -c
INSTALL_DATA = /usr/bin/install -c -m 644

CC = /opt/mipsel-buildroot-linux-gnu_sdk-buildroot/bin/mips-mti-linux-gnu-gcc
CC_FOR_BUILD = gcc
CFLAGS = -O2 -march=mips32r2
CPPFLAGS = 
CXXFLAGS = @CXXFLAGS@
LDFLAGS = -static-libstdc++ -static-libgcc 

SIM_ALIGNMENT = -DWITH_ALIGNMENT=NONSTRICT_ALIGNMENT
SIM_BITSIZE =  -DWITH_TARGET_WORD_BITSIZE=32 -DWITH_TARGET_WORD_MSB=31
SIM_DEFAULT_MODEL = 
SIM_ENDIAN = -DWITH_DEFAULT_TARGET_BYTE_ORDER=BFD_ENDIAN_BIG
SIM_FLOAT = -DWITH_FLOATING_POINT=HARD_FLOATING_POINT -DWITH_TARGET_FLOATING_POINT_BITSIZE=32
SIM_HW_CFLAGS = -DWITH_HW=0
SIM_HW_OBJS = 
SIM_HW = 
SIM_INLINE = -DDEFAULT_INLINE=0
SIM_RESERVED_BITS = -DWITH_RESERVED_BITS=1
SIM_SCACHE = 
WARN_CFLAGS =  -Wall -Wdeclaration-after-statement -Wpointer-arith -Wpointer-sign -Wno-unused -Wunused-value -Wunused-function -Wno-switch -Wno-char-subscripts -Wmissing-prototypes -Wdeclaration-after-statement -Wempty-body -Wmissing-parameter-type -Wold-style-declaration -Wold-style-definition -Wformat-nonliteral
WERROR_CFLAGS = 
SIM_WARN_CFLAGS = $(WARN_CFLAGS)
SIM_WERROR_CFLAGS = $(WERROR_CFLAGS)

HDEFINES = 
TDEFINES =

AR = /opt/mipsel-buildroot-linux-gnu_sdk-buildroot/bin/mips-mti-linux-gnu-ar
AR_FLAGS = rc
RANLIB = /opt/mipsel-buildroot-linux-gnu_sdk-buildroot/bin/mips-mti-linux-gnu-ranlib
MAKEINFO = makeinfo

# Dependency tracking information.
DEPMODE = depmode=gcc3
DEPDIR = .deps
depcomp = $(SHELL) $(srcroot)/depcomp

# Note that these are overridden by GNU make-specific code below if
# GNU make is used.  The overrides implement dependency tracking.
COMPILE.pre = $(CC)
COMPILE.post = -c -o $@
COMPILE = $(COMPILE.pre) $(ALL_CFLAGS) $(COMPILE.post)
POSTCOMPILE = @true

# Each simulator's Makefile.in defines one or more of these variables
# to override our settings as necessary.  There is no need to define these
# in the simulator's Makefile.in if one is using the default value.  In fact
# it's preferable not to.

# List of object files, less common parts.
SIM_OBJS =
# List of extra dependencies.
# Generally this consists of simulator specific files included by sim-main.h.
SIM_EXTRA_DEPS =
# List of flags to always pass to $(CC).
SIM_EXTRA_CFLAGS =
# List of extra libraries to link with.
SIM_EXTRA_LIBS =
# List of extra program dependencies.
SIM_EXTRA_LIBDEPS =
# List of main object files for `run'.
SIM_RUN_OBJS = nrun.o
# Dependency of `all' to build any extra files.
SIM_EXTRA_ALL =
# Dependency of `install' to install any extra files.
SIM_EXTRA_INSTALL =
# Dependency of `clean' to clean any extra files.
SIM_EXTRA_CLEAN =
# Likewise `distclean'
SIM_EXTRA_DISTCLEAN =

# Every time a new general purpose source file was added every target's
# Makefile.in needed to be updated to include the file in SIM_OBJS.
# This doesn't scale.
# This variable specifies all the generic stuff common to the newer simulators.
# Things like sim-reason.o can't go here as the cpu may provide its own
# (though hopefully in time that won't be so).  Things like sim-bits.o can go
# here.  Some files are used by all simulators (e.g. callback.o).
# Those files are specified in LIB_OBJS below.

SIM_COMMON_HW_OBJS = \
	hw-alloc.o \
	hw-base.o \
	hw-device.o \
	hw-events.o \
	hw-handles.o \
	hw-instances.o \
	hw-ports.o \
	hw-properties.o \
	hw-tree.o \
	sim-hw.o \

SIM_NEW_COMMON_OBJS = \
	sim-arange.o \
	sim-bits.o \
	sim-close.o \
	sim-command.o \
	sim-config.o \
	sim-core.o \
	sim-cpu.o \
	sim-endian.o \
	sim-engine.o \
	sim-events.o \
	sim-fpu.o \
	sim-hload.o \
	sim-hrw.o \
	sim-io.o \
	sim-info.o \
	sim-load.o \
	sim-memopt.o \
	sim-model.o \
	sim-module.o \
	sim-options.o \
	sim-profile.o \
	sim-reason.o \
	sim-reg.o \
	sim-signal.o \
	sim-stop.o \
	sim-syscall.o \
	sim-trace.o \
	sim-utils.o \
	sim-watch.o \
	\
	$(SIM_HW_OBJS) \

# cgen-sim.h and the headers it includes
CGEN_SIM_DEPS = \
	$(srccom)/cgen-sim.h \
	$(srccom)/cgen-defs.h \
	$(srccom)/cgen-scache.h \
	$(srccom)/cgen-fpu.h \
	$(srccom)/cgen-par.h \
	$(srccom)/cgen-cpu.h \
	$(srccom)/cgen-trace.h \
	cpuall.h

# Add this to SIM_EXTRA_DEPS.
CGEN_INCLUDE_DEPS = \
	$(CGEN_SIM_DEPS) \
	$(srccom)/cgen-engine.h \
	$(srccom)/cgen-types.h \
	$(srcdir)/../../include/opcode/cgen.h

## End COMMON_PRE_CONFIG_FRAG

srcdir=.
srcroot=$(srcdir)/../../

# Object files created by various simulator generators.


SIM_IGEN_OBJ = \
	support.o \
	itable.o \
	semantics.o \
	idecode.o \
	icache.o \
	engine.o \
	irun.o \


SIM_M16_OBJ = \
	m16_support.o \
	m16_semantics.o \
	m16_idecode.o \
	m16_icache.o \
	\
	m32_support.o \
	m32_semantics.o \
	m32_idecode.o \
	m32_icache.o \
	\
	itable.o \
	m16run.o \

SIM_MICROMIPS_OBJ = \
	micromips16_support.o \
	micromips16_semantics.o \
	micromips16_idecode.o \
	micromips16_icache.o \
	\
	micromips32_support.o \
	micromips32_semantics.o \
	micromips32_idecode.o \
	micromips32_icache.o \
	\
	micromips_m32_support.o \
	micromips_m32_semantics.o \
	micromips_m32_idecode.o \
	micromips_m32_icache.o \
	\
	itable.o \
	micromipsrun.o \


SIM_MULTI_OBJ =  \
		itable.o \
		multi-run.o \

MIPS_EXTRA_LIBS = 

SIM_OBJS = \
	interp.o \
	$(SIM_IGEN_OBJ) \
	$(SIM_NEW_COMMON_OBJS) \
	cp1.o \
	mdmx.o \
	dsp.o \
	sim-main.o \
	sim-resume.o \


# List of flags to always pass to $(CC).
SIM_SUBTARGET= -DMIPS_MACH_DEFAULT=bfd_mach_mips8000
SIM_EXTRA_CFLAGS = $(SIM_SUBTARGET)

SIM_EXTRA_CLEAN = clean-extra
SIM_EXTRA_DISTCLEAN = distclean-extra

SIM_EXTRA_ALL = $(SIM_IGEN_ALL)

SIM_EXTRA_LIBS = $(MIPS_EXTRA_LIBS)


## COMMON_POST_CONFIG_FRAG
## COMMON_POST_CONFIG_FRAG

CONFIG_CFLAGS = \
	-DHAVE_CONFIG_H \
	$(SIM_DEFAULT_MODEL) \
	$(SIM_ALIGNMENT) \
	$(SIM_BITSIZE) \
	$(SIM_ENDIAN) \
	$(SIM_FLOAT) \
	$(SIM_HW_CFLAGS) \
	$(SIM_INLINE) \
	$(SIM_RESERVED_BITS) \
	$(SIM_SCACHE) \
	$(SIM_WARN_CFLAGS) \
	$(SIM_WERROR_CFLAGS) \
	$(SIM_HARDWARE) \
	$(SIM_EXTRA_CFLAGS) \
	$(HDEFINES) $(TDEFINES)
CSEARCH = -I. -I$(srcdir) -I../common -I$(srccom) \
  -I../../include -I$(srcroot)/include \
  -I../../bfd -I$(srcroot)/bfd \
  -I../../opcodes -I$(srcroot)/opcodes \
  
ALL_CFLAGS = $(CONFIG_CFLAGS) $(CSEARCH) $(CFLAGS)
BUILD_CFLAGS = -g -O $(CSEARCH)

COMMON_DEP_CFLAGS = $(CONFIG_CFLAGS) $(CSEARCH)

ZLIB = -L$(top_builddir)/../zlib -lz
LIBIBERTY_LIB = ../../libiberty/libiberty.a
BFD_LIB = ../../bfd/libbfd.a
LIBDL = 
OPCODES_LIB = ../../opcodes/libopcodes.a
LIBINTL = 
LIBINTL_DEP = 
CONFIG_LIBS = -lm -ldl -lnsl  $(ZLIB)
LIBDEPS = $(BFD_LIB) $(OPCODES_LIB) $(LIBINTL_DEP) $(LIBIBERTY_LIB) \
	$(SIM_EXTRA_LIBDEPS)
EXTRA_LIBS = $(BFD_LIB) $(OPCODES_LIB) $(LIBINTL) $(LIBIBERTY_LIB) \
	$(CONFIG_LIBS) $(SIM_EXTRA_LIBS) $(LIBDL)

LIB_OBJS = callback.o syscall.o targ-map.o version.o $(SIM_OBJS)

RUNTESTFLAGS =

callback_h = $(srcroot)/include/gdb/callback.h
remote_sim_h = $(srcroot)/include/gdb/remote-sim.h

all: $(SIM_EXTRA_ALL) libsim.a run$(EXEEXT) .gdbinit

libsim.a: $(LIB_OBJS)
	rm -f libsim.a
	$(AR) $(AR_FLAGS) libsim.a $(LIB_OBJS)
	$(RANLIB) libsim.a

run$(EXEEXT): $(SIM_RUN_OBJS) libsim.a $(LIBDEPS)
	$(CC) $(ALL_CFLAGS) $(LDFLAGS) -o run$(EXEEXT) \
	  $(SIM_RUN_OBJS) libsim.a $(EXTRA_LIBS)

# FIXME: Ideally, callback.o and friends live in a library outside of
# both the gdb and simulator source trees (e.g. devo/remote.  Not
# devo/libremote because this directory would contain more than just
# a library).

gentmap: Makefile $(srccom)/gentmap.c $(srccom)/nltvals.def
	$(CC_FOR_BUILD) $(srccom)/gentmap.c -o gentmap $(BUILD_CFLAGS) $(NL_TARGET)

targ-vals.h targ-map.c: stamp-tvals
stamp-tvals: gentmap
	rm -f tmp-tvals.h tmp-tmap.c
	./gentmap -h >tmp-tvals.h
	$(SHELL) $(srcroot)/move-if-change tmp-tvals.h targ-vals.h
	./gentmap -c >tmp-tmap.c
	$(SHELL) $(srcroot)/move-if-change tmp-tmap.c targ-map.c
	touch stamp-tvals

version.c: Makefile $(srcroot)/gdb/version.in $(srcroot)/bfd/version.h $(srcroot)/gdb/common/create-version.sh
	$(SHELL) $(srcroot)/gdb/common/create-version.sh $(srcroot)/gdb \
	    $(host_alias) $(target_alias) version.c

#
# Rules for building sim-* components.  Triggered by listing the corresponding
# .o file in the list of simulator targets.
#

sim_main_headers = \
	sim-main.h \
	$(sim-assert_h) \
	$(sim-base_h) \
	$(sim-cpu_h) \
	$(sim-engine_h) \
	$(sim-events_h) \
	$(sim-memopt_h) \
	$(sim-model_h) \
	$(sim-module_h) \
	$(sim-profile_h) \
	$(sim-trace_h) \
	$(sim-watch_h) \
	$(sim-basics_h) \
	$(SIM_EXTRA_DEPS)

# Exported version of sim_main_headers.
SIM_MAIN_DEPS = \
	$(sim_main_headers)

sim-alu_h = $(srccom)/sim-alu.h
sim-arange_h = $(srccom)/sim-arange.h \
		$(srccom)/sim-arange.c
sim-assert_h = $(srccom)/sim-assert.h
sim-base_h = $(srccom)/sim-base.h \
		$(sim-module_h) \
		$(sim-trace_h) \
		$(sim-core_h) \
		$(sim-events_h) \
		$(sim-profile_h) \
		$(sim-model_h) \
		$(sim-io_h) \
		$(sim-engine_h) \
		$(sim-watch_h) \
		$(sim-memopt_h) \
		$(sim-cpu_h)
sim-basics_h = $(srccom)/sim-basics.h \
		$(sim-config_h) \
		$(callback_h) \
		$(sim-inline_h) \
		$(sim-types_h) \
		$(sim-bits_h) \
		$(sim-endian_h) \
		$(sim-signal_h) \
		$(sim-arange_h) \
		$(sim-utils_h)
sim-bits_h = $(srccom)/sim-bits.h \
		$(srccom)/sim-bits.c
sim-config_h = $(srccom)/sim-config.h
sim-core_h = $(srccom)/sim-core.h
sim-cpu_h = $(srccom)/sim-cpu.h
sim-endian_h = $(srccom)/sim-endian.h \
		$(srccom)/sim-endian.c
sim-engine_h = $(srccom)/sim-engine.h
sim-events_h = $(srccom)/sim-events.h
sim-fpu_h = $(srccom)/sim-fpu.h
sim-hw_h = $(srccom)/sim-hw.h
sim-inline_h = $(srccom)/sim-inline.h
sim-io_h = $(srccom)/sim-io.h
sim-memopt_h = $(srccom)/sim-memopt.h
sim-model_h = $(srccom)/sim-model.h
sim-module_h = $(srccom)/sim-module.h
sim-n-bits_h = $(srccom)/sim-n-bits.h
sim-n-core_h = $(srccom)/sim-n-core.h
sim-n-endian_h = $(srccom)/sim-n-endian.h
sim-options_h = $(srccom)/sim-options.h
sim-profile_h = $(srccom)/sim-profile.h
sim-signal_h = $(srccom)/sim-signal.h
sim-trace_h = $(srccom)/sim-trace.h
sim-types_h = $(srccom)/sim-types.h
sim-utils_h = $(srccom)/sim-utils.h
sim-watch_h = $(srccom)/sim-watch.h

hw-alloc_h = $(srccom)/hw-alloc.h
hw-base_h = $(srccom)/hw-base.h
hw-device_h = $(srccom)/hw-device.h
hw-events_h = $(srccom)/hw-events.h
hw-handles_h = $(srccom)/hw-handles.h
hw-instances_h = $(srccom)/hw-instances.h
hw-ports_h = $(srccom)/hw-ports.h
hw-properties_h = $(srccom)/hw-properties.h
hw-tree_h = $(srccom)/hw-tree.h

hw_main_headers = \
	$(srccom)/hw-main.h \
	$(hw-alloc_h) \
	$(hw-base_h) \
	$(hw-device_h) \
	$(hw-events_h) \
	$(hw-instances_h) \
	$(hw-handles_h) \
	$(hw-ports_h) \
	$(hw-properties_h) \

#
# Dependency tracking.  Most of this is conditional on GNU Make being
# found by configure; if GNU Make is not found, we fall back to a
# simpler scheme.
#

ifeq ($(DEPMODE),depmode=gcc3)
# Note that we put the dependencies into a .Tpo file, then move them
# into place if the compile succeeds.  We need this because gcc does
# not atomically write the dependency output file.
override COMPILE.post = -c -o $@ -MT $@ -MMD -MP \
	-MF $(DEPDIR)/$(basename $(@F)).Tpo
override POSTCOMPILE = @mv $(DEPDIR)/$(basename $(@F)).Tpo \
	$(DEPDIR)/$(basename $(@F)).Po
else
override COMPILE.pre = source='$<' object='$@' libtool=no \
	DEPDIR=$(DEPDIR) $(DEPMODE) $(depcomp) $(CC)
# depcomp handles atomicity for us, so we don't need a postcompile
# step.
override POSTCOMPILE =
endif

all_object_files = $(LIB_OBJS) $(SIM_RUN_OBJS)
generated_files = \
	$(SIM_EXTRA_DEPS) \
	hw-config.h \
	targ-map.c \
	targ-vals.h \
	version.c

# Ensure that generated files are created early.  Use order-only
# dependencies if available.  They require GNU make 3.80 or newer,
# and the .VARIABLES variable was introduced at the same time.
ifdef .VARIABLES
$(all_object_files): | $(generated_files)
else
$(all_object_files) : $(generated_files)
endif

# Dependencies.
-include $(patsubst %.o, $(DEPDIR)/%.Po, $(all_object_files))

# FIXME This is one very simple-minded way of generating the file hw-config.h
hw-config.h: Makefile.in $(srccom)/Make-common.in config.status Makefile
	rm -f tmp-hw.h
	echo "/* generated by Makefile */" > tmp-hw.h
	sim_hw="$(SIM_HW)"; \
	for hw in $$sim_hw ; do \
	  echo "extern const struct hw_descriptor dv_$${hw}_descriptor[];" ; \
	done >> tmp-hw.h
	echo "const struct hw_descriptor *hw_descriptors[] = {" >> tmp-hw.h
	sim_hw="$(SIM_HW)"; \
	for hw in $$sim_hw ; do \
	  echo "  dv_$${hw}_descriptor," ; \
	done >> tmp-hw.h
	echo "  NULL," >> tmp-hw.h
	echo "};" >> tmp-hw.h
	mv tmp-hw.h hw-config.h

test-hw-events: $(srccom)/hw-events.c libsim.a
	$(CC) $(ALL_CFLAGS) -DMAIN -o test-hw-events$(EXEEXT) \
		$(srccom)/hw-events.c libsim.a $(EXTRA_LIBS)

# CGEN support.

# For use in Makefile.in for cpu-specific files.
CGEN_MAIN_CPU_DEPS = \
	$(SIM_MAIN_DEPS) \
	$(srccom)/cgen-ops.h \
	$(srccom)/cgen-mem.h

# Support targets.

install: install-common $(SIM_EXTRA_INSTALL)

install-common: installdirs
	n=`echo run | sed '$(program_transform_name)'`; \
	$(INSTALL_PROGRAM) run$(EXEEXT) $(DESTDIR)$(bindir)/$$n$(EXEEXT)
	n=`echo libsim.a | sed s/libsim.a/lib$(target_alias)-sim.a/`; \
	$(INSTALL_DATA) libsim.a $(DESTDIR)$(libdir)/$$n ; \
	( cd $(DESTDIR)$(libdir) ; $(RANLIB) $$n )

installdirs:
	$(SHELL) $(srcdir)/../../mkinstalldirs $(DESTDIR)$(bindir)
	$(SHELL) $(srcdir)/../../mkinstalldirs $(DESTDIR)$(libdir)

check:
	cd ../testsuite && $(MAKE) check RUNTESTFLAGS="$(RUNTESTFLAGS)"

info:
clean-info:
install-info:

.NOEXPORT:
MAKEOVERRIDES=

tags etags: TAGS

# Macros like EXTERN_SIM_CORE confuse tags.
# And the sim-n-foo.h files create functions that can't be found either.
TAGS: force
	cd $(srcdir) && \
	etags --regex '/^\([[:lower:]_]+\) (/\1/' --regex '/^\/[*] TAGS: .*/' \
		*.[ch] ../common/*.[ch]

clean: $(SIM_EXTRA_CLEAN)
	rm -f *.[oa] *~ core
	rm -f run$(EXEEXT) libsim.a
	rm -f gentmap targ-map.c targ-vals.h stamp-tvals
	if [ ! -f Make-common.in ] ; then \
		rm -f $(BUILT_SRC_FROM_COMMON) ; \
	fi
	rm -f tmp-mloop.hin tmp-mloop.h tmp-mloop.cin tmp-mloop.c

distclean mostlyclean maintainer-clean realclean: clean $(SIM_EXTRA_DISTCLEAN)
	rm -f TAGS
	rm -f Makefile config.cache config.log config.status .gdbinit
	rm -f config.h stamp-h

.c.o:
	$(COMPILE) $<
	$(POSTCOMPILE)

# Dummy target to force execution of dependent targets.
force:

Makefile: Makefile.in $(srccom)/Make-common.in config.status
	CONFIG_HEADERS= $(SHELL) ./config.status

config.status: configure
	$(SHELL) ./config.status --recheck

config.h: stamp-h ; @true
stamp-h: config.in config.status
	CONFIG_FILES= CONFIG_HEADERS=config.h:config.in $(SHELL) ./config.status

.gdbinit: # config.status $(srccom)/gdbinit.in
	CONFIG_FILES=$@:../common/gdbinit.in CONFIG_HEADERS= $(SHELL) ./config.status


# CGEN support

CGENDIR = @cgendir@
CGEN = "`if [ -f ../../guile/libguile/guile ]; then echo ../../guile/libguile/guile; else echo guile ; fi` -l $(CGENDIR)/guile.scm -s"
CGENFLAGS = -v
CGEN_CPU_DIR = $(CGENDIR)/cpu

# Most ports use the files here instead of cgen/cpu.
CPU_DIR = $(srcroot)/cpu

CGEN_READ_SCM = $(CGENDIR)/sim.scm
CGEN_ARCH_SCM = $(CGENDIR)/sim-arch.scm
CGEN_CPU_SCM = $(CGENDIR)/sim-cpu.scm $(CGENDIR)/sim-model.scm
CGEN_DECODE_SCM = $(CGENDIR)/sim-decode.scm
CGEN_DESC_SCM = $(CGENDIR)/desc.scm $(CGENDIR)/desc-cpu.scm

# Various choices for which cpu specific files to generate.
# These are passed to cgen.sh in the "extrafiles" argument.
CGEN_CPU_EXTR = /extr/
CGEN_CPU_READ = /read/
CGEN_CPU_WRITE = /write/
CGEN_CPU_SEM = /sem/
CGEN_CPU_SEMSW = /semsw/

CGEN_FLAGS_TO_PASS = \
	CGEN='$(CGEN)' \
	CGENFLAGS="$(CGENFLAGS)"

# We store the generated files in the source directory until we decide to
# ship a Scheme interpreter with gdb/binutils.  Maybe we never will.

cgen-arch: force
	$(SHELL) $(srccom)/cgen.sh arch $(srcdir) \
		$(CGEN) $(CGENDIR) "$(CGENFLAGS)" \
		$(arch) "$(FLAGS)" ignored "$(isa)" $(mach) ignored \
		$(archfile) ignored

cgen-cpu: force
	$(SHELL) $(srccom)/cgen.sh cpu $(srcdir) \
		$(CGEN) $(CGENDIR) "$(CGENFLAGS)" \
		$(arch) "$(FLAGS)" $(cpu) "$(isa)" $(mach) "$(SUFFIX)" \
		$(archfile) "$(EXTRAFILES)"

cgen-defs: force
	$(SHELL) $(srccom)/cgen.sh defs $(srcdir) \
		$(CGEN) $(CGENDIR) "$(CGENFLAGS)" \
		$(arch) "$(FLAGS)" $(cpu) "$(isa)" $(mach) "$(SUFFIX)" \
		$(archfile) ignored

cgen-decode: force
	$(SHELL) $(srccom)/cgen.sh decode $(srcdir) \
		$(CGEN) $(CGENDIR) "$(CGENFLAGS)" \
		$(arch) "$(FLAGS)" $(cpu) "$(isa)" $(mach) "$(SUFFIX)" \
		$(archfile) "$(EXTRAFILES)"

cgen-cpu-decode: force
	$(SHELL) $(srccom)/cgen.sh cpu-decode $(srcdir) \
		$(CGEN) $(CGENDIR) "$(CGENFLAGS)" \
		$(arch) "$(FLAGS)" $(cpu) "$(isa)" $(mach) "$(SUFFIX)" \
		$(archfile) "$(EXTRAFILES)"

cgen-desc: force
	$(SHELL) $(srccom)/cgen.sh desc $(srcdir) \
		$(CGEN) $(CGENDIR) "$(CGENFLAGS)" \
		$(arch) "$(FLAGS)" $(cpu) "$(isa)" $(mach) "$(SUFFIX)" \
		$(archfile) ignored $(opcfile)

## End COMMON_POST_CONFIG_FRAG

interp.o: $(srcdir)/interp.c config.h sim-main.h itable.h

m16run.o: sim-main.h m16_idecode.h m32_idecode.h m16run.c $(SIM_EXTRA_DEPS)

micromipsrun.o: sim-main.h micromips16_idecode.h micromips32_idecode.h \
		micromips_m32_idecode.h micromipsrun.c $(SIM_EXTRA_DEPS)

multi-run.o: multi-include.h tmp-mach-multi

../igen/igen:
	cd ../igen && $(MAKE)

IGEN_TRACE= # -G omit-line-numbers # -G trace-rule-selection -G trace-rule-rejection -G trace-entries # -G trace-all
IGEN_INSN=$(srcdir)/mips.igen
IGEN_DC=$(srcdir)/mips.dc
M16_DC=$(srcdir)/m16.dc
MICROMIPS32_DC=$(srcdir)/micromips.dc
MICROMIPS16_DC=$(srcdir)/micromips16.dc
IGEN_INCLUDE=\
	$(srcdir)/micromipsdsp.igen \
	$(srcdir)/micromips.igen \
	$(srcdir)/m16.igen \
	$(srcdir)/m16e.igen \
	$(srcdir)/mdmx.igen \
	$(srcdir)/mips3d.igen \
	$(srcdir)/sb1.igen \
	$(srcdir)/tx.igen \
	$(srcdir)/vr.igen \
	$(srcdir)/dsp.igen \
	$(srcdir)/dsp2.igen \
	$(srcdir)/mips3264r2.igen \

# NB:	Since these can be built by a number of generators, care
#	must be taken to ensure that they are only dependant on
#	one of those generators.
BUILT_SRC_FROM_GEN = \
	itable.h \
	itable.c \

SIM_IGEN_ALL = tmp-igen
SIM_M16_ALL = tmp-m16
SIM_MICROMIPS_ALL = tmp-micromips
SIM_MULTI_ALL = tmp-multi

$(BUILT_SRC_FROM_GEN): $(SIM_IGEN_ALL)



BUILT_SRC_FROM_IGEN = \
	icache.h \
	icache.c \
	idecode.h \
	idecode.c \
	semantics.h \
	semantics.c \
	model.h \
	model.c \
	support.h \
	support.c \
	engine.h \
	engine.c \
	irun.c \

$(BUILT_SRC_FROM_IGEN): tmp-igen

tmp-igen: $(IGEN_INSN) $(IGEN_DC) ../igen/igen $(IGEN_INCLUDE)
	cd ../igen && $(MAKE)
	../igen/igen \
		$(IGEN_TRACE) \
		-I $(srcdir) \
		-Werror \
		-Wnodiscard \
		-F 32,f -M mipsIV  \
		-G gen-direct-access \
		-G gen-zero-r0 \
		-B 32 \
		-H 31 \
		-i $(IGEN_INSN) \
		-o $(IGEN_DC) \
		-x \
		-n icache.h    -hc tmp-icache.h \
		-n icache.c    -c  tmp-icache.c \
		-n semantics.h -hs tmp-semantics.h \
		-n semantics.c -s  tmp-semantics.c \
		-n idecode.h   -hd tmp-idecode.h \
		-n idecode.c   -d  tmp-idecode.c \
		-n model.h     -hm tmp-model.h \
		-n model.c     -m  tmp-model.c \
		-n support.h   -hf tmp-support.h \
		-n support.c   -f  tmp-support.c \
		-n itable.h    -ht tmp-itable.h \
		-n itable.c    -t  tmp-itable.c \
		-n engine.h    -he tmp-engine.h \
		-n engine.c    -e  tmp-engine.c \
		-n irun.c      -r  tmp-irun.c
	$(SHELL) $(srcdir)/../../move-if-change tmp-icache.h icache.h
	$(SHELL) $(srcdir)/../../move-if-change tmp-icache.c icache.c
	$(SHELL) $(srcdir)/../../move-if-change tmp-idecode.h idecode.h
	$(SHELL) $(srcdir)/../../move-if-change tmp-idecode.c idecode.c
	$(SHELL) $(srcdir)/../../move-if-change tmp-semantics.h semantics.h
	$(SHELL) $(srcdir)/../../move-if-change tmp-semantics.c semantics.c
	$(SHELL) $(srcdir)/../../move-if-change tmp-model.h model.h
	$(SHELL) $(srcdir)/../../move-if-change tmp-model.c model.c
	$(SHELL) $(srcdir)/../../move-if-change tmp-support.h support.h
	$(SHELL) $(srcdir)/../../move-if-change tmp-support.c support.c
	$(SHELL) $(srcdir)/../../move-if-change tmp-itable.h itable.h
	$(SHELL) $(srcdir)/../../move-if-change tmp-itable.c itable.c
	$(SHELL) $(srcdir)/../../move-if-change tmp-engine.h engine.h
	$(SHELL) $(srcdir)/../../move-if-change tmp-engine.c engine.c
	$(SHELL) $(srcdir)/../../move-if-change tmp-irun.c irun.c
	touch tmp-igen

BUILT_SRC_FROM_M16 = \
	m16_icache.h \
	m16_icache.c \
	m16_idecode.h \
	m16_idecode.c \
	m16_semantics.h \
	m16_semantics.c \
	m16_model.h \
	m16_model.c \
	m16_support.h \
	m16_support.c \
	\
	m32_icache.h \
	m32_icache.c \
	m32_idecode.h \
	m32_idecode.c \
	m32_semantics.h \
	m32_semantics.c \
	m32_model.h \
	m32_model.c \
	m32_support.h \
	m32_support.c \

$(BUILT_SRC_FROM_M16): tmp-m16

tmp-m16: $(IGEN_INSN) $(IGEN_DC) ../igen/igen $(IGEN_INCLUDE)
	cd ../igen && $(MAKE)
	../igen/igen \
		$(IGEN_TRACE) \
		-I $(srcdir) \
		-Werror \
		-Wnodiscard \
		 -F 16  -M mips16,mipsIII   \
		-G gen-direct-access \
		-G gen-zero-r0 \
		-B 16 \
		-H 15 \
		-i $(IGEN_INSN) \
		-o $(M16_DC) \
		-P m16_ \
		-x \
		-n m16_icache.h    -hc tmp-icache.h \
		-n m16_icache.c    -c  tmp-icache.c \
		-n m16_semantics.h -hs tmp-semantics.h \
		-n m16_semantics.c -s  tmp-semantics.c \
		-n m16_idecode.h   -hd tmp-idecode.h \
		-n m16_idecode.c   -d  tmp-idecode.c \
		-n m16_model.h     -hm tmp-model.h \
		-n m16_model.c     -m  tmp-model.c \
		-n m16_support.h   -hf tmp-support.h \
		-n m16_support.c   -f  tmp-support.c \
		#
	$(SHELL) $(srcdir)/../../move-if-change tmp-icache.h m16_icache.h
	$(SHELL) $(srcdir)/../../move-if-change tmp-icache.c m16_icache.c
	$(SHELL) $(srcdir)/../../move-if-change tmp-idecode.h m16_idecode.h
	$(SHELL) $(srcdir)/../../move-if-change tmp-idecode.c m16_idecode.c
	$(SHELL) $(srcdir)/../../move-if-change tmp-semantics.h m16_semantics.h
	$(SHELL) $(srcdir)/../../move-if-change tmp-semantics.c m16_semantics.c
	$(SHELL) $(srcdir)/../../move-if-change tmp-model.h m16_model.h
	$(SHELL) $(srcdir)/../../move-if-change tmp-model.c m16_model.c
	$(SHELL) $(srcdir)/../../move-if-change tmp-support.h m16_support.h
	$(SHELL) $(srcdir)/../../move-if-change tmp-support.c m16_support.c
	../igen/igen \
		$(IGEN_TRACE) \
		-I $(srcdir) \
		-Werror \
		-Wnodiscard \
		-F 32,f -M mipsIV  \
		-G gen-direct-access \
		-G gen-zero-r0 \
		-B 32 \
		-H 31 \
		-i $(IGEN_INSN) \
		-o $(IGEN_DC) \
		-P m32_ \
		-x \
		-n m32_icache.h    -hc tmp-icache.h \
		-n m32_icache.c    -c  tmp-icache.c \
		-n m32_semantics.h -hs tmp-semantics.h \
		-n m32_semantics.c -s  tmp-semantics.c \
		-n m32_idecode.h   -hd tmp-idecode.h \
		-n m32_idecode.c   -d  tmp-idecode.c \
		-n m32_model.h     -hm tmp-model.h \
		-n m32_model.c     -m  tmp-model.c \
		-n m32_support.h   -hf tmp-support.h \
		-n m32_support.c   -f  tmp-support.c \
		#
	$(SHELL) $(srcdir)/../../move-if-change tmp-icache.h m32_icache.h
	$(SHELL) $(srcdir)/../../move-if-change tmp-icache.c m32_icache.c
	$(SHELL) $(srcdir)/../../move-if-change tmp-idecode.h m32_idecode.h
	$(SHELL) $(srcdir)/../../move-if-change tmp-idecode.c m32_idecode.c
	$(SHELL) $(srcdir)/../../move-if-change tmp-semantics.h \
						m32_semantics.h
	$(SHELL) $(srcdir)/../../move-if-change tmp-semantics.c \
						m32_semantics.c
	$(SHELL) $(srcdir)/../../move-if-change tmp-model.h m32_model.h
	$(SHELL) $(srcdir)/../../move-if-change tmp-model.c m32_model.c
	$(SHELL) $(srcdir)/../../move-if-change tmp-support.h m32_support.h
	$(SHELL) $(srcdir)/../../move-if-change tmp-support.c m32_support.c
	../igen/igen \
		$(IGEN_TRACE) \
		-I $(srcdir) \
		-Werror \
		-Wnodiscard \
		-Wnowidth \
		-F 32,f -M mipsIV   -F 16  -M mips16,mipsIII   \
		-G gen-direct-access \
		-G gen-zero-r0 \
		-i $(IGEN_INSN) \
		-n itable.h    -ht tmp-itable.h \
		-n itable.c    -t  tmp-itable.c \
		#
	$(SHELL) $(srcdir)/../../move-if-change tmp-itable.h itable.h
	$(SHELL) $(srcdir)/../../move-if-change tmp-itable.c itable.c
	touch tmp-m16

BUILT_SRC_FROM_MICROMIPS = \
	micromips16_icache.h \
	micromips16_icache.c \
	micromips16_idecode.h \
	micromips16_idecode.c \
	micromips16_semantics.h \
	micromips16_semantics.c \
	micromips16_model.h \
	micromips16_model.c \
	micromips16_support.h \
	micromips16_support.c \
	\
	micromips32_icache.h \
	micromips32_icache.c \
	micromips32_idecode.h \
	micromips32_idecode.c \
	micromips32_semantics.h \
	micromips32_semantics.c \
	micromips32_model.h \
	micromips32_model.c \
	micromips32_support.h \
	micromips32_support.c \
	\
	micromips_m32_icache.h \
	micromips_m32_icache.c \
	micromips_m32_idecode.h \
	micromips_m32_idecode.c \
	micromips_m32_semantics.h \
	micromips_m32_semantics.c \
	micromips_m32_model.h \
	micromips_m32_model.c \
	micromips_m32_support.h \
	micromips_m32_support.c \

$(BUILT_SRC_FROM_MICROMIPS): tmp-micromips

tmp-micromips: $(IGEN_INSN) $(IGEN_DC) ../igen/igen $(IGEN_INCLUDE)
	cd ../igen && $(MAKE)
	../igen/igen \
		$(IGEN_TRACE) \
		-I $(srcdir) \
		-Werror \
		-Wnodiscard \
		 -F      \
		-G gen-direct-access \
		-G gen-zero-r0 \
		-B 16 \
		-H 15 \
		-i $(IGEN_INSN) \
		-o $(MICROMIPS16_DC) \
		-P micromips16_ \
		-x \
		-n micromips16_icache.h    -hc tmp-icache.h \
		-n micromips16_icache.c    -c  tmp-icache.c \
		-n micromips16_semantics.h -hs tmp-semantics.h \
		-n micromips16_semantics.c -s  tmp-semantics.c \
		-n micromips16_idecode.h   -hd tmp-idecode.h \
		-n micromips16_idecode.c   -d  tmp-idecode.c \
		-n micromips16_model.h     -hm tmp-model.h \
		-n micromips16_model.c     -m  tmp-model.c \
		-n micromips16_support.h   -hf tmp-support.h \
		-n micromips16_support.c   -f  tmp-support.c \
		#
	$(SHELL) $(srcdir)/../../move-if-change tmp-icache.h \
						micromips16_icache.h
	$(SHELL) $(srcdir)/../../move-if-change tmp-icache.c \
						micromips16_icache.c
	$(SHELL) $(srcdir)/../../move-if-change tmp-idecode.h \
						micromips16_idecode.h
	$(SHELL) $(srcdir)/../../move-if-change tmp-idecode.c \
						micromips16_idecode.c
	$(SHELL) $(srcdir)/../../move-if-change tmp-semantics.h \
						micromips16_semantics.h
	$(SHELL) $(srcdir)/../../move-if-change tmp-semantics.c \
						micromips16_semantics.c
	$(SHELL) $(srcdir)/../../move-if-change tmp-model.h \
						micromips16_model.h
	$(SHELL) $(srcdir)/../../move-if-change tmp-model.c \
						micromips16_model.c
	$(SHELL) $(srcdir)/../../move-if-change tmp-support.h \
						micromips16_support.h
	$(SHELL) $(srcdir)/../../move-if-change tmp-support.c \
						micromips16_support.c
	cd ../igen && $(MAKE)
	../igen/igen \
		$(IGEN_TRACE) \
		-I $(srcdir) \
		-Werror \
		-Wnodiscard \
		 -F      \
		-G gen-direct-access \
		-G gen-zero-r0 \
		-B 32 \
		-H 31 \
		-i $(IGEN_INSN) \
		-o $(MICROMIPS32_DC) \
		-P micromips32_ \
		-x \
		-n micromips32_icache.h    -hc tmp-icache.h \
		-n micromips32_icache.c    -c  tmp-icache.c \
		-n micromips32_semantics.h -hs tmp-semantics.h \
		-n micromips32_semantics.c -s  tmp-semantics.c \
		-n micromips32_idecode.h   -hd tmp-idecode.h \
		-n micromips32_idecode.c   -d  tmp-idecode.c \
		-n micromips32_model.h     -hm tmp-model.h \
		-n micromips32_model.c     -m  tmp-model.c \
		-n micromips32_support.h   -hf tmp-support.h \
		-n micromips32_support.c   -f  tmp-support.c \
		#
	$(SHELL) $(srcdir)/../../move-if-change tmp-icache.h \
						micromips32_icache.h
	$(SHELL) $(srcdir)/../../move-if-change tmp-icache.c \
						micromips32_icache.c
	$(SHELL) $(srcdir)/../../move-if-change tmp-idecode.h  \
						micromips32_idecode.h
	$(SHELL) $(srcdir)/../../move-if-change tmp-idecode.c \
						micromips32_idecode.c
	$(SHELL) $(srcdir)/../../move-if-change tmp-semantics.h \
						micromips32_semantics.h
	$(SHELL) $(srcdir)/../../move-if-change tmp-semantics.c \
						micromips32_semantics.c
	$(SHELL) $(srcdir)/../../move-if-change tmp-model.h \
						micromips32_model.h
	$(SHELL) $(srcdir)/../../move-if-change tmp-model.c  \
						micromips32_model.c
	$(SHELL) $(srcdir)/../../move-if-change tmp-support.h \
						micromips32_support.h
	$(SHELL) $(srcdir)/../../move-if-change tmp-support.c \
						micromips32_support.c
	../igen/igen \
		$(IGEN_TRACE) \
		-I $(srcdir) \
		-Werror \
		-Wnodiscard \
		-F 32,f -M mipsIV  \
		-G gen-direct-access \
		-G gen-zero-r0 \
		-B 32 \
		-H 31 \
		-i $(IGEN_INSN) \
		-o $(IGEN_DC) \
		-P micromips_m32_ \
		-x \
		-n micromips_m32_icache.h    -hc tmp-icache.h \
		-n micromips_m32_icache.c    -c  tmp-icache.c \
		-n micromips_m32_semantics.h -hs tmp-semantics.h \
		-n micromips_m32_semantics.c -s  tmp-semantics.c \
		-n micromips_m32_idecode.h   -hd tmp-idecode.h \
		-n micromips_m32_idecode.c   -d  tmp-idecode.c \
		-n micromips_m32_model.h     -hm tmp-model.h \
		-n micromips_m32_model.c     -m  tmp-model.c \
		-n micromips_m32_support.h   -hf tmp-support.h \
		-n micromips_m32_support.c   -f  tmp-support.c \
		#
	$(SHELL) $(srcdir)/../../move-if-change tmp-icache.h \
						micromips_m32_icache.h
	$(SHELL) $(srcdir)/../../move-if-change tmp-icache.c \
						micromips_m32_icache.c
	$(SHELL) $(srcdir)/../../move-if-change tmp-idecode.h \
						micromips_m32_idecode.h
	$(SHELL) $(srcdir)/../../move-if-change tmp-idecode.c \
						micromips_m32_idecode.c
	$(SHELL) $(srcdir)/../../move-if-change tmp-semantics.h \
						micromips_m32_semantics.h
	$(SHELL) $(srcdir)/../../move-if-change tmp-semantics.c \
						micromips_m32_semantics.c
	$(SHELL) $(srcdir)/../../move-if-change tmp-model.h \
						micromips_m32_model.h
	$(SHELL) $(srcdir)/../../move-if-change tmp-model.c \
						micromips_m32_model.c
	$(SHELL) $(srcdir)/../../move-if-change tmp-support.h \
						micromips_m32_support.h
	$(SHELL) $(srcdir)/../../move-if-change tmp-support.c \
						micromips_m32_support.c
	../igen/igen \
		$(IGEN_TRACE) \
		-I $(srcdir) \
		-Werror \
		-Wnodiscard \
		-Wnowidth \
		-F 32,f -M mipsIV   -F       -F     \
		-G gen-direct-access \
		-G gen-zero-r0 \
		-i $(IGEN_INSN) \
		-n itable.h    -ht tmp-itable.h \
		-n itable.c    -t  tmp-itable.c \
		#
	$(SHELL) $(srcdir)/../../move-if-change tmp-itable.h itable.h
	$(SHELL) $(srcdir)/../../move-if-change tmp-itable.c itable.c
	touch tmp-micromips

BUILT_SRC_FROM_MULTI = doesnt-exist.c
SIM_MULTI_IGEN_CONFIGS = 

$(BUILT_SRC_FROM_MULTI): tmp-multi
tmp-multi: tmp-mach-multi tmp-itable-multi tmp-run-multi targ-vals.h
tmp-mach-multi: $(IGEN_INSN) $(IGEN_DC) ../igen/igen $(IGEN_INCLUDE)
	for t in $(SIM_MULTI_IGEN_CONFIGS); do \
	  p=`echo $${t} | sed -e 's/:.*//'` ; \
	  m=`echo $${t} | sed -e 's/.*:\(.*\):.*/\1/'` ; \
	  f=`echo $${t} | sed -e 's/.*://'` ; \
	  case $${p} in \
	    micromips16*) e="-B 16 -H 15 -o $(MICROMIPS16_DC) -F 16" ;; \
	    micromips32* | micromips64*) \
		e="-B 32 -H 31 -o $(MICROMIPS32_DC) -F $${f}" ;; \
	    micromips_m32*) \
		e="-B 32 -H 31 -o $(IGEN_DC) -F $${f}"; \
		m="mips32r2,mips3d,mdmx,dsp,dsp2,smartmips" ;; \
	    micromips_m64*) \
		e="-B 32 -H 31 -o $(IGEN_DC) -F $${f}"; \
		m="mips64r2,mips3d,mdmx,dsp,dsp2,smartmips" ;; \
	    m16*) e="-B 16 -H 15 -o $(M16_DC) -F 16" ;; \
	    *) e="-B 32 -H 31 -o $(IGEN_DC) -F $${f}" ;; \
	  esac; \
	  ../igen/igen \
		$(IGEN_TRACE) \
		$${e} \
		-I $(srcdir) \
		-Werror \
		-Wnodiscard \
		-N 0 \
		-M $${m} \
		-G gen-direct-access \
		-G gen-zero-r0 \
		-i $(IGEN_INSN) \
		-P $${p}_ \
		-x \
		-n $${p}_icache.h    -hc tmp-icache.h \
		-n $${p}_icache.c    -c  tmp-icache.c \
		-n $${p}_semantics.h -hs tmp-semantics.h \
		-n $${p}_semantics.c -s  tmp-semantics.c \
		-n $${p}_idecode.h   -hd tmp-idecode.h \
		-n $${p}_idecode.c   -d  tmp-idecode.c \
		-n $${p}_model.h     -hm tmp-model.h \
		-n $${p}_model.c     -m  tmp-model.c \
		-n $${p}_support.h   -hf tmp-support.h \
		-n $${p}_support.c   -f  tmp-support.c \
		-n $${p}_engine.h    -he tmp-engine.h \
		-n $${p}_engine.c    -e  tmp-engine.c \
	  || exit; \
	  $(SHELL) $(srcdir)/../../move-if-change tmp-icache.h \
						  $${p}_icache.h ; \
	  $(SHELL) $(srcdir)/../../move-if-change tmp-icache.c \
						  $${p}_icache.c ; \
	  $(SHELL) $(srcdir)/../../move-if-change tmp-idecode.h \
						  $${p}_idecode.h ; \
	  $(SHELL) $(srcdir)/../../move-if-change tmp-idecode.c \
						  $${p}_idecode.c ; \
	  $(SHELL) $(srcdir)/../../move-if-change tmp-semantics.h \
						  $${p}_semantics.h ; \
	  $(SHELL) $(srcdir)/../../move-if-change tmp-semantics.c \
						  $${p}_semantics.c ; \
	  $(SHELL) $(srcdir)/../../move-if-change tmp-model.h \
						  $${p}_model.h ; \
	  $(SHELL) $(srcdir)/../../move-if-change tmp-model.c \
						  $${p}_model.c ; \
	  $(SHELL) $(srcdir)/../../move-if-change tmp-support.h \
						  $${p}_support.h ; \
	  $(SHELL) $(srcdir)/../../move-if-change tmp-support.c \
						  $${p}_support.c ; \
	  $(SHELL) $(srcdir)/../../move-if-change tmp-engine.h \
						  $${p}_engine.h ; \
	  $(SHELL) $(srcdir)/../../move-if-change tmp-engine.c \
						  $${p}_engine.c ; \
	done
	touch tmp-mach-multi
tmp-itable-multi: $(IGEN_INSN) $(IGEN_DC) ../igen/igen $(IGEN_INCLUDE)
	../igen/igen \
		$(IGEN_TRACE) \
		-I $(srcdir) \
		-Werror \
		-Wnodiscard \
		-Wnowidth \
		-N 0 \
		 \
		-G gen-direct-access \
		-G gen-zero-r0 \
		-i $(IGEN_INSN) \
		-n itable.h    -ht tmp-itable.h \
		-n itable.c    -t  tmp-itable.c \
		#
	$(SHELL) $(srcdir)/../../move-if-change tmp-itable.h itable.h
	$(SHELL) $(srcdir)/../../move-if-change tmp-itable.c itable.c
	touch tmp-itable-multi
tmp-run-multi: $(srcdir)/m16run.c $(srcdir)/micromipsrun.c
	for t in $(SIM_MULTI_IGEN_CONFIGS); do \
	  case $${t} in \
	    m16*) \
	      m=`echo $${t} | sed -e 's/^m16//' -e 's/:.*//'`; \
	      sed <  $(srcdir)/m16run.c > tmp-run \
		    -e "s/^sim_/m16$${m}_/" \
		    -e "s/m16_/m16$${m}_/" \
		    -e "s/m32_/m32$${m}_/" ; \
	      $(SHELL) $(srcdir)/../../move-if-change tmp-run \
						      m16$${m}_run.c ; \
            ;;\
	    micromips32*) \
	      m=`echo $${t} | sed -e 's/^micromips32//' -e 's/:.*//'`; \
	      sed <  $(srcdir)/micromipsrun.c > tmp-run \
		    -e "s/^sim_/micromips32$${m}_/" \
		    -e "s/micromips16_/micromips16$${m}_/" \
		    -e "s/micromips32_/micromips32$${m}_/" \
		    -e "s/m32_/m32$${m}_/" ; \
	      $(SHELL) $(srcdir)/../../move-if-change tmp-run \
						      micromips$${m}_run.c ; \
             ;;\
	    micromips64*) \
	      m=`echo $${t} | sed -e 's/^micromips64//' -e 's/:.*//'`; \
	      sed <  $(srcdir)/micromipsrun.c > tmp-run \
		    -e "s/^sim_/micromips64$${m}_/" \
		    -e "s/micromips16_/micromips16$${m}_/" \
		    -e "s/micromips32_/micromips64$${m}_/" \
		    -e "s/m32_/m64$${m}_/" ; \
	      $(SHELL) $(srcdir)/../../move-if-change tmp-run \
						      micromips$${m}_run.c ; \
             ;;\
	  esac \
	done
	touch tmp-run-multi

clean-extra:
	rm -f $(BUILT_SRC_FROM_GEN)
	rm -f $(BUILT_SRC_FROM_IGEN)
	rm -f $(BUILT_SRC_FROM_M16)
	rm -f $(BUILT_SRC_FROM_MICROMIPS)
	rm -f $(BUILT_SRC_FROM_MULTI)
	rm -f tmp-*
	rm -f micromips16*.o micromips32*.o m16*.o m32*.o itable*.o

distclean-extra:
	rm -f multi-include.h multi-run.c
