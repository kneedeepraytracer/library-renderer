#pragma once

#include <fmt/format.h>

#include "kdrt/renderer/point3.h"
#include "kdrt/renderer/vector3.h"

namespace kdrt::renderer {
    class Ray {
    public:
        Ray();
        Ray(const Point3& origin, const Vector3& direction);

        const Point3& origin() const;
        const Vector3& direction() const;

        Point3 at(double t) const;
        std::string to_string() const;

    private:
        Point3 orig;
        Vector3 dir;
    };
}
