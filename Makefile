PROXY_WASM_CPP_SDK=/sdk

all: cliregplugin.wasm
	chown ${uid}.${gid} $^

ifdef NO_CONTEXT
  CPP_CONTEXT_LIB =
else
  CPP_CONTEXT_LIB = ${PROXY_WASM_CPP_SDK}/proxy_wasm_intrinsics.cc
endif

SRC	= $(wildcard ./src/*.cc)


%.wasm: ${SRC} ${PROXY_WASM_CPP_SDK}/proxy_wasm_intrinsics.h ${PROXY_WASM_CPP_SDK}/proxy_wasm_enums.h ${PROXY_WASM_CPP_SDK}/proxy_wasm_externs.h ${PROXY_WASM_CPP_SDK}/proxy_wasm_api.h ${PROXY_WASM_CPP_SDK}/proxy_wasm_intrinsics.js ${CPP_CONTEXT_LIB}
	em++ --no-entry -s EXPORTED_FUNCTIONS=['_malloc'] --std=c++17 -O3 -flto -DPROXY_WASM_PROTOBUF_LITE=1 -I${PROXY_WASM_CPP_SDK} -I/usr/local/include --js-library ${PROXY_WASM_CPP_SDK}/proxy_wasm_intrinsics.js ${SRC} ${PROXY_WASM_CPP_SDK}/proxy_wasm_intrinsics_lite.pb.cc ${PROXY_WASM_CPP_SDK}/struct_lite.pb.cc ${CPP_CONTEXT_LIB} ${PROXY_WASM_CPP_SDK}/libprotobuf-lite.a -o $*.wasm

clean:
	rm *.wasm
