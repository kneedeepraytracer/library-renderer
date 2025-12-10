#pragma once

#include <cmath>
#include <iostream>
#include <string>

#include <fmt/format.h>

#include "kdrt/renderer/utils.h"

namespace kdrt::renderer {
    class Vector3 {
    public:
        double e[3];

        Vector3();
        Vector3(double e0, double e1, double e2);

        Vector3 operator-() const;
        double operator[](int i) const;
        double &operator[](int i);
        Vector3 &operator+=(const Vector3 &v);
        Vector3 &operator*=(double t);
        Vector3 &operator/=(double t);

        double length() const;
        double length_squared() const;
        bool near_zero() const;

        static Vector3 random();
        static Vector3 random(double min, double max);

        std::string to_string() const;
    };

    // Vector3 Utility Functions
    inline std::ostream &operator<<(std::ostream &out, const Vector3 &v) {
        return out << v.e[0] << " " << v.e[1] << " " << v.e[2];
    }

    inline Vector3 operator+(const Vector3 &u, const Vector3 &v) {
        return Vector3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
    }

    inline Vector3 operator-(const Vector3 &u, const Vector3 &v) {
        return Vector3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
    }

    inline Vector3 operator*(const Vector3 &u, const Vector3 &v) {
        return Vector3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
    }

    inline Vector3 operator*(double t, const Vector3 &v) {
        return Vector3(t * v.e[0], t * v.e[1], t * v.e[2]);
    }

    inline Vector3 operator*(const Vector3 &v, double t) {
        return t * v;
    }

    inline Vector3 operator/(const Vector3 &v, double t) {
        return (1 / t) * v;
    }

    inline double dot(const Vector3 &u, const Vector3 &v) {
        return (u.e[0] * v.e[0]) + (u.e[1] * v.e[1]) + (u.e[2] * v.e[2]);
    }

    inline Vector3 cross(const Vector3 &u, const Vector3 &v) {
        return Vector3(
                (u.e[1] * v.e[2]) - (u.e[2] * v.e[1]),
                (u.e[2] * v.e[0]) - (u.e[0] * v.e[2]),
                (u.e[0] * v.e[1]) - (u.e[1] * v.e[0])
        );
    }

    inline Vector3 unit_vector(const Vector3 &v) {
        return v / v.length();
    }

    inline Vector3 random_unit_vector() {
        while (true) {
            Vector3 p = Vector3::random(-1, 1);
            double lensq = p.length_squared();
            if (zeroish < lensq && lensq <= 1) {
                return p / sqrt(lensq);
            }
        }
    }

    inline Vector3 random_in_unit_disk() {
        while (true) {
            Vector3 p = Vector3(random_double(-1, 1), random_double(-1, 1), 0);
            if (p.length_squared() < 1) {
                return p;
            }
        }
    }

    inline Vector3 random_on_hemisphere(const Vector3 &normal) {
        Vector3 on_unit_sphere = random_unit_vector();
        if (dot(on_unit_sphere, normal) > 0.0) {
            return on_unit_sphere;
        } else {
            return -on_unit_sphere;
        }
    }

    inline Vector3 reflect(const Vector3 &v, const Vector3 &n) {
        return v - (2 * dot(v, n) * n);
    }

    inline Vector3 refract(const Vector3 &uv, const Vector3 &n, double etai_over_etat) {
        double cos_theta = std::fmin(dot(-uv, n), 1.0);
        Vector3 r_out_perp = etai_over_etat * (uv + (cos_theta * n));
        Vector3 r_out_parallel = -std::sqrt(std::fabs(1.0 - r_out_perp.length_squared())) * n;
        return r_out_perp + r_out_parallel;
    }
}
