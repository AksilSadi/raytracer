#pragma once

#include "geometry/hit.h"
#include "geometry/ray.h"

#include <optional>

class Shape {
public:
    virtual ~Shape() = default;

    // Returns the nearest hit in front of the ray's origin (t > 0), with a unit normal, or nothing.
    virtual std::optional<Hit> hit(const Ray& ray) const = 0;
};
