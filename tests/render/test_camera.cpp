#include "material/material.h"
#include "render/camera.h"
#include "test_helpers.h"

#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

TEST_CASE("camera creates a ray through the centre of its screen") {
    const Camera camera(Vector(0, 0, -1), Vector(0, 0, 0), 2);
    const Ray ray = camera.rayThroughPixel(0, 0, 1, 1);

    requireVectorsEqual(ray.origin(), Vector(0, 0, -1));
    requireVectorsEqual(ray.direction(), Vector(0, 0, 1));
}

TEST_CASE("camera creates a ray with a three four five direction") {
    const Camera camera(Vector(1, 2, -1), Vector(4, 6, -1), 2);
    const Ray ray = camera.rayThroughPixel(0, 0, 1, 1);

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

TEST_CASE("camera renders a red sphere as a shaded plus") {
    const Camera camera(Vector(0, 0, -1), Vector(0, 0, 0), 5);
    const Sphere sphere(Vector(0, 0, 6), 5, Material(Colour(1, 0, 0)));
    const Image image = camera.render(sphere, Vector(0, 0, -1), 5, 3);

    CHECK(image.width() == 5);
    CHECK(image.height() == 3);

    const std::vector<std::string> expected = {
        "..#..",
        ".#O#.",
        "..#..",
    };
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 5; ++column) {
            double red = 0.0;
            if (expected[row][column] == 'O') {
                red = 1.0;
            } else if (expected[row][column] == '#') {
                red = 0.8;
            }
            requireColoursEqual(image.pixel(column, row), Colour(red, 0, 0));
        }
    }
}
