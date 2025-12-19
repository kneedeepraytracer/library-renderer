cmake_minimum_required(VERSION 3.23)

project(kdrtrenderer CXX)

find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)

set(CMAKE_SKIP_RPATH TRUE)

set(KDRTRENDERER_PUBLIC_HEADERS
    include/kdrt/renderer/aabb.h
    include/kdrt/renderer/bvh.h
    include/kdrt/renderer/camera.h
    include/kdrt/renderer/color.h
    include/kdrt/renderer/dialectric.h
    include/kdrt/renderer/frame.h
    include/kdrt/renderer/hitrecord.h
    include/kdrt/renderer/hittable.h
    include/kdrt/renderer/hittable_list.h
    include/kdrt/renderer/interval.h
    include/kdrt/renderer/lambertian.h
    include/kdrt/renderer/material.h
    include/kdrt/renderer/metal.h
    include/kdrt/renderer/point3.h
    include/kdrt/renderer/ray.h
    include/kdrt/renderer/sphere.h
    include/kdrt/renderer/utils.h
    include/kdrt/renderer/vector3.h
)

set(KDRTRENDERER_SOURCES
    src/aabb.cpp
    src/bvh.cpp
    src/camera.cpp
    src/color.cpp
    src/dialectric.cpp
    src/frame.cpp
    src/hitrecord.cpp
    src/hittable_list.cpp
    src/interval.cpp
    src/lambertian.cpp
    src/metal.cpp
    src/point3.cpp
    src/ray.cpp
    src/sphere.cpp
    src/vector3.cpp
)

add_library(kdrtrenderer ${KDRTRENDERER_SOURCES} ${KDRTRENDERER_PUBLIC_HEADERS})

target_include_directories(kdrtrenderer PUBLIC include)

target_link_libraries(kdrtrenderer fmt::fmt)
target_link_libraries(kdrtrenderer spdlog::spdlog)

if(NOT BUILD_TESTING STREQUAL OFF)
    enable_testing()
    include(CTest)

    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        target_compile_options(kdrtrenderer PRIVATE -coverage)
        target_link_options(kdrtrenderer PRIVATE -coverage)
    endif()

    if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        target_compile_options(kdrtrenderer PRIVATE -fprofile-instr-generate -fcoverage-mapping)
        target_link_options(kdrtrenderer PRIVATE -fprofile-instr-generate -fcoverage-mapping)
    endif()

    add_subdirectory(tests)
endif()

install(TARGETS kdrtrenderer)
install(FILES ${KDRTRENDERER_PUBLIC_HEADERS}
        COMPONENT Development
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/kdrt/renderer
)
