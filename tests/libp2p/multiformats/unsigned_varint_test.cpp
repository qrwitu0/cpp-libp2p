


#define BOOST_TEST_MODULE My Test



#include <boost/test/included/unit_test.hpp>

#include <libp2p/multiformats/unsigned_varint.hpp>

using libp2p::multiformats::unsigned_varint;

BOOST_AUTO_TEST_SUITE(cfile_test_suite)


BOOST_AUTO_TEST_CASE(first_test)
{
   unsigned_varint v(2);
   BOOST_CHECK_EQUAL(v.to_uint64(),2);
}


BOOST_AUTO_TEST_CASE(second_test)
{
   unsigned_varint v(2);
   BOOST_CHECK_EQUAL(v.to_uint64(),2);
}

BOOST_AUTO_TEST_SUITE_END()

