#include "kdrt/renderer/frame.h"

#include <cstdint>
#include <vector>

#include <spdlog/spdlog.h>

#include "kdrt/renderer/color.h"

namespace kdrt::renderer {
    Frame::Frame(uint width, uint height) : width{width}, height{height}, pixels{width * height} {}

    uint Frame::get_width() { return width; }
    uint Frame::get_height() { return height; }

    Color Frame::get_pixel(uint x, uint y) {
        return pixels[calc_loc(x, y)];
    }

    void Frame::set_pixel(uint x, uint y, Color color) {
        spdlog::trace("x: {}, y: {}, Color: {}", x, y, color.to_string());
        pixels[calc_loc(x, y)] = color;
    }

    uint Frame::calc_loc(uint x, uint y) {
        return x + (y * width);
    }
}