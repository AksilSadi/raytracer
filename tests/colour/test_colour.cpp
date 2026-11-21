#include "colour/colour.h"
#include "test_helpers.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("colour returns its red green and blue components") {
    const Colour colour(1, 0.5, 0);

    CHECK(colour.r() == 1);
    CHECK(colour.g() == 0.5);
    CHECK(colour.b() == 0);
}

TEST_CASE("scaling a colour scales all of its components") {
    const Colour scaled = 0.5 * Colour(1, 0.5, 0);

    requireColoursEqual(scaled, Colour(0.5, 0.25, 0));
}
