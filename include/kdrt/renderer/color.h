#pragma once

#include <cmath>
#include <iostream>

namespace kdrt::renderer {
    class Color {
    public:
        double red;
        double green;
        double blue;

        Color();
        Color(double r, double g, double b);

        Color &operator+=(const Color &c);

    };

    inline double linear_to_gamma(double linear_component) {
        if (linear_component > 0) {
            return std::sqrt(linear_component);
        }
        return 0;
    }

    inline Color operator+(const Color &u, const Color &v) {
        return Color(u.red + v.red, u.green + v.green, u.blue + v.blue);
    }

    inline Color operator-(const Color &u, const Color &v) {
        return Color(u.red - v.red, u.green - v.green, u.blue - v.blue);
    }

    inline Color operator*(const Color &u, const Color &v) {
        return Color(u.red * v.red, u.green * v.green, u.blue * v.blue);
    }

    inline Color operator*(double t, const Color &c) {
        return Color(t * c.red, t * c.green, t * c.blue);
    }

    inline Color operator*(const Color &v, double t) {
        return t * v;
    }

    void write_color(std::ostream &out, const Color &pixel_color);
}