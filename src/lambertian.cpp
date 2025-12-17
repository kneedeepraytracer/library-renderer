#include "kdrt/renderer/lambertian.h"

#include "kdrt/renderer/color.h"
#include "kdrt/renderer/hitrecord.h"
#include "kdrt/renderer/material.h"
#include "kdrt/renderer/ray.h"
#include "kdrt/renderer/vector3.h"

namespace kdrt::renderer {
    Lambertian::Lambertian(const Color &albedo) : albedo(albedo) {}

    bool Lambertian::scatter(const Ray &r_in, const HitRecord &rec, Color &attenuation, Ray &scattered) const {
        Vector3 scatter_direction = rec.normal + random_unit_vector();

        // Catch degenerate scatter direction
        if (scatter_direction.near_zero()) {
            scatter_direction = rec.normal;
        }

        scattered = Ray(rec.p, scatter_direction, r_in.time());
        attenuation = albedo;
        return true;
    }
}