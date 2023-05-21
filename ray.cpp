#include "ray.h"

// Default constructor
ray::ray() {
    origin = position();
    direction = vec3();
}

// Overloaded constructor
ray::ray(const position& origin, const vec3& direction) {
    this->origin = origin;
    this->direction = direction;
}

// Destructor
ray::~ray() {}

// Getters
position ray::getOrigin() const { return origin; }
vec3 ray::getDirection() const { return direction; }
position ray::getPoint(float num) const { return origin + num * direction; }
