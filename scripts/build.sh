#!/bin/bash
export open62541_DIR=/usr/local/lib/cmake/

SCRIPTS_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
TOP_DIR=${SCRIPTS_DIR}/..

mkdir ${TOP_DIR}/externals/open62541/build/
cd ${TOP_DIR}/externals/open62541/build/

cmake -DCMAKE_INSTALL_PREFIX=${TOP_DIR}/externals/ -DUA_ENABLE_AMALGAMATION=true ..

make 
make install

mkdir -p ${TOP_DIR}/build
cd ${TOP_DIR}/build
cmake ..
make
make test
