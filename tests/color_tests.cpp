#include <gtest/gtest.h>

#include "kdrt/renderer/color.h"

TEST(Color, empty_ctor) {
    const kdrt::renderer::Color color = kdrt::renderer::Color{};

    ASSERT_EQ(color.red, 0.0);
    ASSERT_EQ(color.green, 0.0);
    ASSERT_EQ(color.blue, 0.0);
}

TEST(Color, all_components_ctor) {
    const kdrt::renderer::Color color = kdrt::renderer::Color{1, 2, 3};

    ASSERT_EQ(color.red, 1.0);
    ASSERT_EQ(color.green, 2.0);
    ASSERT_EQ(color.blue, 3.0);
}
