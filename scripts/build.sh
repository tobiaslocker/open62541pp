
#!/bin/bash
#export open62541_DIR=${HOME}/Projects/open62541-cpp-wrapper/third-party/lib/cmake

#SCRIPTS_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
#TOP_DIR=${SCRIPTS_DIR}/..

#mkdir ${TOP_DIR}/third-party/build/
#cd ${TOP_DIR}/third-party/build/

#cmake -DCMAKE_INSTALL_PREFIX=${TOP_DIR}/third-party/ -DUA_ENABLE_AMALGAMATION=true -DCMAKE_BUILD_TYPE=RelWithDebInfo -DUA_ENABLE_FULL_NS0=ON ../open62541

#make 
#make install

#mkdir -p ${TOP_DIR}/build
#cd ${TOP_DIR}/build
#cmake ..
#make
#make test





SCRIPTS_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
TOP_DIR=${SCRIPTS_DIR}/..

export open62541_DIR=${TOP_DIR}/third-party/open62541/build/cmake

#mkdir ${TOP_DIR}/third-party/open62541/build/
#cd ${TOP_DIR}/third-party/open62541/build/

#git checkout v0.3.0

#cmake -DCMAKE_INSTALL_PREFIX=${TOP_DIR}/third-party/open62541/ \
    #-DUA_ENABLE_AMALGAMATION=true \
    #-DCMAKE_BUILD_TYPE=RelWithDebInfo \
    #-DUA_ENABLE_FULL_NS0=ON \
    #..

#make 
#make install

mkdir -p ${TOP_DIR}/build
cd ${TOP_DIR}/build
cmake ..
make
make test
