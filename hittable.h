#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

// Declaring struct to store hit record information
struct hitRecord {
    position point;
    vec3 normal;
    float num;
    bool frontFace;

    // If ray has hit front face, set front face to true and normal to outward normal
    // otherwise, set front face to false and normal to negative outward normal
    inline void setFaceNormal(const ray& ray, const vec3& outwardNormal) {
        frontFace = dotProduct(ray.getDirection(), outwardNormal) < 0;
        normal = frontFace ? outwardNormal : -outwardNormal;
    }
};

// Declaring abstract class for hittable objects
// Special thanks if you catch the King Krule reference :)
class hittable {
    public:
        virtual bool hasThisHit(const ray& ray, float min, float max, hitRecord& record) const = 0;
};

#endif