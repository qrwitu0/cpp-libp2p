




add_executable(test_uv unsigned_varint_test.cpp)
target_link_libraries( test_uv libp2p Boost::boost)

add_test(NAME test_abc COMMAND  test_uv )