#include "camera.h"

// Default constructor
camera::camera() {
    // Declare variables for storing viewport height, aspect ratio, viewport width, focal length
    float aspectRatio = 16.0f / 9.0f;
    float viewportHeight = 2.0f;
    float viewportWidth = aspectRatio * viewportHeight;
    float focalLength = 1.0f;

    // Set camera origin, horizontal, vertical, lower left corner
    origin = position(0.0f, 0.0f, 0.0f);
    horizontal = vec3(viewportWidth, 0.0f, 0.0f);
    vertical = vec3(0.0f, viewportHeight, 0.0f);
    lowerLeftCorner = origin - horizontal / 2 - vertical / 2 - vec3(0.0f, 0.0f, focalLength);
}

// Destructor
camera::~camera() {}

// Function for getting ray from camera to pixel
ray camera::getRay(float u, float v) const {
    return ray(origin, lowerLeftCorner + u * horizontal + v * vertical - origin);
}