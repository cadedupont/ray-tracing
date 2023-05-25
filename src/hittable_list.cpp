#include "hittable_list.h"

// Default constructor
hittable_list::hittable_list() {}

// Overloaded constructor; call add function for adding hittable object passed in as parameter to vector
hittable_list::hittable_list(hittable* object) {
    add(object);
}

// Destructor; iterate through vector, delete each object
hittable_list::~hittable_list() {
    for (hittable* object : objects)
        delete object;
}

// Clear vector of hittable objects
void hittable_list::clear() {
    objects.clear();
}

// Add hittable object to vector
void hittable_list::add(hittable* object) {
    objects.push_back(object);
}

// Implement hasThisHit function from hittable class
bool hittable_list::hasThisHit(const ray& ray, float min, float max, hitRecord& record) const {
    // Declare variable for storing hit record
    hitRecord tempRecord;

    // Declare variable for storing whether or not ray has hit anything
    bool hasHit = false;

    // Declare variable for storing closest hit so far
    float closestHit = max;

    // Iterate through hittable objects
    for (const hittable* object : objects) {
        // If ray has hit object, set hasHit to true, set closestHit to hit number, set hit record to temp record
        if (object->hasThisHit(ray, min, closestHit, tempRecord)) {
            hasHit = true;
            closestHit = tempRecord.num;
            record = tempRecord;
        }
    }

    // Return whether or not ray has hit anything
    return hasHit;
}