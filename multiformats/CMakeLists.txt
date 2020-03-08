


file(GLOB HEADERS "include/multiformats/*.hpp")

add_library( multiformats
#        src/unsigned_varint.cpp
        src/multibase.cpp
        src/multihash.cpp
        ${HEADERS}
        )

target_include_directories( multiformats
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")



