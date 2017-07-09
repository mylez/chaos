#!/bin/sh

# Linux dependencies fetch&build script
# requires: git, autotools, gcc, make, cmake

mkdir local
INSTALL_DIR=`pwd`/local/

# ZLIB
git clone git@github.com:madler/zlib.git
cd zlib
git checkout v1.2.8
mkdir build ; cd build
TRASH=`pwd`
cmake .. -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX=$TRASH \
    -DEXECUTABLE_OUTPUT_PATH=$TRASH \
    -DINSTALL_BIN_DIR=$TRASH/bin \
    -DINSTALL_INC_DIR=$INSTALL_DIR/include \
    -DINSTALL_LIB_DIR=$INSTALL_DIR/lib \
    -DINSTALL_MAN_DIR=$TRASH \
    -DINSTALL_PKGCONFIG_DIR=$TRASH \
    -DLIBRARY_OUTPUT_PATH=$TRASH
make -j4 && make install && make clean
cd ../..

# JANSSON
git clone git@github.com:akheron/jansson.git
cd jansson
git checkout v2.7
autoreconf -i
./configure --prefix=$INSTALL_DIR
make -j4 && make install && make clean
rm -f Makefile Makefile.in aclocal.m4 compile config.guess config.log config.status config.sub configure depcomp doc/Makefile doc/Makefile.in examples/Makefile examples/Makefile.in install-sh jansson.pc jansson_private_config.h jansson_private_config.h.in libtool ltmain.sh missing src/Makefile src/Makefile.in src/jansson_config.h stamp-h1 test-driver test/Makefile test/Makefile.in test/bin/Makefile test/bin/Makefile.in test/suites/Makefile test/suites/Makefile.in test/suites/api/Makefile test/suites/api/Makefile.in
rm -rf autom4te.cache/ examples/.deps/ src/.deps/ test/suites/api/.deps/ test/bin/.deps/
cd ..

make -j4 && make install && make clean
rm -rf $INSTALL_DIR/share $INSTALL_DIR/lib/cmake $INSTALL_DIR/pkgconfig
cd ..
