#!/bin/bash
SCRIPTS_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
TOP_DIR=${SCRIPTS_DIR}/..

rm -r ${TOP_DIR}/build
rm -r ${TOP_DIR}/staging
rm -r ${TOP_DIR}/third-party/open62541/build



