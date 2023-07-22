// color.h

#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include "rtweekend.h"

#include <algorithm>
#include <iostream>

inline void write_color(std::ostream &out, int samples_per_pixel, const color col) {
    // Divide the color total by the number of samples.
    // for a gamma value of 2.0.

    auto scale = 1.0 / samples_per_pixel;
    auto r = sqrt(scale * col.e[0]);
    auto g = sqrt(scale * col.e[1]);
    auto b = sqrt(scale * col.e[2]);
    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(b, 0.0, 0.999)) << '\n';
}

#endif