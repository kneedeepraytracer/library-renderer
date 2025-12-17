#pragma once

#include <algorithm>
#include <memory>
#include <vector>

#include "kdrt/renderer/aabb.h"
#include "kdrt/renderer/hittable.h"
#include "kdrt/renderer/hittable_list.h"

namespace kdrt::renderer {
    class BvhNode : public Hittable {
    public:
        BvhNode(HittableList list);

        BvhNode(std::vector<std::shared_ptr<Hittable>> &objects, size_t start, size_t end);

        bool hit(const Ray &r, Interval ray_t, HitRecord &rec) const override;

        AABB bounding_box() const override;

    private:
        std::shared_ptr<Hittable> left;
        std::shared_ptr<Hittable> right;
        AABB bbox;

        static bool box_compare(const std::shared_ptr<Hittable> a, const std::shared_ptr<Hittable> b, int axis_index);
        static bool box_x_compare(const std::shared_ptr<Hittable> a, const std::shared_ptr<Hittable> b);
        static bool box_y_compare(const std::shared_ptr<Hittable> a, const std::shared_ptr<Hittable> b);
        static bool box_z_compare(const std::shared_ptr<Hittable> a, const std::shared_ptr<Hittable> b);
    };
}
