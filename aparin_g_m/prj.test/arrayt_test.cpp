#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <arrayt/arrayt.hpp>
#include <iostream>

typedef double T;
TEST_CASE("[arrayd] - ArrayT<T> ctor") {
    ArrayT<T> a(3);
    a = ArrayT<T>();
    CHECK_THROWS(a = ArrayT<T>(-3));
}


TEST_CASE("[arrayd] - ArrayT<T> size & capacity") {
    ArrayT<T> a(1, 0.0);
    CHECK(a[0] == 0.0);
    a.insert(2, 2);
    CHECK(a[2] == 2.0);
    a.insert(1, 3);
    CHECK(a[1] == 3.0);
    CHECK(a[2] == 1.0);
    a.remove(0);
    CHECK(a[1] == 1.0);
}
