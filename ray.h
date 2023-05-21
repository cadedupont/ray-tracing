#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
    private:
        position origin;
        vec3 direction;

    public:
        // Default constructor, overloaded constructor, destructor
        ray();
        ray(const position& origin, const vec3& direction);
        ~ray();

        position getOrigin() const;
        vec3 getDirection() const;
        position getPoint(float num) const;
};

#endif