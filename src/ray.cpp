#include "ray.h"

#include "point3.h"
#include "vector3.h"

namespace kdrt::renderer {
    Ray::Ray() {}
    Ray::Ray(const Point3& origin, const Vector3& direction) : orig(origin), dir(direction) {}

    const Point3& Ray::origin() const { return orig; }
    const Vector3& Ray::direction() const { return dir; }

    Point3 Ray::at(double t) const {
        return orig + (t * dir);
    }

    std::string Ray::to_string() const {
        return fmt::format("Ray{{ orig: {}, dir: {} }}", orig.to_string(), dir.to_string());
    }
}