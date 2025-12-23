#!/usr/bin/env python3

### IMPORTS ###
import os

from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout, CMakeToolchain, CMakeDeps

### GLOBALS ###

### FUNCTIONS ###

### CLASSES ###
class LibraryRenderer(ConanFile):
    name = "libkdrtrenderer"
    version = "0.0.4"
    package_type = "library"

    license = "BSD-2-Clause"
    author = "Daniel Williams <dwilliams@port8080.net>"
    url = "https://github.com/kneedeepraytracer/library-renderer"
    description = "A raytracing library"
    topics = ("raytracing")

    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False], "skip_test": [True, False]}
    default_options = {"shared": False, "fPIC": True, "skip_test": False}

    #generators = "CMakeToolchain", "CMakeDeps"

    exports_sources = "CMakeLists.txt", "src/*", "include/*"

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def configure(self):
        if self.options.shared:
            self.options.rm_safe("fPIC")

    def requirements(self):
        self.requires("fmt/11.2.0")
        self.requires("spdlog/1.15.3")

    def build_requirements(self):
        self.test_requires("gtest/1.17.0")

    def layout(self):
        cmake_layout(self)

    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["libkdrtrenderer"]
        #self.cpp_info.set_property("cmake_file_name", "libkdrtrender")
        self.cpp_info.set_property("cmake_target_name", "libkdrtrenderer::libkdrtrenderer")
