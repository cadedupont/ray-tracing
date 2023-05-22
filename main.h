#ifndef MAIN_H
#define MAIN_H

#include "vec3.h"
#include "ray.h"
#include "camera.h"

#include <iostream>

// Declaring math constants
const float infinity = std::numeric_limits<float>::infinity();
const float pi = 3.1415926535897932385f;

// Function for converting degrees to radians
inline float degreesToRadians(float degrees) {
    return degrees * pi / 180.0f;
}

// Get a random real number between 0, inclusive, and 1, exclusive
inline float randomFloat() {
    return rand() / (RAND_MAX + 1.0f);
}

// Overloading randomFloat to get a random real number between min, inclusive, and max, exclusive
inline float randomFloat(float min, float max) {
    return min + (max - min) * randomFloat();
}

// Clamp value between min and max
inline float clamp(float x, float min, float max) {
    return x < min ? min : x > max ? max : x;
}

#endif