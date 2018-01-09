#!/bin/bash
rm c_*
# rm m_*

cmake -H. -Bbuild
cmake --build build -- -j3
./build/modem

