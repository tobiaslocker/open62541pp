#!/bin/bash
export open62541_DIR=${HOME}/Projects/open62541-cpp-wrapper/externals/lib/cmake

SCRIPTS_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
TOP_DIR=${SCRIPTS_DIR}/..

mkdir ${TOP_DIR}/externals/build/
cd ${TOP_DIR}/externals/build/

cmake -DCMAKE_INSTALL_PREFIX=${TOP_DIR}/externals/ -DUA_ENABLE_AMALGAMATION=true -DCMAKE_BUILD_TYPE=RelWithDebInfo -DUA_ENABLE_FULL_NS0=ON ../open62541

make 
make install

mkdir -p ${TOP_DIR}/build
cd ${TOP_DIR}/build
cmake ..
make
make test
