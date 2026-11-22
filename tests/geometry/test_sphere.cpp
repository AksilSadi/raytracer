#include "geometry/sphere.h"
#include "material/material.h"
#include "test_helpers.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("sphere at (0, 0, 9) is hit by the camera ray") {
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    const Sphere sphere(Vector(0, 0, 9), 5, Material(Colour(1, 0, 0)));

    REQUIRE(sphere.isHitBy(ray));
}

TEST_CASE("sphere at (3, 0, 9) is hit by the camera ray") {
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    const Sphere sphere(Vector(3, 0, 9), 5, Material(Colour(1, 0, 0)));

    REQUIRE(sphere.isHitBy(ray));
}

TEST_CASE("sphere at (6, 0, 9) is missed by the camera ray") {
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    const Sphere sphere(Vector(6, 0, 9), 5, Material(Colour(1, 0, 0)));

    REQUIRE_FALSE(sphere.isHitBy(ray));
}

TEST_CASE("sphere behind the camera is missed by the camera ray") {
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    const Sphere sphere(Vector(0, 0, -11), 5, Material(Colour(1, 0, 0)));

    REQUIRE_FALSE(sphere.isHitBy(ray));
}

TEST_CASE("sphere returns its colour") {
    const Colour expectedColour(1, 0.5, 0);
    const Sphere sphere(Vector(0, 0, 9), 5, Material(expectedColour));
    const Colour actualColour = sphere.colour();

    requireColoursEqual(actualColour, expectedColour);
}
