#!/bin/bash

if [[ ! -d build ]]; then
    mkdir -v build
fi

cd build
cmake ..
cd ..
cmake --build build --target procsock-shared -- -j 4
cmake --build build --target procsock-static -- -j 4
