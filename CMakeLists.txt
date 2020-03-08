

project(libp2p)
include(CTest)

cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)

file(GLOB HEADERS "include/libp2p/multiformats/*.hpp"
                  "include/bc/utils/*.hpp")

add_library( libp2p
        src/multiformats/unsigned_varint.cpp
        src/multiformats/multibase.cpp
        ${HEADERS}
)


target_include_directories( libp2p
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")


add_subdirectory(tests)