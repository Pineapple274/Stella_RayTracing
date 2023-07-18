#include "color.h"
#include "vec3.h"
#include "ray.h"

#include <iostream>



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

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (auto j = image_height - 1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (auto i = 0; i < image_width; ++i) {
            auto u = double(i) / image_width ;
            auto v = double(j) / image_height;
            ray r(origin, lower_left_corner + u * horizontal + v * vertical);
            vec3 color = ray_color(r);
            // color pixel_color(double(i)/(image_width - 1), double(j)/(image_height - 1), 0.25);
            write_color(std::cout, color);
        }
    }
    std::cerr << "\nDone.\n";
}