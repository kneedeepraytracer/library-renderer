#include "kdrt/renderer/point3.h"

namespace kdrt::renderer {
    Point3::Point3() : Vector3{0, 0, 0} {}
    Point3::Point3(double e0, double e1, double e2) : Vector3{e0, e1, e2} {}
    Point3::Point3(Vector3 vec) : Vector3{vec.e[0], vec.e[1], vec.e[2]} {}

    double Point3::x() const { return e[0]; }
    double Point3::y() const { return e[1]; }
    double Point3::z() const { return e[2]; }
}