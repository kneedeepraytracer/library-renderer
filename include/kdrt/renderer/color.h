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

    };

    inline double linear_to_gamma(double linear_component) {
        if (linear_component > 0) {
            return std::sqrt(linear_component);
        }
        return 0;
    }

    void write_color(std::ostream &out, const Color &pixel_color);
}