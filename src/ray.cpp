#include "kdrt/renderer/ray.h"

#include "kdrt/renderer/point3.h"
#include "kdrt/renderer/vector3.h"

namespace kdrt::renderer {
    Ray::Ray() {}
    Ray::Ray(const Point3& origin, const Vector3& direction) : orig(origin), dir(direction), tm(0) {}
    Ray::Ray(const Point3& origin, const Vector3& direction, double time) : orig(origin), dir(direction), tm(time) {}

    const Point3& Ray::origin() const { return orig; }
    const Vector3& Ray::direction() const { return dir; }
    double Ray::time() const { return tm; }

    Point3 Ray::at(double t) const {
        return Point3{
            orig.x + (t * dir.x),
            orig.y + (t * dir.y),
            orig.z + (t * dir.z)
        };
    }

    std::string Ray::to_string() const {
        return fmt::format("Ray{{ orig: {}, dir: {} }}", orig.to_string(), dir.to_string());
    }
}