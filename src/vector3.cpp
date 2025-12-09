#include "../include/kdrt/renderer/vector3.h"

#include "../include/kdrt/renderer/utils.h"

namespace kdrt::renderer {
    Vector3::Vector3() : e{0, 0, 0} {}
    Vector3::Vector3(double e0, double e1, double e2) : e{e0, e1, e2} {}

    Vector3 Vector3::operator-() const { return Vector3(-e[0], -e[1], -e[2]); }
    double Vector3::operator[](int i) const { return e[i]; }
    double &Vector3::operator[](int i) { return e[i]; }

    Vector3 &Vector3::operator+=(const Vector3 &v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    Vector3 &Vector3::operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    Vector3 &Vector3::operator/=(double t) {
        return *this *= 1 / t;
    }

    double Vector3::length() const {
        return std::sqrt(length_squared());
    }

    double Vector3::length_squared() const {
        return (e[0] * e[0]) + (e[1] * e[1]) + (e[2] * e[2]);
    }

    bool Vector3::near_zero() const {
        // Return true if the vector is close to zero in all dimensions
        double s = 1e-8; // FIMXE: Should this be the 'zeroish' value?
        return (std::fabs(e[0]) < s) && (std::fabs(e[1]) < s) && (std::fabs(e[2]) < s);
    }

    Vector3 Vector3::random() {
        return Vector3(random_double(), random_double(), random_double());
    }

    Vector3 Vector3::random(double min, double max) {
        return Vector3(random_double(min, max), random_double(min, max), random_double(min, max));
    }

    std::string Vector3::to_string() const {
        return fmt::format("Vector3{{ e[0]: {}, e[1]: {}, e[2]: {} }}", e[0], e[1], e[2]);
    }
}
