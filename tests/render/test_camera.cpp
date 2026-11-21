#include "render/camera.h"
#include "test_helpers.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("camera creates a ray through the centre of its screen") {
    const Camera camera(Vector(0, 0, -1), Vector(0, 0, 0), 2);
    const Ray ray = camera.rayThroughCentre();

    requireVectorsEqual(ray.origin(), Vector(0, 0, -1));
    requireVectorsEqual(ray.direction(), Vector(0, 0, 1));
}

TEST_CASE("camera creates a ray with a three four five direction") {
    const Camera camera(Vector(1, 2, -1), Vector(4, 6, -1), 2);
    const Ray ray = camera.rayThroughCentre();

    requireVectorsEqual(ray.origin(), Vector(1, 2, -1));
    requireVectorsEqual(ray.direction(), Vector(3, 4, 0));
}

TEST_CASE("camera creates a ray through the centre pixel") {
    const Camera camera(Vector(0, 0, -1), Vector(0, 0, 0), 5);
    const Ray ray = camera.rayThroughPixel(2, 1, 5, 3);

    requireVectorsEqual(ray.origin(), Vector(0, 0, -1));
    requireVectorsEqual(ray.direction(), Vector(0, 0, 1));
}

TEST_CASE("camera creates a ray through the top-right pixel") {
    const Camera camera(Vector(0, 0, -1), Vector(0, 0, 0), 5);
    const Ray ray = camera.rayThroughPixel(4, 0, 5, 3);

    requireVectorsEqual(ray.origin(), Vector(0, 0, -1));
    requireVectorsEqual(ray.direction(), Vector(2, 1, 1));
}

TEST_CASE("camera creates a ray through the bottom-left pixel") {
    const Camera camera(Vector(0, 0, -1), Vector(0, 0, 0), 5);
    const Ray ray = camera.rayThroughPixel(0, 2, 5, 3);

    requireVectorsEqual(ray.origin(), Vector(0, 0, -1));
    requireVectorsEqual(ray.direction(), Vector(-2, -1, 1));
}
