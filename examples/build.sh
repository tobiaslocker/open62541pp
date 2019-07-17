#!/bin/bash
export open62541_DIR=/usr/local/lib/cmake/
mkdir build
cd build
cmake ..
make
