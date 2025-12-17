#pragma once

#include "kdrt/renderer/interval.h"
#include "kdrt/renderer/ray.h"

namespace kdrt::renderer {
    class AABB {
    public:
        Interval x;
        Interval y;
        Interval z;

        AABB();
        AABB(const Interval &x, const Interval &y, const Interval &z);
        AABB(const Point3 &a, const Point3 &b);
        AABB(const AABB &a, const AABB &b);

        const Interval &axis_interval(int n) const;

        bool hit(const Ray &r, Interval ray_t) const;

        int longest_axis() const;

        static const AABB empty;
        static const AABB universe;
    };
}
