#!/bin/bash

cmake -H. -Bbuild
cmake --build build -- -j3
./bin/Modem


