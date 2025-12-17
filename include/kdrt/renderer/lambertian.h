#pragma once

#include "kdrt/renderer/color.h"
#include "kdrt/renderer/hitrecord.h"
#include "kdrt/renderer/material.h"
#include "kdrt/renderer/ray.h"

namespace kdrt::renderer {
    class Lambertian : public Material {
    public:
        Lambertian(const Color &albedo);

        bool scatter(const Ray &r_in, const HitRecord &rec, Color &attenuation, Ray &scattered) const override;

    private:
        Color albedo;
    };
}
