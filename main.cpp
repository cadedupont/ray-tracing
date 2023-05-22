#include "vec3.h"
#include "color.h"
#include "ray.h"
#include "hittable_list.h"
#include "sphere.h"

#include <iostream>

// Declaring math constants
const float infinity = std::numeric_limits<float>::infinity();
const float pi = 3.1415926535897932385f;

// Function for converting degrees to radians
inline float degreesToRadians(float degrees) {
    return degrees * pi / 180.0f;
}

// Function for returning root at which ray hits sphere if it does
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

// Function for returning color of pixel
color rayColor(const ray& ray, const hittable& object) {
    // Declare variable for storing hit record
    hitRecord record;

    // If ray has hit a hittable object, return color of normal at hit point
    if (object.hasThisHit(ray, 0.0f, infinity, record))
        return 0.5f * (record.normal + color(1.0f, 1.0f, 1.0f));

    // Otherwise, return background color of blue to white gradient
    vec3 unitDirection = unitVector(ray.getDirection());
    float num = 0.5f * (unitDirection.getY() + 1.0f);
    return (1.0f - num) * color(1.0f, 1.0f, 1.0f) + num * color(0.5f, 0.7f, 1.0f);

}

int main() {
    // Create image dimensions, aspect ratio
    const float aspectRatio = 16.0f / 9.0f;
    const int imageWidth = 400;
    const int imageHeight = int(imageWidth / aspectRatio);

    // Create hittable list
    hittable_list objects;
    objects.add(new sphere(position(0.0f, 0.0f, -1.0f), 0.5f));
    objects.add(new sphere(position(0.0f, -100.5f, -1.0f), 100.0f));

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
            drawColor(std::cout, rayColor(ray(origin, lowerLeftCorner + u * horizontal + v * vertical - origin), objects));
        }
    }

    // Print completion to stderr
    std::cerr << "\nComplete!\n";

    return EXIT_SUCCESS;
}