find_package(GTest REQUIRED)

mark_as_advanced(BUILD_GMOCK BUILD_GTEST gtest_hide_internal_symbols)

add_executable(unit_tests
    vector3_tests.cpp
)

target_link_libraries(unit_tests libkdrtrenderer gtest::gtest)
#gtest_discover_tests(unit_tests DISCOVERY_MODE PRE_TEST)
