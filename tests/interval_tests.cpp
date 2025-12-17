#include <gtest/gtest.h>

#include <limits>

#include "kdrt/renderer/interval.h"

TEST(Interval, empty_ctor) {
    const kdrt::renderer::Interval interval = kdrt::renderer::Interval{};

    ASSERT_EQ(interval.min, std::numeric_limits<double>::infinity());
    ASSERT_EQ(interval.max, -std::numeric_limits<double>::infinity());
}

TEST(Interval, all_components_ctor) {
    const kdrt::renderer::Interval interval = kdrt::renderer::Interval{1.0, 2.0};

    ASSERT_EQ(interval.min, 1.0);
    ASSERT_EQ(interval.max, 2.0);
}
