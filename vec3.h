#ifndef VEC3_H
#define VEC3_H

#include <math.h>

class vec3 {
    private:
        float e[3];

    public:
        // Default constructor, overloaded constructor, destructor
        vec3();
        vec3(float e0, float e1, float e2);
        ~vec3();

        // Operator overloading
        vec3 operator -() const;
        float operator [](int i) const;
        float& operator [](int i);
        vec3& operator +=(const vec3& vec);
        vec3& operator *=(const float num);
        vec3& operator /=(const float num);

        // Get respective coordinates of array
        float getX() const;
        float getY() const;
        float getZ() const;

        // Get magnitude of array
        float getLength() const;
        float getLengthSquared() const;
};

#endif