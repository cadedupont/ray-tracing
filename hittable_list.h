#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"

#include <vector>

class hittable_list : public hittable {
    private:
        // Declare vector for storing hittable objects
        std::vector<hittable*> objects;

    public:
        // Default constructor, overloaded constructor, destructor
        hittable_list();
        hittable_list(hittable* object);
        ~hittable_list();

        void clear();
        void add(hittable* object);

        virtual bool hasThisHit(const ray& ray, float min, float max, hitRecord& record) const override;
};

#endif