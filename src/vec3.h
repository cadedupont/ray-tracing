#ifndef VEC3_H
#define VEC3_H

#include <iostream>
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

// Define aliases for vec3
using color = vec3;
using position = vec3;

// Operator overloading to perform basic arithmetic operations on arrays
// Print contents of array
inline std::ostream& operator << (std::ostream& out, const vec3& vec) {
    return out << vec.getX() << ' ' << vec.getY() << ' ' << vec.getZ();
}

// Add each element of the two arrays together
inline vec3 operator +(const vec3& vec1, const vec3& vec2) {
    return vec3(vec1.getX() + vec2.getX(),
                vec1.getY() + vec2.getY(),
                vec1.getZ() + vec2.getZ());
}

// Subtract each element of the two arrays from each other
inline vec3 operator -(const vec3& vec1, const vec3& vec2) {
    return vec3(vec1.getX() - vec2.getX(),
                vec1.getY() - vec2.getY(),
                vec1.getZ() - vec2.getZ());
}

// Multiply each element of the two arrays together
inline vec3 operator *(const vec3& vec1, const vec3& vec2) {
    return vec3(vec1.getX() * vec2.getX(),
                vec1.getY() * vec2.getY(),
                vec1.getZ() * vec2.getZ());
}

// Multiply each element of the array by the float
inline vec3 operator *(const float num, const vec3& vec) {
    return vec3(vec.getX() * num,
                vec.getY() * num,
                vec.getZ() * num);
}

// Multiply each element of the array by the float using the above overloaded operator
inline vec3 operator *(const vec3& vec, const float num) {
    return num * vec;
}

// Divide each element of the array by the float
inline vec3 operator /(const vec3 vec, const float num) {
    return (1 / num) * vec;
}

// Return the dot product of the two arrays
inline float dotProduct(const vec3& vec1, const vec3& vec2) {
    return vec1.getX() * vec2.getX()
         + vec1.getY() * vec2.getY()
         + vec1.getZ() * vec2.getZ();
}

// Return the cross product of the two arrays
inline vec3 crossProduct(const vec3& vec1, const vec3& vec2) {
    return vec3(vec1.getY() * vec2.getZ() - vec1.getZ() * vec2.getY(),
                vec1.getZ() * vec2.getX() - vec1.getX() * vec2.getZ(),
                vec1.getX() * vec2.getY() - vec1.getY() * vec2.getX());
}

// Return the unit vector of the array
inline vec3 unitVector(const vec3& vec) {
    return vec / vec.getLength();
}

#endif