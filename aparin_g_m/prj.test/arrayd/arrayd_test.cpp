#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <arrayd/arrayd.hpp>

#include <doctest/doctest.h>


TEST_CASE("checking arithmetic") {
    CHECK(a + b == sum);
    CHECK(a - b == dif);
    CHECK(a * b == prod);
    CHECK(a / b == divisions);
}

