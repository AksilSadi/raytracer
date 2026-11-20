#include "render/trace.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("trace returns the sphere colour when the ray hits") {
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    const Sphere sphere(Vector(0, 0, 9), 5, Colour(1, 0, 0));

    const Colour pixel = trace(ray, sphere);

    CHECK(pixel.r() == 1);
    CHECK(pixel.g() == 0);
    CHECK(pixel.b() == 0);
}

TEST_CASE("trace returns black when the ray misses") {
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    const Sphere sphere(Vector(6, 0, 9), 5, Colour(1, 0, 0));

    const Colour pixel = trace(ray, sphere);

    CHECK(pixel.r() == 0);
    CHECK(pixel.g() == 0);
    CHECK(pixel.b() == 0);
}
