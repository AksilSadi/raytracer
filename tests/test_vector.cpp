#include "vector.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("adding vectors adds their coordinates") {
    const Vector first(3, 4, 0);
    const Vector second(4, -3, 0);
    const Vector result = first + second;

    CHECK(result.x() == 7);
    CHECK(result.y() == 1);
    CHECK(result.z() == 0);
}

TEST_CASE("adding vectors includes a non-zero z coordinate") {
    const Vector first(3, 4, 1);
    const Vector second(4, -3, 2);
    const Vector result = first + second;

    CHECK(result.x() == 7);
    CHECK(result.y() == 1);
    CHECK(result.z() == 3);
}

TEST_CASE("subtracting vectors subtracts their coordinates") {
    const Vector first(4, 5, 0);
    const Vector second(1, 1, 0);
    const Vector result = first - second;

    CHECK(result.x() == 3);
    CHECK(result.y() == 4);
    CHECK(result.z() == 0);
}

TEST_CASE("subtracting vectors includes a non-zero z coordinate") {
    const Vector first(4, 5, 6);
    const Vector second(1, 1, 2);
    const Vector result = first - second;

    CHECK(result.x() == 3);
    CHECK(result.y() == 4);
    CHECK(result.z() == 4);
}

TEST_CASE("a vector can be scaled by a number on the left") {
    const Vector result = 2.0 * Vector(3, -4, 1);

    CHECK(result.x() == 6);
    CHECK(result.y() == -8);
    CHECK(result.z() == 2);
}

TEST_CASE("the ray equation evaluates origin plus t times direction") {
    const Vector O(0, 8, 0);
    const Vector D(3, -4, 0);
    const double t = 2;
    const Vector result = O + t * D;

    CHECK(result.x() == 6);
    CHECK(result.y() == 0);
    CHECK(result.z() == 0);
}
