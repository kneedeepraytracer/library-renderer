#include "kdrt/renderer/sphere.h"

#include <memory>

#include <spdlog/spdlog.h>

#include "kdrt/renderer/aabb.h"
#include "kdrt/renderer/hitrecord.h"
#include "kdrt/renderer/hittable.h"
#include "kdrt/renderer/interval.h"
#include "kdrt/renderer/material.h"
#include "kdrt/renderer/point3.h"
#include "kdrt/renderer/vector3.h"

namespace kdrt::renderer {
    // Stationary Sphere
    Sphere::Sphere(const Point3 &static_center, double radius, std::shared_ptr<Material> material)
            : center(static_center, Vector3(0, 0, 0))
            , radius(std::fmax(0, radius))
            , mat(material) {
        bbox = AABB(Point3{static_center.x - radius,
                           static_center.y - radius,
                           static_center.z - radius},
                    Point3{static_center.x + radius,
                           static_center.y + radius,
                           static_center.z + radius});
    }

    // Moving Sphere
    Sphere::Sphere(const Point3 &center1, const Point3 &center2, double radius, std::shared_ptr<Material> material)
            : center(center1, Vector3{center2.x - center1.x, center2.y - center1.y, center2.z - center1.z})
            , radius(std::fmax(0, radius))
            , mat(material) {
        //Vector3 rvec = Vector3(radius, radius, radius);
        AABB box1(Point3{center.at(0).x - radius,
                         center.at(0).y - radius,
                         center.at(0).z - radius},
                  Point3{center.at(0).x + radius,
                         center.at(0).y + radius,
                         center.at(0).z + radius});
        AABB box2(Point3{center.at(1).x - radius,
                         center.at(1).y - radius,
                         center.at(1).z - radius},
                  Point3{center.at(1).x + radius,
                         center.at(1).y + radius,
                         center.at(1).z + radius});
        bbox = AABB(box1, box2);
    }

    bool Sphere::hit(const Ray &r, Interval ray_t, HitRecord &rec) const {
        Point3 current_center = center.at(r.time());
        Vector3 oc = Vector3{current_center.x - r.origin().x,
                             current_center.y - r.origin().y,
                             current_center.z - r.origin().z};
        double a = r.direction().length_squared();
        double h = dot(r.direction(), oc);
        double c = oc.length_squared() - (radius * radius);
        double discriminant = (h * h) - (a * c);

        spdlog::trace("Sphere - Hit Check:");
        spdlog::trace(" - center: {}", center.to_string());
        spdlog::trace(" - radius: {}", radius);
        spdlog::trace(" - a: {}", a);
        spdlog::trace(" - h: {}", h);
        spdlog::trace(" - c: {}", c);
        spdlog::trace(" - discriminant: {}", discriminant);
        spdlog::trace(" - r: {}", r.to_string());

        if (discriminant < 0) {
            return false;
        }

        double sqrtd = std::sqrt(discriminant);

        // Find the nearest root that lies on the acceptable range
        double root = (h - sqrtd) / a;
        if (!ray_t.surrounds(root)) {
            root = (h + sqrtd) / a;
            if (!ray_t.surrounds(root)) {
                return false;
            }
        }

        rec.t = root;
        rec.p = r.at(rec.t);
        Vector3 outward_normal = Vector3{rec.p.x - current_center.x,
                                         rec.p.y - current_center.y,
                                         rec.p.z - current_center.z} / radius;
        rec.set_face_normal(r, outward_normal);
        rec.mat = mat;

        spdlog::trace("Hit Detected");
        spdlog::trace(" - sqrtd: {}", sqrtd);
        spdlog::trace(" - root: {}", root);
        spdlog::trace(" - rec.t: {}", rec.t);
        spdlog::trace(" - rec.p: {}", rec.p.to_string());
        spdlog::trace(" - outward_normal: {}", outward_normal.to_string());
        spdlog::trace(" - rec.normal: {}", rec.normal.to_string());
        spdlog::trace(" - rec.front_face: {}", rec.front_face);

        return true;
    }

    AABB Sphere::bounding_box() const { return bbox; }
}
