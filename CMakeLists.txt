cmake_minimum_required(VERSION 3.15)
project(libkdrtrenderer VERSION 0.0.1 DESCRIPTION "Renderer Library for KneeDeepRayTracer")

find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)

set(CMAKE_SKIP_RPATH TRUE)

add_library(libkdrtrenderer STATIC
        src/vector3.cpp
        src/vector3.h
        src/point3.cpp
        src/point3.h
        src/color.cpp
        src/color.h
        src/interval.cpp
        src/interval.h
        src/ray.cpp
        src/ray.h
)
target_link_libraries(${PROJECT_NAME} fmt::fmt)
target_link_libraries(${PROJECT_NAME} spdlog::spdlog)
