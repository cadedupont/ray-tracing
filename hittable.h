#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

// Declaring struct to store hit record information
struct hitRecord {
    position point;
    vec3 normal;
    float num;

    // If dot product of ray direction and outward normal, ray has hit sphere, set normal to outward normal
    // otherwise, ray hasn't hit sphere, set normal to negative outward normal
    inline void setFaceNormal(const ray& ray, const vec3& outwardNormal) {
        normal = dotProduct(ray.getDirection(), outwardNormal) < 0 ? outwardNormal : -outwardNormal;
    }
};

// Declaring abstract class for hittable objects
// Special thanks if you catch the King Krule reference :)
class hittable {
    public:
        // Declare virtual destructor for deleting hittable objects
        virtual ~hittable() = default;

        // Declare function for checking whether ray has hit hittable object
        virtual bool hasThisHit(const ray& ray, float min, float max, hitRecord& record) const = 0;
};

#endif