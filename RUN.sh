#!/bin/bash

#to run this program, u need to write in console: source RUN.sh"

cmake -H. -Bbuild
cmake --build build -- -j3
./build/Modem

