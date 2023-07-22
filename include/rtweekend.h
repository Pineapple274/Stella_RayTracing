// rtweekend.h

#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include <cmath> 
#include <cstdlib> 
#include <limits> 
#include <memory>
#include <stdlib.h>
#include <vector>

// Usings

using std::shared_ptr;
using std::vector;

// Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180;
}

inline double ffmin(double a, double b) { return a <= b ? a : b; }
inline double ffmax(double a, double b) { return a >= b ? a : b; }

inline double random_double(){

    // Return a random_value in [0, 1)
    return rand() / (RAND_MAX + 1.0);
}

inline double random_double(const double& min, const double& max){

    // Return a random_value in [min, max)
    return min + (max - min) * random_double();
}

inline double clamp(const double& x, const double& min, const double& max){

    // Make x in [min, max]
    return x < min ? min : (x > max ? max : x);
}
// Common Headers

#endif