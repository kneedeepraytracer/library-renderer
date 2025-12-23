cmake_minimum_required(VERSION 3.23)

project(libkdrtrenderer CXX)

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

add_library(libkdrtrenderer ${KDRTRENDERER_SOURCES} ${KDRTRENDERER_PUBLIC_HEADERS})
#add_library(libkdrtrenderer::libkdrtrenderer ALIAS libkdrtrenderer)

target_include_directories(libkdrtrenderer PUBLIC include)

set_target_properties(libkdrtrenderer PROPERTIES PUBLIC_HEADER "${KDRTRENDERER_PUBLIC_HEADERS}" WINDOWS_EXPORT_ALL_SYMBOLS TRUE)

target_link_libraries(libkdrtrenderer fmt::fmt)
target_link_libraries(libkdrtrenderer spdlog::spdlog)

if(NOT BUILD_TESTING STREQUAL OFF)
    enable_testing()
    include(CTest)

    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        target_compile_options(libkdrtrenderer PRIVATE -coverage)
        target_link_options(libkdrtrenderer PRIVATE -coverage)
    endif()

    if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        target_compile_options(libkdrtrenderer PRIVATE -fprofile-instr-generate -fcoverage-mapping)
        target_link_options(libkdrtrenderer PRIVATE -fprofile-instr-generate -fcoverage-mapping)
    endif()

    add_subdirectory(tests)
endif()

install(TARGETS libkdrtrenderer
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/kdrt/renderer"
)
#install(FILES ${KDRTRENDERER_PUBLIC_HEADERS}
#        COMPONENT Development
#        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/kdrt/renderer
#)
