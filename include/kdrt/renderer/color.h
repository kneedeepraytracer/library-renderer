#pragma once

#include <iostream>

#include "vector3.h"

namespace kdrt::renderer {
    class Color : public Vector3 {

    };

    inline double linear_to_gamma(double linear_component) {
        if (linear_component > 0) {
            return std::sqrt(linear_component);
        }
        return 0;
    }

    void write_color(std::ostream &out, const Color &pixel_color);
}