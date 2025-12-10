#include <gtest/gtest.h>

#include "kdrt/renderer/vector3.h"

TEST(Vector3, empty_ctor) {
    const kdrt::renderer::Vector3 vec = kdrt::renderer::Vector3{};

    ASSERT_EQ(vec.e[0], 0.0);
    ASSERT_EQ(vec.e[1], 0.0);
    ASSERT_EQ(vec.e[2], 0.0);
}

TEST(Vector3, all_components_ctor) {
    const kdrt::renderer::Vector3 vec = kdrt::renderer::Vector3{1, 2, 3};

    ASSERT_EQ(vec.e[0], 1.0);
    ASSERT_EQ(vec.e[1], 2.0);
    ASSERT_EQ(vec.e[2], 3.0);
}
