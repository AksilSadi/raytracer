#include "geometry/plane.h"
#include "geometry/sphere.h"
#include "material/material.h"
#include "scene/scene.h"
#include "test_helpers.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <memory>
#include <optional>

TEST_CASE("scene normalises the light direction") {
    const Scene scene(Vector(0, 3, -4));

    requireVectorsEqual(scene.toLight(), Vector(0, 0.6, -0.8));
}

TEST_CASE("scene returns the nearer plane added second") {
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    Scene scene(Vector(0, 0, -1));
    scene.add(std::make_unique<Sphere>(Vector(0, 0, 9), 5, Material(Colour(1, 0, 0))));
    scene.add(std::make_unique<Plane>(
        Vector(0, 0, 2), Vector(0, 0, -1), Material(Colour(0, 0, 1))));

    const std::optional<Hit> hit = scene.nearestHit(ray);

    REQUIRE(hit.has_value());
    REQUIRE_THAT(hit->t, Catch::Matchers::WithinAbs(3, tolerance));
    requireColoursEqual(hit->material.colour(), Colour(0, 0, 1));
}

TEST_CASE("scene returns the nearer sphere added first") {
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    Scene scene(Vector(0, 0, -1));
    scene.add(std::make_unique<Sphere>(Vector(0, 0, 9), 5, Material(Colour(1, 0, 0))));
    scene.add(std::make_unique<Plane>(
        Vector(0, 0, 20), Vector(0, 0, -1), Material(Colour(0, 0, 1))));

    const std::optional<Hit> hit = scene.nearestHit(ray);

    REQUIRE(hit.has_value());
    REQUIRE_THAT(hit->t, Catch::Matchers::WithinAbs(5, tolerance));
    requireColoursEqual(hit->material.colour(), Colour(1, 0, 0));
}

TEST_CASE("scene returns no hit when the ray misses every shape") {
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    Scene scene(Vector(0, 0, -1));
    scene.add(std::make_unique<Sphere>(Vector(6, 0, 9), 5, Material(Colour(1, 0, 0))));

    REQUIRE_FALSE(scene.nearestHit(ray).has_value());
}
