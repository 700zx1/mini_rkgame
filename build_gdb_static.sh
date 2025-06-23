#!/bin/bash
set -e

# Set cross-compiler environment variables for mipsel
#export CC=${CROSS_COMPILE}gcc
#export CXX=${CROSS_COMPILE}g++
#export AR=${CROSS_COMPILE}ar
#export RANLIB=${CROSS_COMPILE}ranlib
#export LD=${CROSS_COMPILE}ld
#export STRIP=${CROSS_COMPILE}strip
#export CFLAGS="-O2 -march=mips32r2"
#export LDFLAGS="-static"

# Use an older GDB version that is less strict about GMP/MPFR
GDB_VER=7.12.1
wget https://ftp.gnu.org/gnu/gdb/gdb-${GDB_VER}.tar.xz

# Extract
rm -rf gdb-${GDB_VER}
tar xf gdb-${GDB_VER}.tar.xz
cd gdb-${GDB_VER}

# Configure at top-level, but only build gdb
default_configure_args=(
  --host=mipsel-linux \
  --disable-werror \
  --disable-nls \
  --disable-shared \
  --enable-static \
  --without-python \
  --without-expat \
  --without-gmp \
  --without-mpfr \
  --prefix=/workspace/gdb-mipsel-static
)

./configure "${default_configure_args[@]}"

make -j$(nproc)
make install

echo "Static GDB for MIPS built and installed to /workspace/gdb-mipsel-static/bin/mipsel-linux-gdb (GDB ${GDB_VER})"
