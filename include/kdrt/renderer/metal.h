#pragma once

#include "kdrt/renderer/color.h"
#include "kdrt/renderer/hitrecord.h"
#include "kdrt/renderer/material.h"
#include "kdrt/renderer/ray.h"

namespace kdrt::renderer {
    class Metal : public Material {
    public:
        Metal(const Color &albedo, double fuzz);

        bool scatter(const Ray &r_in, const HitRecord &rec, Color &attenuation, Ray &scattered) const override;

    private:
        Color albedo;
        double fuzz;
    };
}
