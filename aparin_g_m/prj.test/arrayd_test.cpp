#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <arrayd/arrayd.hpp>

#include <doctest/doctest.h>


int len_a = 5;
ArrayD a(len_a);


TEST_CASE("checking") {
    CHECK(a.ssize() == len_a);
    a.resize(len_a + 2);
    CHECK(a.ssize() == len_a + 2);
    for(int i = 0; i < a.ssize(); i++) {
        a.insert(i, i*i);
    }
    CHECK(a[1] == 1);
    CHECK(a[2] == 4);
    CHECK(a[3] == 9);
}


