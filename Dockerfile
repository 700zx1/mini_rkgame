# Containerfile for SF3000 toolchain v0.1 dev environment
FROM debian:bookworm-slim

LABEL maintainer="you@example.com"

# 1. Install basics
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
      ca-certificates wget rsync tar file build-essential \
      git pkg-config patch \
      libsdl1.2-dev libasound2-dev libncurses-dev \
      libgmp-dev libmpfr-dev texinfo && \
    rm -rf /var/lib/apt/lists/*

# 2. Download and extract the SF3000 toolchain release
ARG TOOLCHAIN_URL="https://github.com/700zx1/sf3000toolchain/raw/refs/heads/main/mipsel-buildroot-linux-gnu_sdk-buildroot.tar.gz"
RUN mkdir -p /opt && \
    wget -qO /opt/toolchain.tar.gz ${TOOLCHAIN_URL} && \
    ls -lh /opt/toolchain.tar.gz && \
    file /opt/toolchain.tar.gz && \
    tar zxvf /opt/toolchain.tar.gz -C /opt && \
    rm /opt/toolchain.tar.gz

# 3. Relocate the SDK
WORKDIR /opt/mipsel-buildroot-linux-gnu_sdk-buildroot
RUN chmod +x relocate-sdk.sh && ./relocate-sdk.sh

# 4. Export cross-compile environment permanently
RUN echo 'export TOOLBIN="/opt/mipsel-buildroot-linux-gnu_sdk-buildroot/bin/mips-mti-linux-gnu-"\n\
export SYSROOT="/opt/mipsel-buildroot-linux-gnu_sdk-buildroot/mipsel-buildroot-linux-gnu/sysroot"\n\
export CROSS_COMPILE="$TOOLBIN"\n\
export CC="${TOOLBIN}gcc"\n\
export CXX="${TOOLBIN}g++"\n\
export LD="${TOOLBIN}ld"\n\
export AS="${TOOLBIN}as"\n\
export AR="${TOOLBIN}ar"\n\
export RANLIB="${TOOLBIN}ranlib"\n\
export STRIP="${TOOLBIN}strip"\n\
#export CFLAGS="-O2 -march=mips32r2"\n\
#export CXXFLAGS="-O2 -march=mips32r2"\n\
export PATH="/opt/mipsel-buildroot-linux-gnu_sdk-buildroot/bin:${PATH}"' > /etc/profile.d/toolchain-env.sh && chmod +x /etc/profile.d/toolchain-env.sh

# Add Linux kernel headers build steps
#WORKDIR /build
#RUN wget https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.10.1.tar.xz && \
#    tar -xvJf linux-5.10.1.tar.xz && \
#    cd linux-5.10.1 && \
#    make ARCH=mips CROSS_COMPILE=mips-mti-linux-gnu- headers_install INSTALL_HDR_PATH=/opt/mipsel-buildroot-linux-gnu_sdk-buildroot/mipsel-buildroot-linux-gnu/sysroot/usr && \
#    cd .. && \
#    rm -rf linux-5.10.1 linux-5.10.1.tar.xz

# Check if the toolchain is working and the sysroot is set up correctly
#RUN echo "Checking linux/random.h..." && \
#    ls /opt/mipsel-buildroot-linux-gnu_sdk-buildroot/mipsel-buildroot-linux-gnu/sysroot/usr/include/linux/random.h

# Cleanup build directory
#WORKDIR /
#RUN rm -rf /build

# 4a. Add the real toolchain `bin/` to your PATH
#ENV PATH="/opt/mipsel-buildroot-linux-gnu_sdk-buildroot/bin:${PATH}"

# 4b. Symlink the *real* cross-compiler binaries into /usr/bin
#RUN ln -s ${TOOLBIN}gcc /usr/bin/mips-linux-gnu-gcc \
# && ln -s ${TOOLBIN}g++ /usr/bin/mips-linux-gnu-g++ \
# && ln -s ${TOOLBIN}ld  /usr/bin/mips-linux-gnu-ld \
# && ln -s ${TOOLBIN}as  /usr/bin/mips-linux-gnu-as \
# && ln -s ${TOOLBIN}ar  /usr/bin/mips-linux-gnu-ar \
# && ln -s ${TOOLBIN}ranlib /usr/bin/mips-linux-gnu-ranlib \
# && ln -s ${TOOLBIN}strip /usr/bin/mips-linux-gnu-strip

# 5. Switch to a workspace directory (mounted from host)
WORKDIR /workspace
VOLUME /workspace

# Default to an interactive shell
CMD ["bash", "-l"]
