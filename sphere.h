#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"

// Sphere class inherits from hittable class
class sphere : public hittable {
    private:
        // Declare variables for storing sphere center and radius
        position center;
        float radius;

    public:
        // Default constructor, overloaded constructor, destructor
        sphere();
        sphere(const position& center, float radius);
        ~sphere();

        // Implement hasThisHit function from hittable class
        virtual bool hasThisHit(const ray& ray, float min, float max, hitRecord& record) const override;
};

#endif