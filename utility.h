#ifndef UTILITY_H
#define UTILITY_H

#include <cstdlib>
#include <cmath>
#include <memory>
#include <vector>

// UTILITY  USINGS
using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// UTILITY CONSTANTS
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// UTILITY FUNCTIONS
inline double degrees_to_radians(double degrees)
{
    return degrees * pi / 180;
}

inline double random_double()
{
    return rand() / (RAND_MAX + 1.0);
}

inline double random_double(double min, double max)
{
    return min + (max - min) * random_double();
}

// COMMON HEADERS
#include "interval.h"
#include "ray.h"
#include "vec3.h"

#endif