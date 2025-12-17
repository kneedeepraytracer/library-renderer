#include <gtest/gtest.h>

#include "kdrt/renderer/vector3.h"

TEST(Vector3, empty_ctor) {
    const kdrt::renderer::Vector3 vec = kdrt::renderer::Vector3{};

    ASSERT_EQ(vec.x, 0.0);
    ASSERT_EQ(vec.y, 0.0);
    ASSERT_EQ(vec.z, 0.0);
}

TEST(Vector3, all_components_ctor) {
    const kdrt::renderer::Vector3 vec = kdrt::renderer::Vector3{1, 2, 3};

    ASSERT_EQ(vec.x, 1.0);
    ASSERT_EQ(vec.y, 2.0);
    ASSERT_EQ(vec.z, 3.0);
}

TEST(Vector3, minus_operator) {
    const kdrt::renderer::Vector3 vec = kdrt::renderer::Vector3{1, 2, 3};
    const kdrt::renderer::Vector3 vec2 = -vec;

    ASSERT_EQ(vec.x, 1.0);
    ASSERT_EQ(vec.y, 2.0);
    ASSERT_EQ(vec.z, 3.0);

    ASSERT_EQ(vec2.x, -1.0);
    ASSERT_EQ(vec2.y, -2.0);
    ASSERT_EQ(vec2.z, -3.0);
}

TEST(Vector3, plus_equals_operator) {
    const kdrt::renderer::Vector3 vec = kdrt::renderer::Vector3{1, 2, 3};
    kdrt::renderer::Vector3 vec2 = kdrt::renderer::Vector3{3, 2, 1};
    vec2 += vec;

    ASSERT_EQ(vec.x, 1.0);
    ASSERT_EQ(vec.y, 2.0);
    ASSERT_EQ(vec.z, 3.0);

    ASSERT_EQ(vec2.x, 4.0);
    ASSERT_EQ(vec2.y, 4.0);
    ASSERT_EQ(vec2.z, 4.0);
}

TEST(Vector3, star_equals_operator) {
    kdrt::renderer::Vector3 vec = kdrt::renderer::Vector3{1, 2, 3};
    vec *= 3;

    ASSERT_EQ(vec.x, 3.0);
    ASSERT_EQ(vec.y, 6.0);
    ASSERT_EQ(vec.z, 9.0);
}

TEST(Vector3, slash_equals_operator) {
    kdrt::renderer::Vector3 vec = kdrt::renderer::Vector3{1, 2, 3};
    vec /= 2;

    ASSERT_EQ(vec.x, 0.5);
    ASSERT_EQ(vec.y, 1.0);
    ASSERT_EQ(vec.z, 1.5);
}

TEST(Vector3, length) {
    kdrt::renderer::Vector3 vec = kdrt::renderer::Vector3{1, 2, 2};

    ASSERT_EQ(vec.length_squared(), 9.0);
    ASSERT_EQ(vec.length(), 3.0);
}

// How to test near_zero?

// How to test random?  Should random even be part of Vector3?
