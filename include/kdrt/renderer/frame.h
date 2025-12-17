#pragma once

#include <cstdint>
#include <vector>

#include "kdrt/renderer/color.h"

namespace kdrt::renderer {
    class Frame {
    public:
        Frame(uint width, uint height);

        uint get_width();
        uint get_height();

        Color get_pixel(uint x, uint y);
        void set_pixel(uint x, uint y, Color color);

    private:
        uint width;
        uint height;
        std::vector<Color> pixels;

        uint calc_loc(uint x, uint y);
    };
}
