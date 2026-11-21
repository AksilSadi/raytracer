#include "material/material.h"
#include "test_helpers.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("a material facing the light returns its whole colour") {
    const Material material(Colour(1, 0.5, 0));

    requireColoursEqual(material.colour(), Colour(1, 0.5, 0));
    requireColoursEqual(
        material.shade(Vector(0, 0, -1), Vector(0, 0, -1)),
        Colour(1, 0.5, 0)
    );
}

TEST_CASE("a material facing the light at an angle returns a shaded colour") {
    const Material material(Colour(1, 0.5, 0));

    requireColoursEqual(
        material.shade(Vector(0, 0, -1), Vector(0.6, 0, -0.8)),
        Colour(0.8, 0.4, 0)
    );
}

TEST_CASE("a material perpendicular to the light returns black") {
    const Material material(Colour(1, 0.5, 0));

    requireColoursEqual(
        material.shade(Vector(0, 0, -1), Vector(1, 0, 0)),
        Colour(0, 0, 0)
    );
}

TEST_CASE("a material facing away from the light returns black") {
    const Material material(Colour(1, 0.5, 0));

    requireColoursEqual(
        material.shade(Vector(0, 0, -1), Vector(0, 0, 1)),
        Colour(0, 0, 0)
    );
}
