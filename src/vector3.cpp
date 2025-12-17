#include "kdrt/renderer/vector3.h"

#include <cmath>
#include <iostream>
#include <string>

#include <fmt/format.h>

#include "kdrt/renderer/utils.h"

namespace kdrt::renderer {
    Vector3::Vector3() : x{0}, y{0}, z{0} {}
    Vector3::Vector3(double x, double y, double z) : x{x}, y{y}, z{z} {}

    Vector3 Vector3::operator-() const { return Vector3(-x, -y, -z); }

    Vector3 &Vector3::operator+=(const Vector3 &v) {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    Vector3 &Vector3::operator*=(double t) {
        x *= t;
        y *= t;
        z *= t;
        return *this;
    }

    Vector3 &Vector3::operator/=(double t) {
        return *this *= 1 / t;
    }

    double Vector3::length_squared() const {
        return (x * x) + (y * y) + (z * z);
    }

    double Vector3::length() const {
        return std::sqrt(length_squared());
    }

    bool Vector3::near_zero() const {
        // Return true if the vector is close to zero in all dimensions
        double s = 1e-8; // FIMXE: Should this be the 'zeroish' value?
        return (std::fabs(x) < s) && (std::fabs(y) < s) && (std::fabs(z) < s);
    }

    Vector3 Vector3::random() {
        return Vector3(random_double(), random_double(), random_double());
    }

    Vector3 Vector3::random(double min, double max) {
        return Vector3(random_double(min, max), random_double(min, max), random_double(min, max));
    }

    std::string Vector3::to_string() const {
        return fmt::format("Vector3{{ x: {}, y: {}, z: {} }}", x, y, z);
    }
}
