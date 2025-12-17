#pragma once

//#include <fstream>
#include <string>

#include "kdrt/renderer/color.h"
#include "kdrt/renderer/frame.h"
#include "kdrt/renderer/hittable.h"
#include "kdrt/renderer/point3.h"
#include "kdrt/renderer/ray.h"
#include "kdrt/renderer/vector3.h"

namespace kdrt::renderer {
    class Camera {
    public:
        double aspect_ratio = 1.0; // Ratio of image width over height
        uint image_width = 100; // Rendered image width in pixel count
        uint samples_per_pixel = 10; // Count of random samples for each pixel
        uint max_depth = 10; // Maximum number of ray bounces into scene

        double vfov = 90; // Vertical view angle (field of view)
        Point3 lookfrom = Point3(0, 0, 0); // Point the camera is looking from (camera location)
        Point3 lookat = Point3(0, 0, -1); // Point the camera is looking at (camera direction)
        Vector3 vup = Vector3(0, 1, 0); // Camera-relative "up" direction (camera orientation)

        double defocus_angle = 0; // Variation angle of rays through each pixel
        double focus_distance = 10; // Distance from camera lookfrom point to plane of perfect focus

        //std::string image_filename = "image.ppm";  // Filename of the output image.

        Frame render(const Hittable &world);

    private:
        uint image_height; // Rendered image height
        double pixel_samples_scale; // Color scale factor for a sum pf pixel samples
        Point3 center; // Camera center
        Point3 pixel_zero_loc; // Location on pixel 0, 0
        Vector3 pixel_delta_u; // Offset to pixel to the right
        Vector3 pixel_delta_v; // Offset to pixel below
        Vector3 u; // Camera from basis vectors
        Vector3 v;
        Vector3 w;
        Vector3 defocus_disk_u; // Defocus disk horizontal radius
        Vector3 defocus_disk_v; // Defocus disk vertical radius

        void initialize();
        Vector3 sample_square() const;
        Ray get_ray(int i, int j) const;
        Point3 defocus_disk_sample() const;
        Color ray_color(const Ray &r, int depth, const Hittable &world) const;
    };
}
