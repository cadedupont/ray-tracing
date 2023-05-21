#include "vec3.h"
#include "color.h"
#include "ray.h"

#include <iostream>

bool hitSphere(const position& center, float radius, const ray& ray) {
    vec3 oc = ray.getOrigin() - center;
    float a = dotProduct(ray.getDirection(), ray.getDirection());
    float b = 2.0f * dotProduct(oc, ray.getDirection());
    float c = dotProduct(oc, oc) - radius * radius;
    float discriminant = b * b - 4 * a * c;
    return (discriminant > 0);
}

color rayColor(const ray& ray) {
    if (hitSphere(position(0.0f, 0.0f, -1.0f), 0.5f, ray))
        return color(1.0f, 0.0f, 0.0f);
    vec3 unitDirection = unitVector(ray.getDirection());
    float num = 0.5f * (unitDirection.getY() + 1.0f);
    return (1.0f - num) * color(1.0f, 1.0f, 1.0f) + num * color(0.5f, 0.7f, 1.0f);
}

int main() {
    const float aspectRatio = 16.0f / 9.0f;
    const int imageWidth = 400;
    const int imageHeight = int(imageWidth / aspectRatio);

    const float viewportHeight = 2.0f;
    const float viewportWidth = aspectRatio * viewportHeight;
    const float focalLength = 1.0f;

    const position origin = position(0.0f, 0.0f, 0.0f);
    const vec3 horizontal = vec3(viewportWidth, 0.0f, 0.0f);
    const vec3 vertical = vec3(0.0f, viewportHeight, 0.0f);
    const position lowerLeftCorner = origin - horizontal / 2 - vertical / 2 - vec3(0.0f, 0.0f, focalLength);

    std::cout << "P3\n" << imageWidth << " " << imageHeight << "\n255\n";

    for (int i = imageHeight - 1; i >= 0; --i) {
        std::cerr << "\rLines Remaining: " << i << ' ' << std::flush;
        for (int j = 0; j < imageWidth; ++j) {
            float u = float(j) / (imageWidth - 1);
            float v = float(i) / (imageHeight - 1);
            drawColor(std::cout, rayColor(ray(origin, lowerLeftCorner + u * horizontal + v * vertical - origin)));
        }
    }

    std::cerr << "\nComplete!\n";

    return EXIT_SUCCESS;
}