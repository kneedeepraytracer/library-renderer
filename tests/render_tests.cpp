#include <gtest/gtest.h>

#include <cmath>
#include <memory>

#include "kdrt/renderer/camera.h"
#include "kdrt/renderer/color.h"
#include "kdrt/renderer/hittable_list.h"
#include "kdrt/renderer/lambertian.h"
#include "kdrt/renderer/material.h"
#include "kdrt/renderer/point3.h"
#include "kdrt/renderer/sphere.h"

TEST(Render, simple_sphere) {
    double R = std::cos(pi/4);

    std::shared_ptr<kdrt::renderer::Material> material_left = std::make_shared<kdrt::renderer::Lambertian>(kdrt::renderer::Color(0, 0, 1));
    std::shared_ptr<kdrt::renderer::Material> material_right = std::make_shared<kdrt::renderer::Lambertian>(kdrt::renderer::Color(1, 0, 0));

    kdrt::renderer::HittableList world;
    world.add(std::make_shared<kdrt::renderer::Sphere>(kdrt::renderer::Point3(-R, 0, -1), R, material_left));
    world.add(std::make_shared<kdrt::renderer::Sphere>(kdrt::renderer::Point3(R, 0, -1), R, material_right));

    // FIXME: Need to make this render to a buffer, not to a file.
    kdrt::renderer::Camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    // Trying a vry vry smol render.
    cam.image_width = 16;
    cam.samples_per_pixel = 10;
    cam.max_depth = 5;

    cam.vfov = 20;
    cam.lookfrom = kdrt::renderer::Point3(13, 2, 3);
    cam.lookat = kdrt::renderer::Point3(0, 0, 0);
    cam.vup = kdrt::renderer::Vector3(0, 1, 0);

    cam.defocus_angle = 0.6;
    cam.focus_distance = 10.0;

    cam.render(world);
}