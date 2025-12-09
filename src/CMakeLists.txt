add_library(libkdrtrenderer STATIC
    vector3.cpp
    point3.cpp
    color.cpp
    interval.cpp
    ray.cpp
)
target_link_libraries(${PROJECT_NAME} fmt::fmt)
target_link_libraries(${PROJECT_NAME} spdlog::spdlog)
