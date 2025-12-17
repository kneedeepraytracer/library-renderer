add_library(libkdrtrenderer STATIC
    aabb.cpp
    bvh.cpp
    camera.cpp
    color.cpp
    dialectric.cpp
    hitrecord.cpp
    hittable_list.cpp
    interval.cpp
    lambertian.cpp
    metal.cpp
    point3.cpp
    ray.cpp
    sphere.cpp
    vector3.cpp
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
