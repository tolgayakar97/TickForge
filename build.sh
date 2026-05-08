#!/bin/bash

set -e

BUILD_DIR=out
mkdir -p $BUILD_DIR

cmake -S . -B $BUILD_DIR \
    -DCMAKE_BUILD_TYPE=Release

cmake --build $BUILD_DIR -j$(sysctl -n hw.ncpu)