#pragma once

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>

// Using
using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// Constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility functions
inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

// Returns a random number in range [0, 1)
inline double random_double() {
    return rand() / (RAND_MAX + 1.0);
}

inline double random_double(double min, double max) {
    return min + (max - min) * random_double();
}

inline int random_int(int min, int max) {
    // Returns a random integer in [min,max].
    return static_cast<int>(random_double(min, max + 1));
}

inline double clamp(double x, double min, double max) {
    if(x < min) return min;
    if(x > max) return max;
    return x;
}

// Common headers
#include "ray.h"
#include "hittable.h"
#include "vec3.h"

