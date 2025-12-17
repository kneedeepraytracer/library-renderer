#pragma once

#include <memory>
#include <vector>

#include "kdrt/renderer/aabb.h"
#include "kdrt/renderer/hittable.h"
#include "kdrt/renderer/interval.h"
#include "kdrt/renderer/ray.h"

namespace kdrt::renderer {
    class HittableList : public Hittable {
    public:
        std::vector<std::shared_ptr<Hittable>> objects;

        HittableList();
        HittableList(std::shared_ptr<Hittable> object);

        void clear();

        void add(std::shared_ptr<Hittable> object);

        bool hit(const Ray &r, Interval ray_t, HitRecord &rec) const override;

        AABB bounding_box() const override;

    private:
        AABB bbox;
    };
}