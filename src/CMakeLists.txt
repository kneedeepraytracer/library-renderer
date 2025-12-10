add_library(libkdrtrenderer STATIC
    vector3.cpp
    point3.cpp
    color.cpp
    interval.cpp
    ray.cpp
)
target_link_libraries(${PROJECT_NAME} fmt::fmt)
target_link_libraries(${PROJECT_NAME} spdlog::spdlog)

if(NOT BUILD_TESTING STREQUAL OFF)
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        target_compile_options(libkdrtrenderer PRIVATE -coverage)
        target_link_options(libkdrtrenderer PRIVATE -coverage)
    endif()

    if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        target_compile_options(libkdrtrenderer PRIVATE -fprofile-instr-generate -fcoverage-mapping)
        target_link_options(libkdrtrenderer PRIVATE -fprofile-instr-generate -fcoverage-mapping)
    endif()
endif()
