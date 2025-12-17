#include "kdrt/renderer/aabb.h"

#include "kdrt/renderer/interval.h"
#include "kdrt/renderer/ray.h"
#include "kdrt/renderer/vector3.h"

namespace kdrt::renderer {
    AABB::AABB() {}

    AABB::AABB(const Interval &x, const Interval &y, const Interval &z) : x(x), y(y), z(z) {}

    AABB::AABB(const Point3 &a, const Point3 &b) {
        // Treat the two points a and b as extrema for the bounding box, so we don't require a
        // particular minimum/maximum coordinate order.
        x = (a.x <= b.x) ? Interval(a.x, b.x) : Interval(b.x, a.x);
        y = (a.y <= b.y) ? Interval(a.y, b.y) : Interval(b.y, a.y);
        z = (a.z <= b.z) ? Interval(a.z, b.z) : Interval(b.z, a.z);
    }

    AABB::AABB(const AABB &a, const AABB &b) {
        x = Interval(a.x, b.x);
        y = Interval(a.y, b.y);
        z = Interval(a.z, b.z);
    }

    const Interval &AABB::axis_interval(int n) const {
        if (n == 1) {
            return y;
        }
        if (n == 2) {
            return z;
        }
        return x;
    }

    bool AABB::hit(const Ray &r, Interval ray_t) const {
        const Point3 &ray_orig = r.origin();
        const Vector3 &ray_dir = r.direction();

        {
            const Interval &ax = x;
            const double adinv = 1.0 / ray_dir.x;

            double t0 = (ax.min - ray_orig.x) * adinv;
            double t1 = (ax.max - ray_orig.x) * adinv;

            if (t0 < t1) {
                if (t0 > ray_t.min) {
                    ray_t.min = t0;
                }
                if (t1 < ray_t.max) {
                    ray_t.max = t1;
                }
            } else {
                if (t1 > ray_t.min) {
                    ray_t.min = t1;
                }
                if (t0 < ray_t.max) {
                    ray_t.max = t0;
                }
            }

            if (ray_t.max <= ray_t.min) {
                return false;
            }
        }

        {
            const Interval &ax = y;
            const double adinv = 1.0 / ray_dir.y;

            double t0 = (ax.min - ray_orig.y) * adinv;
            double t1 = (ax.max - ray_orig.y) * adinv;

            if (t0 < t1) {
                if (t0 > ray_t.min) {
                    ray_t.min = t0;
                }
                if (t1 < ray_t.max) {
                    ray_t.max = t1;
                }
            } else {
                if (t1 > ray_t.min) {
                    ray_t.min = t1;
                }
                if (t0 < ray_t.max) {
                    ray_t.max = t0;
                }
            }

            if (ray_t.max <= ray_t.min) {
                return false;
            }
        }

        {
            const Interval &ax = z;
            const double adinv = 1.0 / ray_dir.z;

            double t0 = (ax.min - ray_orig.z) * adinv;
            double t1 = (ax.max - ray_orig.z) * adinv;

            if (t0 < t1) {
                if (t0 > ray_t.min) {
                    ray_t.min = t0;
                }
                if (t1 < ray_t.max) {
                    ray_t.max = t1;
                }
            } else {
                if (t1 > ray_t.min) {
                    ray_t.min = t1;
                }
                if (t0 < ray_t.max) {
                    ray_t.max = t0;
                }
            }

            if (ray_t.max <= ray_t.min) {
                return false;
            }
        }
        return true;
    }

    int AABB::longest_axis() const {
        // Returns the index of the longest axis of the bounding box.
        if (x.size() > y.size()) {
            return x.size() > z.size() ? 0 : 2;
        } else {
            return y.size() > z.size() ? 1 : 2;
        }
    }

    const AABB AABB::empty = AABB(Interval::empty, Interval::empty, Interval::empty);
    const AABB AABB::universe = AABB(Interval::universe, Interval::universe, Interval::universe);
}