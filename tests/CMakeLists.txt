find_package(GTest REQUIRED CONFIG)

mark_as_advanced(BUILD_GMOCK BUILD_GTEST gtest_hide_internal_symbols)

add_executable(unit_tests
    vector3_tests.cpp
)

target_link_libraries(unit_tests libkdrtrenderer gtest::gtest)
#gtest_discover_tests(unit_tests DISCOVERY_MODE PRE_TEST)


if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(unit_tests PRIVATE -coverage)
    target_link_options(unit_tests PRIVATE -coverage)
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # NOTE:  It looks like I still need the link options here if I want to see the
    #        coverage from the library.
    #target_compile_options(unit_tests PRIVATE -fprofile-instr-generate -fcoverage-mapping)
    target_link_options(unit_tests PRIVATE -fprofile-instr-generate -fcoverage-mapping)
endif()
