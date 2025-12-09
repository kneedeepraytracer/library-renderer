cmake_minimum_required(VERSION 3.22)

project(
    libkdrtrenderer
    VERSION 0.0.1
    DESCRIPTION "Renderer Library for KneeDeepRayTracer"
    LANGUAGES C CXX
)

find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)

set(CMAKE_SKIP_RPATH TRUE)

include_directories(include)
add_subdirectory(src)

enable_testing()
include(CTest)
add_subdirectory(tests)
