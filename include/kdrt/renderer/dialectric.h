#pragma once

#include "kdrt/renderer/color.h"
#include "kdrt/renderer/hitrecord.h"
#include "kdrt/renderer/material.h"
#include "kdrt/renderer/ray.h"

namespace kdrt::renderer {
    class Dielectric : public Material {
    public:
        Dielectric(double refraction_index);

        bool scatter(const Ray &r_in, const HitRecord &rec, Color &attenuation, Ray &scattered) const override;

    private:
        // Refractive index in vacuum or air, or the ratio of the material's refractive index over
        // the refractive index of the enclosing media
        double refraction_index;

        static double reflectance(double cosine, double refraction_index);
    };
}
