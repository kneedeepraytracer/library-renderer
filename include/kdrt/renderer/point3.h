#pragma once

#include "kdrt/renderer/vector3.h"

namespace kdrt::renderer {

    class Point3 : public Vector3 {
    public:
        Point3();
        Point3(double e0, double e1, double e2);
        Point3(Vector3 vec);

        double x() const;
        double y() const;
        double z() const;
    };

    // Vector3 Utility Functions
    inline std::ostream &operator<<(std::ostream &out, const Point3 &v) {
        return out << v.e[0] << " " << v.e[1] << " " << v.e[2];
    }

    inline Point3 operator+(const Point3 &u, const Vector3 &v) {
        return Point3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
    }

    inline Point3 operator-(const Point3 &u, const Vector3 &v) {
        return Point3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
    }

    inline Point3 operator*(const Point3 &u, const Vector3 &v) {
        return Point3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
    }

    inline Point3 operator*(double t, const Point3 &v) {
        return Point3(t * v.e[0], t * v.e[1], t * v.e[2]);
    }

    inline Point3 operator*(const Point3 &v, double t) {
        return t * v;
    }

    inline Point3 operator/(const Point3 &v, double t) {
        return (1 / t) * v;
    }

//    inline Vector3 random_in_unit_disk() {
//        while (true) {
//            Vector3 p = Vector3(random_double(-1, 1), random_double(-1, 1), 0);
//            if (p.length_squared() < 1) {
//                return p;
//            }
//        }
//    }

//    inline Vector3 random_on_hemisphere(const Vector3 &normal) {
//        Vector3 on_unit_sphere = random_unit_vector();
//        if (dot(on_unit_sphere, normal) > 0.0) {
//            return on_unit_sphere;
//        } else {
//            return -on_unit_sphere;
//        }
//    }

}
