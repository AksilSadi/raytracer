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
