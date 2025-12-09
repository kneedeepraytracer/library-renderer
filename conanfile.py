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

    def layout(self):
        cmake_layout(self)

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
