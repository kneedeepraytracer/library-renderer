#pragma once

#include "kdrt/renderer/color.h"
#include "kdrt/renderer/hitrecord.h"
#include "kdrt/renderer/ray.h"

namespace kdrt::renderer {
    class Material {
    public:
        virtual ~Material() = default;

        virtual bool scatter(const Ray &r_in, const HitRecord &rec, Color &attenuation, Ray &scattered) const {
            return false;
        }
    };
}
