#include "hittable.h"
#include "rtweekend.h"
#include "hittable_list.h"
#include "color.h"
#include "sphere.h"
#include "vec3.h"
#include "camera.h"

#include <iostream>
#include <memory>
#include <stdlib.h>

// double hit_sphere(const vec3& center, double radius, const ray& r){
//     vec3 oc = r.origin() - center;
//     auto a = r.direction().length_squared();
//     auto half_b = dot(oc, r.direction());
//     auto c = oc.length_squared() - radius * radius;
//     auto discriminant = half_b * half_b - a * c;
//     // return discriminant > 0;
//     if((discriminant < 0)){
//         return -1.0;
//     }
//     else {
//         return (-half_b - sqrt(discriminant)) / a;
//     }
// }

vec3 ray_color(const ray& r, const hittable& world, int depth){  
    hit_record rec;
    
    // If we've exceeded the ray bounce limit, no more light is gathered.
    if(depth <= 0){
        return vec3(0, 0, 0);
    }

    if(world.hit(r, 0.001, infinity, rec)){
        auto target = rec.p + rec.normal + random_in_unit_vector();
        return 0.5 * ray_color(ray(rec.p, target - rec.p), world, depth - 1); 
    }

    vec3 unit_direction = unit_vector(r.direction());     
    auto t = 0.5 * (unit_direction.y() + 1.0);     
    return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0); 
}

int main() {

    // Image

    const auto image_width  = 200;
    const auto image_height = 100;
    const auto sample_per_pixel = 100;
    const auto max_depth = 50;
    
    // Render
    hittable_list world;
    camera cam;
    world.add(std::make_shared<sphere>(vec3(0,      0, -1), 0.5));
    world.add(std::make_shared<sphere>(vec3(0, -100.5, -1), 100));

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (auto j = image_height - 1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (auto i = 0; i < image_width; ++i) {
            color rgb(0, 0, 0);
            for(auto s = 0; s < sample_per_pixel; ++s){
                auto u = double(i) / image_width ;
                auto v = double(j) / image_height;
                auto r = cam.get_ray(u, v);
                rgb += ray_color(r, world, max_depth);
            }
            write_color(std::cout, sample_per_pixel, rgb);  
        }
    }
    std::cerr << "\nDone.\n";
}