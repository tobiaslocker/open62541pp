#!/bin/bash
set -e
./build.sh
cd build
if [ -z $1 ];
then
    LEVEL=debug
else
    LEVEL=$1
fi
echo $LEVEL
LOG=${LEVEL} ./test-lib
