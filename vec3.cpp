#include "vec3.h"

// Default constructor initializes elements of array to -1, overloaded assigns elements
// of array to corresponding parameters, nothing to do in destructor
vec3::vec3() : e{ -1.0f, -1.0f, -1.0f } { }
vec3::vec3(float e0, float e1, float e2) : e{ e0, e1, e2 } { }
vec3::~vec3() {}

// Return new instance of vec3 class with negative elements of current array
vec3 vec3::operator -() const {
    return vec3(-e[0], -e[1], -e[2]);
}

// Return value stored at position i in array
float vec3::operator [](int i) const {
    return e[i];
}

// Return value stored at position i in array along with reference
float& vec3::operator [](int i) {
    return e[i];
}

// Add each element in the current instance's array by the parameter instance array
vec3& vec3::operator +=(const vec3& vec) {
    this->e[0] += vec.e[0];
    this->e[1] += vec.e[1];
    this->e[2] += vec.e[2];
    return *this;
}

// Multiply each element of the current instance's array by the parameter float
vec3& vec3::operator *=(const float num) {
    e[0] *= num;
    e[1] *= num;
    e[2] *= num;
    return *this;
}

// Use the above overloaded operator *= to multiply each element of the current instance's
// array by the reciprocal of the parameter float
vec3& vec3::operator /=(const float num) {
    return *this *= 1/num;
}

// Get coordinates being stored in array
float vec3::getX() const { return e[0]; }
float vec3::getY() const { return e[1]; }
float vec3::getZ() const { return e[2]; }

// The length of a vector is defined as the square root of the sum of
// each element of the array squared. For a vector with 3 dimensions:
// |x| = sqrt(x^2 + y^2 + z^2)
float vec3::getLength() const {
    return sqrt(getLengthSquared());
}

// Return the sum of each element in the array squared
float vec3::getLengthSquared() const {
    return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}