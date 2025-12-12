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

TEST(Vector3, minus_operator) {
    const kdrt::renderer::Vector3 vec = kdrt::renderer::Vector3{1, 2, 3};
    const kdrt::renderer::Vector3 vec2 = -vec;

    ASSERT_EQ(vec.e[0], 1.0);
    ASSERT_EQ(vec.e[1], 2.0);
    ASSERT_EQ(vec.e[2], 3.0);

    ASSERT_EQ(vec2.e[0], -1.0);
    ASSERT_EQ(vec2.e[1], -2.0);
    ASSERT_EQ(vec2.e[2], -3.0);
}

TEST(Vector3, plus_equals_operator) {
    const kdrt::renderer::Vector3 vec = kdrt::renderer::Vector3{1, 2, 3};
    kdrt::renderer::Vector3 vec2 = kdrt::renderer::Vector3{3, 2, 1};
    vec2 += vec;

    ASSERT_EQ(vec.e[0], 1.0);
    ASSERT_EQ(vec.e[1], 2.0);
    ASSERT_EQ(vec.e[2], 3.0);

    ASSERT_EQ(vec2.e[0], 4.0);
    ASSERT_EQ(vec2.e[1], 4.0);
    ASSERT_EQ(vec2.e[2], 4.0);
}

TEST(Vector3, star_equals_operator) {
    kdrt::renderer::Vector3 vec = kdrt::renderer::Vector3{1, 2, 3};
    vec *= 3;

    ASSERT_EQ(vec.e[0], 3.0);
    ASSERT_EQ(vec.e[1], 6.0);
    ASSERT_EQ(vec.e[2], 9.0);
}

TEST(Vector3, slash_equals_operator) {
    kdrt::renderer::Vector3 vec = kdrt::renderer::Vector3{1, 2, 3};
    vec /= 2;

    ASSERT_EQ(vec.e[0], 0.5);
    ASSERT_EQ(vec.e[1], 1.0);
    ASSERT_EQ(vec.e[2], 1.5);
}
