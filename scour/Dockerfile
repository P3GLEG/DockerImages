#Currently ubuntu 17.04
FROM ubuntu:zesty
MAINTAINER Paul Ganea <k4ch0w@linux.com>
ENV MAKEFLAGS="-j16"
ENV CLANG_DIR="/clang-llvm"
RUN apt-get update -y && apt-get install -y \
        g++ \
        gcc \
        git \
        make \
        libgtest-dev \ 
        python \
        zlib1g-dev 

WORKDIR $CLANG_DIR

RUN git clone http://llvm.org/git/llvm.git \
    && cd llvm/tools \
    && git clone http://llvm.org/git/clang.git \
    && cd clang/tools \
    && git clone http://llvm.org/git/clang-tools-extra.git extra 

RUN cd  $CLANG_DIR \
        && git clone https://github.com/martine/ninja.git \
        && cd ninja \
        && git checkout release \
        && ./bootstrap.py \
        && cp ninja /usr/bin/ \
        && cd $CLANG_DIR \
        && git clone git://cmake.org/stage/cmake.git \
        && cd cmake \
        && git checkout next \
        && ./bootstrap \
        && make \
        && make install \
        && cd $CLANG_DIR \
        && mkdir build && cd build \
        && cmake -G Ninja ../llvm -DLLVM_BUILD_TESTS=OFF \ 
        && ninja \
        && ninja install \
        && cd $CLANG_DIR/build \
        && cmake ../llvm \
        && mkdir $CLANG_DIR/llvm/tools/clang/tools/extra/scour \
        && echo 'add_subdirectory(scour)' >> $CLANG_DIR/llvm/tools/clang/tools/extra/CMakeLists.txt 

COPY src $CLANG_DIR/llvm/tools/clang/tools/extra/scour 
RUN  cd $CLANG_DIR/build \
        #HACK REMOVE
        && rm /clang-llvm/llvm/tools/clang/tools/extra/scour/ScourTests.cpp \
        && mv /clang-llvm/llvm/tools/clang/tools/extra/scour/Sample.c /tmp/test.c\
        && cmake ../llvm \
        && ninja
#TODO Remove
RUN apt-get install -y vim
ENV PATH="$CLANG_DIR/build/bin:${PATH}"
CMD ["/bin/bash -c"]
