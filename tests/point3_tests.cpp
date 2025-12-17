#include <gtest/gtest.h>

#include "kdrt/renderer/point3.h"

TEST(Point3, empty_ctor) {
    const kdrt::renderer::Point3 point = kdrt::renderer::Point3{};

    ASSERT_EQ(point.x, 0.0);
    ASSERT_EQ(point.y, 0.0);
    ASSERT_EQ(point.z, 0.0);
}

TEST(Point3, all_components_ctor) {
    const kdrt::renderer::Point3 point = kdrt::renderer::Point3{1, 2, 3};

    ASSERT_EQ(point.x, 1.0);
    ASSERT_EQ(point.y, 2.0);
    ASSERT_EQ(point.z, 3.0);
}