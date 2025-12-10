#include <gtest/gtest.h>

#include "kdrt/renderer/point3.h"

TEST(Point3, empty_ctor) {
    const kdrt::renderer::Point3 point = kdrt::renderer::Point3{};

    ASSERT_EQ(point.e[0], 0.0);
    ASSERT_EQ(point.e[1], 0.0);
    ASSERT_EQ(point.e[2], 0.0);
}

TEST(Point3, all_components_ctor) {
    const kdrt::renderer::Point3 point = kdrt::renderer::Point3{1, 2, 3};

    ASSERT_EQ(point.e[0], 1.0);
    ASSERT_EQ(point.e[1], 2.0);
    ASSERT_EQ(point.e[2], 3.0);
}