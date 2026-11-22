#include "geometry/sphere.h"
#include "material/material.h"
#include "render/trace.h"
#include "scene/scene.h"
#include "test_helpers.h"

#include <catch2/catch_test_macros.hpp>
#include <memory>

TEST_CASE("trace returns full colour when the hit faces the sun") {
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    Scene scene(Vector(0, 0, -1));
    scene.add(std::make_unique<Sphere>(Vector(0, 0, 9), 5, Material(Colour(1, 0, 0))));

    const Colour pixel = trace(ray, scene);

    requireColoursEqual(pixel, Colour(1, 0, 0));
}

TEST_CASE("trace shades a centred sphere lit at an angle") {
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    Scene scene(Vector(0.6, 0, -0.8));
    scene.add(std::make_unique<Sphere>(Vector(0, 0, 9), 5, Material(Colour(1, 0, 0))));

    const Colour pixel = trace(ray, scene);

    requireColoursEqual(pixel, Colour(0.8, 0, 0));
}

TEST_CASE("trace shades an off-centre sphere lit from behind the camera") {
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    Scene scene(Vector(0, 0, -1));
    scene.add(std::make_unique<Sphere>(Vector(3, 0, 9), 5, Material(Colour(1, 0, 0))));

    const Colour pixel = trace(ray, scene);

    requireColoursEqual(pixel, Colour(0.8, 0, 0));
}

TEST_CASE("trace returns black when the ray misses") {
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    Scene scene(Vector(0, 0, -1));
    scene.add(std::make_unique<Sphere>(Vector(6, 0, 9), 5, Material(Colour(1, 0, 0))));

    const Colour pixel = trace(ray, scene);

    requireColoursEqual(pixel, Colour(0, 0, 0));
}
