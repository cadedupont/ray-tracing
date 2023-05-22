#include "vec3.h"
#include "color.h"
#include "ray.h"

#include <iostream>

float hitSphere(const position& center, float radius, const ray& ray) {
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
    return (discriminant < 0) ? -1 : (-halfB - sqrt(discriminant)) / a;
}

color rayColor(const ray& ray) {
    // Get point value of ray hitting sphere
    float num = hitSphere(position(0.0f, 0.0f, -1.0f), 0.5f, ray);

    // If ray hits sphere, calculate and return color of sphere at hit point
    if (num > 0.0f) {
        vec3 vec = unitVector(ray.getPoint(num) - vec3(0.0f, 0.0f, -1.0f));
        return 0.5f * color(vec.getX() + 1.0f, vec.getY() + 1.0f, vec.getZ() + 1.0f);
    }
    
    // Get unit vector of ray direction
    vec3 unitDirection = unitVector(ray.getDirection());

    // Scale y coordinate to range [0, 1]
    num = 0.5f * (unitDirection.getY() + 1.0f);

    // Linearly blend white and blue depending on y coordinate
    return (1.0f - num) * color(1.0f, 1.0f, 1.0f) + num * color(0.5f, 0.7f, 1.0f);
}

int main() {
    // Create image dimensions, aspect ratio
    const float aspectRatio = 16.0f / 9.0f;
    const int imageWidth = 400;
    const int imageHeight = int(imageWidth / aspectRatio);

    // Create viewport dimensions
    const float viewportHeight = 2.0f;
    const float viewportWidth = aspectRatio * viewportHeight;
    const float focalLength = 1.0f;

    // Create camera origin, horizontal, vertical, lower left corner
    const position origin = position(0.0f, 0.0f, 0.0f);
    const vec3 horizontal = vec3(viewportWidth, 0.0f, 0.0f);
    const vec3 vertical = vec3(0.0f, viewportHeight, 0.0f);
    const position lowerLeftCorner = origin - horizontal / 2 - vertical / 2 - vec3(0.0f, 0.0f, focalLength);

    // Print image header
    std::cout << "P3\n" << imageWidth << " " << imageHeight << "\n255\n";

    // Loop through each pixel in image
    for (int i = imageHeight - 1; i >= 0; --i) {

        // Print progress to stderr
        std::cerr << "\rLines Remaining: " << i << ' ' << std::flush;

        // Loop through each pixel in row
        for (int j = 0; j < imageWidth; ++j) {
            // Get u, v coordinates of pixel
            float u = float(j) / (imageWidth - 1);
            float v = float(i) / (imageHeight - 1);

            // Print color of pixel returned by rayColor function
            drawColor(std::cout, rayColor(ray(origin, lowerLeftCorner + u * horizontal + v * vertical - origin)));
        }
    }

    // Print completion to stderr
    std::cerr << "\nComplete!\n";

    return EXIT_SUCCESS;
}