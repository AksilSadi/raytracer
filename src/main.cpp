#include "colour/colour.h"
#include "render/camera.h"
#include "render/trace.h"
#include "math/vector.h"
#include "geometry/sphere.h"

#include <iostream>

int main() {
    Camera camera(Vector(0, 0, -1), Vector(0, 0, 0));
    Sphere sphere(Vector(0, 0, 9), 5, Colour(1, 0, 0));
    Ray ray = camera.rayThroughCentre();
    Colour pixel = trace(ray, sphere);

    std::cout << "(" << pixel.r() << ", " << pixel.g() << ", " << pixel.b() << ")\n";
    return 0;
}
