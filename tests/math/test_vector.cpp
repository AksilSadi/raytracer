#include "math/vector.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

const double tolerance = 1e-9;

static void requireVectorsEqual(const Vector& actual, const Vector& expected) {
    CHECK_THAT(actual.x(), Catch::Matchers::WithinAbs(expected.x(), tolerance));
    CHECK_THAT(actual.y(), Catch::Matchers::WithinAbs(expected.y(), tolerance));
    CHECK_THAT(actual.z(), Catch::Matchers::WithinAbs(expected.z(), tolerance));
}

TEST_CASE("adding vectors adds their coordinates") {
    const Vector first(3, 4, 0);
    const Vector second(4, -3, 0);
    const Vector result = first + second;

    requireVectorsEqual(result, Vector(7, 1, 0));
}

TEST_CASE("adding vectors includes a non-zero z coordinate") {
    const Vector first(3, 4, 1);
    const Vector second(4, -3, 2);
    const Vector result = first + second;

    requireVectorsEqual(result, Vector(7, 1, 3));
}

TEST_CASE("subtracting vectors subtracts their coordinates") {
    const Vector first(4, 5, 0);
    const Vector second(1, 1, 0);
    const Vector result = first - second;

    requireVectorsEqual(result, Vector(3, 4, 0));
}

TEST_CASE("subtracting vectors includes a non-zero z coordinate") {
    const Vector first(4, 5, 6);
    const Vector second(1, 1, 2);
    const Vector result = first - second;

    requireVectorsEqual(result, Vector(3, 4, 4));
}

TEST_CASE("a vector can be scaled by a number on the left") {
    const Vector result = 2.0 * Vector(3, -4, 1);

    requireVectorsEqual(result, Vector(6, -8, 2));
}

TEST_CASE("the ray equation evaluates origin plus t times direction") {
    const Vector O(0, 8, 0);
    const Vector D(3, -4, 0);
    const double t = 2;
    const Vector result = O + t * D;

    requireVectorsEqual(result, Vector(6, 0, 0));
}

TEST_CASE("dot product multiplies and adds coordinates") {
    const Vector first(3, 4, 0);
    const Vector second(4, 3, 0);

    CHECK(first.dot(second) == 24);
}

TEST_CASE("dot product can be zero") {
    const Vector first(3, 4, 0);
    const Vector second(4, -3, 0);

    CHECK(first.dot(second) == 0);
}

TEST_CASE("dot product includes non-zero z coordinates") {
    const Vector first(3, 4, 12);
    const Vector second(4, 3, 1);

    CHECK(first.dot(second) == 36);
}

TEST_CASE("length is the magnitude of the vector") {
    const Vector vector(3, -4, 0);

    CHECK(vector.length() == 5);
}

TEST_CASE("length includes a non-zero z coordinate") {
    const Vector vector(3, 4, 12);

    CHECK(vector.length() == 13);
}

TEST_CASE("normalised returns a vector in the same direction with length one") {
    const Vector result = Vector(3, -4, 0).normalised();

    requireVectorsEqual(result, Vector(0.6, -0.8, 0));
}

TEST_CASE("normalised vectors have length one") {
    CHECK_THAT(Vector(3, 4, 12).normalised().length(),
               Catch::Matchers::WithinAbs(1, tolerance));
}
