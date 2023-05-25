#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
    private:
        // Declare variables for storing ray origin and direction
        position origin;
        vec3 direction;

    public:
        // Default constructor, overloaded constructor, destructor
        ray();
        ray(const position& origin, const vec3& direction);
        ~ray();

        // Getter methods
        position getOrigin() const;
        vec3 getDirection() const;
        position getPoint(float num) const;
};

#endif