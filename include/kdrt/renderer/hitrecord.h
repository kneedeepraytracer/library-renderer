#pragma once

#include <memory>

#include "kdrt/renderer/ray.h"
#include "kdrt/renderer/vector3.h"

namespace kdrt::renderer {
    // FIXME: I don't like the circular reference here.
    //        Probably shouldn't be using the HitRecord in the material itself...
    class Material;

    class HitRecord {
    public:
        Point3 p;
        Vector3 normal;
        std::shared_ptr<Material> mat;
        double t;
        bool front_face;

        void set_face_normal(const Ray &r, const Vector3 &outward_normal);
    };
}
