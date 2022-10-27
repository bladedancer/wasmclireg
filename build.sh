#!/bin/sh
rm -f *.wasm
docker run -v $PWD:/work -w /work bladedancer/wasmsdk:v2 /build_wasm.sh