#pragma once

#include <memory>

#include "kdrt/renderer/aabb.h"
#include "kdrt/renderer/hitrecord.h"
#include "kdrt/renderer/hittable.h"
#include "kdrt/renderer/interval.h"
#include "kdrt/renderer/material.h"
#include "kdrt/renderer/point3.h"

namespace kdrt::renderer {
    class Sphere : public Hittable {
    public:
        // Stationary Sphere
        Sphere(const Point3 &static_center, double radius, std::shared_ptr<Material> material);

        // Moving Sphere
        Sphere(const Point3 &center1, const Point3 &center2, double radius, std::shared_ptr<Material> material);

        bool hit(const Ray &r, Interval ray_t, HitRecord &rec) const override;

        AABB bounding_box() const override;

    private:
        Ray center;
        double radius;
        std::shared_ptr<Material> mat;
        AABB bbox;
    };
}
