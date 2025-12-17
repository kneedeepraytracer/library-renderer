#pragma once

#include "kdrt/renderer/aabb.h"
#include "kdrt/renderer/interval.h"
#include "kdrt/renderer/hitrecord.h"
#include "kdrt/renderer/ray.h"

namespace kdrt::renderer {
    class Hittable {
    public:
        virtual ~Hittable() = default;

        virtual bool hit(const Ray &r, Interval ray_t, HitRecord &rec) const = 0;

        virtual AABB bounding_box() const = 0;
    };
}