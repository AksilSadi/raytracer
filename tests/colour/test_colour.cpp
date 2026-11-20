#include "colour/colour.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("colour returns its red green and blue components") {
    const Colour colour(1, 0.5, 0);

    CHECK(colour.r() == 1);
    CHECK(colour.g() == 0.5);
    CHECK(colour.b() == 0);
}
