#include "sphere.h"

// Default constructor
sphere::sphere() {
    center = position();
    radius = 0.0f;
}

// Overloaded constructor
sphere::sphere(const position& center, float radius) {
    this->center = center;
    this->radius = radius;
}

// Destructor
sphere::~sphere() {}

// Check if ray has hit a sphere
bool sphere::hasThisHit(const ray& ray, float min, float max, hitRecord& record) const {
    // Get vector from ray origin to sphere center
    vec3 oc = ray.getOrigin() - center;

    // Calculate a, b, c values for quadratic equation
    // a = squared length of ray direction
    float a = ray.getDirection().getLengthSquared();

    // 1/2 b = dot product of oc and ray direction
    float halfB = dotProduct(oc, ray.getDirection());

    // c = squared length of oc subtracted by radius squared
    float c = oc.getLengthSquared() - radius * radius;

    // Calculate discriminant, if less than 0, sphere not hit, otherwise return value of quadratic equation
    float discriminant = halfB * halfB - a * c;
    if (discriminant < 0)
        return false;

    // Get nearest root that is within range
    float root = (-halfB - sqrt(discriminant)) / a;
    if (root < min || root > max) {
        root = (-halfB + sqrt(discriminant)) / a;
        if (root < min || root > max)
            return false;
    }

    // Set hit record information
    record.num = root;
    record.point = ray.getPoint(record.num);
    vec3 outwardNormal = (record.point - center) / radius;
    record.setFaceNormal(ray, outwardNormal);

    return true;
}