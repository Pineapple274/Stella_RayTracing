#include "hittable.h"
#include "rtweekend.h"
#include "hittable_list.h"
#include "color.h"
#include "sphere.h"
#include "vec3.h"

#include <iostream>
#include <memory>

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

vec3 ray_color(const ray& r, const hittable& world){  
    hit_record rec;
    if(world.hit(r, 0, infinity, rec)){
        return 0.5 * (rec.normal + vec3(1,1,1)); 
    }
    vec3 unit_direction = unit_vector(r.direction());     
    auto t = 0.5 * (unit_direction.y() + 1.0);     
    return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0); 
}

int main() {

    // Image

    const auto image_width  = 200;
    const auto image_height = 100;

    //viewer
    vec3 lower_left_corner(-2.0, -1.0, -1.0);
    vec3 horizontal       ( 4.0,  0.0,  0.0);
    vec3 vertical         ( 0.0,  2.0,  0.0);     
    vec3 origin           ( 0.0,  0.0,  0.0);
    
    // Render
    hittable_list world;
    world.add(std::make_shared<sphere>(vec3(0,      0, -1), 0.5));
    world.add(std::make_shared<sphere>(vec3(0, -100.5, -1), 100));

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (auto j = image_height - 1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (auto i = 0; i < image_width; ++i) {
            auto u = double(i) / image_width ;
            auto v = double(j) / image_height;
            ray r(origin, lower_left_corner + u * horizontal + v * vertical);
            vec3 color = ray_color(r, world);
            // color pixel_color(double(i)/(image_width - 1), double(j)/(image_height - 1), 0.25);
            write_color(std::cout, color);
        }
    }
    std::cerr << "\nDone.\n";
}