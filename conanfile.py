#!/usr/bin/env python3

### IMPORTS ###
import os

from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout

### GLOBALS ###

### FUNCTIONS ###

### CLASSES ###
class LibraryRenderer(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"

    def requirements(self):
        self.requires("fmt/11.2.0")
        self.requires("spdlog/1.15.3")

    def build_requirements(self):
        self.test_requires("gtest/1.17.0")

    def layout(self):
        cmake_layout(self)

    def build(self):
        print("tools.build:skip_test {}".format(self.conf.get("tools.build:skip_test", default = False)))
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
