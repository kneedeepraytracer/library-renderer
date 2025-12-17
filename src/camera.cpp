#include "kdrt/renderer/camera.h"

#include <fstream>
#include <string>

#include <spdlog/spdlog.h>

#include "kdrt/renderer/utils.h"

#include "kdrt/renderer/color.h"
#include "kdrt/renderer/hitrecord.h"
#include "kdrt/renderer/hittable.h"
#include "kdrt/renderer/interval.h"
#include "kdrt/renderer/material.h"
#include "kdrt/renderer/point3.h"
#include "kdrt/renderer/ray.h"
#include "kdrt/renderer/vector3.h"

namespace kdrt::renderer {
    void Camera::render(const Hittable &world) {
        initialize();

        // Going to output directly to a file so a logger can be used.
        std::ofstream image_file;
        image_file.open(image_filename);

        image_file << "P3\n" << image_width << " " << image_height << "\n255\n";

        for (int j = 0; j < image_height; j++) {
            for (int i = 0; i < image_width; i++) {
                spdlog::info("Scanlines Remaining: {}, Pixels Remaining: {}", image_height - j, image_width - i);
                Color pixel_color(0, 0, 0);
                for (int sample = 0; sample < samples_per_pixel; sample++) {
                    Ray r = get_ray(i, j);
                    pixel_color += ray_color(r, max_depth, world);
                }
                write_color(image_file, pixel_samples_scale * pixel_color);
            }
        }

        image_file.close();

        spdlog::info("Done - {}", image_filename);
    }

    void Camera::initialize() {
        image_height = int(image_width / aspect_ratio);
        image_height = (image_height < 1) ? 1 : image_height;

        pixel_samples_scale = 1.0 / samples_per_pixel;

        center = lookfrom;

        // Determine viewport dimensions
        double theta = degrees_to_radians(vfov);
        double h = std::tan(theta / 2);
        double viewport_height = 2 * h * focus_distance;
        double viewport_width = viewport_height * (double(image_width) / image_height);

        // Calculate the u, v, w unit basis vectors for the camera coordinate frame
        w = unit_vector(Vector3{lookfrom.x - lookat.x,
                                lookfrom.y - lookat.y,
                                lookfrom.z - lookat.z});
        u = unit_vector(cross(vup, w));
        v = cross(w, u);

        // Calculate the vectors across the horizontal and down the vertical viewport edges
        Vector3 viewport_u = viewport_width * u; // Vector across viewport horizontal edge
        Vector3 viewport_v = viewport_height * -v; // Vector down viewport vertical edge

        // Calculate the horizontal and vertical delta vectors from pixel to pixel
        pixel_delta_u = viewport_u / image_width;
        pixel_delta_v = viewport_v / image_height;

        // Calculate the location of the upper left pixel
        Point3 viewport_upper_left{center.x - (focus_distance * w).x - (viewport_u / 2).x - (viewport_v / 2).x,
                                   center.y - (focus_distance * w).y - (viewport_u / 2).y - (viewport_v / 2).y,
                                   center.z - (focus_distance * w).z - (viewport_u / 2).z - (viewport_v / 2).z};
        pixel_zero_loc = Point3{viewport_upper_left.x + (0.5 * (pixel_delta_u + pixel_delta_v)).x,
                                viewport_upper_left.y + (0.5 * (pixel_delta_u + pixel_delta_v)).y,
                                viewport_upper_left.z + (0.5 * (pixel_delta_u + pixel_delta_v)).z};

        // Calculate the camera defocus dosk basis vectors
        double defocus_radius = focus_distance * std::tan(degrees_to_radians(defocus_angle / 2));
        defocus_disk_u = u * defocus_radius;
        defocus_disk_v = v * defocus_radius;
    }

    Vector3 Camera::sample_square() const {
        // Returns the vector to a random point in the [-0.5, -0.5] - [+0.5, +0.5] unit square
        return Vector3(random_double() - 0.5, random_double() - 0.5, 0);
    }

    Ray Camera::get_ray(int i, int j) const {
        // Construct a camera ray originating from the defocus disk and directed at a randomly sampled
        // point around the pixel location i, j

        Vector3 offset = sample_square();
        Point3 pixel_sample{pixel_zero_loc.x + ((i + offset.x) * pixel_delta_u).x + ((j + offset.y) * pixel_delta_v).x,
                            pixel_zero_loc.y + ((i + offset.x) * pixel_delta_u).y + ((j + offset.y) * pixel_delta_v).y,
                            pixel_zero_loc.z + ((i + offset.x) * pixel_delta_u).z + ((j + offset.y) * pixel_delta_v).z};

        Point3 ray_origin = (defocus_angle <= 0) ? center : defocus_disk_sample();
        Vector3 ray_direction = Vector3{pixel_sample.x - ray_origin.x,
                                        pixel_sample.y - ray_origin.y,
                                        pixel_sample.z - ray_origin.z};
        double ray_time = random_double();

        return Ray(ray_origin, ray_direction, ray_time);
    }

    Point3 Camera::defocus_disk_sample() const {
        // Returns a random point in the camera defocus disk
        Vector3 p = random_in_unit_disk();
        return Point3{center.x + (p.x * defocus_disk_u).x + (p.y * defocus_disk_v).x,
                      center.y + (p.x * defocus_disk_u).y + (p.y * defocus_disk_v).y,
                      center.z + (p.x * defocus_disk_u).z + (p.y * defocus_disk_v).z};
    }

    Color Camera::ray_color(const Ray &r, int depth, const Hittable &world) const {
        // If we've exceeded the ray bounce limit, no more light is gathered
        if (depth <= 0) {
            return Color(0, 0, 0);
        }

        HitRecord rec;

        if (world.hit(r, Interval(0.001, infinity), rec)) {
            Ray scattered;
            Color attenuation;
            if (rec.mat->scatter(r, rec, attenuation, scattered)) {
                return attenuation * ray_color(scattered, depth - 1, world);
            }
            return Color(0, 0, 0);
        }

        Vector3 unit_direction = unit_vector(r.direction());
        double a = 0.5 * (unit_direction.y + 1.0);
        return ((1.0 - a) * Color(1.0, 1.0, 1.0)) + (a * Color(0.5, 0.7, 1.0));
    }
}