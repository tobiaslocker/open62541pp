#define BOOST_TEST_MODULE VsidCommonTest
#include <boost/test/included/unit_test.hpp>

#include "open62541.hpp"



#pragma warning (disable : 4068 )

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdisabled-macro-expansion"

BOOST_AUTO_TEST_SUITE( all )

BOOST_AUTO_TEST_CASE( node_id_test )
{
    BOOST_TEST(true);

}

BOOST_AUTO_TEST_CASE( empty )
{
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE( palindrome_tests )

BOOST_AUTO_TEST_CASE( is_palindrome )
{
}

BOOST_AUTO_TEST_SUITE_END()


#pragma clang diagnostic pop
