#define BOOST_TEST_MODULE MyTest
#include <boost/test/included/unit_test.hpp>
#include "SIN.h"

// Tests for the sin function definition using Boost Test

BOOST_AUTO_TEST_CASE(origin)
{
    // Test for sin(0) = 0.0
    // Verified using a reliable calculator like an HP15C or a mathematical reference
    BOOST_CHECK_EQUAL(sin(0.0, nullptr), 0.0);
}

BOOST_AUTO_TEST_CASE(fails)
{
    // Check if sin(2 * M_PI) is approximately 0.0 (within a tolerance)
    BOOST_CHECK_SMALL(sin(2 * M_PI, nullptr), 1e-6);  // 1e-6 is the tolerance
}

// White box testing using input domain partitioning
BOOST_AUTO_TEST_CASE(partition1)
{
    // Test for a value in the range [0, PI], like sin(PI/2) = 1.0
    BOOST_CHECK_CLOSE(sin(M_PI / 2, nullptr), 1.0, 1e-6); // 1e-6 tolerance

    // Test for a value in the range (PI, 2*PI], like sin(3*PI/2) = -1.0
    BOOST_CHECK_CLOSE(sin(3 * M_PI / 2, nullptr), -1.0, 1e-6); // 1e-6 tolerance
}

// More tests can be added for additional coverage
