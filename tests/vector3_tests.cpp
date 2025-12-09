#include <gtest/gtest.h>

#include "kdrt/renderer/vector3.h"

TEST(Vector3, empty_ctor) {
    const kdrt::renderer::Vector3 vec = kdrt::renderer::Vector3{};

    ASSERT_EQ(vec.e[0], 0.0);
    ASSERT_EQ(vec.e[1], 0.0);
    ASSERT_EQ(vec.e[2], 0.0);
}
