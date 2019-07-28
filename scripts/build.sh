#!/bin/bash
SCRIPTS_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
TOP_DIR=${SCRIPTS_DIR}/..

OPEN62541_INSTALL_DIR=${TOP_DIR}/staging
mkdir -p ${OPEN62541_INSTALL_DIR}

echo ${OPEN62541_INSTALL_DIR}

mkdir -p ${TOP_DIR}/third-party/open62541/build/
cd ${TOP_DIR}/third-party/open62541/build/

cmake -DCMAKE_INSTALL_PREFIX=${OPEN62541_INSTALL_DIR} \
    -DUA_ENABLE_AMALGAMATION=true \
    ..

make 
make install

export open62541_DIR=${OPEN62541_INSTALL_DIR}/lib/cmake

mkdir -p ${TOP_DIR}/build
cd ${TOP_DIR}/build
cmake ..
make
make test
