#include "kdrt/renderer/point3.h"

namespace kdrt::renderer {
    Point3::Point3() : x{0}, y{0}, z{0} {}
    Point3::Point3(double x, double y, double z) : x{x}, y{y}, z{z} {}
    //Point3::Point3(Vector3 vec) : Vector3{vec.e[0], vec.e[1], vec.e[2]} {}

    std::string Point3::to_string() const {
        return fmt::format("Point3{{ x: {}, y: {}, z: {} }}", x, y, z);
    }
}